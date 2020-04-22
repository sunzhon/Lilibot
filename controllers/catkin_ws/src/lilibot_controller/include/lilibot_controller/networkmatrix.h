/**
 * networkmatrix.h
 *
 * Created on:          Mar 22, 2012
 * Last Modified on:    Feb 12, 2016
 *
 * Authors: Andrej fillipow and Sakyasingha Dasgupta
 * Extended by Timon Tomas (2016)
 *
 * Please refer to Readme for basic details
 */

#ifndef NETWORKMATRIX_H_
#define NETWORKMATRIX_H_

#include <fstream>
#include <string>

#include "matrixutils.h"
#include "matrix.h"


class ESNetwork{
    public :

        /**
         * The following functions have to be called manually, and are necessary for functioning
         */

        /*! Main constructor (used for training)
         *
         * Generate the ESN network with all internal parameters defined
         * Takes the number of input, output and hidden neurons, whether inputs should feed into outputs, whether outputs
         * should feed back, and how quickly neurons should leak, in that order. Remember to initialize the weights!
         *
         * @param _input_neurons            Number of input neurons
         * @param _output_neurons           Number of output neurons
         * @param _network_neurons          Number of neurons in ESN, should be about 20-100 times bigger than inputs or outputs
         * @param _throughput_connections   Input to output direct connection
         * @param _feedback_connections     Output to RC connections
         * @param _leak_rate
         * @param _enable_ip                Intrinsic plasticity [Sakya time constant adaptation, Dasgupta 2013]
         * @param _autocorr
         * @param _learn_mode               1: RLS Learning (default), 2: for LMS learning
         * @param _nonlinearity=2           RC neuron nonlinearity 0: linear, 1: sigmoid, 2: tanh (default)
         * @param _outnonlinearity          output neuron nonlinearity 0: linear, 1: sigmoid, 2: tanh (default)
         * @param _with_rl                  1: turn on RLS for combinatorial learning, 2: for standard ESN
         */
        ESNetwork(size_t _input_neurons, size_t _output_neurons, size_t _network_neurons,
                 bool _throughput_connections, bool _feedback_connections, double _leak_rate, bool _enable_ip,
                 double _autocorr=1, int _learn_mode=1, int _nonlinearity=2, int _outnonlinearity=2, int _with_rl=1);


        /*! Main constructor (used for testing)
         *
         * @param num
         * @param dir
         */
        ESNetwork( unsigned int num, const std::string& dir );

        /**
         * Default destructor - handle or dangling objects
         */
        ~ESNetwork();

        /**
         * Generating function for the input, reservoir and output weights. Sparsity governs percentage of matrix sparseness.
         * Inputweights drawn randomnly from the uniform distribution [-0.5,0.5). Innerweights drawn randomnly from the uniform
         * distribution [-1.1). Output weights are all initialised to 0. Innerweights are subsequently scaled to the specific
         * spectral_radius
         *
         * @param sparsity
         * @param spectral_radius
         */
        void generate_random_weights( int sparsity = 90 /*95*/, float spectral_radius = 0.95 /*0.95*/ );


        /**
         * Same as above except with full random Neighboured weighting
         *
         * @param sparsity
         * @param spectral_radius
         * @param nNextNeighbours
         */
        #warning: ESNetwork::generate_neighbour_weights is empty and has no effect!
        void generate_neighbour_weights( int sparsity = 90, float spectral_radius = 0.95, int nNextNeighbours = 15 ) const;

        /**
         * Accepts an array of floats, of length size, and sets the inputs to these given values. can use resetInput()
         * or scrambleInput() instead
         *
         * @param Input
         * @param size
         */
        void setInput( const float *Input, unsigned int size );

        /**
         * Offline training of the output weights. The net is trained over specific "time" steps, the first "discardedTimesteps" time steps are
         * not used to train. This serves as warm up for the ESN network.
         *
         * WARNING: This function does exactly nothing, as all code has been commented out.
         *
         *
         * @param Inputs
         * @param targets
         * @param time
         * @param discardedTimesteps
         */
        #warning: ESNetwork::trainOutputs is empty and has no effect!
        void trainOutputs( const float * Inputs, const float * targets, int time, int discardedTimesteps = 30 ) const;

