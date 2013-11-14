//
//  VideoReviewSlide.cpp
//  Defense
//
//  Created by Javier Villegas on 6/3/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::VideoReviewSlide(int VMode){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofImage RevIma;
    ofSetColor(0, 0, 0 );
    Fuentes[0].drawString("A/S on Music Videos",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    
    ofSetColor(255,255,255 );
    ofxCvColorImage	TempColorImg;
    int TheWi;
    switch (VMode) {
    

        case 0:
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
                TheWi=Fuentes[3].stringWidth("Take on Me, A-ha, 1986,");
                Fuentes[3].drawString("Take on Me, A-ha, 1986,",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);
                TheWi=Fuentes[3].stringWidth("Mike Patterson, Steve Barron");
                Fuentes[3].drawString("Mike Patterson, Steve Barron",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .94*RectOut.height);            
      //      }
            
            break;           
        case 1:
  //          if (VideoIsPlaying){
                TempColorImg.allocate(Mov.width, Mov.height);
                ofSetHexColor(0xFFFFFF);
                TempColorImg.setFromPixels(Mov.getPixels(),Mov.width, Mov.height);
                ofPushMatrix();
                ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
                ofScale(.8, .8);
                TempColorImg.draw(-TempColorImg.width/2.0,-TempColorImg.height/2.0);
                
                ofPopMatrix();
                ofSetColor(0, 0, 0 );
                TheWi=Fuentes[3].stringWidth("Fell in Love With a Girl, The White Stripes, 2002");
                Fuentes[3].drawString("Fell in Love With a Girl, The White Stripes, 2002",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);
                TheWi=Fuentes[3].stringWidth("Michel Gondry");
                Fuentes[3].drawString("Michel Gondry",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .94*RectOut.height);            
  //          }
            
            break;    
        case 2:
 //           if (VideoIsPlaying){
                TempColorImg.allocate(Mov.width, Mov.height);
                ofSetHexColor(0xFFFFFF);
                TempColorImg.setFromPixels(Mov.getPixels(),Mov.width, Mov.height);
                ofPushMatrix();
                ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
                ofScale(.8, .8);
                TempColorImg.draw(-TempColorImg.width/2.0,-TempColorImg.height/2.0);
                
                ofPopMatrix();
                ofSetColor(0, 0, 0 );
                TheWi=Fuentes[3].stringWidth("Black Tambourine, Beck, 2004");
                Fuentes[3].drawString("Black Tambourine, Beck, 2004",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);         
 //           }
            
            break; 
        case 3:
  //          if (VideoIsPlaying){
                TempColorImg.allocate(Mov.width, Mov.height);
                ofSetHexColor(0xFFFFFF);
                TempColorImg.setFromPixels(Mov.getPixels(),Mov.width, Mov.height);
                ofPushMatrix();
                ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
                ofScale(.8, .8);
                TempColorImg.draw(-TempColorImg.width/2.0,-TempColorImg.height/2.0);
                
                ofPopMatrix();
                ofSetColor(0, 0, 0 );
                TheWi=Fuentes[3].stringWidth("Only, Nine Inch Nails, 2005,");
                Fuentes[3].drawString("Only, Nine Inch Nails, 2005",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);
                TheWi=Fuentes[3].stringWidth("David Fincher,");
                Fuentes[3].drawString("David Fincher",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .94*RectOut.height);            
 //           }
            
            break;  
        case 4:
 //           if (VideoIsPlaying){
                TempColorImg.allocate(Mov.width, Mov.height);
                ofSetHexColor(0xFFFFFF);
                TempColorImg.setFromPixels(Mov.getPixels(),Mov.width, Mov.height);
                ofPushMatrix();
                ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
                ofScale(.9, .9);
                TempColorImg.draw(-TempColorImg.width/2.0,-TempColorImg.height/2.0);
                
                ofPopMatrix();
                ofSetColor(0, 0, 0 );
                TheWi=Fuentes[3].stringWidth("Ankle Injuries, Fujiya & Miyagi, 2007");
                Fuentes[3].drawString("Ankle Injuries, Fujiya & Miyagi, 2007",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);         
     //       }    
            break;
        case 5:
 //           if (VideoIsPlaying){
                TempColorImg.allocate(Mov.width, Mov.height);
                ofSetHexColor(0xFFFFFF);
                TempColorImg.setFromPixels(Mov.getPixels(),Mov.width, Mov.height);
                ofPushMatrix();
                ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
                ofScale(.9, .9);
                TempColorImg.draw(-TempColorImg.width/2.0,-TempColorImg.height/2.0);
                
                ofPopMatrix();
                ofSetColor(0, 0, 0 );
                TheWi=Fuentes[3].stringWidth("House of Cards, Radiohead, 2007,");
                Fuentes[3].drawString("House of Cards, Radiohead, 2007,",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);   
                TheWi=Fuentes[3].stringWidth("James Frost, Aaron Koblin");
                Fuentes[3].drawString("James Frost, Aaron Koblin",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .94*RectOut.height);   
//            }    
            break;
        case 6:
 //           if (VideoIsPlaying){
                TempColorImg.allocate(Mov.width, Mov.height);
                ofSetHexColor(0xFFFFFF);
                TempColorImg.setFromPixels(Mov.getPixels(),Mov.width, Mov.height);
                ofPushMatrix();
                ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
                ofScale(.8, .8);
                TempColorImg.draw(-TempColorImg.width/2.0,-TempColorImg.height/2.0);
                
                ofPopMatrix();
                ofSetColor(0, 0, 0 );
                TheWi=Fuentes[3].stringWidth("Fragile Tension, Depeche Mode, 2010,");
                Fuentes[3].drawString("Fragile Tension, Depeche Mode, 2010,",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);   
                TheWi=Fuentes[3].stringWidth("Rob Chandler, Barney Steel");
                Fuentes[3].drawString("Rob Chandler, Barney Steel",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .94*RectOut.height);   
 //           }    
            break;          
        case 7:
//            if (VideoIsPlaying){
                TempColorImg.allocate(Mov.width, Mov.height);
                ofSetHexColor(0xFFFFFF);
                TempColorImg.setFromPixels(Mov.getPixels(),Mov.width, Mov.height);
                ofPushMatrix();
                ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
                ofScale(.8, .8);
                TempColorImg.draw(-TempColorImg.width/2.0,-TempColorImg.height/2.0);
                
                ofPopMatrix();
                ofSetColor(0, 0, 0 );
                TheWi=Fuentes[3].stringWidth("Just the Way you Are, Bruno Mars, 2010,");
                Fuentes[3].drawString("Just the Way you Are, Bruno Mars, 2010,",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);   
                TheWi=Fuentes[3].stringWidth("Ethan Lader (inspired by the artwork of Erika Iris Simmons)");
                Fuentes[3].drawString("Ethan Lader (inspired by the artwork of Erika Iris Simmons)",
                                      (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .94*RectOut.height);   
   //         }    
            break;            
            
            default:
            break;
    
    }
    TempColorImg.clear(); 
}

