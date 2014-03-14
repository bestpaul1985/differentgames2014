#ifndef __prototype02__menu__
#define __prototype02__menu__

#include "ofMain.h"
#include "baseScene.h"
#include "Button.h"

#define Menu_Num 3
class menu :public baseScene{
    
    void setup();
    void update();
    void draw();
    
    void touchDown(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);

public:
    bool isDone();
    void reset();
    bool bTrap();
    bool bEat();
    button myMenu[Menu_Num];
    
};
#endif