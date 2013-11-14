//
//  SectionsContent.cpp
//  Defense
//
//  Created by Javier Villegas on 5/31/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::TemCoherenceContent(){
    TitleAndLine();
    float Ycord = ScreenY/4.0;
    float InterLine = ScreenY/24.0;
    float oldLh =Fuentes[1].getLineHeight();
    Fuentes[0].drawString("TEMPORAL COHERENCY:",ScreenX/20.0,Ycord);
    float TheHeight = Fuentes[0].stringHeight("TEMPORAL COHERENCY:");
    Ycord+= TheHeight + ScreenY/8.0;
    Fuentes[1].setLineHeight(80.0);
    Fuentes[1].drawString("Matching and Interpolation in the Parameters' Domain\nGradient Based Approach\nRedrawing Images\nAttractors Based Algorithm\nComparison",ScreenX/12.0,Ycord);
    Fuentes[1].setLineHeight(oldLh);
}
void defense::CrossContent(){
    TitleAndLine();
    float Ycord = ScreenY/4.0;
    float InterLine = ScreenY/24.0;
    float oldLh =Fuentes[1].getLineHeight();
    Fuentes[0].drawString("CROSS-SYNTHESIS:",ScreenX/20.0,Ycord);
    float TheHeight = Fuentes[0].stringHeight("CROSS-SYNTHESIS:");
    Ycord+= TheHeight + ScreenY/8.0;
    Fuentes[1].setLineHeight(80.0);
    Fuentes[1].drawString("Substitution\nDirect Detection\nGenerative Approach",ScreenX/12.0,Ycord);
    Fuentes[1].setLineHeight(oldLh);
}