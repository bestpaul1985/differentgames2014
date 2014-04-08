
#include "gamePlay.h"

//--------------------------------------------------------------
void gameplay::setup(){

    myField.setup();
    imageLoader();
    myMatter[0].initial(0);
    myMatter[1].initial(1);
    myTrap.setup();
    bTrap = false;
    bEat = false;
    massMax = 5;
    radiusMin = 20;
    golaTop.setup(0);
    golaBot.setup(1);
    Score.setup();
    Obstacle.setup();
}

//--------------------------------------------------------------
void gameplay::update(){
    myMatter[0].update();
    myMatter[1].update();
    checkBallRadius();
    checkScole();
    
	for(int i=0; i<myBalls.size(); i++) {
        myBalls[i].follow();
        myBalls[i].addDampingForce();
		myBalls[i].update();
	}
    
	checkCollision();
    addTrap();
    
}

//--------------------------------------------------------------
void gameplay::draw(){
    
    myField.draw();
    Obstacle.draw();
    Score.draw();
    golaTop.draw();
    golaBot.draw();
    myMatter[0].draw();
    myMatter[1].draw();
    myTrap.draw();

    for(int i=0; i<myBalls.size(); i++) {
        ofPushStyle();
        myBalls[i].draw();
        ofPopStyle();
	}
}


//--------------------------------------------------------------
void gameplay::touchDown(ofTouchEventArgs & touch){
    
    ofPoint touchPos(touch.x,touch.y);
    bool bInitial = true;
    touchOption = NO_INITI;
    int num;
    float dis;
    ofPoint obtaclePos;
    
    if(myField.midRect.inside(touchPos)){
        
        for (int i=0; i<myBalls.size(); i++) {
            dis = myBalls[i].location.distance(touchPos);
            if (dis <myBalls[i].radius+radiusMin) {
                bInitial = false;
                if (dis<myBalls[i].radius && myBalls[i].bFinalized && myBalls[i].ballID != ID_OBTACLE_TOP && myBalls[i].ballID != ID_OBTACLE_BOT&& !myBalls[i].bFolloer) {
                    touchOption = DRAG_BALL;
                }
                break;
            }
        }
        //initial obtacle
        if (bInitial) {
            for (int i=0; i<Obstacle.topPos.size(); i++) {
                dis = Obstacle.topPos[i].distance(touchPos);
                if (dis<20) {
                    touchOption = INITI_OBSTACLE_TOP;
                    obtaclePos = Obstacle.topPos[i];
                    break;
                }
            }
            
            for (int i=0; i<Obstacle.botPos.size(); i++) {
                dis = Obstacle.botPos[i].distance(touchPos);
                if (dis<20) {
                    touchOption = INITI_OBSTACLE_BOT;
                    obtaclePos = Obstacle.botPos[i];
                    break;
                }
            }
        }
    }
    else if (myField.topRect.inside(touchPos)){
        
        
        for (int i=0; i<myBalls.size(); i++) {
            dis = myBalls[i].location.distance(touchPos);
            if (dis <myBalls[i].radius+radiusMin) {
                bInitial = false;
                if (dis<myBalls[i].radius && myBalls[i].bFinalized&& myBalls[i].ballID != ID_OBTACLE_TOP && myBalls[i].ballID != ID_OBTACLE_BOT && !myBalls[i].bFolloer) {
                    touchOption = DRAG_BALL;
                    num = i;
                }
                break;
            }
        }
        
        if (bInitial) {
            if(myMatter[0].amount<=0)return;
            touchOption = INITI_TOP_BALL;
        }
        
    }
    else if(myField.botRect.inside(touchPos)){
        
        for (int i=0; i<myBalls.size(); i++) {
            dis = myBalls[i].location.distance(touchPos);
            if (dis <myBalls[i].radius+radiusMin) {
                bInitial = false;
                if (dis<myBalls[i].radius&& myBalls[i].bFinalized&& myBalls[i].ballID != ID_OBTACLE_TOP && myBalls[i].ballID != ID_OBTACLE_BOT&& !myBalls[i].bFolloer) {
                    touchOption = DRAG_BALL;
                    num = i;
                }
                break;
            }
        }
        
        if (bInitial) {
            if(myMatter[1].amount<=0)return;
            touchOption = INITI_BOT_BALL;
        }
    }
    
    switch (touchOption) {
            
        case INITI_TOP_BALL:{
            
            Ball temp;
            temp.color.set(0,255,30);
            temp.location.set(touchPos);
            temp.followPos.set(touchPos);

            temp.bounce = bounce;
            temp.damping = friction;
            temp.radius = radiusMin;
            temp.radiusMax = radiusMax;
            temp.massMax =  massMax;
            
            temp.touchID = touch.id;
            temp.ballID = ID_TOP_BALL;
            myBalls.push_back(temp);
            myMatter[0].amount-=5;
            
        }
            break;
        case INITI_BOT_BALL:{
            
            Ball temp;
            temp.color.set(255,0,30);
            temp.location.set(touchPos);
            temp.followPos.set(touchPos);

            temp.bounce = bounce;
            temp.damping = friction;
            temp.radius = radiusMin;
            temp.radiusMax = radiusMax;
            temp.massMax =  massMax;

            temp.touchID = touch.id;
            temp.ballID = ID_BOT_BALL;
            myBalls.push_back(temp);
            myMatter[1].amount-=5;
        }
            break;
            
        case DRAG_BALL:{
            myBalls[num].bFolloer = true;
            myBalls[num].followPos.set(touchPos);
            myBalls[num].touchID = touch.id;
            }
            break;
            
        case INITI_OBSTACLE_TOP:{
            
            if (myMatter[0].amount>=100) {
                Ball temp;
                temp.color.set(0,255,30);
                temp.location.set(obtaclePos);
                temp.followPos.set(obtaclePos);
                
                temp.bounce = bounce;
                temp.damping = friction;
                temp.radius = radiusMin;
                temp.radiusMax = radiusMax;
                temp.massMax =  massMax;
                temp.touchID = touch.id;
                temp.ballID = ID_OBTACLE_TOP;
                temp.bObstacle = true;
                
                myBalls.push_back(temp);
                myMatter[0].amount-=50;
            }
        }
            break;
            
        case INITI_OBSTACLE_BOT:{
            
            if (myMatter[0].amount>=100) {

                Ball temp;
                temp.color.set(255,0,30);
                temp.location.set(obtaclePos);
                temp.followPos.set(obtaclePos);
                
                temp.bounce = bounce;
                temp.damping = friction;
                temp.radius = radiusMin;
                temp.radiusMax = radiusMax;
                temp.massMax =  massMax;
                temp.touchID = touch.id;
                temp.ballID = ID_OBTACLE_BOT;
                temp.bObstacle = true;
                
                myBalls.push_back(temp);
                myMatter[0].amount-=50;
            }
        }
            break;
    }
    
}

