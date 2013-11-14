//
//  TableContentSlide.cpp
//  Defense
//
//  Created by Javier Villegas on 5/31/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

//Draws a big rounded  white square and returns a rect with the 
//drawable area oncluding margerns


#include <iostream>
#include "defense.h"

ofRectangle defense::OneBigRect(){
//    TitleAndLine();
//    float Ycord = ScreenY/20.0;
//    // first line
//    float TheHeight = Fuentes[3].stringHeight
//    ("AN ANALYSIS-SYNTHESIS APPROACH TO THE CREATIVE PROCESSING OF VIDEO SIGNALS");
//    Ycord += (Ycord-TheHeight);
//    
//    float SpaceToEdgeX = ScreenX/15.0;
//    float SpaceToEdgeY = ScreenY/15.0;
//    roundedRect(SpaceToEdgeX, Ycord+SpaceToEdgeY, 
//                         ScreenX-2*SpaceToEdgeX, (ScreenY-Ycord)-2*SpaceToEdgeY, ScreenX/20.0);
    return ofRectangle(0,0,
                       ScreenX,ScreenY);
}