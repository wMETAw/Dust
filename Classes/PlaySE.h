#ifndef __Dust__PlaySE__
#define __Dust__PlaySE__

#include "cocos2d.h"

class PlaySE : public cocos2d::CCActionInstant
{
public:
    PlaySE(std::string sound);
    virtual ~PlaySE(){}
    
    virtual void update(float time);
    virtual CCFiniteTimeAction* reverse(void);
    virtual CCObject* copyWithZone(cocos2d::CCZone* pZone);
    
public:
    // 効果音の作成関数
    static PlaySE* create(std::string sound);
    
protected:
    std::string m_sound;
    
};

#endif /* defined(__Dust__PlaySE__) */
