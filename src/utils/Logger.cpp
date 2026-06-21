
#include "utils/Logger.hpp"

namespace shi::logger {

void info(std::string const& message) {
    geode::log::info("[SHI] {}", message);
}

void warn(std::string const& message) {
    geode::log::warn("[SHI] {}", message);
}

void error(std::string const& message) {
    geode::log::error("[SHI] {}", message);
}

void debug(std::string const& message) {
    geode::log::debug("[SHI] {}", message);
}

}

