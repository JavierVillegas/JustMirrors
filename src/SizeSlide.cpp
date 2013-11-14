//
//  SizeSlide.cpp
//  Defense
//
//  Created by Javier Villegas on 6/5/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::SizeSlide(){

       ofRectangle RectOut;
        RectOut = OneBigRect();
        ofSetColor(0, 0, 0 );
        Fuentes[0].drawString("Size",
                              RectOut.x,RectOut.y + RectOut.height*.1);
 
        ofRectangle RectLimits;
        RectLimits.x =(RectOut.getCenter()).x - RectOut.width/4.0;
        RectLimits.y=(RectOut.getCenter()).y - RectOut.height/4.0;
        RectLimits.width=RectOut.width/2.0;
        RectLimits.height=RectOut.height/2.0;

        
    float tempoval;
    glPushMatrix();
    
    ofTranslate(RectLimits.x, RectLimits.y);
    ofScale(RectLimits.width/Nx,RectLimits.height/Ny);
    
    for (int i=0; i <Destino->height; i++) {
        for (int j=0; j<Destino->width; j++) {
            
            tempoval = (float)((uchar *)(Destino->imageData + i*Destino->widthStep))[j*Destino->nChannels + 0];
            float ScalValue = (Slider1/127.0)*(1-tempoval/255.0);
            glPushMatrix();  
            ofTranslate(j*Nx/NumOfSquares.x+(Nx/NumOfSquares.x)/2.0, 
                        i*Ny/NumOfSquares.y+(Ny/NumOfSquares.y)/2.0);
                        ofRect(-.5*Nx/NumOfSquares.x*ScalValue, -.5*Ny/NumOfSquares.y*ScalValue,
                               ScalValue*Nx/NumOfSquares.x, ScalValue*Ny/NumOfSquares.y); 
            //ofScale(.2*ScalValue, .2*ScalValue);
           // grayImage.draw(0,0);
            //          ofSetColor(tempoval,tempoval,tempoval);
            //            ofRect(j*Nx/NumOfSquares.x, i*Ny/NumOfSquares.y, Nx/NumOfSquares.x, Ny/NumOfSquares.y);
            glPopMatrix(); 
            
        }
    }
    
    glPopMatrix();
    
}