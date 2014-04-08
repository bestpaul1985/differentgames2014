//
//  score.cpp
//  prototype02
//
//  Created by Peng Cheng on 4/8/14.
//
//

#include "score.h"

void score::setup(){
    scoreTop = 0;
    scoreBot = 0;
    rectW = 60;
    rectH = 70;
    font.loadFont("font/DS-DIGIB.TTF", 40);
}


void score::draw(){
    
    ofPushMatrix();
    ofTranslate(40,ofGetHeight()/2-40);
    ofRotateZ(90);
    ofSetColor(30);
    ofRectRounded(-rectW/2, -rectH/2, rectW, rectH, 10);
    ofRotateZ(-180);
    ofSetColor(255);
    string score = ofToString(scoreTop);
    font.drawString(score, -(int)font.stringWidth(score)/2, (int)font.stringHeight(score)/2);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(40, ofGetHeight()/2+40);
    ofRotateZ(90);
    ofSetColor(30);
    ofRectRounded(-rectW/2, -rectH/2, rectW, rectH, 10);
    ofRotateZ(-180);
    ofSetColor(255);
    score = ofToString(scoreBot);
    font.drawString(score, -(int)font.stringWidth(score)/2, (int)font.stringHeight(score)/2);
    ofPopMatrix();
    
}