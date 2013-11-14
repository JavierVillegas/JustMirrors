//
//   void AutotuneSlide();
//  Defense
//
//  Created by Javier Villegas on 5/31/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::AutotuneSlide(){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0 );
    Fuentes[0].drawString("A/S on Audio",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    ofImage TheBlock;
    ofSetColor(255, 255, 255 );
    TheBlock.loadImage("review/autotune.png");
    ofPushMatrix();
    ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y+RectOut.height/8.0);
    ofScale(.8, .8);
    TheBlock.draw(-TheBlock.width/2.0,-TheBlock.height/2.0);
    ofPopMatrix();
 
}

