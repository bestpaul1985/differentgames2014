//
//  circleButton.cpp
//  prototype02
//
//  Created by Peng Cheng on 4/9/14.
//
//

#include "circleButton.h"

void circleButton::setup(int x, int y){

    circleButton.loadImage("image/circleButton.png");
    pos.set(x,y);
    radius = circleButton.getWidth()/2;
    bTouched = false;
    bButton = false;
    timer = 0;
}
//---------------------------------------------------------
void circleButton::update(){

    
    
}
//---------------------------------------------------------
void circleButton::draw(){
    
    if (bTouched) {
        timer++;
        radius = circleButton.getWidth()/2 + abs(sin(ofGetElapsedTimef()-lastTime)*40);
        if(timer>80){
            timer = 0;
            bButton = true;
            bTouched = false;
        }        
    }else{
        timer = 0;
        radius = circleButton.getWidth()/2;
    }
    
    ofPushMatrix();
    ofSetColor(255);
    ofTranslate(pos.x, pos.y);
    ofRotateZ(RAD_TO_DEG*ofGetElapsedTimef());
    circleButton.draw(-radius/2,-radius/2,radius,radius);
    ofPopMatrix();
}
//---------------------------------------------------------
void circleButton::touchDown(int x, int y){

    ofPoint touch(x,y);
    if (touch.distance(pos)<radius) {
        bTouched = !bTouched;
        lastTime = ofGetElapsedTimef();
    }
}
//---------------------------------------------------------
void circleButton::touchUp(int x, int y){
    bTouched = false;
}
