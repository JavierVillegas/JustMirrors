//
//  CrossSynthVarias.cpp
//  Defense
//
//  Created by Javier Villegas on 6/7/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::AmbiguousSlide(){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofImage RevIma;
    float TheWi;
    ofSetColor(0, 0, 0 );
    Fuentes[0].drawString("Ambiguous Images",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    ofSetColor(255,255,255);
    RevIma.loadImage("Cross/Arcimboldovertemnus.jpg");
    RevIma.draw((RectOut.getCenter()).x - 2*RectOut.width/8.0 -(1)*RectOut.width/8.0,
                (RectOut.getCenter()).y- (1.2)*RectOut.height/4.0,
                (1)*RectOut.width/4.0,
                (1.2)*RectOut.height/2.0);
    TheWi=Fuentes[3].stringWidth("Portrait of Rudolph II,");
    ofSetColor(0, 0, 0 );
    Fuentes[3].drawString("Portrait of Rudolph II,",
                          (RectOut.getCenter()).x- RectOut.width/4.0-TheWi/2.0
                          ,RectOut.y + .88*RectOut.height);  
    TheWi=Fuentes[3].stringWidth("Arcimboldo, 1591");
    ofSetColor(0, 0, 0 );
    Fuentes[3].drawString("Arcimboldo, 1591",
                          (RectOut.getCenter()).x- RectOut.width/4.0-TheWi/2.0
                          ,RectOut.y + .94*RectOut.height);  
    
    
    ofSetColor(255,255,255);
    RevIma.loadImage("Cross/CharlesGilbertAllisVanity1920.jpg");
    RevIma.draw((RectOut.getCenter()).x + RectOut.width/8.0,
                (RectOut.getCenter()).y- (1.2)*RectOut.height/4.0,
                RectOut.width/4.0,(1.2)*RectOut.height/2.0);
    
    ofSetColor(0, 0, 0 );
    TheWi=Fuentes[3].stringWidth("All is vanity, Charles E. Gilbert, 1920");
    Fuentes[3].drawString("All is vanity, Charles E. Gilbert, 1920",
                          (RectOut.getCenter()).x+RectOut.width/4.0-TheWi/2.0,
                          RectOut.y + .88*RectOut.height);
    
}

void defense::MixingImages(int MMode){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    float TheWi;
    ofSetColor(0, 0, 0 );
    
    ofRectangle RectLimits;
//    RectLimits.x =(RectOut.getCenter()).x - 1.5*RectOut.width/4.0;
//    RectLimits.y=(RectOut.getCenter()).y - 1.3*RectOut.height/4.0;
//    RectLimits.width=1.5*RectOut.width/2.0;
//    RectLimits.height=1.5*RectOut.height/2.0;

    RectLimits.x =0.0;
    RectLimits.y=0.0;
    RectLimits.width=.98*ScreenX;
    RectLimits.height=.98*ScreenY;
    switch (MMode) {
            
        case 0: // size
        {
      
            
            float tempoval;
            ofSetColor(255,255,255);
            glPushMatrix();
            
            ofTranslate(RectLimits.x, RectLimits.y);
            ofScale(RectLimits.width/Nx,RectLimits.height/Ny);
            
            for (int i=0; i <Destino->height; i++) {
                for (int j=0; j<Destino->width; j++) {
                    
                    tempoval = (float)((uchar *)(Destino->imageData + i*Destino->widthStep))[j*Destino->nChannels + 0];
                    float ScalValue = (.2)*(1-tempoval/255.0);
                    glPushMatrix();  
                    ofTranslate(j*Nx/NumOfSquares.x+(Nx/NumOfSquares.x)/2.0, 
                                i*Ny/NumOfSquares.y+(Ny/NumOfSquares.y)/2.0);
//                    ofRect(-.5*Nx/NumOfSquares.x*ScalValue, -.5*Ny/NumOfSquares.y*ScalValue,
//                           ScalValue*Nx/NumOfSquares.x, ScalValue*Ny/NumOfSquares.y); 
                    ofScale(.2*ScalValue, .2*ScalValue);
                     colorImg.draw(0,0);
                    //          ofSetColor(tempoval,tempoval,tempoval);
                    //            ofRect(j*Nx/NumOfSquares.x, i*Ny/NumOfSquares.y, Nx/NumOfSquares.x, Ny/NumOfSquares.y);
                    glPopMatrix(); 
                    
                }
            }
            
            glPopMatrix();
        }
            
            break;         
         
        case 1: // angle
        {
            Fuentes[3].drawString("Mixing images: Angle",
                                  RectOut.x,RectOut.y + RectOut.height*.1);
            
            float tempoval;
            ofSetColor(255,255,255);
            glPushMatrix();
            
            ofTranslate(RectLimits.x, RectLimits.y);
            ofScale(RectLimits.width/Nx,RectLimits.height/Ny);
            
            for (int i=0; i <Destino->height; i++) {
                for (int j=0; j<Destino->width; j++) {
                    
                    tempoval = (float)((uchar *)(Destino->imageData + i*Destino->widthStep))[j*Destino->nChannels + 0];


                    glPushMatrix();  
                    ofTranslate(j*Nx/NumOfSquares.x+(Nx/NumOfSquares.x)/2.0, 
                                i*Ny/NumOfSquares.y+(Ny/NumOfSquares.y)/2.0);
                    //                    ofRect(-.5*Nx/NumOfSquares.x*ScalValue, -.5*Ny/NumOfSquares.y*ScalValue,
                    //                           ScalValue*Nx/NumOfSquares.x, ScalValue*Ny/NumOfSquares.y); 
                    ofRotate(tempoval/255.0*90, 0, 0, 1);
                    ofScale(NumOfSquares.x/Nx, NumOfSquares.y/Ny);
                   
                    colorImg.draw(-colorImg.width/2.0,-colorImg.height/2.0);
                    //          ofSetColor(tempoval,tempoval,tempoval);
                    //            ofRect(j*Nx/NumOfSquares.x, i*Ny/NumOfSquares.y, Nx/NumOfSquares.x, Ny/NumOfSquares.y);
                    glPopMatrix(); 
                    
                }
            }
            
            glPopMatrix();
            
        }   
            break;             
            
            
        default:
            break;
    }
    
}


