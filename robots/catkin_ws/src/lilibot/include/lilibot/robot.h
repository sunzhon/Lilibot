#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "lilibot.h"
#include "rosClass.h"
#include "ststick.h"
#include<pthread.h>
#include<errno.h>

namespace lilibot_ns{

    class Robot{
        public:
            Robot(int argc, char** argv);
            ~Robot();
            bool run();
        private:
            std::vector<sensor> sensorValue;
            std::vector<sensor> motorValue;
            RosClass* ros;
            Lilibot* rob;
            StStick* stick;

        private:
            pthread_t tid;
            static void *paramServiceThread(void *arg);
            void paramService();


    };


}










#endif
