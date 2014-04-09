#include "ofMain.h"

class changer{

public:
    
 
    void setup(int x, int y, int NUM,ofTrueTypeFont &font, string S){
        num = NUM;
        speed.x = ofRandom(-3,3);
        speed.y = ofRandom(-3,3);
        pos.set(x,y);
        org.set(x,y);
        f = &font;
        s = S;
        bRemove = false;
        timer = ofGetElapsedTimeMillis();
    }
    
    void draw(){
    
        pos += speed;
        ofPushMatrix();
        ofTranslate(pos);
        if (num == 0) {
            ofRotateZ(180);
        }
        int alpha = (int)ofMap(ofGetElapsedTimeMillis()- timer, 0, 500, 255, 100);
        ofSetColor(150, alpha);
        f->drawString(s, -f->stringWidth(s)/2, f->stringHeight(s)/2);
        ofPopMatrix();
        if (ofGetElapsedTimeMillis()- timer > 200)bRemove = true;
    }
    
    ofTrueTypeFont *f;
    string s;
    ofPoint pos, org,speed;
    bool bRemove;
    int num;
    float timer;
};

class matter{
public:
    
    matter();
    void initial(int Num);
    void update();
    void draw();
    void setAmount(int Amount);
    
    
    ofPoint                         pos,imagePos;
    int                             amount, lastAmount;
    int                             totalAmount;
    int                             num, h, w;
    ofRectangle                     frontground,background;
    ofColor                         color;
    ofImage                         image;
    ofTrueTypeFont                  font;
    vector<changer>                 Changer;
};