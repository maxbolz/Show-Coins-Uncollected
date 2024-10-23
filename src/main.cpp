#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include <Geode/modify/CCSprite.hpp>

using namespace geode::prelude;

bool swappedTextures = false;

// THANK YOU COLON <3

class $modify(MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) return false;

		if (swappedTextures) return true;
		else swappedTextures = true;

		for (int i = 1; i <= 4; i++) {
			std::string suffix = ("_00" + std::to_string(i) + ".png");
			swapTexture("secretCoin_2_01" + suffix, "secretCoin_2_b_01" + suffix);
		}
		
		return true;
	} 

	void swapTexture(std::string oldKey, std::string newKey) {
		auto textureCache = CCSpriteFrameCache::get();
		auto goldTexture = textureCache->spriteFrameByName(oldKey.c_str());
		textureCache->removeSpriteFrameByName(newKey.c_str());
		textureCache->addSpriteFrame(goldTexture, newKey.c_str());
	}
};