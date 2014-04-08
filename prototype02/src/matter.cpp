#include "matter.h"

matter::matter(){
    
    color.set(134, 60, 227);
    totalAmount = 400;
}

void matter::initial(int Num){

    num = Num;
    image[0].loadImage("image/1.png");
    pos.set(0,0);
    if (num == 1) {
        pos.set(ofGetWidth()-180,ofGetHeight()-200);
    }
}

void matter::update(){

    h = ofMap(amount, 0, totalAmount, 120, 0);
    if (num==1) {
        h*=-1;
    }
}

void matter::draw(){

    
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(255);
    ofRect(pos.x+image[0].getWidth()/2, pos.y+image[0].getHeight()/2, 120,120);
    
    ofSetColor(255,0,0);
    ofRect(pos.x+image[0].getWidth()/2, pos.y+image[0].getHeight()/2-h, 120, 120);
    ofSetRectMode(OF_RECTMODE_CORNER);

    ofSetColor(255);
    image[0].draw(pos,image[0].getWidth(),image[0].getHeight());
    
}

void matter::setAmount(int Amount){
    amount = Amount;
}








