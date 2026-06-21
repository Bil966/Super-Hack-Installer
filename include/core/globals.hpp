#pragma once

#include <string>

namespace shi::core {

    struct RuntimeData {

        // Login
        bool isLoggedIn = false;
        bool isPremium = false;

        // User
        std::string username;
        std::string token;

        // Installer
        bool isInstalled = false;
        std::string installedVersion;

        // Server
        bool apiOnline = false;
        std::string latestVersion;

    };

    RuntimeData& data();

    void reset();

}
