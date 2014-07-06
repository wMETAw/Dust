//
//  GameScene.cpp
//  Dust
//
//  Created by RYO on 2014/07/06.
//
//

#include "GameScene.h"

USING_NS_CC;


// 背景の作成
void GameScene::createBackground()
{
    // 画面サイズの取得
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    // 背景
    CCSprite* bg = CCSprite::create("bg.png");
    bg->setPosition(CCPoint(winSize.width/2, winSize.height/2));
    this->addChild(bg, kZOrderBackground, kTagBackground);
}

// シーンの作成
// @return シーン
CCScene* GameScene::scene()
{
    // シーンを作成
    CCScene* scene = CCScene::create();
    
    // レイヤーを作成
    GameScene* layer = GameScene::create();
    
    // シーンにレイヤーをセット
    scene->addChild(layer);
    
    return scene;
}


// 初期化関数
bool GameScene::init()
{
    if(!CCLayer::init()) {
        return false;
    }
    
    // 背景の表示
    createBackground();
    
    return true;
}