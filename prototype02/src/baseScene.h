#ifndef _BASE_SCENE
#define _BASE_SCENE


#include "ofMain.h"


class baseScene {
	

public: 
	
	virtual void setup(){};
	virtual void update(){};
	virtual void draw(){};
    
    virtual void touchDown(ofTouchEventArgs & touch){};
    virtual void touchMoved(ofTouchEventArgs & touch){};
    virtual void touchUp(ofTouchEventArgs & touch){};
    virtual void touchDoubleTap(ofTouchEventArgs & touch){};
    virtual void touchCancelled(ofTouchEventArgs & touch){};

    virtual void checkCollision(){};
    virtual void checkBallRadius(){};

    virtual void imageLoader(){};
    
};

#endif