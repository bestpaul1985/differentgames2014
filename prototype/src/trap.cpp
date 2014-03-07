
#include "trap.h"

trap::trap(){

    raduis = 40;
    bOpen = false;
    alpha = 0;
    bKill = false;
}

void trap::setup(int x, int y){

    pos.set(x, y);
    timer = ofGetElapsedTimeMillis();

}



void trap::update(){
    
    if (ofGetElapsedTimeMillis()-timer>5000) {
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
    
    if (bOpen) {
        alpha += 1;
        if (alpha > 200) {
            alpha = 200;
            bKill = true;
        }
    }else{
        alpha -= 1;
        if (alpha < 0) {
            alpha = 0;
            bKill = false;
        }
        
    }


}


void trap::draw(){
    
    ofSetColor(150,150,150,alpha);
    ofCircle(pos, raduis);
}