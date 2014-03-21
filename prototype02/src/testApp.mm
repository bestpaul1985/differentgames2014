#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
    ofSetVerticalSync(true);
	ofSetCircleResolution(90);
	ofEnableSmoothing();
	ofEnableAlphaBlending();
    ofTrueTypeFont::setGlobalDpi(72);

    //let's setup gui
    done.addListener(this,&testApp::menu_done);

    ofxGuiSetFont("font/Questrial-Regular.ttf",18,true,true);
	ofxGuiSetTextPadding(4);
	ofxGuiSetDefaultWidth(400);
	ofxGuiSetDefaultHeight(38);
    
    gui.setup("What is in your mind ?");
    gui.add(trap.set("trap", false));
    gui.add(eat.set("eat", false));
    gui.add(radiusMax.set( "Radius", 1, 1, 4));
    gui.add(bounce.set( "Bounce", 1, 1, 4));
    gui.add(friction.set( "Friction", 1, 1, 4));
    gui.add(matter.set( "Matter", 3, 1, 4));
    gui.add(done.setup("done"));
    
    // we set scenes here
    currentScene = 0;
    
    scenes[0] = new menu();
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
    
    float myBounce = ofMap(bounce, 1, 4, 0.2f, 1.0f);
    float myFriction = ofMap(friction, 1, 4, 0.015f, 0.09f);
    int myRadiusMax = ofMap(radiusMax, 1, 4, 40, 120);
    int matterAmount= ofMap(radiusMax, 1, 4, 100, 400);

    ((gameplay*)scenes[1])->setBounce(myBounce);
    ((gameplay*)scenes[1])->setFriction(myFriction);
    ((gameplay*)scenes[1])->setRadiusMax(myRadiusMax);
    ((gameplay*)scenes[1])->setMatter(matterAmount);
    ((gameplay*)scenes[1])->setEat(eat);
    ((gameplay*)scenes[1])->setTrap(trap);

    currentScene = 1;
    

        
}


