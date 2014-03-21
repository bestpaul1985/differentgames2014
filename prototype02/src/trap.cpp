
#include "trap.h"

trap::trap(){

    radius = 50;
    bOpen = false;
    bKill = true;
}

void trap::setup(){

    timer = ofGetElapsedTimeMillis();

}



void trap::update(){
    
    if (ofGetElapsedTimeMillis()-timer>3000) {
        bOpen = !bOpen;
        timer = ofGetElapsedTimeMillis();
        int random = (int)ofRandom(0,5);
        if (random == 0) {
            pos.set(ofGetWidth()/2-150,ofGetHeight()/2-150);
        }else if(random == 1){
            pos.set(ofGetWidth()/2+150,ofGetHeight()/2-150);
        }else if(random == 2){
            pos.set(ofGetWidth()/2-150,ofGetHeight()/2+150);
        }else if(random == 3){
            pos.set(ofGetWidth()/2+150,ofGetHeight()/2+150);
        }else {
            pos.set(ofGetWidth()/2,ofGetHeight()/2);
        }
    }

    
}


void trap::draw(){
    
    if (bOpen) {
        
        float xPct = 0.5f;
        float yPct = 0.7f;
        int nTips = 5 + xPct * 60;
        int nStarPts = nTips * 2;
        float angleChangePerPt = TWO_PI / (float)nStarPts;
        float innerRadius = 0 + yPct*radius;
        float outerRadius = radius;
        float origx = pos.x;
        float origy = pos.y;
        float angle = 0;
        
        ofSetHexColor(0xa16bca);
        ofBeginShape();
        for (int i = 0; i < nStarPts; i++){
            if (i % 2 == 0) {
                // inside point:
                float x = origx + innerRadius * cos(angle);
                float y = origy + innerRadius * sin(angle);
                ofVertex(x,y);
            } else {
                // outside point
                float x = origx + outerRadius * cos(angle);
                float y = origy + outerRadius * sin(angle);
                ofVertex(x,y);
            }
            angle += angleChangePerPt;
        }
        ofEndShape();
    }
  
}