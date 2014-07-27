#include "Button.h"

button::button(){
    
    color.set(255, 200, 30, 150);
    bDone = false;

}
//--------------------------------------------------------------
void button::setup(int posx,int posy, int w, int h, string Title, int fontsize,  bool Trigle){

    rect.set(posx, posy, w, h);
    fontColor.set(255);
    font.loadFont("font/frabk.ttf", fontsize);
    title = Title;
    bSelected = false;
    trigle = Trigle;
    
}
//--------------------------------------------------------------

void button::update(){
    
    if (trigle) {
        if (bSelected) {
            color.a = 255;
        }else{
            color.a = 150;
        }
    }
    
}
//--------------------------------------------------------------

void button::draw(){
    
    
    ofSetColor(color);
    ofRect(rect.position.x+offset.x,rect.position.y+offset.y,rect.width,rect.height+offset.y);
    
    ofSetColor(fontColor);
    ofPoint center = rect.getCenter();
    float fontW = font.stringWidth(title);
    float fontH = font.stringHeight(title);
    font.drawString(title, center.x-fontW/2+offset.x, center.y+fontH/2+offset.y);

    
}
//--------------------------------------------------------------

void button::touchDown(int x, int y, int touchID){
    
    if (touchID == 0) {
        if (rect.inside(x, y) ) {
            bSelected = !bSelected;
            offset.set(3, 3);
        }
       
    }
}
//--------------------------------------------------------------

void button::touchMoved(int x, int y, int touchID){
    
    if (touchID == 0) {
        if (rect.inside(x, y)) {
            offset.set(3, 3);
        }else{
            offset.set(0, 0);
        }
    }
    
    
}
//--------------------------------------------------------------

void button::touchUp(int x, int y, int touchID){
    
    if (touchID == 0) {
        offset.set(0, 0);
        if (rect.inside(x, y)) {
            bDone = true;
        }
    }
    
    
}







