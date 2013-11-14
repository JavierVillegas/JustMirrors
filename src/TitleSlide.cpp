//
//  TitleSlide.cpp
//  Defense
//
//  Created by Javier Villegas on 5/30/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"
// OLD TITLE
void defense::TitleSlide(){
    float Ycord = ScreenY/3.0;
    float InterLine = ScreenY/20.0;
    // first line
    float TheSwitdh = Fuentes[0].stringWidth("INTERACTIVE ABSTRACT MIRRORS");
    float TheHeight = Fuentes[0].stringHeight("INTERACTIVE ABSTRACT MIRRORS");
    Fuentes[0].drawString("INTERACTIVE ABSTRACT MIRRORS",(ScreenX-TheSwitdh)/2.0,Ycord);
    Ycord+= TheHeight + InterLine;
        
    TheSwitdh = Fuentes[0].stringWidth("ON MOBILE DEVICES");
    Fuentes[0].drawString("ON MOBILE DEVICES",(ScreenX-TheSwitdh)/2.0,Ycord);
    TheHeight = Fuentes[0].stringHeight("ON MOBILE DEVICES");
    Ycord+= TheHeight + 2*InterLine;    
    
    TheSwitdh = Fuentes[1].stringWidth("Javier Villegas");
    Fuentes[1].drawString("Javier Villegas",(ScreenX-TheSwitdh)/2.0,Ycord);
    TheHeight = Fuentes[1].stringHeight("Javier Villegas");
    Ycord+= TheHeight + 3*InterLine;  
    
//    TheSwitdh = Fuentes[2].stringWidth("Committee Members:");
//    Fuentes[2].drawString("Committee Members:",(ScreenX-TheSwitdh)/2.0,Ycord);
//    TheHeight = Fuentes[2].stringHeight("Committee Members:");
//    Ycord+= TheHeight + InterLine;  
//    
//    Fuentes[3].drawString("George Legrady (Chair)\nCurtis Roads\nMatthew Turk\nLisa Jevbratt",5*ScreenX/16.0,Ycord);
//    TheSwitdh = Fuentes[3].stringWidth("MAT,MUSIC");
//    Fuentes[3].drawString("ART,MAT\nMAT,MUSIC\nCS,MAT\nART,MAT",11*ScreenX/16.0-TheSwitdh,Ycord);
//    TheHeight =Fuentes[3].stringHeight("ART,MAT\nMAT,MUSIC\nCS,MAT\nART,MAT");
//    Ycord+= TheHeight + 2*InterLine;
//    
    TheSwitdh = Fuentes[3].stringWidth("Creative Coding Lab");
    Fuentes[3].drawString("Creative Coding Lab",(ScreenX-TheSwitdh)/2.0,Ycord);
    TheHeight = Fuentes[3].stringHeight("Creative Coding Lab");
    Ycord+= TheHeight + InterLine/5.0;  
//    
    TheSwitdh = Fuentes[3].stringWidth("School of Information: Science, Technology, and Arts ");
    Fuentes[3].drawString("School of Information: Science, Technology, and Arts ",(ScreenX-TheSwitdh)/2.0,Ycord);
    TheHeight = Fuentes[3].stringHeight("School of Information: Science, Technology, and Arts ");
    Ycord+= TheHeight + InterLine/5.0;  
//    
    TheSwitdh = Fuentes[3].stringWidth("University of Arizona");
    Fuentes[3].drawString("University of Arizona",(ScreenX-TheSwitdh)/2.0,Ycord);
    TheHeight = Fuentes[3].stringHeight("University of Arizona");
    Ycord+= TheHeight + InterLine/5.0;  
//    
    TheSwitdh = Fuentes[3].stringWidth("October 21, 2013");
    Fuentes[3].drawString("October 21, 2013",(ScreenX-TheSwitdh)/2.0,Ycord);
    TheHeight = Fuentes[3].stringHeight("October 21, 2013");
    Ycord+= TheHeight + InterLine/5.0;  
    //    Fuente40Bold.drawString("AN ANALYSIS-SYNTHESIS \nAPPROACH \nTO THE CREATIVE \nPROCESSING OF VIDEO SIGNALS",
//                        ScreenX/10.0, ScreenY/6.0);
}

