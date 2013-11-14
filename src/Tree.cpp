//
//  Tree.cpp
//  Defense
//
//  Created by Javier Villegas on 6/7/12.
//  Copyright (c) 2012 UCSB. All rights reserved.
//

#include <iostream>
#include "defense.h"
void defense::TreeUpdate(){

      float dt = 0.25;
      float  ThDis =13.4;
      float  KtarTree = 19.25;
      float KdamTree = 2.05;
    
      TargetHitsTree.clear();
      TheTargetsTree.clear();

    float Alpha = 0.44;//Slider1/127.0;
    float Beta = 0.63;//Slider2/127.0;
    
    ofxCvGrayscaleImage Tempoview;
    Tempoview.allocate(HalfInputGray->width, HalfInputGray->height);
    Tempoview = HalfInputGray;
    
    for (int i = 0; i < Nx/2*Ny/2; i++) {
        px[i] = (uchar)(255*(Beta + (1-Beta )*pow((float)(Tempoview.getPixels()[i]/255.0),(float)Alpha)));
    }

    while (!PointQueueTree.empty()){
        PointQueueTree.pop();
    }
    BWTest (px, fixedThresholdPx, Nx/2, Ny/2); 
   
    TheTargetsTree.clear();
    TargetHitsTree.clear();
    ThePoints tempoPoint;
    int TheLimit = MIN(NtgTree,PointQueueTree.size());
    
    
    for (int k=0; k < TheLimit; k++){
        tempoPoint =PointQueueTree.top();
        TheTargetsTree.push_back(ofVec2f(tempoPoint.Pos.x,tempoPoint.Pos.y));
        PointQueueTree.pop();
     //   TargetHitsTree.push_back(tempoPoint.Error);
        TargetHitsTree.push_back(0);
    }
    
    

    if (!TheTargetsTree.empty()){     
        
        for(int i =0;i< NobTree;i++){
            TargIndTree[i]=-1;
        }
        
        for (int kt=0; kt<TheTargetsTree.size(); kt++) {
            float MinDis =10000;
            int MinIndi =0;
            //   TargetHits[kt]=0;
            for (int ko=0; ko<NobTree; ko++) {
                
                ofVec2f ErrorVec;
                ErrorVec = TheTargetsTree[kt]-TheObjectsTree[ko];
                float dis = ErrorVec.length();
                if ((dis < MinDis)&&(TargIndTree[ko]==-1)){
                    MinIndi = ko;  
                    MinDis = dis;
                }
            }
            TargIndTree[MinIndi] = kt;
            TargetHitsTree[kt]++;
        }
        
        
        for (int ko=0; ko<NobTree; ko++) {
            
            float minHits = 10000;
            ofVec2f UpdateVec;
            float MinDis =10000000;
            int MinIndi =0;
            
            if (TargIndTree[ko]==-1) {
                MinDis =10000;
                for (int kt=0; kt<TheTargetsTree.size(); kt++) {
                    ofVec2f ErrorVec;
                    ErrorVec = TheTargetsTree[kt]-TheObjectsTree[ko];
                    float dis = ErrorVec.length();
                    if (dis < MinDis){
                        MinDis = dis;  
                        MinIndi = kt;
                    }
                    
                }
                
                TargetHitsTree[MinIndi]++;          
                TargIndTree[ko] = MinIndi;
            }
            
            UpdateVec = TheTargetsTree[TargIndTree[ko]]-TheObjectsTree[ko];
            float newDis = UpdateVec.length();
            UpdateVec.normalize();
            
            
            ofVec2f acc;
            
            if (newDis < ThDis){
                acc = (newDis/10.0)*(KtarTree*UpdateVec) - KdamTree*TheVelocitiesTree[ko];
            }
            else{
                acc = (KtarTree*UpdateVec) - KdamTree*TheVelocitiesTree[ko];
            }
            TheVelocitiesTree[ko] = TheVelocitiesTree[ko] - (-dt)*acc;
            TheObjectsTree[ko]  =  TheObjectsTree[ko] - (-dt)*TheVelocitiesTree[ko];
        }
        
    }// closing the  if from target non empty
    
}
//
void defense::TreeDraw(int TMode){
    
    
    deque<ofVec2f> PosList1;
    
    deque<ofVec2f> PosList2;
    
    deque<ofVec2f> PosList3;
    
     ofVec2f CurrentPoint(320,10);
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    ofClear(255,255,255,255);
    ofSetColor(255, 255, 255,188);
    if (TMode==3) {
        FondoTree.draw(0,0,ScreenX,ScreenY);
    }

    float TheError = 10;
    int itThres = 0;
    float cordX1=0;
    float cordX2=0;
    float cordX3=0;
    
    float TreeThres1 = (Nx/2)/3.0;
    float TreeThres2 = 2*(Nx/2)/3.0;
    
    while ((TheError>2)&&(itThres<5)) {
        PosList1.clear();
        PosList2.clear();
        PosList3.clear();
        
        
        // coping the objects to the list
        // finding te center of mass
        // only using X coordinate
        
        cordX1=0;
        cordX2=0;
        cordX3=0;
        
        
        
        itThres++;
        int sideCounter1=0;
        int sideCounter2=0;
        int sideCounter3=0;
        
        for (int k=0; k < NobTree;k++){
            if (TheObjectsTree[k].x<TreeThres1) {
                cordX1+=TheObjectsTree[k].x;
                PosList1.push_back(ofVec2f(TheObjectsTree[k].x,TheObjectsTree[k].y)); 
                sideCounter1++;
            }
            else if((TheObjectsTree[k].x>=TreeThres1)&&(TheObjectsTree[k].x<TreeThres2))
            {
                cordX2+=TheObjectsTree[k].x;
                PosList2.push_back(ofVec2f(TheObjectsTree[k].x,TheObjectsTree[k].y)); 
                sideCounter2++;
            }
            else{
                cordX3+=TheObjectsTree[k].x;
                PosList3.push_back(ofVec2f(TheObjectsTree[k].x,TheObjectsTree[k].y)); 
                sideCounter3++;
            }
        }
        if (sideCounter1!=0){
            cordX1/=(float)sideCounter1;
        }
        else{
            cordX1 =  (Nx/2)/6.0;
        }
        if (sideCounter2!=0){
            cordX2/=(float)sideCounter2;
        }
        else{
            cordX2 =  (Nx/2)/2.0;
        }
        if (sideCounter3!=0){
            cordX3/=(float)sideCounter3;
        }
        else{
            cordX3 =  5*(Nx/2)/6.0;
        }       
        
        
        TheError = abs(TreeThres1-(cordX2+cordX1)/2.0)
        + abs(TreeThres2-(cordX3+cordX2)/2.0);
        
        TreeThres1 = cordX1  + (cordX2-cordX1)/2.0;
        TreeThres2 = cordX2  + (cordX3-cordX2)/2.0;
    }
    
    

    if (TMode==0) {
        ofSetColor(0, 0, 0);
        glPushMatrix();
        ofScale((ScreenX)/(Nx/2.0), ScreenY/(Ny/2.0));
        for (int c = 0; c<PosList1.size(); c++) {
            ofCircle(PosList1[c].x, PosList1[c].y, 1);
        }
        for (int c = 0; c<PosList2.size(); c++) {
            ofCircle(PosList2[c].x, PosList2[c].y, 1);
        }
        for (int c = 0; c<PosList3.size(); c++) {
            ofCircle(PosList3[c].x, PosList3[c].y, 1);
        }
        
        
        glPopMatrix();
    }
    
    
    if (TMode==1) {
        ofSetColor(0, 0, 0);
        glPushMatrix();
        ofScale((ScreenX)/(Nx/2.0), ScreenY/(Ny/2.0));
        for (int c = 0; c<PosList1.size(); c++) {
            ofCircle(PosList1[c].x, PosList1[c].y, 1);
        }
        for (int c = 0; c<PosList2.size(); c++) {
            ofCircle(PosList2[c].x, PosList2[c].y, 1);
        }
        for (int c = 0; c<PosList3.size(); c++) {
            ofCircle(PosList3[c].x, PosList3[c].y, 1);
        }
        ofSetColor(200, 0, 0);
        ofSetLineWidth(4);
        ofLine(TreeThres1,0,TreeThres1,Ny/2.0);
        ofLine(TreeThres2,0,TreeThres2,Ny/2.0);        
        glPopMatrix();
    }
    
    if (TMode==2) {
        ofSetColor(0, 0, 0);
        glPushMatrix();
        ofScale((ScreenX)/(Nx/2.0), ScreenY/(Ny/2.0));
        for (int c = 0; c<PosList1.size(); c++) {
            ofCircle(PosList1[c].x, PosList1[c].y, 1);
        }
        for (int c = 0; c<PosList2.size(); c++) {
            ofCircle(PosList2[c].x, PosList2[c].y, 1);
        }
        for (int c = 0; c<PosList3.size(); c++) {
            ofCircle(PosList3[c].x, PosList3[c].y, 1);
        }
        ofSetColor(200, 0, 0);
         ofSetLineWidth(4);
        ofLine(TreeThres1,0,TreeThres1,(Ny/2.0));
        ofLine(TreeThres2,0,TreeThres2,(Ny/2.0));
        ofSetColor(0, 0, 200,180);
  
        ofBeginShape();
            ofVertex(cordX1 -Nx/100.0,.99*Ny/2.0);
            ofVertex(cordX1 +Nx/100.0,.99*Ny/2.0);
            ofVertex(cordX1,.95*Ny/2.0);
            ofVertex(cordX1 -Nx/100.0,.99*Ny/2.0);
        ofEndShape();

        ofBeginShape();
            ofVertex(cordX2 -Nx/100.0,.99*Ny/2.0);
            ofVertex(cordX2 +Nx/100.0,.99*Ny/2.0);
            ofVertex(cordX2,.95*Ny/2.0);
            ofVertex(cordX2 -Nx/100.0,.99*Ny/2.0);
        ofEndShape();
        ofBeginShape();
            ofVertex(cordX3 -Nx/100.0,.99*Ny/2.0);
            ofVertex(cordX3 +Nx/100.0,.99*Ny/2.0);
            ofVertex(cordX3,.95*Ny/2.0);
        ofVertex(cordX3 -Nx/100.0,.99*Ny/2.0);
        ofEndShape();
        
     //   ofCircle(cordX1, (Ny/2.0), 2);
//        ofCircle(cordX2, (Ny/2.0), 2);
//        ofCircle(cordX3, (Ny/2.0), 2);
//        
        glPopMatrix();
    }
    if (TMode==3) {
        float Afact = .7;
        DrawCentralTreeSombra(PosList1,0, 0, Afact*(Nx/2.0), Afact*(Ny/2.0),ofVec2f(cordX1,(Ny/2.0)*1.15),.8);   
        DrawCentralTreeSombra(PosList2,0, 0, Afact*(Nx/2.0), Afact*(Ny/2.0),ofVec2f(cordX2,(Ny/2.0)*1.3),.9);     
        DrawCentralTreeSombra(PosList3,0, 0, Afact*(Nx/2.0), Afact*(Ny/2.0),ofVec2f(cordX3,(Ny/2.0)*1.24),.8); 
    }
    
    ofSetLineWidth(1);

}