//--------------------------------------------------------------
void gameplay::touchMoved(ofTouchEventArgs & touch){
    
    ofPoint touchPos(touch.x,touch.y);
    for (int i=0; i<myBalls.size(); i++) {
        if (myBalls[i].touchID == touch.id && myBalls[i].bFolloer) {
            myBalls[i].followPos.set(touchPos);
        }
    }
    
}

//--------------------------------------------------------------
void gameplay::touchUp(ofTouchEventArgs & touch){
    
    for (int i=0; i<myBalls.size(); i++) {
        if (myBalls[i].touchID == touch.id ) {
            myBalls[i].bFinalized = true;
            myBalls[i].bFolloer = false;
        }
    }
    
}

//--------------------------------------------------------------
void gameplay::checkCollision(){
    
    for(int i=0; i<myBalls.size(); i++) {
        bool bCollied = false;
        for(int j=i+1; j<myBalls.size(); j++) {
            if(ofDist(myBalls[i].location.x, myBalls[i].location.y, myBalls[j].location.x, myBalls[j].location.y) <= myBalls[i].radius+myBalls[j].radius) {
				myBalls[i].collision( myBalls[j] );
                addShrink(myBalls[i],myBalls[j]);
                addEat(myBalls[i],myBalls[j], i, j);
                bCollied = true;
            }
        }
        
        if (bCollied) {
            myBalls[i].bCollided = true;
        }else{
            myBalls[i].bCollided = false;
        }
    }
    
    
   
}

//--------------------------------------------------------------
void gameplay::checkBallRadius(){
    
    for(int i=0; i<myBalls.size(); i++) {
        if (!myBalls[i].bFinalized) {
            for(int j=0; j<myBalls.size(); j++) {
                if (i!=j) {
                    if(ofDist(myBalls[i].location.x, myBalls[i].location.y, myBalls[j].location.x, myBalls[j].location.y) <= myBalls[i].radius+myBalls[j].radius) {
                        myBalls[i].bFinalized = true;
                        myBalls[j].bFinalized = true;
                    }
                }
            }
        }
    }
    
    
    for(int i=0; i<myBalls.size(); i++) {
        
        if (!myBalls[i].bFinalized) {
            
            if (myBalls[i].ballID == ID_TOP_BALL && myMatter[0].amount>0) {
    
                myBalls[i].radius ++;
                myMatter[0].amount --;
                if (myBalls[i].radius>radiusMax) {
                    myBalls[i].radius = radiusMax;
                    myBalls[i].bFinalized = true;
                }
            }
            else if (myBalls[i].ballID == ID_BOT_BALL && myMatter[1].amount>0){
               
                myBalls[i].radius ++;
                myMatter[1].amount --;
                if (myBalls[i].radius>radiusMax) {
                    myBalls[i].radius = radiusMax;
                    myBalls[i].bFinalized = true;
                }
            }
        }
    }
    
}

