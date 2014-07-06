//
//  GameScene.h
//  Dust
//
//  Created by RYO on 2014/07/06.
//
//

#ifndef __Dust__GameScene__
#define __Dust__GameScene__

#include "cocos2d.h"

class GameScene : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    // cocosで使われる.create()関数が定義されている
    CREATE_FUNC(GameScene);
    
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
    
};

#endif /* defined(__Dust__GameScene__) */
