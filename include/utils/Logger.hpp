
#pragma once

#include <Geode/Geode.hpp>

namespace shi::logger {

    void info(std::string const& message);

    template <typename... Args>
    void info(fmt::format_string<Args...> fmt, Args&&... args) {
        geode::log::info(fmt, std::forward<Args>(args)...);
    }

    void warn(std::string const& message);

    template <typename... Args>
    void warn(fmt::format_string<Args...> fmt, Args&&... args) {
        geode::log::warn(fmt, std::forward<Args>(args)...);
    }

    void error(std::string const& message);

    template <typename... Args>
    void error(fmt::format_string<Args...> fmt, Args&&... args) {
        geode::log::error(fmt, std::forward<Args>(args)...);
    }

    void debug(std::string const& message);

    template <typename... Args>
    void debug(fmt::format_string<Args...> fmt, Args&&... args) {
        geode::log::debug(fmt, std::forward<Args>(args)...);
    }

}

