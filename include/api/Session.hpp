#pragma once

#include <string>

class Session {
public:
    static Session& get();

    // User
    void setUsername(const std::string& username);
    const std::string& getUsername() const;

    // Token
    void setToken(const std::string& token);
    const std::string& getToken() const;

    // Login
    void setLoggedIn(bool value);
    bool isLoggedIn() const;

    // Premium
    void setPremium(bool value);
    bool isPremium() const;

    // Logout
    void clear();

private:
    Session() = default;

private:
    std::string m_username;
    std::string m_token;

    bool m_loggedIn = false;
    bool m_premium = false;
};
