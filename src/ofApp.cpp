#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // listen on the given port
    ofLog() << "listening for osc messages on port " << PORT;
    receiver.setup(PORT);
    
    camWidth = 640;  // try to grab at this size.
    camHeight = 480;
    
    //get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    for(size_t i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            //log the device
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            //log the device and note it as unavailable
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth, camHeight);

    ofSetVerticalSync(true);
}


//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(100, 100, 100);
    vidGrabber.update();
    
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        if(m.getAddress() == "/screenshot/right"){
            shutterRight = true;
            printf("screenshot right!");
        }

        if(m.getAddress() == "/screenshot/left"){
            shutterLeft = true;
            printf("screenshot left!");
        }
        
        if(m.getAddress() == "/screenshot"){
            shutterAll = true;
            printf("screenshot all!");
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(100, 0);
    
//    webCam描画
    vidGrabber.draw(0, 0, camWidth,camHeight);
    
    
//    スクリーンショット撮影 webCam描画より後ろにおく！
    if(shutterRight == true){
        screenShot.grabScreen(0, 0 , camWidth/2, camHeight);
        printf("screenshot right!");
        screenShot.save("screenshot_right.png");
        shutterRight = false;
    }
    
    if(shutterLeft == true){
        screenShot.grabScreen(camWidth/2, 0, camWidth/2, camHeight);
        printf("screenshot left!");
        screenShot.save("screenshot_left.png");
        shutterLeft = false;
    }
    
    if(shutterAll == true){
        screenShot.grabScreen(0, 0, camWidth, camHeight);
        printf("screenshot all!");
        screenShot.save("screenshot_all.png");
        shutterAll = false;
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

//    スクショ用
    if(key == 'r' || key == 'R'){
        screenShot.grabScreen(0, 0 , camWidth/2, camHeight);
        printf("screenshot right!");
        screenShot.save("screenshot_right.png");
    }
    
    if(key == 'l' || key == 'L'){
        screenShot.grabScreen(camWidth/2, 0, camWidth/2, camHeight);
        printf("screenshot left!");
        screenShot.save("screenshot_left.png");
    }
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
