                                            LILIBOT

1) Intriduction

Self-organization of locomotion characterizes the feature of automatically spontaneous gait generation without preprogrammed limb movement coordination. To study this feature in quadruped locomotion, we propose here a new open-source small-sized reconfigurable quadruped robot (called Lilibot) with multiple sensory feedback and its physical simulation. Lilibot was designed as a friendly quadrupedal platform with unique characteristics, including lightweight, easy-handling, modular components, and multiple real-time sensory feedback. Its modular components can be flexibly reconfigured to obtain, e.g., different leg orientations for testing the effectiveness and generalization of a self-organized locomotion controller. Its available multiple sensory feedback (i.e., joint angles, joint velocities, joint currents, joint voltages, etc., in total 61) can support vestibular reflexes and compliant control mechanisms for body posture stabilization and compliant behavior, respectively. To evaluate the performance of Lilibot, we implemented our developed adaptive neural controller on it. Experimental results show that Lilibot can autonomously and quickly perform adaptive and versatile behaviors including spontaneous self-organized locomotion (i.e., adaptive locomotion behavior) under different leg orientations, body posture stabilization on a tiltable plane, and leg compliance for unexpected external load compensation. To this end, we succeeded in developing an open-source, friendly, small-sized and lightweight quadruped robot with reconfigurable legs and multiple sensory feedback that can serve as a generic quadruped platform for research and education in the domain of locomotion, vestibular reflex-based, and compliant controls.


2) Framework

The control code was put on controllers folder,and the robots folder is the interface code for a real robot. The Vrep simulation model was put in vrep_simulation folder

3) The steps to implement this project on your PC:

3.0) Install VREP
3.1) Install ROS kinetic
3.2) Install git
3.3) mkdir -p ~/workspace/stbot/ && cd ~/workspace/stbot/
3.4) git clone https://gitlab.com/neutron-nuaa/lilibot
3.5) cd ./lilibot/catkin_ws && catkin_make
3.6) Run simularion, 
    a) roscore
    b) cd vrep_simualtion && vrep ~/workspace/stbot/vrep_simulation/lilibot-V5.ttt

4) How to implement your controller

 Just edit the file of lilibot_controller_node.cpp
you can find this file at src/lilibot_controller/src/lilibot_controller_node.cpp

