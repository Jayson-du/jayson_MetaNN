#include <MetaNN/meta_nn.h>
#include <calculate_tags.h>
#include <data_gen.h>

#include <cmath>
#include <iostream>
using namespace std;
using namespace MetaNN;

namespace {
void test_tan_case1() {
  cout << "Test tan case 1 (scalar)\t";
  {
    Scalar<CheckElement, CheckDevice> ori(static_cast<CheckElement>(0.2718));
    auto op = Tan(ori);
    auto res = Evaluate(op);
    assert(fabs(res.Value() - std::tan(0.2718)) < 0.001f);
  }
  cout << "done" << endl;
}

void test_tan_case2() {
  cout << "Test tan case 2 (matrix)\t";
  auto ori =
      GenTensor<CheckElement>(-1, static_cast<CheckElement>(0.01), 10, 7);
  auto op = Tan(ori);
  static_assert(IsMatrix<decltype(op)>);
  assert(op.Shape()[0] == 10);
  assert(op.Shape()[1] == 7);

  auto res = Evaluate(op);
  static_assert(IsMatrix<decltype(res)>);
  assert(res.Shape()[0] == 10);
  assert(res.Shape()[1] == 7);

  for (size_t i = 0; i < 10; ++i) {
    for (size_t k = 0; k < 7; ++k) {
      auto value = std::tan(ori(i, k));
      assert(fabs(res(i, k) - value) < 0.001f);
    }
  }
  cout << "done" << endl;
}

void test_tan_case3() {
  cout << "Test tan case 3 (3d-array)\t";
  auto ori =
      GenTensor<CheckElement>(-1, static_cast<CheckElement>(0.01), 2, 10, 7);
  auto op = Tan(ori);
  static_assert(IsThreeDArray<decltype(op)>);
  assert(op.Shape()[0] == 2);
  assert(op.Shape()[1] == 10);
  assert(op.Shape()[2] == 7);

  auto res = Evaluate(op);
  static_assert(IsThreeDArray<decltype(res)>);
  assert(res.Shape()[0] == 2);
  assert(res.Shape()[1] == 10);
  assert(res.Shape()[2] == 7);

  for (size_t p = 0; p < 2; ++p) {
    for (size_t i = 0; i < 10; ++i) {
      for (size_t k = 0; k < 7; ++k) {
        auto value = std::tan(ori(p, i, k));
        assert(fabs(res(p, i, k) - value) < 0.001f);
      }
    }
  }
  cout << "done" << endl;
}

void test_tan_case4() {
  cout << "Test tan case 4 (batch scalar)\t";
  auto ori = GenTensor<CheckElement>(-1, static_cast<CheckElement>(0.1), 10);
  auto op = Tan(ori);
  static_assert(IsVector<decltype(op)>);
  assert(op.Shape()[0] == 10);

  auto res = Evaluate(op);
  static_assert(IsVector<decltype(res)>);
  assert(res.Shape()[0] == 10);

  for (size_t i = 0; i < 10; ++i) {
    auto value = std::tan(ori[i].Value());
    assert(fabs(res[i].Value() - value) < 0.001f);
  }
  cout << "done" << endl;
}
} // namespace

namespace Test::Operation::Math {
void test_tan() {
  test_tan_case1();
  test_tan_case2();
  test_tan_case3();
  test_tan_case4();
}
} // namespace Test::Operation::Math

