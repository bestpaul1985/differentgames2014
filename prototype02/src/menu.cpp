#include "menu.h"

//--------------------------------------------------------------
void menu::setup(){
    
    
    int w = 500;
    int h = 150;
    int offset = 10;
    int posx = (ofGetWidth()-w)/2;
    int posy = (ofGetHeight()-h*Menu_Num-offset*Menu_Num)/2;
    
    
    string title;
    title = "+ TRAP ME +";
    myMenu[0].setup(posx, posy+h*0+offset*0, w, h, title,30, true);
   
    title = "+ EAT IT +";
    myMenu[1].setup(posx, posy+h*1+offset*1, w, h, title, 30, true);
    
    title = "GO";
    myMenu[2].setup(posx, posy+h*2+offset*4, w, h, title, 60, false);
    myMenu[2].color.set(190, 60, 200);
    
}

//--------------------------------------------------------------
void menu::update(){
    
    
    if (!myMenu[0].bSelected && !myMenu[1].bSelected) {
        myMenu[2].color.a = 100;
    }else{
        myMenu[2].color.a = 255;
    }
    
    
    for (int i=0; i<Menu_Num; i++) {
        myMenu[i].update();
    }
    
}

//--------------------------------------------------------------
void menu::draw(){
    
    for (int i=0; i<Menu_Num; i++) {
        myMenu[i].draw();
    }
}

//--------------------------------------------------------------
void menu::touchDown(ofTouchEventArgs & touch){
    
    for (int i=0; i<Menu_Num; i++) {
        myMenu[i].touchDown(touch.x,touch.y,touch.id);
    }
}

//--------------------------------------------------------------
void menu::touchMoved(ofTouchEventArgs & touch){
  
    for (int i=0; i<Menu_Num; i++) {
        myMenu[i].touchMoved(touch.x,touch.y,touch.id);
    }
    
}

//--------------------------------------------------------------
void menu::touchUp(ofTouchEventArgs & touch){
   
    for (int i=0; i<Menu_Num; i++) {
        myMenu[i].touchUp(touch.x,touch.y,touch.id);
    }
    
}

//--------------------------------------------------------------
bool menu::isDone(){

    return myMenu[2].bDone;
}

//--------------------------------------------------------------
void menu::reset(){
    
    myMenu[0].bSelected = false;
    myMenu[1].bSelected = false;
    myMenu[2].bDone = false;
    
}

//--------------------------------------------------------------
bool menu::bTrap(){
    return myMenu[0].bSelected;

}

//--------------------------------------------------------------
bool menu::bEat(){
    return myMenu[1].bSelected;
}



