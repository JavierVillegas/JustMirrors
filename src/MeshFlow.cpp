//
//  MeshFlow.cpp
//  Defense
//
//  Created by Javier Villegas on 6/5/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::MeshFlowUpdate(){

    float Fx,Fy;
    
    short* SptrX;
    short* SptrY;
    
    float Dt = 0.1;
    // updating the gradient;
    cvSobel(TheInputGray,G_Gx,1,0);  // 
	cvSobel(TheInputGray,G_Gy,0,1);
    
   // G_kMesh = 0.0;
   // G_kdMesh = 0;
 //   G_kgMesh = 1.5;
    // caculating Forces and updating velocities
	for (int k=1;k<MeshX-1;k++){
		for(int q=1; q < MeshY-1; q++) {
            uchar* ptrX = (uchar*) (
                                    G_Gx->imageData + (Nx/MeshX)*q * G_Gx->widthStep);
            uchar* ptrY = (uchar*) (
                                    G_Gy->imageData + (Ny/MeshY)*q * G_Gy->widthStep);            
            SptrX =(short *) ptrX;
            SptrY =(short *) ptrY;
            
            Fx = G_kMesh*(G_posX[k-1][q] - G_posX[k][q])  
            + G_kMesh*(G_posX[k+1][q] - G_posX[k][q])
            + G_kMesh*(G_posX[k][q-1] - G_posX[k][q])
            + G_kMesh*(G_posX[k][q+1] - G_posX[k][q])
            - G_kdMesh*G_velX[k][q]
            - G_kgMesh*(SptrX[(Nx/MeshX)*k]);
            
            Fy = G_kMesh*(G_posY[k-1][q] - G_posY[k][q])  
            + G_kMesh*(G_posY[k+1][q] - G_posY[k][q])
            + G_kMesh*(G_posY[k][q-1] - G_posY[k][q])
            + G_kMesh*(G_posY[k][q+1] - G_posY[k][q])
            - G_kdMesh*G_velY[k][q]
            - G_kgMesh*(SptrY[(Ny/MeshY)*k]);
            
            G_velX[k][q]+=Fx*Dt;
            G_velY[k][q]+=Fy*Dt;

            
            
//            G_velX[k][q]=Fx*Dt;
//            G_velY[k][q]=Fy*Dt;
        }
	}
    
    // updating position
    
    for (int k=1;k<MeshX-1;k++){
        for(int q=1; q < MeshY-1; q++) {
            
            G_PrevX[k][q]=G_posX[k][q];
            G_PrevY[k][q]=G_posY[k][q];
            
            G_posX[k][q]+=G_velX[k][q]*Dt;
            G_posY[k][q]+=G_velY[k][q]*Dt;
        }
    }

}

void defense::MeshFlowDraw(){
    
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0 );

    ofRectangle RectLimits;
    
//    RectLimits.x =(RectOut.getCenter()).x - 1.5*RectOut.width/4.0;
//    RectLimits.y=(RectOut.getCenter()).y - 1.2*RectOut.height/4.0;
//    RectLimits.width=RectOut.width/2.0;
//    RectLimits.height=RectOut.height/2.0;

    
    RectLimits.x =0.0;
    RectLimits.y= 0.0;
    RectLimits.width=.67*ScreenX;
    RectLimits.height=.67*ScreenY;
    
    
    
    glPushMatrix();
    
    ofTranslate(RectLimits.x, RectLimits.y);
    ofScale(1.5*RectLimits.width/Nx,1.5*RectLimits.height/Ny);
    
    ofSetColor(0, 0, 0);
    // ploting horizontal lines
    
	for (int k=0;k<MeshX;k++){
		glBegin(GL_LINE_STRIP);
        for(int q=0; q < MeshY; q++) {
            glVertex2f(G_posX[k][q],G_posY[k][q]);
//            float Dt = 0.1;
//             glVertex2f(G_posX[k][q] + G_velX[k][q]*Dt,
//                        G_posY[k][q] + G_velY[k][q]*Dt);
        }
		glEnd();
    }
    
    // ploting Vertical lines

	for (int q=0;q<MeshY;q++){
		glBegin(GL_LINE_STRIP);
        for(int k=0; k < MeshX; k++) {
            glVertex2f(G_posX[k][q],G_posY[k][q]);
//            float Dt = 0.1;
//            glVertex2f(G_posX[k][q] + G_velX[k][q]*Dt,
//                       G_posY[k][q] + G_velY[k][q]*Dt);         
        }
		glEnd();
        
	}

 glPopMatrix();


}


void defense::ArrowsDraw(){
    
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0 );
    Fuentes[1].drawString("Example 1. The gradient of an image",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    ofRectangle RectLimits;
    
    RectLimits.x =(RectOut.getCenter()).x - 1.5*RectOut.width/4.0;
    RectLimits.y=(RectOut.getCenter()).y - 1.2*RectOut.height/4.0;
    RectLimits.width=RectOut.width/2.0;
    RectLimits.height=RectOut.height/2.0;
    glPushMatrix();
    
    ofTranslate(RectLimits.x, RectLimits.y);
    ofScale(1.5*RectLimits.width/Nx,1.5*RectLimits.height/Ny);
    short SX,SY;
    ofSetColor(0, 0, 0 );
    for (int k=0;k<MeshX;k+=2) {
        for (int q=0; q < MeshY; q+=2) {
            //lines
            
            SX = ((short*)(G_Gx->imageData + (Ny/MeshY)*G_Gx->widthStep*q))[(Nx/MeshX)*k];
            SY = ((short*)(G_Gy->imageData + (Ny/MeshY)*G_Gy->widthStep*q))[(Nx/MeshX)*k];
            
            ofLine(G_posX[k][q], G_posY[k][q], 
                 G_posX[k][q] - (.2)*(float)SX, G_posY[k][q]- (.2)*(float)SY);
//            // arrows
            float tipX = G_posX[k][q]-(.2)*(float)SX;
            float tipY = G_posY[k][q]-(.2)*(float)SY;
            float f = tan(PI/9.0)*sqrt((.2)*(float)SX*(.2)*(float)SX+
                                       (.2)*(float)SY*(.2)*(float)SY)/5.0;
            float alfa = atan2((.2)*(float)SY, (.2)*(float)SX); 
            ofFill();
            ofBeginShape();
            ofVertex(tipX, tipY);
            ofVertex(tipX+(.2)*(float)SX/5.0+f*sin(alfa), 
                   tipY+(.2)*(float)SY/5.0 - f*cos(alfa));
            ofVertex(tipX+(.2)*(float)SX/5.0-f*sin(alfa), 
                   tipY+(.2)*(float)SY/5.0 + f*cos(alfa));
            ofEndShape(true);
        }
    }
    
    
    
    
    
    
    
    glPopMatrix();
    
    
}








