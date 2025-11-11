#include "color/color.h"
#include <array>
#include <cstddef>
#include <cstdint>

constexpr float toFloat(uint8_t c) {
  return c / 255.0f;
}

constexpr std::array<float, 3> buildColor(const std::array<uint8_t, 3> &rgb) {
  std::array<float, 3> res{};
  for (size_t i = 0; i < rgb.size(); i++) {
    res[i] = toFloat(rgb[i]);
  }
  return res;
}

constexpr std::array<uint8_t, 3> STICKS_RGB = {208, 171, 160};
constexpr std::array<uint8_t, 3> BACKGROUND_RGB = {222, 196, 161};
constexpr std::array<uint8_t, 3> SLITS_RGB = {237, 207, 142};

constinit const std::array<float, 3> STICKS_COLOR = buildColor(STICKS_RGB);
constinit const std::array<float, 3> BACKGROUND_COLOR =
  buildColor(BACKGROUND_RGB);
constinit const std::array<float, 3> BACKGROUND_SLITS_COLOR =
  buildColor(SLITS_RGB);
