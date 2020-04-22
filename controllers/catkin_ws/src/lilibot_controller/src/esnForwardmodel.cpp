#include "esnForwardmodel.h"


ESNForwardmodel::ESNForwardmodel(unsigned int ID){
    // ESN ID
    this->ID=ID;
    //Setting ENS parameters
    ESN = new ESNetwork(1/*no. input*/,1 /*no. output*/,250 /*rc hidden neurons*/,
            false /*feedback*/, false /*feeding input to output*/, 0 /*leak = 0.0*/, false/*IP*/);

    ESN->outnonlinearity = 0; // 0 = linear, 1 = sigmoid, 2 = tanh: transfer function of an output neuron

    ESN->nonlinearity = 2; // 0 = linear, 1 = sigmoid, 2 = tanh: transfer function of all hidden neurons

    ESN->withRL = 2; // 2 = stand ESN learning, 1 = RL with TD learning

    ESN->InputSparsity = 0; // if 0 = input connects to all hidden neurons, if 100 = input does not connect to hidden neurons

    ESN->autocorr = pow(10,3); // set as high as possible, default = 1

    ESN->InputWeightRange = 0.15; // scaling of input to hidden neurons, default 0.15 means [-0.15, +0.15]

    ESN->LearnMode = 1;//RLS = 1. LMS =2

    ESN->Loadweight = false; // true = loading learned weights

    ESN->NoiseRange = 0.001; //

    ESN->RCneuronNoise = false; // false = constant fixed bias, true = changing noise bias every time
    ESN->generate_random_weights(50 /*10% sparsity = 90% connectivity */, 0.95 /*1.2-1.5 = chaotics*/);

    //Create ESN input vector
    ESinput = new float[1];
    ESoutput = new float[1];

    //Create ESN target output vector
    ESTrainOutput = new float[1];

    //Initial values of input and target output
    for(unsigned int i = 0; i < 1; i++)
    {
        ESinput[i] = 0.0;
    }
    for(unsigned int i = 0; i< 1; i++)
    {
        ESTrainOutput[i] = 0.0;
    }
    learn=true;
    learning_episodes=1000;

}

ESNForwardmodel::~ESNForwardmodel(){
    //----- ESN objects garbage collection ---- //
    delete []ESN;
    delete []ESinput;
    delete []ESoutput;
    delete []ESTrainOutput;
}

void ESNForwardmodel::setInputDataSet(std::vector<float> inputs,std::vector<float> targets){
    ESTrainOutput[0]= targets.at(0); //Training output (target function)
    ESinput[0] = inputs.at(0/*6*/);// Input
}

void ESNForwardmodel::step(){
    if(global_count>learning_episodes){
        // 1) ESN training-------------------//
        learn=false;
        std::cout << "learn finish"<<std::endl;
    }
    //1.2) save training
    //1.1) training
    ESN->setInput(ESinput, 1/* no. input*/);
    ESN->takeStep(ESTrainOutput, 0.9/*0.9*RLS,0.0005*//*0.0055*//*1.5*//*1.8*/, 1 /*no td = 1 else td_error*/, learn/* true= learn, false = not learning learn_critic*/, 0);
    ESoutput[0] = ESN->outputs->val(0, 0);
    global_count+=1;
}

float ESNForwardmodel::getOutput(unsigned int idx){
    return ESoutput[idx];
}
void ESNForwardmodel::loadModel(unsigned int id, const std::string& dir){
    // load model from a file
    ESN->readParametersFromFile(id, dir);
    ESN->readStartweightsFromFile(id, dir);
    ESN->readEndweightsFromFile(id, dir);
    ESN->readInnerweightsFromFile(id, dir);
    ESN->readNoiseFromFile(id, dir);
}

void ESNForwardmodel::saveModel(unsigned int id, const std::string & dir){
    ESN->writeParametersToFile(id, dir);
    ESN->writeStartweightsToFile(id, dir);
    ESN->writeEndweightsToFile(id, dir);
    ESN->writeInnerweightsToFile(id, dir);
    ESN->writeNoiseToFile(id, dir);
}
