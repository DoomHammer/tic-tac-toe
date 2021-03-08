#pragma once

#if __cpp_lib_to_underlying
#include <utility>
using std::to_underlying;
#else
template<class Enum>
constexpr auto to_underlying(Enum e) noexcept {
    return static_cast<std::underlying_type_t<Enum>>(e);
}
#endif
