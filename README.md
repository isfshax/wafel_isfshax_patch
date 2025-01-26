# Stroopwafel plugin to tolerate ISFShax

This plugin for [stroopwafel](https://github.com/shinyquagsire23/stroopwafel) a IOSU patch to tolerate [isfshax](https://github.com/isfshax/isfshax).

A stock IOSU would trip over the isfshax superblock and crash. This patch allows IOSU to work with an installed isfshax.

**Warning** This should only be used when ISFShax is actually installed.

## How to use

Put the `5isfshax.ipx` together with `wafel_core.ipx` from stroopwafel in `/wiiu/ios_plugins` on your SD Card.

## Building

```bash
export STROOPWAFEL_ROOT=/path/to/stroopwafel-repo
make
```

## Thanks

- [**rw-r-r-0644**](https://github.com/rw-r-r-0644) for isfshax

- [**GaryOderNichts**](https://github.com/GaryOderNichts) for isfshax contributions

- [**shinyquagsire23**](https://github.com/shinyquagsire23) for de_Fuse and stroopwafel
