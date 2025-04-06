#pragma once

#include <MetaNN/facilities/traits.h>

#include <type_traits>

namespace MetaNN {
/// data types
namespace CategoryTags {
struct OutOfCategory;

// 张量的维度标签
// 所有的数据类型都可以归类为张量
template <size_t uDim> struct Tensor { constexpr static size_t DimNum = uDim; };

// 0维张量是标量，
using Scalar = Tensor<0>;
// 1维张量是向量，
using Vector = Tensor<1>;
// 2维张量是矩阵，
using Matrix = Tensor<2>;
} // namespace CategoryTags

template <typename T> constexpr bool IsValidCategoryTag = false;

template <size_t uDim>
constexpr bool IsValidCategoryTag<CategoryTags::Tensor<uDim>> = true;

template <typename TElem, typename TDevice, size_t uDim> class Tensor;

template <typename TElem, typename TDevice, size_t uDim>
struct PrincipalDataType_ {
  // 萃取张量类型
  using type = Tensor<TElem, TDevice, uDim>;
};

template <typename TCategory, typename TElem, typename TDevice>
using PrincipalDataType =
    typename PrincipalDataType_<TElem, TDevice, TCategory::DimNum>::type;

// 用于将具体的类型与标签关联
template <typename T> struct DataCategory_ {
  template <typename R>
  static typename R::CategoryTag Test(typename R::CategoryTag *);

  // 因为是模板类, Test函数本身不需要实现, 主要用于萃取CategoryTags类型,
  // 如果某个类中有"using CategoryTag = CategoryTags::Tensor<uDim>;"
  // 使得 DataCategory_ 的 Test 能通过 R::CategoryTag 提取到 Tensor<uDim>,
  // 则会使用这个函数, 编译器自动判断返回值类型,
  // 是否属于CategoryTags中定义的类型 如果没有找到CategoryTag,
  template <typename R> static CategoryTags::OutOfCategory Test(...);

  // 否则, 使用这个函数, 返回OutOfCategory
  using type = decltype(Test<RemConstRef<T>>(nullptr));
};

// 数据种类萃取器
template <typename T> using DataCategory = typename DataCategory_<T>::type;

// 模板判断是否是张量类型
template <typename T, size_t uDim>
constexpr bool IsTensorWithDim =
    std::is_same_v<DataCategory<T>, CategoryTags::Tensor<uDim>>;

// 特化版本
template <typename T> constexpr bool IsScalar = IsTensorWithDim<T, 0>;

template <typename T> constexpr bool IsVector = IsTensorWithDim<T, 1>;

template <typename T> constexpr bool IsMatrix = IsTensorWithDim<T, 2>;

template <typename T> constexpr bool IsThreeDArray = IsTensorWithDim<T, 3>;
} // namespace MetaNN
