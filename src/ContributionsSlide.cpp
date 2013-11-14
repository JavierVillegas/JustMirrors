//
//  ScopeAndLimitations.cpp
//  Defense
//
//  Created by Javier Villegas on 6/2/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::ContributionsSlide(){
    ofRectangle RecOut;
    float Ypos;
    RecOut= OneBigRect();
    Ypos = RecOut.y;
    ofSetColor(0, 0, 0);
    
    float TheSwitdh = Fuentes[0].stringWidth("Contributions:");
    float TheHeight = Fuentes[0].stringHeight("Contributions:");
    Ypos+=3*TheHeight;
   // Fuentes[0].drawString("Contributions:",ScreenX/10.0,Ypos);
     Fuentes[0].drawString("Contributions:",RecOut.x,RecOut.y + RecOut.height*.1);
    Ypos+=ScreenY/8.0;
    TheHeight =Fuentes[1].stringHeight("Mapping Algorithms");
    ofEllipse(RecOut.x+.05*RecOut.width, Ypos - TheHeight/2.0, 10,10);
    Fuentes[1].drawString("Mapping Algorithms",RecOut.x+.1*RecOut.width,Ypos );
    Ypos+=ScreenY/8.0;
  
    TheHeight =Fuentes[1].stringHeight("Strategies for Temporal Coherency");
    ofEllipse(RecOut.x+.05*RecOut.width, Ypos - TheHeight/2.0, 10,10);
    Fuentes[1].drawString("Strategies for Temporal Coherency",RecOut.x+.1*RecOut.width,Ypos); 
    Ypos+=ScreenY/8.0;

    TheHeight =Fuentes[1].stringHeight("Algorithms for Cross-Synthesis on Videos");                                   
    ofEllipse(RecOut.x+.05*RecOut.width, Ypos - TheHeight/2.0, 10,10);
    Fuentes[1].drawString("Algorithms for Cross-Synthesis on Videos",RecOut.x+.1*RecOut.width,Ypos); 
    Ypos+=ScreenY/8.0;
    
    TheHeight =Fuentes[1].stringHeight("Cross-Synthesis for Parallel Narratives");                                   
    ofEllipse(RecOut.x+.05*RecOut.width, Ypos - TheHeight/2.0, 10,10);
    Fuentes[1].drawString("Cross-Synthesis for Parallel Narratives",RecOut.x+.1*RecOut.width,Ypos); 
}