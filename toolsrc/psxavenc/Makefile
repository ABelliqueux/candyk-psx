#~ OUTPUT_TOOLS += $(OUTPUT_BINDIR)psxavenc$(EXEPOST)
#~ OUTPUT_TOOLS_OBJS +=

OUTPUT_BINDIR = ./
EXEPOST=".exe"

NATIVE_CC = ../../../mxe/usr/bin/i686-w64-mingw32.static-gcc
NATIVE_CFLAGS = -O2 -g
NATIVE_LDFLAGS = -O2 -g

TOOLS_PSXAVENC_SRCS =
TOOLS_PSXAVENC_SRCS += cdrom.c
TOOLS_PSXAVENC_SRCS += decoding.c
TOOLS_PSXAVENC_SRCS += filefmt.c
TOOLS_PSXAVENC_SRCS += mdec.c
TOOLS_PSXAVENC_SRCS += psxavenc.c

TOOLS_PSXAVENC_INCS =
TOOLS_PSXAVENC_INCS += common.h

$(OUTPUT_BINDIR)psxavenc$(EXEPOST): $(TOOLS_PSXAVENC_SRCS) $(TOOLS_PSXAVENC_INCS) ../libpsxav/libpsxav.a
	$(NATIVE_CC) -o $@ $(TOOLS_PSXAVENC_SRCS) $(NATIVE_CFLAGS) $(NATIVE_LDFLAGS) \
		-I./../libpsxav -L../libpsxav \
		-L./../../../mxe/usr/i686-w64-mingw32.static/lib \
		-I./../../../mxe/usr/i686-w64-mingw32.static/include \
		-lavformat -lavcodec -lavutil -lswresample -lswscale -lpsxav -liconv -lmp3lame -lbz2 -lgnutls -ltasn1 -lhogweed -lgmp -lnettle -lbluray -lfreetype -lpng -lharfbuzz -lfreetype -lxml2 -lz -llzma -lws2_32 -lidn2 -lunistring -lx264 -lvpx -lvorbis -logg -lxvidcore -lcrypt32 -ltheora -ltheoraenc -lopus -lspeex -lopencore-amrwb -lopencore-amrnb -lvo-amrwbenc -lvorbisenc -lole32 -lbcrypt -lncrypt

# source : https://discord.com/channels/642647820683444236/642848592754901033/880571296231096381
# make tools NATIVE_CFLAGS="-O2 -g -I./../../../mxe/usr/i686-w64-mingw32.static/include" NATIVE_LDFLAGS="-O2 -g -L./../../../mxe/usr/i686-w64-mingw32.static/lib" CC=./../../../mxe/usr/bin/i686-w64-mingw32.static-gcc
#~         -lavformat -lavcodec -lavutil -lswresample -lswscale -lpsxav -liconv -lmp3lame -lbz2 -lgnutls -ltasn1 -lhogweed -lgmp -lnettle -lbluray -lfreetype -lpng -lharfbuzz -lfreetype -lxml2 -lz -llzma -lws2_32 -lidn2 -lunistring -lx264 -lvpx -lvorbis -logg -lxvidcore -lcrypt32 -ltheora -ltheoraenc -lopus -lspeex -lopencore-amrwb -lopencore-amrnb -lvo-amrwbenc -lvorbisenc -lole32 -lbcrypt -lncrypt
