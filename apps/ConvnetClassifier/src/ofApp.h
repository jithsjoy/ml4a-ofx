#pragma once

#include "ofMain.h"
#include "ofxCcv.h"
#include "ofxGrt.h"

#define PRE_RECORDING_COUNTDOWN_TIME 2000
#define RECORDING_TIME 5000


class ofApp : public ofBaseApp {
public:
        enum ClassifierType{ ADABOOST=0, DECISION_TREE, KKN, GAUSSIAN_MIXTURE_MODEL, NAIVE_BAYES, MINDIST, RANDOM_FOREST_10, RANDOM_FOREST_100, RANDOM_FOREST_200, SOFTMAX, SVM_LINEAR, SVM_RBF, NUM_CLASSIFIERS };
    
    void setup();
    void update();
    void draw();
    
    void sendOsc();
    void keyPressed(int key);
    
    
    ofVideoGrabber cam;
    
    ofxCcv ccv;
    ofVideoPlayer video;
    
    vector<float> classifierEncoding;
    vector<float> featureEncoding;
    
    bool setClassifier( const int type );
    
    //Create some variables for the demo
    ClassificationData trainingData;      		//This will store our training data
    GestureRecognitionPipeline pipeline;        //This is a wrapper for our classifier and any pre/post processing modules
    bool recordTrainingData;                                //This is a flag that keeps track of when we should record training data
    bool trainingModeActive;
    bool predictionModeActive;
    bool drawInfo;
    
    
    UINT trainingClassLabel;                    //This will hold the current label for when we are training the classifier
    UINT predictedClassLabel;
    string infoText;                            //This string will be used to draw some info messages to the main app window
    ofTrueTypeFont largeFont;
    ofTrueTypeFont smallFont;
    ofTrueTypeFont hugeFont;
    ofxGrtTimeseriesPlot plot1;
    ofxGrtTimeseriesPlot plot2;
    ofxGrtTimeseriesPlot predictionPlot;
    Timer trainingTimer;
    
    float lastX = 0;
    float lastY = 0;
    float lastTic = 0;
    
    bool nullRejection = false;
    
    int classifierType;
    
    string classifierTypeToString( const int type ){
        switch( type ){
            case ADABOOST:
                return "ADABOOST";
                break;
            case DECISION_TREE:
                return "DECISION_TREE";
                break;
            case KKN:
                return "KKN";
                break;
            case GAUSSIAN_MIXTURE_MODEL:
                return "GMM";
                break;
            case NAIVE_BAYES:
                return "NAIVE_BAYES";
                break;
            case MINDIST:
                return "MINDIST";
                break;
            case RANDOM_FOREST_10:
                return "RANDOM_FOREST_10";
                break;
            case RANDOM_FOREST_100:
                return "RANDOM_FOREST_100";
                break;
            case RANDOM_FOREST_200:
                return "RANDOM_FOREST_200";
                break;
            case SOFTMAX:
                return "SOFTMAX";
                break;
            case SVM_LINEAR:
                return "SVM_LINEAR";
                break;
            case SVM_RBF:
                return "SVM_RBF";
                break;
        }
        return "UNKOWN_CLASSIFIER";
    }
    
};