        /**
         * Online training of the output weights using the Recursive least squares algorithm. For algorithm introduction
         * check http://en.wikipedia.org/wiki/Recursive_least_squares_filter
         *
         * @param targets               Target values for the recursive least squares algorithm.
         * @param forgettingFactor
         * @param td_error
         * @param param
         */
        void trainOnlineRecursive( const float * targets, float forgettingFactor, float td_error, double param = 0.0 );

        /**
         *
         * Least Means squared learning of Endweights
         *
         * @param targets
         * @param forgettingFactor
         * @param td_error
         * @param param
         */
        void trainOnlineLMS( const float * targets, float forgettingFactor, float td_error, double param = 0.0 );

        /**
         * Backpropagation-Decorrelation learning function. This is intended for online learning purposes. Note that this is not fully functional yet.
         *
         * @param targets
         * @param learningRate
         */
        #warning: ESNetwork::trainBackpropagationDecorrelation is empty and has no effect!
        void trainBackpropagationDecorrelation( const float * targets, float learningRate ) const;

        /**
         * Called at every discrete time step, calculating the inner neuron activations and outputs for the next discrete timestep.
         * If "learn_online" is true, the ESN learns the outputs specified in
         * "Outputs" via "trainOnlineRecursive()"
         * NOTE: the learningRate parameter acts as the forgetting factor for the trainOnlineRecursive() function.
         *
         * @param targets
         * @param learningRate
         * @param td_error
         * @param learn
         * @param timestep
         * @param param
         */
        void takeStep( const float * targets, float learningRate, float td_error, bool learn = true, int timestep = 1, double param = 0.0 );

        /**
         * The ESN takes a step without online learning, as above. this is called e.g. from "trainOutputs()"
         */
        void takeStep() {

            float* nothing = nullptr;
            takeStep( nothing, 1, 0, false );

        }

        /**
         * The following functions have to be called manually, and are optional
         */

        /**
         *
         * @param start
         * @param end
         * @param desiredOutputs
         * @return the mean square error between given Outputs and computed outputs over "time" discrete timesteps. Please refer to readme for further details.
         */
        float evaluatePerformance( int start,int end, const float * desiredOutputs ) const;

        /**
         * Writers
         */
        void writeParametersToFile( unsigned int num, const std::string& dir = "" ) const;

        void writeStartweightsToFile( unsigned int num, const std::string& dir = "" ) const;

        void writeInnerweightsToFile( unsigned int num, const std::string& dir = "" ) const;

        void writeInneractivityToFile( unsigned int num, const std::string& dir = "" ) const;

        /**
         * Write the Endweights (RC to output neurons) values to a text file
         *
         * @param num
         */
        void writeEndweightsToFile( unsigned int num, const std::string& dir = "" ) const;

        void writeNoiseToFile( unsigned int num, const std::string& dir = "" ) const;


        /**
         * Readers
         */
        void readParametersFromFile( unsigned int num, const std::string& dir = "" );

        void readStartweightsFromFile( unsigned int num, const std::string& dir = "" );

        void readInnerweightsFromFile( unsigned int num, const std::string& dir = "" );

        void readEndweightsFromFile( unsigned int num, const std::string& dir = "" );

        void readNoiseFromFile( unsigned int num, const std::string& dir = "" );

        /**
         * Resets input to zero
         */
        void resetInput();

        /**
         * Randomizes input
         */
        void scrambleInput();

        /**
         * Prints the passed matrix to the terminal
         *
         * @param printedMatrix
         */
        void printMatrix( const matrix::Matrix *printedMatrix ) const;

        /**
         * Prints the outputs to the terminal
         */
        void printOutputToTerminal() const;

        /**
         * Prints the activations of the inner neurons to the terminal
         */
        void printNeuronsToTerminal() const;

        /**
         * Generate numbers from the uniform distribution [a,b)
         *
         * @param a
         * @param b
         * @return
         */
        double uniform( double a, double b ) const;

        /**
         * @return the Array of output values
         */
        float * readOutputs() const;

