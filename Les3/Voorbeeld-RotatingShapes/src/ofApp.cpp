#include "ofApp.h"

void ofApp::setup() {
    ofSetFrameRate(60);

    drawGrid = true;

    // zet de GUI op
    gui.setup();
    gui.add(rotateSpeedX.set("X", 0, 0, 9.0));     // slider voor X toevoegen
    gui.add(rotateSpeedY.set("Y", 0, 0, 9.0));     // slider voor Y toevoegen
    gui.add(rotateSpeedZ.set("Z", 0, 0, 9.0));     // slider voor Z toevoegen
    gui.add(drawGrid.set("Grid", false));          // toggle: teken grid
    gui.add(saveMatrix.set("save matrix", false)); // toggle: gebruik ofPushMatrix()/ofPopMatrix() per rotatie
}

void ofApp::update() {
    // neem de huidige rotatie waarden, en voeg daar de waardes uit de sliders aan toe
    rotationX += rotateSpeedX;
    rotationY += rotateSpeedY;
    rotationZ += rotateSpeedZ;
}

void ofApp::draw() {
    gui.draw();

    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);    // verplaats het 0-punt naar 't midden van 't scherm

    if (saveMatrix) ofPushMatrix();      // draai het grid om de x-as
    ofRotateX(rotationX);
    ofSetColor(255, 0, 0);
    ofDrawCircle(-300, 0, 130);
    if (saveMatrix) ofPopMatrix();

    if (saveMatrix) ofPushMatrix();
    ofRotateY(rotationY);               // draai het grid om de y-as
    ofSetColor(0, 255, 0);
    ofDrawCircle(0, 0, 130);
    if (saveMatrix) ofPopMatrix();

    if (saveMatrix) ofPushMatrix();
    ofRotateZ(rotationZ);               // draai het grid om de z-as
    ofSetColor(0, 0, 255);
    ofDrawCircle(300, 0, 130);
    if (saveMatrix) ofPopMatrix();

    // als het 'drawGrid' vlaggetje op 'true' staat, teken dan 't grid
    if (drawGrid) ofDrawGrid(200);
}

void ofApp::keyPressed(int key) {
    if (key == 'g') {          // als op de 'g' toets gedrukt wordt...
        drawGrid = !drawGrid;  // verander de boolean in de tegenovergestelde waarde: true->false, false->true
    } else if (key == 'r') {  // toets 'r': reset de rotatie
        rotationX = 0;
        rotationY = 0;
        rotationZ = 0;
    } else if (key == ' ') {  // spatiebalk: zet de rotatie stil
        rotateSpeedX = 0;
        rotateSpeedY = 0;
        rotateSpeedZ = 0;
    } else if (key == 'm') {   // 'm': gebruik ofPushMatrix()/ofPopMatrix() tussen de rotaties
        saveMatrix = !saveMatrix;
    }
}