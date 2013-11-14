//
//  Future.cpp
//  Defense
//
//  Created by Javier Villegas on 6/2/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::ExtensionsSlide(){
    ofRectangle RecOut;
    float Ypos;
    RecOut= OneBigRect();
    Ypos = RecOut.y;
    ofSetColor(0, 0, 0);
    
    float TheSwitdh = Fuentes[0].stringWidth("Extension:");
    float TheHeight = Fuentes[0].stringHeight("Extension:");
    Ypos+=3*TheHeight;
   // Fuentes[0].drawString("Contributions:",ScreenX/10.0,Ypos);
     Fuentes[0].drawString("Extension and Future Work:",RecOut.x,RecOut.y + RecOut.height*.1);
    Ypos+=ScreenY/8.0;
    TheHeight =Fuentes[1].stringHeight("Explorations on Perception");
    ofEllipse(RecOut.x+.05*RecOut.width, Ypos - TheHeight/2.0, 10,10);
    Fuentes[1].drawString("Explorations on Perception",RecOut.x+.1*RecOut.width,Ypos );
    Ypos+=ScreenY/8.0;
  
    TheHeight =Fuentes[1].stringHeight("Gesture Augmentation");
    ofEllipse(RecOut.x+.05*RecOut.width, Ypos - TheHeight/2.0, 10,10);
    Fuentes[1].drawString("Gesture Augmentation",RecOut.x+.1*RecOut.width,Ypos); 
    Ypos+=ScreenY/8.0;

    TheHeight =Fuentes[1].stringHeight("Matching Algorithm Visualization");                                   
    ofEllipse(RecOut.x+.05*RecOut.width, Ypos - TheHeight/2.0, 10,10);
    Fuentes[1].drawString("Matching Algorithm Visualization",RecOut.x+.1*RecOut.width,Ypos); 
    Ypos+=ScreenY/8.0;

}


void defense::FutureSlide(){
    ofRectangle RecOut;
    float Ypos;
    RecOut= OneBigRect();
    Ypos = RecOut.y;
    ofSetColor(0, 0, 0);
    
    float TheSwitdh = Fuentes[0].stringWidth("Future Work:");
    float TheHeight = Fuentes[0].stringHeight("Future Work:");
    Ypos+=3*TheHeight;
    // Fuentes[0].drawString("Contributions:",ScreenX/10.0,Ypos);
    Fuentes[0].drawString("Future Work:",RecOut.x,RecOut.y + RecOut.height*.1);
    Ypos+=ScreenY/8.0;
    TheHeight =Fuentes[1].stringHeight("Mobile Platforms");
    ofEllipse(RecOut.x+.05*RecOut.width, Ypos - TheHeight/2.0, 10,10);
    Fuentes[1].drawString("Mobile Platforms",RecOut.x+.1*RecOut.width,Ypos );
    Ypos+=ScreenY/8.0;
    
    TheHeight =Fuentes[1].stringHeight("Parallel Narratives");
    ofEllipse(RecOut.x+.05*RecOut.width, Ypos - TheHeight/2.0, 10,10);
    Fuentes[1].drawString("Parallel Narratives",RecOut.x+.1*RecOut.width,Ypos); 
    Ypos+=ScreenY/8.0;
    
    TheHeight =Fuentes[1].stringHeight("Cohesion");                                   
    ofEllipse(RecOut.x+.05*RecOut.width, Ypos - TheHeight/2.0, 10,10);
    Fuentes[1].drawString("Cohesion",RecOut.x+.1*RecOut.width,Ypos); 
    Ypos+=ScreenY/8.0;
    
    TheHeight =Fuentes[1].stringHeight("Coherence on Connections");                                   
    ofEllipse(RecOut.x+.05*RecOut.width, Ypos - TheHeight/2.0, 10,10);
    Fuentes[1].drawString("Coherence on Connections",RecOut.x+.1*RecOut.width,Ypos); 
    
}