//
//  DensityRelatedFunctions.cpp
//  Defense
//
//  Created by Javier Villegas on 6/5/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"
void defense::DensitySlide(){
    
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0 );

    ofRectangle RectLimits;
    
//    RectLimits.x =(RectOut.getCenter()).x - RectOut.width/4.0;
//    RectLimits.y=(RectOut.getCenter()).y - RectOut.height/4.0;
//    RectLimits.width=RectOut.width/2.0;
//    RectLimits.height=RectOut.height/2.0;
 
    RectLimits.x =0.0;
    RectLimits.y=10.0;
    RectLimits.width=ScreenX;
    RectLimits.height=ScreenY;
    
    glPushMatrix();
    
    ofTranslate(RectLimits.x, RectLimits.y);
    ofScale(RectLimits.width/Nx,RectLimits.height/Ny);

    
    for (int k=0; k<PointsList.size(); k++) {
        
        ofCircle(PointsList[k].x, PointsList[k].y, 4);
        
    }
    glPopMatrix();
    
}

void defense::SortPointsToPlot(){
    SortedPoints.clear();
    ofVec2f CurrentPoint;
    int NextIndex;

  
        CurrentPoint.x = Nx/2.0;
        CurrentPoint.y = Ny/2.0;
        float minDista = 100000000;
    for (int k=0; k<PointsList.size(); k++) {
        float TheDista =CurrentPoint.distanceSquared(PointsList[k]);
        
        if (TheDista < minDista){
            minDista =TheDista;
            NextIndex = k;
        }
        
    }
        while (PointsList.size()>0) {
            CurrentPoint = PointsList[NextIndex];
            SortedPoints.push_back(CurrentPoint);
            PointsList.erase(PointsList.begin()+NextIndex);
            float minDista = 100000000;
            for (int k=0; k<PointsList.size(); k++) {
                float TheDista =CurrentPoint.distanceSquared(PointsList[k]);
                
                if (TheDista < minDista){
                    minDista =TheDista;
                     NextIndex = k;
                }
            }
            
            
        }
    
}







void defense::ConnectednessSlide(int CMode){
    
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0 );

    ofRectangle RectLimits;
    
//    RectLimits.x =(RectOut.getCenter()).x - RectOut.width/4.0;
//    RectLimits.y=(RectOut.getCenter()).y - RectOut.height/4.0;
//    RectLimits.width=RectOut.width/2.0;
//    RectLimits.height=RectOut.height/2.0;

    RectLimits.x =0.0;
    RectLimits.y=10.0;
    RectLimits.width=ScreenX;
    RectLimits.height=ScreenY;
    
//    glEnable(GL_BLEND);
//    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    ofSetColor(0,0,0,30);
    
    glPushMatrix();
             ofSetLineWidth(4);
    ofTranslate(RectLimits.x, RectLimits.y);
    ofScale(RectLimits.width/Nx,RectLimits.height/Ny);
    if (CMode==0) {

        glBegin(GL_LINE_STRIP);
            for (int k=0; k<SortedPoints.size(); k++) {
                glVertex2f(SortedPoints[k].x,SortedPoints[k].y);
            }
        glEnd();
    }   
    else if (CMode==1){
        PlotIntensityDist();
    }
    else{
        ofSetLineWidth(1);
    
        PlotCirclesTest();
    }
    
    ofSetLineWidth(1);
        
    glPopMatrix();
//        glDisable(GL_BLEND);
    
}

//void defense::ConnectednessSlide(int CMode){
//    
//    
//    ofRectangle RectOut;
//    RectOut = OneBigRect();
//    ofSetColor(0, 0, 0 );
//  
//    ofRectangle RectLimits;
//    
//    RectLimits.x =(RectOut.getCenter()).x - 2*RectOut.width/4.0;
//    RectLimits.y=(RectOut.getCenter()).y - 2.5*RectOut.height/4.0;
//    RectLimits.width=2.2*RectOut.width/2.0;
//    RectLimits.height=2.2*RectOut.height/2.0;
//    
//    
//    
//    ofClear(255, 255, 255);
    
    //    glEnable(GL_BLEND);
    //    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //    ofSetColor(0,0,0,30);
    
    

 
    //  
    
    
    
//if (booleanforCapture==true){   
//    
//    glPushMatrix();
//    
//    ofTranslate(RectLimits.x, RectLimits.y);
//    ofScale(RectLimits.width/Nx,RectLimits.height/Ny);
//    ofFill();
//    for (int k=0; k<SortedPoints.size(); k++) {
//        ofCircle(SortedPoints[k].x, SortedPoints[k].y, 4);
//    }
//    ofSaveScreen("circles.png");
//    
//    ofClear(255, 255, 255);
//    
//    glBegin(GL_LINE_STRIP);
//    for (int k=0; k<SortedPoints.size(); k++) {
//        glVertex2f(SortedPoints[k].x,SortedPoints[k].y);
//    }
//    glEnd();
//  
//    ofSaveScreen("LasLineas.png");
//    
//    ofClear(255, 255, 255);
//    
//        PlotIntensityDist();
// 
//    ofSaveScreen("Intensities.png");
//    
//    ofClear(255, 255, 255);        
//        PlotCirclesTest();
//    ofSaveScreen("Bolas.png");
//    glPopMatrix();
//   
//    booleanforCapture = false;
//}
    
    
//}



void defense::PlotIntensityDist(){
    
    float Th =200+800*Slider1/127.0;
    
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    for (int k=0; k<SortedPoints.size()-1; k++) {
        for (int q= k+1; q<SortedPoints.size(); q++) {
            
            float TheDista =SortedPoints[k].distanceSquared(SortedPoints[q]);
            if (TheDista <Th) {
                ofSetColor(0, 0, 0, 255*(1.0-TheDista/Th));
                ofLine(SortedPoints[k].x, SortedPoints[k].y, SortedPoints[q].x, SortedPoints[q].y);
            }
        }
    }
   glDisable(GL_BLEND); 

}

void defense::PlotCirclesTest(){
    
    float Th =200+800*Slider1/127.0;
    float MinDista = 100000000000.0;
    ofNoFill();
    for (int k=0; k<SortedPoints.size(); k++) {
        MinDista = 100000000000.0;
        for (int q= 0; q<SortedPoints.size(); q++) {
            
            float TheDista =SortedPoints[k].distanceSquared(SortedPoints[q]);
            if ((TheDista <MinDista)&&(k!=q)) {
                MinDista = TheDista;
            }

        }
        if (MinDista<100000000000.0){
        ofCircle(SortedPoints[k].x, SortedPoints[k].y, sqrt(MinDista/2.0f));
        }
    } 
    ofFill();
}


