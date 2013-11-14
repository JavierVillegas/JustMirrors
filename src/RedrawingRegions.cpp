//
//  RedrawingRegions.cpp
//  Defense
//
//  Created by Javier Villegas on 6/4/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::RedrawingRegions(int RMode){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0 );

    switch (RMode) {
            
        case 0: // basic square quantization
    
//            PlotCuadros(ofRectangle((RectOut.getCenter()).x-RectOut.width/4.0,
//                        (RectOut.getCenter()).y-.8*RectOut.height/4.0,
//                        RectOut.width/2.0,RectOut.height/2.0),RMode);
            PlotCuadros(ofRectangle(0.0,0.0,1.05*ScreenX,ScreenY),RMode);
            break;
        case 1:    
//            PlotCuadros(ofRectangle((RectOut.getCenter()).x-RectOut.width/4.0,
//                                    (RectOut.getCenter()).y-.8*RectOut.height/4.0,
//                                    RectOut.width/2.0,RectOut.height/2.0),RMode);        
            PlotCuadros(ofRectangle(0.0,0.0,1.05*ScreenX,ScreenY),RMode);
            break;
        case 2:
            ofPushMatrix();
            ofTranslate((RectOut.getCenter()).x,
                        (RectOut.getCenter()).y);
            ofScale(0.75*ScreenX/2.0, 0.9*ScreenY/2.0);
                PlotLizardArray();
            
            ofPopMatrix();
            
            break;
       
            
        case 3:
            
//            PlotContours(ofRectangle((RectOut.getCenter()).x-RectOut.width/4.0,
//                                     (RectOut.getCenter()).y-.8*RectOut.height/4.0,
//                                     RectOut.width/2.0,RectOut.height/2.0),0);
            PlotContours(ofRectangle(0.0,0.0,ScreenX,ScreenY),0);
            break;
        case 4:
            
//            PlotContours(ofRectangle((RectOut.getCenter()).x-RectOut.width/4.0,
//                                     (RectOut.getCenter()).y-.8*RectOut.height/4.0,
//                                     RectOut.width/2.0,RectOut.height/2.0),1);
            PlotContours(ofRectangle(0.0,0.0,ScreenX,ScreenY),1);
            break;            
        default:
            break;
    }
}
