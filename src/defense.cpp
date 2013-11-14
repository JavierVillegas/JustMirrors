#include "defense.h"



//--------------------------------------------------------------
void defense::setup(){

 

        vidGrabber.setVerbose(true);
       vidGrabber.initGrabber(Nx,Ny);

     colorImg.allocate(Nx,Ny);
	grayImage.allocate(Nx,Ny);
    TheInputGray = cvCreateImage(cvSize(Nx, Ny), 8, 1);
    TheInputRGB = cvCreateImage(cvSize(Nx, Ny), 8, 3);

    // The fonts  for 1280 x 800
     Fuentes[0].loadFont("helveticaBold.ttf", 34,true,true,false);
     Fuentes[1].loadFont("helvetica.ttf", 30,true,true,false);
     Fuentes[2].loadFont("helveticaBold.ttf", 20,true,true,false);
     Fuentes[3].loadFont("helvetica.ttf", 20,true,true,true);
    Fuentes[4].loadFont("helveticaBold.ttf", 40,true,true,false);
    
    //  keyString.push_back("CaptureSlideJul26");
//    keyString.push_back("TitleSlide");
//    keyString.push_back("TableContentSlide");
//    keyString.push_back("IntroductionTitle");
//    keyString.push_back("DefinitionsSlide");
//    keyString.push_back("JustAnalysis");
//    keyString.push_back("BlockDiagram");
 //   keyString.push_back("ScopeAndLimitationsSlide");

//    keyString.push_back("ReviewTitle");
  //  keyString.push_back("Autotune");
   // keyString.push_back("Vocoder");
 //   keyString.push_back("ImageReview");
 //   keyString.push_back("VideoNPR");
 //   keyString.push_back("VideoReview");
 //   keyString.push_back("MediaArtReview");
 //   keyString.push_back("CreativeCodingEra");
 //   keyString.push_back("RedrawingTitle");
    keyString.push_back("RedrawingRegions");
    keyString.push_back("EdgesAndLines");
    keyString.push_back("OrientationSlide");
 //   keyString.push_back("SizeSlide");
  //  keyString.push_back("ShapeSlide");

//    keyString.push_back("Transcoding");
 //   keyString.push_back("TemporalCoherencyTitle");
//    keyString.push_back("TemCoherenceContent");
//    keyString.push_back("MatchingTitle");
  //  keyString.push_back("TheMatchingProblem");
//    keyString.push_back("NCcir");
   // keyString.push_back("NCcirMatched");
//    keyString.push_back("MinMaxEquation");
//    keyString.push_back("MinMaxcir");
//    keyString.push_back("BottleNeckEquation");
//    keyString.push_back("BottleNeckCir");
//    keyString.push_back("DirectionFiltCir");
//    keyString.push_back("GradientTitle");
  //  keyString.push_back("GradientBlocks");
  //  keyString.push_back("ArrowsDraw");

    
//    keyString.push_back("MobileMirrors");
//    keyString.push_back("AngleShift");
//    keyString.push_back("MeshMobile");
//    keyString.push_back("FutureWorkNonCoherent");
    keyString.push_back("DensitySlide");
    keyString.push_back("Connectedness");
//    keyString.push_back("FutureWorkMobile");
    
    
 //   keyString.push_back("DisTrans");
//    keyString.push_back("GradientCircs");
//    keyString.push_back("TargetsTitle");  
//    keyString.push_back("TargetsAlgorithm"); 
    //keyString.push_back("TargetEllipseExample");
     keyString.push_back("EllipwithTarget");
    keyString.push_back("MeshFlow");
//    keyString.push_back("GoodFeaturesExample");
   // keyString.push_back("ComparisionTitle");
   // keyString.push_back("HistoJumps");
   // keyString.push_back("JerKBar");
  //  keyString.push_back("SmoothVsQual");
  //  keyString.push_back("Dispersion");
 //   keyString.push_back("CrossSynthesisTitle");
 //   keyString.push_back("CrossContent");
//    keyString.push_back("AmbiguousSlide");
//    keyString.push_back("SubstitutionTitle"); 
    keyString.push_back("Mixing");
//    keyString.push_back("Bagette");

    keyString.push_back("Hormigas");
//    keyString.push_back("DirectTitle");  
 //   keyString.push_back("TemplateMatching");
  //  keyString.push_back("StatesSlide");
   // keyString.push_back("ViterbiSlide");
 //   keyString.push_back("TemplateDemo");
  //  keyString.push_back("GenerativeTitle");
    keyString.push_back("Tree");
    
  //  keyString.push_back("DiscussionSlide");
  //  keyString.push_back("ContributionsSlide");
  //  keyString.push_back("ExtensionsSlide");
//    keyString.push_back("FutureSlide");
 //   keyString.push_back("QuestionsSlide");
    //  keyString.push_back("TreeDemo");
    
    SlideCounter =0;
    InterMode = 0;
   // ofBackground(14,113,180);
     ofBackground(255,255,255);
    // Ellipse Initialization
    for (int k =0; k < MaxEllip ; k++){
        
        TheObjectsEllip[k].set(ofRandom(Nx),ofRandom(Ny),ofRandom(6,Nx/14.0),ofRandom(6,Nx/14.0),ofRandom(180),ofRandom(255));
        TheVelocitiesEllip[k].set(0.0,0.0,0.0,0.0,0.0,0.0);
    }
    
    // video names
    videoNames.push_back("ahaseg.mov");
    videoNames.push_back("WSseg.mov");
    videoNames.push_back("Beckseg.mov");
    videoNames.push_back("NINseg.mov");
    videoNames.push_back("ankleseg.mov");
    videoNames.push_back("Houseseg.mov");
    videoNames.push_back("Fragileseg.mov");
    videoNames.push_back("Brunosmall.mov");
    
    videosNPR.push_back("SF.mov");
    videosNPR.push_back("anipaint.mov");
    videosNPR.push_back("VideoMosaics.mov");
    
    // midi
    midiIn.listPorts();
	midiIn.openPort(0);
    midiIn.addListener(this);

    Slider1=0;
    Slider2=0;
    // audio
    
  //  int bufferSize = 2048;
	
	
//	left.assign(bufferSize, 0.0);
//	right.assign(bufferSize, 0.0);	
    
//    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
       VideoIsPlaying = false;
    vector<ofVec3f> TempoVec;
    avMat.clear();
    for (int k =0; k<AvMaxX; k++) {
        TempoVec.clear();
        for (int q=0; q<AvMaxY; q++) {
            TempoVec.push_back(ofVec3f(0.0,0.0,0.0));
        }
        avMat.push_back(TempoVec);
    }
    
    
    ArrayOfContours.clear();
    ContourGray.clear();
    LineVec.clear();
    
    NumOfSquares = ofVec2f(64,48);
    Destino = cvCreateImage(cvSize(NumOfSquares.x, NumOfSquares.y), 8, 1);
    CircsFrameCount = 1;
    BetweenFrames =0;
    MaxBetweener =5;
    
    for (int k=0; k<Ncirs; k++) {
        VelCirc[k].x =0;
        VelCirc[k].y =0;
        TheCircPos[k].x =0;
        TheCircPos[k].y =0;
    }
    
    G_ka = 3.35;
    G_Dammping = 2.45;
    
    ofSetFrameRate(30);
    
    G_kMesh=4.0; // elastic constant	
	G_kgMesh=0.15; // gradient factor
	G_kdMesh=3; // drag constant
	G_Gx=cvCreateImage( cvSize(Nx,Ny), IPL_DEPTH_16S, 1);
	G_Gy=cvCreateImage( cvSize(Nx,Ny), IPL_DEPTH_16S, 1);
	cvSetZero(G_Gx);
	cvSetZero(G_Gy);
    
    for(int k=0;k<MeshX;k++){
		for(int q=0;q<MeshY;q++){
			G_posX[k][q]=(float)k*(Nx)/(float)(MeshX);
			G_posY[k][q]=(float)q*(Ny)/(float)(MeshY);
			G_velX[k][q]=0;
			G_velY[k][q]=0;
            G_PrevX[k][q]=G_posX[k][q];
			G_PrevY[k][q]=G_posY[k][q];
		}	
	}
    
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
    
      
    for(int i =0;i< NobGood;i++){
        
        
        TheObjectsGood[i].set(ofRandom(Nx),ofRandom(Ny));
        TargIndGood[i] =-1;
        TheVelocitiesGood[i].set(0.0,0.0);
        
    }
    
    // Hormigas Setup
    
    for (int k=1; k<7; k++) {
        LasHormigas[k-1].loadImage("Cross/AntN" + ofToString(k)+".png");
    }
    FondoHormigas.loadImage("Cross/Suelo1024.jpg");
    for(int i =0;i< NobHormigas;i++){
        
        
        TheObjectsHormigas[i].set(ofRandom(Nx),ofRandom(Ny));
        TargIndHormigas[i] =-1;
        TheVelocitiesHormigas[i].set(0.0,0.0);
        RandAngleHormigas[i] = ofRandom(360);
        AntState[i] = (int) ofRandom(6);
        
    }
    KtarHormigas = 20.0;
    KdamHormigas = 1.05;
    G_QualityHormigas=0.001;
    G_minDistanceHormigas=8;
    
    
    /// Templates setup
    
    ofFile lafile;
    char * pointBuff;
    Float32 Objfloat[4*NobTemplates];

    
    
    // loading the images
    for (int k=0; k<NT; k++) {
        Templates[k].loadImage("Cross/SA" + ofToString(k+1)+".png");
    }
    
    for (int frames=NiniFrame; frames <= NEndFame; frames++) {
        
        // opening the file of objects
        lafile.open(ofToDataPath("Cross/BinFiles/ZBetaBinOutA" + ofToString(frames)+".bin"),
                    //  lafile.open(ofToDataPath("Grande240.bin"),
                    ofFile::ReadOnly, false); 
        ofBuffer buffy = lafile.readToBuffer();
        lafile.close();
        pointBuff = buffy.getBinaryBuffer();
        memcpy(Objfloat, pointBuff, 4*NobTemplates*sizeof(Float32));
        // filling the object array
        for (int oc =0; oc<NobTemplates; oc++) {
            (TheBins[oc][frames-NiniFrame]).x = (float)Objfloat[oc];
            (TheBins[oc][frames-NiniFrame]).y = (float)Objfloat[oc+NobTemplates];
            (TheBins[oc][frames-NiniFrame]).z = (float)Objfloat[oc+2*NobTemplates];
            (TheBins[oc][frames-NiniFrame]).w = (float)Objfloat[oc+3*NobTemplates]-1;
        }
        
        
        buffy.clear();
    }

    G_CurrentTargetInterpol=2;
    G_NewTargetInterpol=2;
    
    
    for (int oc=0; oc<NobTemplates;oc++) {
        XTemplates[oc].x= ofRandom(Nx/4.0);
        XTemplates[oc].y= ofRandom(Ny/4.0);
        VelTemplates[oc]= ofVec2f(0.0,0.0);
        TheAngleTemplates[oc]=0.0;
        WTemplates[oc]=0.0;
        for (int sc=0; sc <G_CurrentTargetInterpol; sc++) {
            (TheState[oc]).push_back(8);
        }
    }
    G_kaTemplates = 7.35;
    G_DammpingTemplates = 2.45;
    G_PowTemplates=1.0;
    
    // boolean for capture
    booleanforCapture = false;
    
    // Setup para el tree.
    // Tree Setup
    
    // The backkground image
    FondoTree.loadImage("Cross/TreeBg.png");
    Hojas.loadImage("Cross/TranspLeavesRotBRsGRAY.png");
    //Hojas.loadImage("Cross/TranspLeavesRotBR.png");
    for(int i =0;i< NobTree;i++){  
        TheObjectsTree[i].set(0,0);
        TargIndTree[i] =-1;
        TheVelocitiesTree[i].set(0.0,0.0);
    }
    TheTargetsTree.clear();
    // allocate image fro halfthe size  
    HalfInputGray = cvCreateImage(cvSize(Nx/2, Ny/2), 8, 1);
    
    //  HalfgrayImage.allocate(Nx, Ny);
    
    // the pointers arrays with half size
    px    = new unsigned char [Nx/2*Ny/2];
    fixedThresholdPx  = new unsigned char [Nx/2*Ny/2];
    

    
    
    
    FrameNumber = 0;
    
    // nom empty sliders
    
     Slider1 =60;
    Slider2 =60;
    Slider3 =60;
    Slider4 =60;
    Slider5 =60;
    
    
    
}

