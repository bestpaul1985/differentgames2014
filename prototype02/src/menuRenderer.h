//
//  menuRenderer.h
//  prototype02
//
//  Created by Peng Cheng on 3/31/14.
//
//

#ifndef __prototype02__menuRenderer__
#define __prototype02__menuRenderer__

#include "ofMain.h"
class ballSetting{
public:
    void setup(string name){
        parameters.setName(name);
        parameters.add(radiusMax.set( "Radius", 2, 1, 4));
        parameters.add(bounce.set( "Bounce", 2, 1, 4));
        parameters.add(friction.set( "Friction", 2, 1, 4));
    }
   
    ofParameterGroup parameters;
    ofParameter<float> radiusMax;
	ofParameter<float> bounce;
    ofParameter<float> friction;
   
};

class fieldSetting{
public:
    void setup(string name){
    
        parameters.setName(name);
        parameters.add(matter.set("Matter",4,1,4));
        parameters.add(trap.set("trap",false));
        parameters.add(eat.set("eat", false));
        parameters.add(shrink.set("Shrink", false));

    }
    
    ofParameterGroup parameters;
    ofParameter<float> matter;
    ofParameter<bool> trap;
    ofParameter<bool> eat;
    ofParameter<bool> shrink;

};

class winningSituation{
public:
    void setup(string name){

        parameters.setName(name);
        parameters.add(score.set("Score",10,1,20));
        
    };
    
    ofParameterGroup parameters;
    ofParameter<int> score;
    
};
#endif /* defined(__prototype02__menuRenderer__) */