void defense::BaggeteExample(){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    float TheWi;
    ofSetColor(0, 0, 0 );
//    Fuentes[1].drawString("Ambiguous Sequences",
//                          RectOut.x,RectOut.y + RectOut.height*.05);
    Fuentes[1].drawString("Double Meaning Sequences",
                          RectOut.x,RectOut.y + RectOut.height*.05);

    
    Fuentes[3].drawString("Baguettes substituting ellipses",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    ofRectangle RectLimits;
    RectLimits.x =(RectOut.getCenter()).x - 1.5*RectOut.width/4.0;
    RectLimits.y=(RectOut.getCenter()).y - 1.3*RectOut.height/4.0;
    RectLimits.width=1.5*RectOut.width/2.0;
    RectLimits.height=1.5*RectOut.height/2.0;
    ofSetColor(255, 255, 255);
    PlotEllipsesTexture(TheCoherentEllipses,RectLimits);

}


void defense::Capture3styles(){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    float TheWi;
//    ofSetColor(0, 0, 0 );
//    Fuentes[3].drawString("Substitution of ellipses",
//                          RectOut.x,RectOut.y + RectOut.height*.1);
    ofRectangle RectLimits;
    RectLimits.x =(RectOut.getCenter()).x - 2*RectOut.width/4.0;
    RectLimits.y=(RectOut.getCenter()).y - 2.5*RectOut.height/4.0;
    RectLimits.width=2.2*RectOut.width/2.0;
    RectLimits.height=2.2*RectOut.height/2.0;
    ofSetColor(255, 255, 255);
    ofClear(255, 255, 255);
    PlotEllipsesTexture(TheCoherentEllipses,RectLimits);
//    if (booleanforCapture==true){
//       
//    //    ofSaveScreen("LasEllipses.png");
//        ofClear(255, 255, 255);
//        PlotEllipsesTexture(TheCoherentEllipses,RectLimits);
//     //   ofSaveScreen("LosPanes.png");
//        ofClear(255, 255, 255);
//        PlotEllipsesTextureNew(TheCoherentEllipses,RectLimits);
//      //  ofSaveScreen("Lospezcados.png");
//        booleanforCapture = false;
//    }
    
}

void defense::TemplateMatching(){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofImage RevIma;
    float TheWi;
    ofSetColor(0, 0, 0 );
    Fuentes[3].drawString("A template matching algorithm",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    ofSetColor(255,255,255);
    RevIma.loadImage("Cross/templatematching.png");
    RevIma.draw((RectOut.getCenter()).x - 1.5*RectOut.width/4.0,
                (RectOut.getCenter()).y- (1.5)*RectOut.height/4.0,
                (1.5)*RectOut.width/2.0,
                (1.6)*RectOut.height/2.0);
          
}
void defense::StatesSlide(){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofImage RevIma;
    float TheWi;
    ofSetColor(0, 0, 0 );
    Fuentes[3].drawString("State transitions of the synthesis elements",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    ofSetColor(255,255,255);
    RevIma.loadImage("Cross/MarkovRB.png");
    RevIma.draw((RectOut.getCenter()).x - 1.3*RectOut.width/4.0,
                (RectOut.getCenter()).y- (1.5)*RectOut.height/4.0,
                (1.3)*RectOut.width/2.0,
                (1.6)*RectOut.height/2.0);
    
}



