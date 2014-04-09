//
//  timer.cpp
//  prototype02
//
//  Created by Peng Cheng on 4/8/14.
//
//

#include "timer.h"

void timer::setup(){

    font.loadFont("font/DS-DIGIB.TTF", 60);
    startTime = ofGetElapsedTimef();
    totalTime = 10.0f;
    timer = 60;
}

void timer::update(){

    timer = totalTime - (ofGetElapsedTimef() - startTime);
    
    if (timer<0) {
        timer = 0;
    }
    
}

void timer::draw(){
    
    string timeString = ofToString(timer,0);
    int offsetW = 30;
    int offsetH = 25;
    ofPushMatrix();
    ofTranslate(740, ofGetHeight()/2);
    ofRotateZ(90);
    ofSetColor(230, 0, 200);
    font.drawString(timeString, -offsetW, offsetH);
    ofPopMatrix();
    
}