
#include "ofMain.h"
class button{
public:
    void setup(int posx,int posy, int w, int h, string Title, int fontsize, bool Trigle);
    void update();
    void draw();
    void touchDown(int x, int y, int touchID);
    void touchMoved(int x, int y, int touchID);
    void touchUp(int x, int y, int touchID);
    
    button();
    ofRectangle rect;
    ofColor     color;
    ofColor     fontColor;
    int         alpha;
    bool        bSelected;
    bool        trigle;
    bool        bDone;
    ofPoint     offset;
    ofTrueTypeFont font;
    string title;
};
