#include <cstdint>

#include <catch2/catch_test_macros.hpp>
#include <VExercise2.h>

TEST_CASE("Test VExercise2") {
  // Test a variety of inputs
  uint16_t init = 0;
  VExercise2 model;

  // Cycle the clock a few times with reset asserted
  for(int i = 0; i < 5; i++) {
    // Call the Verilog module
    model.clk = 1;
    model.reset = 0;
    model.init = init;
    model.eval();
    model.clk = 0;
    model.reset = 1;
    model.eval();

    // Check if the output is valid
    REQUIRE((uint16_t) ~model.out == init);
    init = rand() % 0xFFFF;
  }

  // Turn off reset
  uint16_t state = model.out;
  model.reset = 0;
  model.clk = 1;
  model.eval();

  // Test a variety of inputs
  for(int i = 0; i < 1000; i++) {
    // Generate a random input value
    model.clk = 0;
    model.eval();

    // Compute the next state of the LFSR
    uint16_t bit =
        ((state >> 10) ^ (state >> 8) ^ (state >> 3) ^ (state >> 1)) & 1;
    state = (state << 1) | bit;
    // Check if the output is correct
    REQUIRE(model.out == state);
    model.clk = 1;
    model.eval();
  }
}