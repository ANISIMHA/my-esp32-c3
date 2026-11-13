#pragma once
#include <string>
#include <type_traits>

template <typename T>
auto espnow_extract_str(const T &info, int) -> decltype(std::string(info.data.begin(), info.data.end())) {
  return std::string(info.data.begin(), info.data.end());
}

template <typename T>
auto espnow_extract_str(const T &info, long) -> decltype(std::string(reinterpret_cast<const char *>(info.data), info.len)) {
  return std::string(reinterpret_cast<const char *>(info.data), info.len);
}

template <typename T>
auto espnow_extract_rssi(const T &info, int) -> decltype(static_cast<int>(info.rssi)) {
  return static_cast<int>(info.rssi);
}

template <typename T>
auto espnow_extract_rssi(const T &info, long) -> decltype(static_cast<int>(info.rx_ctrl->rssi)) {
  return static_cast<int>(info.rx_ctrl->rssi);
}
