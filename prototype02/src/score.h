//
//  score.h
//  prototype02
//
//  Created by Peng Cheng on 4/8/14.
//
//

#ifndef __prototype02__score__
#define __prototype02__score__

#include "ofMain.h"

class score{
public:
    
    void setup();
    void draw();
    
    
    ofTrueTypeFont font;
    int scoreTop,scoreBot;
    int rectW,rectH;
};

#endif /* defined(__prototype02__score__) */
