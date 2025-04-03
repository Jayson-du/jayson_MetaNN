namespace Test::Layer {
namespace Recurrent {
void test_recurrent_layer();

void test_gru();
} // namespace Recurrent

void test_recurrent() {
  Recurrent::test_recurrent_layer();

  Recurrent::test_gru();
}
} // namespace Test::Layer