#include <MetaNN/meta_nn.h>
#include <calculate_tags.h>
#include <data_gen.h>

#include <cmath>
#include <iostream>
using namespace std;
using namespace MetaNN;

namespace {
void test_square_case1() {
  cout << "Test square case 1 (scalar)\t";
  {
    Scalar<CheckElement, CheckDevice> ori(static_cast<CheckElement>(0.3348));
    auto op = Square(ori);
    auto res = Evaluate(op);
    assert(fabs(res.Value() - 0.3348 * 0.3348) < 0.001f);
  }
  cout << "done" << endl;
}

void test_square_case2() {
  cout << "Test square case 2 (matrix)\t";
  auto ori =
      GenTensor<CheckElement>(-1, static_cast<CheckElement>(0.01), 10, 7);
  auto op = Square(ori);
  static_assert(IsMatrix<decltype(op)>);
  assert(op.Shape()[0] == 10);
  assert(op.Shape()[1] == 7);

  auto res = Evaluate(op);
  static_assert(IsMatrix<decltype(res)>);
  assert(res.Shape()[0] == 10);
  assert(res.Shape()[1] == 7);

  for (size_t i = 0; i < 10; ++i) {
    for (size_t k = 0; k < 7; ++k) {
      auto value = ori(i, k) * ori(i, k);
      assert(fabs(res(i, k) - value) < 0.001f);
    }
  }
  cout << "done" << endl;
}

void test_square_case3() {
  cout << "Test square case 3 (3d-array)\t";
  auto ori =
      GenTensor<CheckElement>(-1, static_cast<CheckElement>(0.01), 2, 10, 7);
  auto op = Square(ori);
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
        auto value = ori(p, i, k) * ori(p, i, k);
        assert(fabs(res(p, i, k) - value) < 0.001f);
      }
    }
  }
  cout << "done" << endl;
}

void test_square_case4() {
  cout << "Test square case 4 (batch scalar)\t";
  auto ori = GenTensor<CheckElement>(-1, static_cast<CheckElement>(0.1), 10);
  auto op = Square(ori);
  static_assert(IsTensorWithDim<decltype(op), 1>);
  assert(op.Shape()[0] == 10);

  auto res = Evaluate(op);
  static_assert(IsTensorWithDim<decltype(res), 1>);
  assert(res.Shape()[0] == 10);

  for (size_t i = 0; i < 10; ++i) {
    auto value = ori[i].Value() * ori[i].Value();
    assert(fabs(res[i].Value() - value) < 0.001f);
  }
  cout << "done" << endl;
}
}  // namespace

namespace Test::Operation::Math {
void test_square() {
  test_square_case1();
  test_square_case2();
  test_square_case3();
  test_square_case4();
}
}  // namespace Test::Operation::Math

namespace {
void test_square_grad_case1() {
  cout << "Test square-grad case 1 (scalar)\t";
  {
    Scalar<CheckElement, CheckDevice> grad(1.5);
    Scalar<CheckElement, CheckDevice> ori(static_cast<CheckElement>(0.3348));
    auto op = SquareGrad(grad, ori);
    auto res = Evaluate(op);

    auto check = 3 * 0.3348;
    assert(fabs(res.Value() - check) < 0.001f);
  }
  cout << "done" << endl;
}

void test_square_grad_case2() {
  cout << "Test square-grad case 2 (matrix)\t";
  auto grad = GenTensor<CheckElement>(0, 1, 10, 7);
  auto ori = GenTensor<CheckElement>(static_cast<CheckElement>(-0.5),
                                     static_cast<CheckElement>(0.01), 10, 7);
  auto op = SquareGrad(grad, ori);
  static_assert(IsMatrix<decltype(op)>);
  assert(op.Shape()[0] == 10);
  assert(op.Shape()[1] == 7);

  auto res = Evaluate(op);
  static_assert(IsMatrix<decltype(res)>);
  assert(res.Shape()[0] == 10);
  assert(res.Shape()[1] == 7);

  for (size_t i = 0; i < 10; ++i) {
    for (size_t k = 0; k < 7; ++k) {
      auto check = 2 * grad(i, k) * ori(i, k);
      assert(fabs(res(i, k) - check) < 0.001f);
    }
  }
  cout << "done" << endl;
}

void test_square_grad_case3() {
  cout << "Test square-grad case 3 (3d-array)\t";
  auto grad = GenTensor<CheckElement>(0, 1, 2, 10, 7);
  auto ori = GenTensor<CheckElement>(static_cast<CheckElement>(-0.9),
                                     static_cast<CheckElement>(0.01), 2, 10, 7);
  auto op = SquareGrad(grad, ori);
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
        auto check = 2 * grad(p, i, k) * ori(p, i, k);
        assert(fabs(res(p, i, k) - check) < 0.001f);
      }
    }
  }
  cout << "done" << endl;
}

void test_square_grad_case4() {
  cout << "Test square-grad case 4 (batch scalar)\t";
  auto grad = GenTensor<CheckElement>(0, 1, 10);
  auto ori = GenTensor<CheckElement>(static_cast<CheckElement>(-0.9),
                                     static_cast<CheckElement>(0.1), 10);
  auto op = SquareGrad(grad, ori);
  static_assert(IsTensorWithDim<decltype(op), 1>);
  assert(op.Shape()[0] == 10);

  auto res = Evaluate(op);
  static_assert(IsTensorWithDim<decltype(res), 1>);
  assert(res.Shape()[0] == 10);

  for (size_t i = 0; i < 10; ++i) {
    auto check = 2 * grad[i].Value() * ori[i].Value();
    assert(fabs(res[i].Value() - check) < 0.001f);
  }
  cout << "done" << endl;
}

void test_square_grad_case5() {
  cout << "Test square-grad case 5 (grad broadcast)\t";
  auto grad = GenTensor<CheckElement>(0, 1, 10, 7);
  auto ori = GenTensor<CheckElement>(static_cast<CheckElement>(-0.9),
                                     static_cast<CheckElement>(0.01), 2, 10, 7);
  auto op = SquareGrad(grad, ori);
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
        auto check = 2 * grad(i, k) * ori(p, i, k);
        assert(fabs(res(p, i, k) - check) < 0.001f);
      }
    }
  }
  cout << "done" << endl;
}
}  // namespace

namespace Test::Operation::Math {
void test_square_grad() {
  test_square_grad_case1();
  test_square_grad_case2();
  test_square_grad_case3();
  test_square_grad_case4();
  test_square_grad_case5();
}
}  // namespace Test::Operation::Math