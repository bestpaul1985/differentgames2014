#include "ofMain.h"

class field{

public:
    
    field();
    void setup();
    void update();
    void draw();
    void drawTop();
    void drawBot();
    ofRectangle topRect,botRect, midRect, midRectTop,midRectBot;
};
