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

You can read it back with `XAPLAY.EXE`, that's in `psyq/bin/XAplay`.

You can use [`MOVPACK.EXE`](https://psx.arthus.net/tools/pimp-psx.zip) to interleave several PSX media files.
