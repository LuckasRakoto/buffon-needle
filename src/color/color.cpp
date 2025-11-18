#include "color/color.h"
#include <array>
#include <cstddef>
#include <cstdint>

constexpr float toFloat(uint8_t c) {
  return c / 255.0f;
}

constexpr Color::Color(std::array<uint8_t, 3> raw)
    : r(toFloat(raw[0])), g(toFloat(raw[1])), b(toFloat(raw[2])) {
}

std::array<float, 3> Color::unpack() const {
  return {r, g, b};
}

constexpr std::array<uint8_t, 3> STICKS_RGB = {208, 171, 160};
constexpr std::array<uint8_t, 3> BACKGROUND_RGB = {222, 196, 161};
constexpr std::array<uint8_t, 3> SLITS_RGB = {237, 207, 142};

constinit const Color STICKS_COLOR = Color(STICKS_RGB);
constinit const Color BACKGROUND_COLOR = Color(BACKGROUND_RGB);
constinit const Color BACKGROUND_SLITS_COLOR = Color(SLITS_RGB);
