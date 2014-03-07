
#include "ball.h"


ball::ball(){
    bFinish = false;
    bRemove = false;
    group = 0;
    color.set(0, 180, 40, 150);
    
}



void ball::draw(){

    if(!isBody()) return;
	
   
    
	ofPushMatrix();
	ofTranslate(getPosition().x, getPosition().y, 0);
	ofRotate(getRotation(), 0, 0, 1);
    ofPushStyle();
    ofSetColor(color);
	ofCircle(0, 0, getRadius());
    ofPopStyle();
	ofPopMatrix();

}

void ball::setTopGroup(){
    color.set(0, 180, 40, 150);
    group = 0;
}

void ball::setBotGroup(){
    color.set(180, 0, 40, 150);
    group = 1;
}