#pragma once

#include <Geode/Geode.hpp>
#include <string>

namespace shi::config {

    struct ConfigData {
        bool autoLogin = false;
        bool rememberMe = true;

        std::string loginType = "account"; // account | license

        std::string username;
        std::string token;
        std::string licenseKey;

        std::string installedVersion;
    };

    bool load();
    bool save();

    ConfigData& data();

    void reset();

}
