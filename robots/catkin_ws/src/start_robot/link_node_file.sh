#! /bin/sh

file="$GOROBOTS/projects/stbot/genesis/catkin_ws/src/stbot/stbot_node"
if [ ! -f "$file" ];then
    ln -s $GOROBOTS/projects/stbot/genesis/catkin_ws/devel/lib/stbot/stbot_node $GOROBOTS/projects/stbot/genesis/catkin_ws/src/stbot/stbot_node
fi

file="$GOROBOTS/utils/real_robots/stbot/catkin_ws/src/lilibot/lilibot_node"
if [ ! -f "$file" ];then
    ln -s $GOROBOTS/utils/real_robots/stbot/catkin_ws/devel/lib/lilibot/lilibot_node $GOROBOTS/utils/real_robots/stbot/catkin_ws/src/lilibot/lilibot_node
fi
