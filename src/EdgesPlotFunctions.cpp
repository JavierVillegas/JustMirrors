//
//  EdgesPlotFunctions.cpp
//  Defense
//
//  Created by Javier Villegas on 6/5/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"


void defense::PlotLines(vector<ofVec2f> TheLines,ofRectangle RectLimits){
  
    vector<ofVec2f> PlotLineArray;


    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    ofSetColor(100,0,0,30); 
    glPushMatrix();
      ofTranslate(RectLimits.x,RectLimits.y);
      ofScale(RectLimits.width/Nx, RectLimits.height/Ny);
    for (int k=0;k<TheLines.size();k++){
        
        PlotLineArray.clear();
        float tempx,tempy;
        float cosT = cos(TheLines[k].x);
        float sinT = sin(TheLines[k].x);
        float rho = TheLines[k].y;
         

        // 4 cases
        
        if (cosT!=0){
            tempx=(rho -Ny*sinT)/cosT;
            if ((tempx>0)&&(tempx<Nx)){
                PlotLineArray.push_back(ofVec2f(tempx,Ny));
            }
            tempx=(rho)/cosT;
            if ((tempx>0)&&(tempx<Nx)){
                PlotLineArray.push_back(ofVec2f(tempx,-0));
            }      
        }
        if (sinT!=0){
            tempy=rho/sinT;
            if ((tempy>0)&&(tempy<Ny)){
                PlotLineArray.push_back(ofVec2f(0,tempy));
            }
            tempy=(rho -Nx*cosT)/sinT;
            if ((tempy>0)&&(tempy<Ny)){
                PlotLineArray.push_back(ofVec2f(Nx,tempy));
            }      
        }
        
        if(PlotLineArray.size()==2){
            ofLine(PlotLineArray[0].x,PlotLineArray[0].y,
                   PlotLineArray[1].x,PlotLineArray[1].y);
        }
        
        
    }
    glPopMatrix();
      glDisable(GL_BLEND); 

    
}
     
    
 
