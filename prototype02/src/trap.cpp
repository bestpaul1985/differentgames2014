
#include "trap.h"

trap::trap(){

    radius = 40;
    bOpen = false;
    alpha = 200;
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
        ofSetColor(150,150,150,alpha);
        ofCircle(pos, radius);
    }
  
}