//
//  SomeTCSlides.cpp
//  Defense
//
//  Created by Javier Villegas on 6/3/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"



void defense::TheMatchingProblem(){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofImage RevIma;
    ofSetColor(0, 0, 0 );
    Fuentes[0].drawString("The Problem",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    
    ofSetColor(255,255,255 );
    int TheWi;
    
             RevIma.loadImage("TemporalCoherence/matchingProblem.png");
            ofPushMatrix();
            ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y);
            ofScale(.9, .9);
            RevIma.draw(-RevIma.width/2.0,-RevIma.height/2.0);
            ofPopMatrix();
//            ofSetColor(0, 0, 0 );
//            TheWi=Fuentes[3].stringWidth("Studies on Perception I, Kenneth Knowlton 1966");
//            Fuentes[3].drawString("Studies on Perception I, Kenneth Knowlton 1966",
//                                  (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);


}



void defense::MinMaxEquation(){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofImage RevIma;
    ofSetColor(0, 0, 0 );
//    Fuentes[0].drawString("The Problem",
  //                        RectOut.x,RectOut.y + RectOut.height*.1);
    
    ofSetColor(255,255,255 );
    int TheWi;
    
    RevIma.loadImage("TemporalCoherence/MinSumEquations.png");
    ofPushMatrix();
    ofTranslate((RectOut.getCenter()).x -RectOut.width/8.0,(RectOut.getCenter()).y);
    ofScale(1.2, 1.1);
    RevIma.draw(-RevIma.width/2.0,-RevIma.height/2.0);
    ofPopMatrix();
    //            ofSetColor(0, 0, 0 );
    //            TheWi=Fuentes[3].stringWidth("Studies on Perception I, Kenneth Knowlton 1966");
    //            Fuentes[3].drawString("Studies on Perception I, Kenneth Knowlton 1966",
    //                                  (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);
    
    
}

void defense::BottleNeckEquation(){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofImage RevIma;
    ofSetColor(0, 0, 0 );
    //    Fuentes[0].drawString("The Problem",
    //                        RectOut.x,RectOut.y + RectOut.height*.1);
    
    ofSetColor(255,255,255 );
    int TheWi;
    
    RevIma.loadImage("TemporalCoherence/BottleneckEquations.png");
    ofPushMatrix();
    ofTranslate((RectOut.getCenter()).x -RectOut.width/8.0,(RectOut.getCenter()).y);
    ofScale(1.2, 1.1);
    RevIma.draw(-RevIma.width/2.0,-RevIma.height/2.0);
    ofPopMatrix();
    //            ofSetColor(0, 0, 0 );
    //            TheWi=Fuentes[3].stringWidth("Studies on Perception I, Kenneth Knowlton 1966");
    //            Fuentes[3].drawString("Studies on Perception I, Kenneth Knowlton 1966",
    //                                  (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);
    
    
}

// gradient blocks

void defense::GradientBlocks(){
    ofRectangle RectOut;
    RectOut = OneBigRect();
    ofImage RevIma;
    ofSetColor(0, 0, 0 );
    Fuentes[0].drawString("The Gradient Based Approach",
                          RectOut.x,RectOut.y + RectOut.height*.1);
    
    ofSetColor(255,255,255 );
    int TheWi;
    
    RevIma.loadImage("TemporalCoherence/generativeBlocks.jpg");
    ofPushMatrix();
    ofTranslate((RectOut.getCenter()).x,(RectOut.getCenter()).y + RectOut.height*.12);
    ofScale(.5, .5);
    RevIma.draw(-RevIma.width/2.0,-RevIma.height/2.0);
    ofPopMatrix();
    //            ofSetColor(0, 0, 0 );
    //            TheWi=Fuentes[3].stringWidth("Studies on Perception I, Kenneth Knowlton 1966");
    //            Fuentes[3].drawString("Studies on Perception I, Kenneth Knowlton 1966",
    //                                  (RectOut.getCenter()).x -TheWi/2.0,RectOut.y + .88*RectOut.height);
    
    
}



