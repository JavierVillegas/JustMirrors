#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"
#include "ofxMidi.h"
#include "ThePoints.h"
#include "TheEllipse.h"


#define ScreenX 1280
#define ScreenY 800
#define Nx 640
#define Ny 480
#define MaxEllip 1000
#define AvMaxX 80
#define AvMaxY 60
#define MaxCont 200  // max number of contours for FD
#define FFTSize 64  // for the FD
#define MaxLines 1800 // max number of lines
#define Ncirs 1000
#define MeshX 160    // size of the mesh
#define MeshY 120
#define NGradCirs 1000
#define NOBJTargDemo 40
#define NTARTargDemo 20 
#define NobGood 800
#define NobHormigas 800
#define NT 26
#define NobTemplates 80
#define NEndFame 300
#define NiniFrame 1
#define NobTree 1500
#define NtgTree 1500



class defense : public ofBaseApp , public ofxMidiListener{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);	
    
    //the SlideFunctions
    
    // MIDI FUNCTION
    void newMidiMessage(ofxMidiEventArgs& eventArgs);
    // Audio In function
  //  void audioIn(float * input, int bufferSize, int nChannels); 
    
    // Auxiliary  functions
    void roundedRect(float x, float y, float w, float h, float r);
    void PseudoColor(IplImage* GrayInput,IplImage* TheOutput);
    void ImageToEllipseList(IplImage* TheInput,int NPlanes);
    void PlotEllipses(vector<TheEllipse> ElliVec,ofRectangle RectLimits);
    void PlotEllipNoFill(vector<TheEllipse> ElliVec,ofRectangle RectLimits);
    void PlotEllipPolligon(vector<TheEllipse> ElliVec,ofRectangle RectLimits);
    void PlotEllipsesTexture(vector<TheEllipse> ElliVec,ofRectangle RectLimits);
    void PlotEllipsesTextureNew(vector<TheEllipse> ElliVec,ofRectangle RectLimits);
    void PlotEllipExternal(vector<TheEllipse> ElliVec,ofRectangle RectLimits,int Mode);
    void CoherentEllipses();
    void PlotCuadros(ofRectangle RectLimits,int AMode);
    void updateMat();
    void PlotALizard();
    void PlotLizardArray();
    void ImgToContours(IplImage* TheInput,int PlaneNumber,int CMode);
    void PlotContours(ofRectangle RectLimits,int CMode);
    void ImgToLineList();
    void PlotLines(vector<ofVec2f> TheLines,ofRectangle RectLimits);
    void DithPointList();
    void SortPointsToPlot();
    void PlotIntensityDist();
    void PlotCirclesTest();
    
    void NCCirUpdate();
    void CirMatched(int CircSet);
    void MeshFlowUpdate();
    void MeshFlowDraw();
    
    
    void CirclesGradientUpdate();
    void CirclesGradientDraw();
    void TargetAlgorithmUpdate(int TMode);
    void TargetAlgorithmDraw();
    void GoodFeaturesUpdate();
    void GoodFeaturesDraw();
    void Comparisions(int CMode);
    void MixingImages(int MMode);
    void CrossContent();
    void BaggeteExample();
    void Capture3styles();
    
    void HormigasUpdate();
    void HormigasDraw(int HMode);
    void TemplateDemoUpdate();
    void TemplateDemoDraw();
    int *ViterbiStates(int ini,int last,int steps);
    //   tree
    void TreeUpdate();
    void BWTest(const unsigned char * src, unsigned char * dst, int w, int h); 
    void TreeDraw(int TMode);  
    void DrawCentralTreeSombra(deque<ofVec2f> PosList,float x, float y, float width, float height,ofVec2f TargetPoint, float CenFac);
    
    
    //  New Slide with the algorithm
    
    void EllipWithTarget();
    void plotPointsFroEllipses(vector<TheEllipse> ElliVec,ofRectangle RectLimits,int DMode);
    void PlotStar(float x, float y,int verty, int rad1,int rad2);
    
    // Slide Templates
    void TitleAndLine();
    void ChapterTitle(string TheTitle);
    ofRectangle OneBigRect();
    
    // Individual Slides
    void TitleSlide();
    void TableContentSlide();
    void DefinitionsSlide();
    void JustAnalysis(int JAMode);
    void BlockDiagram(int BMode);
    void ScopeAndLimitationsSlide();
    void ContributionsSlide();
    void AutotuneSlide();
    void VocoderSlide();
    void ImageReviewSlides(int IMode);
    void VideoNPR(int VMode);
    void VideoReviewSlide(int VMode);
    void MediaArtReviewSlide(int MMode);
    void CreativeCodingEraSlide(int CMode);
    void RedrawingRegions(int RMode);
    void EdgesAndLines(int LMode);
    void Orientation();
    void SizeSlide();
    void ShapeSlide();
    void DensitySlide();
    void ConnectednessSlide(int CMode);
    void WaveSlide();
    void TemCoherenceContent();
    void AllSubSectionTitles(string TheTitle);
    void TheMatchingProblem();
    void MinMaxEquation();
    void NCCirDraw(string thetitle);
    void BottleNeckEquation();
    void GradientBlocks();
    void ArrowsDraw();
    
    void AngleShift();
    void MeshMobile();
    
    void DisTrans(int DTMode);
    void TargetEllipseExample();
    void AmbiguousSlide();
    void TemplateMatching();
    void StatesSlide();
    void ViterbiSlide();
    void FutureSlide();
    void ExtensionsSlide();
    
    
    // The Global Images
    ofVideoGrabber 		vidGrabber;
    ofxCvColorImage			colorImg;
    ofxCvGrayscaleImage 	grayImage;
    ofxCvGrayscaleImage     grayImageHalf;
    
    IplImage *TheInputGray;
    IplImage *TheInputRGB;
    
    // The Image Gradient
    IplImage* G_Gx;
	IplImage* G_Gy;
    
    float G_kMesh; // elastic constant	
	float G_kgMesh; // gradient factor
	float G_kdMesh; // drag constant
    
    // Previous pos and velocities
    
    float G_posX[MeshX][MeshY];
	float G_posY[MeshX][MeshY];
	float G_velX[MeshX][MeshY];
	float G_velY[MeshX][MeshY];
    float G_PrevX[MeshX][MeshY];
	float G_PrevY[MeshX][MeshY];
    
    // The Fonts  
    ofTrueTypeFont Fuentes[5];
    
    
    
    // the vector of slide strings
    vector<string> keyString;
    
    // vectors of video names
    vector<string> videoNames;
    vector<string> videosNPR;
    
    // 2D vector for color averaging;
    vector<vector<ofVec3f> > avMat;
    
    
    // variables for the Hormigas
    
    ofImage LasHormigas[6];
    ofImage FondoHormigas;
    ofVec2f TheObjectsHormigas[NobHormigas];
    ofVec2f TheVelocitiesHormigas[NobHormigas];    
    int TargIndHormigas[NobHormigas];
    vector<ofVec2f> TheTargetsHormigas;
    float RandAngleHormigas[NobHormigas];
    int AntState[NobHormigas];
    float G_QualityHormigas;
    int G_minDistanceHormigas;
    
    float KtarHormigas;
    float KdamHormigas;
    
    
    
    // variables for the templates
    
    ofImage  Templates[NT];
    ofVec4f TheBins [NobTemplates][NEndFame - NiniFrame+1];
    ofVec2f XTemplates[NobTemplates]; // the current position
    float TheAngleTemplates[NobTemplates]; // Current Angle
    ofVec2f VelTemplates[NobTemplates]; // velocities
    float WTemplates[NobTemplates];// Angular velocities
    
    vector <int> TheState[NobTemplates]; 
    
    int G_CurrentTargetInterpol;
    int G_NewTargetInterpol;
    // the globals for the controller
    int G_InterpolTemplates;
    int G_frameCounterTemplates;
    float G_kaTemplates;
    float G_DammpingTemplates;
    float G_PowTemplates;
    
    /// Variables for the Tree
    
    ofImage FondoTree;
    ofImage Hojas;
    ofVec2f TheObjectsTree[NobTree];
    ofVec2f TheVelocitiesTree[NobTree];  
    int TargIndTree[NobTree];
    priority_queue<ThePoints, vector<ThePoints>,greater<vector<ThePoints>::value_type> > PointQueueTree;
    vector<int> TargetHitsTree;
    vector<ofVec2f> TheTargetsTree;
    unsigned char * px;
    unsigned char *fixedThresholdPx;
    IplImage *HalfInputGray;
    
    
    
    //Globals
    string CurrentSlide;
    int SlideCounter;
    int InterMode;
    int MaxMode;
    int Slider1;
    int Slider2;
    int Slider3;
    int Slider4;
    int Slider5;
    
    float G_ka;
    float G_Dammping;
    
    // for the targt demo
    
    ofVec2f TheObjectsTargDemo[NOBJTargDemo];
    ofVec2f TheVelocitiesTargDemo[NOBJTargDemo];    
    int TargIndTargDemo[NOBJTargDemo];
    float KtarTgDemo,KdamTgDemo;
    ofVec2f TheTargetsTargDemo[NTARTargDemo];
    
    // for the good features to track
    
    ofVec2f TheObjectsGood[NobGood];
    ofVec2f TheVelocitiesGood[NobGood];    
    int TargIndGood[NobGood];
    float KtarGood,KdamGood;
    vector<ofVec2f> TheTargetsGood;
    
    
    
    
    
    // counter for matching frames
    int CircsFrameCount;
    int BetweenFrames;
    int MaxBetweener;
    ofVec2f GradientCircs[NGradCirs];
    ofVec2f VelsGradient[NGradCirs];
    ofVec2f TheCircPos[Ncirs];
    ofVec2f VelCirc[Ncirs];
    // Points form dithering
    deque<ofVec2f> PointsList;
    vector<ofVec2f> SortedPoints;
    
    
    // List of ellipse Parameters
    vector<TheEllipse> TheTargetsEllipses;
    vector<TheEllipse> TheCoherentEllipses;
    // Vectors of coherent Ellip positions and 
    // Velocities
    TheEllipse TheObjectsEllip[MaxEllip];
    TheEllipse TheVelocitiesEllip[MaxEllip]; 
    
    // contours and contour gray levels
    vector<vector<ofVec2f> > ArrayOfContours;
    vector<int> ContourGray;
    
    // vector of detected lines
    vector<ofVec2f> LineVec;
    
    // Number of elements  for  some mappings
    ofVec2f NumOfSquares;
    IplImage *Destino;
    
    
    CvMat * TESTTEST;
    // Midi variables
    
    ofxMidiIn	midiIn;
    int port;
    int id;
    double timestamp;
	
    int byteOne;
    int byteTwo;
    int TheStatus;
    int chanel;
    
    // audio variables
    
    
	
    vector <float> left;
    vector <float> right;
    
    float CurrentEnergy;
    
    
    //Audio
    ofSoundStream soundStream;
    // Video
    ofVideoPlayer Mov;
    bool VideoIsPlaying;
    
    // for capture
    bool booleanforCapture;
    
    int FrameNumber;
    
    
    
    
    
};

