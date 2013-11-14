//
//  Slide.h
//  Defense
//
//  Created by Javier Villegas on 5/30/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#ifndef Defense_Slide_h
#define Defense_Slide_h
#include "ofMain.h"
class Slide{

public:
    string TheTitle;
    ofVec2f Titlepos;
    int Mode;

    Slide(ofVec2f exTitlePos,string exTheTitle,int exMode);
    void Update();
    void Draw(ofTrueTypeFont Fuente);
};

#endif
