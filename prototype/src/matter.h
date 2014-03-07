#include "ofMain.h"

class matter{
public:
    
    matter();
    void initial(int x, int y, int degree,ofImage &image01, ofImage &image02, ofImage &image03);
    void update();
    void draw();
    void setAmount(int Amount);
    
    
    ofImage *                         matter01;
    ofImage *                         matter02;
    ofImage *                         mask;
    
    ofFbo                           maskFbo;
    ofFbo                           fbo;
    ofShader                        shader;
    ofVec2f                         matterPos;
    int                             amount;
    int                             angle;
    int                             width,height;
};