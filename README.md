# Laser-Measuring-Tape
## Introduction to Project
Conventional measuring tapes usually require 2 people to measure a distance from 'A' to 'B'. In scenarios like measuring a room's vertical height, dragging the tape from ground to the ceiling is impractical and inefficient. In such scenarios, a laser-based measuring tape simplifies such an issue with accurate and efficient readings of distance. 

- Code exists in "laserTapewswitch"
- Connections are shown in "Setup"
- The components for the 3D printed enclosure is available in "Frame"

## Concept: Time of Flight
The VL53L0X contains a laser transmitter and a receiver. The transmitted laser beam, reflects off a surface and hits the receiver. The time of flight for this duration is calculated by the sensor, to obtain the distance reading. 

- Speed of light in air = c = 3 x 10^8 m/s
- Time to receive the incident light beam = t
- Distance = (ct)/2 

## Current Limitations
The VL53L0X sensor used for this particular project, has a distance range of 2m. This project was performed for educational purposes, but the concept applied can be extended to larger applications of laser tapes. 
