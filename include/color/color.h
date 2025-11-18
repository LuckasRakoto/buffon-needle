#pragma once
#include <array>

class Color {
public:
  constexpr Color(std::array<uint8_t, 3> raw);
  std::array<float, 3> unpack() const;

  float r;
  float g;
  float b;
};

extern constinit const Color STICKS_COLOR;
extern constinit const Color BACKGROUND_COLOR;
extern constinit const Color BACKGROUND_SLITS_COLOR;
