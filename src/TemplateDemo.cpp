//
//  TemplateDemo.cpp
//  Defense
//
//  Created by Javier Villegas on 6/7/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"


void defense::TemplateDemoUpdate(){

    ofVec2f XObs;
    float AngleObs;
    ofVec2f TempVel;
    float TempW;  
    float dt =0.1;
    
    
     G_kaTemplates= 3+ 8*(Slider1)/127.0;
    G_DammpingTemplates= 0.45+ 5*(Slider2)/127.0;
    G_NewTargetInterpol= 2 + (int)(20*(Slider3)/127.0);
     G_PowTemplates = .2 +  (6*(Slider4)/127.0);
    
    // if a new frame ,fill the intermediate steps
    
    if (G_InterpolTemplates==0) {
        
        
        for (int oc =0; oc < NobTemplates; oc++) {
            (TheState[oc]).clear();
            int * ThePath;
            int nextState = (G_frameCounterTemplates==NEndFame)?NiniFrame:G_frameCounterTemplates+1;
            ThePath = ViterbiStates((TheBins[oc][G_frameCounterTemplates-NiniFrame]).w,
                                    (TheBins[oc][nextState-NiniFrame]).w,
                                    G_CurrentTargetInterpol);
            for (int st =0; st<G_CurrentTargetInterpol; st++) {
                (TheState[oc]).push_back(ThePath[st]);
                //            (TheState[oc]).push_back((TheBins[oc][0]).w);
            }
            
        }
    }
    
    
    
    
    for (int oc =0; oc < NobTemplates; oc++) {
        
        XObs.x =  (TheBins[oc][G_frameCounterTemplates-NiniFrame]).x;
        XObs.y =  (TheBins[oc][G_frameCounterTemplates-NiniFrame]).y;
        AngleObs = (TheBins[oc][G_frameCounterTemplates-NiniFrame]).z;
        
        XObs -= XTemplates[oc];   
        
        AngleObs -=TheAngleTemplates[oc];
        if (AngleObs>180){ AngleObs=360-AngleObs;}
        if (AngleObs<-180){ AngleObs=360+AngleObs;}
        
        XObs *=G_kaTemplates;
        AngleObs*=G_kaTemplates;
        
        TempVel = VelTemplates[oc]*G_DammpingTemplates;
        TempW = WTemplates[oc]*G_DammpingTemplates;
        
        XObs-= TempVel;
        AngleObs-=TempW;
        
        XObs*=dt;
        AngleObs*=dt;
        
        WTemplates[oc]*=.9;
        
        VelTemplates[oc]+=XObs;
        WTemplates[oc]+=AngleObs;
        
        XObs = VelTemplates[oc]*dt;
        AngleObs = WTemplates[oc]*dt;
        
        XTemplates[oc]+=XObs;
        TheAngleTemplates[oc]+=AngleObs;
    }
    

    
    
    

}

void defense::TemplateDemoDraw(){
    
    ofImage toDraw;
    
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0 );
//    Fuentes[0].drawString("Ambiguous Images",
//                          RectOut.x,RectOut.y + RectOut.height*.1);
    Fuentes[0].drawString("Two-level Animation",
                          RectOut.x,RectOut.y + RectOut.height*.1);

    //    Fuentes[3].drawString("Viterbi interpolation and combinatorial matching",
//                          RectOut.x,RectOut.y + RectOut.height*.2);

    Fuentes[3].drawString("Combinatorial matching algorithm",
                          RectOut.x,RectOut.y + RectOut.height*.2);
    
    
    ofRectangle RectLimits;
    
    RectLimits.x =(RectOut.getCenter()).x - 1.5*RectOut.width/4.0;
    RectLimits.y=(RectOut.getCenter()).y - 1.2*RectOut.height/4.0;
    RectLimits.width=RectOut.width/2.0;
    RectLimits.height=RectOut.height/2.0;
    glPushMatrix();
    
    ofTranslate(RectLimits.x, RectLimits.y);
    ofScale(1.5*RectLimits.width/Nx,1.5*RectLimits.height/Ny);

    
    
    ofSetColor(255,255,255);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    for (int oc=0; oc <NobTemplates; oc++) {
        
        ofPushMatrix();
        ofTranslate(4*(XTemplates[oc]).x,4*(XTemplates[oc]).y);
        ofRotate(-(TheAngleTemplates[oc]));
        ofScale(.2,.2);
        
        Templates[TheState[oc][G_InterpolTemplates]].draw(-Templates[TheState[oc][G_InterpolTemplates]].width/2.0,
                                                 -Templates[TheState[oc][G_InterpolTemplates]].height/2.0);
        ofPopMatrix();
    }
    ofPopMatrix();
    
    
  G_InterpolTemplates++;
    if (G_InterpolTemplates==G_CurrentTargetInterpol) {
        
        G_frameCounterTemplates++;
        
        G_InterpolTemplates=0;
        G_CurrentTargetInterpol =G_NewTargetInterpol;
        if (G_frameCounterTemplates>NEndFame){
            G_frameCounterTemplates=NiniFrame;
        }
    }
    
   glDisable(GL_BLEND); 
}

