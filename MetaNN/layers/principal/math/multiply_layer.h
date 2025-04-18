#pragma once
#include <MetaNN/layers/facilities/policies.h>
#include <MetaNN/layers/facilities/traits.h>
#include <MetaNN/policies/_.h>

namespace MetaNN {
template <typename TInputs, typename TPolicies> class MultiplyLayer {
  static_assert(IsPolicyContainer<TPolicies>);
  using CurLayerPolicy = PlainPolicy<TPolicies>;

public:
  static constexpr bool IsFeedbackOutput =
      PolicySelect<GradPolicy, CurLayerPolicy>::IsFeedbackOutput;
  static constexpr bool IsUpdate = false;

  using InputPortSet = LayerPortSet<struct LeftOperand, struct RightOperand>;
  using OutputPortSet = LayerPortSet<struct LayerOutput>;
  using InputMap =
      typename std::conditional_t<std::is_same_v<TInputs, NullParameter>,
                                  EmptyLayerInMap_<InputPortSet>,
                                  Identity_<TInputs>>::type;
  static_assert(CheckInputMapAvailable_<InputMap, InputPortSet>::value);

private:
  using TLeftOperandFP = typename InputMap::template Find<LeftOperand>;
  using TRightOperandFP = typename InputMap::template Find<RightOperand>;

public:
  MultiplyLayer(std::string name) : m_name(std::move(name)) {}

  template <typename TIn> auto FeedForward(TIn &&p_in) {
    const auto &input1 = LayerTraits::PickItemFromCont<InputMap, LeftOperand>(
        std::forward<TIn>(p_in));
    const auto &input2 = LayerTraits::PickItemFromCont<InputMap, RightOperand>(
        std::forward<TIn>(p_in));

    if constexpr (IsFeedbackOutput) {
      m_input1.push(input1);
      m_input2.push(input2);
      m_inputShape1.PushDataShape(input1);
      m_inputShape2.PushDataShape(input2);
    }

    return LayerOutputCont<MultiplyLayer>().template Set<LayerOutput>(input1 *
                                                                      input2);
  }

  template <typename TGrad> auto FeedBackward(TGrad &&p_grad) {
    if constexpr (!IsFeedbackOutput ||
                  RemConstRef<TGrad>::template IsValueEmpty<LayerOutput>) {
      if constexpr (IsFeedbackOutput) {
        LayerTraits::PopoutFromStack(m_input1, m_input2, m_inputShape1,
                                     m_inputShape2);
      }
      return LayerInputCont<MultiplyLayer>();
    } else {
      if ((m_input1.empty()) || (m_input2.empty())) {
        throw std::runtime_error("Cannot feed back in MultiplyLayer");
      }
      auto input1 = m_input1.top();
      auto input2 = m_input2.top();

      auto grad = std::forward<TGrad>(p_grad).template Get<LayerOutput>();

      auto grad1 = grad * input1;
      auto grad2 = grad * input2;
      auto res1 = LayerTraits::Collapse<TLeftOperandFP>(grad2);
      auto res2 = LayerTraits::Collapse<TRightOperandFP>(grad1);
      m_inputShape1.CheckDataShape(res1);
      m_inputShape2.CheckDataShape(res2);

      LayerTraits::PopoutFromStack(m_input1, m_input2, m_inputShape1,
                                   m_inputShape2);
      return LayerInputCont<MultiplyLayer>()
          .template Set<LeftOperand>(std::move(res1))
          .template Set<RightOperand>(std::move(res2));
    }
  }

  void NeutralInvariant() {
    if constexpr (IsFeedbackOutput) {
      LayerTraits::CheckStackEmpty(m_input1, m_input2, m_inputShape1,
                                   m_inputShape2);
    }
  }

private:
  std::string m_name;
  LayerTraits::LayerInternalBuf<TLeftOperandFP, IsFeedbackOutput> m_input1;
  LayerTraits::LayerInternalBuf<TRightOperandFP, IsFeedbackOutput> m_input2;

  LayerTraits::ShapeChecker<TLeftOperandFP, IsFeedbackOutput> m_inputShape1;
  LayerTraits::ShapeChecker<TRightOperandFP, IsFeedbackOutput> m_inputShape2;
};
} // namespace MetaNN
