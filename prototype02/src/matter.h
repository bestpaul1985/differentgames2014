#include "ofMain.h"

class matter{
public:
    
    matter();
    void initial(int Num);
    void update();
    void draw();
    void setAmount(int Amount);
    
    
    ofVec2f                         pos;
    int                             amount;
    int                             totalAmount;

    int                             num, h, w;
    ofRectangle                     frontground,background;
    
    ofColor                         color;
    
    ofImage                         image[2];
};