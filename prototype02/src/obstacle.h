//
//  obstacle.h
//  prototype02
//
//  Created by Peng Cheng on 4/8/14.
//
//

#ifndef __prototype02__obstacle__
#define __prototype02__obstacle__

#include "ofMain.h"
class obstacle{
public:
    void setup();
    void draw();
    
    vector<ofPoint> topPos;
    vector<ofPoint> botPos;
    vector<bool> bTop;
    vector<bool> bBot;
    vector<float> topSpeed;
    vector<float> botSpeed;
    
};

#endif /* defined(__prototype02__obstacle__) */
