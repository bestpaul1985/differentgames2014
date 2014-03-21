#ifndef __prototype02__menu__
#define __prototype02__menu__

#include "ofMain.h"
#include "baseScene.h"
#include "ofxGui.h"



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
   
    
    bool bDone;
    
    ofxPanel gui;
    ofxButton done;


    ofParameter<float> speed;
    ofParameter<float> friction;
    ofParameter<float> bounce;
    ofParameter<bool> trap;
    ofParameter<bool> eat;
\
};
#endif