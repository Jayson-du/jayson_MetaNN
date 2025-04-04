#pragma once

#include <MetaNN/model/param_initializer/facilities/fill_with_spec_dist.h>
#include <MetaNN/model/param_initializer/facilities/policies.h>

#include <random>
#include <stdexcept>
#include <type_traits>

namespace MetaNN {
template <typename TPolicyCont = PolicyContainer<>> class GaussianFiller {
  using TRandomEngine =
      typename PolicySelect<InitPolicy, TPolicyCont>::RandEngine;

public:
  GaussianFiller(double p_mean, double p_std,
                 unsigned seed = std::random_device{}())
      : m_engine(seed), m_mean(p_mean), m_std(p_std) {
    if (p_std <= 0) {
      throw std::runtime_error("Invalid std.");
    }
  }

  template <typename TData> void Fill(TData &data) {
    using ElementType = typename TData::ElementType;
    std::normal_distribution<ElementType> dist(static_cast<ElementType>(m_mean),
                                               static_cast<ElementType>(m_std));
    NSInitializer::FillWithDist(data, dist, m_engine);
  }

private:
  TRandomEngine m_engine;
  double m_mean;
  double m_std;
};
} // namespace MetaNN