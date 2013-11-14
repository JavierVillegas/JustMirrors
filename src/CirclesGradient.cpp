//
//  CirclesGradient.cpp
//  Defense
//
//  Created by Javier Villegas on 6/6/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>

#include "defense.h"
void defense::CirclesGradientUpdate(){

    IplImage * TheBW;

    IplImage * TheDistance32F1;
    IplImage * TheDistance32F2;
    IplImage * LocalGx;
    IplImage * LocalGy;
    float AreaFactor;
    
    TheBW = cvCreateImage(cvSize(Nx, Ny),IPL_DEPTH_8U,1); 
    TheDistance32F1 =cvCreateImage( cvSize(Nx,Ny),IPL_DEPTH_32F,1);
    TheDistance32F2 =cvCreateImage( cvSize(Nx,Ny),IPL_DEPTH_32F,1);
    LocalGx=cvCreateImage( cvSize(Nx,Ny), IPL_DEPTH_32F, 1);
	LocalGy=cvCreateImage( cvSize(Nx,Ny), IPL_DEPTH_32F, 1);
    cvThreshold(TheInputGray, TheBW, 2*Slider1, 255, CV_THRESH_BINARY_INV);
//    cvSet(TheBW, cvScalarAll(0));
//    cvCircle(TheBW, cvPoint(Nx/2.0, Ny/2.0), 200, cvScalarAll(255),-1);
    
    CvScalar TempSum =cvAvg(TheBW);
    AreaFactor = TempSum.val[0];
    cvDistTransform(TheBW,TheDistance32F1);
    cvNot(TheBW, TheBW);

    
    cvDistTransform(TheBW,TheDistance32F2);
    cvSub(TheDistance32F1, TheDistance32F2, TheDistance32F1);
    cvSobel(TheDistance32F1,LocalGx,1,0);
    cvSobel(TheDistance32F1,LocalGy,0,1);
    
    
    // update the ball positions
    
    float Kp;
    int Nit =5;
    
    Kp=(5*Slider2/127.0)/(float)Nit;
    
    //Kp = .1;
    float dx,dy,r,d,MagV,vx,vy,LocalFactor;
    
    LocalFactor = 1.5*pow((3*Slider3/127.0)*AreaFactor/255.0*(Nx*Ny/((float)NGradCirs)),0.4);
    
    for (int sss=0; sss<Nit;sss++){
        
        for(int c=0; c< NGradCirs;c++){
            
			for(int cn=c+1;cn<NGradCirs;cn++){
                
				dx = GradientCircs[cn].x -GradientCircs[c].x; 
				dy = GradientCircs[cn].y -GradientCircs[c].y; 
                //	r = (Radii[cn] + Radii[c])*G_AreaFactor;
				r = LocalFactor;			
				d = GradientCircs[cn].distanceSquared(GradientCircs[c]);
				MagV = sqrt(d);
				if (MagV<(r-0.01)){
                    //		cout << c<< "\n";
                    vx = dx;
					vy = dy;
					if (MagV!=0){
						vx =vx/MagV;
						vy =vy/MagV;
					}
                    vx=vx*((r-MagV)*Kp);
					vy=vy*((r-MagV)*Kp);
                    //	vx=vx*d/25.0;
                    //	vy=vy*d/25.0;
					GradientCircs[cn].x += vx;
					GradientCircs[cn].y += vy;
					GradientCircs[c].x -= vx;
					GradientCircs[c].y -= vy;
                    
				} // end if Mag
                
                
			} //end	 for cn	
            
		} // end for c

        
        
        float Ku=0;
          float dt = 0.05;
        //	if (G_ErrorFactor < 0.25){Ku=0.25;}
        //		if ((G_ErrorFactor >= 0.25)&&(G_ErrorFactor < 8)){Ku=0.3;}
        //		if((G_ErrorFactor>=8)&&(G_ErrorFactor<20)){Ku = 0.3*G_ErrorFactor/8.0;}
        //		if(G_ErrorFactor>=20){Ku = 0.75;}
        
      //  Ku = 10.0/((float)sss+200);
          Ku = 3*Slider4/127.0;
        int TheCordX,TheCordY;
        CvScalar tempSX,tempSY;
        float ax =0;
        float ay =0;
        
        float Kd =Slider5/127.0;
        //	damping = (1.0)/((float)it+5.0);
		for(int k=0;k<NGradCirs;k++){               
                TheCordX = (int) GradientCircs[k].x;
                TheCordX = (TheCordX<0)?0:TheCordX;
                TheCordX = (TheCordX>=Nx)?Nx-1:TheCordX;
                TheCordY = (int) GradientCircs[k].y;
                TheCordY = (TheCordY<0)?0:TheCordY;
                TheCordY = (TheCordY>=Ny)?Ny-1:TheCordY;
                tempSX=cvGet2D(LocalGx,TheCordY,TheCordX);
                tempSY=cvGet2D(LocalGy,TheCordY,TheCordX);
                vx = tempSX.val[0]*Ku;
                vy = tempSY.val[0]*Ku;	
            
            
                ax = vx - Kd*(VelsGradient[k].x);    
                ay = vy - Kd*VelsGradient[k].y;               
                VelsGradient[k].x += dt*ax;
                VelsGradient[k].y += dt*ay;
            
            
                GradientCircs[k].x+=VelsGradient[k].x*dt;
                GradientCircs[k].y+=VelsGradient[k].y*dt;
                GradientCircs[k].x = (GradientCircs[k].x<0)?0:GradientCircs[k].x;
                GradientCircs[k].x = (GradientCircs[k].x>=Nx)?Nx-1:GradientCircs[k].x;
                GradientCircs[k].y = (GradientCircs[k].y<0)?0:GradientCircs[k].y;
                GradientCircs[k].y = (GradientCircs[k].y>=Ny)?Ny-1:GradientCircs[k].y;
		}
    } // end for iterations

    cvReleaseImage(&TheBW);
    cvReleaseImage(&LocalGx);
    cvReleaseImage(&LocalGy);
    cvReleaseImage(&TheDistance32F1);
    cvReleaseImage(&TheDistance32F2);

}


