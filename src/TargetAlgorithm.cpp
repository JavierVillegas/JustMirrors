//
//  TargetAlgorithm.cpp
//  Defense
//
//  Created by Javier Villegas on 6/6/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::TargetAlgorithmUpdate(int TMode){

    float ThDis =13.4;
    KtarTgDemo = 19.25;
    KdamTgDemo = 1.05;
     float dt = 0.25;

        
        
//        for(int i =0;i< NTARTargDemo;i++){
//            TargIndTargDemo[i]=-1;
//        }
        
        for (int kt=0; kt<NTARTargDemo; kt++) {
            float MinDis =10000000;
            int MinIndi =-5;
            for (int ko=0; ko<NOBJTargDemo; ko++) {
                
                ofVec2f ErrorVec;
                ErrorVec = TheTargetsTargDemo[kt]-TheObjectsTargDemo[ko];
                float dis = ErrorVec.length();
                if ((dis < MinDis)&&(TargIndTargDemo[ko]==-1)){
                    MinIndi = ko;  
                    MinDis = dis;
                }
            }
            TargIndTargDemo[MinIndi] = kt;
        }
        
        
        for (int ko=0; ko<NOBJTargDemo; ko++) {
            
            ofVec2f UpdateVec;
            float MinDis =10000000;
            int MinIndi =-5;
            
            if (TargIndTargDemo[ko]==-1) {
                MinDis =100000;
                for (int kt=0; kt<NTARTargDemo; kt++) {
                    ofVec2f ErrorVec;
                    ErrorVec = TheTargetsTargDemo[kt]-TheObjectsTargDemo[ko];
                    float dis = ErrorVec.length();
                    if (dis < MinDis){
                        MinDis = dis;  
                        MinIndi = kt;
                    }
                    
                }
                
                    
                TargIndTargDemo[ko] = MinIndi;
            }
            
            UpdateVec = TheTargetsTargDemo[TargIndTargDemo[ko]]-TheObjectsTargDemo[ko];
            float newDis = UpdateVec.length();
            UpdateVec.normalize();
            ofVec2f acc;
            if (newDis < ThDis){
                acc = (newDis/10.0)*(KtarTgDemo*UpdateVec) - KdamTgDemo*TheVelocitiesTargDemo[ko];
            }
            else{
                acc = (KtarTgDemo*UpdateVec) - KdamTgDemo*TheVelocitiesTargDemo[ko];
            }
            if (TMode==0) {
                acc=ofVec2f(0.0, 0.0);
            }
            
            TheVelocitiesTargDemo[ko] = TheVelocitiesTargDemo[ko] - (-dt)*acc;
            TheObjectsTargDemo[ko]  =  TheObjectsTargDemo[ko] - (-dt)*TheVelocitiesTargDemo[ko];
        }
}


void defense::TargetAlgorithmDraw(){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0);
    // temp for video
    Fuentes[1].drawString("Temporal Coherence Algorithms",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    Fuentes[3].drawString("The Attractors Based Algorithm:",
                          RectOut.x,RectOut.y + RectOut.height*.2);
    Fuentes[3].drawString("Black dots are attracted by the red stars",
                          RectOut.x,RectOut.y + RectOut.height*.3);

    ofRectangle RectLimits;
    
    RectLimits.x =(RectOut.getCenter()).x - 1.4*RectOut.width/4.0;
    RectLimits.y=(RectOut.getCenter()).y - .8*RectOut.height/4.0;
    RectLimits.width=1.4*RectOut.width/2.0;
    RectLimits.height=1.4*RectOut.height/2.0;
    
    
    glPushMatrix();
    
    ofTranslate(RectLimits.x, RectLimits.y);
    ofScale(RectLimits.width/Nx,RectLimits.height/Ny);
    
    // ploting the Targets
    ofSetColor(200, 0, 0);
    for (int k=0;k<NTARTargDemo;k++){
        PlotStar(TheTargetsTargDemo[k].x, TheTargetsTargDemo[k].y, 5, 5,10);
        //ofRect(TheTargetsTargDemo[k].x -5, TheTargetsTargDemo[k].y-5,10,10);        
    }
    ofSetColor(0, 0, 0);
    for (int k=0;k<NOBJTargDemo;k++){
        ofCircle(TheObjectsTargDemo[k].x , TheObjectsTargDemo[k].y,3);        
    }
    glPopMatrix();






}


