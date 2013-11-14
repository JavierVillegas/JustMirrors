//
//  TitleAndLine.cpp
//  Defense
//
//  Created by Javier Villegas on 5/31/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

// original

void defense::TitleAndLine(){
    float Ycord = ScreenY/20.0;
    // first line
    float TheSwitdh = Fuentes[3].stringWidth
    ("INTERACTIVE ABSTRACT MIRRORS ON MOBILE DEVICES");
    float TheHeight = Fuentes[3].stringHeight
    ("INTERACTIVE ABSTRACT MIRRORS ON MOBILE DEVICES");
    Fuentes[3].drawString
    ("INTERACTIVE ABSTRACT MIRRORS ON MOBILE DEVICES",
    (ScreenX-TheSwitdh)/2.0,Ycord);
    ofLine(0, Ycord+(Ycord-TheHeight), ScreenX, Ycord+(Ycord-TheHeight));

}

//void defense::TitleAndLine(){
//    float Ycord = ScreenY/20.0;
//    // first line
//    float TheSwitdh = Fuentes[3].stringWidth
//    ("AUTOMATIC DOUBLE MEANING ANIMATIONS");
//    float TheHeight = Fuentes[3].stringHeight
//    ("AUTOMATIC DOUBLE MEANING ANIMATIONS");
//    Fuentes[3].drawString
//    ("AUTOMATIC DOUBLE MEANING ANIMATIONS",
//     (ScreenX-TheSwitdh)/2.0,Ycord);
//    ofLine(0, Ycord+(Ycord-TheHeight), ScreenX, Ycord+(Ycord-TheHeight));
//    
//}