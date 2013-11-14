//
//  ChapterTitle.cpp
//  Defense
//
//  Created by Javier Villegas on 5/31/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"
void defense::ChapterTitle(string TheTitle){
   TitleAndLine();
    float TheSwitdh = Fuentes[4].stringWidth(TheTitle);
    float TheSHeight = Fuentes[4].stringHeight(TheTitle);
    Fuentes[4].drawString(TheTitle, (ScreenX-TheSwitdh)/2.0, ScreenY/2.0+TheSHeight/2.0);

}