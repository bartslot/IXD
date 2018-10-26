#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor::black);
    
    primitive = ofIcoSpherePrimitive(sphereRadius, 2);
}

//--------------------------------------------------------------
void ofApp::update(){
    auto triangles = primitive.getMesh().getUniqueFaces();
    auto quad = primitive.getMesh().getUniqueFaces();
    float displacement = sin(ofGetElapsedTimef() * 2) * 5;
    
    for (int i = 0; i < triangles.size(); ++i) {
        ofVec3f faceNormal = triangles[i].getFaceNormal();
        for (int j = 1 ; j< 2; j++) {
            triangles[i].setVertex(j,
                triangles[i].getVertex(j)+ faceNormal * displacement);
        }
    }
    primitive.getMesh().setFromTriangles(triangles);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth() / 2, ofGetHeight() /2);
    
    primitive.rotateDeg(spinX, 1, 0, 0);
    primitive.rotateDeg(spinY, 0, 1, 0);
    
    if(drawWireframe) {
        primitive.drawWireframe();
    } else {
        primitive.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        drawWireframe = !drawWireframe;
    }
    if (key == 'y'){ //Sphere SpinY +1
        spinY++;
        if (spinY == 25) {
            spinY = 20;
        }
    }
    if (key == 'x'){ //Sphere SpinX +1
        spinX++;
        if (spinX == 25) {
            spinX = 20;
        }
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
