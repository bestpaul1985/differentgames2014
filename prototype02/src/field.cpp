#include "field.h"

field::field(){

}
//--------------------------------------------------------------
void field::setup(){

    ofBackground(255);
    int h = 200;
    topRect.set(0, 0, ofGetWidth(), h);
    botRect.set(0, ofGetHeight()-h, ofGetWidth(), ofGetHeight());
    midRect.set(0, h,ofGetWidth(), ofGetHeight()-h*2);
    midRectTop.set(0,200, ofGetWidth(), ofGetHeight()/2-200);
    midRectBot.set(0,ofGetHeight()/2, ofGetWidth(), ofGetHeight()/2-200);

}

//--------------------------------------------------------------
void field::update(){

    
}

//--------------------------------------------------------------
void field::draw(){
    
    //top
    ofSetColor(200,255);
    ofRect(topRect);
    ofSetColor(230,255);
    ofRect(midRectTop);
    
    //bot
    ofSetColor(200,255);
    ofRect(botRect);
    ofSetColor(230,255);
    ofRect(midRectBot);
    
    ofSetColor(180,255);
    ofLine(0, ofGetHeight()/2, ofGetWidth(), ofGetHeight()/2);
}

//--------------------------------------------------------------
void field::drawTop(){

    //top
    ofSetColor(200,255);
    ofRect(topRect);
    ofSetColor(230,255);
    ofRect(midRectTop);
    
    ofSetColor(180,255);
    ofLine(0, ofGetHeight()/2, ofGetWidth(), ofGetHeight()/2);

    
}

//--------------------------------------------------------------
void field::drawBot(){
    
   
    //bot
    ofSetColor(200,255);
    ofRect(botRect);
    ofSetColor(230,255);
    ofRect(midRectBot);
    
    ofSetColor(180,255);
    ofLine(0, ofGetHeight()/2, ofGetWidth(), ofGetHeight()/2);
    
    
}












