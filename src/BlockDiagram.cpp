//
//  BlockDiagram.cpp
//  Defense
//
//  Created by Javier Villegas on 5/31/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::BlockDiagram(int BMode){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofImage TheBlock;
    TheBlock.loadImage("Introduction/newblocks.png");
    ofPushMatrix();
    ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y+RectOut.height/8.0);
    ofScale(.8, .8);
    TheBlock.draw(-TheBlock.width/2.0,-TheBlock.height/2.0);
    ofPopMatrix();
    
    if (BMode>=0) { // only the input
        ofSetHexColor(0xffffff);
        colorImg.draw(RectOut.x,
                      RectOut.y+RectOut.height/5.0,
                      RectOut.width/6.0, 3*RectOut.width/(4*6.0));
        }
    if (BMode>=1) {
        ofSetHexColor(0xffffff);
        colorImg.draw(RectOut.x+3*RectOut.width/16.0,
                      RectOut.y+RectOut.height/5.0,
                      RectOut.width/6.0, 3*RectOut.width/(4*6.0));
        ofSetColor(200,0,0);
        PlotEllipNoFill(TheTargetsEllipses,ofRectangle(RectOut.x+3*RectOut.width/16.0,
                                                    RectOut.y+RectOut.height/5.0,
                                                    RectOut.width/6.0, 3*RectOut.width/(4*6.0)));
        
    }
    if (BMode>=2) {
        ofSetHexColor(0xffffff);
        colorImg.draw(RectOut.x+6.5*RectOut.width/16.0,
                      RectOut.y+RectOut.height/5.0,
                      RectOut.width/6.0, 3*RectOut.width/(4*6.0));
        ofSetColor(0,0,200);
        PlotEllipNoFill(TheCoherentEllipses,ofRectangle(RectOut.x+6.5*RectOut.width/16.0,
                                                       RectOut.y+RectOut.height/5.0,
                                                       RectOut.width/6.0, 3*RectOut.width/(4*6.0)));
        
    } 
    if (BMode==3) {
        PlotEllipPolligon(TheCoherentEllipses,ofRectangle(RectOut.x+13*RectOut.width/16.0,
                                                        RectOut.y+RectOut.height/5.0,
                                                        RectOut.width/5.0, 3*RectOut.width/(4*5.0)));
    }
    if (BMode==4) {
        PlotEllipsesTexture(TheCoherentEllipses,ofRectangle(RectOut.x+13*RectOut.width/16.0,
                                                            RectOut.y+RectOut.height/5.0,
                                                            RectOut.width/5.0, 3*RectOut.width/(4*5.0)));
    }
    if (BMode==5) {
        
        PlotEllipsesTexture(TheCoherentEllipses,ofRectangle(RectOut.x+13*RectOut.width/16.0,
                                                            RectOut.y+RectOut.height/5.0,
                                                            RectOut.width/5.0, 3*RectOut.width/(4*5.0)));   
//        PlotEllipExternal(TheCoherentEllipses,ofRectangle(RectOut.x+13*RectOut.width/16.0,
//                                                          RectOut.y+RectOut.height/5.0,
//                                                          RectOut.width/5.0, 3*RectOut.width/(4*5.0)),0);
    }
  
    
}

