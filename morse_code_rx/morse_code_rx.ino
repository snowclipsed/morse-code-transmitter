// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
 
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
int led = 6;
int speak = 7;

char* MorseCode[] = {
  ".-",     // A
  "-...",   // B
  "-.-.",   // C
  "-..",    // D
  ".",      // E
  "..-.",   // F
  "--.",    // G
  "....",   // H
  "..",     // I
  ".---",   // J
  "-.-",    // K
  ".-..",   // L
  "--",     // M
  "-.",     // N
  "---",    // O
  ".--.",   // P
  "--.-",   // Q
  ".-.",    // R
  "...",    // S
  "-",      // T
  "..-",    // U
  "...-",   // V
  ".--",    // W
  "-..-",   // X
  "-.--",   // Y
  "--.."    // Z
};

//Enter Numbers Library
char* Numbers[] = {
  "-----",   // 0
  ".----",   // 1
  "..---",   // 2
  "...--",   // 3
  "....-",   // 4
  ".....",   // 5
  "-....",   // 6
  "--...",   // 7
  "---..",   // 8
  "----."    // 9
};

void setup()
{
    // Initialize ASK Object
    rf_driver.init();
    // Setup Serial Monitor
    pinMode(led, OUTPUT);
    Serial.begin(9600);
    
}
 
void loop()
{
    // Set buffer to size of expected message
    uint8_t buf[20];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      
      // Message received with valid checksum
      Serial.print("Message Received: ");
      Serial.println((char*)buf);
    }

    char letter;
   // Check if bluetooth is connected

    // Read data from bluetooth
int i = 0;
while(buf[i] != '\0')
{    // Lower case letters
  letter = buf[i];
    if (letter >= 'a' && letter <= 'z') {
      // Call the letter element then apply morse code decoder
      decoder(MorseCode[letter - 'a']);
    }

    // Capital case letters
    else if (letter >= 'A' && letter <= 'Z') {
      // Call the letter element then apply morse code decoder
      decoder(MorseCode[letter - 'A']);
    }

    // Numbers
    else if (letter >= '0' && letter <= '9') {
      // Call Number's Element then apply morse code decoder
      decoder(Numbers[letter - '0']);
    }

    // Space Case
    else if (letter == ' ') {
      delay(600);
    }
    
    // Print output back
    if (letter == '\0') {
      Serial.println("");
    } else {
      Serial.print(letter);
      i++;
    }
   }
delay(5000);
}

void decoder (char* x) {

  // Counter
  int i = 0;

  //Decoder
  while (x[i] != '\0') {
    flashType(x[i]);
    i++;
  }
  
  // Delay between every letter
  delay(250);
}

void flashType (char data) {

  // Turn laser & Buzzer on
  digitalWrite(led , HIGH);
  digitalWrite(speak , HIGH);
  
  // DOT
  if (data == '.') {
    delay(200);
  }

  //Dash
  if (data == '-') {
    delay(600);
  }

  // Turn laser & Buzzer off
  digitalWrite(led, LOW);
  digitalWrite(speak , LOW);

  //Delay before the following dash/dot
  delay(200); 
}
