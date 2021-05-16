# Patch

Patched by [@impiaaa](https://github.com/impiaaa) : Add mode parameter to use 2336 bytes sectors needed by [mkpsxiso](https://github.com/Lameguy64/mkpsxiso).

## XA file creation

You can use [`psxavenc`](https://github.com/ABelliqueux/candyk-psx/tree/master/toolsrc/psxavenc) to convert your audio file to a 2336 bytes XA file :

```bash
./psxavenc -f 37800 -t xa -b 4 -c 2 -F 1 -C 1 "input.wav" "output.xa"
```

You can read it back with `XAPLAY.EXE`, that's in `psyq/bin/XAplay`.

You can use [`MOVPACK.EXE`](https://psx.arthus.net/tools/pimp-psx.zip) to interleave several PSX media files.

## Usage

`xainterleave <mode> <in.txt> <out.raw>`

`mode` can be 0 for full raw sectors or 1 for just XA.

`in.txt` is a manifest txt file as seen [here](https://github.com/ChenThread/fromage/blob/master/res/music.txt)

Example for 1 music file, to be played at 1x CD speed :

```
1 xa test.xa 1 0
1 null
1 null
1 null
```

Add 4 more 1 null lines for 2x.

```
   1     xa  menu.xa        1                          0  
sectors type file    xa_file number (0-255) xa_channel number (0-31)
```

The format seems to correspond to the [entry_t struct](https://github.com/ABelliqueux/candyk-psx/blob/db71929903cc09398f5efc23973f9e136d123bbb/toolsrc/xainterleave/xainterleave.c#L35).

## mkpsxiso

You can use the following syntax to include your XA file in the CD image :

```xml
<file name="mymusic1.xa" type="xa" source="mymusic1.xa"/>
```

See here for more details : https://github.com/Lameguy64/mkpsxiso/blob/c44b78e37bbc115591717ac4dd534af6db499ea4/examples/example.xml#L85


## More

XA SCEE Technical note - July 1998 : http://psx.arthus.net/sdk/Psy-Q/DOCS/CONF/SCEE/98July/xa_sound.pdf

PSX audio tools : https://forum.xentax.com/viewtopic.php?t=10136

PIMP tools : https://psx.arthus.net/tools/pimp-psx.zip

Source : https://discord.com/channels/642647820683444236/663664210525290507/843211084609617930
