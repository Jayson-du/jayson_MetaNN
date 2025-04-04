#include <MetaNN/meta_nn.h>
#include <calculate_tags.h>
#include <data_gen.h>

#include <cassert>
#include <iostream>
using namespace MetaNN;
using namespace std;

namespace {
using CommonInputMap =
    LayerInMap<LayerKV<LayerInput, Vector<CheckElement, CheckDevice>>>;
void test_acos_layer1() {
  cout << "Test acos layer case 1 ...\t";
  using RootLayer = MakeInferLayer<AcosLayer>;
  static_assert(!RootLayer::IsFeedbackOutput);
  static_assert(!RootLayer::IsUpdate);

  RootLayer layer("root");

  Tensor<CheckElement, CheckDevice, 1> in(7);
  in.SetValue(0, 0.3460);
  in.SetValue(1, 0.9098);
  in.SetValue(2, 0.6349);
  in.SetValue(3, 0.8008);
  in.SetValue(4, 0);
  in.SetValue(5, 0.99);
  in.SetValue(6, -0.99);
  auto input = LayerInputCont<RootLayer>().Set<LayerInput>(in);

  LayerNeutralInvariant(layer);
  auto out = layer.FeedForward(input);
  auto res = Evaluate(out.Get<LayerOutput>());

  assert(res.Shape()[0] == 7);
  assert(fabs(res(0) - 1.2175) < 0.0001);
  assert(fabs(res(1) - 0.4280) < 0.0001);
  assert(fabs(res(2) - 0.8829) < 0.0001);
  assert(fabs(res(3) - 0.6422) < 0.0001);
  assert(fabs(res(4) - 1.5708) < 0.0001);
  assert(fabs(res(5) - 0.1415) < 0.0001);
  assert(fabs(res(6) - 3.0001) < 0.0001);

  auto out_grad = layer.FeedBackward(LayerOutputCont<RootLayer>());
  static_assert(decltype(out_grad)::template IsValueEmpty<LayerInput>);

  LayerNeutralInvariant(layer);
  cout << "done" << endl;
}

void test_acos_layer2() {
  cout << "Test acos layer case 2 ...\t";
  using RootLayer = MakeTrainLayer<AcosLayer, CommonInputMap, PFeedbackOutput>;
  static_assert(RootLayer::IsFeedbackOutput);
  static_assert(!RootLayer::IsUpdate);

  RootLayer layer("root");

  Tensor<CheckElement, CheckDevice, 1> in(7);
  in.SetValue(0, 0.3460);
  in.SetValue(1, 0.9098);
  in.SetValue(2, 0.6349);
  in.SetValue(3, 0.8008);
  in.SetValue(4, 0);
  in.SetValue(5, 0.99);
  in.SetValue(6, -0.99);
  auto input = LayerInputCont<RootLayer>().Set<LayerInput>(in);

  LayerNeutralInvariant(layer);
  auto out = layer.FeedForward(input);
  auto res = Evaluate(out.Get<LayerOutput>());
  assert(res.Shape()[0] == 7);

  assert(fabs(res(0) - 1.2175) < 0.0001);
  assert(fabs(res(1) - 0.4280) < 0.0001);
  assert(fabs(res(2) - 0.8829) < 0.0001);
  assert(fabs(res(3) - 0.6422) < 0.0001);
  assert(fabs(res(4) - 1.5708) < 0.0001);
  assert(fabs(res(5) - 0.1415) < 0.0001);
  assert(fabs(res(6) - 3.0001) < 0.0001);

  auto grad = GenTensor<CheckElement>(1, 0, 7);
  auto out_grad =
      layer.FeedBackward(LayerOutputCont<RootLayer>().Set<LayerOutput>(grad));
  auto fb = Evaluate(out_grad.Get<LayerInput>());

  assert(fabs(fb(0) + 1.0658) < 0.0001);
  assert(fabs(fb(1) + 2.4094) < 0.0001);
  assert(fabs(fb(2) + 1.2943) < 0.0001);
  assert(fabs(fb(3) + 1.6696) < 0.0001);
  assert(fabs(fb(4) + 1.0000) < 0.0001);
  assert(fabs(fb(5) + 7.0888) < 0.0001);
  assert(fabs(fb(6) + 7.0888) < 0.0001);

  LayerNeutralInvariant(layer);
  cout << "done" << endl;
}
} // namespace

namespace Test::Layer::Principal {
void test_acos_layer() {
  test_acos_layer1();
  test_acos_layer2();
}
} // namespace Test::Layer::Principal