void defense::DrawCentralTreeSombra(deque<ofVec2f> PosList,float x, float y, float width, float height,ofVec2f TargetPoint, float CenFac){
    
    
    deque<ofVec2f>savingHojas;
    
    savingHojas = PosList;
    
    
    glPushMatrix();
    
    ofTranslate(x, y);
    ofScale(width/(Nx/2.0),height/(Ny/2.0));
    
    
    float Xoffset =ScreenX*((Nx/2.0)/width)*(1.0-width/(Nx/2.0))/2.0;
    
    
    deque<ofVec2f> UpPos;
    
    float AlphaSombra = 24;
    float ColorSombra = 50;
    float ScaleHojas = 0.56;
    float SlopeSombra = -1.37;
    float ScaleXSombra = 1.0;
    float ScaleYSombra = 0.224;
    
    float ScaX = ScaleXSombra;
    float ScaY = ScaleYSombra;
    float mSom = SlopeSombra;
    float TroncoAlpha = 60;
    float G_ItFact=2/25.0;
    float Kn=2.9;
    float Kc=5.0;
    float joinTh=1;
    float  G_ThTarget = 25;
    
    float     BrincoR = 0.24;
    float BrincoG = 0.35; 
    ofSetColor(255,255,255  );
    
    
    
    ofSetColor(76,56,0,TroncoAlpha);
    
    
    
    int it  = 0;
    while ((PosList.size()>0)&&(it<500)) {
        it++;
        float dt = .2 + it/5000.0;
        
        
        UpPos.clear();
        // cout<<PosList.size()<<"\n";
        for (int c = 0; c<PosList.size(); c++) {
            float minDis =10000000;
            int minIndi = -1;
            if (PosList[c].x==-10000){
                continue;
            }
            for (int cn =c+1; cn<PosList.size();cn++){
                // looking  for the closer point
                if (PosList[cn].x!=-10000){
                    float dist =PosList[c].distanceSquared(PosList[cn]);
                    if (dist<minDis) {
                        minIndi = cn;
                        minDis=dist;
                    }
                 }
            }
            
            
            if (minIndi!=-1){
                ofVec2f TheF1;
                ofVec2f TheF2;
                ofVec2f LocalTarget;
                LocalTarget.x = TargetPoint.x;
                LocalTarget.y = TargetPoint.y - CenFac*(TargetPoint.y -MAX(PosList[c].y, PosList[minIndi].y));
                ofVec2f VecN = PosList[minIndi]-PosList[c];
                ofVec2f VecC1,VecC2;
                ofVec2f GradValueC;
                ofVec2f GradValueMinIndi;
                
                
                VecC1 = LocalTarget - PosList[c];
                //      VecC1.normalize();
                VecC2 = LocalTarget - PosList[minIndi];
                //    VecC2.normalize();
                
                
                VecN.normalize();
                VecC1.normalize();
                VecC2.normalize();
                float lKc;
                lKc = ((float)it*(G_ItFact))*Kc;
                
                TheF1 =VecC1*lKc + VecN*Kn;
                
                
                TheF2 = VecC2*lKc + VecN*(-Kn);
                
                
                // update position
                
                ofVec2f newPos1 = PosList[c]+ TheF1*dt;
                ofVec2f newPos2 = PosList[minIndi]+ TheF2*dt;
                
                
                
                // creating the new  list
                UpPos.push_back(newPos1);
                if (newPos1.distanceSquared(newPos2)>joinTh){
                    UpPos.push_back(newPos2);  
                    
                }
                else{
                    newPos2=newPos1;
                    
                    
                }
                
                // Ploting the sombra:
                
                
                
                ofSetColor(ColorSombra,ColorSombra,ColorSombra,AlphaSombra);
                
                
                float sx1,sx2,sy1,sy2,sx3,sy3,sx4,sy4;
                
                sx1 = PosList[c].x - TargetPoint.x;
                sy1 = PosList[c].y - TargetPoint.y;
                sx1 =  ScaX*sx1 + ScaY*mSom*sy1;
                sy1 = ScaY*sy1;
                
                
                sx2 = newPos1.x - TargetPoint.x;
                sy2 = newPos1.y - TargetPoint.y;
                sx2 =  ScaX*sx2 + ScaY*mSom*sy2;
                sy2 = ScaY*sy2;                
                
                sx3 = PosList[minIndi].x - TargetPoint.x;
                sy3 = PosList[minIndi].y - TargetPoint.y;
                sx3 =  ScaX*sx3 + ScaY*mSom*sy3;
                sy3 = ScaY*sy3;
                
                sx4 = newPos2.x - TargetPoint.x;
                sy4 = newPos2.y - TargetPoint.y;
                sx4 =  ScaX*sx4 + ScaY*mSom*sy4;
                sy4 = ScaY*sy4;               
                
                ofSetLineWidth(2);
                
                ofLine(Xoffset+(ScreenX/(float)(Nx/2.0))*(sx1+TargetPoint.x),
                       (ScreenY/(float)(Ny/2.0))*(sy1+TargetPoint.y),
                       Xoffset+(ScreenX/(float)(Nx/2.0))*(sx2+TargetPoint.x),
                       (ScreenY/(float)(Ny/2.0))*(sy2+TargetPoint.y)); 
                ofLine(Xoffset+(ScreenX/(float)(Nx/2.0))*(sx3+TargetPoint.x),
                       (ScreenY/(float)(Ny/2.0))*(sy3+TargetPoint.y),
                       Xoffset+(ScreenX/(float)(Nx/2.0))*(sx4+TargetPoint.x),
                       (ScreenY/(float)(Ny/2.0))*(sy4+TargetPoint.y));
                
                
                ofSetColor((1.2)*76,(1.2)*56,0,TroncoAlpha);
                
                if (it<10){
                    ofSetLineWidth(1);
                }
                if ((it>=10)&&(it<20)){
                    ofSetLineWidth(2);
                }  
                if ((it>=20)&&(it<100)){
                    ofSetLineWidth(4);
                }
                if (it>100){
                    ofSetLineWidth(5);
                }
                ofLine(Xoffset + (ScreenX/(float)(Nx/2.0))*PosList[c].x, 
                       (ScreenY/(float)(Ny/2.0))*PosList[c].y, 
                       Xoffset + (ScreenX/(float)(Nx/2.0))*newPos1.x, 
                       (ScreenY/(float)(Ny/2.0))*newPos1.y);
                ofLine(Xoffset + (ScreenX/(float)(Nx/2.0))*PosList[minIndi].x, 
                       (ScreenY/(float)(Ny/2.0))*PosList[minIndi].y,
                       Xoffset + (ScreenX/(float)(Nx/2.0))*newPos2.x, 
                       (ScreenY/(float)(Ny/2.0))*newPos2.y);   
                
                // Marking the points as used
                
                PosList[minIndi].x = -10000;
                PosList[c].x = -10000;
            }
            else{ //if not pair paint single
                
                ofVec2f TheF1;
                ofVec2f VecC;
                ofVec2f LocalTarget;
                LocalTarget.x = TargetPoint.x;
                LocalTarget.y = TargetPoint.y - CenFac*(TargetPoint.y -PosList[c].y);
                
                float lKc;
                lKc = ((float)it*(G_ItFact))*Kc;
                VecC = LocalTarget - PosList[c];
                VecC.normalize();
                TheF1 = VecC*lKc;
                ofVec2f newPos1 = PosList[c]+ TheF1*(dt);
                
                
                // Sombra
                
                
                
                
                ofSetColor(ColorSombra,ColorSombra,ColorSombra,AlphaSombra);
                
                float sx1,sx2,sy1,sy2;
                
                sx1 = PosList[c].x - TargetPoint.x;
                sy1 = PosList[c].y - TargetPoint.y;
                sx1 =  ScaX*sx1 + ScaY*mSom*sy1;
                sy1 = ScaY*sy1;
                
                
                sx2 = newPos1.x - TargetPoint.x;
                sy2 = newPos1.y - TargetPoint.y;
                sx2 =  ScaX*sx2 + ScaY*mSom*sy2;
                sy2 = ScaY*sy2;                
                
                
                ofSetLineWidth(2);
                
                ofLine(Xoffset+(ScreenX/(float)(Nx/2.0))*(sx1+TargetPoint.x),
                       (ScreenY/(float)(Ny/2.0))*(sy1+TargetPoint.y),
                       Xoffset+(ScreenX/(float)(Nx/2.0))*(sx2+TargetPoint.x),
                       (ScreenY/(float)(Ny/2.0))*(sy2+TargetPoint.y)); 
                
                
                
                
                
                
                ofSetColor((1.2)*76,(1.2)*56,0,TroncoAlpha);
                
                if (it<10){
                    ofSetLineWidth(1);
                }
                if ((it>=10)&&(it<20)){
                    ofSetLineWidth(2);
                }  
                if ((it>=20)&&(it<100)){
                    ofSetLineWidth(4);
                }
                if (it>100){
                    ofSetLineWidth(5);
                }
                ofLine(Xoffset+(ScreenX/(float)(Nx/2.0))*PosList[c].x, 
                       (ScreenY/(float)(Ny/2.0))*PosList[c].y, 
                       Xoffset+(ScreenX/(float)(Nx/2.0))*newPos1.x, 
                       (ScreenY/(float)(Ny/2.0))*newPos1.y);
                UpPos.push_back(newPos1);
                PosList[c].x = -10000;
            }
        }
        
        //  deleting the closer paths
        
        int c =0;
        while(c<UpPos.size()){
            
            ofVec2f VecC1;        
            if (UpPos[c].distanceSquared(TargetPoint)<G_ThTarget){
                if (it<10){
                    ofSetLineWidth(1);
                }
                if ((it>=10)&&(it<20)){
                    ofSetLineWidth(2);
                }  
                if ((it>=20)&&(it<100)){
                    ofSetLineWidth(4);
                }
                if (it>100){
                    ofSetLineWidth(5);
                }
                ofLine(Xoffset+(ScreenX/(float)(Nx/2.0))*UpPos[c].x, 
                       (ScreenY/(float)(Ny/2.0))*UpPos[c].y, 
                       Xoffset+(ScreenX/(float)(Nx/2.0))*TargetPoint.x, 
                       (ScreenY/(float)(Ny/2.0))*TargetPoint.y);
                //           (PlotY/(float)Nh)*(TargetPoint.y - .95*(TargetPoint.y -PosList[c].y)));
                UpPos.erase(UpPos.begin()+c);
            }
            else{
                c++;
            }
            
        }
        
        
        UpPos.swap(PosList);     
    }
    
    // Ploting the leaves
    // ofSetColor(140,140,140,255); original
    //    ofSetColor(100,100,100,200);
    for (int k=0; k<MIN(savingHojas.size(),TargetHitsTree.size()); k++) {
        
        
        
        ofVec2f CurrentPoint = savingHojas[k];
        
        ofVec2f LocalTarget;
        LocalTarget.x = TargetPoint.x;
        LocalTarget.y = TargetPoint.y - 0.0*TargetPoint.y;
        
        
        
        
        //ofVec2f VecC1 = TargetPoint - savingHojas[k];
        ofVec2f VecC1 = LocalTarget - savingHojas[k];
        
        
        // sombra
        
        ofSetColor(ColorSombra,ColorSombra,ColorSombra,.8*AlphaSombra);
        float RotAngle =atan2(VecC1.y, VecC1.x);
        
        float sx1,sx2,sy1,sy2;
        
        sx1 = CurrentPoint.x - TargetPoint.x;
        sy1 = CurrentPoint.y - TargetPoint.y;
        sx1 =  ScaX*sx1 + ScaY*mSom*sy1;
        sy1 = ScaY*sy1;
        glPushMatrix(); 
        ofTranslate(Xoffset + (ScreenX/(float)(Nx/2.0))*(sx1+TargetPoint.x),(ScreenY/(float)(Ny/2.0))*(sy1+TargetPoint.y));
        ofRotate(90 +(180*RotAngle/CV_PI)-180);
        //     ofTranslate(Xoffset + (PlotX/(float)Nw)*(CurrentPoint.x),(PlotY/(float)Nh)*CurrentPoint.y);  
        ofScale(1.5*ScaX*ScaleHojas,1.5*ScaY*ScaleHojas);  
        //        //    // //old      // ofScale(.032,.032);
        Hojas.draw(-Hojas.width/2.0,-Hojas.height);
        glPopMatrix();
        
        
        
        
        float TheValueR = 136.5+(255-136.5)*BrincoR*CurrentPoint.distance(
                        ofVec2f((Nx/2.0),(Ny/2.0)))/sqrt((Nx/2.0)*(Nx/2.0)+(Ny/2.0)*(Ny/2.0));
        float TheValueG = 150.5+(255-150.5)*BrincoG*CurrentPoint.distance(
                        ofVec2f((Nx/2.0),(Ny/2.0)))/sqrt((Nx/2.0)*(Nx/2.0)+(Ny/2.0)*(Ny/2.0));
        
        
        ofSetColor(TheValueR,TheValueG,66.2,200);
        //float RotAngle =atan2(VecC1.y, VecC1.x);
        glPushMatrix();  
        ofTranslate(Xoffset + (ScreenX/(float)(Nx/2.0))*(CurrentPoint.x),(ScreenY/(float)(Ny/2.0))*CurrentPoint.y);
        ofRotate(90 +(180*RotAngle/CV_PI)-180);
        ofScale(ScaleHojas,ScaleHojas);  
        //    // //old      // ofScale(.032,.032);
        Hojas.draw(-Hojas.width/2.0,-Hojas.height);
        glPopMatrix(); 
        
        
        
        
    }
    
    
    
    glPopMatrix(); 
}



