#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"
#include "ball.h"
#include "field.h"

enum E_OPTION{ NO_INITI,INITI_TOP_BALL,INITI_BOT_BALL,DRAG_TOP_BALL,DRAG_BOT_BALL};

class testApp : public ofxiOSApp{
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
        void checkBallRadius();
     
    
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);
    
        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
        void checkCollision();

    
        field           myField;
        vector <Ball>   myBalls;
        float           radius;
        E_OPTION        touchOption;
    
    
        

};


