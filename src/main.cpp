
#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(UpdatedMenuLayer, MenuLayer) {
	bool init() {

		if (!MenuLayer::init()) {
			return false;
		}

		auto EditorShortcutButton = CCMenuItemSpriteExtra::create(
			CCSprite::create("editorShortcutBtn001.png"_spr),
			this,
	
			menu_selector(UpdatedMenuLayer::onEditorShortcutButton)
		);
		auto location = "side-menu"; //initializes as side-menu as fallback
		std::string locationSetting = Mod::get()->getSettingValue<std::string>("button_location");
		
		if (locationSetting == "left") {
			location = "side-menu";
		} else if (locationSetting == "right") {
			location = "right-side-menu";
		} else if (locationSetting == "bottom") {
			location = "bottom-menu";
		}
		
		auto menu = this->getChildByID(location);
		menu->addChild(EditorShortcutButton);

		EditorShortcutButton->setID("EditorShortcut-button"_spr);

		menu->updateLayout();

		return true;
	}

	void onEditorShortcutButton(CCObject*) {
		CCScene* newScene = LevelBrowserLayer::scene(GJSearchObject::create(SearchType::MyLevels));
		CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, newScene));
	}
};