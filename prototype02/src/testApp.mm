#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
    ofSetVerticalSync(true);
	ofEnableSmoothing();
    ofSetCircleResolution(30);
	ofEnableAlphaBlending();
    ofTrueTypeFont::setGlobalDpi(72);

    //let's setup gui
    done.addListener(this,&testApp::menu_done);

    ofxGuiSetFont("font/faucet.ttf",18,true,true,72);
	ofxGuiSetTextPadding(2);
	ofxGuiSetDefaultWidth(280);
	ofxGuiSetDefaultHeight(30);
    BallSetting.setup("Ball");
    WorldSetting.setup("World");
    gui.setup("Try some things!");
    gui.add(p1.set(" 1P",false));
    gui.add(p2.set(" 2P",true));
    gui.add(p3.set(" 3P",false));
    gui.add(p4.set(" 4P",false));
    gui.add(BallSetting.parameters);
    gui.add(WorldSetting.parameters);
    gui.add(done.setup  (">>> Play! <<<"));
    
    // we set scenes here
    currentScene = 0;
    scenes[0] = new baseScene();
    scenes[1] = new gameplay();
    
    scenes[0]->setup();
    scenes[1]->setup();
    ((gameplay*)scenes[1])->setSceneNum(currentScene);


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

    ((gameplay*)scenes[1])->setBounce(myBounce);
    ((gameplay*)scenes[1])->setFriction(myFriction);
    ((gameplay*)scenes[1])->setRadiusMax(myRadiusMax);
    ((gameplay*)scenes[1])->setEat(BallSetting.eat);
    ((gameplay*)scenes[1])->setTrap(WorldSetting.trap);
    ((gameplay*)scenes[1])->setShrink(BallSetting.shrink);
    ((gameplay*)scenes[1])->setTime(WorldSetting.timer);
    ((gameplay*)scenes[1])->setMatter(WorldSetting.matter);
    ((gameplay*)scenes[1])->setBumpers(WorldSetting.bumpers);
    ((gameplay*)scenes[1])->setGoal(WorldSetting.goal);
    ((gameplay*)scenes[1])->setScoreboard(WorldSetting.scoreboard);

    
    currentScene = 1;
    
}


