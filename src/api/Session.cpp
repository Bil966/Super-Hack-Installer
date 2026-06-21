#include <api/Session.hpp>

Session& Session::get() {
    static Session instance;
    return instance;
}

void Session::setUsername(const std::string& username) {
    m_username = username;
}

const std::string& Session::getUsername() const {
    return m_username;
}

void Session::setToken(const std::string& token) {
    m_token = token;
}

const std::string& Session::getToken() const {
    return m_token;
}

void Session::setLoggedIn(bool value) {
    m_loggedIn = value;
}

bool Session::isLoggedIn() const {
    return m_loggedIn;
}

void Session::setPremium(bool value) {
    m_premium = value;
}

bool Session::isPremium() const {
    return m_premium;
}

void Session::clear() {
    m_username.clear();
    m_token.clear();

    m_loggedIn = false;
    m_premium = false;
}
