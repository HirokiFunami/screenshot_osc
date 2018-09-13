#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include <string>

// listening port
#define PORT 8888

// max number of strings to display
#define NUM_MSG_STRINGS 20

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofVideoGrabber vidGrabber;
        int camWidth;
        int camHeight;
    
        ofImage screenShot;
    
        ofTrueTypeFont font;
        ofxOscReceiver receiver;
    
//    撮影トリガー
        bool shutterLeft = false;
        bool shutterRight = false;
        bool shutterAll = false;
    
        int imageNum = 10000000;
		
};
