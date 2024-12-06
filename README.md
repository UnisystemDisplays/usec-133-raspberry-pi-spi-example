OVERVIEW
--------
This repository contains example of [*usec-133-generic-spi-lib*](https://github.com/UnisystemDisplays/usec-133-generic-spi-lib) library integration for [*Raspberry Pi*](https://www.raspberrypi.org/) boards. Please check [*usec-133-generic-spi-lib*](https://github.com/UnisystemDisplays/usec-133-generic-spi-lib) project repository for more info about library itself.

PREREQUISITES
-------------

To get started, please make sure, that all libraries and tools for C/C++ development on *Raspberry Pi* are properly installed and configured.

CONNECTIONS
-----------

|  USEC module connector | Raspberry Pi |
| ---- | ----- |
| VBUS | 3.3V  |
| GND  | GND   |
| SCLK | 11    |
| MISO | 9     |
| MOSI | 10    |
| CS   | 8     |
| RDY  | 24    |
| RST  | 17    |

__Note:__ *you can easily reconfigure pinout by editting platfrom.h file*

COMPILATION
-----------

[1] Download and install *bcm2835-1.75* library:

```
cd ~
wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.75.tar.gz
tar zxvf bcm2835-1.75.tar.gz
cd bcm2835-1.75
./configure
make
sudo make check
sudo make install
```

[2] Clone *usec-133-raspberry-pi-spi-example* repository:

```
cd ~
git clone https://github.com/UnisystemDisplays/usec-133-raspberry-pi-spi-example.git
```

[3] Build and run demo application:

```
cd usec-133-raspberry-pi-spi-example
make
sudo ./usec-133-raspberry-pi-spi-example
```

GETTING HELP
------------

Please contact Unisystem support - [*<lukasz.skalski@unisystem.com>*](lukasz.skalski@unisystem.com) or [*<jacek.marcinkowski@unisystem.com>*](jacek.marcinkowski@unisystem.com)

LICENSE
-------

See *LICENSE.txt* file for details.

