#!/bin/sh
#============================================
# Copyright (C) Signalogic Inc 2014
# Function: To apply Signalogic Patch to ffmpeg sources
# Rev 1.0
# Revision History
# Created: October, 2015 by HP
#============================================ 

#--------------------------------
# VARS 
# VARS path needs to be change as per location of ffmpeg sources and packages
FFMPEG_SRC_PATH="/root/ffmpeg/ffmpeg"
FFMPEG_PKG_PATH="/root/ffmpeg_build"
   
#--------------------------------

cp -p c66x_accel.h $FFMPEG_PKG_PATH/include/
patch $FFMPEG_SRC_PATH/ffmpeg.c ffmpeg_Signalogic.patch
sed -i "20i CFLAGS += -D_TI66X_ACCEL" $FFMPEG_SRC_PATH/Makefile

