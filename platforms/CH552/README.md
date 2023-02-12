# CMSIS-DAP Cat Programmer

An Open-Source CMSIS-DAP Debug Probe based on DAPLink

## Description

DAP Cat Programmer is a low-cost of $3 dollars debug probe based on the CMSIS-DAP (also known as DAPLink) protocol standard and USB-Serial convert and it can realize USB convert to serial interface. It can be used to program and debug the application software running on Arm Cortex Microcontrollers.

The probe comes with indicator LEDs, a button to reset the target or trigger the firmware update, reversible USB-C connector and easy-to-use 10-pin 2.54mm Header.

## Features

- CH552G microcontroller
- 16KB Flash, 1KB xRAM & 256B iRAM;
- ROM-based USB drivers. Flash updates via USB supported.
- Shipped with Arm Mbed DAPLink Firmware
- HID - CMSIS-DAP compliant debug channel
- USB Serial bus convert and it can realize USB convert to serial interface.
- Supported Arduino IDE and OpenOCD
- LED indicator & Button
- 3.3V DC-DC regulator with 1A output current
- 3.3V Digital I/O Operating Voltage
- Reversible USB-C Connector
- Easy-to-use 5-pin 2.54mm Header with SWD & UART interface
- Very small form factor: 20 x 48 mm

<a href="https://electroniccats.com/store/nfc-copy-cat/">
  <img src="https://electroniccats.com/wp-content/uploads/badge_store.png" width="200" height="104" />
</a>


## Wiki and Getting Started
[Getting Started in our Wiki](https://github.com/ElectronicCats/DAP-Cat-Programmer/wiki)

## Software compatible
**Tested**

- OpenOCD
- Arduino IDE
- Keil
- PyOCD()

**Without Test**
- Dap.js()
- IAR
- [edbg](https://github.com/ataradov/edbg)

## Manual available
- [Our Wiki](https://github.com/ElectronicCats/DAP-Cat-Programmer/wiki)
- [How to debug hardware with openocd or pyocd](https://www.hackster.io/sabas1080/how-to-debug-hardware-with-openocd-or-pyocd-e7e718)

## Driver for windows

![Zadig image](https://raw.githubusercontent.com/DeqingSun/ch55xduino/ch55xduino/docs/Zadig_bootloader.png)

[Zadig](https://zadig.akeo.ie/) is the recommended tool to install drivers in Windows. The bootloader (4348,55E0) should be installed with WinUSB or libusb-win32 driver.

You can use USB Serial (CDC) driver for default CDC USB stack. If you tried to emulate another type of USB device without changing the PID/VID, you may need to uninstall the device before installing a new driver.

## Special Thanks

- [Deqing Sun](https://github.com/DeqingSun)
- CH552 Group in Telegram

