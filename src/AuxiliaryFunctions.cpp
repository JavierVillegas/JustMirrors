//
//  AuxiliaryFunctions.cpp
//  Defense
//
//  Created by Javier Villegas on 5/31/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void quadraticBezierVertex(float cpx, float cpy, float x, float y, float prevX, float prevY) {  
    float cp1x = prevX + 2.0/3.0*(cpx - prevX);  
    float cp1y = prevY + 2.0/3.0*(cpy - prevY);  
    float cp2x = cp1x + (x - prevX)/3.0;  
    float cp2y = cp1y + (y - prevY)/3.0;  
    
    // finally call cubic Bezier curve function  
    ofBezierVertex(cp1x, cp1y, cp2x, cp2y, x, y);  
}; 

void defense::roundedRect(float x, float y, float w, float h, float r) {  
    ofBeginShape();  
    ofVertex(x+r, y);  
    ofVertex(x+w-r, y);  
    quadraticBezierVertex(x+w, y, x+w, y+r, x+w-r, y);  
    ofVertex(x+w, y+h-r);  
    quadraticBezierVertex(x+w, y+h, x+w-r, y+h, x+w, y+h-r);  
    ofVertex(x+r, y+h);  
    quadraticBezierVertex(x, y+h, x, y+h-r, x+r, y+h);  
    ofVertex(x, y+r);  
    quadraticBezierVertex(x, y, x+r, y, x, y+r);  
    ofEndShape();  
} 

void defense::PseudoColor(IplImage* GrayInput,IplImage *TheOutput){
    
    ofImage ParaLeer;
    ofxCvColorImage ParaCopiar;
    IplImage * TheColormap;
    IplImage * TempIn;
    
    ParaLeer.loadImage("Introduction/jethRB.tif");
    ParaCopiar.allocate(ParaLeer.width,ParaLeer.height);
    ParaCopiar.setFromPixels(ParaLeer.getPixels(),ParaLeer.width,ParaLeer.height);
    //TheColormap = cvCreateImage( cvSize(256,1),IPL_DEPTH_8U, 3);
    TempIn = cvCreateImage(cvGetSize(GrayInput), IPL_DEPTH_8U, 3);
    TheColormap = ParaCopiar.getCvImage();
    //cvSet(TheColormap,CV_RGB(200, 0, 0));
    cvCvtColor(GrayInput,TempIn,CV_GRAY2BGR);
    cvLUT( TempIn, TheOutput,TheColormap);
    ParaLeer.clear();
    ParaCopiar.clear();
   // if(TheColormap!=NULL) {cvReleaseImage(&TheColormap);}
   if(TempIn!=NULL) {cvReleaseImage(&TempIn);}

    
}

