/* =====================================================================
   __  __      _____  ______  _   _  _______   _____   ____   _____ 
   \ \ \ \    / ____||  ____|| \ | ||__   __| / ____| / __ \ |  __ \    
 __ \ \ \ \  | (___  | |__   |  \| |   | |   | (___  | |  | || |__) |   
 \ \ \ \ \_\  \___ \ |  __|  |     |   | |    \___ \ | |  | ||  _  /    
  \ \ \ \     ____) || |____ | |\  |   | |    ____) || |__| || | \ \    
   \_\ \_\   |_____/ |______||_| \_|   |_|   |_____/  \____/ |_|  \_\   

 Project      : Name Card Information Injector (NCII) - Keyboard Output
 Description  : Outputing text/command using NCII as USB HID Keyboard
 Author       : SENTSOR
 Version      : 1.0.0 - Initial Build
 Note         : Using ATmega32u4 with Arduino Micro bootloader
 
===================================================================== */

//Pin definition
#define led 5
#define bt0 10
#define bt1 9
#define bt2 8
#define bt3 6
#define bt4 12
#define bt5 4
#define sw0 A0
#define sw1 A1
#define sw2 A2
#define sw3 A3

//Other definition
#define HEARTBEAT_INTERVAL 3000UL

#include <Keyboard.h>

void setup() {
  pinMode(led,OUTPUT);
  pinMode(bt0,INPUT);
  pinMode(bt1,INPUT);
  pinMode(bt2,INPUT);
  pinMode(bt3,INPUT);
  pinMode(bt4,INPUT);
  pinMode(bt5,INPUT);
  pinMode(sw0,INPUT);
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  pinMode(sw3,INPUT);

  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  static boolean buttonPressed=false;
  static uint32_t timer;

  //Check button reading with polling method and call function if button pressed
  if(digitalRead(bt0)) {output0(); buttonPressed=true;}
  if(digitalRead(bt1)) {output1(); buttonPressed=true;}
  if(digitalRead(bt2)) {output2(); buttonPressed=true;}
  if(digitalRead(bt3)) {output3(); buttonPressed=true;}
  if(digitalRead(bt4)) {output4(); buttonPressed=true;}
  if(digitalRead(bt5)) {output5(); buttonPressed=true;}

  if(buttonPressed) {
    //Blink indicator LED if button pressed
    heartbeat(1);
    delay(500); //Add small delay as simple debouncing
    buttonPressed=false;
    timer=millis();
  }

  //LED Heartbeat - Blink indicator LED when idle to indicate program still running normally
  //Modify 'HEARTBEAT_INTERVAL' value to change blink interval, unit in milliseconds
  if(millis()-timer>=HEARTBEAT_INTERVAL) {
    heartbeat(1);
    timer=millis();
  }
}

void output0() {
  //Statement to run if button 0 pressed
  Serial.print(F("Button 0 pressed, function output0() called\n"));
  
  //Print text via keyboard, "\r\n" in the end used as new line character
  Keyboard.print("Alphabet output: Aa Bb Cc Dd Ee Ff Gg Hh Ii Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz\r\n");
}

void output1() {
  //Statement to run if button 1 pressed
  Serial.print(F("Button 1 pressed, function output1() called\n"));
  Keyboard.print("Numeric output: 0123456789\r\n");
}

void output2() {
  //Statement to run if button 2 pressed
  Serial.print(F("Button 2 pressed, function output2() called\n"));
  Keyboard.print("Symbol output: `~!@#$%^&*()_+-={}[]|;:'?\r\n");
}

void output3() {
  //Statement to run if button 3 pressed
  Serial.print(F("Button 3 pressed, function output3() called\n"));

  //To write special character (e.g. " double quote or \ backslash) you need to add "escape character" \ before
  //Ex: " -> \" , \ -> \\
  //Ex: This syntax will print "C:\Program Files (x86)\Arduino\arduino.exe"
  Keyboard.print("Special char output: \"C:\\Program Files (x86)\\Arduino\\arduino.exe\"\r\n");
}

void output4() {
  //Statement to run if button 4 pressed
  Serial.print(F("Button 4 pressed, function output4() called\n"));
  Keyboard.print("Deleting text...\r\n");
  delay(2000);
  
  //Simulate CTRL+A DEL
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('a');
  Keyboard.press(KEY_DELETE);
  Keyboard.releaseAll();
}

void output5() {
  //Statement to run if button 5 pressed
  Serial.print(F("Button 5 pressed, function output5() called\n"));

  //Simulate WIN+R command to open Run dialog
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(1000); //Add delay to compensate slow app opening

  //Run notepad
  Keyboard.print("notepad.exe");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000); //Add delay to compensate slow app opening

  Keyboard.print("Welcome! This text sent from NCII\r\n");
}

void heartbeat(uint8_t n) {
  //Blink indicator LED for n-times
  while(n>0) {
    digitalWrite(led,HIGH);
    delay(10);
    digitalWrite(led,LOW);
    delay(100);
    n--;
  }
}

// End of File [SENTSOR]
