#!/bin/bash

rosparam load ~/gebetto_ws/src/urcirak_breathe/config/yep.yaml;
sleep 2.0
rosparam load ~/gebetto_ws/src/urcirak_breathe/config/breathing_parameters.yaml;
