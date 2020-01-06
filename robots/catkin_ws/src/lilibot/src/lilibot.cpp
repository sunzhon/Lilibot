#include "lilibot.h"
namespace lilibot_ns{

    Lilibot::Lilibot(){
        dxl_wb = new DynamixelWorkbench;
        ser = new serial::Serial();
    }

    Lilibot::~Lilibot(){
        for (uint8_t index = 0; index < dxl_cnt; index++)
            dxl_wb->itemWrite(dxl_id[index], "Torque_Enable", 0);
        delete dxl_wb;
        delete ser;
    }

    bool Lilibot::init(ros::NodeHandle* node_handle){
        //1) init dynamixel
        node=node_handle;
        string dxl_device;
        if(!node->getParam("dxl_device",dxl_device)){
            ROS_ERROR("No dxl_device given (namespace: %s)", node->getNamespace().c_str());
            return false;
        }
        int dxl_baud;
        if(!node->getParam("dxl_baud",dxl_baud)){

            ROS_ERROR("No dxl_baud given (namespace: %s)", node->getNamespace().c_str());
            return false;
        }
        int scan_range;
        if(!node->getParam("scan_range",scan_range)){
            ROS_ERROR("No scan_range given (namespace: %s)", node->getNamespace().c_str());
            return false;
        }
        int profile_velocity;
        if(!node->getParam("profile_velocity",profile_velocity)){
            ROS_ERROR("No profile velocity given (namespace: %s)", node->getNamespace().c_str());
            return false;

        }
        int profile_acceleration;
        if(!node->getParam("profile_acceleration",profile_acceleration)){
            ROS_ERROR("No profile acclearation given (namespace: %s)", node->getNamespace().c_str());
            return false;
        }
        string imu_device;
        if(!node->getParam("imu_device",imu_device)){
            ROS_ERROR("No imu device given (namespace: %s)", node->getNamespace().c_str());
            return false;
        }
        int imu_baud;
        if(!node->getParam("imu_baud",imu_baud)){
            ROS_ERROR("No imu baud given (namespace: %s)", node->getNamespace().c_str());
            return false;
        }

        if(!node->getParam("leg_num",leg_num)){
            ROS_ERROR("No leg_num given (namespace: %s)", node->getNamespace().c_str());
            return false;
        }

        if(!node->getParam("motor_num",motor_num)){
            ROS_ERROR("No motor_num given (namespace: %s)", node->getNamespace().c_str());
            return false;
        }

        if(!node->getParam("sensor_num",sensor_num)){
            ROS_ERROR("No sensor_num given (namespace: %s)", node->getNamespace().c_str());
            return false;
        }

        if(!node->getParam("pose_num",pose_num)){
            ROS_ERROR("No pose_num given (namespace: %s)", node->getNamespace().c_str());
            return false;
        }

        // open motor
        const char *log;
        bool result;
        result=dxl_wb->init(dxl_device.c_str(), dxl_baud, &log);
        if(result==false){
            printf("%s\n",log);
            perror("Fail to init Dynamixel motors!\n");
            return false;
        }

        if (dxl_wb->scan(dxl_id, &dxl_cnt, scan_range, &log) != true) {
            ROS_ERROR("Not found Motors, Please check scan range or baud rate");
            ros::shutdown();
            return false;
        }
        printf("%s\n",log);
        initMsg();
        for (int index = 0; index < dxl_cnt; index++){

            result = dxl_wb->torqueOff(dxl_id[index],&log);// torque off
            if (result == false)
            {
                printf("%s\n", log);
                perror("Failed to torque off Dynamixel motor\n");
                return false;
            }
            result = dxl_wb->itemWrite(dxl_id[index],"Profile_Velocity",profile_velocity,&log);
            if (result == false)
            {
                printf("%s\n", log);
                perror("Failed to set profile of velocity to Dynamixel motor\n");
                return false;
            }
            result = dxl_wb->itemWrite(dxl_id[index],"Profile_Acceleration",profile_acceleration,&log);
            if (result == false)
            {
                printf("%s\n", log);
                perror("Failed to initialize Dynamixel motor\n");
                return false;
            }
            result = dxl_wb->setCurrentBasedPositionControlMode(dxl_id[index],&log);
            //result = dxl_wb->setPositionControlMode(dxl_id[index],&log);
            //result = dxl_wb->setCurrentControlMode(dxl_id[index],&log);
            if (result == false)
            {
                printf("%s\n", log);
                perror("Failed to initialize Dynamixel motor\n");
                return false;
            }


            result = dxl_wb->torqueOn(dxl_id[index],&log);
            if (result == false)
            {
                printf("%s\n", log);
                perror("Failed to initialize Dynamixel motor\n");
                return false;
            }

        }

        int index=0;
        result = dxl_wb->addSyncWriteHandler(dxl_id[index], "Goal_Position", &log);
        if (result == false)
        {
            printf("%s\n", log);
            perror("Failed to add sync write handler: Goal_Position\n");
            return false;
        }

        result = dxl_wb->addSyncWriteHandler(dxl_id[index], "Goal_Current", &log);
        if (result == false)
        {
            printf("%s\n", log);
            perror("Failed to add sync write handler: Goal_Current\n");
            return false;
        }

        result = dxl_wb->addSyncReadHandler(dxl_id[index], "Present_Position", &log);
        if (result == false)
        {
            printf("%s\n", log);
            perror("Failed to add sync read handler position\n");
            return false;
        }

        result = dxl_wb->addSyncReadHandler(dxl_id[index], "Present_Velocity", &log);
        if (result == false)
        {
            printf("%s\n", log);
            perror("Failed to add sync read handler velocity\n");
            return false;
        }

        result = dxl_wb->addSyncReadHandler(dxl_id[index], "Present_Current", &log);
        if (result == false)
        {
            printf("%s\n", log);
            perror("Failed to add sync read handler current\n");
            return false;
        }

        result = dxl_wb->addSyncReadHandler(dxl_id[index], "Present_Input_Voltage", &log);
        if (result == false)
        {
            printf("%s\n", log);
            perror("Failed to add sync read handler voltage\n");
            return false;
        }

        //2) init pose imu sensor
        try 
        { 
            //设置串口属性，并打开串口 
            ser->setPort(imu_device.c_str()); 
            ser->setBaudrate(imu_baud); 
            serial::Timeout to = serial::Timeout::simpleTimeout(1000); 
            ser->setTimeout(to); 
            ser->open(); 
        } 
        catch (serial::IOException& e) 
        { 
            ROS_ERROR_STREAM("Unable to open port :JY901"); 
            return false; 
        }    
        //检测串口是否已经打开，并给出提示信息 
        if(ser->isOpen()) 
        { 
            ROS_INFO_STREAM("Serial Port initial successful!"); 
        } 
        else 
        { 
            return true; 
        }
        //local control
        position_error.resize(dxl_cnt);
        float_position_error.resize(dxl_cnt);
        float_velocity_error.resize(dxl_cnt);
        previous_goal_position.resize(dxl_cnt);
        // motor commands
        goal_position.resize(dxl_cnt);
        goal_velocity.resize(dxl_cnt);
        goal_current.resize(dxl_cnt);
        // sensory feedback
        present_position.resize(motor_num);
        present_velocity.resize(motor_num);
        present_current.resize(motor_num);
        present_voltage.resize(motor_num);
        physical_present_position.resize(motor_num);
        physical_present_velocity.resize(motor_num);
        physical_present_current.resize(motor_num);
        physical_present_voltage.resize(motor_num);

        grf.resize(leg_num);
        pose.resize(pose_num);
        motorValue.resize(motor_num);
        sensorValue.resize(sensor_num);
        // wait
        ros::Duration(3.5).sleep();
        p_gain=0.001;
        d_gain=0.001;
        MI=0.06;
        return true;
    }



