#include "ofApp.h"

void ofApp::setup() {
    ofSetFrameRate(20);
    ofBackground(ofColor::black);
}

void ofApp::update() {
    rotateX = rotateX + 1;
    rotateY += 2; // zelfde, maar korter dan rotateY = rotateY + 2
    rotateZ += 3;
}

void ofApp::draw() {
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

    if (doRotate) {
        ofRotateXDeg(rotateX);
        ofRotateYDeg(rotateY);
        ofRotateZDeg(rotateZ);
    }

    if (drawGrid) {
        ofDrawGrid(200);
    }

//    ofNoFill(); // dan wordt alleen 't mesh getekend
    ofSetColor(ofColor::cornflowerBlue);
    ofDrawSphere(200, 100, 300, 50);

}

void ofApp::keyPressed(int key) {
    if (key == 'g') {
        drawGrid = !drawGrid;
    }

    if (key == ' ') {
        doRotate = !doRotate;
    }
}