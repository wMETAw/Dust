//
//  TitleScene.h
//  Dust
//
//  Created by RYO on 2014/07/11.
//
//

#ifndef __Dust__TitleScene__
#define __Dust__TitleScene__

#include "cocos2d.h"
#include "GameScene.h"

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
    };
    
    // Zオーダー（表示順序）
    enum kZOder {
        kZOrderBackground = 1, // 背景
    };
    
    // 背景の作成
    void createBackground();
    
    // タッチ開始の処理
    virtual void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
};

#endif /* defined(__Dust__TitleScene__) */
