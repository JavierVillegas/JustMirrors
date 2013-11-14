//
//  MobileSlides.cpp
//  MobileMatters
//
//  Created by Javier Villegas on 10/20/13.
//  Copyright (c) 2013 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"
void defense::AngleShift(){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofImage RevIma;
    ofImage AngleMem;
    ofSetColor(0, 0, 0 );
        Fuentes[0].drawString("Example 1. Orientation Mirror",
                            RectOut.x,RectOut.y + RectOut.height*.1);
    
    ofSetColor(255,255,255 );
    int TheWi;
    
    RevIma.loadImage("Mobile/AngleMemoryless.png");
    AngleMem.loadImage("Mobile/Angle.png");
    ofPushMatrix();
    ofTranslate((RectOut.getCenter()).x -5*RectOut.width/16.0,(RectOut.getCenter()).y);
    ofScale(0.5, 0.5);
    RevIma.draw(-RevIma.width/2.0,-RevIma.height/2.0);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate((RectOut.getCenter()).x +4*RectOut.width/16.0,(RectOut.getCenter()).y+
                RectOut.height/16.0);
    ofScale(0.5, 0.5);
    AngleMem.draw(-AngleMem.width/2.0,-AngleMem.height/2.0);
    ofPopMatrix();
    
}


void defense::MeshMobile(){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofImage RevIma;
    ofImage AngleMem;
    ofSetColor(0, 0, 0 );
    Fuentes[0].drawString("Example 2. Mesh Mirror",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    
    ofSetColor(255,255,255 );
    int TheWi;
    
    RevIma.loadImage("Mobile/meshMemoryless.png");
    AngleMem.loadImage("Mobile/MeshFlow.png");
    ofPushMatrix();
    ofTranslate((RectOut.getCenter()).x -5.5*RectOut.width/16.0,(RectOut.getCenter()).y);
    ofScale(0.5, 0.5);
    RevIma.draw(-RevIma.width/2.0,-RevIma.height/2.0);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate((RectOut.getCenter()).x +3*RectOut.width/16.0,(RectOut.getCenter()).y);
    ofScale(0.5, 0.5);
    AngleMem.draw(-AngleMem.width/2.0,-AngleMem.height/2.0);
    ofPopMatrix();
    
}
