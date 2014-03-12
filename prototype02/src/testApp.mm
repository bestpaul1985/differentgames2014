#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
    ofSetVerticalSync(true);
	ofSetCircleResolution(90);
	ofEnableSmoothing();
	ofEnableAlphaBlending();
	ofBackground(51, 51, 51);
    
    radius = 20;
}

//--------------------------------------------------------------
void testApp::update(){
    
    checkBallRadius();
    
	for(int i=0; i<myBalls.size(); i++) {
        myBalls[i].follow();
        myBalls[i].addDampingForce();
		myBalls[i].update();
	}
    

	checkCollision();
    
    
 
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i=0; i<myBalls.size(); i++) {
		myBalls[i].draw();
	}
}

//--------------------------------------------------------------
void testApp::exit(){

    
}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
   
    ofPoint touchPos(touch.x,touch.y);
    bool bInitial = true;
    for (int i=0; i<myBalls.size(); i++) {
        float dis = myBalls[i].location.distance(touchPos);
        if (dis <myBalls[i].radius+radius) {
            bInitial = false;
            if (dis<myBalls[i].radius) {
                myBalls[i].bFolloer = true;
                myBalls[i].followPos.set(touchPos);
            }
        }
    }
    
    if (bInitial) {
        Ball temp;
        temp.location.set(touchPos);
        temp.bounce = 1;
        temp.color.set(255,30,0);
        temp.mass = ofRandom(3.0) + 1.0;
        temp.bounce = 0.9;
        temp.radius = radius;
        temp.touchID = touch.id;
        temp.followPos.set(touchPos);
        myBalls.push_back(temp);
    }
    
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
    ofPoint touchPos(touch.x,touch.y);
    for (int i=0; i<myBalls.size(); i++) {
        if (myBalls[i].touchID == touch.id && myBalls[i].bJoint) {
            myBalls[i].followPos.set(touchPos);
        }
    }
    
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){
 
    for (int i=0; i<myBalls.size(); i++) {
        if (myBalls[i].touchID == touch.id ) {
            myBalls[i].bFinalized = true;
            myBalls[i].bFolloer = false;
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
void testApp::checkCollision(){

    for(int i=0; i<myBalls.size(); i++) {
        for(int j=i+1; j<myBalls.size(); j++) {
            if(ofDist(myBalls[i].location.x, myBalls[i].location.y, myBalls[j].location.x, myBalls[j].location.y) < myBalls[i].radius+myBalls[j].radius) {
				myBalls[i].collision( myBalls[j] );
            }
        }
    }
}

//--------------------------------------------------------------
void testApp::checkBallRadius(){
    
    for(int i=0; i<myBalls.size(); i++) {
        if (!myBalls[i].bFinalized) {
            for(int j=0; j<myBalls.size(); j++) {
                if (i!=j) {
                    if(ofDist(myBalls[i].location.x, myBalls[i].location.y, myBalls[j].location.x, myBalls[j].location.y) < myBalls[i].radius+myBalls[j].radius) {
                        myBalls[i].bFinalized = true;
                        myBalls[j].bFinalized = true;
                    }
                }
            }
        }
    }
    
    
    for(int i=0; i<myBalls.size(); i++) {
        myBalls[i].changeRadius();
    }
    
}
//--------------------------------------------------------------






