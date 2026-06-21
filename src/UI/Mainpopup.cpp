#include "MainPopup.hpp"

using namespace geode::prelude;

bool MainPopup::setup() {
    this->setTitle("SUPER HACK INSTALLER");

    auto label = CCLabelBMFont::create(
        "Super Hack Menu Ready To Install",
        "goldFont.fnt"
    );

    label->setScale(0.45f);
    label->setPosition(
        m_size.width / 2,
        m_size.height / 2 + 10.f
    );

    m_mainLayer->addChild(label);

    auto footer = CCLabelBMFont::create(
        "Made by Homeless Team & NeonGD",
        "chatFont.fnt"
    );

    footer->setScale(0.45f);
    footer->setPosition(
        m_size.width / 2,
        20.f
    );

    m_mainLayer->addChild(footer);

    return true;
}

MainPopup* MainPopup::create() {
    auto ret = new MainPopup();

    if (ret && ret->initAnchored(360.f, 220.f)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}
