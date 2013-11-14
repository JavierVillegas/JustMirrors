//
//  ImageToEllipseList.cpp
//  Defense
//
//  Created by Javier Villegas on 6/1/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

// fills a global vector with Ellipse parameters.




#include <iostream>
#include "defense.h"



void defense::ImageToEllipseList(IplImage* TheInput,int PlaneNumber){

    priority_queue<TheEllipse, vector<TheEllipse>,less<vector<TheEllipse>::value_type> > EllipQueue;
    
    TheTargetsEllipses.clear();
    
    CvMemStorage* G_storage=NULL;
	G_storage=cvCreateMemStorage(0);   
    CvSeq* contour = 0;
    IplImage * Maska;
    Maska = cvCreateImage( cvGetSize(TheInput),IPL_DEPTH_8U,1); 
    int TotalEllip=0;
    
    for (int k=0;k<PlaneNumber;k++){ 
        cvInRangeS(TheInput,cvScalarAll((k-1)*255/(float)PlaneNumber),cvScalarAll(k*255/(float)PlaneNumber),Maska);
        cvSmooth(Maska,Maska,CV_MEDIAN,3);  
        int NC=cvFindContours( Maska, G_storage, &contour, sizeof(CvContour), 
                              CV_RETR_EXTERNAL, CV_CHAIN_APPROX_TC89_L1 );
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
                    // calculating the best ellipse	
                    Ellipdesc=cvFitEllipse2(CountArray);
                    
                    
                    EllipQueue.push(TheEllipse(Ellipdesc.center.x,
                                               Ellipdesc.center.y,
                                               Ellipdesc.size.width,
                                               Ellipdesc.size.height,
                                               Ellipdesc.angle,
                                               k*255/PlaneNumber));
                    TotalEllip++;
                    delete [] OtroArray;
                    cvReleaseMat(&CountArray);  
                } // end of if contour-> total
                
                
            } // end of for contours
            

        
    } // end For the Planes
    while (!EllipQueue.empty()){
        TheTargetsEllipses.push_back(EllipQueue.top());
        EllipQueue.pop();
    }
    
    cvReleaseImage(&Maska);
    
    // releasing mem storages
    if (contour!=NULL){cvClearSeq(contour);}
    //cvClearMemStorage(storage);
    if (G_storage!=NULL){cvReleaseMemStorage(&G_storage);}
    
    
    

}