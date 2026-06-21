#pragma once

#include <Geode/Geode.hpp>
#include <functional>
#include <string>

namespace shi::api {

    using SuccessCallback = std::function<void(std::string const&)>;
    using ErrorCallback = std::function<void(std::string const&)>;

    void get(
        std::string const& endpoint,
        SuccessCallback success,
        ErrorCallback error
    );

    void post(
        std::string const& endpoint,
        std::string const& body,
        SuccessCallback success,
        ErrorCallback error
    );

}
