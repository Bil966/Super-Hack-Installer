#pragma once

#include <string>

namespace shi::api::endpoints {

    inline const std::string BASE_URL = "https://api.superhack.com";

    inline const std::string LOGIN = "/auth/login";
    inline const std::string LICENSE = "/auth/license";
    inline const std::string VERIFY = "/auth/verify";

    inline const std::string VERSION = "/installer/version";
    inline const std::string DOWNLOAD = "/installer/download";

}
