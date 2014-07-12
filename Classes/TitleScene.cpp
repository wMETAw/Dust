//
//  TitleScene.cpp
//  Dust
//
//  Created by RYO on 2014/07/11.
//
//

#include "TitleScene.h"

USING_NS_CC;


// タッチ開始処理
void TitleScene::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
    CCSetIterator it;
    for (it = touches->begin(); it != touches->end(); ++it)
    {
        CCTouch* touch = (CCTouch*)(*it);
        
        if(!touch) {
            break;
        }

        // ページめくりでシーンきりかえ【引数】アニメーション時間、シーンのポインタ
        CCDirector::sharedDirector()->replaceScene(CCTransitionFadeTR::create(0.5f, GameScene::scene()));
        
    }
}

// 背景の作成
void TitleScene::createBackground()
{
    // 画面サイズの取得
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    // 背景
    CCSprite* bg = CCSprite::create("title_bg.png");
    bg->setPosition(CCPoint(winSize.width/2, winSize.height/2));
    this->addChild(bg, kZOrderBackground, kTagBackground);
}

// シーンの作成
// @return シーン
CCScene* TitleScene::scene()
{
    // シーンを作成
    CCScene* scene = CCScene::create();
    
    // レイヤーを作成
    TitleScene* layer = TitleScene::create();
    
    // シーンにレイヤーをセット
    scene->addChild(layer);
    
    return scene;
}


// 初期化関数
bool TitleScene::init()
{
    if(!CCLayer::init()) {
        return false;
    }
    
    // タップを有効にする
    setTouchEnabled(true);
    
    // 背景の表示
    createBackground();
    
    return true;
}