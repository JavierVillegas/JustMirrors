//
//  AllSubSectionTitles.cpp
//  Defense
//
//  Created by Javier Villegas on 5/31/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"
void defense::AllSubSectionTitles(string TheTitle){
   TitleAndLine();
    float TheSwitdh;
    float TheSHeight;
    
    TheSwitdh = Fuentes[1].stringWidth(TheTitle);
    TheSHeight = Fuentes[1].stringHeight(TheTitle);
    Fuentes[1].drawString(TheTitle,
                          (ScreenX-TheSwitdh)/2.0, ScreenY/2.0+TheSHeight/2.0); 
    
    
    
    
    
    
//    switch (cual) {
//        case 0:
//             TheSwitdh = Fuentes[1].stringWidth("Matching and Interpolation in the Parameters' Domain");
//             TheSHeight = Fuentes[1].stringHeight("Matching and Interpolation in the Parameters' Domain");
//            Fuentes[1].drawString("Matching and Interpolation in the Parameters' Domain",
//                                  (ScreenX-TheSwitdh)/2.0, ScreenY/2.0+TheSHeight/2.0);
//            break;
//        case 1:
//            TheSwitdh = Fuentes[1].stringWidth("Gradient Based Approach");
//            TheSHeight = Fuentes[1].stringHeight("Gradient Based Approach");
//            Fuentes[1].drawString("Gradient Based Approach",
//                                  (ScreenX-TheSwitdh)/2.0, ScreenY/2.0+TheSHeight/2.0);
//            break;
//        case 2:
//            TheSwitdh = Fuentes[1].stringWidth("Attractors Based Algorithm");
//            TheSHeight = Fuentes[1].stringHeight("Attractors Based Algorithm");
//            Fuentes[1].drawString("Attractors Based Algorithm",
//                                  (ScreenX-TheSwitdh)/2.0, ScreenY/2.0+TheSHeight/2.0);
//            break;  
//        case 3:
//            TheSwitdh = Fuentes[1].stringWidth("Comparison");
//            TheSHeight = Fuentes[1].stringHeight("Comparison");
//            Fuentes[1].drawString("Comparison",
//                                  (ScreenX-TheSwitdh)/2.0, ScreenY/2.0+TheSHeight/2.0);
//
//        case 4:
//            TheSwitdh = Fuentes[1].stringWidth("Substitution");
//            TheSHeight = Fuentes[1].stringHeight("Substitution");
//            Fuentes[1].drawString("Substitution",
//                                  (ScreenX-TheSwitdh)/2.0, ScreenY/2.0+TheSHeight/2.0);
//            break;     
//        default:
//            
//            break;
//    }
    


}