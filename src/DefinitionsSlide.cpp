//
//  DefinitionsSlide.cpp
//  Defense
//
//  Created by Javier Villegas on 5/31/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::DefinitionsSlide(){
    ofRectangle RecOut;
    float Ypos;
    RecOut= OneBigRect();
    Ypos = RecOut.y;
    ofSetColor(0, 0, 0);
    
    float TheSwitdh = Fuentes[0].stringWidth("The A/S Approach:");
    float TheHeight = Fuentes[0].stringHeight("The A/S Approach:");
    Ypos+=3*TheHeight;
   // Fuentes[0].drawString("Definitions:",ScreenX/10.0,Ypos);
     Fuentes[0].drawString("The A/S Approach:",RecOut.x,RecOut.y + RecOut.height*.1);
    Ypos+=ScreenY/10.0;
    TheSwitdh = Fuentes[3].stringWidth("Analysis: The separating of any material or abstract entity into its constituent \nelements (opposed to synthesis).");
        Fuentes[3].drawString("Analysis: The separating of any material or abstract entity into its constituent \nelements (opposed to synthesis).",ScreenX/10.0,Ypos);
    Ypos+=ScreenY/10.0;
    TheSwitdh = Fuentes[3].stringWidth("Synthesis: The combining of the constituent elements of separate material or \nabstract entities into a single or unified entity (opposed to analysis).");
    Fuentes[3].drawString("Synthesis: The combining of the constituent elements of separate material or \nabstract entities into a single or unified entity (opposed to analysis).",ScreenX/10.0,Ypos); 
    

}