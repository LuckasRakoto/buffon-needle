#include <array>

constexpr float _toFloat(uint8_t c) {
  return c / 255.0f;
}

constexpr std::array<float, 3> _buildColor(const std::array<uint8_t, 3> &rgb) {
  std::array<float, 3> res{};
  for (size_t i = 0; i < rgb.size(); i++) {
    res[i] = _toFloat(rgb[i]);
  }
  return res;
}

constexpr std::array<float, 3> STICKS_COLOR = _buildColor({208, 171, 160});
constexpr std::array<float, 3> BACKGROUND_COLOR = _buildColor({222, 196, 161});
constexpr std::array<float, 3> BACKGROUND_SLITS_COLOR =
  _buildColor({237, 207, 142});