void defense::CirclesGradientDraw(){
    
    ofxCvGrayscaleImage ForTheBW;
    ForTheBW.allocate(Nx, Ny);
    IplImage * TheBW;
    TheBW = cvCreateImage(cvSize(Nx, Ny),IPL_DEPTH_8U,1); 
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofSetColor(0, 0, 0);
    Fuentes[3].drawString("Moving circles with the distance transform",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    cvThreshold(TheInputGray, TheBW, 2*Slider1, 255, CV_THRESH_BINARY);
    ForTheBW = TheBW;
    
    ofRectangle RectLimits;
    
    RectLimits.x =(RectOut.getCenter()).x - 2*RectOut.width/4.0;
    RectLimits.y=(RectOut.getCenter()).y - 1.8*RectOut.height/4.0;
    RectLimits.width=1.8*RectOut.width/2.0;
    RectLimits.height=1.8*RectOut.height/2.0;

    
    glPushMatrix();
    
    ofTranslate(RectLimits.x, RectLimits.y);
    ofScale(RectLimits.width/Nx,RectLimits.height/Ny);
    
    // ploting the object array

    for (int k=0;k<NGradCirs;k++){
        ofCircle(GradientCircs[k].x , GradientCircs[k].y, 3);        
    }
    glPopMatrix();

    
    ofSetColor(255, 255, 255);
    
    ForTheBW.draw(RectOut.x, 
                  RectOut.y+3*RectOut.height/4.0,
                  RectOut.width/4.0,RectOut.height/4.0);
    ofSetColor(0, 0, 0);
    ofNoFill();
    ofRect(RectOut.x, 
           RectOut.y+3*RectOut.height/4.0,
           RectOut.width/4.0,RectOut.height/4.0);
    ofFill();
     cvReleaseImage(&TheBW);
}
