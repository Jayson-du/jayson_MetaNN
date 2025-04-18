#pragma once

#include <MetaNN/facilities/traits.h>
namespace MetaNN {
/// lower access
template <typename TData> struct LowerAccessImpl;

template <typename TData> auto LowerAccess(TData &&p) {
  using RawType = RemConstRef<TData>;
  return LowerAccessImpl<RawType>(std::forward<TData>(p));
}
} // namespace MetaNN
