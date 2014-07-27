#ifndef __Dust__GameScene__
#define __Dust__GameScene__

#include "cocos2d.h"
#include "TitleScene.h"
#include "PlaySE.h"
#include "Box2D/Box2D.h"


USING_NS_CC;

class GameScene : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    // cocosで使われる.create()関数が定義されている
    CREATE_FUNC(GameScene);
    
    // 物理ワールド更新
    void update(float dt);
    
    
protected:
    
    // 画像タグ
    enum kTag {
        kTagBackground = 1, // 背景
    };
    
    // Zオーダー（表示順序）
    enum kZOder {
        kZOrderBackground = 1, // 背景
        kZOrderBall,
    };
    
    // 物理ワールドの作成
    b2World* world;
    void initPhysics();
    b2Body* bgBody;
    
    // 背景の作成
    void createBackground();
    
    // ボールの作成
    void createBall();
    
    // タッチ開始の処理
    virtual void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
    // タッチ終了の処理
    virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
    CCPoint touchStartPoint;
    b2Body* touchBody;
    
};

#endif /* defined(__Dust__GameScene__) */
