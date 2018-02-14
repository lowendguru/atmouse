# Introduction to ATmouse

This device is intended to be an assistive technology solution for computer users whom due to disability or physical condition find it difficult to use a regular mouse but are still able to push buttons. Users with Parkinson's disease, any tremor related condition, cerebral palsy and many other conditions that interfere with the users' ability to make precise hand movements.

The device is based on the Arduino Pro Micro (Leonardo compatible) and thus is a plug and play input device, meaning that it will be recognized as a USB mouse without the need of any additional drivers.

The device has a total of 13 buttons and 3 LED lights. The user can press buttons to:
- Move the mouse pointer (up, down, left, right)
- Left click
- Double left click
- Right click
- Hold left click
- Middle button click
- Hold middle button click
- Scroll wheel (up and down)
- Change the mouse movement speed between 3 different settings.




# Instructions

Print the 3 plastic parts (front case, back case, buttons array).
Etch or mill the PCB. This is a single sided PCB board and the tracks only use the "bottom" layer. Ignore the "top" layer of the Eagle design, but use wire jumpers to make the connections seen in the "top" layers.
Solder all electrical components to the PCB according to the Eagle design.
Upload the .ino sketch to the Pro Mini using Arduino IDE (Leonardo board settings).

Assemble the device. Start by placing the cover facing down on a table.
Then put the buttons array inside the sockets.
Make sure the USB cable is connected to the Pro Micro. Then place the PCB, the 5mm LEDs will fit inside their sockets and this will align the whole board into the front case.
Finally place the back case to close. You may have to glue the back case (as there are no screw holes in this version).
Optionally, you can use some pieces Polyurethane foam or similar material between the buttons array and the PCB, and also between the PCB and the back case for a tighter fit.

# Bill of materials

13 - 6mm push buttons
13 - 10k resistors
3 - 5mm LED
3 - 1k resistors
1 - PCB board 200x150mm (1 sided)
1 - Arduino Pro Micro
1 - Mini-USB cable
1 - Front case (3d printed)
1 - Back case (3d printed)
1 - Buttons array (3d printed)
Some foam rubber, Polyurethane foam or similar material (for a tighter fit)
Some strong glue (no screws yet, sorry)

# Demo video

https://www.youtube.com/watch?v=QU9dcgiuyGs