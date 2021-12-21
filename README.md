# ESP32_CLOCK
## status : Incomplete
In this I made a analog clock prototype using esp32 and LEDs.


![image](https://user-images.githubusercontent.com/70768880/146915396-0ae8e69d-dc10-443a-bfd1-7c4e6f0a352e.png | scale = 0.5)

Errors faced:

![image](https://user-images.githubusercontent.com/70768880/146915474-0d0da352-8e3c-4dbb-ba14-070a09433cdd.png)

Circuit diagram:
![image](https://user-images.githubusercontent.com/70768880/146915797-84354208-d3be-4f87-9f80-1b465cd6419c.png)

the led at the bottom is to determine if it is AM of PM.
i.e. If it glow then it is PM else it is AM.


We can make an seven segmented display but the number of leds used and the requirments of pins are also High.

#### Idea for seven segmented display with a single ESP32
Attach only 14 Leds i.e. 2 digit number.
For differentiation between hours, minutes and Seconds with a small delay.
As this circuit is more complex I went with the analog display.

##### drawback of going with analog clock
we cannot accuratly display the minutes as there are only 12 leds representing 1 2 .. 12 i.e. 0 5 10 .. 55.
For time with minutes falling in between these multiple of 5s I chose to decrease the brightness of the leds with pwm in ESP32.