//--------------------------------------------------------------
void gameplay::checkScole(){
    
    //balls and golas collision
    for(int i=0; i<myBalls.size(); i++) {
        
        if (golaTop.conllision(myBalls[i].location, myBalls[i].radius) ) {
            if (myBalls[i].ballID == ID_BOT_BALL) {
                myBalls.erase(myBalls.begin()+i);
                Score.scoreBot ++;
            }
           
        }
        else if(golaBot.conllision(myBalls[i].location, myBalls[i].radius)){
            if (myBalls[i].ballID == ID_TOP_BALL) {
                myBalls.erase(myBalls.begin()+i);
                Score.scoreTop ++;
            }
        }
    }
    
}

//--------------------------------------------------------------
void gameplay::imageLoader(){

//    image[0].loadImage("image/front.jpg");
//    image[1].loadImage("image/back.jpg");
//    image[2].loadImage("image/mask.png");
    
}

//--------------------------------------------------------------
void gameplay::addTrap(){

    if (bTrap) {
        myTrap.update();
        if (myTrap.bOpen) {
            for (int i=0; i<myBalls.size(); i++) {
                if (ofDist(myTrap.pos.x, myTrap.pos.y, myBalls[i].location.x, myBalls[i].location.y) < myTrap.radius+myBalls[i].radius/4*3) {
                    myBalls.erase(myBalls.begin()+i);
                    
                }
            }
        }
    }
    
   
}


//--------------------------------------------------------------
void gameplay::addEat(Ball A,Ball B, int a, int b){

    if (bEat && A.ballID != B.ballID ) {
        if (A.radius>B.radius ) {
            
            if (A.ballID == ID_TOP_BALL) {

                myMatter[0].amount += B.radius;
                if (myMatter[0].amount>myMatter[0].totalAmount) {
                    myMatter[0].amount = myMatter[0].totalAmount;
                }
                
            }else{
                myMatter[1].amount += B.radius;
                if (myMatter[1].amount>myMatter[1].totalAmount) {
                    myMatter[1].amount = myMatter[1].totalAmount;
                }
                
            }
            
            myBalls.erase(myBalls.begin()+b);
            
        }else if(B.radius>A.radius){
            
            if (B.ballID == ID_TOP_BALL) {
                
                myMatter[0].amount += A.radius;
                if (myMatter[0].amount>myMatter[0].totalAmount) {
                    myMatter[0].amount = myMatter[0].totalAmount;
                }
                
            }else{
                myMatter[1].amount += A.radius;
                if (myMatter[1].amount>myMatter[1].totalAmount) {
                    myMatter[1].amount = myMatter[1].totalAmount;
                }
                
            }
        
            myBalls.erase(myBalls.begin()+a);
        }
    }
}
//--------------------------------------------------------------
void gameplay::addShrink(Ball &A, Ball &B){

    if (A.ballID != B.ballID && bShrink) {
        A.radius*=0.9;
        B.radius*=0.9;
    
        if (A.radius < radiusMin) A.radius = radiusMin;
        if (B.radius < radiusMin) B.radius = radiusMin;
    }
}

//--------------------------------------------------------------
void gameplay::setTrap(bool trap){
    bTrap = trap;
}
//--------------------------------------------------------------
void gameplay::setEat(bool eat){
    bEat = eat;
}
//--------------------------------------------------------------
void gameplay::setShrink(bool shrink){
    bShrink = shrink;
}
//--------------------------------------------------------------
void gameplay::setFriction(float Friction){
    friction = Friction;
};
//--------------------------------------------------------------
void gameplay::setBounce(float Bounce){
    bounce = Bounce;
};
//--------------------------------------------------------------
void gameplay::setRadiusMax(float RadiusMax){
    radiusMax = RadiusMax;
};
//--------------------------------------------------------------
void gameplay::setRadiusMin(float RadiusMin){
    radiusMin = RadiusMin;
};
//--------------------------------------------------------------
void gameplay::setMassMax(int MassMax){
    massMax = MassMax;
};

//--------------------------------------------------------------
void gameplay::setMatter(int Matter){
    myMatter[0].amount = Matter;
    myMatter[1].amount = Matter;
};





