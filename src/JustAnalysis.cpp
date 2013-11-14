//
//  JustAnalysis.cpp
//  Defense
//
//  Created by Javier Villegas on 5/31/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::JustAnalysis(int JAMode){
    ofSetHexColor(0xffffff);
    ofRectangle RectOut;
    RectOut = OneBigRect();
    int Values[4][4];
    float Xside = 3*RectOut.width/8.0;
    float Yside= RectOut.height/2.0;
    
    float Ypos = RectOut.y;
    ofSetColor(0, 0, 0);
    
    float TheSwitdh = Fuentes[3].stringWidth("Constituent Elements:");
    float TheHeight = Fuentes[3].stringHeight("Constituent Elements:");
    Ypos+=3*TheHeight;
    Fuentes[3].drawString("Constituent Elements:",ScreenX/10.0,Ypos);
   
    
    if (JAMode==0){ // constituent elemts are pixels
        ofSetColor(0, 0, 0);
        
        float TheSwitdh = Fuentes[3].stringWidth("Pixels?");
        float TheHeight = Fuentes[3].stringHeight("Pixels?");
        Fuentes[3].drawString("Pixels?",ScreenX/10.0,Ypos+2*RectOut.height/20.0);
         ofSetHexColor(0xffffff);
        ofPushMatrix();
        float Xini =RectOut.x+RectOut.width/4.0; 
        float Yini = RectOut.y+RectOut.height/2.0;
        
        ofTranslate(RectOut.x+RectOut.width/4.0, RectOut.y+RectOut.height/2.0);
        ofScale(.5, .5);
        grayImage.draw(-grayImage.width/2.0, -grayImage.height/2.0);
        ofPopMatrix();
        
//        ofTranslate(RectOut.x+RectOut.width/4.0, RectOut.y+RectOut.height/2.0);
//        
//         grayImage.draw(-Xside/2.0, -Yside/2.0,
//                        Xside,Yside);
//        ofPopMatrix();
        // finding the values of 4x4 pixels in the center
        for (int row=0; row<4; row++) {
            for(int col = 0;col<4;col++){
            
                Values[row][col] =(int)((uchar *)
                (TheInputGray->imageData + (TheInputGray->height/2+row)*TheInputGray->widthStep))
                [(TheInputGray->width/2+col)*TheInputGray->nChannels + 0];
            }
        }

            // ploting the grid of 4x4 pixels in the center
        ofSetColor(200, 0, 0);
        ofNoFill();
        
        for (int row=0; row<4; row++) {
            for(int col = 0;col<4;col++){
                float Xini =RectOut.x+3*RectOut.width/4.0 - Xside/2.0;
                float Yini = RectOut.height/2.0 - Yside/2.0;
                ofRect(Xini+col*Xside/4.0,Yini+row*Yside/4.0,
                       Xside/4.0,Yside/4.0);
                
            }
        }
    
        ofFill();
        
        //ploting the values
        
        for (int row=0; row<4; row++) {
            for(int col = 0;col<4;col++){
                float Xini =RectOut.x+3*RectOut.width/4.0 - Xside/2.0 + Xside/8.0;
                float Yini = RectOut.height/2.0 - Yside/2.0 + Yside/8.0;
                float TheSWidth = Fuentes[3].stringWidth(ofToString(Values[row][col]));
                float TheSHeight = Fuentes[3].stringHeight(ofToString(Values[row][col]));

                Fuentes[3].drawString(ofToString(Values[row][col]),Xini+col*Xside/4.0-TheSWidth/2.0,Yini+row*Yside/4.0);
            }
        }
        
        // ploting the lines
        
        ofLine(RectOut.x+RectOut.width/4.0,
               RectOut.y+RectOut.height/2.0,
               RectOut.x+3*RectOut.width/4.0 - Xside/2.0,
               RectOut.height/2.0 - Yside/2.0);
        ofLine(RectOut.x+RectOut.width/4.0,
               RectOut.y+RectOut.height/2.0,
               RectOut.x+3*RectOut.width/4.0 - Xside/2.0,
               RectOut.height/2.0 + Yside/2.0);
        
    } // end if mode 0
    else if(JAMode==1){// regions
        ofSetColor(0, 0, 0);
        
        float TheSwitdh = Fuentes[3].stringWidth("Regions?");
        float TheHeight = Fuentes[3].stringHeight("Regions?");
        Fuentes[3].drawString("Regions?",ScreenX/10.0,Ypos+2*RectOut.height/20.0);
        ofSetHexColor(0xffffff);
        CvMemStorage* G_storage=NULL;
        G_storage=cvCreateMemStorage(0); 
        CvSeq* contour = 0;
        IplImage * TempBin;
        TempBin = cvCreateImage( cvSize(TheInputGray->width,TheInputGray->height),IPL_DEPTH_8U,1); 
        
        cvThreshold( TheInputGray, TempBin, 128, 255, CV_THRESH_BINARY );
        
        int NC=cvFindContours( TempBin, G_storage, &contour, sizeof(CvContour), CV_RETR_EXTERNAL, CV_CHAIN_APPROX_TC89_L1 );

        vector<ofVec2f> LargerContour;
        for( ; contour != 0; contour = contour->h_next )
        {
            
            
            if (contour->total > LargerContour.size()){
                
                LargerContour.clear();
                for(int k=0;k<contour->total;k++){
                    CvPoint* p = (CvPoint*)cvGetSeqElem( contour, k );
                   LargerContour.push_back(ofVec2f((float)p->x,(float)p->y));
                }
  
            } // end of if
            
            
        } // end of for contours
        
        
        
        
        ofPushMatrix();
            float Xini =RectOut.x+RectOut.width/4.0;
            float Yini = RectOut.y+RectOut.height/2.0;
            
        ofTranslate(RectOut.x+RectOut.width/4.0, RectOut.y+RectOut.height/2.0);
        ofScale(.5, .5);
        grayImage.draw(-grayImage.width/2.0, -grayImage.height/2.0);
        ofSetColor(200, 0, 0);
        ofSetLineWidth(4);
        glBegin(GL_LINE_STRIP);
            for(int k = 0; k< LargerContour.size();k++){
                glVertex2f(LargerContour[k].x-grayImage.width/2.0,
                           LargerContour[k].y-grayImage.height/2.0);
            }
        glEnd();

        
        ofPopMatrix();
        
        if (LargerContour.size()>10) {
            // ploting the larger contour
            float MaxX=LargerContour[0].x;
            float MinX=LargerContour[0].x;
            float MaxY=LargerContour[0].y;
            float MinY=LargerContour[0].y;
            float MeanX=LargerContour[0].x;
            float MeanY=LargerContour[0].y;
         
            for (int k=1; k<LargerContour.size(); k++) {
           
                MeanX+=LargerContour[k].x;
                MeanY+=LargerContour[k].y;
            
                if (LargerContour[k].x>MaxX) {
                    MaxX = LargerContour[k].x;
                }
                if (LargerContour[k].y>MaxY) {
                    MaxY = LargerContour[k].y;
                }     
                if (LargerContour[k].x<MinX) {
                    MinX = LargerContour[k].x;
                }
                if (LargerContour[k].y<MinY) {
                    MinY = LargerContour[k].y;
                }  
            }
            MeanX/=LargerContour.size();
            MeanY/=LargerContour.size();
            float RangeX = (MaxX+MinX)/2.0;
            float RangeY = (MaxY+MinY)/2.0;
        
        
            ofPushMatrix();
            Xini =RectOut.x+3*RectOut.width/4.0;
            Yini = RectOut.y+RectOut.height/2.0;
            ofTranslate(Xini, Yini);
            ofScale(.8, .8);
            ofSetColor(200, 0, 0);
            ofSetLineWidth(4);
            glBegin(GL_LINE_STRIP);
            for(int k = 0; k< LargerContour.size();k++){
                glVertex2f(LargerContour[k].x-RangeX,
                           LargerContour[k].y-RangeY);
            }
            glEnd();
            ofPopMatrix();
        
        }
        
    
        cvReleaseImage(&TempBin);
        // releasing mem storages
        if (contour!=NULL){cvClearSeq(contour);}
        //cvClearMemStorage(storage);
        if (G_storage!=NULL){cvReleaseMemStorage(&G_storage);}
    } // end if mode 1
    else if (JAMode==2){
        ofSetColor(0, 0, 0);
        
        float TheSwitdh = Fuentes[3].stringWidth("DCT coeficients?");
        float TheHeight = Fuentes[3].stringHeight("DCT coeficients?");
        Fuentes[3].drawString("DCT coeficients?",ScreenX/10.0,Ypos+2*RectOut.height/20.0);
        ofSetHexColor(0xffffff); 
        IplImage * TempFloat1;
        TempFloat1 = cvCreateImage( cvSize(TheInputGray->width,TheInputGray->height),IPL_DEPTH_32F,1); 
       
        IplImage * TempBin1;
        TempBin1 = cvCreateImage( cvSize(TheInputGray->width,TheInputGray->height),IPL_DEPTH_8U,1);  
        cvConvertScale(TheInputGray, TempFloat1);
        
        IplImage * TempColor;
        TempColor = cvCreateImage( cvSize(TheInputGray->width,TheInputGray->height),IPL_DEPTH_8U,3);  
        cvConvertScale(TheInputGray, TempFloat1);
        
        //Zeros image
        IplImage * BlackFloat;
        BlackFloat= cvCreateImage( cvSize(TheInputGray->width,TheInputGray->height),IPL_DEPTH_32F,1); 
        cvSetZero(BlackFloat);
        
        // The region
        CvRect TheRegion;
        TheRegion.x =0;
        TheRegion.y =0;
        TheRegion.width = Nx-2*((int)Nx*(Slider1/127.0)/2.0);
        TheRegion.height = Ny-2*((int)Ny*(Slider1/127.0)/2.0);
        
        //direct DCT
        cvDCT(TempFloat1, TempFloat1,CV_DXT_FORWARD);
        cvSetImageROI(BlackFloat, TheRegion);
        cvSetImageROI(TempFloat1, TheRegion);
        cvCopy(TempFloat1, BlackFloat);
        cvResetImageROI(TempFloat1);
        cvResetImageROI(BlackFloat);
        
        cvConvertScale(BlackFloat, TempBin1,40.0,0.0);
        
        ofxCvColorImage tempImage;
        tempImage.allocate(TheInputGray->width,TheInputGray->height);
         PseudoColor(TempBin1,TempColor);
        tempImage = TempColor;
        
        ofPushMatrix();
        float Xini =RectOut.x+3*RectOut.width/4.0;
         float Yini = RectOut.y+RectOut.height/2.0;
        ofTranslate(Xini, Yini);
        ofScale(.5, .5);
        tempImage.draw(-tempImage.width/2.0, -tempImage.height/2.0);
        ofPopMatrix();
        
        
        

        cvDCT(BlackFloat, BlackFloat, CV_DXT_INVERSE);
        cvConvertScale(BlackFloat, TempBin1);
        

        ofxCvGrayscaleImage TempGrayImage;
        TempGrayImage.allocate(TheInputGray->width,TheInputGray->height);
        TempGrayImage = TempBin1;
       
        //cvSetZero(TempColor);
        ofPushMatrix();
        Xini =RectOut.x+RectOut.width/4.0;     
        ofTranslate(RectOut.x+RectOut.width/4.0, RectOut.y+RectOut.height/2.0);
        ofScale(.5, .5);
        TempGrayImage.draw(-grayImage.width/2.0, -grayImage.height/2.0);
        ofPopMatrix();
        

        
        TempGrayImage.clear();
        tempImage.clear();
        cvReleaseImage(&BlackFloat);
         cvReleaseImage(&TempColor);
      cvReleaseImage(&TempBin1);
       cvReleaseImage(&TempFloat1);
    
    }

}
