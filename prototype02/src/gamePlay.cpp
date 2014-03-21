
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
}

//--------------------------------------------------------------
void gameplay::update(){
    myMatter[0].update();
    myMatter[1].update();
    checkBallRadius();
    
	for(int i=0; i<myBalls.size(); i++) {
//      myBalls[i].chcekFollower(myField.midRect);
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

    
    
    if(myField.midRect.inside(touchPos)){
        
        for (int i=0; i<myBalls.size(); i++) {
            dis = myBalls[i].location.distance(touchPos);
            if (dis <myBalls[i].radius+radiusMin) {
                bInitial = false;
                if (dis<myBalls[i].radius && myBalls[i].bFinalized) {
                    touchOption = DRAG_BALL;
                    num = i;
                }
                break;
            }
        }
    }
    else if (myField.topRect.inside(touchPos)){
        
        
        for (int i=0; i<myBalls.size(); i++) {
            dis = myBalls[i].location.distance(touchPos);
            if (dis <myBalls[i].radius+radiusMin) {
                bInitial = false;
                if (dis<myBalls[i].radius && myBalls[i].bFinalized) {
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
                if (dis<myBalls[i].radius&& myBalls[i].bFinalized) {
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
            myMatter[0].amount--;
            
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
            myMatter[1].amount--;
        }
            break;
            
//        case DRAG_TOP_BALL:{
//            
//            if (myBalls[num].ballID==ID_TOP_BALL) {
//                myBalls[num].bFolloer = true;
//                myBalls[num].followPos.set(touchPos);
//                myBalls[num].touchID = touch.id;
//            }
//            
//            
//        }
//            break;
//        case DRAG_BOT_BALL:{
//            if (myBalls[num].ballID==ID_BOT_BALL) {
//                myBalls[num].bFolloer = true;
//                myBalls[num].followPos.set(touchPos);
//                myBalls[num].touchID = touch.id;
//
//            }
//        }
//            break;
//            
//        case DRAG_MID_BALL:{
//                myBalls[num].bFolloer = true;
//                myBalls[num].followPos.set(touchPos);
//                myBalls[num].touchID = touch.id;
//        }
//            break;
//            
        case DRAG_BALL:{
            myBalls[num].bFolloer = true;
            myBalls[num].followPos.set(touchPos);
            myBalls[num].touchID = touch.id;
            
            cout<<"ok3"<<endl;
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
void gameplay::setTrap(bool trap){
    bTrap = trap;
}
//--------------------------------------------------------------
void gameplay::setEat(bool eat){
    bEat = eat;
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
    myMatter[0].totalAmount = Matter;
    myMatter[1].totalAmount = Matter;
};





