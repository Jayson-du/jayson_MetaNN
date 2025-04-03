#!/usr/bin/bash

format=clang-format

${format} --style=llvm -i ./MetaNN/data/batch/batch_sequence.h
${format} --style=llvm -i ./MetaNN/data/bias_vector.h
${format} --style=llvm -i ./MetaNN/data/dynamic.h
${format} --style=llvm -i ./MetaNN/data/facilities/allocators.h
${format} --style=llvm -i ./MetaNN/data/facilities/category_tags.h
${format} --style=llvm -i ./MetaNN/data/facilities/continuous_memory.h
${format} --style=llvm -i ./MetaNN/data/facilities/device_tags.h
${format} --style=llvm -i ./MetaNN/data/facilities/lower_access.h
${format} --style=llvm -i ./MetaNN/data/facilities/shape.h
${format} --style=llvm -i ./MetaNN/data/facilities/traits.h
${format} --style=llvm -i ./MetaNN/data/scalable_tensor.h
${format} --style=llvm -i ./MetaNN/data/tensor.h
${format} --style=llvm -i ./MetaNN/data/trivial_tensor.h
${format} --style=llvm -i ./MetaNN/data/zero_tensor.h
${format} --style=llvm -i ./MetaNN/data_copy/data_copy.h
${format} --style=llvm -i ./MetaNN/evaluate/eval_buffer.h
${format} --style=llvm -i ./MetaNN/evaluate/eval_dispatcher.h
${format} --style=llvm -i ./MetaNN/evaluate/eval_group.h
${format} --style=llvm -i ./MetaNN/evaluate/eval_handle.h
${format} --style=llvm -i ./MetaNN/evaluate/eval_item.h
${format} --style=llvm -i ./MetaNN/evaluate/eval_plan.h
${format} --style=llvm -i ./MetaNN/facilities/cont_metafuns/helpers.h
${format} --style=llvm -i ./MetaNN/facilities/cont_metafuns/map.h
${format} --style=llvm -i ./MetaNN/facilities/cont_metafuns/multi_map.h
${format} --style=llvm -i ./MetaNN/facilities/cont_metafuns/set.h
${format} --style=llvm -i ./MetaNN/facilities/cont_metafuns/value_sequential.h
${format} --style=llvm -i ./MetaNN/facilities/null_param.h
${format} --style=llvm -i ./MetaNN/facilities/traits.h
${format} --style=llvm -i ./MetaNN/facilities/type_id.h
${format} --style=llvm -i ./MetaNN/facilities/var_type_dict.h
${format} --style=llvm -i ./MetaNN/layers/composite/bias_layer.h
${format} --style=llvm -i ./MetaNN/layers/composite/compose_kernel.h
${format} --style=llvm -i ./MetaNN/layers/composite/linear_layer.h
${format} --style=llvm -i ./MetaNN/layers/composite/single_layer_perceptron.h
${format} --style=llvm -i ./MetaNN/layers/composite/weight_layer.h
${format} --style=llvm -i ./MetaNN/layers/facilities/interface_fun.h
${format} --style=llvm -i ./MetaNN/layers/facilities/layer_in_map.h
${format} --style=llvm -i ./MetaNN/layers/facilities/make_layer.h
${format} --style=llvm -i ./MetaNN/layers/facilities/policies.h
${format} --style=llvm -i ./MetaNN/layers/facilities/traits.h
${format} --style=llvm -i ./MetaNN/layers/principal/math/abs_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/math/acos_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/math/acosh_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/math/add_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/math/asin_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/math/asinh_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/math/cos_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/math/multiply_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/math/sigmoid_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/math/sin_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/math/square_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/math/substract_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/math/tan_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/math/tanh_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/nn/nll_loss_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/nn/relu_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/nn/softmax_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/others/interpolate_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/others/param_source_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/others/value_source_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/tensor/dot_layer.h
${format} --style=llvm -i ./MetaNN/layers/principal/tensor/permute_layer.h
${format} --style=llvm -i ./MetaNN/layers/recurrent/gru_step.h
${format} --style=llvm -i ./MetaNN/layers/recurrent/recurrent_layer.h
${format} --style=llvm -i ./MetaNN/model/facilities/weight_buffer.h
${format} --style=llvm -i ./MetaNN/model/param_initializer/constant_filler.h
${format} --style=llvm -i ./MetaNN/model/param_initializer/facilities/fill_with_spec_dist.h
${format} --style=llvm -i ./MetaNN/model/param_initializer/facilities/policies.h
${format} --style=llvm -i ./MetaNN/model/param_initializer/gaussian_filler.h
${format} --style=llvm -i ./MetaNN/model/param_initializer/param_initializer.h
${format} --style=llvm -i ./MetaNN/model/param_initializer/uniform_filler.h
${format} --style=llvm -i ./MetaNN/model/param_initializer/var_scale_filler.h
${format} --style=llvm -i ./MetaNN/model/weight_cont/grad_collector.h
${format} --style=llvm -i ./MetaNN/model/weight_cont/load_buffer.h
${format} --style=llvm -i ./MetaNN/operation/conv.h
${format} --style=llvm -i ./MetaNN/operation/facilities/instance_id.h
${format} --style=llvm -i ./MetaNN/operation/facilities/operation_frame.h
${format} --style=llvm -i ./MetaNN/operation/facilities/organizer.h
${format} --style=llvm -i ./MetaNN/operation/facilities/policies.h
${format} --style=llvm -i ./MetaNN/operation/facilities/tags.h
${format} --style=llvm -i ./MetaNN/operation/facilities/tail_calculator.h
${format} --style=llvm -i ./MetaNN/operation/math/abs.h
${format} --style=llvm -i ./MetaNN/operation/math/acos.h
${format} --style=llvm -i ./MetaNN/operation/math/acosh.h
${format} --style=llvm -i ./MetaNN/operation/math/add.h
${format} --style=llvm -i ./MetaNN/operation/math/asin.h
${format} --style=llvm -i ./MetaNN/operation/math/asinh.h
${format} --style=llvm -i ./MetaNN/operation/math/cos.h
${format} --style=llvm -i ./MetaNN/operation/math/divide.h
${format} --style=llvm -i ./MetaNN/operation/math/exp.h
${format} --style=llvm -i ./MetaNN/operation/math/multiply.h
${format} --style=llvm -i ./MetaNN/operation/math/negative.h
${format} --style=llvm -i ./MetaNN/operation/math/reduce_sum.h
${format} --style=llvm -i ./MetaNN/operation/math/sigmoid.h
${format} --style=llvm -i ./MetaNN/operation/math/sign.h
${format} --style=llvm -i ./MetaNN/operation/math/sin.h
${format} --style=llvm -i ./MetaNN/operation/math/square.h
${format} --style=llvm -i ./MetaNN/operation/math/substract.h
${format} --style=llvm -i ./MetaNN/operation/math/tan.h
${format} --style=llvm -i ./MetaNN/operation/math/tanh.h
${format} --style=llvm -i ./MetaNN/operation/nn/facilities/organizer.h
${format} --style=llvm -i ./MetaNN/operation/nn/nll_loss.h
${format} --style=llvm -i ./MetaNN/operation/nn/relu.h
${format} --style=llvm -i ./MetaNN/operation/nn/softmax.h
${format} --style=llvm -i ./MetaNN/operation/others/interpolate.h
${format} --style=llvm -i ./MetaNN/operation/tensor/dot.h
${format} --style=llvm -i ./MetaNN/operation/tensor/permute.h
${format} --style=llvm -i ./MetaNN/operation/tensor/reshape.h
${format} --style=llvm -i ./MetaNN/operation/tensor/slice.h
${format} --style=llvm -i ./MetaNN/operation/tensor/tile.h
${format} --style=llvm -i ./MetaNN/policies/policy_container.h
${format} --style=llvm -i ./MetaNN/policies/policy_macro_begin.h
${format} --style=llvm -i ./MetaNN/policies/policy_operations.h
${format} --style=llvm -i ./Tests/DataOpTest/data/_.h
${format} --style=llvm -i ./Tests/DataOpTest/data/facilities/_.h
${format} --style=llvm -i ./Tests/DataOpTest/data/facilities/test_shape.cpp
${format} --style=llvm -i ./Tests/DataOpTest/data/test_bias_vector.cpp
${format} --style=llvm -i ./Tests/DataOpTest/data/test_dynamic.cpp
${format} --style=llvm -i ./Tests/DataOpTest/data/test_scalable_tensor.cpp
${format} --style=llvm -i ./Tests/DataOpTest/data/test_scalar.cpp
${format} --style=llvm -i ./Tests/DataOpTest/data/test_tensor.cpp
${format} --style=llvm -i ./Tests/DataOpTest/data/test_trivial_tensor.cpp
${format} --style=llvm -i ./Tests/DataOpTest/data/test_zero_tensor.cpp
${format} --style=llvm -i ./Tests/DataOpTest/main.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/_.h
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/_.h
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_abs.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_acos.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_acosh.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_add.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_asin.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_asinh.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_cos.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_divide.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_exp.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_multiply.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_negative.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_reduce_sum.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_sigmoid.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_sign.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_sin.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_square.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_substract.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_tan.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/math/test_tanh.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/nn/_.h
${format} --style=llvm -i ./Tests/DataOpTest/operation/nn/test_nll_loss.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/nn/test_relu.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/nn/test_softmax.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/others/_.h
${format} --style=llvm -i ./Tests/DataOpTest/operation/others/test_interpolate.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/tensor/_.h
${format} --style=llvm -i ./Tests/DataOpTest/operation/tensor/test_dot.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/tensor/test_permute.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/tensor/test_reshape.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/tensor/test_slice.cpp
${format} --style=llvm -i ./Tests/DataOpTest/operation/tensor/test_tile.cpp
${format} --style=llvm -i ./Tests/LayerTest/composite/_.h
${format} --style=llvm -i ./Tests/LayerTest/composite/test_bias_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/composite/test_compose_kenrel.cpp
${format} --style=llvm -i ./Tests/LayerTest/composite/test_linear_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/composite/test_single_layer_perceptron.cpp
${format} --style=llvm -i ./Tests/LayerTest/composite/test_weight_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/main.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/_.h
${format} --style=llvm -i ./Tests/LayerTest/principal/math/_.h
${format} --style=llvm -i ./Tests/LayerTest/principal/math/test_abs_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/math/test_acos_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/math/test_acosh_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/math/test_add_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/math/test_asin_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/math/test_asinh_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/math/test_cos_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/math/test_multiply_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/math/test_sigmoid_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/math/test_sin_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/math/test_square_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/math/test_substract_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/math/test_tan_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/math/test_tanh_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/nn/_.h
${format} --style=llvm -i ./Tests/LayerTest/principal/nn/test_nll_loss_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/nn/test_relu_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/nn/test_softmax_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/others/_.h
${format} --style=llvm -i ./Tests/LayerTest/principal/others/test_interpolate_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/others/test_param_source_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/others/test_value_source_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/tensor/_.h
${format} --style=llvm -i ./Tests/LayerTest/principal/tensor/test_dot_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/principal/tensor/test_permute_layer.cpp
${format} --style=llvm -i ./Tests/LayerTest/recurrent/_.h
${format} --style=llvm -i ./Tests/LayerTest/recurrent/test_gru.cpp
${format} --style=llvm -i ./Tests/LayerTest/recurrent/test_recurrent_layer.cpp
${format} --style=llvm -i ./Tests/OtherTests/facilities/test_map.cpp
${format} --style=llvm -i ./Tests/OtherTests/facilities/test_multi_map.cpp
${format} --style=llvm -i ./Tests/OtherTests/facilities/test_sequential.cpp
${format} --style=llvm -i ./Tests/OtherTests/facilities/test_set.cpp
${format} --style=llvm -i ./Tests/OtherTests/main.cpp
${format} --style=llvm -i ./Tests/OtherTests/model/_.h
${format} --style=llvm -i ./Tests/OtherTests/model/param_initializer/param_initializer.cpp
${format} --style=llvm -i ./Tests/OtherTests/model/param_initializer/test_constant_filler.cpp
${format} --style=llvm -i ./Tests/OtherTests/model/param_initializer/test_gaussian_filler.cpp
${format} --style=llvm -i ./Tests/OtherTests/model/param_initializer/test_param_initializer.cpp
${format} --style=llvm -i ./Tests/OtherTests/model/param_initializer/test_uniform_filler.cpp
${format} --style=llvm -i ./Tests/OtherTests/model/param_initializer/test_var_scale_filler.cpp
${format} --style=llvm -i ./Tests/OtherTests/policies/_.h
${format} --style=llvm -i ./Tests/OtherTests/policies/test_policy_operations.cpp
${format} --style=llvm -i ./Tests/data_gen.h