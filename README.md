# morse_code_transmitter

This repository includes the code for a morse code transmitter and reciever made using the Arduino [Radiohead Library (433Mhz)](https://www.airspayce.com/mikem/arduino/RadioHead/). 

[Morse](https://www.babbel.com/en/magazine/how-does-morse-code-work) is a type of encryption which uses a specific combination of dashes and dots. It can be used to encrypt almost any modern laguange. I have used american morse code.

For this project, a 433MHz transmitter/reciever set was used to transmit messages through amplitude shift keying across some distance (~max 20 m, but can be upscaled with better equipment). The user uses the arduino console to input text, which is then converted to a morse signal by the arduino on the transmitter end, and is sent through the radio transmitter. The reciever radio antenna will recieve the signal, and it will be processed by the reciever arduino which then sends the signal to a small speaker, hence successfully transmitting the signal in morse. This setup allows for only one-way communication.
