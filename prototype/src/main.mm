#include "ofMain.h"
#include "testApp.h"

int main(){
    ofAppiOSWindow * window = new ofAppiOSWindow();
    window->enableRendererES2();
    
	ofSetupOpenGL(1024,768,OF_FULLSCREEN);			// <-------- setup the GL context
	ofRunApp(new testApp());
}
