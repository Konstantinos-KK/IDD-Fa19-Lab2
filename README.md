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
   
**c. What was one mistake you made when wiring up the display? How did you fix it?**

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?** The line I had to change was lcd.print("hello, world!"); and replace the text inside the quotation marks with my name (lcd.print("Konstantinos");).
 
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**


## Part C. Using a time-based digital sensor

**Upload a video of your working rotary encoder here.**


## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**
 
**b. What song is playing?**


## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**

**b. Post a link to the completed lab report your class hub GitHub repo.**
