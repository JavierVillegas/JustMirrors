//
//  EdgesAndLines.cpp
//  Defense
//
//  Created by Javier Villegas on 6/5/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::EdgesAndLines(int RMode){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0 );
    // calculating the Edge map
    IplImage * EdgeMap;
    EdgeMap = cvCreateImage( cvSize(Nx,Ny),IPL_DEPTH_8U,1); 
//    cvCanny(TheInputGray, EdgeMap, 50*(.1+Slider1/127.0), 100*(.1+Slider1/127.0),3);
    cvCanny(TheInputGray, EdgeMap, 50, 100,3);
    ofxCvGrayscaleImage TempGray;
    TempGray.allocate(Nx, Ny);
    TempGray = EdgeMap;
    switch (RMode) {
            
        case 0: 
            // edge map
            ofSetColor(255, 255, 255 );
           TempGray.draw( ofRectangle(0.0,
                        0.0,ScreenX,ScreenY));
            
            break;

        case 1: 
            // Lines
//            PlotLines(LineVec,ofRectangle((RectOut.getCenter()).x-RectOut.width/4.0,
//                                          (RectOut.getCenter()).y-.8*RectOut.height/4.0,
//                                          RectOut.width/2.0,RectOut.height/2.0));
            PlotLines(LineVec,ofRectangle(0.0,0.0,ScreenX,ScreenY));
            
            break;
         
        default:
            break;
    }
    cvReleaseImage(&EdgeMap);
}
