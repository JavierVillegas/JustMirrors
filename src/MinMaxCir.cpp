//
//  MinMaxCir.cpp
//  Defense
//
//  Created by Javier Villegas on 6/5/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

//void defense::MinMaxCirUpdate(){
//    
//    float G_ka = 3.35;
//    float G_Dammping = 2.45;
//    float dt = 0.1;
//    ofFile lafile;
//    char * pointBuff;
//    Float32 Objfloat[2*Ncirs];
//    ofVec2f XObs;
//    ofVec2f TempVel;
//    // opening the file of objects
//    lafile.open(ofToDataPath("TemporalCoherence/MinSumcir/minsum" + ofToString(CircsFrameCount)+".bin"),
//                ofFile::ReadOnly, false); 
//    ofBuffer buffy = lafile.readToBuffer();
//    lafile.close();
//    pointBuff = buffy.getBinaryBuffer();
//    memcpy(Objfloat, pointBuff, 2*Ncirs*sizeof(Float32));
//  
//     for (int oc =0; oc < Ncirs; oc++) {
//    
//         XObs.x = Objfloat[Ncirs+oc];
//         XObs.y = Objfloat[oc]; 
//         
//         XObs -= TheCircPos[oc];
//         XObs *=G_ka;
//         TempVel = VelCirc[oc]*G_Dammping;
//         XObs-= TempVel;
//         XObs*=dt;
//         VelCirc[oc]+=XObs;
//         XObs = VelCirc[oc]*dt;
//         TheCircPos[oc]+=XObs;
//    }
//    
//    
//    
//    
//    
//}


//void defense::MinMaxCirDraw(){
    
//   ofRectangle RectOut;
//    RectOut = OneBigRect();
//    ofSetColor(0, 0, 0);
//    Fuentes[3].drawString("Example 1: Non-coherent circles",
//                          RectOut.x,RectOut.y + RectOut.height*.1);
//
//    ofRectangle RectLimits;
//    
//    RectLimits.x =(RectOut.getCenter()).x - 2*RectOut.width/4.0;
//    RectLimits.y=(RectOut.getCenter()).y - 1.8*RectOut.height/4.0;
//    RectLimits.width=1.8*RectOut.width/2.0;
//    RectLimits.height=1.8*RectOut.height/2.0;
//    glPushMatrix();
//    
//    ofTranslate(RectLimits.x, RectLimits.y);
//    ofScale(RectLimits.width/Nx,RectLimits.height/Ny);
//
//    // ploting the object array
//  
//    for (int k=0;k<Ncirs;k++){
//        ofCircle(TheCircPos[k].x , TheCircPos[k].y, 4);        
//    }
//    glPopMatrix();
//}