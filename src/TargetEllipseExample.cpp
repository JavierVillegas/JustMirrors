//
//  TargetEllipseExample.cpp
//  Defense
//
//  Created by Javier Villegas on 6/6/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"
void defense::TargetEllipseExample(){

    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0);
    Fuentes[1].drawString("Temporal Coherence Algorithms",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    Fuentes[3].drawString("Example, Ellipses as synthesis objects",
                          RectOut.x,RectOut.y + RectOut.height*.2);
    Fuentes[3].drawString("Non-coherent (Left) Vs Attractors algorithm (Right)",
                          RectOut.x,RectOut.y + RectOut.height*.3);
    ofRectangle RectLimits;
    
    RectLimits.x =(RectOut.getCenter()).x - 3.5*RectOut.width/8.0;
    RectLimits.y=(RectOut.getCenter()).y - .5*RectOut.height/4.0;
    RectLimits.width=1.5*RectOut.width/4.0;
    RectLimits.height=RectOut.height/2.0;

    PlotEllipses(TheTargetsEllipses,RectLimits);
    RectLimits.x =(RectOut.getCenter()).x + .5*RectOut.width/8.0;
    PlotEllipses(TheCoherentEllipses,RectLimits);

}
