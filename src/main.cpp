#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "ui/MainPopup.hpp"

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        auto bottomMenu = this->getChildByID("bottom-menu");

        if (!bottomMenu)
            return true;

        auto sprite = CCSprite::create(
            (Mod::get()->getResourcesDir() / "SUPERHACK_LOGO.png").string().c_str()
        );

        if (!sprite) {
            log::error("Failed to load SUPERHACK_LOGO.png");
            return true;
        }

        sprite->setScale(0.35f);

        auto button = CCMenuItemSpriteExtra::create(
            sprite,
            this,
            menu_selector(MyMenuLayer::onSuperHack)
        );

        button->setID("superhack-button");

        bottomMenu->addChild(button);
        bottomMenu->updateLayout();

        return true;
    }

    void onSuperHack(CCObject*) {
        MainPopup::create()->show();
    }
};
