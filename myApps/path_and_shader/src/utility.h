//
//  utility.cpp
//  path_and_shader
//
//  Created by Avneesh Sarwate on 9/16/21.
//
#include "ofMain.h"


ofRectangle getPathBbox(ofPath &path) {
    ofRectangle rect;
    for (int i=0; i<path.getOutline().size(); i++) {
        ofRectangle b = path.getOutline().at(i).getBoundingBox();
        if (i==0) rect = b;
        else rect.growToInclude(b);
    }
    return rect;
}

ofRectangle getPlaneBbox(ofPlanePrimitive &plane) {
    ofRectangle rect;
    auto vertices = plane.getMesh().getVertices();
    for (int i=0; i< vertices.size(); i++) {
        auto pt = vertices.at(i);
        rect.growToInclude(glm::vec2(pt.x, pt.y));
    }
    return rect;
}

ofRectangle getCircleBbox(float x, float y, float rad) {
    ofRectangle rect = ofRectangle(x-rad, y-rad, rad*2, rad*2);
    return rect;
}

void setBBoxUniform(ofRectangle bbox, ofShader shader) {
    shader.setUniform4f("bbox", bbox.getMinX(), bbox.getMinY(), bbox.getWidth(), bbox.getHeight());
}

void setResolutionUniform(ofShader shader) {
    shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
}