//void defense::TitleSlide(){
//    float Ycord = ScreenY/2.0;
//    float InterLine = ScreenY/20.0;
//    // first line
//    float TheSwitdh = Fuentes[0].stringWidth("AUTOMATIC DOUBLE MEANING ANIMATIONS");
//    float TheHeight = Fuentes[0].stringHeight("AUTOMATIC DOUBLE MEANING ANIMATIONS");
//    Fuentes[0].drawString("AUTOMATIC DOUBLE MEANING ANIMATIONS",(ScreenX-TheSwitdh)/2.0,Ycord);
//    Ycord+= TheHeight + InterLine;
    
//    TheSwitdh = Fuentes[0].stringWidth("WITH GLOBAL AND LOCAL NARRATIVES");
//    Fuentes[0].drawString("WITH GLOBAL AND LOCAL NARRATIVES",(ScreenX-TheSwitdh)/2.0,Ycord);
//    TheHeight = Fuentes[0].stringHeight("WITH GLOBAL AND LOCAL NARRATIVES");
//    Ycord+= TheHeight + 2*InterLine;    
    
//    TheSwitdh = Fuentes[1].stringWidth("Javier Villegas");
//    Fuentes[1].drawString("Javier Villegas",(ScreenX-TheSwitdh)/2.0,Ycord);
//    TheHeight = Fuentes[1].stringHeight("Javier Villegas");
//    Ycord+= TheHeight + 2*InterLine;  
    
//    TheSwitdh = Fuentes[2].stringWidth("Committee Members:");
//    Fuentes[2].drawString("Committee Members:",(ScreenX-TheSwitdh)/2.0,Ycord);
//    TheHeight = Fuentes[2].stringHeight("Committee Members:");
//    Ycord+= TheHeight + InterLine;  
//    
//    Fuentes[3].drawString("George Legrady (Chair)\nCurtis Roads\nMatthew Turk\nLisa Jevbratt",5*ScreenX/16.0,Ycord);
//    TheSwitdh = Fuentes[3].stringWidth("MAT,MUSIC");
//    Fuentes[3].drawString("ART,MAT\nMAT,MUSIC\nCS,MAT\nART,MAT",11*ScreenX/16.0-TheSwitdh,Ycord);
//    TheHeight =Fuentes[3].stringHeight("ART,MAT\nMAT,MUSIC\nCS,MAT\nART,MAT");
//    Ycord+= TheHeight + 2*InterLine;
    
//    TheSwitdh = Fuentes[3].stringWidth("Experimental Visualization Lab");
//    Fuentes[3].drawString("Experimental Visualization Lab",(ScreenX-TheSwitdh)/2.0,Ycord);
//    TheHeight = Fuentes[3].stringHeight("Experimental Visualization Lab");
//    Ycord+= TheHeight + InterLine/5.0;  
//    
//    TheSwitdh = Fuentes[3].stringWidth("Media Arts & Technology Department");
//    Fuentes[3].drawString("Media Arts & Technology Department",(ScreenX-TheSwitdh)/2.0,Ycord);
//    TheHeight = Fuentes[3].stringHeight("Media Arts & Technology Department");
//    Ycord+= TheHeight + InterLine/5.0;  
//    
//    TheSwitdh = Fuentes[3].stringWidth("University of California Santa Barbara");
//    Fuentes[3].drawString("University of California Santa Barbara",(ScreenX-TheSwitdh)/2.0,Ycord);
//    TheHeight = Fuentes[3].stringHeight("University of California Santa Barbara");
//    Ycord+= TheHeight + InterLine/5.0;  
//    
//    TheSwitdh = Fuentes[3].stringWidth("June 8, 2012");
//    Fuentes[3].drawString("June 8, 2012",(ScreenX-TheSwitdh)/2.0,Ycord);
//    TheHeight = Fuentes[3].stringHeight("June 8, 2012");
//    Ycord+= TheHeight + InterLine/5.0;  
    //    Fuente40Bold.drawString("AN ANALYSIS-SYNTHESIS \nAPPROACH \nTO THE CREATIVE \nPROCESSING OF VIDEO SIGNALS",
    //                        ScreenX/10.0, ScreenY/6.0);
//}
	