#!/bin/bash

rosparam load ~/gebetto/src/urcirak_breathe/config/nop.yaml;
sleep 2.0
rosparam load ~/gebetto_ws/src/urcirak_breathe/config/breathing_parameters.yaml;