void defense::BWTest(const unsigned char * src, unsigned char * dst, int w, int h) {
    
    int pxPos;
    int oldPx = 0;
    int newPx = 0;
    int qError = 0;
    
    int threshold = 130;//G_DithThreshold;
    memcpy(dst, src, w*h);
    int r1, r2,  bl1, bc1, br1, bc2;
    int new1,new2;
    for (int j = 0; j < h-2; j++) {
        for (int i = 1; i < w-2; i++) {
            pxPos = j*w+i;
            oldPx = dst[j*w+i];
            newPx = oldPx < threshold ? 0 : 255;
            dst[j*w+i] = newPx;
            
            qError = oldPx - newPx;
            
            //if (qError <0)
            {qError*=2*(0.5)/*G_ThresWhiter*/;}
            
            // super duper ugly 2 part value clipping (to avoid values beyond 0-255)
            r1  = MIN(dst[j*w+(i+1)]     + (int)(.125f * qError), 255);
            r2  = MIN(dst[j*w+(i+2)]     + (int)(.125f * qError), 255);
            bl1 = MIN(dst[(j+1)*w+(i-1)] + (int)(.125f * qError), 255);
            bc1 = MIN(dst[(j+1)*w+(i)]   + (int)(.125f * qError), 255);
            br1 = MIN(dst[(j+1)*w+(i+1)] + (int)(.125f * qError), 255);
            bc2 = MIN(dst[(j+2)*w+(i)]   + (int)(.125f * qError), 255);
            //            new1 = MIN(dst[(j+1)*w+(i+2)] + (int)(.125f * qError), 255);
            //            new2 = MIN(dst[(j+2)*w+(i+1)]   + (int)(.125f * qError), 255);
            
            
            dst[j*w+(i+1)]     = MAX(r1 , 0);
            dst[(j+1)*w+(i-1)] = MAX(bl1, 0);
            dst[(j+1)*w+(i)]   = MAX(bc1, 0);
            dst[(j+1)*w+(i+1)] = MAX(br1, 0);
            dst[(j+2)*w+(i)]   = MAX(bc2, 0);
            //            dst[(j+1)*w+(i+2)] = MAX(new1, 0);
            //            dst[(j+2)*w+(i+1)]   = MAX(new2, 0);            
            if (qError>0){
                PointQueueTree.push(ThePoints(Nx/2-i,j,qError));
            }
            
        }
    }
}
