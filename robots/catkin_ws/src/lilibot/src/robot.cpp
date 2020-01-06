#include "robot.h"

namespace lilibot_ns
{
    Robot::Robot(int argc, char** argv)
    {
        ros = new RosClass(argc,argv);
        rob = new Lilibot();
        if(!rob->init(ros->getHandle())){
            perror("lilibot init false\n");
        }
        stick = new StStick();
        if(!stick->init(ros->getHandle())){
            perror("ststick init false\n");
        }

        motorValue.resize(rob->motor_num);
        sensorValue.resize(rob->sensor_num);

        // get parameter thread
        if(pthread_create(&tid, NULL, paramServiceThread, (void *)this) != 0){ 
            perror("create thread fail in controller!\n");
        } 
        rob->getParameters();

        ROS_INFO("robot node start successful!\n");
    }

    Robot::~Robot(){
        delete rob;
        delete ros;
        delete stick;
    }
    void Robot::paramService(){
        rob->getParameters();
    }   

    void *Robot::paramServiceThread(void * arg){
        Robot * ptr = (Robot*) arg;
        while(!ptr->ros->terminate){
        ptr->paramService();
        sleep(1);
        }
        pthread_exit(0);
    }

    bool Robot::run(){
        if(ros::ok()){
            rob->getSensoryValue(sensorValue);
            ros->readSensorValue(sensorValue);
            ros->writeMotorValue(motorValue);
            rob->setMotorValue(motorValue);
            stick->guide();
            ros->rosSleep();
            return true;
        }else{
            return false;
        }

    }

}
