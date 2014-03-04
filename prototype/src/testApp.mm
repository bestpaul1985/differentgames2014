#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.setFPS(60);
    box2d.registerGrabbing();
    box2d.createBounds();
    box2d.setIterations(1, 1);
    
    for (int i=0; i<10; i++) {
        //I changed here to create smart pointer objects
		ofPtr<ofxBox2dCircle> c = ofPtr<ofxBox2dCircle>(new ofxBox2dCircle);
        c.get()->setPhysics(1, 0.4, 0.4);
        c.get()->setup(box2d.getWorld(), ofRandomWidth(), ofRandomHeight(), ofRandom(13, 25));
        circles.push_back(c);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    ofVec2f gravity;
    gravity.set(0,0);
    box2d.setGravity(gravity);
    box2d.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetHexColor(0xABDB44);
    for(int i = 0; i < circles.size() ; i++) {
        //I changed here to implement smart pointer objects
        circles[i].get()->draw();
    }
    
}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
    //I changed here to add new smart pointer objects
    ofPtr<ofxBox2dCircle> c = ofPtr<ofxBox2dCircle>(new ofxBox2dCircle);
    c.get()->setPhysics(1, 0.4, 0.4);
    c.get()->setup(box2d.getWorld(), touch.x, touch.y, ofRandom(13, 25));
    circles.push_back(c);
    
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){

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
