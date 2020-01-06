#! /usr/bin/python3

import os
import sys
import time
from multiprocessing import Process

def launch_ros(bluetooth):
    '''
    launch ros node by joy stick
    '''
    startpath=os.environ['GOROBOTS'] + "/utils/real_robots/stbot/catkin_ws/src/start_robot/start_lilibot"
    data=[]
    with open(bluetooth, 'rb') as f:
        while True:
            a=f.readline(1)
            data.append(ord(a))
            if len(data)==16:
                if (data[-2] == 2) and (data[-1]==0) :
                    print("Causion, Lilibot will move")
                    os.system(startpath)
                    break
                if((data[-3]==0) and (data[-2]==1) and (data[-1]==8)):
                    print("shutdown down the robot computer!")
                    os.system("sudo shutdown now")
                    done=False
                    break
                data.clear()

def open_bt(bluetooth):
    '''
    open bluetooth 
    '''
    not_find_bluetooth=True
    while not_find_bluetooth:
        if os.path.exists(bluetooth):
            not_find_bluetooth=False
        else:
            print("not find joystick, please connect joystick")


if __name__=="__main__":
    bluetooth="/dev/input/js0"
    open_bt(bluetooth)
    time.sleep(4)
    while True:
        p=Process(target=launch_ros,args=(bluetooth,))
        print("please UP or Down  joystick")
        p.start()
        p.join()

