//
//  obstacle.cpp
//  prototype02
//
//  Created by Peng Cheng on 4/8/14.
//
//

#include "obstacle.h"
//-----------------------------------------------------------------
void obstacle::setup(){
    

    int maxI = 7;
    int maxJ = 4;
    int w = 768/maxI;
    int h = (512-200)/maxJ;
    
    for (int i=0 ; i<maxI-1; i++) {
        for (int j=1; j<maxJ; j++){
            ofPoint pos;
            pos.set(w+w*i, 200+h*j);
            topPos.push_back(pos);
        }
    }
    
    for (int i=0 ; i<maxI-1; i++) {
        for (int j=1; j<maxJ; j++){
            ofPoint pos;
            pos.set(w+w*i, 512+h*j);
            botPos.push_back(pos);
        }
    }
}
//-----------------------------------------------------------------
void obstacle::draw(){

    for (int i=0; i<topPos.size(); i++) {
        ofSetColor(150,255);
        ofCircle(topPos[i], 2);
    }
    
    for (int i=0; i<botPos.size(); i++) {
        ofSetColor(150,255);
        ofCircle(botPos[i], 2);
    }

}
//-----------------------------------------------------------------