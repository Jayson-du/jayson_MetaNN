#pragma once

#include <MetaNN/data/facilities/traits.h>
#include <MetaNN/evaluate/eval_plan.h>
#include <MetaNN/facilities/_.h>
#include <MetaNN/operation/facilities/_.h>

#include <cassert>
#include <cmath>
#include <type_traits>

namespace MetaNN::OpTags {
struct Tan;
struct TanGrad;
}  // namespace MetaNN::OpTags

namespace MetaNN {
namespace OperTan::NSCaseGen {
template <typename TInputHandle, typename TOutputHandle>
class EvalItem : public BaseEvalItem {
  using CategoryTag = CategoryTagFromHandle<TOutputHandle>;

 public:
  EvalItem(TInputHandle oriHandle, TOutputHandle outputHandle)
      : BaseEvalItem(TypeID<EvalItem>(), {oriHandle.DataPtr()},
                     outputHandle.DataPtr()),
        m_inputHandle(std::move(oriHandle)),
        m_outputHandle(std::move(outputHandle)) {}

  const TInputHandle m_inputHandle;
  TOutputHandle m_outputHandle;
};

template <typename TInputHandle, typename TOutputHandle>
class EvalGroup
    : public TrivialEvalGroup<EvalItem<TInputHandle, TOutputHandle>> {
  using EvalItemType = EvalItem<TInputHandle, TOutputHandle>;

 protected:
  virtual void EvalInternalLogic(EvalItemType& evalItem) final override {
    const auto& in = evalItem.m_inputHandle.Data();

    using ResType = typename TOutputHandle::DataType;
    using ElementType = typename ResType::ElementType;
    ResType out(in.Shape());

    const size_t count = in.Shape().Count();
    assert(count == out.Shape().Count());

    auto low_in = LowerAccess(in);
    const ElementType* mem_in = low_in.RawMemory();

    auto low_out = LowerAccess(out);
    ElementType* mem_out = low_out.MutableRawMemory();

    static_assert(
        std::is_same_v<DeviceTypeFromHandle<TOutputHandle>, DeviceTags::CPU>,
        "Currently only CPU is supported");

    for (size_t i = 0; i < count; ++i) {
      mem_out[i] = (ElementType)(std::tan(mem_in[i]));
    }
    evalItem.m_outputHandle.SetData(std::move(out));
  }
};
}  // namespace OperTan::NSCaseGen

template <>
struct OperSeq_<OpTags::Tan> {
  using type = OperCalAlgoChain<TailCalculator<OperTan::NSCaseGen::EvalItem,
                                               OperTan::NSCaseGen::EvalGroup>>;
};

template <typename TP,
          std::enable_if_t<IsValidOper<OpTags::Tan, TP>>* = nullptr>
auto Tan(TP&& p_m) {
  using rawM = RemConstRef<TP>;
  using ResType = Operation<OpTags::Tan, OperandContainer<rawM>>;
  return ResType(std::forward<TP>(p_m));
}
}  // namespace MetaNN

namespace MetaNN {
namespace OperTanGrad::NSCaseGen {
template <typename TGradHandle, typename TInputHandle, typename TOutputHandle>
class EvalItem : public BaseEvalItem {
  using CategoryTag = CategoryTagFromHandle<TOutputHandle>;

 public:
  EvalItem(TGradHandle gradHandle, TInputHandle oriHandle,
           TOutputHandle outputHandle)
      : BaseEvalItem(TypeID<EvalItem>(),
                     {gradHandle.DataPtr(), oriHandle.DataPtr()},
                     outputHandle.DataPtr()),
        m_gradHandle(std::move(gradHandle)),
        m_inputHandle(std::move(oriHandle)),
        m_outputHandle(std::move(outputHandle)) {}

  const TGradHandle m_gradHandle;
  const TInputHandle m_inputHandle;
  TOutputHandle m_outputHandle;
};

template <typename TGradHandle, typename TInputHandle, typename TOutputHandle>
class EvalGroup : public TrivialEvalGroup<
                      EvalItem<TGradHandle, TInputHandle, TOutputHandle>> {
  using EvalItemType = EvalItem<TGradHandle, TInputHandle, TOutputHandle>;

 protected:
  virtual void EvalInternalLogic(EvalItemType& evalItem) final override {
    const auto& grad = evalItem.m_gradHandle.Data();
    const auto& in = evalItem.m_inputHandle.Data();

    using ResType = typename TOutputHandle::DataType;
    using ElementType = typename ResType::ElementType;
    ResType out(in.Shape());

    const size_t count = in.Shape().Count();
    const size_t grad_count = grad.Shape().Count();
    assert(count == out.Shape().Count());
    assert(count % grad_count == 0);

    auto low_grad = LowerAccess(grad);
    const ElementType* mem_grad = low_grad.RawMemory();
    auto low_in = LowerAccess(in);
    const ElementType* mem_in = low_in.RawMemory();

    auto low_out = LowerAccess(out);
    ElementType* mem_out = low_out.MutableRawMemory();

    static_assert(
        std::is_same_v<DeviceTypeFromHandle<TOutputHandle>, DeviceTags::CPU>,
        "Currently only CPU is supported");

    for (size_t i = 0; i < count; ++i) {
      auto sec = 1 / std::cos(mem_in[i]);
      mem_out[i] = mem_grad[i % grad_count] * sec * sec;
    }
    evalItem.m_outputHandle.SetData(std::move(out));
  }
};
}  // namespace OperTanGrad::NSCaseGen

template <>
struct OperSeq_<OpTags::TanGrad> {
  using type =
      OperCalAlgoChain<TailCalculator<OperTanGrad::NSCaseGen::EvalItem,
                                      OperTanGrad::NSCaseGen::EvalGroup>>;
};

template <
    typename TGrad, typename TInput,
    std::enable_if_t<IsValidOper<OpTags::TanGrad, TGrad, TInput>>* = nullptr>
auto TanGrad(TGrad&& p_grad, TInput&& p_input) {
  static_assert(DataCategory<TInput>::DimNum >= DataCategory<TGrad>::DimNum);

  using rawOp1 = RemConstRef<TGrad>;
  using rawOp2 = RemConstRef<TInput>;
  using ResType = Operation<OpTags::TanGrad, OperandContainer<rawOp1, rawOp2>>;
  return ResType(std::forward<TGrad>(p_grad), std::forward<TInput>(p_input));
}
}  // namespace MetaNN