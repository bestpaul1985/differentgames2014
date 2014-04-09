//
//  circleButton.h
//  prototype02
//
//  Created by Peng Cheng on 4/9/14.
//
//

#ifndef __prototype02__circleButton__
#define __prototype02__circleButton__

#include "ofMain.h"
class circleButton{
public:
    
    void setup(int x, int y);
    void update();
    void draw();
    void touchDown(int x, int y);
    void touchUp(int x, int y);
    
    ofPoint pos;
    float radius, lastTime;
    ofImage circleButton;
    bool bTouched, bButton;
    int timer;
};

#endif /* defined(__prototype02__circleButton__) */
