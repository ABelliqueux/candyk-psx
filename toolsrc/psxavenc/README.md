```
./psxavenc 
Usage: psxavenc [-f freq] [-b bitdepth] [-c channels] [-F num] [-C num] [-t xa|xacd|spu|str2] <in> <out>

    -f freq          Use specified frequency
    -t format        Use specified output type:
                       xa     [A.] .xa 2336-byte sectors
                       xacd   [A.] .xa 2352-byte sectors
                       spu    [A.] raw SPU-ADPCM data
                       str2   [AV] v2 .str video 2352-byte sectors
    -b bitdepth      Use specified bit depth (only 4 bits supported)
    -c channels      Use specified channel count (1 or 2)
    -F num           [.xa] Set the file number to num (0-255)
    -C num           [.xa] Set the channel number to num (0-31)
```

You can read it back with `XAPLAY.EXE`, that's in `psyq/bin/XAplay`.  
You can use [`MOVPACK.EXE`](https://psx.arthus.net/tools/pimp-psx.zip) or [xainterleave](https://github.com/ABelliqueux/candyk-psx/tree/master/toolsrc/xainterleave) to interleave several PSX media files.

# Cross compiling Windows binaries from Linux

## Install MXE

Follow the steps at https://mxe.cc/#tutorial to setup a cross-compiling environment on your system.

At step **3a**, use the following command :

```bash
make cc ffmpeg
```

**If encountering an error due to yasm not building, see here : https://github.com/mxe/mxe/issues/2627#issuecomment-843282994**

You should now have the toolchain in `./mxe/usr/bin`, and libraries and headers in `mxe/usr/i686-w64-mingw32.static/lib` and `mxe/usr/i686-w64-mingw32.static/include` .

## Compiling

You can now build windows 32b binaries by using the toolchain in `./mxe/usr/bin`, e.g:

```bash
./mxe/usr/bin/i686-w64-mingw32.static-gcc -o xainterleave.exe xainterleave.c
```

## psxavenc

A makefile is provided to build `psxavenc.exe` as the process is more involved (ffmpeg dependencies) but mainly :

  * Replace the libs in the `targets.make` file in `candyk-psx/toolsrc/psxavenc` with:  
```bash
# line 17 now reads  
-lavformat -lavcodec -lavutil -lswresample -lswscale -lpsxav -liconv -lmp3lame -lbz2 -lgnutls -ltasn1 -lhogweed -lgmp -lnettle -lbluray -lfreetype -lpng -lharfbuzz -lfreetype -lxml2 -lz -llzma -lws2_32 -lidn2 -lunistring -lx264 -lvpx -lvorbis -logg -lxvidcore -lcrypt32 -ltheora -ltheoraenc -lopus -lspeex -lopencore-amrwb -lopencore-amrnb -lvo-amrwbenc -lvorbisenc -lole32 -lbcrypt -lncrypt
```  
  * Use the following command, making sure you adapt the toolchain, lib and headers paths to your system, to compile the tools in  `candyk-psx/toolsrc/`:   
```bash
make tools NATIVE_CFLAGS="-O2 -g -I./../../../mxe/usr/i686-w64-mingw32.static/include" NATIVE_LDFLAGS="-O2 -g -L./../../../mxe/usr/i686-w64-mingw32.static/lib" CC=./../../../mxe/usr/bin/i686-w64-mingw32.static-gcc
```  

## Pre-built binaries

Pre-built win32 binaries are available here : http://psx.arthus.net/sdk/candyk-psx-tools.zip , courtesy of @nicolasnoble.

# Source & thanks
@nicolasnoble for guiding through the process and investigating the needed libs, and providing pre-built binaries !

https://discord.com/channels/642647820683444236/642848592754901033/880571296231096381  