    void Lilibot::getSensoryValue(vector<sensor>& value){
        assert(value.size()==sensor_num);

        readSensorValue();

        for(uint8_t idx=0;idx<motor_num;idx++){
            value.at(idx) = physical_present_position.at(idx);
        }

        for(uint8_t idx=0;idx<motor_num;idx++){
            value.at(idx+motor_num) = physical_present_velocity.at(idx);
        }

        for(uint8_t idx=0;idx<motor_num;idx++){
            value.at(idx +2*motor_num) = physical_present_current.at(idx);
        }

        for(uint8_t idx=0;idx<motor_num;idx++){
            value.at(idx +3*motor_num) = physical_present_voltage.at(idx);
        }

        for(uint8_t idx=0;idx<pose_num;idx++){
            value.at(idx+4*motor_num)=pose.at(idx);
        }

        for(uint8_t idx=0;idx<leg_num;idx++){
            value.at(idx+4*motor_num+pose_num)=grf.at(idx);
        }


    }

    void Lilibot::setMotorValue(const vector<command>& value){
        assert(value.size()>=dxl_cnt);
        for(int index=0;index<dxl_cnt;index++){
            value2cmd(value,goal_position);
        }
        localController();
        //   cout<<"Time:"<<ros::Time::now()<<endl;
    }


