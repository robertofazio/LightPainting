#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup()
{
    ofSetVerticalSync(true);
    ofSetFrameRate(120);
    ofEnableAntiAliasing();
    cam.setup(1280, 720);
    contourFinder.setMinAreaRadius(10);
    contourFinder.setMaxAreaRadius(150);
    //contourFinder.setInvert(true); // find black instead of white
    
    fboPainting.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA);
    fboPainting.begin();
    ofClear(255,255,255,127);
    fboPainting.end();
    
    gui.setup();
    gui.add(threshold.set("Threshold", 9, 0, 255));
    //gui.add(trackHs.set("Track Hue/Saturation", false));
    gui.add(debugBlog.set("View Blob", false));
    gui.add(drawCam.set("Draw Cam", true));
    gui.add(raggio.set("Radius", 10, 1, 250));
    gui.add(alpha.set("alpha", 127, 5, 255));
    gui.add(clear.set("Cancel", false));
    
    
    palette.setup();
    currColor = new ofColor();
    
}

void ofApp::update()
{
    cam.update();
    if(cam.isFrameNew())
    {
        contourFinder.setTargetColor(targetColor, trackHs ? TRACK_COLOR_HS : TRACK_COLOR_RGB);
        contourFinder.setThreshold(threshold);
        contourFinder.findContours(cam);
    }
    
    radiusPointer = raggio;
    
    if(palette.bClear || clear)
    {
        fboPainting.begin();
        ofClear(255,255,255,127);
        fboPainting.end();
        //cout << "Clear Screen" << endl;
    }

}

void ofApp::draw()
{
    if(drawCam)
        cam.draw(0, 0);
    
    fboPainting.draw(0,0);
    
    ofSetLineWidth(5);
    ofSetColor(255, 0, 0);
    
    palette.draw();
    if(contourFinder.size() >0)
    {
        ofVec2f v;
        v.set(contourFinder.getCentroid(0).x, contourFinder.getCentroid(0).y);
        palette.pointer = v;
        
        ofSetColor(palette.setColor(), alpha);
        ofDrawCircle(v.x, v.y, 0, radiusPointer);
        
        if(debugBlog)
            contourFinder.draw();
        
        fboPainting.begin();
        ofDrawCircle(contourFinder.getCentroid(0).x, contourFinder.getCentroid(0).y, radiusPointer);
        fboPainting.end();
    }

    gui.draw();
    
    ofTranslate(ofGetWidth() - 30, palette.radius -10);
    ofFill();
    ofSetColor(0);
    ofDrawRectangle(-3, -3, 32+6, 32+6);
    ofSetColor(targetColor);
    ofDrawRectangle(0, 0, 32, 32);
    
}

void ofApp::mousePressed(int x, int y, int button)
{
    targetColor = cam.getPixels().getColor(x, y);
}
