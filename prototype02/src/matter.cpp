#include "matter.h"

matter::matter(){
    
    color.set(134, 60, 227);
    totalAmount = 400;
}
//------------------------------------------------------
void matter::initial(int Num){

    num = Num;
    h = 120;
    
    if (num == 0) {
        image.loadImage("image/frontFull.png");
        pos.set(40,40);
        imagePos.set(0, 0);
    }
    
    if (num == 1) {
        image.loadImage("image/frontFull02.png");
        pos.set(ofGetWidth()-40-120,ofGetHeight()-40-120);
        imagePos.set(0,ofGetHeight()-200);
    }
    
    font.loadFont("font/faucet.ttf", 20);
}
//------------------------------------------------------
void matter::update(){
    
    //normal
    h = ofMap(amount, 0, totalAmount, 120, 0);
    if (num == 1) h *= -1;
    
    
    if (lastAmount != amount) {
        int d = amount-lastAmount;
        string s;
        if (d>0) {
            s = "+ "+ ofToString(d);
        }else{
            s = "- "+ ofToString(d);
        }
        changer temp;
        if (num == 0) temp.setup(100, 100, 0, font, s);
        if (num == 1) temp.setup(ofGetWidth()-120, ofGetHeight()-120, 1, font, s);

        Changer.push_back(temp);
    }
    
    lastAmount = amount;
    
    
    //unlimited
    if (bUnlimited) {
        amount = 400;
    }
   
}
//------------------------------------------------------
void matter::draw(){

    ofSetColor(255,221,0);
    ofPushMatrix();
    ofTranslate(pos.x, pos.y-h);
    ofRect(0,0,120,120);
    ofPopMatrix();
    ofSetColor(255);
    image.draw(imagePos, image.getWidth(),image.getHeight());
    
    for (int i=0; i<Changer.size(); i++) {
        Changer[i].draw();
        if (Changer[i].bRemove) {
            Changer.erase(Changer.begin()+i);
        }
    }
    
    string s;
    if (bUnlimited) {
        s = "Unlimited";
    }else{
        s = ofToString(amount);
    }
    
    if (num == 0) {
        ofPushMatrix();
        ofTranslate(100,100);
        ofRotateZ(180);
        ofSetColor(180, 255);
        font.drawString(s, -(int)font.stringWidth(s)/2,(int)font.stringHeight(s)/2);
        ofPopMatrix();
    }
    
    if (num == 1) {
        ofPushMatrix();
        ofTranslate(768-100,1024-100);
        ofSetColor(180, 255);
        font.drawString(s, -(int)font.stringWidth(s)/2,(int)font.stringHeight(s)/2);
        ofPopMatrix();
    }
    
    
}
//------------------------------------------------------
void matter::setAmount(int Amount){
    amount = Amount;
}








