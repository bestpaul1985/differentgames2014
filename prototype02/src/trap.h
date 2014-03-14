
#include "ofMain.h"
class trap{
public:
    
    trap();
    void setup();
    void update();
    void draw();
    
    ofVec2f pos;
    float radius;
    int   alpha;
    
    bool bOpen;
    bool bKill;
    float timer;
};

