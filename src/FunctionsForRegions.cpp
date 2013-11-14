//
//  FunctionsForRegions.cpp
//  Defense
//
//  Created by Javier Villegas on 6/4/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"


void defense::updateMat(){
    
    vector<ofVec3f> TempoVec;
    avMat.clear();
    int SideX = Nx/MAX((127 - Slider1)*AvMaxX/127,1);
    int SideY = Ny/MAX((127 - Slider2)*AvMaxY/127,1);
    CvRect TheSection;
    TheSection.width = SideX;
    TheSection.height = SideY;
    
    for (int k=0; k + SideX-1<Nx; k+=SideX) {
        TempoVec.clear();
        for (int q =0; q+SideY-1<Ny; q+=SideY) {
            TheSection.x =k;
            TheSection.y =q;
            
            cvSetImageROI(TheInputRGB, TheSection);
            CvScalar TheAv;
            TheAv = cvAvg(TheInputRGB);
            cvResetImageROI(TheInputRGB);
            TempoVec.push_back(ofVec3f(TheAv.val[0],TheAv.val[1],TheAv.val[2]));
        }
        avMat.push_back(TempoVec);

    }

}




void defense::PlotCuadros(ofRectangle RectLimits,int AMode){

    int SideX = RectLimits.width/avMat.size();
    int SideY = RectLimits.height/(avMat[0]).size();
    for (int k = 0; k < avMat.size(); k++) {
        for (int q=0; q<(avMat[k]).size(); q++) {
            ofSetColor((avMat[k][q]).x, (avMat[k][q]).y, (avMat[k][q]).z);
            if(AMode==0){
            ofRect(RectLimits.x + k*SideX,
                   RectLimits.y + q*SideY, 
                   SideX, SideY);
            }
            else if(AMode==1){
            ofEllipse(RectLimits.x + k*SideX+SideX/2.0,
                      RectLimits.y + q*SideY+SideY/2.0,
                      SideX, SideY);
            }
            
        }    
    }
}

void defense::PlotALizard(){
    GLdouble LizardX[50 ]={
        8.660254e-001,
        7.318236e-001,
        6.245530e-001,
        2.383790e-001,
        1.597139e-001,
        3.814064e-002,
        -2.050060e-001,
        -1.334923e-001,
        -4.767580e-003,
        -1.191895e-002,
        -2.479142e-001,
        -5.411204e-001,
        -2.121573e-001,
        -4.410012e-001,
        -5.411204e-001,
        -8.660254e-001,
        -1.280854e+000,
        -1.498131e+000,
        -1.414369e+000,
        -8.782911e-001,
        -6.904577e-001,
        -7.960688e-001,
        -8.128725e-001,
        -8.629321e-001,
        -5.840286e-001,
        -6.698451e-001,
        -5.411204e-001,
        -3.837902e-001,
        -9.058403e-002,
        8.104887e-002,
        3.027414e-001,
        0,
        3.442738e-002,
        2.753323e-001,
        3.239891e-001,
        5.634912e-001,
        5.554505e-001,
        3.473091e-001,
        7.123943e-003,
        4.500458e-001,
        7.842256e-001,
        8.079878e-001,
        1.083109e+000,
        1.153665e+000,
        1.294707e+000,
        1.352739e+000,
        1.279566e+000,
        8.500570e-001,
        5.083316e-001,
        5.104357e-001};
    GLdouble LizardY[50 ]={
        5.000000e-001,
        9.880810e-001,
        1.052443e+000,
        8.808105e-001,
        4.302741e-001,
        4.159714e-001,
        6.233611e-001,
        7.449344e-001,
        7.520858e-001,
        1.073897e+000,
        1.059595e+000,
        6.734207e-001,
        2.443385e-001,
        1.549464e-002,
        2.085816e-001,
        5.000000e-001,
        3.643332e-001,
        3.741709e-001,
        6.156439e-002,
        1.319136e-001,
        -3.150974e-001,
        -5.266266e-001,
        -5.637664e-001,
        -9.785459e-001,
        -1.328963e+000,
        -9.856973e-001,
        -6.710369e-001,
        -5.709178e-001,
        -6.781883e-001,
        -6.352801e-001,
        -7.854589e-001,
        -1,
        -1.369452e+000,
        -1.252550e+000,
        -1.082458e+000,
        -8.821690e-001,
        -6.958575e-001,
        -4.270485e-001,
        -3.297349e-001,
        -2.634060e-001,
        -5.141486e-001,
        -5.472709e-001,
        -3.801718e-001,
        -4.880749e-001,
        -4.892209e-001,
        -1.749549e-001,
        -7.682073e-002,
        -2.339630e-001,
        1.465711e-002,
        1.397373e-001};
    
    ofBeginShape();    
    for (int k=0; k<50; k++) {
        ofVertex(LizardX[k], LizardY[k]);
    }
    ofEndShape();

    }




