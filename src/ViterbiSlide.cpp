//
//  ViterbiSlide.cpp
//  Defense
//
//  Created by Javier Villegas on 6/7/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"
void defense::ViterbiSlide(){
    
    float  Steps [NT][NT] = 
    {{.4, 1, 2, 3, 4, 1, 2, 3, 4,  5,  2,  3,  4,  5,  2,  3,  4,  5,  1,  2,  3,  4,  1, 2,  3,  4},
        {1, .4, 1, 2, 3, 2, 1, 2, 3,  4,  3,  4,  5,  6,  3,  4,  5,  6,  2,  3,  4,  5,  2, 3,  4,  5},
        {2, 1, .4, 1, 2, 3, 2, 1, 2,  3,  4,  5,  6,  7,  4,  5,  6,  7,  3,  4,  5,  6,  3, 4,  5,  6},
        {3, 2, 1, .4, 1, 4, 3, 2, 1,  2,  5,  6,  7,  8,  5,  6,  7,  8,  4,  5,  6,  7,  4, 5,  6,  7},
        {4, 3, 2, 1, .4, 5, 4, 3, 2,  1,  6,  7,  8,  9,  6,  7,  8,  9,  5,  6,  7,  8,  5, 6,  7,  8},
        {1, 2, 3, 4, 5, .4, 1, 2, 3,  4,  1,  2,  3,  4,  1,  2,  3,  4,  2,  3,  4,  5,  2, 3,  4,  5},
        {2, 1, 2, 3, 4, 1, .4, 1, 2,  3,  2,  3,  4,  5,  2,  3,  4,  5,  3,  4,  5,  6,  3, 4,  5,  6},
        {3, 2, 1, 2, 3, 2, 1, .4, 1,  2,  3,  4,  5,  6,  3,  4,  5,  6,  4,  5,  6,  7,  4, 5,  6,  7},
        {4, 3, 2, 1, 2, 3, 2, 1, .4,  1,  4,  5,  6,  7,  4,  5,  6,  7,  5,  6,  7,  8,  5, 6,  7,  8},
        {5, 4, 3, 2, 1, 4, 3, 2, 1,  .4,  5,  6,  7,  8,  5,  6,  7,  8,  6,  7,  8,  9,  6, 7,  8,  9},
        {2, 3, 4, 5, 6, 1, 2, 3, 4,  5,  .4,  1,  2,  3,  2,  3,  4,  5,  1,  2,  3,  4,  3, 4,  5,  6},
        {3, 4, 5, 6, 7, 2, 3, 4, 5,  6,  1,  .4,  1,  2,  3,  4,  5,  6,  2,  1,  2,  3,  4, 5,  6,  7},
        {4, 5, 6, 7, 8, 3, 4, 5, 6,  7,  2,  1,  .4,  1,  4,  5,  6,  7,  3,  2,  1,  2,  5, 6,  7,  8},
        {5, 6, 7, 8, 9, 4, 5, 6, 7,  8,  3,  2,  1,  .4,  5,  6,  7,  8,  4,  3,  2,  1,  6, 7,  8,  9},
        {2, 3, 4, 5, 6, 1, 2, 3, 4,  5,  2,  3,  4,  5,  .4,  1,  2,  3,  3,  4,  5,  6,  1, 2,  3,  4},
        {3, 4, 5, 6, 7, 2, 3, 4, 5,  6,  3,  4,  5,  6,  1,  .4,  1,  2,  4,  5,  6,  7,  2, 1,  2,  3},
        {4, 5, 6, 7, 8, 3, 4, 5, 6,  7,  4,  5,  6,  7,  2,  1,  .4,  1,  5,  6,  7,  8,  3, 2,  1,  2},
        {5, 6, 7, 8, 9, 4, 5, 6, 7,  8,  5,  6,  7,  8,  3,  2,  1,  .4,  6,  7,  8,  9,  4, 3,  2,  1},
        {1, 2, 3, 4, 5, 2, 3, 4, 5,  6,  1,  2,  3,  4,  3,  4,  5,  6,  .4,  1,  2,  3,  2, 3,  4,  5},
        {2, 3, 4, 5, 6, 3, 4, 5, 6,  7,  2,  1,  2,  3,  4,  5,  6,  7,  1,  .4,  1,  2,  3, 4,  5,  6},
        {3, 4, 5, 6, 7, 4, 5, 6, 7,  8,  3,  2,  1,  2,  5,  6,  7,  8,  2,  1,  .4,  1,  4, 5,  6,  7},
        {4, 5, 6, 7, 8, 5, 6, 7, 8,  9,  4,  3,  2,  1,  6,  7,  8,  9,  3,  2,  1,  .4,  5, 6,  7,  8},
        {1, 2, 3, 4, 5, 2, 3, 4, 5,  6,  3,  4,  5,  6,  1,  2,  3,  4,  2,  3,  4,  5,  .4, 1,  2,  3},
        {2, 3, 4, 5, 6, 3, 4, 5, 6,  7,  4,  5,  6,  7,  2,  1,  2,  3,  3,  4,  5,  6,  1, .4,  1,  2},
        {3, 4, 5, 6, 7, 4, 5, 6, 7,  8,  5,  6,  7,  8,  3,  2,  1,  2,  4,  5,  6,  7,  2, 1,  .4,  1},
        {4, 5, 6, 7, 8, 5, 6, 7, 8,  9,  6,  7,  8,  9,  4,  3,  2,  1,  5,  6,  7,  8,  3, 2,  1,  .4}};
   
    int ini =MIN((int)26*Slider1/127.0,25);
    int dest =MIN((int)26*Slider2/127.0,25);
    G_PowTemplates = .2 +  (6*(Slider3)/127.0);
    
    ofRectangle RectOut;
    RectOut = OneBigRect();
    float TheWi;

    
    
    
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    ofClear(255,255,255,255);
    

    
    // First stage
    for (int Tem =0; Tem<26; Tem++) {
        float LineCol =255*powf(((Steps[ini][Tem]-1)/9.0),.25);
        ofSetColor(LineCol, LineCol, LineCol, 255);    
          ofLine((float)ScreenX/6.0,
           (float)ScreenY/27.0 +ini*(float)ScreenY/27.0,
           2*(float)ScreenX/6.0,
           (float)ScreenY/27.0 +Tem*(float)ScreenY/27.0);
    }
    
    //Midle Stages
    for (int Ts=1; Ts<3; Ts++) {
        for ( int PreTem =0; PreTem<26; PreTem++){  
            for (int Tem =0; Tem<26; Tem++) {
                 float LineCol =255*powf(((Steps[PreTem][Tem]-1)/9.0),.25);
                 ofSetColor(LineCol, LineCol, LineCol, 50);    
                ofLine((float)ScreenX/6.0+Ts*(float)ScreenX/6.0,
               (float)ScreenY/27.0 +PreTem*(float)ScreenY/27.0,
               (float)ScreenX/6.0+(Ts+1)*(float)ScreenX/6.0,
               (float)ScreenY/27.0 +Tem*(float)ScreenY/27.0);
            }
      }    
    }
    
    // Last  Stage
    
    for (int Tem =0; Tem<26; Tem++) {
        float LineCol =255*powf(((Steps[Tem][dest]-1)/9.0),.25);
        ofSetColor(LineCol, LineCol, LineCol, 255);    
        ofLine(4*(float)ScreenX/6.0,
               (float)ScreenY/27.0 +Tem*(float)ScreenY/27.0,
               5*(float)ScreenX/6.0,
               (float)ScreenY/27.0 +dest*(float)ScreenY/27.0);
    }    
    
    
    // The Best path:
    int * ThePath;
    ThePath = ViterbiStates(ini,dest,4);
    ofSetColor(255, 0, 0, 255);
   // Drawing the winner
    ofSetLineWidth(3.0);
    for (int Ts=0; Ts<3; Ts++) {
        ofLine((Ts+1)*(float)ScreenX/6.0,
               (float)ScreenY/27.0 +ThePath[Ts]*(float)ScreenY/27.0,
               (Ts+2)*(float)ScreenX/6.0,
               (float)ScreenY/27.0+ThePath[Ts+1]*(float)ScreenY/27.0);
       }
    
    ofLine(4*(float)ScreenX/6.0,
           (float)ScreenY/27.0 +ThePath[3]*(float)ScreenY/27.0,
           5*(float)ScreenX/6.0,
           (float)ScreenY/27.0+dest*(float)ScreenY/27.0);
     ofSetLineWidth(1.0);
    
    // 5 time steps
    //  26 templates
    ofSetColor(255, 255, 255, 255);
    
    // The nodes
    for (int Ts=0; Ts<5; Ts++) {
        
        for (int Tem =0; Tem<26; Tem++) {
            
            ofPushMatrix();
            ofTranslate((float)ScreenX/6.0+Ts*(float)ScreenX/6.0,
                        (float)ScreenY/27.0 +Tem*(float)ScreenY/27.0);
            ofScale(.09,.09);
            
            Templates[Tem].draw(-Templates[Tem].width/2.0,
                                -Templates[Tem].height/2.0);
            ofPopMatrix();
            
        }        
    }
    

    ofSetColor(255, 0, 0 );
    Fuentes[1].drawString("Viterbi Algorithm",
                          RectOut.x,RectOut.y*.5 + RectOut.height*.01);
    
    Fuentes[3].drawString("Finding 3 intermediate states between " +
                          ofToString(ini) + " and " + ofToString(dest),
                          RectOut.x,RectOut.y*.5 + RectOut.height*.1);
    
    
    glDisable(GL_BLEND);
    


}
