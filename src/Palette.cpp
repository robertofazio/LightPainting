//
//  Palette.cpp
//  ContoursTracking
//
//  Created by Roberto Fazio on 26/04/17.
//
//

#include "Palette.h"

Palette::Palette()
{
    pos.set(0, ofGetHeight() - 120);
    radius = 120;
    colors = new ofColor[MAX_COLS];
    pointer.set(0,0);
    actualCol = new ofColor(255,255,255,127);
}

void Palette::setup()
{
    for(int i = 0; i < MAX_COLS; i++)
    {
        pos.x = i * gap;
        //cout << pos.x << endl;
        
        colors[0].r = 255;
        colors[0].g = 0;
        colors[0].b = 0;
        colors[1].r = 255;
        colors[1].g = 255;
        colors[1].b = 0;
        colors[2].r = 255;
        colors[2].g = 100;
        colors[2].b = 200;
        colors[3].r = 127;
        colors[3].g = 127;
        colors[3].b = 255;
        colors[4].r = 0;
        colors[4].g = 0;
        colors[4].b = 255;
        colors[5].r = 255;
        colors[5].g = 0;
        colors[5].b = 127;
        
        colors[6].r = 0;
        colors[6].g = 0;
        colors[6].b = 0;
    
        position.push_back(pos);
    }
    
    bDrawing = false;
    bClear = false;
    
    font.load("GothamRoundedLight_21020.ttf", 10, true, true, true);
}


void Palette::update()
{
    
}

ofColor Palette::setColor()
{
    return *actualCol;
}

void Palette::draw()
{
    ofPushMatrix();
    
    for(int i = 0; i < MAX_COLS; i++)
    {
        ofSetColor(colors[i].r, colors[i].g, colors[i].b);
        ofDrawRectangle(position[i].x, position[i].y, radius, radius);
        
        if((pointer.x > position[i].x && pointer.x < position[i].x + radius) && (pointer.y > position[i].y && pointer.y < position[i].y + radius ))
        {
            bDrawing = true;
            *actualCol = colors[i];
            
            ofSetColor(255,255,255,127);
            ofDrawRectangle(position[i].x, position[i].y, radius, radius);
            
            if(i == MAX_COLS-1)
                bClear = true;
        }
        else
        {
            bDrawing = false;
            bClear = false;
        }
        ofSetColor(ofColor::white);
        font.drawString(ofToString(colors[i]), position[i].x, position[i].y + radius);
        ofSetColor(ofColor::black);
        ofDrawBitmapString("CLEAR", position[MAX_COLS-1].x, position[MAX_COLS-1].y);
        
    }
    
    ofPopMatrix();
}

bool Palette::onTrigger()
{
    return bDrawing;
    cout << bDrawing << endl;
}

