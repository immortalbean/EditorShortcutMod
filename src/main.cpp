
#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {

		if (!MenuLayer::init()) {
			return false;
		}

		auto EditorShortcutButton = CCMenuItemSpriteExtra::create(
			CCSprite::create("editorShortcutBtn001.png"_spr),
			this,
	
			menu_selector(MyMenuLayer::onEditorShortcutButton)
		);
		auto menu = this->getChildByID("side-menu");
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