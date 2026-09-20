# AVR-Interrupt-Running-Light
Hardware interrupt-driven LED chaser for Note for real hardware:
This project is made for Wokwi simulation. If you want to build it in real life, you need to remember two things:
1. You must connect a resistor to every LED anode.
2. Physical buttons have contact bounce, so you need to add a hardware debouncing circuit.
Without this, the code won't work correctly on a real breadboard.

