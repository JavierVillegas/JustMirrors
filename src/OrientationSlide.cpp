//
//  OrientationSlide.cpp
//  Defense
//
//  Created by Javier Villegas on 6/5/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>

#include "defense.h"
void defense::Orientation(){
    
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0 );
    ofRectangle RectLimits;
    
//    RectLimits.x =(RectOut.getCenter()).x - RectOut.width/4.0;
//    RectLimits.y=(RectOut.getCenter()).y - RectOut.height/4.0;
//    RectLimits.width=RectOut.width/2.0;
//    RectLimits.height=RectOut.height/2.0;

    RectLimits.x =0.0;
    RectLimits.y=0.0;
    RectLimits.width=ScreenX;
    RectLimits.height=ScreenY;
    
    float tempoval;
    ofSetColor(0, 0, 0);
    glPushMatrix();
    ofSetLineWidth(4);
    ofTranslate(RectLimits.x, RectLimits.y);
    ofScale(RectLimits.width/Nx,RectLimits.height/Ny);
    
    for (int i=0; i <Destino->height; i++) {
        for (int j=0; j<Destino->width; j++) {
            
            tempoval = (float)((uchar *)(Destino->imageData + i*Destino->widthStep))[j*Destino->nChannels + 0];
            float lineLenght = (4*Slider1/127.0)*sqrt(Nx/NumOfSquares.x*Nx/NumOfSquares.x +Ny/NumOfSquares.y*Ny/NumOfSquares.y);
            glPushMatrix();  
            ofTranslate(j*Nx/NumOfSquares.x+(Nx/NumOfSquares.x)/2.0, 
                        i*Ny/NumOfSquares.y+(Ny/NumOfSquares.y)/2.0);
            ofScale(.05*lineLenght, .05*lineLenght);
            ofRotate(180*(255-tempoval)/255.0);
                 ofLine(-lineLenght/2.0, 0, lineLenght/2.0, 0);
            
            //grayImage.draw(-.5*Nx/NumOfSquares.x, -.5*Ny/NumOfSquares.y,Nx/NumOfSquares.x, Ny/NumOfSquares.y);
            //            ofRect(-.5*Nx/NumOfSquares.x, -.5*Ny/NumOfSquares.y, .9*Nx/NumOfSquares.x, .9*Ny/NumOfSquares.y);  
            //          ofSetColor(tempoval,tempoval,tempoval);
            //            ofRect(j*Nx/NumOfSquares.x, i*Ny/NumOfSquares.y, Nx/NumOfSquares.x, Ny/NumOfSquares.y);
   
            glPopMatrix(); 
            
        }
    }
             ofSetLineWidth(1);
    glPopMatrix();
    
}