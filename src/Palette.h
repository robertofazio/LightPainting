//
//  Palette.hpp
//  ContoursTracking
//
//  Created by Roberto Fazio on 26/04/17.
//
//
#pragma once

#include "ofMain.h"

#define MAX_COLS 7

class Palette
{
public:
    
    Palette();
    void setup();
    void update();
    void draw();
    
    ofColor setColor();
    
    ofVec2f pos;
    float radius;
    int gap = 120;
    ofColor *colors;
    vector<ofVec2f> position;
    ofVec2f pointer;
    
    bool bDrawing;
    bool onTrigger();
    bool bClear;
    
    ofColor *actualCol;
    
    ofTrueTypeFont font;

};




