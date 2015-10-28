/*
 *
 * c66x accelerator support
 
     -accelerate ffmpeg with TI multicore CPUs
     -allow streaming on the accelerator card
     -support ffmpeg at HPC levels of performance inside VMs
     -_TI66X_ACCEL enables c66x accelerator support
     
 * Copyright (c) 2014-2015  Signalogic, Inc.
 *
 * This file is part of FFmpeg
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef AVCODEC_C66X_ACCEL_H
#define AVCODEC_C66X_ACCEL_H

#define MAXCPUSPERCARD                      8  /* given for C6678, these may change in C7000 processor family */
#define MAXCORESPERCPU                      8
#define MAXCORESPERCARD                     (MAXCPUSPERCARD*MAXCORESPERCPU)
#define MAXCARDS                            8

/* attributes used for accelerated ffmpeg and opencv support */

#define C66X_ACCEL_ENABLE_ENCODE_H264       1
#define C66X_ACCEL_ENABLE_DECODE_H264       2
#define C66X_ACCEL_ENABLE_ENCODE_VPX        4
#define C66X_ACCEL_ENABLE_DECODE_VPX        8
#define C66X_ACCEL_ENABLE_STREAMING_RTP     0x10
#define C66X_ACCEL_ENABLE_STREAMING_MPEGTS  0x20

#define C66X_ACCEL_HOSTFS_MODE              1
#define C66X_ACCEL_HOSTIO_MODE              2
#define C66X_ACCEL_VIRTFS_MODE              5
#define C66X_ACCEL_VIRTIO_MODE              6

#define C66X_ACCEL_GUI_FOREGROUND           0x100

//#include "vdi.h"

#endif /* AVCODEC_C66X_ACCEL_H */