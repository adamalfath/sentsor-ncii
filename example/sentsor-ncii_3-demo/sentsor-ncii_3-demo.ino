/* =====================================================================
   __  __      _____  ______  _   _  _______   _____   ____   _____ 
   \ \ \ \    / ____||  ____|| \ | ||__   __| / ____| / __ \ |  __ \    
 __ \ \ \ \  | (___  | |__   |  \| |   | |   | (___  | |  | || |__) |   
 \ \ \ \ \_\  \___ \ |  __|  |     |   | |    \___ \ | |  | ||  _  /    
  \ \ \ \     ____) || |____ | |\  |   | |    ____) || |__| || | \ \    
   \_\ \_\   |_____/ |______||_| \_|   |_|   |_____/  \____/ |_|  \_\   

 Project      : Name Card Information Injector (NCII) - Demo
 Description  : NCII name card demo
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
  
  Keyboard.begin();
  intro();
}

void loop() {
  static boolean keyPressed=false;
  static uint32_t timer;
  
  if(digitalRead(bt0)) {output0(); keyPressed=true;}
  if(digitalRead(bt1)) {output1(); keyPressed=true;}
  if(digitalRead(bt2)) {output2(); keyPressed=true;}
  if(digitalRead(bt3)) {output3(); keyPressed=true;}
  if(digitalRead(bt4)) {output4(); keyPressed=true;}
  if(digitalRead(bt5)) {output5(); keyPressed=true;}

  if(keyPressed) {
    //Blink indicator LED if key pressed
    heartbeat(1);
    delay(500); //Add small delay as simple debouncing
    keyPressed=false;
    timer=millis();
  }

  if(millis()-timer>=HEARTBEAT_INTERVAL) {
    heartbeat(1);
    timer=millis();
  }
}

void intro() {
  delay(3000); //Settle down
  
  //Simulate WIN+R command to open Run dialog
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(1000);

  //Run notepad
  Keyboard.print("notepad.exe");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000); //Add delay to compensate slow app opening

  Keyboard.print("Hi!\r\n");
  Keyboard.print("I'm NCII, it's stand for Name Card Information Injector.\r\n");
  Keyboard.print("Please press any key on the card to explore my information.\r\n");
  Keyboard.print("Have a nice day! ^_^\r\n");
  Keyboard.print("\r\n");

  heartbeat(3);
}

void output0() {
  Keyboard.print("Hi!\r\n");
  Keyboard.print("My name is Muhammad Adam Alfath. You can call me Adam.\r\n");
  Keyboard.print("I'm an electronics and hardware engineer.\r\n");
  Keyboard.print("\r\n");
}

void output1() {
  if(digitalRead(sw0)) {
    Keyboard.print("adam.alfath23@gmail.com\r\n");
  }
  else {
    Keyboard.print("E-mail Address\r\n");
    Keyboard.print("Personal : adam.alfath23@gmail.com\r\n");
    Keyboard.print("Work     : adam@gti.co.id\r\n");
    Keyboard.print("\r\n");
  }
}

void output2() {
  if(digitalRead(sw1)) {
    Keyboard.print("+6289657609886\r\n");
  }
  else {
    Keyboard.print("Phone Number\r\n");
    Keyboard.print("Mobile   : +62 896 57609886\r\n");
    Keyboard.print("Feel freely to contact me.\r\n");
    Keyboard.print("\r\n");
  }
}

void output3() {
  if(digitalRead(sw2)) {
    Keyboard.print("Bandung, West Java, Indonesia\r\n");
  }
  else {
    Keyboard.print("Address\r\n");
    Keyboard.print("Hometown : Sindanglaya, Cipanas, Kabupaten Cianjur\r\n");
    Keyboard.print("           https://goo.gl/maps/uxv6iGkc7QET1ytH7\r\n");
    Keyboard.print("Current  : Cibabat, Cimahi Utara, Kota Cimahi\r\n");
    Keyboard.print("           https://goo.gl/maps/HKdo9aLUffLQcenS8\r\n");
    Keyboard.print("\r\n");
  }
}

void output4() {
  if(digitalRead(sw3)) {
    Keyboard.print("Resume\r\n");
    Keyboard.print("Online Resume    : linkedin.com/in/adamalfath\r\n");
    Keyboard.print("\r\n");
  }
  else {
    Keyboard.print("Portfolio\r\n");
    Keyboard.print("More information : adamalfath.github.io - Project display\r\n");
    Keyboard.print("                   github.com/adamalfath - Project repository\r\n");
    Keyboard.print("                   sentsor.net - SENTSOR Project homepage\r\n");
    Keyboard.print("\r\n");
  }
}

void output5() {
  const uint8_t key[4]={1,0,1,0};
  boolean correctKey=true;

  //Check switch combination for key
  if((digitalRead(sw0))!=key[0]) correctKey=false;
  if((digitalRead(sw1))!=key[1]) correctKey=false;
  if((digitalRead(sw2))!=key[2]) correctKey=false;
  if((digitalRead(sw3))!=key[3]) correctKey=false;

  if(correctKey) {
    Keyboard.print("Yay! You have the correct key.\r\n");
    Keyboard.print("  __  __      _____  ______  _   _  _______   _____   ____   _____  \r\n");
    Keyboard.print("  \\ \\ \\ \\    / ____||  ____|| \\ | ||__   __| / ____| / __ \\ |  __ \\ \r\n");    
    Keyboard.print("__ \\ \\ \\ \\  | (___  | |__   |  \\| |   | |   | (___  | |  | || |__) |\r\n");   
    Keyboard.print("\\ \\ \\ \\ \\_\\  \\___ \\ |  __|  |     |   | |    \\___ \\ | |  | ||  _  / \r\n");   
    Keyboard.print(" \\ \\ \\ \\     ____) || |____ | |\\  |   | |    ____) || |__| || | \\ \\ \r\n");   
    Keyboard.print("  \\_\\ \\_\\   |_____/ |______||_| \\_|   |_|   |_____/  \\____/ |_|  \\_\\\r\n");
    Keyboard.print("\r\n");
  }
}

void heartbeat(uint8_t n) {
  while(n>0) {
    digitalWrite(led,HIGH);
    delay(10);
    digitalWrite(led,LOW);
    delay(100);
    n--;
  }
}

// End of File [SENTSOR]
