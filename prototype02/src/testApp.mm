#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
    ofSetVerticalSync(true);
	ofSetCircleResolution(100);
	ofEnableSmoothing();
	ofEnableAlphaBlending();
    ofTrueTypeFont::setGlobalDpi(72);

    //let's setup gui
    done.addListener(this,&testApp::menu_done);

    ofxGuiSetFont("font/Questrial-Regular.ttf",16,true,true);
	ofxGuiSetTextPadding(8);
	ofxGuiSetDefaultWidth(300);
	ofxGuiSetDefaultHeight(42);
    
    BallSetting.setup("Ball");
    FieldSetting.setup("Field");
    WinningSetting.setup("Win");
    
    gui.setup("What is in your mind ?");
    gui.add(BallSetting.parameters);
    gui.add(FieldSetting.parameters);
    gui.add(WinningSetting.parameters);
    gui.add(done.setup  ("done"));
    
    // we set scenes here
    currentScene = 0;
    
    scenes[0] = new baseScene();
    scenes[1] = new gameplay();
    
    scenes[0]->setup();
    scenes[1]->setup();

}

//--------------------------------------------------------------
void testApp::update(){
    
    scenes[currentScene]->update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    scenes[currentScene]->draw();
    
    if (currentScene==0) {
        gui.draw();
    }
    
    
}

//--------------------------------------------------------------
void testApp::exit(){

    
}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
  
    scenes[currentScene]->touchDown(touch);
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
   
    scenes[currentScene]->touchMoved(touch);

}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){
 
    scenes[currentScene]->touchUp(touch);
   
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
    
}

//--------------------------------------------------------------
void testApp::checkBallRadius(){
   
    
}
//--------------------------------------------------------------
void testApp::imageLoader(){

    scenes[currentScene]->imageLoader();

}

//--------------------------------------------------------------
void testApp::menu_done(){
    
    float myBounce = ofMap(BallSetting.bounce, 1, 4, 0.4f, 1.0f);
    float myFriction = ofMap(BallSetting.friction, 1, 4, 0.001f, 0.01f);
    int myRadiusMax = ofMap(BallSetting.radiusMax, 1, 4, 40, 120);
    int matterAmount= ofMap(FieldSetting.matter, 1, 4, 100, 400);

    ((gameplay*)scenes[1])->setBounce(myBounce);
    ((gameplay*)scenes[1])->setFriction(myFriction);
    ((gameplay*)scenes[1])->setRadiusMax(myRadiusMax);
    ((gameplay*)scenes[1])->setMatter(matterAmount);
    ((gameplay*)scenes[1])->setEat(FieldSetting.eat);
    ((gameplay*)scenes[1])->setTrap(FieldSetting.trap);
    ((gameplay*)scenes[1])->setShrink(FieldSetting.shrink);
    ((gameplay*)scenes[1])->setStartTime(ofGetElapsedTimef());
    ((gameplay*)scenes[1])->setTimer(WinningSetting.timer);
    ((gameplay*)scenes[1])->setSceneNum(currentScene);
    
    currentScene = 1;
    
}