//--------------------------------------------------------------
void defense::update(){
    
 
    CurrentSlide = keyString[SlideCounter];
    if(VideoIsPlaying == false){
    bool bNewFrame = false;
    vidGrabber.update();
    bNewFrame = vidGrabber.isFrameNew();
	if (bNewFrame){
       colorImg.setFromPixels(vidGrabber.getPixels(), Nx,Ny);
       colorImg.mirror(false, true);
       TheInputRGB = colorImg.getCvImage(); 
       grayImage = colorImg;
       TheInputGray = grayImage.getCvImage();
       cvResize(TheInputGray, HalfInputGray);
    }
    
    }
    
    if ((CurrentSlide.compare("BlockDiagram")==0)&&(InterMode>0)){
        ImageToEllipseList(TheInputGray, 16);
        CoherentEllipses();
        
    }
    

    if ((CurrentSlide.compare("VideoReview")==0)&&(VideoIsPlaying)){
        Mov.idleMovie();
    }
    
    if ((CurrentSlide.compare("VideoNPR")==0)&&(VideoIsPlaying)){
        Mov.idleMovie();
    }
    
    if ((CurrentSlide.compare("RedrawingRegions")==0)&&(InterMode<2)){
        updateMat();
    }
    
    if ((CurrentSlide.compare("RedrawingRegions")==0)&&(InterMode==3)){
    ImgToContours(TheInputGray,14,0);
    } 
    if ((CurrentSlide.compare("RedrawingRegions")==0)&&(InterMode==4)){
        ImgToContours(TheInputGray,8,1);
    } 
    if ((CurrentSlide.compare("EdgesAndLines")==0)&&(InterMode==1)){
        ImgToLineList();
    } 
    
    if ((CurrentSlide.compare("OrientationSlide")==0)||
        (CurrentSlide.compare("SizeSlide")==0)||
        CurrentSlide.compare("ShapeSlide")==0){
        
        NumOfSquares = ofVec2f(64,48);
        
        
//    if ((NumOfSquares.x != (int)(10+(Nx/4-10)*Slider2/127.0))||
//        (NumOfSquares.y != (int)(10+(Ny/4-10)*Slider3/127.0))){
//        NumOfSquares.x = (int)(10+(Nx/4-10)*Slider2/127.0);
//        NumOfSquares.y = (int)(10+(Ny/4-10)*Slider3/127.0);
        Destino = cvCreateImage(cvSize(NumOfSquares.x, NumOfSquares.y), 8, 1);
//    }
        cvResize(TheInputGray, Destino);
    }
    if (CurrentSlide.compare("DensitySlide")==0) {
        NumOfSquares = ofVec2f(128,96);
//        if ((NumOfSquares.x != (int)(10+(Nx/4-10)*Slider2/127.0))||
//            (NumOfSquares.y != (int)(10+(Ny/4-10)*Slider3/127.0))){
//            NumOfSquares.x = (int)(10+(Nx/4-10)*Slider2/127.0);
//            NumOfSquares.y = (int)(10+(Ny/4-10)*Slider3/127.0);
            Destino = cvCreateImage(cvSize(NumOfSquares.x, NumOfSquares.y), 8, 1);
//        }
        cvResize(TheInputGray, Destino);
        DithPointList();
    }
    if (CurrentSlide.compare("Connectedness")==0) {
        NumOfSquares = ofVec2f(128,96);
//        if ((NumOfSquares.x != (int)(10+(Nx/4-10)*Slider2/127.0))||
//            (NumOfSquares.y != (int)(10+(Ny/4-10)*Slider3/127.0))){
//            NumOfSquares.x = (int)(10+(Nx/4-10)*Slider2/127.0);
//            NumOfSquares.y = (int)(10+(Ny/4-10)*Slider3/127.0);
            Destino = cvCreateImage(cvSize(NumOfSquares.x, NumOfSquares.y), 8, 1);
//        }
        cvResize(TheInputGray, Destino);
        DithPointList();
        SortPointsToPlot();
          
    }
    
    
    if (CurrentSlide.compare("Transcoding")==0){
        
        NumOfSquares = ofVec2f(64,48);
        
        
        //    if ((NumOfSquares.x != (int)(10+(Nx/4-10)*Slider2/127.0))||
        //        (NumOfSquares.y != (int)(10+(Ny/4-10)*Slider3/127.0))){
        //        NumOfSquares.x = (int)(10+(Nx/4-10)*Slider2/127.0);
        //        NumOfSquares.y = (int)(10+(Ny/4-10)*Slider3/127.0);
        Destino = cvCreateImage(cvSize(NumOfSquares.x, NumOfSquares.y), 8, 1);
        //    }
        cvResize(TheInputGray, Destino);
    } 
    
    
    
    if(CurrentSlide.compare("NCcir")==0){
        NCCirUpdate();
        CircsFrameCount++;
        if (CircsFrameCount>260){
            CircsFrameCount=1;
        }
    
    }
    
    if (CurrentSlide.compare("NCcirMatched")==0) {
        CirMatched(0);
    }
    if (CurrentSlide.compare("MinMaxcir")==0) {
        CirMatched(1);
    }
    if (CurrentSlide.compare("BottleNeckCir")==0) {
        CirMatched(2);
    } 
    if (CurrentSlide.compare("DirectionFiltCir")==0) {
        CirMatched(3);
    }
    
    if((CurrentSlide.compare("NCcirMatched")==0)||
       (CurrentSlide.compare("MinMaxcir")==0)||
       (CurrentSlide.compare("BottleNeckCir")==0)||
       (CurrentSlide.compare("DirectionFiltCir")==0)){
        
        G_ka = 1.35 + 4*Slider1/127.0;
        G_Dammping = .45 + 4*Slider2/127.0;
        MaxBetweener = 2 + 18*(int)Slider3/127.0;
        BetweenFrames++;
        if(BetweenFrames>=MaxBetweener){
            CircsFrameCount++;
            BetweenFrames=0;
            if (CircsFrameCount>260){
                CircsFrameCount=1;
            }
        }
  
    }
    
    if((CurrentSlide.compare("MeshFlow")==0)||
    (CurrentSlide.compare("ArrowsDraw")==0)){
        
        G_kMesh=4.0 + 4*Slider1/127.0; // elastic constant	
        G_kgMesh=.4*Slider2/127.0; // gradient factor
//        G_kdMesh=.5+4*Slider3/127.0; // drag constant
       G_kdMesh=.05+4*Slider3/127.0; // drag constant  
        MeshFlowUpdate();
    }
    
    
    
    
    if(CurrentSlide.compare("GradientCircs")==0){
    
        CirclesGradientUpdate();
    }
    
    if (CurrentSlide.compare("TargetsAlgorithm")==0) {
        MaxMode =2;
        if(InterMode>MaxMode-1){InterMode=0;} 
        TargetAlgorithmUpdate(InterMode);
    }
    
    
    if (CurrentSlide.compare("EllipwithTarget")==0){
        
        ImageToEllipseList(TheInputGray, 16);
        MaxMode =2;
        if(InterMode>MaxMode-1){InterMode=0;} 
        if (InterMode==1){
            CoherentEllipses();
        }
        
    }
    
    
    if (CurrentSlide.compare("TargetEllipseExample")==0){
    
        ImageToEllipseList(TheInputGray, 16);
        CoherentEllipses();
    
    }
    
    if (CurrentSlide.compare("GoodFeaturesExample")==0) {
        GoodFeaturesUpdate();
    }

    if (CurrentSlide.compare("Mixing")==0){

        NumOfSquares.x = 28;
        NumOfSquares.y = 28;
        
        
            Destino = cvCreateImage(cvSize(NumOfSquares.x, NumOfSquares.y), 8, 1);
        cvResize(TheInputGray, Destino);
    }
    
    
    if ((CurrentSlide.compare("Bagette")==0)){
        ImageToEllipseList(TheInputGray, 16);
        CoherentEllipses();     
    }
  
    if ((CurrentSlide.compare("CaptureSlideJul26")==0)){
        ImageToEllipseList(TheInputGray, 16);
        CoherentEllipses();     
    }
   
    
    
    if (CurrentSlide.compare("Hormigas")==0) {
        HormigasUpdate();
    }
    
    if (CurrentSlide.compare("Tree")==0) {
        TreeUpdate();
    } 
    if (CurrentSlide.compare("TemplateDemo")==0) {
        ofSetFrameRate(12);
        TemplateDemoUpdate();
    }
    if (CurrentSlide.compare("TemplateDemo")!=0){
    ofSetFrameRate(30);
    }
    
   
    
}

