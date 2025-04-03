#pragma once

#include <MetaNN/policies/policy_macro_begin.h>

#include <random>
namespace MetaNN {
struct InitPolicy {
  using MajorClass = InitPolicy;

  struct RandEngineTypeCate;
  using RandEngine = std::mt19937;
};

TypePolicyTemplate(PRandomGeneratorIs, InitPolicy, RandEngine);
} // namespace MetaNN

#include <MetaNN/policies/policy_macro_end.h>