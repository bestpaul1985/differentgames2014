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
        parameters.add(eat.set("Eat", false));
        parameters.add(shrink.set("Shrink", false));
    }
   
    ofParameterGroup parameters;
    ofParameter<float> radiusMax;
	ofParameter<float> bounce;
    ofParameter<float> friction;
    ofParameter<bool> eat;
    ofParameter<bool> shrink;

};

class worldSetting{
public:
    void setup(string name){
    
        parameters.setName(name);
        parameters.add(matter.set("Matter",400,0,400));
        parameters.add(timer.set("Time",60,0,120));
        parameters.add(trap.set("Trap",false));
        parameters.add(goal.set("Goal",true));
        parameters.add(bumpers.set("Bumpers",true));
        parameters.add(scoreboard.set("Scoreboard",true));
    }
    
    ofParameterGroup parameters;
    
    ofParameter<int> matter;
    ofParameter<int> timer;
    ofParameter<bool> trap;
    ofParameter<bool> goal;
    ofParameter<bool> bumpers;
    ofParameter<bool> scoreboard;

  

};

#endif /* defined(__prototype02__menuRenderer__) */
