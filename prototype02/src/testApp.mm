#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
    ofSetVerticalSync(true);
	ofSetCircleResolution(90);
	ofEnableSmoothing();
	ofEnableAlphaBlending();
    ofTrueTypeFont::setGlobalDpi(72);

    currentScene = 0;
    
    scenes[0] = new menu();
    scenes[1] = new gameplay();
    
    scenes[0]->setup();
    scenes[1]->setup();
}

//--------------------------------------------------------------
void testApp::update(){
    
    scenes[currentScene]->update();
    
    if(((menu*)scenes[0])->isDone()){
        
        currentScene = 1;
        
        if (((menu*)scenes[0])->bTrap()) {
            ((gameplay*)scenes[1])->setTrap();
        }
        if (((menu*)scenes[0])->bEat()) {
            ((gameplay*)scenes[1])->setEat();
        }
        
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
   scenes[currentScene]->draw();
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





