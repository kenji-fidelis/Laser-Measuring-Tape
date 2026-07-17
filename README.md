# Laser-Measuring-Tape
## Introduction to Project
Conventional measuring tapes often require two people to accurately measure the distance between two points. Tasks such as measuring the distance from the floor to the ceiling can be inconvenient and time-consuming with a traditional tape measure.

This project demonstrates a portable laser-based measuring tape that uses a VL53L0X Time-of-Flight (ToF) sensor to measure distance and display the reading on an OLED screen. The prototype was developed as an educational embedded systems project using an Arduino Nano.

## Repository Contents
- Code exists in "laserTapewswitch"
- Connections are shown in "Setup"
- The components for the 3D printed enclosure is available in "Frame"

## Working Principle: Time of Flight
The VL53L0X sensor measures distance using the Time-of-Flight (ToF) principle.
  1. A laser pulse is emitted by the sensor.
  2. The pulse reflects off the target surface.
  3. The reflected light returns to the sensor.
  4. The sensor measures the time taken for the round trip and calculates the distance. 

### Calculation of Distance: 
- Speed of light in air = c = 3 x 10^8 m/s
- Time to receive the incident light beam = t
- Distance = (ct)/2   

## Features of the Product
- Real-time distance measurement using the VL53L0X Time-of-Flight sensor
- Distance displayed on a 0.91" I²C OLED display
- Portable battery-powered design using an Arduino Nano
- Custom 3D-printed enclosure for compact assembly

## Current Limitations
The prototype uses the VL53L0X, which has an effective measurement range of approximately 2 metres. While this project was developed for educational purposes, the same concept can be extended to commercial laser measuring devices by using higher-range ToF sensors and additional calibration techniques.

## Demonstration
[Watch the project demo](Demonstration.mp4)
