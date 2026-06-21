#include "config/Config.hpp"

using namespace geode::prelude;

namespace shi::config {

    static ConfigData g_config;

    ConfigData& data() {
        return g_config;
    }

    bool load() {
        auto saved = Mod::get()->getSavedValue<matjson::Value>("config", matjson::Value::object());

        if (!saved.isObject())
            return false;

        auto obj = saved.asObject();

        g_config.autoLogin = obj["autoLogin"].asBool().unwrapOr(false);
        g_config.rememberMe = obj["rememberMe"].asBool().unwrapOr(true);

        g_config.loginType = obj["loginType"].asString().unwrapOr("account");

        g_config.username = obj["username"].asString().unwrapOr("");
        g_config.token = obj["token"].asString().unwrapOr("");
        g_config.licenseKey = obj["licenseKey"].asString().unwrapOr("");

        g_config.installedVersion = obj["installedVersion"].asString().unwrapOr("");

        return true;
    }

    bool save() {

        matjson::Value obj = matjson::Value::object();

        obj["autoLogin"] = g_config.autoLogin;
        obj["rememberMe"] = g_config.rememberMe;

        obj["loginType"] = g_config.loginType;

        obj["username"] = g_config.username;
        obj["token"] = g_config.token;
        obj["licenseKey"] = g_config.licenseKey;

        obj["installedVersion"] = g_config.installedVersion;

        Mod::get()->setSavedValue("config", obj);

        return true;
    }

    void reset() {
        g_config = ConfigData();
        save();
    }

}
