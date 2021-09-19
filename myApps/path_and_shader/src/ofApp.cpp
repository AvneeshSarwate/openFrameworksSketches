#include "ofMain.h"
#include "ofApp.h"
#include "utility.h"


//--------------------------------------------------------------
void ofApp::update(){

}

//ofApp.h

//ofApp.cpp

void ofApp::setup(){
    
    shader.load("shadersGL3/shader");
    shader_2.load("shadersGL3/shader_2");
    shader_uv.load("shadersGL3/shader_uv");
    
    
    buffers[0].allocate(ofGetWidth(), ofGetHeight());
    buffers[1].allocate(ofGetWidth(), ofGetHeight());
    
    int low = 20;
    int high = 240;
    path.moveTo(low,low);
    path.lineTo(high,low);
    path.lineTo(high,high);
    path.lineTo(low,high);
    path.close();
}

double sinN(double t) { return (sin(t)+1)/2; }
double cosN(double t) { return (cos(t)+1)/2; }

void setPath(ofPath &path, float time) {
    path.clear();
    int circle_res = 20;
    float resf = (float) circle_res;
    int rad = 100;
    auto startPt = glm::vec2(400 + sinN(time)*100, 400);
//    path.moveTo(startPt);
    for(int i = 0; i < circle_res+3; i++) {
        float deg = i/resf * PI*2;
        auto pt = startPt + glm::vec2(sin(deg), cos(deg)) * rad;
        if(i == 0){
            path.moveTo(pt);
        }
        path.curveTo(pt);
        
    }
    path.close();
}

void ofApp::draw(){
    ofSetColor(255);
    auto time = ofGetElapsedTimef();
    
    shader_2.begin();
    shader_2.setUniform1f("time", (float)time);
    path.draw();
    shader_2.end();
    
    
    shader_uv.begin();
    auto bbox_circ = getCircleBbox(sinN(time)*ofGetWidth(), cosN(time)*ofGetHeight(), 120);
    setBBoxUniform(bbox_circ, shader_uv);
    ofDrawCircle(sinN(time)*ofGetWidth(), cosN(time)*ofGetHeight(), 120);
    shader_uv.end();
    
    shader_uv.begin();
    setPath(path2, time);
    auto bbox = getPathBbox(path2);
    setBBoxUniform(bbox, shader_uv);
    path2.draw();
    shader_uv.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
