#include "PlaySE.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

PlaySE::PlaySE(std::string sound)
{
    m_sound = sound;
}


// 作成関数
PlaySE* PlaySE::create(std::string sound)
{
    PlaySE* pRet = new PlaySE(sound);
    
    if(pRet) {
        
        // インスタンスが不要になったら自動解放してくれる
        pRet->autorelease();
    }
    
    return pRet;
}

// soundの再生
void PlaySE::update(float time)
{
    // 引数が使われなかったときにWarningがでないようにするマクロ
    CC_UNUSED_PARAM(time);
    
    // m_sound.c_str() はstd::string の文字列を吐き出す関数
    SimpleAudioEngine::sharedEngine()->playEffect(m_sound.c_str());
}

// 逆再生
CCFiniteTimeAction* PlaySE::reverse()
{
    // とりあえず通常再生
    return (CCFiniteTimeAction*)(PlaySE::create(m_sound));
}

// インスタンスのコピー関数
CCObject* PlaySE::copyWithZone(CCZone* pZone)
{
    CCZone* pNewZone = NULL;
    PlaySE* pRet = NULL;
    if(pZone && pZone->m_pCopyObject) {
        pRet = (PlaySE*)(pZone->m_pCopyObject);
    } else {
        pRet = new PlaySE(m_sound);
        pZone = pNewZone = new CCZone(pRet);
    }
    
    CCActionInstant::copyWithZone(pZone);
    CC_SAFE_DELETE(pNewZone);
    
    return pRet;
}