void defense::PlotLizardArray(){
    
    int LizCol= 28;
    int LizFil=25;
	float Col = LizCol;
	float Fil = LizFil;
	CvScalar TheAv;
	int Maxq=1;
	int Maxk=1;
	int rotn=1;
	int trasn=1;
	float cordx,cordy;
	int SideX = Nx/LizCol;
	int SideY = Ny/LizFil;
	int cornerX,cornerY,newSideX,newSideY;
    float LizSep =0.05;
    
	CvRect  Cuadro;  
	for (int k=0;k<Fil;k++){
		for (int q=0;q<Col;q++){
			rotn=((k-((int)(LizFil/2)))%2==0)?((q-(LizCol/2))%3):(((q-(LizCol/2))+2)%3);
			trasn=((k-((int)(LizFil/2)))%2==0)?0:1;
			cordx=Nx/2.0+(0.5)*(Nx/1.2)*LizSep* ( (q-(LizCol/2))*2*cos(CV_PI/6.0)+trasn*cos(CV_PI/6.0) );
			cordy = (Ny/2.0)+(0.5)*(Ny/0.9)*LizSep*(k-((float)(LizFil/2.0)))*1.5;
			
			cornerX = (cordx-SideX/2)<0?0:(cordx-SideX/2);
			cornerY = (cordy-SideY/2)<0?0:(cordy-SideY/2);
            
			newSideX = (cornerX+SideX)>(Nx-1)?(Nx-1)-cornerX:SideX;
			newSideY = (cornerY+SideY)>(Ny-1)?(Ny-1)-cornerY:SideY;
            
            
			cvSetImageROI(TheInputRGB, cvRect(cornerX,cornerY,newSideX,newSideY));
			TheAv = cvAvg(TheInputRGB);
            cvResetImageROI(TheInputRGB);
			ofSetColor(TheAv.val[0],TheAv.val[1],TheAv.val[2]);
  
			glPushMatrix();
            ofTranslate(LizSep*((q-(LizCol/2))*2*cos(CV_PI/6.0)+trasn*cos(CV_PI/6.0)),
                        LizSep*(k-((int)(LizFil/2)))*1.5);
            glRotatef((rotn)*(-120), 0, 0, -1);
            ofScale(LizSep,LizSep);
            PlotALizard();            
			glPopMatrix();
            
            
            //		glBegin(GL_QUADS);
            //			float hafan=1.2/Col;
            //			glVertex3f(2.4*(q-Col/2.0)/Col-hafan,
            //				1.8*(k-Fil/2.0)/Fil+hafan,-2);
            //			glVertex3f(2.4*(q-Col/2.0)/Col+hafan,
            //				1.8*(k-Fil/2.0)/Fil+hafan,-2);
            //			glVertex3f(2.4*(q-Col/2.0)/Col+hafan,
            //				1.8*(k-Fil/2.0)/Fil-hafan,-2);
            //			glVertex3f(2.4*(q-Col/2.0)/Col-hafan,
            //				1.8*(k-Fil/2.0)/Fil-hafan,-2);
            //		glEnd();
		}
	}

}





//void defense::PlotLizardArray(ofRectangle RectLimits){
//    
//    int SideX = RectLimits.width/avMat.size();
//    int SideY = RectLimits.height/(avMat[0]).size();
//    for (int k = 0; k < avMat.size(); k++) {
//        for (int q=0; q<(avMat[k]).size(); q++) {
//            ofSetColor((avMat[k][q]).x, (avMat[k][q]).y, (avMat[k][q]).z);
//            
//            
//            
//            
//            if(AMode==0){
//                ofRect(RectLimits.x + k*SideX,
//                       RectLimits.y + q*SideY, 
//                       SideX, SideY);
//            }
//            else if(AMode==1){
//                ofEllipse(RectLimits.x + k*SideX+SideX/2.0,
//                          RectLimits.y + q*SideY+SideY/2.0,
//                          SideX, SideY);
//            }
//            
//            
//            
//            
//        }    
//    }
//}
