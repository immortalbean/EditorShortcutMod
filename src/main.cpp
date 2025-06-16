
#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(UpdatedMenuLayer, MenuLayer) {
	bool init() {


		auto location = "side-menu"; //initializes as side-menu as fallback
		auto buttonStyle = "editorShortcutBtn001.png"_spr;
		std::string locationSetting = Mod::get()->getSettingValue<std::string>("button_location");
		
		if (locationSetting == "left") {
			location = "side-menu";
		} else if (locationSetting == "right") {
			location = "right-side-menu";
		} else if (locationSetting == "bottom") {
			location = "bottom-menu";
			buttonStyle = "editorShortcutBtn003.png"_spr;
		} else if (locationSetting == "center") {
			location = "main-menu";
			buttonStyle = "editorShortcutBtn002.png"_spr;
		} else if (locationSetting == "top left") {
			location = "close-menu";
			buttonStyle = "editorShortcutBtn005.png"_spr;
		} else if (locationSetting == "top right") {
			location = "top-right-menu";
		}

		
		if (!MenuLayer::init()) {
			return false;
		}

		auto EditorShortcutButton = CCMenuItemSpriteExtra::create(
			CCSprite::create(buttonStyle),
			this,
	
			menu_selector(UpdatedMenuLayer::onEditorShortcutButton)
		);
		
		
		auto menu = this->getChildByID(location);
		menu->addChild(EditorShortcutButton);

		EditorShortcutButton->setID("EditorShortcut-button");

		menu->updateLayout();

		return true;
	}

	void onEditorShortcutButton(CCObject*) {
		CCScene* newScene = LevelBrowserLayer::scene(GJSearchObject::create(SearchType::MyLevels));
		CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, newScene));
	}
};