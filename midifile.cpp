//
//  midifile.cpp
//  Defense
//
//  Created by Javier Villegas on 6/1/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"

void defense::newMidiMessage(ofxMidiEventArgs& eventArgs) {
	
	// store some data from midi message in variables
	byteOne = eventArgs.byteOne;
	byteTwo = eventArgs.byteTwo;
    TheStatus = eventArgs.status;
    id = eventArgs.channel;
	port = eventArgs.port;
	timestamp = eventArgs.timestamp;
    chanel = eventArgs.channel;
    //    cout<<"byteOne:"<<byteOne<<"\n";
    //	cout<<"byteTwo:"<<byteTwo<<"\n";
    //    cout<<"TheStatus:"<<TheStatus<<"\n";
    //    cout<<"id:"<<id<<"\n";
    //    cout<<"port:"<<port<<"\n";
    //    cout<<"channel:"<<chanel<<"\n";
    //cout<<"timestamp:"<<timestamp<<"\n"; 
    switch (byteOne) {
        case 0:
            if ((byteTwo>-1)&&(byteTwo<128)){
                Slider1 = byteTwo;
            }
            break;
        case 1:
            if ((byteTwo>-1)&&(byteTwo<128)){
                Slider2 = byteTwo;
         }
            break;   
            
        case 2:
            if ((byteTwo>-1)&&(byteTwo<128)){
                Slider3 = byteTwo;
            }
            break; 
            
        case 3:
            if ((byteTwo>-1)&&(byteTwo<128)){
                    Slider4 = byteTwo;
                
            }
            break; 
        case 4:
            if ((byteTwo>-1)&&(byteTwo<128)){
                Slider5 = byteTwo;
              }
            break;             
        case 5:
            if ((byteTwo>-1)&&(byteTwo<128)){

            }
            break;  
        case 6:
            if ((byteTwo>-1)&&(byteTwo<128)){

            }
            break;            
//        case 41:// Video Player
//            if ((byteTwo>100)&&(byteTwo<128)){
//                if (VideoIsPlaying==false){
//                    vidGrabber.close();
                    
//                if((InterMode==0)&&(CurrentSlide.compare("VideoReview")==0)){
//                    Mov.setUseTexture(false);
//                    Mov.loadMovie("review/" + videoNames[InterMode]);
//                    Mov.play();
//                    VideoIsPlaying = true;
//                }
//                if((InterMode==0)&&((CurrentSlide.compare("VideoNPR")==0))){
//                    Mov.setUseTexture(false);
//                    Mov.loadMovie("review/" + videosNPR[InterMode]);
//                    Mov.play();
//                    VideoIsPlaying = true;
//                }      
//            }
//                
//            }
//            break;  
        case 42:// Stop
            if ((byteTwo>100)&&(byteTwo<128)){
//                if(VideoIsPlaying){
//                     VideoIsPlaying = false;
//                    Mov.stop();
//                    Mov.closeMovie();  
//                  //vidGrabber.initGrabber(Nx,Ny);
//                
//                }
         
            }
            break;  
        case 44:// Slide +
            if ((byteTwo>100)&&(byteTwo<128)){
                InterMode=0;
                SlideCounter++;
                if (SlideCounter>keyString.size()-1){SlideCounter=0;}
            
            if(VideoIsPlaying){
                VideoIsPlaying = false;
                Mov.stop();
                Mov.closeMovie();  
                vidGrabber.initGrabber(Nx,Ny);
                
            }
            // cleaning 
            avMat.clear();
            TheTargetsEllipses.clear();
            TheCoherentEllipses.clear();
            ArrayOfContours.clear();
            ContourGray.clear();
            LineVec.clear();
         //   PointsList.clear();
        //    SortedPoints.clear();
            }
            
            break;   
        case 45:// Reset   
            if ((byteTwo>100)&&(byteTwo<128)){
            for (int  k=0; k<NGradCirs; k++) {
                GradientCircs[k].set(ofRandom(Nx), ofRandom(Ny));
                VelsGradient[k].set(0.0, 0.0);
            }
            
            for (int k=0; k<NOBJTargDemo; k++) {
                TheObjectsTargDemo[k].set(ofRandom(Nx), ofRandom(Ny));
                TheVelocitiesTargDemo[k].set(0.0, 0.0);
                TargIndTargDemo[k]=-1;
            }
            
            for (int k=0; k<NTARTargDemo; k++) {
                TheTargetsTargDemo[k].set(ofRandom(Nx), ofRandom(Ny));
            }
                
                if (CurrentSlide.compare("TargetsAlgorithm")==0) {
                    InterMode=0;
                }
                
                for(int i =0;i< NobGood;i++){
                    
                    
                    TheObjectsGood[i].set(ofRandom(Nx),ofRandom(Ny));
                    TargIndGood[i] =-1;
                    TheVelocitiesGood[i].set(0.0,0.0);
                    
                }   
                

                for (int k =0; k < MaxEllip ; k++){
                    
                    TheObjectsEllip[k].set(ofRandom(Nx),ofRandom(Ny),ofRandom(6,Nx/14.0),ofRandom(6,Nx/14.0),ofRandom(180),ofRandom(255));
                    TheVelocitiesEllip[k].set(0.0,0.0,0.0,0.0,0.0,0.0);
                }
                
                
                
            }
            
            break;
            
        case 43:// Slide -
            if ((byteTwo>100)&&(byteTwo<128)){
                InterMode=0;
                SlideCounter--;
                if (SlideCounter<0) {SlideCounter=keyString.size()-1;}  
            
            if(VideoIsPlaying){
                VideoIsPlaying = false;
                Mov.stop();
                Mov.closeMovie();  
                vidGrabber.initGrabber(Nx,Ny);
                
            }
            // cleaning 
            avMat.clear();
            TheTargetsEllipses.clear();
            TheCoherentEllipses.clear();
            ArrayOfContours.clear();
            ContourGray.clear();
            LineVec.clear();
         //   PointsList.clear();
        //    SortedPoints.clear();
            }   
            break; 
        case 62: // Inter Slide +
            if ((byteTwo>100)&&(byteTwo<128)){
                InterMode++;
                if(InterMode>MaxMode-1){InterMode=0;}
                if(VideoIsPlaying){
                    VideoIsPlaying = false;
                    Mov.stop();
                    Mov.closeMovie();  
                    if(CurrentSlide.compare("VideoReview")==0){
                        Mov.setUseTexture(false);
                        Mov.loadMovie("review/" + videoNames[InterMode]);
                        Mov.play();
                        VideoIsPlaying = true;
                    }
                    if(CurrentSlide.compare("VideoNPR")==0){
                        Mov.setUseTexture(false);
                        Mov.loadMovie("review/" + videosNPR[InterMode]);
                        Mov.play();
                        VideoIsPlaying = true;
                    }
                }
            }
            break;         
        case 61: //Inter Slide -
            if ((byteTwo>100)&&(byteTwo<128)){
                InterMode--;
                if(InterMode<0){InterMode=MaxMode-1;} 
                if(VideoIsPlaying){
                    VideoIsPlaying = false;
                    Mov.stop();
                    Mov.closeMovie();  
                    if(CurrentSlide.compare("VideoReview")==0){
                        Mov.setUseTexture(false);
                        Mov.loadMovie("review/" + videoNames[InterMode]);
                        Mov.play();
                        VideoIsPlaying = true;
                    }
                    if(CurrentSlide.compare("VideoNPR")==0){
                        Mov.setUseTexture(false);
                        Mov.loadMovie("review/" + videosNPR[InterMode]);
                        Mov.play();
                        VideoIsPlaying = true;
                    }  
                }
            	}
            break;     
            
   
        case 39:// saving the frames for a very particular objectve
            if ((byteTwo>100)&&(byteTwo<128)){
                
                Slider1 =60;
                Slider2 =60;
                Slider3 =60;
                
            }
            break;  
            
        case 64:// saving the frames for a very particular objectve
            if ((byteTwo>100)&&(byteTwo<128)){
                
                SlideCounter =0;
                InterMode = 0;
            }
            break;         
            
        case 65:// saving the frames for a very particular objectve
            if ((byteTwo>100)&&(byteTwo<128)){
                
                SlideCounter =0;
                InterMode = 3;
                
            }
            break;   
        case 66:// saving the frames for a very particular objectve
            if ((byteTwo>100)&&(byteTwo<128)){
                
                SlideCounter =1;
                InterMode = 1;
            }
            break;   
        case 67:// saving the frames for a very particular objectve
            if ((byteTwo>100)&&(byteTwo<128)){
                
                SlideCounter =2;
                InterMode = 0;
                
            }
            break;   
        case 68:// saving the frames for a very particular objectve
            if ((byteTwo>100)&&(byteTwo<128)){
                
                SlideCounter =3;
                InterMode = 0;
            }
            break;   
        case 69:// saving the frames for a very particular objectve
            if ((byteTwo>100)&&(byteTwo<128)){
                
                SlideCounter =5;
                InterMode = 0;
                
            }
            break;   
        case 70:// saving the frames for a very particular objectve
            if ((byteTwo>100)&&(byteTwo<128)){
                
                SlideCounter =6;
                InterMode = 0;
                
            }
            break;   
        case 71:// saving the frames for a very particular objectve
            if ((byteTwo>100)&&(byteTwo<128)){
                
                SlideCounter =7;
                InterMode = 0;
            }
            break;   
            
        case 32:// saving the frames for a very particular objectve
            if ((byteTwo>100)&&(byteTwo<128)){
                
                SlideCounter =8;
                InterMode = 0;
                
            }
            break;   
        case 33:// saving the frames for a very particular objectve
            if ((byteTwo>100)&&(byteTwo<128)){
                
                SlideCounter =9;
                InterMode = 0;
            }
            break;   
            
            
            
    
    }
    
}
