#include "API.hpp"

#include <Geode/Geode.hpp>
#include <Geode/utils/web.hpp>

using namespace geode::prelude;

static constexpr const char* BASE_URL =
    "https://your-api-domain.com";

void API::login(
    const std::string& username,
    const std::string& password,
    std::function<void(bool, std::string)> callback
) {
    web::WebRequest request;

    request.header("Content-Type", "application/json");

    matjson::Value body = {
        { "username", username },
        { "password", password }
    };

    request.post(
        std::string(BASE_URL) + "/login",
        body.dump()
    ).listen([callback](web::WebResponse* res) {
        if (!res || !res->ok()) {
            callback(false, "Network Error");
            return;
        }

        auto json = res->json();

        if (!json) {
            callback(false, "Invalid JSON");
            return;
        }

        bool success = json->contains("success")
            ? (*json)["success"].asBool().unwrapOr(false)
            : false;

        std::string message = json->contains("message")
            ? (*json)["message"].asString().unwrapOr("")
            : "";

        callback(success, message);
    });
}

void API::verifyToken(
    const std::string& token,
    std::function<void(bool)> callback
) {
    web::WebRequest request;

    request.header("Authorization", "Bearer " + token);

    request.get(
        std::string(BASE_URL) + "/verify"
    ).listen([callback](web::WebResponse* res) {
        callback(res && res->ok());
    });
}

void API::downloadHack(
    std::function<void(std::string)> callback
) {
    web::WebRequest request;

    request.get(
        std::string(BASE_URL) + "/download"
    ).listen([callback](web::WebResponse* res) {
        if (!res || !res->ok()) {
            callback("");
            return;
        }

        callback(res->string().unwrapOr(""));
    });
}
