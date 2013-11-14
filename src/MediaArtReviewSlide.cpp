//
//  MediaArtReviewSlide.cpp
//  Defense
//
//  Created by Javier Villegas on 6/4/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>

#include "defense.h"

void defense::MediaArtReviewSlide(int MMode){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofImage RevIma;
    ofSetColor(0, 0, 0 );
    Fuentes[0].drawString("A/S in Interactive Media Art",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    
    ofSetColor(255,255,255 );
    ofxCvColorImage	TempColorImg;
    int TheWi;
    switch (MMode) {
            
        case 0:
           
            RevIma.loadImage("review/woodenmirrormuseum.jpg");
            ofPushMatrix();
            ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
            ofScale(.4 ,.4);
            RevIma.draw(-RevIma.width/2.0,-RevIma.height/2.0);
            ofPopMatrix();
            ofSetColor(0, 0, 0 );
            TheWi=Fuentes[3].stringWidth("Wooden Mirror, Daniel Rozin, 1999");
            Fuentes[3].drawString("Wooden Mirror, Daniel Rozin, 1999",
                                  (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);

            
            break;
        case 1:
            
            RevIma.loadImage("review/JimCampbell.jpg");
            ofPushMatrix();
            ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
            ofScale(.8, .8);
            RevIma.draw(-RevIma.width/2.0,-RevIma.height/2.0);
            ofPopMatrix();
            ofSetColor(0, 0, 0 );
            TheWi=Fuentes[3].stringWidth("Low Resolution Works: Running Falling Series:");
            Fuentes[3].drawString("Low Resolution Works: Running Falling Series:",
                                  (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);
            
            TheWi=Fuentes[3].stringWidth("Ambiguous Icon 5 Running Falling, Jim Campbell, 2000" );
            Fuentes[3].drawString("Ambiguous Icon 5 Running Falling, Jim Campbell, 2000",
                                  (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .94*RectOut.height);                            
                                        
            
            break;      
        case 2:
            
            RevIma.loadImage("review/3rd_person_05.jpg");
            ofPushMatrix();
            ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
            ofScale(.9, .9);
            RevIma.draw(-RevIma.width/2.0,-RevIma.height/2.0);
            ofPopMatrix();
            ofSetColor(0, 0, 0 );
            TheWi=Fuentes[3].stringWidth("Third Person, Rafael Lozano-Hemmer, 2006");
            Fuentes[3].drawString("Third Person, Rafael Lozano-Hemmer, 2006",
                                  (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);
            
                               
            
            
            break;  
        case 3:
            
            RevIma.loadImage("review/ScanProcessor.png");
            ofPushMatrix();
            ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
            ofScale(.7, .7);
            RevIma.draw(-RevIma.width/2.0,-RevIma.height/2.0);
            ofPopMatrix();
            ofSetColor(0, 0, 0 );
            TheWi=Fuentes[3].stringWidth("Scan Processor Studies, Vasulka & ORelly, 1970 & 2009");
            Fuentes[3].drawString("Scan Processor Studies, Vasulka & ORelly, 1970 & 2009",
                                  (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);
            
            
            
            
            break;  
            
        default:
            break;
            
    }
}