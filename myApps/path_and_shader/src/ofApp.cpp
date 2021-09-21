#include "ofMain.h"
#include "ofApp.h"
#include "utility.h"


//--------------------------------------------------------------
void ofApp::update(){

}

//ofApp.h

//ofApp.cpp

void ofApp::setup(){
    
    shader_2.load("shadersGL3/shader_2");
    shader_uv.load("shadersGL3/shader_uv");
    shader_fdbk.load("shadersGL3/feedback");
    
    for(int i = 0; i < 2; i++) {
        buffers[i].allocate(ofGetWidth(), ofGetHeight());
        buffers[i].activateAllDrawBuffers();
    }
    
    plane.set(200, 200);
    plane.setPosition(200, 200, 0);
    
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
    
    auto targetFBO = buffers[fdbkInd%2];
    auto lastFrameFBO = buffers[(fdbkInd+1)%2];
    fdbkInd++;
    
//    targetFBO.clear(); //todo: why does this flip the Y axis?
    targetFBO.begin();
        ofClear(0, 0, 0);
    
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
        float t2 = 0;
        auto root = glm::vec2(sinN(t2)*200, cosN(t2)*200);
        plane.setPosition(root.x, root.y, 0);
//        shader_uv.setUniform4f("bbox", root.x-100, root.y-100, 200, 200); //why is this wrong?
        auto bbox_plane = getPlaneBbox(plane);
        setBBoxUniform(bbox_plane, shader_uv);
        plane.draw();
        shader_uv.end();
    
        shader_uv.begin();
        setPath(path2, time);
        auto bbox = getPathBbox(path2);
        setBBoxUniform(bbox, shader_uv);
        path2.draw();
        shader_uv.end();
    
    targetFBO.end();
    
//    shader_fdbk.begin();
//        setResolutionUniform(shader_fdbk);
//        shader_fdbk.setUniformTexture("currentColor", targetFBO.getTexture(), 0);
////        shader_fdbk.setUniformTexture("currentDepth", targetFBO.getDepthTexture(), 1);
//        shader_fdbk.setUniformTexture("lastColor", lastFrameFBO.getTexture(), 2);
////        shader_fdbk.setUniformTexture("lastDepth", lastFrameFBO.getDepthTexture(), 3);
//        shader_fdbk.setUniform4f("bbox", 0, 0, ofGetWidth(), ofGetHeight());
//
//        ofDrawPlane(0, 0, ofGetWidth(), ofGetHeight());
//    shader_fdbk.end();
    
    targetFBO.draw(0, 0); //why does using FBO at all seem to change color of path-quad?
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
