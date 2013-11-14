//
//  PlotEllipses.cpp
//  Defense
//
//  Created by Javier Villegas on 6/2/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

// Plot Ellipses from a list on a given rect

#include <iostream>
#include "defense.h"

void defense::PlotEllipses(vector<TheEllipse> ElliVec,ofRectangle RectLimits){
  TheEllipse CurrentEllipse(320,10,10,10,0,0);    
    glPushMatrix();
    ofTranslate(RectLimits.getCenter());
    ofScale(RectLimits.width/Nx, RectLimits.height/Ny);
    for (int k=0; k < ElliVec.size();k++){
         CurrentEllipse = ElliVec[k];
        ofSetColor(CurrentEllipse.TheGray,CurrentEllipse.TheGray,CurrentEllipse.TheGray);
        glPushMatrix();  
        ofTranslate(CurrentEllipse.x-Nx/2.0, CurrentEllipse.y-Ny/2.0);
        ofRotate(CurrentEllipse.angle);
        ofEllipse(0.0,0.0 , CurrentEllipse.a, CurrentEllipse.b);
         glPopMatrix();  
    }
    glPopMatrix(); 
}

void defense::PlotEllipNoFill(vector<TheEllipse> ElliVec,ofRectangle RectLimits){
    TheEllipse CurrentEllipse(320,10,10,10,0,0);    
    ofNoFill();
    ofSetLineWidth(1.0);
    glPushMatrix();
    ofTranslate(RectLimits.getCenter());
    ofScale(RectLimits.width/Nx, RectLimits.height/Ny);

    for (int k=0; k < ElliVec.size();k++){
        CurrentEllipse = ElliVec[k];
        
        glPushMatrix();  
        ofTranslate(CurrentEllipse.x-Nx/2.0, CurrentEllipse.y-Ny/2.0);
        ofRotate(CurrentEllipse.angle);
        ofEllipse(0.0,0.0 , CurrentEllipse.a, CurrentEllipse.b);
        glPopMatrix();  
    }
    glPopMatrix(); 
    ofFill();
}

void defense::PlotEllipPolligon(vector<TheEllipse> ElliVec,ofRectangle RectLimits){
    TheEllipse CurrentEllipse(320,10,10,10,0,0);    
    glPushMatrix();
    ofTranslate(RectLimits.getCenter());
    ofScale(RectLimits.width/Nx, RectLimits.height/Ny);
    int Nsides = (127-Slider1)*12/127 +4;
    for (int k=0; k < ElliVec.size();k++){
        CurrentEllipse = ElliVec[k];
        ofSetColor(CurrentEllipse.TheGray,CurrentEllipse.TheGray,CurrentEllipse.TheGray);
        glPushMatrix();  
        ofTranslate(CurrentEllipse.x-Nx/2.0, CurrentEllipse.y-Ny/2.0);
        ofRotate(CurrentEllipse.angle);
        
        glBegin(GL_POLYGON);
        for (int s =0; s<Nsides; s++) {
            glVertex2f(CurrentEllipse.a/2.0*cos(CV_PI/Nsides+s*2*CV_PI/Nsides),
                       CurrentEllipse.b/2.0*sin(CV_PI/Nsides+s*2*CV_PI/Nsides));
        }
        glEnd();
        glPopMatrix();  
    }
    glPopMatrix(); 
}

void defense::PlotEllipsesTexture(vector<TheEllipse> ElliVec,ofRectangle RectLimits){
    TheEllipse CurrentEllipse(320,10,10,10,0,0);   
    ofImage TheTextu;
    TheTextu.loadImage("Blocks/baggetteNew2.png");
    glPushMatrix();
    ofTranslate(RectLimits.getCenter());
    ofScale(RectLimits.width/Nx, RectLimits.height/Ny);
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    for (int k=0; k < ElliVec.size();k++){
        CurrentEllipse = ElliVec[k];
        ofSetColor(2*CurrentEllipse.TheGray,2*CurrentEllipse.TheGray,2*CurrentEllipse.TheGray);
        glPushMatrix();  
        ofTranslate(CurrentEllipse.x-Nx/2.0, CurrentEllipse.y-Ny/2.0);
        ofRotate(90+CurrentEllipse.angle);
        TheTextu.draw(-CurrentEllipse.b/2.0,-CurrentEllipse.a/2.0 , CurrentEllipse.b, CurrentEllipse.a);
        glPopMatrix();  
    }
    glPopMatrix(); 
    glDisable(GL_BLEND);
}

void defense::PlotEllipsesTextureNew(vector<TheEllipse> ElliVec,ofRectangle RectLimits){
    TheEllipse CurrentEllipse(320,10,10,10,0,0);   
    ofImage TheTextu;
    TheTextu.loadImage("Blocks/transparentFishBR.png");
    glPushMatrix();
    ofTranslate(RectLimits.getCenter());
    ofScale(RectLimits.width/Nx, RectLimits.height/Ny);
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    for (int k=0; k < ElliVec.size();k++){
        CurrentEllipse = ElliVec[k];
        ofSetColor(2*CurrentEllipse.TheGray,2*CurrentEllipse.TheGray,2*CurrentEllipse.TheGray);
        glPushMatrix();  
        ofTranslate(CurrentEllipse.x-Nx/2.0, CurrentEllipse.y-Ny/2.0);
        ofRotate(90+CurrentEllipse.angle);
        TheTextu.draw(-CurrentEllipse.b/2.0,-CurrentEllipse.a/2.0 , CurrentEllipse.b, CurrentEllipse.a);
        glPopMatrix();  
    }
    glPopMatrix(); 
     glDisable(GL_BLEND);
}



void defense::PlotEllipExternal(vector<TheEllipse> ElliVec,ofRectangle RectLimits,int AMode){
    TheEllipse CurrentEllipse(320,10,10,10,0,0);   
    
    if (AMode==0){
        glPushMatrix();
        ofTranslate(RectLimits.getCenter());
        ofScale(RectLimits.width/Nx, RectLimits.height/Ny);
        int Nsides = 128;
        for (int k=0; k < ElliVec.size();k++){
            CurrentEllipse = ElliVec[k];
            ofSetColor(CurrentEllipse.TheGray,CurrentEllipse.TheGray,CurrentEllipse.TheGray);
            glPushMatrix();  
            ofTranslate(CurrentEllipse.x-Nx/2.0, CurrentEllipse.y-Ny/2.0);
            ofRotate(CurrentEllipse.angle);
            glBegin(GL_POLYGON);
            for (int s =0; s<Nsides; s++) {
                glVertex2f(CurrentEllipse.a/2.0*cos(CV_PI/Nsides+s*2*CV_PI/Nsides)*(1+
                           5*CurrentEnergy*cos(s*2*CV_PI/8.0)),
                       CurrentEllipse.b/2.0*sin(CV_PI/Nsides+s*2*CV_PI/Nsides)*(1+
                          5*CurrentEnergy*cos(s*2*CV_PI/8.0)) );
            }
            glEnd();
            glPopMatrix();  
        }
        glPopMatrix(); 
    }
    
    
}
