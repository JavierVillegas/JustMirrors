//
//  ImgToLineList.cpp
//  Defense
//
//  Created by Javier Villegas on 6/5/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"



void defense::ImgToLineList(){

    LineVec.clear();
    IplImage * EdgeMap;
    EdgeMap = cvCreateImage( cvSize(Nx,Ny),IPL_DEPTH_8U,1); 
  //  cvCanny(TheInputGray, EdgeMap, 50*(.1+Slider1/127.0), 100*(.1+Slider1/127.0),3);
    cvCanny(TheInputGray, EdgeMap, 50, 100,3);
    CvMemStorage* storage = cvCreateMemStorage(0);
    CvSeq* lines = 0;
    
    lines = cvHoughLines2( EdgeMap, storage, CV_HOUGH_STANDARD, 1, CV_PI/180, 15, 0,0 );
    for( int i = 0; i < MIN(lines->total,MaxLines); i++ )
    {
        float* line = (float*)cvGetSeqElem(lines,i);
        float rho = line[0];
        float theta = line[1];
        LineVec.push_back(ofVec2f(theta,rho));        
    }

    // releasing mem storages
    if (lines!=NULL){cvClearSeq(lines);}
    //cvClearMemStorage(storage);
    if (storage!=NULL){cvReleaseMemStorage(&storage);}
}