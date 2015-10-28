## Requirements for using c66x ffmpeg:

1. c66x accelerator card made by one of several vendors

2. Half-length or full-length PCIe card slot, depending on card type and vendor.  Cards are full height, single slot thickness, x8 lanes, and consume from 55 to 120W (power also depending on card type and vendor).

3. Add to ffmpeg command line:

   -hwaccel c66x [optional syntax]

4. Software from Signalogic:

  -c66x CPU code acceleration executable from Signalogic
  -DirectCore library and drivers.  For VM functionality, virtIO drivers

##Steps to apply a patch to ffmpeg
1. Copy c66x_accel.h to <FFMPEG_PKGS>/include folder that contains ffmpeg header files
2. Apply a patch to ffmpeg.c using command,
   <br />patch ffmpeg.c ffmpeg_Signalogic.patch
3. Add a flag to ffmpeg Makefile using command,
   <br />sed -i "20i CFLAGS += -D_TI66X_ACCEL" Makefile
4. Recompile ffmpeg to get ffmpeg binary with applied patch
