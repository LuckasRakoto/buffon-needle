#include "color/color.h"
#include <array>
#include <cstddef>
#include <cstdint>

constexpr float toFloat(uint8_t c) {
  return c / 255.0f;
}

constexpr Color buildColor(const std::array<uint8_t, 3> &rgb) {
  return {
      .r = toFloat(rgb[0]),
      .g = toFloat(rgb[1]),
      .b = toFloat(rgb[2]),
  };
}

constexpr std::array<uint8_t, 3> STICKS_RGB = {208, 171, 160};
constexpr std::array<uint8_t, 3> BACKGROUND_RGB = {222, 196, 161};
constexpr std::array<uint8_t, 3> SLITS_RGB = {237, 207, 142};

constinit const Color STICKS_COLOR = buildColor(STICKS_RGB);
constinit const Color BACKGROUND_COLOR = buildColor(BACKGROUND_RGB);
constinit const Color BACKGROUND_SLITS_COLOR = buildColor(SLITS_RGB);
