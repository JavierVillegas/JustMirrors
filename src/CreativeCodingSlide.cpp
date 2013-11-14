//
//  CreativeCodingSlide.cpp
//  Defense
//
//  Created by Javier Villegas on 6/4/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::CreativeCodingEraSlide(int CMode){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofImage RevIma;
    ofSetColor(0, 0, 0 );
    Fuentes[0].drawString("A/S with Creative Coding Frameworks",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    
    ofSetColor(255,255,255 );
    ofxCvColorImage	TempColorImg;
    int TheWi;
    switch (CMode) {
            
        case 0:
            
            RevIma.loadImage("review/creative2.png");
            RevIma.draw((RectOut.getCenter()).x - 3.5*RectOut.width/8.0 ,
                        (RectOut.getCenter()).y- (1.2)*RectOut.height/4.0,
                        1.5*RectOut.width/4.0,
                        (1.2)*RectOut.height/2.0);
            TheWi=Fuentes[3].stringWidth("ASCII Video, Processing Demo,");
            ofSetColor(0, 0, 0 );
            Fuentes[3].drawString("ASCII Video, Processing Demo,",
                                  (RectOut.getCenter()).x- RectOut.width/4.0-TheWi/2.0
                                  ,RectOut.y + .88*RectOut.height);  
            TheWi=Fuentes[3].stringWidth("Ben Fry, 2004-2011");
            ofSetColor(0, 0, 0 );
            Fuentes[3].drawString("Ben Fry, 2004-2011",
                                  (RectOut.getCenter()).x- RectOut.width/4.0-TheWi/2.0
                                  ,RectOut.y + .94*RectOut.height);  
            
            
            ofSetColor(255,255,255);
            RevIma.loadImage("review/creative1.png");
            RevIma.draw((RectOut.getCenter()).x + RectOut.width/8.0 - .5*RectOut.width/8.0,
                        (RectOut.getCenter()).y- (1.2)*RectOut.height/4.0,
                        1.5*RectOut.width/4.0,
                        (1.2)*RectOut.height/2.0);
            
            ofSetColor(0, 0, 0 );
            TheWi=Fuentes[3].stringWidth("Mirror, Processing Demo,");
            Fuentes[3].drawString("Mirror, Processing Demo,",
                                  (RectOut.getCenter()).x+RectOut.width/4.0-TheWi/2.0,
                                  RectOut.y + .88*RectOut.height);
            
            TheWi=Fuentes[3].stringWidth("Daniel Shiffman");
            Fuentes[3].drawString("Daniel Shiffman",
                                  (RectOut.getCenter()).x+RectOut.width/4.0-TheWi/2.0,
                                  RectOut.y + .94*RectOut.height);       
            
            break;
        case 1:
            
            
            RevIma.loadImage("review/GenerativeBook.png");
            RevIma.draw((RectOut.getCenter()).x - 3*RectOut.width/8.0 ,
                        (RectOut.getCenter()).y- (1.2)*RectOut.height/4.0,
                        RectOut.width/4.0,(1.2)*RectOut.height/2.0);
            TheWi=Fuentes[3].stringWidth("Image from \"Generative Gestaltung,\"");
            ofSetColor(0, 0, 0 );
            Fuentes[3].drawString("Image from \"Generative Gestaltung,\"",
                                  (RectOut.getCenter()).x- RectOut.width/4.0-TheWi/2.0
                                  ,RectOut.y + .88*RectOut.height);  
            TheWi=Fuentes[3].stringWidth("2009");
            ofSetColor(0, 0, 0 );
            Fuentes[3].drawString("2009",
                                  (RectOut.getCenter()).x- RectOut.width/4.0-TheWi/2.0
                                  ,RectOut.y + .94*RectOut.height);  
            
            
            ofSetColor(255,255,255);
            RevIma.loadImage("review/RobertHodgin.jpg");
            RevIma.draw((RectOut.getCenter()).x + RectOut.width/8.0 - .5*RectOut.width/8.0,
                        (RectOut.getCenter()).y- (1.2)*RectOut.height/4.0,
                        (1.5)*RectOut.width/4.0,
                        (1.2)*RectOut.height/2.0);
            
            ofSetColor(0, 0, 0 );
            TheWi=Fuentes[3].stringWidth("Body Dysmorphia,");
            Fuentes[3].drawString("Body Dysmorphia,",
                                  (RectOut.getCenter()).x+RectOut.width/4.0-TheWi/2.0,
                                  RectOut.y + .88*RectOut.height);
            TheWi=Fuentes[3].stringWidth("Robert Hodgin, 2011");
            Fuentes[3].drawString("Robert Hodgin, 2011",
                                  (RectOut.getCenter()).x+RectOut.width/4.0-TheWi/2.0,
                                  RectOut.y + .94*RectOut.height);           
            break;      

        default:
            break;
            
    }
}