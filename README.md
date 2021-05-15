CandyK-PSX: A candy shop of tools and libraries for PlayStation development

This readme will need to be better fleshed-out.

## Patch

Patched by [@impiaaa](https://github.com/impiaaa) : Add mode parameter to use 2336 bytes sectors needed by [mkpsxiso](https://github.com/Lameguy64/mkpsxiso).

Usage: xainterleave <mode> <in.txt> <out.raw>

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

`1       xa  menu.xa    1       0`
sectors type file    xa_file xa_channel

The format seems to correspond to the [entry_t struct](https://github.com/ABelliqueux/candyk-psx/blob/db71929903cc09398f5efc23973f9e136d123bbb/toolsrc/xainterleave/xainterleave.c#L35).

Source : [https://discord.com/channels/642647820683444236/663664210525290507/843211084609617930]

## Licensing

CandyK, as a whole, is licensed under the "zlib license". Please check the LICENSE file for more information.

### Exceptions

Toolchain examples are licensed under the Creative Commons Zero license - feel absolutely free to base your code on them!

## Installation

### Binary

1. Install or compile pacman (the Arch Linux package manager).
2. Append the following to /etc/pacman.conf:

```
[candyk]
Server = http://candyk.asie.pl/repo/x86_64
```

3. `pacman -Syu`
4. `pacman -S candyk-psx`

### Source

TODO

## Architecture

### Directories

* `bin/`: Target directory for host-native tools
* `lib/`: Target directory for PlayStation libraries
* `src/`: Source code for PlayStation libraries
* `toolsrc/`: Source code for host-native tools

### Makefile system

TODO: formalise this.

Basically there's a bunch of `target.make` files which are included as needed.
