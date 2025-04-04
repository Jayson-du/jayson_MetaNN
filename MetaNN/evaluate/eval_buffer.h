#pragma once

#include <MetaNN/evaluate/eval_handle.h>

#include <memory>

namespace MetaNN {
template <typename TData> class EvalBuffer {
public:
  using DataType = TData;

  auto Handle() const { return m_handle; }

  auto ConstHandle() const {
    return ConstEvalHandle<EvalHandle<TData>>(m_handle);
  }

  bool IsEvaluated() const noexcept { return m_handle.IsEvaluated(); }

private:
  EvalHandle<TData> m_handle;
};
} // namespace MetaNN