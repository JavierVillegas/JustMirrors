//
//  NCCir.cpp
//  Defense
//
//  Created by Javier Villegas on 6/5/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::NCCirUpdate(){
    
    ofFile lafile;
    char * pointBuff;
    Float32 Objfloat[2*Ncirs];
    // opening the file of objects
    lafile.open(ofToDataPath("TemporalCoherence/NCcir/circs" + ofToString(CircsFrameCount)+".bin"),
                ofFile::ReadOnly, false); 
    ofBuffer buffy = lafile.readToBuffer();
    lafile.close();
    pointBuff = buffy.getBinaryBuffer();
    memcpy(Objfloat, pointBuff, 2*Ncirs*sizeof(Float32));
    // filling the object array
    for (int k=0;k<Ncirs;k++){
        
        TheCircPos[k].x = Objfloat[Ncirs+k];
        TheCircPos[k].y = Objfloat[k];
        
    }
}


void defense::CirMatched(int CircSet){
    

    float dt = 0.1;
    ofFile lafile;
    char * pointBuff;
    Float32 Objfloat[2*Ncirs];
    ofVec2f XObs;
    ofVec2f TempVel;
  // file open
    if (CircSet==0) {
    lafile.open(ofToDataPath("TemporalCoherence/NCcir/circs" + ofToString(CircsFrameCount)+".bin"),
                ofFile::ReadOnly, false); 
    }
    else if (CircSet==1){
    lafile.open(ofToDataPath("TemporalCoherence/MinSumcir/minsum" + ofToString(CircsFrameCount)+".bin"),
                    ofFile::ReadOnly, false); 
    }
    else if (CircSet==2){
        lafile.open(ofToDataPath("TemporalCoherence/BottleCir/BottleCirc" + ofToString(CircsFrameCount)+".bin"),
                    ofFile::ReadOnly, false); 
    }
    else if (CircSet==3){
        lafile.open(ofToDataPath("TemporalCoherence/SpaceTime/SpaceTime" + ofToString(CircsFrameCount)+".bin"),
                    ofFile::ReadOnly, false); 
    }
    ofBuffer buffy = lafile.readToBuffer();
    lafile.close();
    pointBuff = buffy.getBinaryBuffer();
    memcpy(Objfloat, pointBuff, 2*Ncirs*sizeof(Float32));

    for (int oc =0; oc < Ncirs; oc++) {
        
        XObs.x = Objfloat[Ncirs+oc];
        XObs.y = Objfloat[oc]; 
        
        XObs -= TheCircPos[oc];
        XObs *=G_ka;
        TempVel = VelCirc[oc]*G_Dammping;
        XObs-= TempVel;
        XObs*=dt;
        VelCirc[oc]+=XObs;
        XObs = VelCirc[oc]*dt;
        TheCircPos[oc]+=XObs;
    }
    
    
}


void defense::NCCirDraw(string TheText){
    
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0);
    // temp for video
    Fuentes[1].drawString("Temporal Coherence Algorithms",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    Fuentes[3].drawString(TheText,
                          RectOut.x,RectOut.y + RectOut.height*.2);

    ofRectangle RectLimits;
    
    RectLimits.x =(RectOut.getCenter()).x - 2*RectOut.width/4.0;
    RectLimits.y=(RectOut.getCenter()).y - 1.8*RectOut.height/4.0;
    RectLimits.width=1.8*RectOut.width/2.0;
    RectLimits.height=1.8*RectOut.height/2.0;
    glPushMatrix();
    
    ofTranslate(RectLimits.x, RectLimits.y);
    ofScale(RectLimits.width/Nx,RectLimits.height/Ny);

    // ploting the object array
  
    for (int k=0;k<Ncirs;k++){
        ofCircle(TheCircPos[k].x , TheCircPos[k].y, 4);        
    }
    glPopMatrix();
}