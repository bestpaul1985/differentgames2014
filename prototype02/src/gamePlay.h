
#include "ofMain.h"
#include "baseScene.h"
#include "ball.h"
#include "field.h"
#include "matter.h"
#include "trap.h"

enum E_OPTION{ NO_INITI,INITI_TOP_BALL,INITI_BOT_BALL,DRAG_TOP_BALL,DRAG_BOT_BALL};

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
    void setTrap();
    void setEat();
    void addTrap();
    void addEat(Ball A,Ball B, int a, int b);

    field           myField;
    vector <Ball>   myBalls;
    float           radius;
    E_OPTION        touchOption;
    
    matter          myMatter[2];
    ofImage         image[3];
    bool            bTrap, bEat;
    
    trap            myTrap;
};