namespace {
void test_tan_grad_case1() {
  cout << "Test tan-grad case 1 (scalar)\t";
  {
    Scalar<CheckElement, CheckDevice> grad(1.5);
    Scalar<CheckElement, CheckDevice> ori(static_cast<CheckElement>(0.3348));
    auto op = TanGrad(grad, ori);
    auto res = Evaluate(op);

    auto check = 1.5 / std::cos(0.3348) / std::cos(0.3348);
    assert(fabs(res.Value() - check) < 0.001f);
  }
  cout << "done" << endl;
}

void test_tan_grad_case2() {
  cout << "Test tan-grad case 2 (matrix)\t";
  auto grad = GenTensor<CheckElement>(0, 1, 10, 7);
  auto ori = GenTensor<CheckElement>(static_cast<CheckElement>(-0.5),
                                     static_cast<CheckElement>(0.01), 10, 7);
  auto op = TanGrad(grad, ori);
  static_assert(IsMatrix<decltype(op)>);
  assert(op.Shape()[0] == 10);
  assert(op.Shape()[1] == 7);

  auto res = Evaluate(op);
  static_assert(IsMatrix<decltype(res)>);
  assert(res.Shape()[0] == 10);
  assert(res.Shape()[1] == 7);

  for (size_t i = 0; i < 10; ++i) {
    for (size_t k = 0; k < 7; ++k) {
      auto check = grad(i, k) / std::cos(ori(i, k)) / std::cos(ori(i, k));
      assert(fabs(res(i, k) - check) < 0.001f);
    }
  }
  cout << "done" << endl;
}

void test_tan_grad_case3() {
  cout << "Test tan-grad case 3 (3d-array)\t";
  auto grad = GenTensor<CheckElement>(0, 1, 2, 10, 7);
  auto ori = GenTensor<CheckElement>(static_cast<CheckElement>(-0.9),
                                     static_cast<CheckElement>(0.01), 2, 10, 7);
  auto op = TanGrad(grad, ori);
  static_assert(IsThreeDArray<decltype(op)>);
  assert(op.Shape()[0] == 2);
  assert(op.Shape()[1] == 10);
  assert(op.Shape()[2] == 7);

  auto res = Evaluate(op);
  static_assert(IsThreeDArray<decltype(res)>);
  assert(res.Shape()[0] == 2);
  assert(res.Shape()[1] == 10);
  assert(res.Shape()[2] == 7);

  for (size_t p = 0; p < 2; ++p) {
    for (size_t i = 0; i < 10; ++i) {
      for (size_t k = 0; k < 7; ++k) {
        auto check =
            grad(p, i, k) / std::cos(ori(p, i, k)) / std::cos(ori(p, i, k));
        assert(fabs(res(p, i, k) - check) < 0.001f);
      }
    }
  }
  cout << "done" << endl;
}

void test_tan_grad_case4() {
  cout << "Test tan-grad case 4 (batch scalar)\t";
  auto grad = GenTensor<CheckElement>(0, 1, 10);
  auto ori = GenTensor<CheckElement>(static_cast<CheckElement>(-0.9),
                                     static_cast<CheckElement>(0.1), 10);
  auto op = TanGrad(grad, ori);
  static_assert(IsTensorWithDim<decltype(op), 1>);
  assert(op.Shape()[0] == 10);

  auto res = Evaluate(op);
  static_assert(IsTensorWithDim<decltype(res), 1>);
  assert(res.Shape()[0] == 10);

  for (size_t i = 0; i < 10; ++i) {
    auto check =
        grad[i].Value() / std::cos(ori[i].Value()) / std::cos(ori[i].Value());
    assert(fabs(res[i].Value() - check) < 0.001f);
  }
  cout << "done" << endl;
}

void test_tan_grad_case5() {
  cout << "Test tan-grad case 5 (grad broadcast)\t";
  auto grad = GenTensor<CheckElement>(0, 1, 10, 7);
  auto ori = GenTensor<CheckElement>(static_cast<CheckElement>(-0.9),
                                     static_cast<CheckElement>(0.01), 2, 10, 7);
  auto op = TanGrad(grad, ori);
  static_assert(IsThreeDArray<decltype(op)>);
  assert(op.Shape()[0] == 2);
  assert(op.Shape()[1] == 10);
  assert(op.Shape()[2] == 7);

  auto res = Evaluate(op);
  static_assert(IsThreeDArray<decltype(res)>);
  assert(res.Shape()[0] == 2);
  assert(res.Shape()[1] == 10);
  assert(res.Shape()[2] == 7);

  for (size_t p = 0; p < 2; ++p) {
    for (size_t i = 0; i < 10; ++i) {
      for (size_t k = 0; k < 7; ++k) {
        auto check =
            grad(i, k) / std::cos(ori(p, i, k)) / std::cos(ori(p, i, k));
        assert(fabs(res(p, i, k) - check) < 0.001f);
      }
    }
  }
  cout << "done" << endl;
}
} // namespace

namespace Test::Operation::Math {
void test_tan_grad() {
  test_tan_grad_case1();
  test_tan_grad_case2();
  test_tan_grad_case3();
  test_tan_grad_case4();
  test_tan_grad_case5();
}
} // namespace Test::Operation::Math