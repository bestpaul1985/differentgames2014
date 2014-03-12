#pragma mark once

#include "ofMain.h"

#define otherObjsCount 2

class Ball{
    public:
        Ball();

        void addForce(ofVec2f force);
        void update();
        void draw();
        void collision(Ball& b1);
        void changeRadius();
        void follow();
        void joint();
        void addDampingForce();
    
        ofVec3f location;
        ofVec3f velocity;
        ofVec3f acceleration;
        float mass; // how heavy are we?
        float maximum_velocity;
        // How bouncy are we? 1 means we don't lose any speed in bouncing,
        // higher means we gain speed, lower means we lose it
        float bounce;
        float radius;
        float damping;
        int touchID;
        ofColor color;
        bool bFinalized;
        bool bFolloer;
        bool bJoint;

        ofPoint followPos;
        ofPoint anchor;
    


};
