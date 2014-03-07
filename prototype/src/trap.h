
#include "ofMain.h"
class trap{
public:
    
    trap();
    void setup(int x, int y);
    void update();
    void draw();
    
    ofVec2f pos;
    float raduis;
    int   alpha;
    
    bool bOpen;
    bool bKill;
    float timer;
};