        /**
         * these are the variables for Backpropagation-Decorrelation learning
         */
        float * errors;
        float * oldErrors;
        float * oldOutputs;
        float * oldIntermediates;


        int EvaluationCollectionStep;

        /**
         * The following functions are called from within other functions
         */

        /**
         * Limits (thresholded) the hidden neuron activation range between steps using an appropriate transfer function
         *
         * @param threshold
         */
        void cullInnerVector( float threshold = 0.5 );

        /**
         * Limits (thresholded) the output neuron activation range between steps using an appropriate transfer function
         *
         * @param threshold
         */
        void cullOutput( float threshold = 0.5/*unused*/ );

        /**
         * Approximated logistic function (Fermi-Dirac)
         *
         * @param x
         * @return
         */
        float sigmoid( float x ) const;

        /**
         * Derivative of the above function, used in backpropagation-decorrelation learning
         *
         * @param x
         * @return
         */
        float deriSigmoid( float x ) const;

        /**
         * Tangens hyperbolicus function
         *
         * @param x
         * @param flag
         * @return
         */
        double tanh( double x, bool flag );

        /**
         * Calculates the change in parameter b (gain) of a neuron using Gaussian IP learning rule
         *
         * @param y
         * @param eta
         * @return
         */
        double updateGauss_gain( double y, double eta ) const;

        /**
         * Scales the matrix of inner Weights, so that the highest eigenvalue is equal to "density".
         * Thus, the Echo-State-Property of the Network is ensured.
         *
         * @param density
         */
        void normalizeInnerWeights( float density );

        /**
         * Scales the matrix of start Weights (input to reservoir connections), so that the highest eigenvalue is equal to "density"
         *
         * @param density
         */
        void normalizeInputWeights( float density );

        std::ofstream out;
        size_t inputNeurons;
        size_t outputNeurons;
        size_t networkNeurons;                              //!< networkNeurons should be about 20-100 times bigger than inputs or outputs

        int stepsRun = 0;                                   //!< Initial number of simulation steps to wear off the initial conditions influence.

        matrix::Matrix * inputs;                            //!< Input neuron activations
        matrix::Matrix * outputs;                           //!< Output neuron activations
        matrix::Matrix * intermediates;                     //!< Intermediate neuron activations

        matrix::Matrix * identity;
        matrix::Matrix * leak_mat;
        matrix::Matrix * inverse_leak_mat;

        /// Matrices needed for online learning. for details, please refer to sakyas paper
        matrix::Matrix * onlineLearningAutocorrelation;
        matrix::Matrix * onlineError;                       //!< The error between input and desired output
        matrix::Matrix * transposedIntermediates;           //!< Intermediate for a multiplication step
        matrix::Matrix * toChangeOutputWeights;             //!< The final change of output weights is onlineError times this

        matrix::Matrix * gainvector = nullptr;

        /// matrix for experimental learning
        matrix::Matrix * history;

        matrix::Matrix * noise;

        /// the weights:
        matrix::Matrix * startweights;
        matrix::Matrix * innerweights;
        matrix::Matrix * endweights;
        matrix::Matrix * feedweights;

        bool throughputConnections;         //!< Whether inputs connect to outputs
        bool feedbackConnections;           //!< Whether outputs feed back to hidden layer
        bool leak = false;                  //!< Enable or disable leaky integrated neurons
        bool RCneuronNoise = false;
        bool Loadweight = false;

        int withRL;

        /// Intrinsic plasticity parameters para_a and para_b
        double para_a;
        double para_b;
        bool enable_IP;   // Enable or disable Gaussian IP

        double store_para_a[100000];
        double store_para_b[100000];
        double outputsCollection[10000];

        double leak_rate;
        double autocorr;
        int nonlinearity;
        int outnonlinearity;
        int LearnMode;

        unsigned int verboseLevel = 0;          //!< Verbosity of debuggin output. 0: silences debugging output.


        /*-------------------- Weight Parameters -------------------------------*/

        float InputWeightRange = 0.15;
        float RCWeightRange = 1.0;
        float FeedbackWeightRange = 0.5;
        float NoiseRange = 0.001;
        float input_scaling = 0.5;

        int InputSparsity = 0;          // 50
        int RCsparsity = 90;

};
#endif
