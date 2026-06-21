#pragma once

#include <Geode/Geode.hpp>
#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

enum class LoginMethod {
    Account,
    License
};

class LoginPopup : public Popup<> {
protected:
    LoginMethod m_method = LoginMethod::Account;

    bool setup() override;

    void onAccount(CCObject*);
    void onLicense(CCObject*);
    void onLogin(CCObject*);
    void updateUI();

public:
    static LoginPopup* create();
};
