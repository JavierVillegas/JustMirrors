//
//  Hormigas.cpp
//  Defense
//
//  Created by Javier Villegas on 6/7/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"
void defense::HormigasUpdate(){

    float ThDis =13.4;
//    KtarHormigas = 20.0;
//    KdamHormigas = 1.05;
    G_QualityHormigas=.001;
    G_minDistanceHormigas=4 + 4*(int)Slider1/127.0;
    
    float dt = 0.25;
    
    TheTargetsHormigas.clear();
    IplImage* eig_image = cvCreateImage( cvSize(Nx,Ny), IPL_DEPTH_32F, 1 );
    IplImage* tmp_image = cvCreateImage( cvSize(Nx,Ny), IPL_DEPTH_32F, 1 );       
    
    
    int corner_count = NobHormigas;
    CvPoint2D32f* cornersA = new CvPoint2D32f[ NobHormigas ];
    
    
    cvGoodFeaturesToTrack(TheInputGray,eig_image, tmp_image,cornersA,&corner_count,
                          G_QualityHormigas,G_minDistanceHormigas,0,3,0,0);
    
    for (int k=0;k<corner_count;k++){
        
        TheTargetsHormigas.push_back(ofVec2f(cornersA[k].x,cornersA[k].y));
    }
    
    
    // reseting
    
    if (!TheTargetsHormigas.empty()){     
        
        for(int i =0;i< NobHormigas;i++){
            TargIndHormigas[i]=-1;
        }
        
        for (int kt=0; kt<TheTargetsHormigas.size(); kt++) {
            float MinDis =10000000;
            int MinIndi =-5;
            for (int ko=0; ko<NobHormigas; ko++) {
                
                ofVec2f ErrorVec;
                ErrorVec = TheTargetsHormigas[kt]-TheObjectsHormigas[ko];
                float dis = ErrorVec.length();
                if ((dis < MinDis)&&(TargIndHormigas[ko]==-1)){
                    MinIndi = ko;  
                    MinDis = dis;
                }
            }
            TargIndHormigas[MinIndi] = kt;
        }
        
        
        for (int ko=0; ko<NobHormigas; ko++) {
            
            ofVec2f UpdateVec;
            float MinDis =10000000;
            int MinIndi =-5;
            
            if (TargIndHormigas[ko]==-1) {
                MinDis =10000000;
                for (int kt=0; kt<TheTargetsHormigas.size(); kt++) {
                    ofVec2f ErrorVec;
                    ErrorVec = TheTargetsHormigas[kt]-TheObjectsHormigas[ko];
                    float dis = ErrorVec.length();
                    if (dis < MinDis){
                        MinDis = dis;  
                        MinIndi = kt;
                    }
                    
                }
                         
                TargIndHormigas[ko] = MinIndi;
            }
            
            UpdateVec = TheTargetsHormigas[TargIndHormigas[ko]]-TheObjectsHormigas[ko];
            float newDis = UpdateVec.length();
            UpdateVec.normalize();
            
            
            ofVec2f acc;
            if (newDis < ThDis){
                acc = (newDis/10.0)*(KtarHormigas*UpdateVec) - KdamHormigas*TheVelocitiesHormigas[ko];
            }
            else{
                acc = (KtarHormigas*UpdateVec) - KdamHormigas*TheVelocitiesHormigas[ko];
            }
            TheVelocitiesHormigas[ko] = TheVelocitiesHormigas[ko] - (-dt)*acc;
            TheObjectsHormigas[ko]  =  TheObjectsHormigas[ko] - (-dt)*TheVelocitiesHormigas[ko];
        }
        
    }// closing the  if from target non empty
    
    
    
    cvReleaseImage(&eig_image);
    cvReleaseImage(&tmp_image);
}

void defense::HormigasDraw(int HMode){

    ofRectangle RectOut;
    RectOut = OneBigRect();
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    ofClear(255,255,255,255);
//    ofSetColor(0, 0, 0 );
//    Fuentes[1].drawString("Ambiguous Sequences",
//                          RectOut.x,RectOut.y + RectOut.height*.02);
//    
//    Fuentes[3].drawString("Ants substituting detected corners",
//                          RectOut.x,RectOut.y + RectOut.height*.1);
    
    ofVec2f CurrentCorner(320,10);
    if (HMode>0) {
        ofSetColor(255,255,255,2*Slider5);
   //  ofSetColor(255,255,255,255*3/4.0);
        FondoHormigas.draw(0,0,ScreenX,ScreenY);
    }
    
    glPushMatrix();
    ofScale(ScreenX/Nx, (float)ScreenY/(float)Ny);
//    ofSetColor(2*Slider4,2*Slider4,2*Slider4,255);
    ofSetColor(255*(.5),255*(.5),255*(.5),255);
    for (int k=0; k < NobHormigas;k++){
                
        CurrentCorner = TheObjectsHormigas[k];
        glPushMatrix();  
        ofTranslate(CurrentCorner.x, CurrentCorner.y);
        if (TheVelocitiesHormigas[k].squareLength()>20) {
            ofRotate(180-180*atan2(TheVelocitiesHormigas[k].x, TheVelocitiesHormigas[k].y)/(CV_PI));
            AntState[k]++;
            if (AntState[k]>5) {
                AntState[k]=0;
            }
        }
        else{
            ofRotate(RandAngleHormigas[k]);
        }
        
        if(HMode==2){
            ofScale(.08,.08);    
            LasHormigas[AntState[k]].draw(-LasHormigas[AntState[k]].width/2.0,-LasHormigas[AntState[k]].height/2.0);
        }
        else{
            ofSetColor(5,5,255,255);
            ofEllipse(0,0,4,4);
        }
        glPopMatrix();  
        
    }    
    
    
    glPopMatrix();  
  //  colorImg.draw(0,0,320,240);
    
    glDisable(GL_BLEND);
}



