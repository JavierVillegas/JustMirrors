//
//  DithPointList.cpp
//  Defense
//
//  Created by Javier Villegas on 6/5/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"



void defense::DithPointList(){

    int oldPx = 0;
    int newPx = 0;
    int qError = 0;
    
    int threshold = 127;
    
    int r1, r2,  bl1, bc1, br1, bc2;
    float Alpha = 0.4;
       

        PointsList.clear();

    Alpha = Slider4/127.0;
    float Imin = 0;
    Imin = 2*Slider2;
    float Imax = 255;
    
    Imax = 2*Slider3;
    if (Imax <Imin) {
        Imin=Imax-1;
    }
    
    for (int i=0; i <Destino->height; i++) {
        
        for (int j=0; j<Destino->width; j++) {
            
            
            
            oldPx = ((uchar *)(Destino->imageData + i*Destino->widthStep))[j];
            
            //            oldPx = (uchar)(255*(Beta + (1-Beta )*pow((float)(oldPx/255.0),(float)Alpha)));
            
            oldPx = (uchar)(Imin + (Imax-Imin)*powf(((float)oldPx/255.0),(float)Alpha));
            
            
            
            ((uchar *)(Destino->imageData + i*Destino->widthStep))[j] = oldPx;
            
            
            
        } // for width
        
    } // for height
    
    

    for (int i=0; i <Destino->height-2; i++) {
        for (int j=1; j<Destino->width-2; j++) {
            
            oldPx = ((uchar *)(Destino->imageData + i*Destino->widthStep))[j*Destino->nChannels + 0];
//            oldPx = (uchar)(255*(Beta + (1-Beta )*powf((float)(oldPx/255.0),(float)Alpha)));
            newPx = oldPx < threshold ? Imin : Imax;
            //  dst[i*w+j] = newPx;
            qError = oldPx - newPx;
            
            
            r1  = MIN(((uchar *)(Destino->imageData + i*Destino->widthStep))[(j+1)*Destino->nChannels + 0]
                      + (int)(.125f * qError), 255);
            r2  = MIN(((uchar *)(Destino->imageData + i*Destino->widthStep))[(j+2)*Destino->nChannels + 0] 
                      + (int)(.125f * qError), 255);
            bl1 = MIN(((uchar *)(Destino->imageData + (i+1)*Destino->widthStep))[(j-1)*Destino->nChannels + 0]
                      + (int)(.125f * qError), 255);
            bc1 = MIN(((uchar *)(Destino->imageData + (i+1)*Destino->widthStep))[j*Destino->nChannels + 0]
                      + (int)(.125f * qError), 255); 
            br1 = MIN(((uchar *)(Destino->imageData + (i+1)*Destino->widthStep))[(j+1)*Destino->nChannels + 0]
                      + (int)(.125f * qError), 255);
            bc2 = MIN(((uchar *)(Destino->imageData + (i+2)*Destino->widthStep))[j*Destino->nChannels + 0]   
                      + (int)(.125f * qError), 255);  
            
            ((uchar *)(Destino->imageData + i*Destino->widthStep))[(j+1)*Destino->nChannels + 0]     = MAX(r1 , 0);
            ((uchar *)(Destino->imageData + (i+1)*Destino->widthStep))[(j-1)*Destino->nChannels + 0] = MAX(bl1, 0);
            ((uchar *)(Destino->imageData + (i+1)*Destino->widthStep))[j*Destino->nChannels + 0]   = MAX(bc1, 0);
            ((uchar *)(Destino->imageData + (i+1)*Destino->widthStep))[(j+1)*Destino->nChannels + 0] = MAX(br1, 0);
            ((uchar *)(Destino->imageData + (i+2)*Destino->widthStep))[j*Destino->nChannels + 0]   = MAX(bc2, 0);            
            
            
            if (newPx==Imin){
                PointsList.push_back(ofVec2f(j*Nx/NumOfSquares.x+(Nx/NumOfSquares.x)/2.0, i*Ny/NumOfSquares.y+(Ny/NumOfSquares.y)/2.0));
            }//  end if newPx ==0
        } // for width
    } // for height
    
}