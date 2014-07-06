//
//  AppMacros.h
//  Dust
//
//  Created by RYO on 2014/07/03.
//
//

#ifndef Dust_AppMacros_h
#define Dust_AppMacros_h

#include "cocos2d.h"

typedef struct tagResource
{
    cocos2d::CCSize size;
    char directory[100];
} Resource;

// マルチレゾリューションサイズ
static Resource smallResource  = { cocos2d::CCSizeMake(  384,  512), "img/S"};
static Resource mediumResource = { cocos2d::CCSizeMake(  786, 1024), "img/M"};
static Resource largeResource  = { cocos2d::CCSizeMake( 1536, 2048), "img/L"};

static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(768, 1024);

#define SCORE_FONT_SIZE (cocos2d::CCEGLView::sharedOpenGLView()->getDesignResolutionSize().width / mediumResource.size.width * 48)

#endif
