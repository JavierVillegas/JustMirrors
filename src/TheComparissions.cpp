//
//  TheComparissions.cpp
//  Defense
//
//  Created by Javier Villegas on 6/7/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::Comparisions(int CMode){
ofImage RevIma;
ofRectangle RectOut;
RectOut = OneBigRect();

    
    
    ofRectangle RectLimits;
    
    float TheWi;
    
 switch (CMode) {    
     case 0: // histograms
         ofSetColor(0, 0, 0);
         Fuentes[3].drawString("Displacement distribution:",
                      RectOut.x,RectOut.y + RectOut.height*.1);
         RevIma.loadImage("TemporalCoherence/HistoJumpsRB.png");
         ofSetColor(255, 255, 255);
         RectLimits.x =(RectOut.getCenter()).x - 1.5*RectOut.width/4.0;
         RectLimits.y=(RectOut.getCenter()).y - 1.5*RectOut.height/4.0;
         RectLimits.width=1.5*RectOut.width/2.0;
         RectLimits.height=1.8*RectOut.height/2.0; 
         RevIma.draw(RectLimits);
         
         break;
     case 1: // jerk

         RevIma.loadImage("TemporalCoherence/JerckEquation.png");
         ofSetColor(255, 255, 255);
         RectLimits.x =RectOut.x;
         RectLimits.y=RectOut.y + RectOut.height*.1;
         RectLimits.width =RevIma.width*.8;
         RectLimits.height =RevIma.height*.8;
         RevIma.draw(RectLimits);
         RevIma.loadImage("TemporalCoherence/JerkBarRB.png");
         
         RectLimits.x =(RectOut.getCenter()).x - 1.*RectOut.width/4.0;
         RectLimits.y=(RectOut.getCenter()).y - .4*RectOut.height/4.0;
         RectLimits.width=1.*RectOut.width/2.0;
         RectLimits.height=1.*RectOut.height/2.0; 
         
         RevIma.draw(RectLimits);
         
         ofSetColor(0, 0, 0);
         Fuentes[3].drawString("Smoothness of the matching",
                               RectOut.x,RectOut.y + RectOut.height*.1);
         TheWi=Fuentes[3].stringWidth("1) Minimum sum. 2) Minimum max. 3) Direction smoothing 4) Attractors");
         Fuentes[3].drawString("1) Minimum sum. 2) Minimum max. 3) Direction smoothing 4) Attractors",
                               (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .92*RectOut.height);
  
         

         break;
         
     case 2: 
         
         RevIma.loadImage("TemporalCoherence/jerkVsError1RB.png");
         ofSetColor(255, 255, 255);
         RectLimits.x =(RectOut.getCenter()).x - 3.8*RectOut.width/8.0;
         RectLimits.y=(RectOut.getCenter()).y - .3*RectOut.height/4.0;
         RectLimits.width=1.5*RectOut.width/4.0;
         RectLimits.height=RectOut.height/2.0;
         RevIma.draw(RectLimits);
         RevIma.loadImage("TemporalCoherence/jerkVsError2RB.png");
         RectLimits.y=(RectOut.getCenter()).y - RectOut.height/4.0;
         RectLimits.width=2.4*RectOut.width/4.0;
         RectLimits.height=1.4*RectOut.height/2.0;
         RectLimits.x =(RectOut.getCenter()).x-RectOut.width/16.0;
                  
         RevIma.draw(RectLimits);
         
         ofSetColor(0, 0, 0);
         Fuentes[3].drawString("Smoothness versus representation",
                               RectOut.x,RectOut.y + RectOut.height*.1);
         
         break;
     case 3: // dispersion
         
         RevIma.loadImage("TemporalCoherence/Dispersionequ.png");
         ofSetColor(255, 255, 255);
         RectLimits.x =RectOut.x;
         RectLimits.y=RectOut.y + RectOut.height*.12;
         RectLimits.width =RevIma.width*.8;
         RectLimits.height =RevIma.height*.8;
         RevIma.draw(RectLimits);
         RevIma.loadImage("TemporalCoherence/AngledispersionRB.png");
         
         RectLimits.x =(RectOut.getCenter()).x - 1.*RectOut.width/4.0;
         RectLimits.y=(RectOut.getCenter()).y - .6*RectOut.height/4.0;
         RectLimits.width=1.*RectOut.width/2.0;
         RectLimits.height=1.*RectOut.height/2.0; 
         
         RevIma.draw(RectLimits);
         
         ofSetColor(0, 0, 0);
         Fuentes[3].drawString("Direction dispersion",
                               RectOut.x,RectOut.y + RectOut.height*.1);
         TheWi=Fuentes[3].stringWidth("1) Random 2) Minimum sum. 3) Minimum max.");
         Fuentes[3].drawString("1) Random 2) Minimum sum. 3) Minimum max. ",
                               (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .9*RectOut.height);
         
         TheWi=Fuentes[3].stringWidth("4) Direction smoothing 5) Gradient 6) Attractors");
         Fuentes[3].drawString("4) Direction smoothing 5) Gradient 6) Attractors",
                               (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .94*RectOut.height);      
         
         break; 
         
     default:
         break;
 }
}
    
    
