
#include "ball.h"

Ball::Ball() {
	
    bFinalized = false;
    bFolloer = true;
    bJoint = true;
    bFixed = false;
    alpha = 50;
    mass = 0;
}
//--------------------------------------------------------------
void Ball::update() {
	
    mass = ofMap(radius, 0, radiusMax, 0, massMax);
    //    cout<<mass<<" radius"<<radius<<" radiusMax"<<radiusMax<<" massMax"<<massMax<<endl;
    velocity += acceleration;
    location += velocity;
    acceleration.set(0.0f,0.0f,0.0f);
    // this assumes that the height of the window is 800px and the width is 1000
    // you can also use the getWindowSize() method to determine how large the window is
    if (location.y > ofGetHeight()-radius) {
        velocity.y *= -bounce;
        location.y = ofGetHeight()-radius;
    }
    if(location.y < radius) {
        velocity.y *= -bounce;
        location.y = radius;
    }
    if (location.x > ofGetWidth()-radius) {
        velocity.x *= -bounce;
        location.x = ofGetWidth()-radius;
    }
    if (location.x < radius) {
        velocity.x *= -bounce;
        location.x = radius;
    }
	
}
//--------------------------------------------------------------
void Ball::draw() {
    
    if(bFixed &&velocity.length() < 0.05){
        alpha = 255;
    }
    else if (bFinalized && !bFolloer) {
        alpha = 150;
    }else if (bFinalized && bFolloer) {
        alpha = 100;
    }
    
    
    ofSetColor(color,alpha);
    ofCircle(location.x, location.y, radius);
}

//--------------------------------------------------------------
void Ball::collision(Ball& b1)
{	
//	cout << b1.mass << " " << b1.location.x << " " << b1.location.y << endl;
    // we'll just declare all these things we'll need at once
    float newMass, diff, angle, newX, newY, newVelocityX, newVelocityY, fy21, sign;
	
    newMass = b1.mass/mass;
    newX = b1.location.x - location.x;
    newY = b1.location.y - location.y;
    newVelocityX = b1.velocity.x - velocity.x;
    newVelocityY = b1.velocity.y - velocity.y;
	
    //  If the balls aren't heading at one another, we don't want to alter them 
    //  because they could be heading away from each other.
    if ( (newVelocityX*newX + newVelocityY*newY) >= 0) return;
	
    fy21=fabs(newY);
    
    fy21=1.0E-12*fabs(b1.location.y);
    
    if ( fabs(newX)<fy21 ) {
        if (newX<0) { sign=-1; } else { sign=1;}
        newX=fy21*sign;
    }
	
    // Now that we've figured out which direction things are heading,
    // set their velocities.
    angle=newY/newX;
    diff = -2 * (newVelocityX + angle * newVelocityY)/((1 + angle * angle) * (1 + newMass));
    b1.velocity.x = b1.velocity.x + diff;
    b1.velocity.y = b1.velocity.y + angle * diff;
	velocity.x = velocity.x - newMass * diff;
    velocity.y = velocity.y - angle * newMass * diff;
    velocity *= 0.8;
	
}

//--------------------------------------------------------------
void Ball::addForce( ofVec2f force ) {
	
	force /= mass; // make sure the force is modified by the mass
	acceleration += force; // the acceleration is affected by the force
}


//--------------------------------------------------------------
void Ball::follow(){

    if (bFolloer && !bCollided) {
       
        float maxSpeed = 25;
        ofPoint desired = followPos - location;
        float d = desired.length();
        desired.normalize();
        
        if (d < radius) {
            float m = ofMap(d,0,radius,0,maxSpeed);
            desired *= m;
        }else{
            desired *= maxSpeed;
        }
        
        ofPoint steer;
        steer = desired - velocity;
        addForce(steer);
        cout<<"ok4"<<endl;
    }
   
}

//--------------------------------------------------------------
void Ball::joint(){
    
    if (bJoint) {
        float distance = 0.0;
        float springiness = 0.01f;
    
        ofVec2f pta = location;
        ofVec2f ptb = anchor;
	
        float theirDistance = (pta - ptb).length();
        float diff = distance - theirDistance;
        float newDiff = MIN(diff,20);
        float springForce = (springiness * newDiff);
        ofVec2f frcToAdd = (pta-ptb).normalized() * springForce;
        
        addForce(frcToAdd);
    }
}
//--------------------------------------------------------------
void Ball::addDampingForce(){

    acceleration.x = acceleration.x - velocity.x * damping;
    acceleration.y = acceleration.y - velocity.y * damping;
    
}

//--------------------------------------------------------------
void Ball::chcekFollower(ofRectangle rect){

    if (rect.inside(location)) {
        bFolloer = false;
        bFixed = true;
    }else{
        bFixed = false;
    }
    
  
}


