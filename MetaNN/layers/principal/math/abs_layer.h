#pragma once

#include <MetaNN/layers/facilities/policies.h>
#include <MetaNN/layers/facilities/traits.h>
#include <MetaNN/policies/_.h>

namespace MetaNN {
template <typename TInputs, typename TPolicies> class AbsLayer {
  static_assert(IsPolicyContainer<TPolicies>);
  using CurLayerPolicy = PlainPolicy<TPolicies>;

public:
  static constexpr bool IsFeedbackOutput =
      PolicySelect<GradPolicy, CurLayerPolicy>::IsFeedbackOutput;
  static constexpr bool IsUpdate = false;

  using InputPortSet = LayerPortSet<struct LayerInput>;
  using OutputPortSet = LayerPortSet<struct LayerOutput>;
  using InputMap =
      typename std::conditional_t<std::is_same_v<TInputs, NullParameter>,
                                  EmptyLayerInMap_<InputPortSet>,
                                  Identity_<TInputs>>::type;
  static_assert(CheckInputMapAvailable_<InputMap, InputPortSet>::value);

private:
  using TLayerInputFP = typename InputMap::template Find<LayerInput>;

public:
  AbsLayer(std::string name) : m_name(std::move(name)) {}

  template <typename TIn> auto FeedForward(TIn &&p_in) {
    auto val = LayerTraits::PickItemFromCont<InputMap, LayerInput>(
        std::forward<TIn>(p_in));
    auto res = Abs(val);

    if constexpr (IsFeedbackOutput) {
      m_inputShape.PushDataShape(val);
      m_data.push(std::move(val));
    }
    return LayerOutputCont<AbsLayer>().template Set<LayerOutput>(
        std::move(res));
  }

  template <typename TGrad> auto FeedBackward(TGrad &&p_grad) {
    if constexpr (!IsFeedbackOutput ||
                  RemConstRef<TGrad>::template IsValueEmpty<LayerOutput>) {
      if constexpr (IsFeedbackOutput) {
        LayerTraits::PopoutFromStack(m_data, m_inputShape);
      }
      return LayerInputCont<AbsLayer>();
    } else {
      if (m_data.empty()) {
        throw std::runtime_error("Cannot feed back in AbsLayer");
      }
      auto input = m_data.top();

      auto grad = std::forward<TGrad>(p_grad).template Get<LayerOutput>();
      auto res = std::move(grad) * Sign(std::move(input));
      m_inputShape.CheckDataShape(res);

      LayerTraits::PopoutFromStack(m_data, m_inputShape);
      return LayerInputCont<AbsLayer>().template Set<LayerInput>(
          std::move(res));
    }
  }

  void NeutralInvariant() const {
    if constexpr (IsFeedbackOutput) {
      LayerTraits::CheckStackEmpty(m_data, m_inputShape);
    }
  }

private:
  std::string m_name;
  LayerTraits::LayerInternalBuf<TLayerInputFP, IsFeedbackOutput> m_data;
  LayerTraits::ShapeChecker<TLayerInputFP, IsFeedbackOutput> m_inputShape;
};
} // namespace MetaNN