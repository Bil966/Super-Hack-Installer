#include "LoginPopup.hpp"

using namespace geode::prelude;

bool LoginPopup::setup() {
    this->setTitle("LOGIN");

    auto info = CCLabelBMFont::create(
        "Select Login Method",
        "goldFont.fnt"
    );

    info->setScale(0.45f);
    info->setPosition(
        m_size.width / 2,
        m_size.height - 45.f
    );

    m_mainLayer->addChild(info);

    // =========================
    // Account Button
    // =========================

    auto accountBtn = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("Account"),
        this,
        menu_selector(LoginPopup::onAccount)
    );

    accountBtn->setPosition(
        m_size.width / 2 - 60.f,
        m_size.height - 80.f
    );

    m_buttonMenu->addChild(accountBtn);

    // =========================
    // License Button
    // =========================

    auto licenseBtn = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("License"),
        this,
        menu_selector(LoginPopup::onLicense)
    );

    licenseBtn->setPosition(
        m_size.width / 2 + 60.f,
        m_size.height - 80.f
    );

    m_buttonMenu->addChild(licenseBtn);

    // =========================
    // Login Button
    // =========================

    auto loginBtn = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("Login"),
        this,
        menu_selector(LoginPopup::onLogin)
    );

    loginBtn->setPosition(
        m_size.width / 2,
        35.f
    );

    m_buttonMenu->addChild(loginBtn);

    updateUI();

    return true;
}

LoginPopup* LoginPopup::create() {
    auto ret = new LoginPopup();

    if (ret && ret->initAnchored(360.f, 220.f)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}

void LoginPopup::onAccount(CCObject*) {
    m_method = LoginMethod::Account;
    updateUI();
}

void LoginPopup::onLicense(CCObject*) {
    m_method = LoginMethod::License;
    updateUI();
}

void LoginPopup::onLogin(CCObject*) {
    switch (m_method) {
        case LoginMethod::Account:
            log::info("Login with Account");
            break;

        case LoginMethod::License:
            log::info("Login with License");
            break;
    }
}

void LoginPopup::updateUI() {
    switch (m_method) {
        case LoginMethod::Account:
            log::info("Current Mode: Account");
            break;

        case LoginMethod::License:
            log::info("Current Mode: License");
            break;
    }
}
