#include "matter.h"

matter::matter(){
    
    amount = 200;
    
}

void matter::initial(int x, int y, int degree,ofImage &image01, ofImage &image02, ofImage &image03){

    matter01 = &image01;
    matter02 = &image02;
    mask = &image03;
    
    width = matter01->getWidth();
    height = matter01->getHeight();
    
    maskFbo.allocate(width,height);
    fbo.allocate(width,height);
    
    shader.load("shaders/alphamask.vert","shaders/alphamask.frag");
    
    maskFbo.begin();
    ofClear(0,0,0,255);
    maskFbo.end();
    
    fbo.begin();
    ofClear(0,0,0,255);
    fbo.end();
    
    matterPos.set(x, y);
    angle = degree;
}

void matter::update(){
    
    int h = (int)ofMap(amount, 200, 0, -160, 0, true);
    maskFbo.begin();
    mask->draw(0,h);
    maskFbo.end();
    
    fbo.begin();
    
    ofClear(0, 0, 0, 0);
    
    shader.begin();
    
    shader.setUniformTexture("maskTex", maskFbo.getTextureReference(), 1 );
    
    matter02->draw(0,0);
    
    shader.end();
    
    fbo.end();
    
}

void matter::draw(){
    
    
    ofPushMatrix();
    ofTranslate(matterPos.x+width/2, matterPos.y+height/2);
    ofRotateZ(angle);
    ofSetColor(255,255);
    matter01->draw(-width/2,-height/2);
    fbo.draw(-width/2,-height/2);
    ofPopMatrix();

}

void matter::setAmount(int Amount){
    amount = Amount;
}








