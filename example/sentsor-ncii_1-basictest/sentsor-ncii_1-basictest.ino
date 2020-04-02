/* =====================================================================
   __  __      _____  ______  _   _  _______   _____   ____   _____ 
   \ \ \ \    / ____||  ____|| \ | ||__   __| / ____| / __ \ |  __ \    
 __ \ \ \ \  | (___  | |__   |  \| |   | |   | (___  | |  | || |__) |   
 \ \ \ \ \_\  \___ \ |  __|  |     |   | |    \___ \ | |  | ||  _  /    
  \ \ \ \     ____) || |____ | |\  |   | |    ____) || |__| || | \ \    
   \_\ \_\   |_____/ |______||_| \_|   |_|   |_____/  \____/ |_|  \_\   

 Project      : Name Card Information Injector (NCII) - Basic Test
 Description  : Basic input/output: reading pin state, blinking LED,
                calling function, using NCII
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
#define DEBUG false

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
  
  #if DEBUG
    //Enter test mode to stream pin state and blinking LED
    //Set 'DEBUG' value to 'true' to enter debug mode
    debug();
  #endif
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
}

void output1() {
  if(digitalRead(sw0)) {
    //Statement to run if button 1 pressed with switch 0 HIGH
    Serial.print(F("Button 1 pressed, switch 0 HIGH, function output1()-1 called\n"));
    Serial.print(F("Blink LED 1x for 1x\n"));
    delay(1000); heartbeat(1);
  }
  else {
    //Statement to run if button 1 pressed with switch 0 LOW
    Serial.print(F("Button 1 pressed, switch 0 LOW, function output1()-2 called\n"));
    Serial.print(F("Blink LED 1x for 2x\n"));
    delay(1000); heartbeat(1); delay(1000); heartbeat(1);
  }
}

void output2() {
  if(digitalRead(sw1)) {
    //Statement to run if button 2 pressed with switch 1 HIGH
    Serial.print(F("Button 2 pressed, switch 1 HIGH, function output2()-1 called\n"));
    Serial.print(F("Blink LED 2x for 1x\n"));
    delay(1000); heartbeat(2);
  }
  else {
    //Statement to run if button 2 pressed with switch 1 LOW
    Serial.print(F("Button 2 pressed, switch 1 LOW, function output2()-2 called\n"));
    Serial.print(F("Blink LED 2x for 2x\n"));
    delay(1000); heartbeat(2); delay(1000); heartbeat(2);
  }
}

void output3() {
  if(digitalRead(sw2)) {
    //Statement to run if button 3 pressed with switch 2 HIGH
    Serial.print(F("Button 3 pressed, switch 2 HIGH, function output3()-1 called\n"));
    Serial.print(F("Blink LED 3x for 1x\n"));
    delay(1000); heartbeat(3);
  }
  else {
    //Statement to run if button 3 pressed with switch 2 LOW
    Serial.print(F("Button 3 pressed, switch 2 LOW, function output3()-2 called\n"));
    Serial.print(F("Blink LED 3x for 2x\n"));
    delay(1000); heartbeat(3); delay(1000); heartbeat(3);
  }
}

void output4() {
  if(digitalRead(sw3)) {
    //Statement to run if button 4 pressed with switch 3 HIGH
    Serial.print(F("Button 4 pressed, switch 4 HIGH, function output4()-1 called\n"));
    Serial.print(F("Blink LED 4x for 1x\n"));
    delay(1000); heartbeat(4);
  }
  else {
    //Statement to run if button 4 pressed with switch 3 LOW
    Serial.print(F("Button 4 pressed, switch 3 LOW, function output4()-2 called\n"));
    Serial.print(F("Blink LED 4x for 2x\n"));
    delay(1000); heartbeat(4); delay(1000); heartbeat(4);
  }
}

void output5() {
  //Statement to run if button 5 pressed
  Serial.print(F("Button 5 pressed\n"));
  Serial.print(F("Switch position : "));
  Serial.print(digitalRead(sw0));
  Serial.print(digitalRead(sw1));
  Serial.print(digitalRead(sw2));
  Serial.print(digitalRead(sw3));
  Serial.print('\n');
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

void debug() {
  while(1) {
    Serial.print(F("bt0=")); Serial.print(digitalRead(bt0)); Serial.print(' ');
    Serial.print(F("bt1=")); Serial.print(digitalRead(bt1)); Serial.print(' ');
    Serial.print(F("bt2=")); Serial.print(digitalRead(bt2)); Serial.print(' ');
    Serial.print(F("bt3=")); Serial.print(digitalRead(bt3)); Serial.print(' ');
    Serial.print(F("bt4=")); Serial.print(digitalRead(bt4)); Serial.print(' ');
    Serial.print(F("bt5=")); Serial.print(digitalRead(bt5)); Serial.print(' ');
    Serial.print(F("sw0=")); Serial.print(digitalRead(sw0)); Serial.print(' ');
    Serial.print(F("sw1=")); Serial.print(digitalRead(sw1)); Serial.print(' ');
    Serial.print(F("sw2=")); Serial.print(digitalRead(sw2)); Serial.print(' ');
    Serial.print(F("sw3=")); Serial.print(digitalRead(sw3)); Serial.print('\n');
    heartbeat(1);
    delay(1000);
  }
}

// End of File [SENTSOR]
