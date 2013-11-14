//
//  Slide.cpp
//  Defense
//
//  Created by Javier Villegas on 5/30/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "Slide.h"
Slide::Slide(ofVec2f exTitlePos,string exTheTitle, int exMode){
     Titlepos = exTitlePos;
     TheTitle = exTheTitle;
     Mode = exMode;
    
}

void Slide::Update(){}

void Slide::Draw(ofTrueTypeFont Fuente){

    switch (Mode){
    
    case 0:  //the title slide
            Fuente.loadFont("helvetica.ttf",32);
            
            
            break;
    case 1: // table of content
            break;
    case 2: // big title
            break;
    case 3: // one graph
            break;
    case 4: // two graphs
            break;
       
    }


}