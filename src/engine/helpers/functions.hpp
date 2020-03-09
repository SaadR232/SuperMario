#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

// ---------------------------------------------------------- //
// ---------------------------------------------------------- //
// ---------------------------------------------------------- //
// -------------------------FUNCTIONS------------------------ //
// ---------------------------------------------------------- //
// ---------------------------------------------------------- //
// ---------------------------------------------------------- //

#include <iostream>
#include <type_traits>

#include "checkers.hpp"

#ifdef ENABLE_DEBUG_MODE

namespace Debug
{
    template<typename... Ts>
    constexpr std::enable_if_t<((std::is_arithmetic_v<Ts> || is_string_v<Ts>) && ...)> print(Ts... args) noexcept
        // requires ((std::is_arithmetic_v<Ts> || is_string_v<Ts>) && ...) // C++20
    {
        ((std::cout << args), ...);
        std::cout << std::endl;
    }
} // namespace Debug

#endif // ENABLE_DEBUG_MODE

#endif