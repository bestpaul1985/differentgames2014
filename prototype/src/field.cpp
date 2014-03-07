#include "field.h"

field::field(){

}

void field::setup(){

    ofBackground(255);
    int h = 200;
    topRect.set(0, 0, ofGetWidth(), h);
    botRect.set(0, ofGetHeight()-h, ofGetWidth(), ofGetHeight());
    midRect.set(0, h,ofGetWidth(), ofGetHeight()-h);
}

void field::update(){

    
}

void field::draw(){
    
    ofSetColor(200,255);
    ofRect(topRect);
    ofSetColor(200,255);
    ofRect(botRect);
}
