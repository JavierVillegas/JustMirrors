//
//  TableContentSlide.cpp
//  Defense
//
//  Created by Javier Villegas on 5/31/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::TableContentSlide(){
    TitleAndLine();
    float Ycord = ScreenY/5.0;
    float InterLine = ScreenY/40.0;
    float oldLh =Fuentes[1].getLineHeight();
    Fuentes[0].drawString("CONTENT:",ScreenX/20.0,Ycord);
    float TheHeight = Fuentes[0].stringHeight("CONTENT:");
    Ycord+= TheHeight + ScreenY/16.0;
    Fuentes[1].setLineHeight(80.0);
    Fuentes[1].drawString("Introduction\nThe A/S Approach\nRedrawing Images\nMobile Mirrors\nFuture Work - Temporal Coherency\nFuture Work - Ambiguous Images\nDiscussion",ScreenX/12.0,Ycord);
    TheHeight = Fuentes[1].stringHeight("Introduction");
    Ycord+= TheHeight + InterLine;
     Fuentes[1].setLineHeight(oldLh);
}