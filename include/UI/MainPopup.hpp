#pragma once

#include <Geode/Geode.hpp>
#include <Geode/ui/Popup.hpp>

using namespace geode::prelude;

class MainPopup : public Popup<> {
protected:
    bool setup() override;

    void onInstall(CCObject*);
    void onReinstall(CCObject*);
    void onUninstall(CCObject*);
    void onLogin(CCObject*);

public:
    static MainPopup* create();
};
