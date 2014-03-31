
#include "ofMain.h"
#include "baseScene.h"
#include "ball.h"
#include "field.h"
#include "matter.h"
#include "trap.h"

enum E_OPTION{ NO_INITI,INITI_TOP_BALL,INITI_BOT_BALL,DRAG_TOP_BALL,DRAG_BOT_BALL, DRAG_MID_BALL, DRAG_BALL};

class gameplay :public baseScene{
    
    void setup();
    void update();
    void draw();
    void exit();
    void checkBallRadius();
    void touchDown(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);
    void checkCollision();
    void imageLoader();
    
    
public:
    void addTrap();
    void addEat(Ball A,Ball B, int a, int b);
    void addShrink(Ball &A,Ball &B);
    //setup ball paramater
    void setTrap(bool trap);
    void setEat(bool eat);
    void setShrink(bool shink);
    void setFriction(float Friction);
    void setBounce(float Bounce);
    void setRadiusMax(float RadiusMax);
    void setRadiusMin(float RadiusMin);
    void setMatter(int Matter);
    void setMassMax(int MassMax);
    





    field           myField;
    matter          myMatter[2];
    trap            myTrap;
    E_OPTION        touchOption;

    vector <Ball>   myBalls;
    
    ofImage         image[3];
    
    bool            bTrap, bEat, bShrink;
    float           friction,bounce,radiusMax,radiusMin,massMax;
    
};

