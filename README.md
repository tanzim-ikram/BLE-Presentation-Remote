# DIY BLE Presentation Remote with ESP32

This project implements a DIY presentation remote control using the ESP32 microcontroller, leveraging the BLE Keyboard library to simulate keyboard inputs for slide navigation. The remote features four buttons:

- **Next Slide**: Sends the Page Down key.
- **Previous Slide**: Sends the Page Up key.
- **Start Slide Show**: Sends the F5 key to start the presentation slide show.
- **End Slide Show**: Sends the Esc key to end the presentation slide show.

Additionally, an indicator LED lights up when any button is pressed, providing visual feedback. The remote is designed for seamless integration with presentation software, making it a versatile tool for enhancing presentations.

## Features:
- BLE keyboard functionality for wireless operation.
- Simple button interface with debounce handling.
- Visual feedback through an LED indicator.
- Laser pointer for precise pointing during presentations (not directly connected to the ESP32).

## Components Used:
- ESP32 microcontroller
- Push buttons
- LED
- Laser diode
- Slide switch
