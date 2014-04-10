#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"
#include "baseScene.h"
#include "gamePlay.h"
#include "menuRenderer.h"
#include "ofxGui.h"

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
        void imageLoader();
        void menu_done();
    
        baseScene  * scenes[2];
    
        int currentScene;
    
    
        //----let's create a gui-----
        ofxPanel gui;
        ofParameter<bool> p1;
        ofParameter<bool> p2;
        ofParameter<bool> p3;
        ofParameter<bool> p4;
        ofxButton done;
    
        ballSetting         BallSetting;
        worldSetting        WorldSetting;

};


