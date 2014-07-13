#include "GameScene.h"

USING_NS_CC;


// タッチ開始処理
void GameScene::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
    CCSetIterator it;
    for (it = touches->begin(); it != touches->end(); ++it)
    {
        CCTouch* touch = (CCTouch*)(*it);
        
        if(!touch) {
            break;
        }
        
        // タイトルへ
        CCScene* TitleScene = TitleScene::scene();
        
        // ページめくりでシーンきりかえ【引数】アニメーション時間、シーンのポインタ、逆再生フラグ
        CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, TitleScene, 0));
    }
}

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
    
    // タップを有効にする
    setTouchEnabled(true);
    
    // 背景の表示
    createBackground();
    
    return true;
}