//--------------------------------------------------------------
void defense::draw(){
    ofSetHexColor(0xffffff);
    
    if (CurrentSlide.compare("CaptureSlideJul26")==0) {
        Capture3styles();
        
        
    }
    
    
    if (CurrentSlide.compare("TitleSlide")==0){
        TitleSlide();
    }
    if (CurrentSlide.compare("TableContentSlide")==0){
        TableContentSlide();
    }
    if (CurrentSlide.compare("IntroductionTitle")==0){
        ChapterTitle("INTRODUCTION");
    }
    if (CurrentSlide.compare("DefinitionsSlide")==0){
        DefinitionsSlide();
        
    }
    if (CurrentSlide.compare("JustAnalysis")==0){
        MaxMode =3;
        if(InterMode>MaxMode-1){InterMode=0;}
        JustAnalysis(InterMode);
        
    }
    if (CurrentSlide.compare("BlockDiagram")==0){
        MaxMode =5;
        if(InterMode>MaxMode-1){InterMode=0;}
        BlockDiagram(InterMode);
      }
    if (CurrentSlide.compare("ScopeAndLimitationsSlide")==0){
        ScopeAndLimitationsSlide();
        
    }  
    if (CurrentSlide.compare("ContributionsSlide")==0){
        ContributionsSlide();
        
    }  
    if (CurrentSlide.compare("ReviewTitle")==0){
        ChapterTitle("REVIEW OF A/S IN MEDIA ARTS");
    }  
    if (CurrentSlide.compare("Autotune")==0){
        AutotuneSlide();
    }  
    if (CurrentSlide.compare("Vocoder")==0){
        VocoderSlide();
    }  
    if (CurrentSlide.compare("ImageReview")==0){
        MaxMode =7;
        if(InterMode>MaxMode-1){InterMode=0;}  
        ImageReviewSlides(InterMode);
    } 
    if (CurrentSlide.compare("VideoNPR")==0){
        MaxMode =3;
        if(InterMode>MaxMode-1){InterMode=0;}  
        VideoNPR(InterMode);
    } 
    if (CurrentSlide.compare("VideoReview")==0){
        MaxMode =8;
        if(InterMode>MaxMode-1){InterMode=0;}  
        VideoReviewSlide(InterMode);
    } 
    if (CurrentSlide.compare("MediaArtReview")==0){
        MaxMode =4;
        if(InterMode>MaxMode-1){InterMode=0;}  
        MediaArtReviewSlide(InterMode);
    } 

    if (CurrentSlide.compare("CreativeCodingEra")==0) {
       MaxMode =2;
        if(InterMode>MaxMode-1){InterMode=0;}  
        CreativeCodingEraSlide(InterMode); 
    }
    
    if (CurrentSlide.compare("RedrawingTitle")==0) {
        ChapterTitle("REDRAWING IMAGES");
    }
    if (CurrentSlide.compare("RedrawingRegions")==0) {
        MaxMode =5;
        if(InterMode>MaxMode-1){InterMode=0;} 
        RedrawingRegions(InterMode);
    }
    if (CurrentSlide.compare("EdgesAndLines")==0){
        MaxMode =2;
        if(InterMode>MaxMode-1){InterMode=0;} 
        EdgesAndLines(InterMode);
    }    
    if (CurrentSlide.compare("OrientationSlide")==0) {
        
        Orientation();
    }
    if (CurrentSlide.compare("SizeSlide")==0) {
        SizeSlide();
    }
    if (CurrentSlide.compare("ShapeSlide")==0) {
        ShapeSlide();
    }
    if (CurrentSlide.compare("DensitySlide")==0) {
       DensitySlide();

    } 
    if (CurrentSlide.compare("Connectedness")==0) {
        MaxMode =3;
        if(InterMode>MaxMode-1){InterMode=0;} 
        ConnectednessSlide(InterMode);
    }   
    
    if (CurrentSlide.compare("Transcoding")==0) {
        WaveSlide();
    }  
    
    
    
    if (CurrentSlide.compare("TemporalCoherencyTitle")==0) {
        ChapterTitle("TEMPORAL COHERENCY");
    }
    
    if (CurrentSlide.compare("TemCoherenceContent")==0) {
        TemCoherenceContent();
    }

    if (CurrentSlide.compare("MatchingTitle")==0) {
        AllSubSectionTitles("Matching and Interpolation in the Parameters Domain");
    }
    if (CurrentSlide.compare("TheMatchingProblem")==0) {
        TheMatchingProblem();
    }
    if (CurrentSlide.compare("MinMaxEquation")==0) {
        MinMaxEquation();
    }
    if (CurrentSlide.compare("NCcir")==0)

    {
        NCCirDraw("Example 1: Non-coherent circles");
    }
    
    if(CurrentSlide.compare("MinMaxcir")==0){
           
     NCCirDraw("Minimizing the sum of distances");
    }
    if(CurrentSlide.compare("NCcirMatched")==0){
    NCCirDraw("Random matching");
    }
    if(CurrentSlide.compare("BottleNeckEquation")==0){
        BottleNeckEquation();
    }
    if(CurrentSlide.compare("BottleNeckCir")==0){
        NCCirDraw("Minimizing the maximum distance");
    }
    if (CurrentSlide.compare("DirectionFiltCir")==0){
       NCCirDraw("Penalizing particular directions");
    }
    
    if (CurrentSlide.compare("GradientTitle")==0) {
        AllSubSectionTitles("Gradient Based Approach");
    }
    if (CurrentSlide.compare("GradientBlocks")==0) {
        GradientBlocks();
    }  
    if (CurrentSlide.compare("MeshFlow")==0) {
        MeshFlowDraw();
    } 
    if (CurrentSlide.compare("ArrowsDraw")==0) {
        ArrowsDraw();
    } 
    
    if(CurrentSlide.compare("MobileMirrors")==0){
        ChapterTitle("MOBILE MIRRORS");

    }
    if(CurrentSlide.compare("AngleShift")==0){
        AngleShift();
        
    }
  
    if(CurrentSlide.compare("MeshMobile")==0){
        MeshMobile();
        
    }
    
    if(CurrentSlide.compare("FutureWorkNonCoherent")==0){
        ChapterTitle("FUTURE WORK:\nDENSITY MIRRORS");
        
    }

  
    if(CurrentSlide.compare("FutureWorkMobile")==0){
        ChapterTitle("FUTURE WORK IN\nTEMPORAL COHERENCY");
        
    }
    
//    keyString.push_back("");
//    keyString.push_back("");
//    keyString.push_back("MeshMobile");
//    keyString.push_back("FutureWorkMobile");
    
    
    
    
    if (CurrentSlide.compare("DisTrans")==0) {
        MaxMode =3;
        if(InterMode>MaxMode-1){InterMode=0;} 
        DisTrans(InterMode);
    }
    
    if(CurrentSlide.compare("GradientCircs")==0){
        
         CirclesGradientDraw();
    }
    
    if (CurrentSlide.compare("TargetsTitle")==0) {
        AllSubSectionTitles("Attractors Based Algorithm");
    }
    if (CurrentSlide.compare("TargetsAlgorithm")==0) {
        TargetAlgorithmDraw();
    }
    
    if (CurrentSlide.compare("EllipwithTarget")==0) {
        EllipWithTarget();
    }
    
    if (CurrentSlide.compare("TargetEllipseExample")==0){

        TargetEllipseExample();
        
    }
    
    if (CurrentSlide.compare("GoodFeaturesExample")==0) {

        GoodFeaturesDraw();
    }
    
    if (CurrentSlide.compare("ComparisionTitle")==0) {
        AllSubSectionTitles("Comparison");
    }
    if (CurrentSlide.compare("HistoJumps")==0) {
        Comparisions(0);
    }
    if (CurrentSlide.compare("JerKBar")==0) {
        Comparisions(1);
    }
    if (CurrentSlide.compare("SmoothVsQual")==0) {
        Comparisions(2);
    }
    if (CurrentSlide.compare("Dispersion")==0) {
        Comparisions(3);
    } 
    if (CurrentSlide.compare("CrossSynthesisTitle")==0) {
        ChapterTitle("FUTURE WORK \nAMBIGUOUS IMAGES");
    }
    if (CurrentSlide.compare("CrossContent")==0) {
        CrossContent();
    }
    
    
    if (CurrentSlide.compare("AmbiguousSlide")==0) {
        AmbiguousSlide();
    }
    
    if (CurrentSlide.compare("SubstitutionTitle")==0) {
        AllSubSectionTitles("Substitution");
    }
    if (CurrentSlide.compare("Mixing")==0) {
        MaxMode =3;
        if(InterMode>MaxMode-1){InterMode=0;} 
        MixingImages(InterMode);
    
    }

    if ((CurrentSlide.compare("Bagette")==0)){
    
        BaggeteExample();
    }
    
    if (CurrentSlide.compare("Hormigas")==0) {
        MaxMode =3;
        if(InterMode>MaxMode-1){InterMode=0;} 
        HormigasDraw(InterMode);
    }
    
    if (CurrentSlide.compare("Tree")==0) {
        MaxMode =4;
        if(InterMode>MaxMode-1){InterMode=0;} 
        TreeDraw(InterMode);
    }
    
    if (CurrentSlide.compare("DirectTitle")==0) {
        AllSubSectionTitles("Direct Detection");
    }
    
    
    if (CurrentSlide.compare("TemplateMatching")==0) {
        
        TemplateMatching();
        
    }
    
    if (CurrentSlide.compare("StatesSlide")==0) {
        
         StatesSlide();
        
    }
    
    if (CurrentSlide.compare("TemplateDemo")==0) {
        TemplateDemoDraw();
    }
    if (CurrentSlide.compare("ViterbiSlide")==0) {
        ViterbiSlide();
    }
    if (CurrentSlide.compare("GenerativeTitle")==0) {
        AllSubSectionTitles("Generative Approach");
    }
//    if (CurrentSlide.compare("TreeDemo")==0){
//        TreeDraw();
//    
//    }
    
    if (CurrentSlide.compare("DiscussionSlide")==0){
           ChapterTitle("DISCUSSION");
    }
 
    if (CurrentSlide.compare("ExtensionsSlide")==0){
    
        ExtensionsSlide();
    }
    if (CurrentSlide.compare("FutureSlide")==0){
        
        FutureSlide();
    }

    if (CurrentSlide.compare("QuestionsSlide")==0){
     ChapterTitle("QUESTIONS?");
    }
    
    
    // checkink to save 
    if (booleanforCapture==true) {
        
   //     ofSaveScreen("ParaReNew" + ofToString(FrameNumber) +".png");
   //     FrameNumber++;
//     ofSaveScreen("SuperImagen.png" + ofToString(FrameNumber) + ".png");   
//        booleanforCapture = false;
//        FrameNumber++;
    }
    
    // draw the incoming, the grayscale, the bg and the thresholded difference
//	ofSetHexColor(0xffffff);
//    colorImg = TheInput;
//	colorImg.draw(0,0);
//	grayImage.draw(360,20);


}

