//
//  WaveformDrawing.cpp
//  Sep6pres
//
//  Created by Javier Villegas on 9/5/13.
//  Copyright (c) 2013 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"
void defense::WaveSlide(){
    
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0 );
    Fuentes[0].drawString("Transcoding",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    
    ofRectangle RectLimits;
    RectLimits.x =(RectOut.getCenter()).x - 3*RectOut.width/8.0;
    RectLimits.y=(RectOut.getCenter()).y - 0.8*3*RectOut.height/8.0;
    RectLimits.width=3*RectOut.width/4.0;
    RectLimits.height=3*RectOut.height/4.0;
    
    
    float tempoval;
    glPushMatrix();
    
    ofTranslate(RectLimits.x, RectLimits.y);
    ofScale(RectLimits.width/Nx,RectLimits.height/Ny);

    
    int tempindi,cordx,cordy,AudioLine2;
	float TheValue,x,y,dx,dy,cost,sint,x01,y01,slope;
    // ploting the line
	//glColor4f( 0.2, 0.2, 0.2, .4*G_Blend);
	//glColor4f( 0.1, 0.1, 0.1, .4*G_Blend);
    int NumLines = 281;
    int AudioLine =2048;
    float  Lx = 1.2;
    float  Ly = 0.9;
    AudioLine2=8*AudioLine;
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    ofSetColor(0.0, 0.0, 0.0,40);
    float base = 1.02;// + .05*Slider2/127.0;
 
	for(int k=-(NumLines-1)/2;k<(NumLines-1)/2;k+=2){
        
        
       glBegin(GL_LINE_STRIP);
        for (int q=0;q<AudioLine2;q+=8){
        			x01 = q/(float)AudioLine2;
			slope = pow((float)base,(float)k)*pow((float)x01,(float)(pow((float)base,(float)k)-1));	
			y01 = pow((float)x01,(float)pow(base,(float)k));
            
			cordx =(int)(Destino->width*x01);
			cordy =(int)(Destino->height*y01);
			if ((cordx<0)||(cordx>=Destino->width)||(cordy<0)||(cordy>=Destino->height)){
                TheValue = 0;
			}
			else{
                TheValue = (float)((uchar *)(Destino->imageData + (Destino->height-cordy)*Destino->widthStep))[cordx*Destino->nChannels + 0];
				TheValue = 255*pow((1.0 -TheValue/255.0),2)*Slider1/127.0;
			}
			int esteindi= q%(AudioLine);
			dx = .001*left[esteindi]*TheValue*(-sin(atan(slope)));
			dy = .001*left[esteindi]*TheValue*cos(atan(slope));
			dx = dx*Nx;
			dy = dy*Ny;
            
            //			dx = .001*G_CurrentValue[q]*TheValue*cost;
            //			dy = .001*G_CurrentValue[q]*TheValue*sint;
            
            //			dx = .005*(2*rand()/(float)RAND_MAX-1)*cost;
            //			dy = .005*(2*rand()/(float)RAND_MAX-1)*sint;
            
            x = x01*Nx;
            y = Ny -y01*Ny;
            glVertex2f(x+dx,y+dy);
            //	(0.0008*(TheValue)*G_CurrentValue[q]),-2);
            
        }
		glEnd();
	}
    
    glDisable(GL_BLEND);
    
    
    
    
    
    
//    for (int i=0; i <Destino->height; i++) {
//        for (int j=0; j<Destino->width; j++) {
//            
//            tempoval = (float)((uchar *)(Destino->imageData + i*Destino->widthStep))[j*Destino->nChannels + 0];
//            float ScalValue = (Slider1/127.0)*(1-tempoval/255.0);
//            glPushMatrix();  
//            ofTranslate(j*Nx/NumOfSquares.x+(Nx/NumOfSquares.x)/2.0, 
//                        i*Ny/NumOfSquares.y+(Ny/NumOfSquares.y)/2.0);
//            ofRect(-.5*Nx/NumOfSquares.x*ScalValue, -.5*Ny/NumOfSquares.y*ScalValue,
//                   ScalValue*Nx/NumOfSquares.x, ScalValue*Ny/NumOfSquares.y); 
//            //ofScale(.2*ScalValue, .2*ScalValue);
//            // grayImage.draw(0,0);
//            //          ofSetColor(tempoval,tempoval,tempoval);
//            //            ofRect(j*Nx/NumOfSquares.x, i*Ny/NumOfSquares.y, Nx/NumOfSquares.x, Ny/NumOfSquares.y);
//            glPopMatrix(); 
//            
//        }
//    }
    
    glPopMatrix();
    
}