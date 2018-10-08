#include "ofApp.h"

void ofApp::setup() {
    ofBackground(ofColor::black);

    gui.setup();
    gui.add(drawGrid.set("Grid", false));
    gui.add(useLight.set("Light", true));

    light.setDirectional();
    light.setDiffuseColor(ofColor::white);
    light.enable();
}

void ofApp::update() {
}

void ofApp::draw() {

    ofEnableDepthTest();

    cam.setVFlip(true);
    cam.begin();

    if (useLight) {
        ofEnableLighting();
    } else {
        ofDisableLighting();
    }

    ofSetColor(ofColor::yellow);
    ofDrawSphere(0, 0, 0, 100);

    ofSetColor(ofColor::blue);
    ofDrawSphere(200, 0, 0, 50);

    if (drawGrid) ofDrawGrid(200);

    cam.end();
    ofDisableDepthTest();

    if (drawGui) {
        ofDisableLighting();
        gui.draw();
    }
}

void ofApp::keyPressed(int key) {
    if (key == 'l') useLight = !useLight;
    if (key == 'g') drawGrid = !drawGrid;
    if (key == ' ') drawGui = !drawGui;
}