//
//  ImageReviewSlides.cpp
//  Defense
//
//  Created by Javier Villegas on 6/3/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::ImageReviewSlides(int IMode){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofImage RevIma;
    ofSetColor(0, 0, 0 );
    Fuentes[0].drawString("A/S on Images",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    
    ofSetColor(255,255,255 );
    int TheWi;
    switch (IMode) {
            
        case 0: // keneth kcnowlton
             RevIma.loadImage("review/knowlton.png");
            ofPushMatrix();
            ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
            ofScale(.9, .9);
            RevIma.draw(-RevIma.width/2.0,-RevIma.height/2.0);
            ofPopMatrix();
            ofSetColor(0, 0, 0 );
            TheWi=Fuentes[3].stringWidth("Studies on Perception I, Kenneth Knowlton 1966");
            Fuentes[3].drawString("Studies on Perception I, Kenneth Knowlton 1966",
                                  (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);
            
            
            break;
        case 1: // csuri CGT

          
            
            RevIma.loadImage("review/csuri_sinecurveman.jpg");
            RevIma.draw((RectOut.getCenter()).x - 2*RectOut.width/8.0 -(1.4)*RectOut.width/8.0,
                        (RectOut.getCenter()).y- (1.2)*RectOut.height/4.0,
                        (1.4)*RectOut.width/4.0,(1.2)*RectOut.height/2.0);
            TheWi=Fuentes[3].stringWidth("Sine Curve Man, Csuri 1967");
            ofSetColor(0, 0, 0 );
            Fuentes[3].drawString("Sine Curve Man, Csuri 1967",
                                 (RectOut.getCenter()).x- RectOut.width/4.0-TheWi/2.0
                                  ,RectOut.y + .88*RectOut.height);  
            
  
            ofSetColor(255,255,255);
            RevIma.loadImage("review/RandomWalkKennedy.jpg");
            RevIma.draw((RectOut.getCenter()).x + RectOut.width/8.0,
                        (RectOut.getCenter()).y- (1.2)*RectOut.height/4.0,
                        RectOut.width/4.0,(1.2)*RectOut.height/2.0);
            
            ofSetColor(0, 0, 0 );
            TheWi=Fuentes[3].stringWidth("Random Walk Kennedy, CTG 1967");
            Fuentes[3].drawString("Random Walk Kennedy, CTG 1967",
                                  (RectOut.getCenter()).x+RectOut.width/4.0-TheWi/2.0,
                                  RectOut.y + .88*RectOut.height);
            break;     
        case 2: // Robeert Silvers
            RevIma.loadImage("review/RobertSilversLIFE_b.jpg");
            ofPushMatrix();
            ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
            ofScale(.3, .3);
            RevIma.draw(-RevIma.width/2.0,-RevIma.height/2.0);
            ofPopMatrix();
            ofSetColor(0, 0, 0 );
            TheWi=Fuentes[3].stringWidth("60th Anniversary Cover of Life Magazine,");
            Fuentes[3].drawString("60th Anniversary Cover of Life Magazine,",
                                  (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);
            TheWi=Fuentes[3].stringWidth("Robert Silvers, 1996");
            Fuentes[3].drawString("Robert Silvers, 1996",
                                  (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .94*RectOut.height);            
            
            break;        
            
        case 3: // Robeert Silvers
            RevIma.loadImage("review/monads_toy-soldier.jpg");
            ofPushMatrix();
            ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
            ofScale(.25, .25);
            RevIma.draw(-RevIma.width/2.0,-RevIma.height/2.0);
            ofPopMatrix();
            ofSetColor(0, 0, 0 );
            TheWi=Fuentes[3].stringWidth("Toy Soldier, Vik Muniz, 2003");
            Fuentes[3].drawString("Toy Soldier, Vik Muniz, 2003",
                                  (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);
            // Micro narratives//
            
            break;  
        case 4: // Chuck close
            
            
            
            RevIma.loadImage("review/close3RB.jpg");
            RevIma.draw((RectOut.getCenter()).x - 3*RectOut.width/8.0 ,
                        (RectOut.getCenter()).y- (1.2)*RectOut.height/4.0,
                        RectOut.width/4.0,(1.2)*RectOut.height/2.0);
            TheWi=Fuentes[3].stringWidth("Phil (Watercolor), Chuck Close, 1977");
            ofSetColor(0, 0, 0 );
            Fuentes[3].drawString("Phil (Watercolor), Chuck Close, 1977",
                                  (RectOut.getCenter()).x- RectOut.width/4.0-TheWi/2.0
                                  ,RectOut.y + .88*RectOut.height);  
            
            
            ofSetColor(255,255,255);
            RevIma.loadImage("review/close4RB.jpg");
            RevIma.draw((RectOut.getCenter()).x + RectOut.width/8.0,
                        (RectOut.getCenter()).y- (1.2)*RectOut.height/4.0,
                        RectOut.width/4.0,(1.2)*RectOut.height/2.0);
            
            ofSetColor(0, 0, 0 );
            TheWi=Fuentes[3].stringWidth("Phil (Stamp Pad Ink), Chuck Close, 1980");
            Fuentes[3].drawString("Phil (Stamp Pad Ink), Chuck Close, 1980",
                                  (RectOut.getCenter()).x+RectOut.width/4.0-TheWi/2.0,
                                  RectOut.y + .88*RectOut.height);
            break;    
        case 5: // Golan Levin
            
            
            
            RevIma.loadImage("review/floccugraph_1.jpg");
            RevIma.draw((RectOut.getCenter()).x - 3.2*RectOut.width/8.0 ,
                        (RectOut.getCenter()).y- (1.2)*RectOut.height/4.0,
                        (1.3)*RectOut.width/4.0,
                        (1.2)*RectOut.height/2.0);
            TheWi=Fuentes[3].stringWidth("Floccular Portraits, Golan Levin, 1999");
            ofSetColor(0, 0, 0 );
            Fuentes[3].drawString("Floccular Portraits, Golan Levin, 1999",
                                  (RectOut.getCenter()).x- RectOut.width/4.0-TheWi/2.0
                                  ,RectOut.y + .88*RectOut.height);  
            
            
            ofSetColor(255,255,255);
            RevIma.loadImage("review/GolanSegSyn.jpg");
            RevIma.draw((RectOut.getCenter()).x + RectOut.width/4.0 -15*RectOut.width/64.0,
                        (RectOut.getCenter()).y- (1.2)*RectOut.height/4.0,
                        15*RectOut.width/32.0,
                        (1.2)*RectOut.height/2.0);
            
            ofSetColor(0, 0, 0 );
            TheWi=Fuentes[3].stringWidth("Segmentation and Symptom,");
            Fuentes[3].drawString("Segmentation and Symptom,",
                                  (RectOut.getCenter()).x+RectOut.width/4.0-TheWi/2.0,
                                  RectOut.y + .88*RectOut.height);
            TheWi=Fuentes[3].stringWidth("Golan Levin, 2000");
            Fuentes[3].drawString("Golan Levin, 2000",
                                  (RectOut.getCenter()).x+RectOut.width/4.0-TheWi/2.0,
                                  RectOut.y + .94*RectOut.height);
            
            break; 
        case 6: // NPR
            
            ofSetColor(0, 0, 0 );
            TheWi=Fuentes[0].stringWidth("A/S on Images");
              Fuentes[0].drawString(" (NPR)",RectOut.x+TheWi,
                                    RectOut.y + RectOut.height*.1);
            RevIma.loadImage("review/haeberli.jpg");
            ofSetColor(255,255,255);
            ofPushMatrix();
            ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
            ofScale(.6, .6);
            RevIma.draw(-RevIma.width/2.0,-RevIma.height/2.0);
            ofPopMatrix();
            ofSetColor(0, 0, 0 );
            TheWi=Fuentes[3].stringWidth("From: \"Paint by Numbers: Abstract");
            Fuentes[3].drawString("From: \"Paint by Numbers: Abstract",
                                  (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);
            TheWi=Fuentes[3].stringWidth("Image Representations\", Paul Haeberli, 1990");
            Fuentes[3].drawString("Image Representations\", Paul Haeberli, 1990",
                                  (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .94*RectOut.height);
            break;         
            
            // Decir que en photoshop o Gimp se hacen en cuestion de segundos.
            
            
        default:
            break;
    }

}