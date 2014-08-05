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

// スタートボタン作成
void TitleScene::createStartBtn()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCMenuItemImage* start = CCMenuItemImage::create("ball.png", "ball.png", this, menu_selector(TitleScene::tapStartBtn));
    start->setPosition(ccp(winSize.width * 0.5, winSize.height * 0.5));
    
    CCMenu* menu = CCMenu::create(start, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu, kZOrderStartBtn);
}

// スタートボタンタップ時の処理
void TitleScene::tapStartBtn()
{
    // ページめくりでシーンきりかえ【引数】アニメーション時間、シーンのポインタ
    CCDirector::sharedDirector()->replaceScene(CCTransitionFadeTR::create(0.5f, GameScene::scene()));
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
    
    // スタートボタンの作成
    createStartBtn();
    
    // BGMのロードし、再生
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(BGM_MAIN);
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(BGM_MAIN, true);
    
    return true;
}