    //private----------------------------------------//
    void Lilibot::readJoints(){
        //1) read joint angles
        const uint8_t handler_index_read_position=0;
        const uint8_t handler_index_read_velocity=1;
        const uint8_t handler_index_read_current=2;
        const uint8_t handler_index_read_voltage=3;
        bool result;
        const char * log;
        // read joint position
        result = dxl_wb->syncRead(handler_index_read_position, &log);
        if (result == false)
        {   
            printf("%s\n", log);
            printf("Failed to sync read position\n");
        }   
        result = dxl_wb->getSyncReadData(handler_index_read_position, &present_position[0], &log);

        // read joint velocity
        result = dxl_wb->syncRead(handler_index_read_velocity, &log);
        if (result == false)
        {   
            printf("%s\n", log);
            printf("Failed to sync read velocity\n");
        }   
        result = dxl_wb->getSyncReadData(handler_index_read_velocity, &present_velocity[0], &log);

        // read joint current
        result = dxl_wb->syncRead(handler_index_read_current, &log);
        if (result == false)
        {   
            printf("%s\n", log);
            printf("Failed to sync read current\n");
        }   
        result = dxl_wb->getSyncReadData(handler_index_read_current, &present_current[0], &log);

        // read joint voltage
        result = dxl_wb->syncRead(handler_index_read_voltage, &log);
        if (result == false)
        {   
            printf("%s\n", log);
            printf("Failed to sync read current\n");
        }   
        result = dxl_wb->getSyncReadData(handler_index_read_voltage, &present_voltage[0], &log);

        for(int index=0;index < dxl_cnt;index++){
            physical_present_position.at(index) = dxl_wb->convertValue2Radian(dxl_id[index],present_position[index]);
            physical_present_velocity.at(index) = dxl_wb->convertValue2Velocity(dxl_id[index],present_velocity[index]);
            physical_present_current.at(index) = dxl_wb->convertValue2Current(present_current[index]);
            physical_present_voltage.at(index) = 0.1*present_voltage[index];
        }
        // the motor right and left with opposite movement direction
        for(int index=0;index<dxl_cnt;index++)
            switch(index){                
                case 0:
                case 3:
                case 2:
                case 5:
                case 7:
                case 10:
                    physical_present_position.at(index) = -1.0*physical_present_position.at(index);        
            }        

    }

    void Lilibot::readImu(){
        std_msgs::String results;
        uint8_t sum=0x00;
        uint8_t temp1[11];
        signed short temp2[6];
        float roll=0.0,pitch=0.0,yaw=0.0;
        results.data=ser->read(ser->available());
        if((results.data[0]==0x55)&&(results.data[1]==0x53)){
            for(uint8_t i=0;i<11;i++)
                temp1[i] = (uint8_t)results.data[i];                   
            for(uint8_t i=0;i<10;i++){
                sum+=temp1[i];
            }

            for(uint8_t i=0;i<6;i++)
                temp2[i]=(signed short)temp1[i+2];
            if(sum==temp1[10]){
                roll = (short)((temp2[1]<<8)|temp2[0])/32768.0*M_PI -  0.04;
                pitch = (short)((temp2[3]<<8)|temp2[2])/32768.0*M_PI + 0.055;
                yaw = (short)((temp2[5]<<8)|temp2[4])/32768.0*M_PI;
                pose.at(0)= -0.65*roll;
                pose.at(1) = -1.0*pitch;
                pose.at(2) = -1.0*yaw;
                pose.at(3) = 0.0;
                pose.at(4) = 0.0;
                pose.at(5) = 0.0;
            }
        }
    }

