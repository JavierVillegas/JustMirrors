//
//  DisTransGradient.cpp
//  Defense
//
//  Created by Javier Villegas on 6/6/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>

#include "defense.h"
void defense::DisTrans(int DTMode){
    
    ofxCvGrayscaleImage ForTheBW;
    ofxCvColorImage ForDistance;
    
    ForTheBW.allocate(Nx, Ny);
    ForDistance.allocate(Nx, Ny);
    
    IplImage * TheBW;
    IplImage * TheDistanceRGB;
    IplImage * TheDistance32F1;
    IplImage * TheDistance32F2;
    
    TheBW = cvCreateImage(cvSize(Nx, Ny),IPL_DEPTH_8U,1); 
    TheDistanceRGB = cvCreateImage(cvSize(Nx, Ny),IPL_DEPTH_8U,3);
    TheDistance32F1 =cvCreateImage( cvSize(Nx,Ny),IPL_DEPTH_32F,1);
    TheDistance32F2 =cvCreateImage( cvSize(Nx,Ny),IPL_DEPTH_32F,1);
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0 );
    Fuentes[1].drawString("Gradient using the distance transform",
                          RectOut.x,RectOut.y + RectOut.height*.1);

    
    cvThreshold(TheInputGray, TheBW, 2*Slider1, 255, CV_THRESH_BINARY);
    ForTheBW = TheBW;
    
    ofSetColor(255, 255, 255);
    
    if((DTMode==0)||(DTMode==2)){
    ForTheBW.draw(RectOut.getCenter().x-3.5*RectOut.width/8.0, 
                  RectOut.getCenter().y-RectOut.height/4.0,
                 (1.5)*RectOut.width/4.0,RectOut.height/2.0);
    }
    
    cvDistTransform(TheBW,TheDistance32F1);
    cvNot(TheBW, TheBW);
    if(DTMode==1){
        ForTheBW = TheBW;
        ForTheBW.draw(RectOut.getCenter().x-3.5*RectOut.width/8.0, 
                      RectOut.getCenter().y-RectOut.height/4.0,
                      1.5*RectOut.width/4.0,RectOut.height/2.0);
    } 
    
    
    cvDistTransform(TheBW,TheDistance32F2);
    
    if (DTMode==0) {
        cvConvertScale(TheDistance32F1, TheBW, 0.25,100); 
    }
    else if (DTMode==1){
       cvConvertScale(TheDistance32F2, TheBW, 0.5,100);  
    }
    else if (DTMode==2){
        cvSub(TheDistance32F1, TheDistance32F2, TheDistance32F1);
        cvConvertScale(TheDistance32F1, TheBW, 0.25,100);  
    }  
    
    PseudoColor(TheBW,TheDistanceRGB);
    
    
    ForDistance = TheDistanceRGB;
    ForDistance.draw(RectOut.getCenter().x+.5*RectOut.width/8.0, 
                  RectOut.getCenter().y-RectOut.height/4.0,
                  1.5*RectOut.width/4.0,RectOut.height/2.0);
    
    
    
    cvReleaseImage(&TheBW);
    cvReleaseImage(&TheDistanceRGB);
    cvReleaseImage(&TheDistance32F1);
     cvReleaseImage(&TheDistance32F2);

}