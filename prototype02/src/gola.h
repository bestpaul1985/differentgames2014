//
//  gola.h
//  prototype02
//
//  Created by Peng Cheng on 4/8/14.
//
//

#ifndef __prototype02__gola__
#define __prototype02__gola__

#include "ofMain.h"

class gola{
public:
    void setup(int where);
    bool conllision(ofPoint pos, float radius);
    void draw();
    
    ofRectangle rect;
};

#endif /* defined(__prototype02__gola__) */
