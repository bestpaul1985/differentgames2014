#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"

#include "ofxBox2d.h"
#include "field.h"
#include "ball.h"
#include "matter.h"
#include "trap.h"

class testApp : public ofxiOSApp{
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
	
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);
    
        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);
    
        void imageLoader();
    
        ofxBox2d                        box2d;    
    
        field                           myField;
        vector<ofPtr<ball> >            myBalls;
        matter                          matter_top, matter_bot;
        ofImage                         myImage[3];
    
        trap                            myTrap;
};