int * defense::ViterbiStates(int ini,int last,int steps){
    
    
    float  Steps [NT][NT] = 
//    {{1, 1, 2, 3, 4, 1, 2, 3, 4,  5,  2,  3,  4,  5,  2,  3,  4,  5,  1,  2,  3,  4,  1, 2,  3,  4},
//        {1, 1, 1, 2, 3, 2, 1, 2, 3,  4,  3,  4,  5,  6,  3,  4,  5,  6,  2,  3,  4,  5,  2, 3,  4,  5},
//        {2, 1, 1, 1, 2, 3, 2, 1, 2,  3,  4,  5,  6,  7,  4,  5,  6,  7,  3,  4,  5,  6,  3, 4,  5,  6},
//        {3, 2, 1, 1, 1, 4, 3, 2, 1,  2,  5,  6,  7,  8,  5,  6,  7,  8,  4,  5,  6,  7,  4, 5,  6,  7},
//        {4, 3, 2, 1, 1, 5, 4, 3, 2,  1,  6,  7,  8,  9,  6,  7,  8,  9,  5,  6,  7,  8,  5, 6,  7,  8},
//        {1, 2, 3, 4, 5, 1, 1, 2, 3,  4,  1,  2,  3,  4,  1,  2,  3,  4,  2,  3,  4,  5,  2, 3,  4,  5},
//        {2, 1, 2, 3, 4, 1, 1, 1, 2,  3,  2,  3,  4,  5,  2,  3,  4,  5,  3,  4,  5,  6,  3, 4,  5,  6},
//        {3, 2, 1, 2, 3, 2, 1, 1, 1,  2,  3,  4,  5,  6,  3,  4,  5,  6,  4,  5,  6,  7,  4, 5,  6,  7},
//        {4, 3, 2, 1, 2, 3, 2, 1, 1,  1,  4,  5,  6,  7,  4,  5,  6,  7,  5,  6,  7,  8,  5, 6,  7,  8},
//        {5, 4, 3, 2, 1, 4, 3, 2, 1,  1,  5,  6,  7,  8,  5,  6,  7,  8,  6,  7,  8,  9,  6, 7,  8,  9},
//        {2, 3, 4, 5, 6, 1, 2, 3, 4,  5,  1,  1,  2,  3,  2,  3,  4,  5,  1,  2,  3,  4,  3, 4,  5,  6},
//        {3, 4, 5, 6, 7, 2, 3, 4, 5,  6,  1,  1,  1,  2,  3,  4,  5,  6,  2,  1,  2,  3,  4, 5,  6,  7},
//        {4, 5, 6, 7, 8, 3, 4, 5, 6,  7,  2,  1,  1,  1,  4,  5,  6,  7,  3,  2,  1,  2,  5, 6,  7,  8},
//        {5, 6, 7, 8, 9, 4, 5, 6, 7,  8,  3,  2,  1,  1,  5,  6,  7,  8,  4,  3,  2,  1,  6, 7,  8,  9},
//        {2, 3, 4, 5, 6, 1, 2, 3, 4,  5,  2,  3,  4,  5,  1,  1,  2,  3,  3,  4,  5,  6,  1, 2,  3,  4},
//        {3, 4, 5, 6, 7, 2, 3, 4, 5,  6,  3,  4,  5,  6,  1,  1,  1,  2,  4,  5,  6,  7,  2, 1,  2,  3},
//        {4, 5, 6, 7, 8, 3, 4, 5, 6,  7,  4,  5,  6,  7,  2,  1,  1,  1,  5,  6,  7,  8,  3, 2,  1,  2},
//        {5, 6, 7, 8, 9, 4, 5, 6, 7,  8,  5,  6,  7,  8,  3,  2,  1,  1,  6,  7,  8,  9,  4, 3,  2,  1},
//        {1, 2, 3, 4, 5, 2, 3, 4, 5,  6,  1,  2,  3,  4,  3,  4,  5,  6,  1,  1,  2,  3,  2, 3,  4,  5},
//        {2, 3, 4, 5, 6, 3, 4, 5, 6,  7,  2,  1,  2,  3,  4,  5,  6,  7,  1,  1,  1,  2,  3, 4,  5,  6},
//        {3, 4, 5, 6, 7, 4, 5, 6, 7,  8,  3,  2,  1,  2,  5,  6,  7,  8,  2,  1,  1,  1,  4, 5,  6,  7},
//        {4, 5, 6, 7, 8, 5, 6, 7, 8,  9,  4,  3,  2,  1,  6,  7,  8,  9,  3,  2,  1,  1,  5, 6,  7,  8},
//        {1, 2, 3, 4, 5, 2, 3, 4, 5,  6,  3,  4,  5,  6,  1,  2,  3,  4,  2,  3,  4,  5,  1, 1,  2,  3},
//        {2, 3, 4, 5, 6, 3, 4, 5, 6,  7,  4,  5,  6,  7,  2,  1,  2,  3,  3,  4,  5,  6,  1, 1,  1,  2},
//        {3, 4, 5, 6, 7, 4, 5, 6, 7,  8,  5,  6,  7,  8,  3,  2,  1,  2,  4,  5,  6,  7,  2, 1,  1,  1},
//        {4, 5, 6, 7, 8, 5, 6, 7, 8,  9,  6,  7,  8,  9,  4,  3,  2,  1,  5,  6,  7,  8,  3, 2,  1,  1}};
    {{.4, 1, 2, 3, 4, 1, 2, 3, 4,  5,  2,  3,  4,  5,  2,  3,  4,  5,  1,  2,  3,  4,  1, 2,  3,  4},
        {1, .4, 1, 2, 3, 2, 1, 2, 3,  4,  3,  4,  5,  6,  3,  4,  5,  6,  2,  3,  4,  5,  2, 3,  4,  5},
        {2, 1, .4, 1, 2, 3, 2, 1, 2,  3,  4,  5,  6,  7,  4,  5,  6,  7,  3,  4,  5,  6,  3, 4,  5,  6},
        {3, 2, 1, .4, 1, 4, 3, 2, 1,  2,  5,  6,  7,  8,  5,  6,  7,  8,  4,  5,  6,  7,  4, 5,  6,  7},
        {4, 3, 2, 1, .4, 5, 4, 3, 2,  1,  6,  7,  8,  9,  6,  7,  8,  9,  5,  6,  7,  8,  5, 6,  7,  8},
        {1, 2, 3, 4, 5, .4, 1, 2, 3,  4,  1,  2,  3,  4,  1,  2,  3,  4,  2,  3,  4,  5,  2, 3,  4,  5},
        {2, 1, 2, 3, 4, 1, .4, 1, 2,  3,  2,  3,  4,  5,  2,  3,  4,  5,  3,  4,  5,  6,  3, 4,  5,  6},
        {3, 2, 1, 2, 3, 2, 1, .4, 1,  2,  3,  4,  5,  6,  3,  4,  5,  6,  4,  5,  6,  7,  4, 5,  6,  7},
        {4, 3, 2, 1, 2, 3, 2, 1, .4,  1,  4,  5,  6,  7,  4,  5,  6,  7,  5,  6,  7,  8,  5, 6,  7,  8},
        {5, 4, 3, 2, 1, 4, 3, 2, 1,  .4,  5,  6,  7,  8,  5,  6,  7,  8,  6,  7,  8,  9,  6, 7,  8,  9},
        {2, 3, 4, 5, 6, 1, 2, 3, 4,  5,  .4,  1,  2,  3,  2,  3,  4,  5,  1,  2,  3,  4,  3, 4,  5,  6},
        {3, 4, 5, 6, 7, 2, 3, 4, 5,  6,  1,  .4,  1,  2,  3,  4,  5,  6,  2,  1,  2,  3,  4, 5,  6,  7},
        {4, 5, 6, 7, 8, 3, 4, 5, 6,  7,  2,  1,  .4,  1,  4,  5,  6,  7,  3,  2,  1,  2,  5, 6,  7,  8},
        {5, 6, 7, 8, 9, 4, 5, 6, 7,  8,  3,  2,  1,  .4,  5,  6,  7,  8,  4,  3,  2,  1,  6, 7,  8,  9},
        {2, 3, 4, 5, 6, 1, 2, 3, 4,  5,  2,  3,  4,  5,  .4,  1,  2,  3,  3,  4,  5,  6,  1, 2,  3,  4},
        {3, 4, 5, 6, 7, 2, 3, 4, 5,  6,  3,  4,  5,  6,  1,  .4,  1,  2,  4,  5,  6,  7,  2, 1,  2,  3},
        {4, 5, 6, 7, 8, 3, 4, 5, 6,  7,  4,  5,  6,  7,  2,  1,  .4,  1,  5,  6,  7,  8,  3, 2,  1,  2},
        {5, 6, 7, 8, 9, 4, 5, 6, 7,  8,  5,  6,  7,  8,  3,  2,  1,  .4,  6,  7,  8,  9,  4, 3,  2,  1},
        {1, 2, 3, 4, 5, 2, 3, 4, 5,  6,  1,  2,  3,  4,  3,  4,  5,  6,  .4,  1,  2,  3,  2, 3,  4,  5},
        {2, 3, 4, 5, 6, 3, 4, 5, 6,  7,  2,  1,  2,  3,  4,  5,  6,  7,  1,  .4,  1,  2,  3, 4,  5,  6},
        {3, 4, 5, 6, 7, 4, 5, 6, 7,  8,  3,  2,  1,  2,  5,  6,  7,  8,  2,  1,  .4,  1,  4, 5,  6,  7},
        {4, 5, 6, 7, 8, 5, 6, 7, 8,  9,  4,  3,  2,  1,  6,  7,  8,  9,  3,  2,  1,  .4,  5, 6,  7,  8},
        {1, 2, 3, 4, 5, 2, 3, 4, 5,  6,  3,  4,  5,  6,  1,  2,  3,  4,  2,  3,  4,  5,  .4, 1,  2,  3},
        {2, 3, 4, 5, 6, 3, 4, 5, 6,  7,  4,  5,  6,  7,  2,  1,  2,  3,  3,  4,  5,  6,  1, .4,  1,  2},
        {3, 4, 5, 6, 7, 4, 5, 6, 7,  8,  5,  6,  7,  8,  3,  2,  1,  2,  4,  5,  6,  7,  2, 1,  .4,  1},
        {4, 5, 6, 7, 8, 5, 6, 7, 8,  9,  6,  7,  8,  9,  4,  3,  2,  1,  5,  6,  7,  8,  3, 2,  1,  .4}};  
    float Cost[NT];
    
    vector <int> ThePath[NT];
    vector <int> TheUpdater[NT];
    float NewCost [NT];
    int NewState[NT];
    int * FinalPath = new int[steps];
    float minCost;
    // Initial step
    
    for (int k=0; k<NT; k++) {
        (ThePath[k]).clear();
        (TheUpdater[k]).clear();
        Cost[k] =powf(Steps[ini][k],G_PowTemplates);
        (ThePath[k]).push_back(ini);
    }
    
    for (int st =1; st<steps; st++) {
        
        // check the acummulated cost of comming to this state
        
        
        for (int dos=0; dos<NT; dos++) {
            minCost=Cost[0] + powf(Steps[0][dos],G_PowTemplates);   // repeat here
            for (int uno=0; uno<NT; uno++) {
                float thiscost;
                thiscost = Cost[uno] + powf(Steps[uno][dos],G_PowTemplates);   //any changes here
                if (thiscost <= minCost){
                    minCost = thiscost;
                    NewCost[dos] = thiscost;
                    (TheUpdater[dos]).clear();
                    for (int ps=0; ps<(ThePath[dos]).size(); ps++) {
                        TheUpdater[dos].push_back(ThePath[uno][ps]);
                    }
                    TheUpdater[dos].push_back(uno);
                }
            }
            
            
        }
        
        // now updating paths and costs
        
        
        for (int k=0; k<NT; k++) {
            (ThePath[k]).swap(TheUpdater[k]);
            Cost[k] =NewCost[k] ;
        }
    }
    
    
    // returning the output
    
    for (int st =0; st<steps; st++) {
        FinalPath[st] = ThePath[last][st];
        
    }
    return FinalPath;
    
};
