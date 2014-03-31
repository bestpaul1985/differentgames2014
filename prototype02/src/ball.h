#pragma mark once

#include "ofMain.h"

#define otherObjsCount 2
enum E_ID{ID_TOP_BALL, ID_BOT_BALL};

class Ball{
    
    public:
        Ball();

        void addForce(ofVec2f force);
        void update();
        void draw();
        void collision(Ball& b1);
        void follow();
        void chcekFollower(ofRectangle rect);
        void joint();
        void addDampingForce();
        void checkFinalized();
    
        ofVec3f         location;
        ofVec3f         velocity;
        ofVec3f         acceleration;
        ofColor         color;
        // How bouncy are we? 1 means we don't lose any speed in bouncing,
        // higher means we gain speed, lower means we lose it
        float           mass,massMax; // how heavy are we?
        float           bounce;
        float           maximum_velocity;
        float           radius,radiusMax;
        float           damping;
        float           alpha;
        int             touchID;
        bool            bFinalized;
        bool            bFolloer;
        bool            bJoint;
        bool            bFixed;
        bool            bCollided;
    
    
        ofPoint         followPos;
        ofPoint         anchor;
        //top ball or bot ball?
        E_ID            ballID;

    


};
