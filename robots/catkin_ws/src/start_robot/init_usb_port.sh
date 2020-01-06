#! /bin/sh

file="/sys/bus/usb-serial/devices/ttyUSB0/latency_timer"

if [ -f "$file" ]; then
    sudo usermod -aG dialout $USER && echo 1 | sudo tee /sys/bus/usb-serial/devices/ttyUSB0/latency_timer
else
    sudo usermod -aG dialout $USER && echo 1 | sudo tee /sys/bus/usb-serial/devices/ttyUSB1/latency_timer
fi

