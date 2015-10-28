### Requirements for using c66x ffmpeg:

1. c66x accelerator card made by one of several vendors
2. Half-length or full-length PCIe card slot, depending on card type and vendor.  Cards are full height, single slot thickness, x8 lanes, and consume from 55 to 120W (power also depending on card type and vendor)
3. Add to ffmpeg command line:
   -hwaccel c66x [optional syntax]
4. Software from Signalogic:
  -c66x CPU code acceleration executable from Signalogic
  -DirectCore library and drivers.  For VM functionality, DirectCore virtIO drivers are additionally required

###Steps to apply a patch to ffmpeg
1. Copy c66x_accel.h to <FFMPEG_PKGS>/include folder that contains ffmpeg header files
2. Apply a patch to ffmpeg.c using command,
   <br />patch ffmpeg.c ffmpeg_Signalogic.patch
3. Add a flag to ffmpeg Makefile using command,
   <br />sed -i "20i CFLAGS += -D_TI66X_ACCEL" Makefile
4. Recompile ffmpeg to get ffmpeg binary with applied patch

###Usage
Command line examples:
<br />1. ffmpeg -y `-hwaccel c66x fg f ia` -f rawvideo -pix_fmt yuv420p -s 352x288 -r 30 -i input.yuv -b:v 1500000 /tmp/host_files/output.yuv
<br />2. ffmpeg -y `-hwaccel c66x fg f` -f rawvideo -pix_fmt yuv420p -s 352x288 -r 30 -i input.yuv -b:v 1500000 /tmp/host_files/output.yuv -f rtp rtp://< ip_addr >:< port_num >:< mac_addr >

###Supported options
`fg/bg`: To run H264 encoded streaming process in foreground/background
<br />`f`: To use VIRTFS/HOSTFS mode. That will use ffmpeg code for frame-by-frame processing of input. There is also VIRTIO/HOSTIO mode, which will use Signalogic APIs to process frame by frame input(under development)
<br />`ia`: To use Image Analytics along with the encoding and streaming using c66x accelerator cards. Default is just a streaming mode
<br />`d`: Debug mode in which, both c66x and ffmpeg outputs the encoded stream that can be used for quality checks and troubleshooting(under development)
