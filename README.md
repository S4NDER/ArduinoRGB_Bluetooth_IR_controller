# Arduino IR Bluetooth RGB LED controller
A project I made for myself to put into my car to control RGB led strips.

## Getting Started
### Getting The code
You can clone this project just by entering this command.
```
git clone https://github.com/S4NDER/ArduinoRGB_Bluetooth_IR_controller.git
```

### Prequisites
In order to use the code, you'll need to have the following things:
* Arduino Nano
* IR receiver
* IR Remote (those cheap ones will probably do)
* Bluetooth Module (HC-06, HC-05 will probably work too)
* An RGB LED to develop or an RGB LED strip if you have one laying around

### Installing Hardware
You can connect your devices to the pins you want and only need to change it in
the code. Make sure you connect the RGB output to PWM pins! Also the RX of the
HC-06 needs a voltage divider, i used a 1kOhm and a 2kOhm to ground for this setup.
Don't forget that the LED(strip) needs a resistor on each pin. I used 220 Ohm.

## Documentation
### Sending data
The Arduino expects the following JSON objects (ex.):
```json
{"red":248,"green":128,"blue":75}
```
```json
{"red":248}
```
```json
{"green":128}
```
```json
{"blue":75}
```
```json
{"delay":356}
```
```json
{"beat":true}
```
Feel free to clone the Android app I made for this project. It can be found [here](https://github.com/S4NDER/RGBArduinoApp).
It has the same funtionality like an IR remote with some extra features.

## Built With
* [Arduino IDE](https://www.arduino.cc/en/main/software) - The compiler/editor
* [Atom](https://atom.io/) - Editor of my personal preference

## Used Libraries
* [ArduinoJSON](https://github.com/bblanchon/ArduinoJson) - To parse data
* [IRLib2](https://github.com/cyborg5/IRLib2) - To receive IR signals
* [ArduinoThread](https://github.com/ivanseidel/ArduinoThread) - Tasking the different devices

## Authors
* **Sander Jansen** - *Writing the whole driver* - [S4NDER](https://github.com/S4NDER)

## License
This project is licensed under the [MIT License](LICENSE.MD) - see the [LICENSE.md](LICENSE.MD) file for details.
