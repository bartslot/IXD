#include "ofApp.h"

void ofApp::setup() {
    x = ofRandom(0, ofGetWidth());
    y = ofRandom(0, ofGetHeight());

    speedX = ofRandom(-10, 10);
    speedY = ofRandom(-10, 10);

    radius = 40;
    color = ofColor::red;
}

void ofApp::update() {
    if (x < 0) {
        x = 0;
        speedX = -speedX;
    }

    if (x > ofGetWidth()) {
        x = ofGetWidth();
        speedX = -speedX;
    }
    if (y < 0) {
        y = 0;
        speedY = -speedY;
    }

    if (y > ofGetHeight()) {
        y = ofGetHeight();
        speedY = -speedY;
    }

    x += speedX;
    y += speedY;
}

void ofApp::draw() {
    ofSetColor(color);
    ofDrawCircle(x, y, radius);
}

void ofApp::keyPressed(int key) {

}
