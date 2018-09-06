# ApplianceRelay
A work in progress Bluetooth activated solid state relay
Appliances Bluetooth solution
Keep in mind  this project was a put together under some time pressure, so it’s actually just a bare bones, working proof of concept. Here you will find sufficient information to flash and operate the devices.
The projects are written using PlatformIO, you can learn more about it from Platform.io
NB: All devices needs to be flashed with fresh firmware. You will find a link to the correct Github Repo in each corresponding section.

The Relay is the box with an arrow and a blue line on it.

![This is the Relay](https://d2mxuefqeaa7sj.cloudfront.net/s_0E6F65BF6D9DACD3E9DB665A93A1D8F9B54E7C10C982D281FF46A388F12AC47A_1536240951364_Bluetooth+boxes.jpg)


They function like a solid state relay, with a MOSFET as the switch. There are two ports on the box. The one below the arrow if for input, while the one on top if for output.
The blue stripe indicates what is the negative pole. It would be good to also make sure this is true just in case.

To flash the device, do the same as with the Beacon.

You can find the source code for the Relay here: github.com/Thogul/ApplianceRelay

Notes: The polarity of the MOSFET might be reversed. If it is, just open the box and switch them.
