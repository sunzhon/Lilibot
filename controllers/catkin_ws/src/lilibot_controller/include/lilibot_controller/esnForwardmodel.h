#ifndef ESNFORWARDMODEL_H_
#define ESNFORWARDMODEL_H_
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "networkmatrix.h"


class ESNetwork;

class ESNForwardmodel{
    public:
        ESNForwardmodel(unsigned int ID);
        ~ESNForwardmodel();
        void step();
        void setInputDataSet(std::vector<float> inputs,std::vector<float> targets);
        float getOutput(unsigned int idx);
        void loadModel(unsigned int id, const std::string& dir);
        void saveModel(unsigned int id, const std::string& dir);
    private:
        ESNetwork * ESN;
        float * ESinput;
        float * ESoutput;
        float * ESTrainOutput;
        unsigned int ID;
        unsigned int global_count;
        bool learn;       
        unsigned int learning_episodes;
};



#endif
