## ffmpeg
To support C66x accelerator in ffmpeg

##Steps to apply a patch to ffmpeg
1. Copy c66x_accel.h to <FFMPEG_PKGS>/include folder that contains ffmpeg header files
2. Apply a patch to ffmpeg.c using command,
   <enter>patch ffmpeg.c ffmpeg_Signalogic.patch
3. Add a flag to ffmpeg Makefile using command,
   <enter>sed -i "20i CFLAGS += -D_TI66X_ACCEL" Makefile
4. Recompile ffmpeg to get ffmpeg binary with applied patch
