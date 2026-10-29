# k3ng_cw_keyer
K3NG Arduino CW Keyer

The K3NG Keyer is an open source Arduino based CW (Morse Code) keyer with a lot of features and flexibility, rivaling commercial keyers which often cost significantly more. The code can be used with a full blown Arduino board or an AVR microcontroller chip can be programmed and used directly in a circuit. This keyer is suitable as a standalone keyer or for use permanently installed inside a rig, especially homebrew QRP rigs. It’s open source code so you can fully customize it to fit your needs and also perhaps learn from it or find coding ideas for other projects.

Documentation is located here:
https://github.com/k3ng/k3ng_cw_keyer/wiki

## Building with PlatformIO

The sketch can also be built with [PlatformIO](https://platformio.org/) from the repository root. The Arduino IDE layout is unchanged; `platformio.ini` points PlatformIO at `k3ng_keyer/` and the bundled `libraries/`.

    pio run                              # build for Arduino Nano (new bootloader)
    pio run -e nano -t upload            # build and upload
    pio run -e nano_oldbootloader -t upload   # Nano clones with the old bootloader
    pio device monitor                   # serial monitor at 115200

Hardware profiles and features are still selected by editing `keyer_hardware.h` and the `keyer_features_and_options*.h` files.
