#pragma once

#include "ofMain.h"

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
    
        ofShader shader;
        ofShader shader_2;
        ofShader shader_uv;
    
        ofPath path;
        ofPath path2;
		
        vector<ofFbo> buffers{ofFbo(), ofFbo()};
        int fbkInd = 0;
    
//        ofFbo fdbkBuffer1;
//        ofFbo fdbkBuffer2;
};