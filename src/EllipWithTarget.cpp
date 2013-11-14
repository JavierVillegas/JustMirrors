//
//  EllipWithTarget.cpp
//  CADemo
//
//  Created by Javier Villegas on 7/15/13.
//  Copyright (c) 2013 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::EllipWithTarget(){
    
    ofRectangle RectOut;
    RectOut = OneBigRect();
//    ofSetColor(0, 0, 0);
//    Fuentes[1].drawString("Testin Testing",
//                          RectOut.x,RectOut.y + RectOut.height*.1);
//    Fuentes[3].drawString("Example, Ellipses as synthesis objects",
//                          RectOut.x,RectOut.y + RectOut.height*.2);
//    Fuentes[3].drawString("Non-coherent (Left) Vs Attractors algorithm (Right)",
//                          RectOut.x,RectOut.y + RectOut.height*.3);
    
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    
    
    
    ofRectangle RectLimits;
    RectLimits.x =0.0;
    RectLimits.y=10.0;
    RectLimits.width=ScreenX;
    RectLimits.height=ScreenY;
//    RectLimits.x =(RectOut.getCenter()).x + 1.5*RectOut.width/8.0;
//    RectLimits.y=(RectOut.getCenter().y- RectOut.height/2.0 + 1.0*RectOut.height/32.0);
//    RectLimits.width=1.3*RectOut.width/4.0;
//    RectLimits.height=0.9*RectOut.height/2.0;

    
    
    
    
    PlotEllipPolligon(TheCoherentEllipses,RectLimits);
//     RectLimits.y=(RectOut.getCenter()).y + 1.0*RectOut.height/32.0;
//    PlotEllipses(TheTargetsEllipses,RectLimits);
//   
//    
//    RectLimits.x =(RectOut.getCenter()).x - RectOut.width/2.0;
//    RectLimits.y=(RectOut.getCenter().y- RectOut.height/2.0 + 1.0*RectOut.height/32.0);
//    RectLimits.width=1.3*RectOut.width/2.0;
//    RectLimits.height=0.9*RectOut.height;
//   
//     plotPointsFroEllipses(TheTargetsEllipses,RectLimits,1);
//    plotPointsFroEllipses(TheCoherentEllipses,RectLimits,0);
    glDisable(GL_BLEND);
}

void defense::plotPointsFroEllipses(vector<TheEllipse> ElliVec,ofRectangle RectLimits,int DMode){
// function for reducing the dimension of the ellipses from 6 to 2, for illustration purpuses.
    TheEllipse CurrentEllipse(320,10,10,10,0,0);
    float projectedX,projectedY;
    for (int k=0; k < ElliVec.size();k++){
        CurrentEllipse = ElliVec[k];
        
        //Projecting in first 2 results of the PCA
        float TheAnglenew;
//        if (DMode==1){
//        TheAnglenew = (CurrentEllipse.angle<270)?CurrentEllipse.angle-180:CurrentEllipse.angle-360;
//            TheAnglenew*=2;
//        }
        TheAnglenew =0;
        
        
        projectedX = ( 0.254875586682973)*CurrentEllipse.x + (0.352504157439573)*CurrentEllipse.y +
         (-0.492816054122748)*CurrentEllipse.a +( -0.664964456204252)*CurrentEllipse.b +
        (0.067291073966082)*TheAnglenew + (-0.348146196947756)* CurrentEllipse.TheGray;
        
        projectedY = (0.183031525708023)*CurrentEllipse.x + (0.402785835088686)*CurrentEllipse.y +
        (-0.079850959565727)*CurrentEllipse.a +( 0.169392137925460)*CurrentEllipse.b +
        (0.737947268733986)*TheAnglenew + (0.473948296845160)* CurrentEllipse.TheGray; 
        
        // Adjsting for the plot rect
        float MINx = -400;
        float MAXx = 300;
        float MAXy = 400;
        float MINy = 50;
        float defX = RectLimits.x+(projectedX-(MINx))/(MAXx-MINx)*RectLimits.width;
        float defY = RectLimits.y+(projectedY-(MINy))/(MAXy-MINy)*RectLimits.height;
        
        if (DMode==0){
            ofSetColor(0, 0, 0,255);
              ofCircle(defX, defY, 2);
        }
        if (DMode==1){
            ofSetColor(200, 0, 0,140);
            PlotStar(defX, defY, 5, 3,5);
//            ofRect(defX-2, defY-2, 4, 4);

//                       static float thesupermin = 0;
//                       if (TheAnglenew>thesupermin) {
//                          thesupermin = TheAnglenew;
//                           cout<< TheAnglenew<<endl;
//                        }


        
        }
//        ofSetColor(CurrentEllipse.TheGray,CurrentEllipse.TheGray,CurrentEllipse.TheGray);
//        glPushMatrix();  
//        ofTranslate(CurrentEllipse.x-Nx/2.0, CurrentEllipse.y-Ny/2.0);
//        ofRotate(CurrentEllipse.angle);
//        ofEllipse(0.0,0.0 , CurrentEllipse.a, CurrentEllipse.b);
//        glPopMatrix();  
    }
}

void defense::PlotStar(float x, float y, int verty, int rad1,int rad2){
    ofFill();
    glPushMatrix();
    ofTranslate(x,y);
    ofBeginShape();
    
    for(int k = 0; k < verty;k++){
     
        ofVertex(rad2*sin(k*2*PI/(float)verty), rad2*cos(k*2*PI/(float)verty));
     ofVertex(rad1*sin(PI/(float)verty+k*2*PI/(float)verty), rad1*cos(PI/(float)verty+k*2*PI/(float)verty));
    
    }
    
    ofEndShape();
    glPopMatrix();
}




