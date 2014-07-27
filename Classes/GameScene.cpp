#include "GameScene.h"
#include "GB2ShapeCache-x.h"

#define PTM_RATIO 400

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
    
    // シェイプデータの読み込み
    gbox2d::GB2ShapeCache::sharedGB2ShapeCache()->addShapesWithFile("test3.plist");
    
    // 物理ワールドの設定
    initPhysics();
    
    // タップを有効にする
    setTouchEnabled(true);
    
    // 背景の表示
    createBackground();
    
    // ボール作成
    createBall();
    
    // 毎フレームの処理の開始
    scheduleUpdate();
    
    return true;
}

// 物理ワールド初期化
void GameScene::initPhysics()
{
    // 物理ワールドを生成し、重力を設定
    b2Vec2 gravity;
    gravity.Set(0.0f, -2.0f);
    world = new b2World(gravity);
}


// 物理ワールド更新
void GameScene::update(float dt)
{
    int velocityIterations = 8;
    int positionIterations = 1;
    
    world->Step(dt, velocityIterations, positionIterations);
    
    // 物理ワールドすべての剛体をループ
    for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
    {
        if(b->GetUserData() != NULL) {
            CCSprite* myActor = (CCSprite*)b->GetUserData();
            
            if(b->GetPosition().y < 0) {
                world->DestroyBody(b);
                this->removeChild(myActor);
                continue;
            }
            
            myActor->setPosition(CCPointMake(b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO));
            myActor->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));
        }
    }
}

// タッチ開始処理
void GameScene::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    
    CCSetIterator it;
    for (it = touches->begin(); it != touches->end(); ++it)
    {
        CCTouch* touch = (CCTouch*)(*it);
        
        if(!touch) {
            break;
        }
        
        // 画面上でのタッチ位置を取得
        CCPoint tPoint = pDirector->convertToGL(touch->getLocationInView());
        
        // 物理ワールドすべての剛体をループ
        for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
        {
            if(b->GetUserData() != NULL) {
                
                CCSprite* myActor = (CCSprite*)b->GetUserData();
                CCRect rect = myActor->boundingBox();
                
                // あたり判定
                if (rect.containsPoint(tPoint)) {
                    
                    touchBody = b;
                    touchStartPoint = tPoint;
                    break;
                }
                
            }
        }
        
        // タイトルへ
        //CCScene* TitleScene = TitleScene::scene();
        
        // ページめくりでシーンきりかえ【引数】アニメーション時間、シーンのポインタ、逆再生フラグ
        //CCDirector::sharedDirector()->replaceScene(CCTransitionPageTurn::create(0.5f, TitleScene, 0));
        
        //createBall();
    }
}

// タッチ終了
void GameScene::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    
    CCSetIterator it;
    for (it = touches->begin(); it != touches->end(); ++it)
    {
        CCTouch* touch = (CCTouch*)(*it);
        
        if(!touch){
            break;
        }
        
        // 画面上でのタッチ位置を取得
        CCPoint touchEndPoint = pDirector->convertToGL(touch->getLocationInView());
        
        // タッチした物体があれば力を加える
        if (touchBody != NULL) {

            float x = (touchEndPoint.x - touchStartPoint.x)*0.1;
            float y = (touchEndPoint.y - touchStartPoint.y)*0.1;
            touchBody->ApplyForce(b2Vec2(x, y), touchBody->GetWorldCenter());
            touchBody = NULL;
        }
        
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
    
    // 背景の物理構造
    b2BodyDef bgBodyDef;
    bgBodyDef.type = b2_staticBody;
    bgBodyDef.position.Set(bg->getPositionX() / PTM_RATIO, bg->getPositionY() / PTM_RATIO);
    bgBodyDef.userData = bg;
    bgBody = world->CreateBody(&bgBodyDef);
    
    gbox2d::GB2ShapeCache* sc = gbox2d::GB2ShapeCache::sharedGB2ShapeCache();
    sc->addFixturesToBody(bgBody, "bg");
    bg->setAnchorPoint(sc->anchorPointForShape("bg"));
}

// ボールの生成
void GameScene::createBall()
{
    // ウィンドウサイズの取得
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    // ボールの作成
    CCPoint ballPoint = ccp(winSize.width * 0.25, winSize.height * 0.55);
    CCSprite* ball = CCSprite::create("ball.png");
    ball->setPosition(ballPoint);
    this->addChild(ball, kZOrderBall);
    
    // ボールの物理構造
    b2BodyDef ballBodyDef;
    ballBodyDef.type = b2_dynamicBody;
    ballBodyDef.position.Set(ballPoint.x / PTM_RATIO, ballPoint.y / PTM_RATIO);
    ballBodyDef.userData = ball;
    b2Body* body = world->CreateBody(&ballBodyDef);
    
    gbox2d::GB2ShapeCache* sc = gbox2d::GB2ShapeCache::sharedGB2ShapeCache();
    sc->addFixturesToBody(body, "ball");
    ball->setAnchorPoint(sc->anchorPointForShape("ball"));
}














