#include "ofMain.h"
#include "ofxBox2dCircle.h"

class ball : public ofxBox2dCircle{

public:
    ball();
    
    void draw();
    void setTopGroup();
    void setBotGroup();
    bool bRemove;
    bool bFinish;
    int touchID;
    ofColor color;
    int group;
};