//--------------------------------------------------------------
void defense::keyPressed(int key){

	switch (key){
        case ' ':
            booleanforCapture = !booleanforCapture;
            break;  
        case OF_KEY_RIGHT:
            SlideCounter++;
            InterMode=0;
            if (SlideCounter>keyString.size()-1){SlideCounter=0;}
            break;
        case OF_KEY_LEFT:
            InterMode=0;
            SlideCounter--;
            if (SlideCounter<0) {SlideCounter=keyString.size()-1;}
            break;    
            
        case 'm':
            
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
            break;
          case 'n':
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
            
            break;
        case '1':
            Slider1++;
            if (Slider1>128){
                Slider1 =128;
            }
        break;
        case '2':
            Slider2++;
            if (Slider2>128){
                Slider2 =128;
            }
            break;
        case '3':
            Slider3++;
            if (Slider3>128){
                Slider3 =128;
            }
            break;
        case '4':
            Slider4++;
            if (Slider4>128){
                Slider4 =128;
            }
            break;
        case '5':
            Slider5++;
            if (Slider5>128){
                Slider5 =128;
            }
           break;
        case 'q':
            Slider1--;
            if (Slider1<0){
                Slider1 =0;
            }
            break;
        case 'w':
            Slider2--;
            if (Slider2<0){
                Slider2 =0;
            }
            break;
        case 'e':
            Slider3--;
            if (Slider3<0){
                Slider3 =0;
            }
            break;
        case 'r':
            Slider4--;
            if (Slider4<0){
                Slider4 =0;
            }
            break;
        case 't':
            Slider5--;
            if (Slider5<0){
                Slider5 =0;
            }
            break;        
            
            
	}
}

// Audio callback

//void defense::audioIn(float * input, int bufferSize, int nChannels){	
//	
//	
//	
//	// samples are "interleaved"
//	
//	float SampleAverage=0;
//    float RMSValue = 0;
//	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume	
//	for (int i = 0; i < bufferSize; i++){
//		SampleAverage = input[i*2]*.5 + input[i*2+1]*0.5;
//		RMSValue +=SampleAverage*SampleAverage;
//        left[i] = SampleAverage;
//	}
//    
//	CurrentEnergy = RMSValue/bufferSize;
//}


//--------------------------------------------------------------
void defense::keyReleased(int key){

}

//--------------------------------------------------------------
void defense::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void defense::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void defense::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void defense::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void defense::windowResized(int w, int h){

}

//--------------------------------------------------------------
void defense::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void defense::dragEvent(ofDragInfo dragInfo){ 

}
