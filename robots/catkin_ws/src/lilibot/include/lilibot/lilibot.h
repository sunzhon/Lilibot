#ifndef _LILIBOT_H_
#define _LILIBOT_H_
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ros/ros.h"
#include <serial/serial.h>  //ROS已经内置了的串口包 
#include "std_msgs/String.h"
#include "std_msgs/Float32MultiArray.h"
//#include <dynamixel_workbench_toolbox/dynamixel_workbench.h>
//#include <dynamixel_workbench_controllers/position_control.h>
//#include <dynamixel_workbench_msgs/DynamixelStateList.h>
#include <dynamixel_workbench_toolbox/dynamixel_workbench.h>
#include <dynamixel_workbench_controllers/dynamixel_workbench_controllers.h>
#include <dynamixel_workbench_msgs/DynamixelStateList.h>
#include <dynamixel_workbench_msgs/DynamixelCommand.h>
#include <sstream>
#include <algorithm>
#include "typeHeader.h"
using namespace std;
namespace lilibot_ns{

    class Lilibot{
        public:
            Lilibot();
            ~Lilibot();    
            bool init(ros::NodeHandle* node);

            void setMotorValue(const vector<command>& value);
            void getSensoryValue(vector<sensor>& value);
            void getParameters();
         private:
            void initMsg(); 
            void readJoints();
            void readImu();
            void readFootForce();
            void writeServoValue();
            void readSensorValue();
            void localController();
            void value2cmd(const std::vector<float>& value, std::vector<int32_t>& cmd);
        private:
            DynamixelWorkbench * dxl_wb;
            uint8_t dxl_id[16];
            uint8_t dxl_cnt;
            serial::Serial *ser; //声明串口对象 
            ros::NodeHandle* node;
            long int t;
            //deivce num
            //feedback sensory
            std::vector<sensor> physical_present_position;
            std::vector<sensor> physical_present_velocity;
            std::vector<sensor> physical_present_current;
            std::vector<sensor> physical_present_voltage;

            std::vector<sensor> pose;
            std::vector<sensor> grf;
            std::vector<sensor> sensorValue;
            std::vector<sensor> motorValue;

            //dxl device
            std::vector<int32_t> goal_position;
            std::vector<int32_t> goal_velocity;
            std::vector<int32_t> goal_current;

            std::vector<int32_t> present_position;
            std::vector<int32_t> present_velocity;
            std::vector<int32_t> present_current;
            std::vector<int32_t> present_voltage;

            //local controller
            std::vector<int32_t> position_error;
            std::vector<int32_t> previous_goal_position;
            std::vector<float> float_position_error;
            std::vector<float> float_velocity_error;

            float p_gain;
            float d_gain;
            float MI;
        public:
            int leg_num;
            int motor_num;
            int sensor_num;
            int pose_num;

    };

}

#endif

