# hermes

<img align="left" src="https://cloud.githubusercontent.com/assets/965430/15920452/d1d317f0-2dce-11e6-8704-7390fb0681e3.png">

Hermes is a personal hobby robot rover project. It's based on a 4WD chassis
driven by an Arduino board and a motor shield. Hermes also uses a Respberry Pi
as its brain. The Pi is responsible for exchanging commands with the Arduino
board, communicating with controlling device like a mobile phone through WI-FI
direct protocol, processing and streaming video, and many more.

Phase one of this project is aiming for building a cell phone or tablet controlled
robotic rover without any intelligence. The controlling of the rover will be
completely relying on a pilot.

In the following phases, I will improve the rover with solar panel, obstacle
avoidance, more sensors and some machine learning, so it will have some limited
intelligence.

### Hardware

* [DFRobot 4WD Mobile Platform](http://www.robotshop.com/ca/en/dfrobot-4wd-arduino-mobile-platform.html)
* [Arduino Uno Rev 3](http://www.robotshop.com/ca/en/arduino-uno-usb-microcontroller-rev-3.html)
* [Waveshare Motor Driver Shield](http://www.robotshop.com/ca/en/600-ma-dual-h-bridge-motor-driver-shieldfor-dc-steppers-l293d.html)
* [Lynxmotion Pan and Tilt Kit](http://www.robotshop.com/ca/en/lynxmotion-pan-and-tilt-kit-aluminium2.html)
* [Adafruit 6 AA Battery Holder](http://www.robotshop.com/ca/en/adafruit-battery-holder-barrel-jack.html)
* [Terminal to 2.1mm Barrel Jack](http://www.robotshop.com/ca/en/terminal-barrel-jack.html)
* [DFRobot Standoff Mounting Kit](http://www.robotshop.com/ca/en/standoff-mounting-kit.html)
* [Raspberry Pi 2 Model B](https://www.buyapi.ca/product/raspberry-pi-2-model-b-armv7-with-1g-ram/)
* [Raspberry Pi Camera](https://www.buyapi.ca/product/raspberry-pi-camera-board-add-on/)
* [300mm Flex Cable for Raspberry Pi Camera](http://www.robotshop.com/ca/en/300mm-flex-cable-raspberry-pi-camera.html)
* [MoPi: Mobile Pi Power (Stackable Version)](https://www.buyapi.ca/product/mopi-mobile-pi-power-stackable-version/)
* [1m USB Cable Type A to B](http://www.robotshop.com/ca/en/1m-usb-cable-type-a-to-b.html)
* [Geekroo PWM Servo PiCobber](http://www.robotshop.com/ca/en/pwm-servo-driver-picobber-raspberry-pi-hat.html)
* [DFRobot 65mm Rubber Wheel - Silver](http://www.robotshop.com/ca/en/dfrobot-rubber-wheel-pair-silver.html)
* [DFRobot Mounting Hub for 65mm Wheels](http://www.robotshop.com/ca/en/mounting-hub-pair-dfrobot-wheels.html)

### Software

* [Arduino sketch](https://www.arduino.cc/en/Reference/HomePage) (C++)
* [Go](https://golang.org/) with `GOOS=linux GOARCH=arm` for [Raspbian](https://www.raspbian.org/)

More details and code to come as I'm building the robot.
