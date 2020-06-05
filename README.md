# Message stack between desktop and microcontroller

Saving characters received from desktop virtual com through UART into Stack Structure. and the data can be poped again using a push button.

![simulation](simulation/simulation.gif)

## Instructions

1. clone the project repository to your machine

2. you can build the project directly if you have Atmel studio installed to your machine

3. if not include the project directories `HAL`, `MCAL`, `UTL`, and the main file `Serial_control.c` to a project created by any IDE that supports ATmega32 AVR toolchain

4. you can also find the hex file in the repository `Debug/Serial_control.hex` 

5. to burn the hex file to your hardware (ATmega32) you can do that by using [eXtreme Burner](https://extreme-burner-avr.software.informer.com/download/)

6. you can find the schematics in the simulation file `simulation/New Project.pdsprj` and also you can run the simulation at your machine if you have Proteus installed
