#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableAlphaBlending();
    ofSetCircleResolution(150);
    imageLoader();
    
    box2d.init();
    box2d.setGravity(0, 0);
    box2d.setFPS(60);
    box2d.registerGrabbing();
    box2d.createBounds();
    box2d.setIterations(1, 1);
    
    
    myField.setup();
    matter_top.initial(0, 0, 180, myImage[0], myImage[1], myImage[2]);
    matter_bot.initial(600, 860, 0, myImage[0], myImage[1], myImage[2]);

    myTrap.setup(ofGetWidth()/2+150,ofGetHeight()/2+150);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i=0; i<myBalls.size(); i++) {
    
        if (myBalls[i].get()->bRemove) {
//          box2d.world->DestroyBody(myBalls[i].get()->body);
            myBalls[i].get()->destroy();
        }
    }
    
    box2d.update();

    myField.update();
    myTrap.update();
    
    matter_top.update();
    matter_bot.update();
    
    
    for (int i=0; i<myBalls.size(); i++) {
        
        myBalls[i].get()->setDamping(0.99);
        
        if (myBalls[i].get()->group == 0) {
            if (!myBalls[i].get()->bFinish && myBalls[i].get()->getRadius() <70 && matter_top.amount>0) {
                float radius = myBalls[i].get()->getRadius();
                radius += 1;
                myBalls[i].get()->setRadius(radius);
                matter_top.amount --;
                
            }
        }
        else if(myBalls[i].get()->group == 1){
            if (!myBalls[i].get()->bFinish && myBalls[i].get()->getRadius() <70 && matter_bot.amount>0) {
                float radius = myBalls[i].get()->getRadius();
                radius += 1;
                myBalls[i].get()->setRadius(radius);
                matter_bot.amount --;
                
            }
        }
        
     
        if (myBalls[i].get()->getPosition().distance(myTrap.pos)< (myBalls[i].get()->getRadius() + myTrap.raduis) ) {
            myBalls[i].get()->bRemove = true;
        }
        
    }
    
    
    
    
     
}

//--------------------------------------------------------------
void testApp::draw(){
    
    myField.draw();
    myTrap.draw();
    matter_top.draw();
    matter_bot.draw();
    
    
    for (int i=0; i<myBalls.size(); i++) {
        myBalls[i].get()->draw();
    }

}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
    

    int situation = 0;
    ofVec2f touchPos(touch.x,touch.y);
    if (myField.topRect.inside(touchPos) && matter_top.amount>0) situation = 1;
    if (myField.botRect.inside(touchPos) && matter_bot.amount>0) situation = 2;
    
    if (situation > 0) {
        bool bInitialBall = true;
        float radius = 15;
        for (int i=0; i<myBalls.size(); i++) {
            if (touchPos.distance(myBalls[i].get()->getPosition())<myBalls[i].get()->getRadius()) {
                bInitialBall = false;
            }
        }
        
        if (bInitialBall) {
            ofPtr<ball> c = ofPtr<ball>(new ball);
            c.get()->setPhysics(2, 0.4, 0.4);
            c.get()->setup(box2d.getWorld(), touch.x, touch.y, radius);
            c.get()->touchID = touch.id;
            if(situation == 1)c.get()->setTopGroup();
            if(situation == 2)c.get()->setBotGroup();
            myBalls.push_back(c);
        }

    }
    
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
    
    
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){
    
    ofVec2f touchPos(touch.x,touch.y);
    
    for (int i=0; i<myBalls.size(); i++) {
        if (touch.id == myBalls[i].get()->touchID) {
            myBalls[i].get()->bFinish = true;
        }
    }

    
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::lostFocus(){

}

//--------------------------------------------------------------
void testApp::gotFocus(){

}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){

}

//--------------------------------------------------------------
void testApp::imageLoader(){

    
    myImage[0].loadImage("image/image0.jpg");
    myImage[1].loadImage("image/image1.jpg");
    myImage[2].loadImage("image/image2.jpg");

    
    
}
