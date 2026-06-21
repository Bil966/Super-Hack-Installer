#include "MainPopup.hpp"
#include "LoginPopup.hpp"

using namespace geode::prelude;

MainPopup* MainPopup::create() {
    auto ret = new MainPopup();

    if (ret && ret->initAnchored(340.f, 240.f)) {
        ret->autorelease();
        return ret;
    }

    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool MainPopup::setup() {
    setTitle("Super Hack Installer");

    auto winSize = m_size;

    auto menu = CCMenu::create();
    menu->setPosition({0.f, 0.f});
    m_mainLayer->addChild(menu);

    // Install
    auto installBtn = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("Install"),
        this,
        menu_selector(MainPopup::onInstall)
    );
    installBtn->setPosition({-80.f, 40.f});
    menu->addChild(installBtn);

    // Reinstall
    auto reinstallBtn = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("Reinstall"),
        this,
        menu_selector(MainPopup::onReinstall)
    );
    reinstallBtn->setPosition({80.f, 40.f});
    menu->addChild(reinstallBtn);

    // Uninstall
    auto uninstallBtn = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("Uninstall"),
        this,
        menu_selector(MainPopup::onUninstall)
    );
    uninstallBtn->setPosition({-80.f, -20.f});
    menu->addChild(uninstallBtn);

    // Login
    auto loginBtn = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("Login"),
        this,
        menu_selector(MainPopup::onLogin)
    );
    loginBtn->setPosition({80.f, -20.f});
    menu->addChild(loginBtn);

    // Footer
    auto label = CCLabelBMFont::create(
        "Made by Homeless Team",
        "goldFont.fnt"
    );
    label->setScale(0.35f);
    label->setPosition({winSize.width / 2, 15.f});
    m_mainLayer->addChild(label);

    return true;
}

void MainPopup::onInstall(CCObject*) {
    FLAlertLayer::create(
        "Install",
        "Install chưa được lập trình.",
        "OK"
    )->show();
}

void MainPopup::onReinstall(CCObject*) {
    FLAlertLayer::create(
        "Reinstall",
        "Reinstall chưa được lập trình.",
        "OK"
    )->show();
}

void MainPopup::onUninstall(CCObject*) {
    FLAlertLayer::create(
        "Uninstall",
        "Uninstall chưa được lập trình.",
        "OK"
    )->show();
}

void MainPopup::onLogin(CCObject*) {
    LoginPopup::create()->show();
}
