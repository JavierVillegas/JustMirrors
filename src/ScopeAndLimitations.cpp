//
//  ScopeAndLimitations.cpp
//  Defense
//
//  Created by Javier Villegas on 6/2/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::ScopeAndLimitationsSlide(){
    ofRectangle RecOut;
    float Ypos;
    RecOut= OneBigRect();
    Ypos = RecOut.y;
    ofSetColor(0, 0, 0);
    
    float TheSwitdh = Fuentes[0].stringWidth("Scope and Limitations:");
    float TheHeight = Fuentes[0].stringHeight("Scope and Limitations:");
    Ypos+=3*TheHeight;
 //   Fuentes[0].drawString("Scope and Limitations:",ScreenX/10.0,Ypos);
     Fuentes[0].drawString("Scope and Limitations:",RecOut.x,RecOut.y + RecOut.height*.1);

    Ypos+=ScreenY/12.0;
    TheHeight =Fuentes[1].stringHeight("Input is always an RGB image.");
    ofEllipse(RecOut.x+.05*RecOut.width, Ypos - TheHeight/2.0, 10,10);
    Fuentes[1].drawString("Input is always an RGB image.",RecOut.x+.1*RecOut.width,Ypos );
    Ypos+=ScreenY/9.0;
    
    TheHeight =Fuentes[1].stringHeight("Not assumptions about the contents of the");
    //ofEllipse(RecOut.x+.05*RecOut.width, Ypos, 10,10);
    ofEllipse(RecOut.x+.05*RecOut.width, Ypos - TheHeight/2.0, 10,10);
    Fuentes[1].drawString("Not assumptions about the contents of the\ninput image",RecOut.x+.1*RecOut.width,Ypos); 
    Ypos+=ScreenY/6.0;
    
    TheHeight =Fuentes[1].stringHeight("The temporal coherence algorithm are not");                                   
    //ofEllipse(RecOut.x+.05*RecOut.width, Ypos +.4*TheHeight/2.0, 10,10);
    ofEllipse(RecOut.x+.05*RecOut.width, Ypos - TheHeight/2.0, 10,10);
    Fuentes[1].drawString("The temporal coherence algorithms are not\nintented as general solution to the problem\nof time coherent stylistic animation",RecOut.x+.1*RecOut.width,Ypos); 
  
    
}