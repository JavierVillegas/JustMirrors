//
//  PlotContours.cpp
//  Defense
//
//  Created by Javier Villegas on 6/4/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::PlotContours(ofRectangle RectLimits,int CMode){
    
    
//    float TheX;
//   float Thesize1 = ArrayOfContours.size();

 //   CvMat * OtraTemp;
  //  OtraTemp = cvCreateMat(64, 1, CV_32FC2);
//    OtraTemp = ArrayOfContours.back();
//    ArrayOfContours.pop_back();
//    TheX = ((float*)(OtraTemp->data.ptr + OtraTemp->step*0))[10]; 
    
    if (CMode==1) {
        glEnable(GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        ofSetColor(0,0,0,50);
    }
    
    
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    glPushMatrix();
    ofSetLineWidth(4);
    ofTranslate(RectLimits.x,RectLimits.y);
    ofScale(RectLimits.width/Nx, RectLimits.height/Ny);
    for(int k=0;k<ArrayOfContours.size();k++){
        if (CMode==0) {
            ofSetColor(ContourGray[k], ContourGray[k], ContourGray[k]);
        }
    ofBeginShape();
  
     for (int q=0; q < 64;q++){

       ofVertex((ArrayOfContours[k][q]).x, (ArrayOfContours[k][q]).y);
      }
    ofEndShape(true);
    }
    ofSetLineWidth(1);
    glPopMatrix(); 
    if (CMode==1) {
  glDisable(GL_BLEND); 
    }
}
