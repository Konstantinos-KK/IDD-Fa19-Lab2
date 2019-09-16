# Make a Digital Timer!

**A lab report by Konstantinos Karras Kallidromitis**

[Pre-Lab work can be found here](https://github.com/Konstantinos-KK/IDD-Lab2-Prep/tree/master)

## Part A. Solder your LCD panel

**Take a picture of your soldered panel and add it here!**

<p align="center"> <b> Soldered LCD </b> <p>
<p align="center">
  <img width="600" src="https://github.com/Konstantinos-KK/IDD-Fa19-Lab2/blob/master/soldered_lcd.jpg">
</p>

## Part B. Writing to the LCD

 <p align="center"> <b> Hello world </b> <p>
<p align="center">
  <img width="600" src="https://github.com/Konstantinos-KK/IDD-Fa19-Lab2/blob/master/hello_world.jpg">
</p>

**a. What voltage level do you need to power your display?** The display requires a potential difference of 5V at the VDD port but additional voltage at the V0 port which also regulated the brightness.

**b. What voltage level do you need to power the display backlight?** The backlight stops operating only when removing the 3.3V source connected to A (PIN 15).
   
**c. What was one mistake you made when wiring up the display? How did you fix it?** A mistake was that my LCD was not working. To fix the mistake I had to test with another LCD. The soldering seemed fine so I got a new LCD and everything worked perfectly.

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?** The line I had to change was lcd.print("hello, world!"); and replace the text inside the quotation marks with my name:
``` C++
(lcd.print("Konstantinos");).
 ```
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**
[Multimeter Code](https://github.com/Konstantinos-KK/IDD-Fa19-Lab2/blob/master/analoginput.ino)

<p align="center"> <b> Multimeter for 0V and 5V </b> </p>
<p float="left">
  <img src="https://github.com/Konstantinos-KK/IDD-Fa19-Lab2/blob/master/lowly_0.jpg" width="425" />
  <img src="https://github.com/Konstantinos-KK/IDD-Fa19-Lab2/blob/master/lowly_5.jpg" width="425" /> 
</p>

## Part C. Using a time-based digital sensor

**Upload a video of your working rotary encoder here.**
[Video of rotary encoder](https://youtu.be/D_NBaBaHKoY)

## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?** I added a for loop that multiplies the note duration array by a factor of 2. 
``` C++
  for(int i = 0; i < 8; i++) {
    noteDurations[i] *= 2;}
```
[Code 2x](https://github.com/Konstantinos-KK/IDD-Fa19-Lab2/blob/master/tone2x.ino)
 
**b. What song is playing?** Star wars theme song


## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**

**b. Post a link to the completed lab report your class hub GitHub repo.**
