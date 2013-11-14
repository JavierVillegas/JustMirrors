//
//  VideoNPR.cpp
//  Defense
//
//  Created by Javier Villegas on 6/4/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::VideoNPR(int VMode){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofImage RevIma;
    ofSetColor(0, 0, 0 );
    Fuentes[0].drawString("A/S on Videos (NPR)",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    
    ofSetColor(255,255,255 );
    ofxCvColorImage	TempColorImg;
    int TheWi;
    
    
    
    
    switch (VMode) {
            
            
        case 0:
        //    if (VideoIsPlaying){
                TempColorImg.allocate(Mov.width, Mov.height);
                ofSetHexColor(0xFFFFFF);
                TempColorImg.setFromPixels(Mov.getPixels(),Mov.width, Mov.height);
                ofPushMatrix();
                ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
                ofScale(.8, .8);
                TempColorImg.draw(-TempColorImg.width/2.0,-TempColorImg.height/2.0);
                
                ofPopMatrix();
                ofSetColor(0, 0, 0 );
                TheWi=Fuentes[3].stringWidth("Impressions of San Francisco,");
                Fuentes[3].drawString("Impressions of San Francisco,",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);
                TheWi=Fuentes[3].stringWidth("Peter Litwinowicz, SIGGRAPH'97");
                Fuentes[3].drawString("Peter Litwinowicz, SIGGRAPH'97",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .94*RectOut.height);            
     //       }
            
            break;           
        case 1:
    //        if (VideoIsPlaying){
                TempColorImg.allocate(Mov.width, Mov.height);
                ofSetHexColor(0xFFFFFF);
                TempColorImg.setFromPixels(Mov.getPixels(),Mov.width, Mov.height);
                ofPushMatrix();
                ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
                ofScale(.8, .8);
                TempColorImg.draw(-TempColorImg.width/2.0,-TempColorImg.height/2.0);
                
                ofPopMatrix();
                ofSetColor(0, 0, 0 );
                TheWi=Fuentes[3].stringWidth("AniPaint: Interactive Paintery Animation From Video,");
                Fuentes[3].drawString("AniPaint: Interactive Paintery Animation From Video,",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);
                TheWi=Fuentes[3].stringWidth("Peter O'Donovan, Aaron Hertzmann, 2012");
                Fuentes[3].drawString("Peter O'Donovan, Aaron Hertzmann, 2012",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .94*RectOut.height);            
       //     }
            
            break;    
        case 2:
     //       if (VideoIsPlaying){
                TempColorImg.allocate(Mov.width, Mov.height);
                ofSetHexColor(0xFFFFFF);
                TempColorImg.setFromPixels(Mov.getPixels(),Mov.width, Mov.height);
                ofPushMatrix();
                ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
                ofScale(.8, .8);
                TempColorImg.draw(-TempColorImg.width/2.0,-TempColorImg.height/2.0);
                
                ofPopMatrix();
                ofSetColor(0, 0, 0 );
                TheWi=Fuentes[3].stringWidth("Video Mosaics,");
                Fuentes[3].drawString("Video Mosaics,",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height); 
                TheWi=Fuentes[3].stringWidth("Klein, Grant, Finkelstein, Cohen, 2002");
                Fuentes[3].drawString("Klein, Grant, Finkelstein, Cohen, 2002",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .94*RectOut.height);
     //       }
            
            break; 
               
        default:
            break;
            
    }
    TempColorImg.clear(); 
}
