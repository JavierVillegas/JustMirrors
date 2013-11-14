//
//  ImgToContours.cpp
//  Defense
//
//  Created by Javier Villegas on 6/4/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"



void defense::ImgToContours(IplImage* TheInput,int PlaneNumber, int CMode){
    
    
    CvMemStorage* G_storage=NULL;
	G_storage=cvCreateMemStorage(0);   
    CvSeq* contour = 0;
    IplImage * Maska;
    Maska = cvCreateImage( cvGetSize(TheInput),IPL_DEPTH_8U,1); 
    int TotalEllip=0;
    CvMat* TempMat;
    TempMat = cvCreateMat(FFTSize, 1, CV_32FC2);
    vector <ofVec2f> TempVec;
    ArrayOfContours.clear();
    ContourGray.clear();
    for (int k=0;k<PlaneNumber;k++){
        if (CMode==0) {
            cvInRangeS(TheInput,cvScalarAll((k-1)*255/(float)PlaneNumber),cvScalarAll(k*255/(float)PlaneNumber),Maska);
        }
        else{  
        cvThreshold(TheInput, Maska, k*255/(float)PlaneNumber, 255, CV_THRESH_BINARY_INV);
        }
        cvSmooth(Maska,Maska,CV_MEDIAN,3);  
        int NC=cvFindContours( Maska, G_storage, &contour, sizeof(CvContour), 
                              CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
  //                            CV_RETR_EXTERNAL, CV_CHAIN_APPROX_TC89_L1 );
        for( ; contour != 0; contour = contour->h_next )
        {
            
            if ((contour->total > 10 )&&(TotalEllip<MaxEllip)){
                
                CvMat* CountArray;
                CvBox2D Ellipdesc;
                CvPoint2D32f * OtroArray;
                OtroArray = new CvPoint2D32f[contour->total];
                for(int q=0;q<contour->total;q++){
                    CvPoint* p = (CvPoint*)cvGetSeqElem( contour, q );
                    OtroArray[q].x = (float)p->x;
                    OtroArray[q].y=(float)p->y;
                }
                CountArray=cvCreateMatHeader(contour->total,1,CV_32FC2);
                cvInitMatHeader(CountArray,contour->total,1,CV_32FC2,OtroArray);
                cvResize(CountArray, TempMat);	
                cvDFT(TempMat, TempMat, CV_DXT_FORWARD);
                int TheLimit = (int)((FFTSize/2)*Slider1/127.0) -1;
                
                for (int q =0; q < TheLimit; q++) { 
                    ((float*)(TempMat->data.ptr + TempMat->step*((FFTSize/2)-q)))[0] = 0.0;
                    ((float*)(TempMat->data.ptr + TempMat->step*((FFTSize/2)-q)))[1] = 0.0;
                    ((float*)(TempMat->data.ptr + TempMat->step*((FFTSize/2)+q)))[0] = 0.0;
                    ((float*)(TempMat->data.ptr + TempMat->step*((FFTSize/2)+q)))[1] = 0.0;                 
                 }
                 cvDFT(TempMat, TempMat, CV_DXT_INV_SCALE);
                TempVec.clear();
                for (int q=0; q < FFTSize;q++){
                    TempVec.push_back(ofVec2f (((const float*)(TempMat->data.ptr + TempMat->step*q))[0],
                    ((const float*)(TempMat->data.ptr + TempMat->step*q))[1]));
                }
                ArrayOfContours.push_back(TempVec);
                ContourGray.push_back(k*255/(float)PlaneNumber);
                
                TotalEllip++;
                delete [] OtroArray;
                cvReleaseMat(&CountArray);  
            } // end of if contour-> total
            
            
        } // end of for contours
        
        
    } // end for planenumber
    
    cvReleaseMat(&TempMat);
    cvReleaseImage(&Maska);
    
    // releasing mem storages
    if (contour!=NULL){cvClearSeq(contour);}
    //cvClearMemStorage(storage);
    if (G_storage!=NULL){cvReleaseMemStorage(&G_storage);}
  
}