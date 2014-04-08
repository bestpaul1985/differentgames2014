//
//  gola.cpp
//  prototype02
//
//  Created by Peng Cheng on 4/8/14.
//
//

#include "gola.h"
//-------------------------------------------------------------
void gola::setup(int where){

    int w = 150;
    int h = 16;
    if (where == 0) {
        rect.setFromCenter(ofGetWidth()/2, h/2, w, h);

    }else{
        rect.setFromCenter(ofGetWidth()/2, ofGetHeight()-h/2, w, h);
    }
   

}

//-------------------------------------------------------------
bool gola::conllision(ofPoint pos, float radius){
    
    bool bCollide;
    
    ofPoint A = rect.getTopLeft();
    ofPoint B = rect.getTopRight();
    ofPoint C = rect.getBottomLeft();
    ofPoint D = rect.getBottomRight();
    
    ofPoint ballTop(pos.x,pos.y-radius);
    ofPoint ballLeft(pos.x-radius,pos.y);
    ofPoint ballRight(pos.x+radius,pos.y);
    ofPoint ballBot(pos.x,pos.y+radius);
    ofPoint intersactionPos;
    if (pos.distance(A)<=radius) {
        bCollide = true;
    }
    else if (pos.distance(B)<=radius){
        bCollide = true;
    }
    else if(pos.distance(C)<=radius){
        bCollide = true;
    }
    else if(pos.distance(D)<=radius){
        bCollide = true;
        
    }
    else if (ofLineSegmentIntersection(A, B, pos, ballBot,intersactionPos)){
        bCollide = true;
    }
    else if (ofLineSegmentIntersection(B, C, pos, ballLeft,intersactionPos)){
        bCollide = true;
    }
    else if (ofLineSegmentIntersection(C, D, pos, ballTop,intersactionPos)){
        bCollide = true;
    }
    else if (ofLineSegmentIntersection(D, A, pos, ballRight,intersactionPos)){
        bCollide = true;
    }
    else{
        bCollide = false;
    }
    
    
    return bCollide;
    

}

//-------------------------------------------------------------
void gola::draw(){
    
    ofSetColor(255, 0, 220);
    ofRect(rect);
}