    void Lilibot::readFootForce(){

        // for F and B structure configuration //
        float grf_temp;
        float grf_offset[] ={-0.3, -0.3, -0.3,-0.3};
        float grf_slope = 1.1;
        float grf_uplimit = 0.75;
        float temp_off=(MI-0.085)*5.5;
        grf_offset[0] = grf_offset[0]- (temp_off>0.0 ? temp_off: 0.0);
        grf_offset[1] = grf_offset[1]- (temp_off>0.0 ? temp_off: 0.0);
        grf_offset[2] = grf_offset[2]- (temp_off>0.0 ? temp_off: 0.0);
        grf_offset[3] = grf_offset[3]- (temp_off>0.0 ? temp_off: 0.0);
        if(MI==0.0)
            MI=0.0000001;// can't make it become 0.0

        //grf_temp = grf_slope*current[2]+grf_offset[0];    
        grf_temp = 0.0001/MI*physical_present_current[2]-0.4;    
        grf[0] = grf_temp < 0.0 ? 0.0:(grf_temp > grf_uplimit ? grf_uplimit:grf_temp);//right
        //grf_temp = grf_slope*current[5] + grf_offset[1];
        grf_temp = 0.0001/MI*physical_present_current[5]-0.4;    
        grf[1] = grf_temp < 0.0 ? 0.0:(grf_temp > grf_uplimit ? grf_uplimit:grf_temp);//right

        //grf_temp = grf_slope*-1.0*current[8] + grf_offset[2];
        grf_temp = -0.0001/MI*physical_present_current[8]-0.4;    
        grf[2] = grf_temp < 0.0 ? 0.0:(grf_temp > grf_uplimit ? grf_uplimit:grf_temp);// left 

        //grf_temp = grf_slope*-1.0*current[11]+ grf_offset[3];
        grf_temp = -0.0001/MI*physical_present_current[11]-0.4;    
        grf[3] = grf_temp < 0.0 ? 0.0:(grf_temp > grf_uplimit ? grf_uplimit:grf_temp);//left
       
    }


    void Lilibot::initMsg(){
        printf("-----------------------------------------------------------------------\n");
        printf("  There are these Dynamixel motors             \n");
        printf("-----------------------------------------------------------------------\n");
        printf("\n");
        if(dxl_cnt==0){
            printf("Didn't find motor !");
            ROS_ERROR("NO motors!");

        }
        for (int index = 0; index < dxl_cnt; index++)
        {
            printf("MODEL   : %s\n", dxl_wb->getModelName(dxl_id[index]));
            printf("ID      : %d\n", dxl_id[index]);
            printf("dxl_cntt:%d\n",dxl_cnt);
            printf("\n");
        }
        printf("-----------------------------------------------------------------------\n");
    }

    void Lilibot::readSensorValue(){
        readFootForce();
        readImu();
        readJoints();
    }


    void Lilibot::getParameters(){
        if(!node->getParam("p_gain",p_gain))
            ROS_ERROR("can't loccate p_gain");
        if(!node->getParam("d_gain",d_gain))
            ROS_ERROR("can't loccate d_gain");
        if(!node->getParam("MI",MI))
            ROS_ERROR("can't loccate MI");
    }

