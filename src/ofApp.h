#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"
#include "Palette.h"

class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    
    ofVideoGrabber cam;
    ofxCv::ContourFinder contourFinder;
    ofColor targetColor;
    
    ofxPanel gui;
    ofParameter<float> threshold;
    ofParameter<bool> trackHs;
    ofParameter<bool> debugBlog;
    ofParameter<bool> drawCam;
    ofParameter<float> raggio;
    ofParameter<bool> clear;
    ofParameter<float> alpha;
    
    float radiusPointer;
    
    Palette palette;
    ofColor *currColor;
    ofFbo fboPainting;
    
    
    
};
