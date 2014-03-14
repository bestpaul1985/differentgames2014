#include "matter.h"

matter::matter(){
    
    amount = 200;
    totalAmount = 200;
    color.set(134, 60, 227);
    

    

}

void matter::initial(int Num){

    num = Num;
    image[0].loadImage("image/front.png");
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
    
    ofSetColor(30);
    ofRect(pos.x+image[0].getWidth()/2, pos.y+image[0].getHeight()/2-h, 120, 120);
    ofSetRectMode(OF_RECTMODE_CORNER);

    ofSetColor(255);
    image[0].draw(pos);
    
}

void matter::setAmount(int Amount){
    amount = Amount;
}








