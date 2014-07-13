#ifndef __Dust__TitleScene__
#define __Dust__TitleScene__

#include "cocos2d.h"
#include "GameScene.h"
#include "PlaySE.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

#define BGM_MAIN "sound/main_bgm.mp3"

class TitleScene : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    // cocosで使われる.create()関数が定義されている
    CREATE_FUNC(TitleScene);
    
protected:
    
    // 画像タグ
    enum kTag {
        kTagBackground = 1, // 背景
        kTagStartBtn,       // スタートボタン
    };
    
    // Zオーダー（表示順序）
    enum kZOder {
        kZOrderBackground = 1, // 背景
        kZOrderStartBtn,       // スタートボタン
    };
    
    // 背景の作成
    void createBackground();
    
    // スタートボタンの作成
    void createStartBtn();
    void tapStartBtn();
    
    // タッチ開始の処理
    virtual void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
};

#endif /* defined(__Dust__TitleScene__) */
