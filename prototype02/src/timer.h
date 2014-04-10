//
//  timer.h
//  prototype02
//
//  Created by Peng Cheng on 4/8/14.
//
//

#ifndef __prototype02__timer__
#define __prototype02__timer__

#include "ofMain.h"
class timer{
public:
    void setup();
    void update();
    void draw();
    
    ofTrueTypeFont font;
    float timer, startTime, totalTime;
    bool bStart, bUnlimited;
};

#endif /* defined(__prototype02__timer__) */