    void Lilibot::localController(){

        for(uint8_t index =0; index < dxl_cnt;index++){
            switch(index){
                case 0:
                case 1:
                case 2:
                case 6:
                case 7:
                case 8:
                goal_current[index] = p_gain*200 > 400 ? 400 : p_gain*200;
                break;
                case 3:
                case 4:
                case 5:
                case 9:
                case 10:
                case 11:
                //goal_current[index] = 2*p_gain*200 > 400 ? 400 : 2*p_gain*200;
                goal_current[index] =p_gain*200 > 400 ? 400 : p_gain*200;
                break;
            }
        }
        /*
           float a=20, b =2.0, beta=0.05;
           float tra_diff, co_diff, ff, D_gain, K_gain, calculated_torque;
           for(uint8_t index =0; index < dxl_cnt;index++){
           goal_velocity[index]= (int32_t)round((0.088*(goal_position[index]-previous_goal_position[index])*100)*60/(2*M_PI*0.229));//0.088/value ,ros node 100Hz
           previous_goal_position[index] = goal_position[index];
           float_position_error[index] = dxl_wb->convertValue2Radian(dxl_id[index],present_position[index])-dxl_wb->convertValue2Radian(dxl_id[index],goal_position[index]);
           float_velocity_error[index] = (present_velocity[index]-goal_velocity[index])*0.229*2.0*M_PI/60.0;
           float tra_diff = float_position_error[index]+beta*(float_velocity_error[index]);
           float co_diff = a/(1+b*tra_diff*tra_diff);
           float ff = tra_diff/co_diff;

           K_gain= ff*float_position_error[index];
           D_gain= ff*float_velocity_error[index];
           calculated_torque  = (-ff-K_gain*float_position_error[index]-D_gain*float_velocity_error[index]);
           goal_current[index]  = (int32_t)(round((1.38/2.38)*calculated_torque/(2.69*0.001)));

           cout<<present_position[index]<<endl;
           std::cout<<"  0:"<<present_velocity[index]<<endl;
           std::cout<<"  1:"<<goal_velocity[index]<<endl;
           std::cout<<"  2:"<<float_velocity_error[index]<<endl;
           std::cout<<"  3:"<<goal_current[index]<<endl;
           std::cout<<"  4:"<<float_position_error[index]<<endl;
           std::cout<<"  5:"<<present_position[index]<<endl;
           std::cout<<"  6:"<<goal_position[index]<<endl;
           std::cout<<"  7:"<<dxl_wb->convertValue2Radian(dxl_id[index],present_position[index])<<endl;
           std::cout<<"  8:"<<dxl_wb->convertValue2Radian(dxl_id[index],goal_position[index])<<endl;
        //goal_current[index] = 0; //(int32_t)(round(calculated_torque));
        }
        */
        writeServoValue();
    }

    void Lilibot::writeServoValue(){
        const uint8_t handler_index_write_position = 0;
        const uint8_t handler_index_write_current = 1;
        bool result;
        const char * log;

        result = dxl_wb->syncWrite(handler_index_write_position, &goal_position[0], &log);
        if (result == false)
        {
            printf("%s\n", log);
            printf("Failed to sync write position\n");
        }

        result = dxl_wb->syncWrite(handler_index_write_current, &goal_current[0], &log);
        if (result == false)
        {
            printf("%s\n", log);
            printf("Failed to sync write current\n");
        }

    }

    void Lilibot::value2cmd(const std::vector<float>& value, std::vector<int32_t>& cmd){
        assert(value.size()==motor_num);
        assert(cmd.size()>=dxl_cnt);
        for(int index=0;index<dxl_cnt;index++){
            switch(index){
                case 0:
                case 3:
                    cmd[index]=(unsigned int )floor(-350.0*value.at(index)+2048.0);
                    break;
                case 1:
                case 4:
                    cmd[index]=(unsigned int )floor(512.0*(value.at(index)+0.25)+512.0);//+0.3
                    break;
                case 2:
                case 5:
                    cmd[index]=(unsigned int )floor(-724.0*(value.at(index)+0.25)+1324.0);//+0.2
                    break;
                case 6:
                case 9:
                    cmd[index]=(unsigned int )floor(350.0*value.at(index)+2048.0);
                    break;
                case 7:
                case 10: 
                    cmd[index]=(unsigned int )floor(-512.0*(value.at(index)+0.25)+3583.0);//0.3
                    break;
                case 8:
                case 11:
                    cmd[index]=(unsigned int )floor(724.0*(value.at(index)+0.25)+2772.0);//+0.2
                    break;
                default:
                    perror("error value2int");
            }

        }
    }
}
