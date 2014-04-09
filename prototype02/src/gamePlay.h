
#include "ofMain.h"
#include "baseScene.h"
#include "ball.h"
#include "field.h"
#include "matter.h"
#include "trap.h"
#include "gola.h"
#include "score.h"
#include "obstacle.h"
#include "timer.h"
enum E_OPTION{ NO_INITI,
               INITI_TOP_BALL,
               INITI_BOT_BALL,
               DRAG_BALL,
               INITI_OBSTACLE_TOP,
               INITI_OBSTACLE_BOT
};
enum E_OVER{
    NOT_START,
    STEP_ONE,
    STEP_TWO,
    STEP_THREE,
};

enum E_WINNING{
    TOP_WIN,
    BOT_WIN,
    TIE
};

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
    void checkScole();

    void imageLoader();
    void checkGameover();
    
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
    void setStartTime(float time);
    void setTimer(float time);
    void setSceneNum(int &Scene);
    
    field           myField;
    matter          myMatter[2];
    trap            myTrap;
    E_OPTION        touchOption;
    E_OVER          overStep;
    E_WINNING       winning;
    vector <Ball>   myBalls;

    ofImage         image[3];
    
    bool            bTrap, bEat, bShrink, bGameOver;
    float           friction,bounce,radiusMax,radiusMin,massMax,abstacleMax,abstacleMin,abstacleSpeed,overTimer;
    int *           scene;
    gola            golaTop, golaBot;
    score           Score;
    obstacle        Obstacle;
    timer           Timer;
    ofTrueTypeFont  font;
};

