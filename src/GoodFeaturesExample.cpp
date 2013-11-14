//
//  GoodFeaturesExample.cpp
//  Defense
//
//  Created by Javier Villegas on 6/6/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::GoodFeaturesUpdate(){

float dt = 0.25;
    float ThDis=13.4;
    KtarGood = 19.25;
    KdamGood = 1.05;

    TheTargetsGood.clear();


    IplImage* eig_image = cvCreateImage( cvSize(Nx,Ny), IPL_DEPTH_32F, 1 );
    IplImage* tmp_image = cvCreateImage( cvSize(Nx,Ny), IPL_DEPTH_32F, 1 ); 
    int corner_count = NobGood;
    CvPoint2D32f* cornersA = new CvPoint2D32f[ NobGood ];
    
    
    cvGoodFeaturesToTrack(TheInputGray,eig_image, tmp_image,cornersA,&corner_count,
                          0.01,5.0,0,3,0,.04);
    for (int k=0;k<corner_count;k++){
        
        TheTargetsGood.push_back(ofVec2f(cornersA[k].x,cornersA[k].y));
        
    }
    if (!TheTargetsGood.empty()){     
        
        for(int i =0;i< NobGood;i++){
            TargIndGood[i]=-1;
        }
        
        for (int kt=0; kt<TheTargetsGood.size(); kt++) {
            float MinDis =10000000;
            int MinIndi =-5;
            for (int ko=0; ko<NobGood; ko++) {
                
                ofVec2f ErrorVec;
                ErrorVec = TheTargetsGood[kt]-TheObjectsGood[ko];
                float dis = ErrorVec.length();
                if ((dis < MinDis)&&(TargIndGood[ko]==-1)){
                    MinIndi = ko;  
                    MinDis = dis;
                }
            }
            TargIndGood[MinIndi] = kt;
        }
        
        
        for (int ko=0; ko<NobGood; ko++) {
            
            float MinHits = 10000;
            ofVec2f UpdateVec;
            float MinDis =10000;
            int MinIndi =0;
            
            if (TargIndGood[ko]==-1) {
                MinDis =10000;
                for (int kt=0; kt<TheTargetsGood.size(); kt++) {
                    ofVec2f ErrorVec;
                    ErrorVec = TheTargetsGood[kt]-TheObjectsGood[ko];
                    float dis = ErrorVec.length();
                    if (dis < MinDis){
                        MinDis = dis;  
                        MinIndi = kt;
                    }
                    
                }
                        
                TargIndGood[ko] = MinIndi;
            }
            
            UpdateVec = TheTargetsGood[TargIndGood[ko]]-TheObjectsGood[ko];
            float newDis = UpdateVec.length();
            UpdateVec.normalize();
            
            
            ofVec2f acc;
            if (newDis < ThDis){
                acc = (newDis/10.0)*(KtarGood*UpdateVec) - KdamGood*TheVelocitiesGood[ko];
            }
            else{
                acc = (KtarGood*UpdateVec) - KdamGood*TheVelocitiesGood[ko];
            }
            TheVelocitiesGood[ko] = TheVelocitiesGood[ko] - (-dt)*acc;
            TheObjectsGood[ko]  =  TheObjectsGood[ko] - (-dt)*TheVelocitiesGood[ko];
        }
        
    }// closing the  if from target non empty
    
    
    
    cvReleaseImage(&eig_image);
    cvReleaseImage(&tmp_image);
    
}


void defense::GoodFeaturesDraw(){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0);
    Fuentes[3].drawString("Example 2, Good features to track:",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    
    
    ofRectangle RectLimits;
    
    RectLimits.x =(RectOut.getCenter()).x - 3.5*RectOut.width/8.0;
    RectLimits.y=(RectOut.getCenter()).y - RectOut.height/4.0;
    RectLimits.width=1.5*RectOut.width/4.0;
    RectLimits.height=RectOut.height/2.0;
    
    ofVec2f CurrentCorner(320,10);

    ofSetColor(255,255,255);
    
        colorImg.draw(RectLimits);
    
    //Non coherent:   
    glPushMatrix();
    ofTranslate(RectLimits.x, RectLimits.y);
    ofScale(RectLimits.width/Nx,RectLimits.height/Ny);
    
    ofSetColor(255,0,0);
    for (int k=0; k < TheTargetsGood.size();k++){
        ofEllipse(TheTargetsGood[k].x,TheTargetsGood[k].y , 10, 10);
    }
    glPopMatrix();
    
        RectLimits.x =(RectOut.getCenter()).x + .5*RectOut.width/8.0;
    
    
    ofSetColor(0,0,0);
    
    glPushMatrix();
    ofTranslate(RectLimits.x, RectLimits.y);
    ofScale(RectLimits.width/Nx,RectLimits.height/Ny);

    for (int k=0; k < NobGood;k++){
        ofEllipse(TheObjectsGood[k].x, TheObjectsGood[k].y, 6, 6);     
    }
        glPopMatrix();
    
 
    
}


