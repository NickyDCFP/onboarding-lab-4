#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <VExercise4.h>

uint8_t selector(uint8_t sel, uint8_t alpha, uint8_t beta, uint8_t gamma) {
  switch(sel) {
    case 0:
      return alpha;
    case 1:
      return beta;
    case 2:
      return gamma;
    default:
      return alpha & (beta | gamma);
  }
}

TEST_CASE("Decoder") {
  VExercise4 model;
  model.alpha = 1;
  model.beta = 2;
  model.gamma = 3;
  model.cs = 1;

  for(model.sel = 0; model.sel < 4; ++model.sel) {
    model.eval();
    REQUIRE(
        model.out == selector(model.sel, model.alpha, model.beta, model.gamma));
  }
  model.cs = 0;
  model.eval();
  for(model.sel = 0; model.sel < 4; ++model.sel) {
    model.eval();
    REQUIRE(model.out == 0);
  }
}