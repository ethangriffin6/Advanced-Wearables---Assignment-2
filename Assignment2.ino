/*
Motion Controlled Color Sound Level
Ethan Griffin
DIGF-3010-001 Avanced Wearable Electronics
OCAD University
01 March, 2022
Based on:
Hello_Accelerometer, Adafruit, https://github.com/adafruit/Adafruit_CircuitPlayground/blob/master/examples/Hello_CircuitPlayground/Hello_Accelerometer/Hello_Accelerometer.ino
Hello_SoundSensor, Adafruit, https://github.com/adafruit/Adafruit_CircuitPlayground/blob/master/examples/Hello_CircuitPlayground/Hello_SoundSensor/Hello_SoundSensor.ino
*/

#include <Adafruit_CircuitPlayground.h>

int cycleCount = 0; //motion controller
float X; //X value
float soundValue; //sound value


void setup() {
  Serial.begin(9600);  
  CircuitPlayground.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  X = CircuitPlayground.motionX(); //motion input

  soundValue = CircuitPlayground.mic.soundPressureLevel(10);//sound input
  
  Serial.print("X: ");
  Serial.print(X);
  //display values
  Serial.print("  Sound Sensor SPL: ");
  Serial.println(soundValue);


  if (X < -10) {//rotate motion 
    cycleCount++;
      CircuitPlayground.setPixelColor(0, 50,   50,   50);//flash to indicate change of colour
      CircuitPlayground.setPixelColor(1, 50,   50,   50);
      CircuitPlayground.setPixelColor(2, 50,   50,   50);
      CircuitPlayground.setPixelColor(3, 50,   50,   50);
      CircuitPlayground.setPixelColor(4, 50,   50,   50);
      CircuitPlayground.setPixelColor(5, 50,   50,   50);
      CircuitPlayground.setPixelColor(6, 50,   50,   50);
      CircuitPlayground.setPixelColor(7, 50,   50,   50);
      CircuitPlayground.setPixelColor(8, 50,   50,   50);
      CircuitPlayground.setPixelColor(9, 50,   50,   50);
    delay(1000);  
    
  }
  if (X > 10) {//oppsoite rotate motion
    cycleCount--;
      CircuitPlayground.setPixelColor(0, 50,   50,   50);//flash to indicate change of colour
      CircuitPlayground.setPixelColor(1, 50,   50,   50);
      CircuitPlayground.setPixelColor(2, 50,   50,   50);
      CircuitPlayground.setPixelColor(3, 50,   50,   50);
      CircuitPlayground.setPixelColor(4, 50,   50,   50);
      CircuitPlayground.setPixelColor(5, 50,   50,   50);
      CircuitPlayground.setPixelColor(6, 50,   50,   50);
      CircuitPlayground.setPixelColor(7, 50,   50,   50);
      CircuitPlayground.setPixelColor(8, 50,   50,   50);
      CircuitPlayground.setPixelColor(9, 50,   50,   50);
    delay(1000);
    if (cycleCount == 0){
      CircuitPlayground.clearPixels();
    }
  }
  if (cycleCount == -1){
    cycleCount = 3;
  }
 
  if (cycleCount == 4){//reset
    CircuitPlayground.clearPixels();
  }
  if (cycleCount == 5){
    cycleCount = 1;
  }

  if (cycleCount == 1){
      CircuitPlayground.clearPixels();
    if (soundValue <= 40){
      CircuitPlayground.clearPixels();
    }
    else if (soundValue > 40 && soundValue <= 55){//normal sound sensitivty
      CircuitPlayground.setPixelColor(0, 255,   0,   0);//bright red for when you're on alert
    }
    else if (soundValue > 55 && soundValue <= 65){
      CircuitPlayground.setPixelColor(0, 255,   0,   0);
      CircuitPlayground.setPixelColor(1, 255,   0,   0);
    }
    else if (soundValue > 65 && soundValue <= 70){
      CircuitPlayground.setPixelColor(0, 255,   0,   0);
      CircuitPlayground.setPixelColor(1, 255,   0,   0);
      CircuitPlayground.setPixelColor(2, 255,   0,   0);
    }
    else if (soundValue > 70 && soundValue <= 75){
      CircuitPlayground.setPixelColor(0, 255,   0,   0);
      CircuitPlayground.setPixelColor(1, 255,   0,   0);
      CircuitPlayground.setPixelColor(2, 255,   0,   0);
      CircuitPlayground.setPixelColor(3, 255,   0,   0);
    }
    else if (soundValue > 75 && soundValue <= 80){
      CircuitPlayground.setPixelColor(0, 255,   0,   0);
      CircuitPlayground.setPixelColor(1, 255,   0,   0);
      CircuitPlayground.setPixelColor(2, 255,   0,   0);
      CircuitPlayground.setPixelColor(3, 255,   0,   0);
      CircuitPlayground.setPixelColor(4, 255,   0,   0);
    }
    else if (soundValue > 80 && soundValue <= 85){
      CircuitPlayground.setPixelColor(0, 255,   0,   0);
      CircuitPlayground.setPixelColor(1, 255,   0,   0);
      CircuitPlayground.setPixelColor(2, 255,   0,   0);
      CircuitPlayground.setPixelColor(3, 255,   0,   0);
      CircuitPlayground.setPixelColor(4, 255,   0,   0);
      CircuitPlayground.setPixelColor(5, 255,   0,   0);
    }
    else if (soundValue > 85 && soundValue <= 90){
      CircuitPlayground.setPixelColor(0, 255,   0,   0);
      CircuitPlayground.setPixelColor(1, 255,   0,   0);
      CircuitPlayground.setPixelColor(2, 255,   0,   0);
      CircuitPlayground.setPixelColor(3, 255,   0,   0);
      CircuitPlayground.setPixelColor(4, 255,   0,   0);
      CircuitPlayground.setPixelColor(5, 255,   0,   0);
      CircuitPlayground.setPixelColor(6, 255,   0,   0);
    }
    else if (soundValue > 90 && soundValue <= 95){
      CircuitPlayground.setPixelColor(0, 255,   0,   0);
      CircuitPlayground.setPixelColor(1, 255,   0,   0);
      CircuitPlayground.setPixelColor(2, 255,   0,   0);
      CircuitPlayground.setPixelColor(3, 255,   0,   0);
      CircuitPlayground.setPixelColor(4, 255,   0,   0);
      CircuitPlayground.setPixelColor(5, 255,   0,   0);
      CircuitPlayground.setPixelColor(6, 255,   0,   0);
      CircuitPlayground.setPixelColor(7, 255,   0,   0);
    }
    else if (soundValue > 95 && soundValue <= 105){
      CircuitPlayground.setPixelColor(0, 255,   0,   0);
      CircuitPlayground.setPixelColor(1, 255,   0,   0);
      CircuitPlayground.setPixelColor(2, 255,   0,   0);
      CircuitPlayground.setPixelColor(3, 255,   0,   0);
      CircuitPlayground.setPixelColor(4, 255,   0,   0);
      CircuitPlayground.setPixelColor(5, 255,   0,   0);
      CircuitPlayground.setPixelColor(6, 255,   0,   0);
      CircuitPlayground.setPixelColor(7, 255,   0,   0);
      CircuitPlayground.setPixelColor(8, 255,   0,   0);
    }
    else if (soundValue > 105 && soundValue <= 120){
      CircuitPlayground.setPixelColor(0, 255,   0,   0);
      CircuitPlayground.setPixelColor(1, 255,   0,   0);
      CircuitPlayground.setPixelColor(2, 255,   0,   0);
      CircuitPlayground.setPixelColor(3, 255,   0,   0);
      CircuitPlayground.setPixelColor(4, 255,   0,   0);
      CircuitPlayground.setPixelColor(5, 255,   0,   0);
      CircuitPlayground.setPixelColor(6, 255,   0,   0);
      CircuitPlayground.setPixelColor(7, 255,   0,   0);
      CircuitPlayground.setPixelColor(8, 255,   0,   0);
      CircuitPlayground.setPixelColor(9, 255,   0,   0);
    }
  }

  
  else if (cycleCount == 2){
      CircuitPlayground.clearPixels();
      if (soundValue <= 40){
      CircuitPlayground.clearPixels();
    }
    else if (soundValue > 0 && soundValue <= 35){
      CircuitPlayground.setPixelColor(0, 75,   129,   34);//more sensitive
    }
    else if (soundValue > 35 && soundValue <= 40){
      CircuitPlayground.setPixelColor(0, 75,   129,   34);
      CircuitPlayground.setPixelColor(1, 75,   129,   34);
    }
    else if (soundValue > 40 && soundValue <= 45){
      CircuitPlayground.setPixelColor(0, 75,   129,   34);
      CircuitPlayground.setPixelColor(1, 75,   129,   34);
      CircuitPlayground.setPixelColor(2, 75,   129,   34);
    }
    else if (soundValue > 45 && soundValue <= 50){
      CircuitPlayground.setPixelColor(0, 75,   129,   34);
      CircuitPlayground.setPixelColor(1, 75,   129,   34);
      CircuitPlayground.setPixelColor(2, 75,   129,   34);
      CircuitPlayground.setPixelColor(3, 75,   129,   34);
    }
    else if (soundValue > 50 && soundValue <= 55){
      CircuitPlayground.setPixelColor(0, 75,   129,   34);
      CircuitPlayground.setPixelColor(1, 75,   129,   34);
      CircuitPlayground.setPixelColor(2, 75,   129,   34);
      CircuitPlayground.setPixelColor(3, 75,   129,   34);
      CircuitPlayground.setPixelColor(4, 75,   129,   34);
    }
    else if (soundValue > 55 && soundValue <= 60){
      CircuitPlayground.setPixelColor(0, 75,   129,   34);
      CircuitPlayground.setPixelColor(1, 75,   129,   34);
      CircuitPlayground.setPixelColor(2, 75,   129,   34);
      CircuitPlayground.setPixelColor(3, 75,   129,   34);
      CircuitPlayground.setPixelColor(4, 75,   129,   34);
      CircuitPlayground.setPixelColor(5, 75,   129,   34);
    }
    else if (soundValue > 60 && soundValue <= 65){
      CircuitPlayground.setPixelColor(0, 75,   129,   34);
      CircuitPlayground.setPixelColor(1, 75,   129,   34);
      CircuitPlayground.setPixelColor(2, 75,   129,   34);
      CircuitPlayground.setPixelColor(3, 75,   129,   34);
      CircuitPlayground.setPixelColor(4, 75,   129,   34);
      CircuitPlayground.setPixelColor(5, 75,   129,   34);
      CircuitPlayground.setPixelColor(6, 75,   129,   34);
    }
    else if (soundValue > 65 && soundValue <= 70){
      CircuitPlayground.setPixelColor(0, 75,   129,   34);
      CircuitPlayground.setPixelColor(1, 75,   129,   34);
      CircuitPlayground.setPixelColor(2, 75,   129,   34);
      CircuitPlayground.setPixelColor(3, 75,   129,   34);
      CircuitPlayground.setPixelColor(4, 75,   129,   34);
      CircuitPlayground.setPixelColor(5, 75,   129,   34);
      CircuitPlayground.setPixelColor(6, 75,   129,   34);
      CircuitPlayground.setPixelColor(7, 75,   129,   34);
    }
    else if (soundValue > 70 && soundValue <= 75){
      CircuitPlayground.setPixelColor(0, 75,   129,   34);
      CircuitPlayground.setPixelColor(1, 75,   129,   34);
      CircuitPlayground.setPixelColor(2, 75,   129,   34);
      CircuitPlayground.setPixelColor(3, 75,   129,   34);
      CircuitPlayground.setPixelColor(4, 75,   129,   34);
      CircuitPlayground.setPixelColor(5, 75,   129,   34);
      CircuitPlayground.setPixelColor(6, 75,   129,   34);
      CircuitPlayground.setPixelColor(7, 75,   129,   34);
      CircuitPlayground.setPixelColor(8, 75,   129,   34);
    }
    else if (soundValue > 75 && soundValue <= 80){
      CircuitPlayground.setPixelColor(0, 75,   129,   34);
      CircuitPlayground.setPixelColor(1, 75,   129,   34);
      CircuitPlayground.setPixelColor(2, 75,   129,   34);
      CircuitPlayground.setPixelColor(3, 75,   129,   34);
      CircuitPlayground.setPixelColor(4, 75,   129,   34);
      CircuitPlayground.setPixelColor(5, 75,   129,   34);
      CircuitPlayground.setPixelColor(6, 75,   129,   34);
      CircuitPlayground.setPixelColor(7, 75,   129,   34);
      CircuitPlayground.setPixelColor(8, 75,   129,   34);
      CircuitPlayground.setPixelColor(9, 75,   129,   34);
    }
  }


  else if (cycleCount == 3){
    CircuitPlayground.clearPixels();
      if (soundValue <= 40){
      CircuitPlayground.clearPixels();
    }
    else if (soundValue > 40 && soundValue <= 60){
      CircuitPlayground.setPixelColor(0, 0,   111,   255);//users prefrence of colour
    }
    else if (soundValue > 60 && soundValue <= 70){
      CircuitPlayground.setPixelColor(0, 0,   111,   255);
      CircuitPlayground.setPixelColor(1, 0,   111,   255);
    }
    else if (soundValue > 70 && soundValue <= 80){
      CircuitPlayground.setPixelColor(0, 0,   111,   255);
      CircuitPlayground.setPixelColor(1, 0,   111,   255);
      CircuitPlayground.setPixelColor(2, 0,   111,   255);
    }
    else if (soundValue > 80 && soundValue <= 90){
      CircuitPlayground.setPixelColor(0, 0,   111,   255);
      CircuitPlayground.setPixelColor(1, 0,   111,   255);
      CircuitPlayground.setPixelColor(2, 0,   111,   255);
      CircuitPlayground.setPixelColor(3, 0,   111,   255);
    }
    else if (soundValue > 90 && soundValue <= 100){
      CircuitPlayground.setPixelColor(0, 0,   111,   255);
      CircuitPlayground.setPixelColor(1, 0,   111,   255);
      CircuitPlayground.setPixelColor(2, 0,   111,   255);
      CircuitPlayground.setPixelColor(3, 0,   111,   255);
      CircuitPlayground.setPixelColor(4, 0,   111,   255);
    }
    else if (soundValue > 100 && soundValue <= 110){
      CircuitPlayground.setPixelColor(0, 0,   111,   255);
      CircuitPlayground.setPixelColor(1, 0,   111,   255);
      CircuitPlayground.setPixelColor(2, 0,   111,   255);
      CircuitPlayground.setPixelColor(3, 0,   111,   255);
      CircuitPlayground.setPixelColor(4, 0,   111,   255);
      CircuitPlayground.setPixelColor(5, 0,   111,   255);
    }
    else if (soundValue > 110 && soundValue <= 120){
      CircuitPlayground.setPixelColor(0, 0,   111,   255);
      CircuitPlayground.setPixelColor(1, 0,   111,   255);
      CircuitPlayground.setPixelColor(2, 0,   111,   255);
      CircuitPlayground.setPixelColor(3, 0,   111,   255);
      CircuitPlayground.setPixelColor(4, 0,   111,   255);
      CircuitPlayground.setPixelColor(5, 0,   111,   255);
      CircuitPlayground.setPixelColor(6, 0,   111,   255);
    }
    else if (soundValue > 120 && soundValue <= 130){
      CircuitPlayground.setPixelColor(0, 0,   111,   255);
      CircuitPlayground.setPixelColor(1, 0,   111,   255);
      CircuitPlayground.setPixelColor(2, 0,   111,   255);
      CircuitPlayground.setPixelColor(3, 0,   111,   255);
      CircuitPlayground.setPixelColor(4, 0,   111,   255);
      CircuitPlayground.setPixelColor(5, 0,   111,   255);
      CircuitPlayground.setPixelColor(6, 0,   111,   255);
      CircuitPlayground.setPixelColor(7, 0,   111,   255);
    }
    else if (soundValue > 130 && soundValue <= 140){
      CircuitPlayground.setPixelColor(0, 0,   111,   255);
      CircuitPlayground.setPixelColor(1, 0,   111,   255);
      CircuitPlayground.setPixelColor(2, 0,   111,   255);
      CircuitPlayground.setPixelColor(3, 0,   111,   255);
      CircuitPlayground.setPixelColor(4, 0,   111,   255);
      CircuitPlayground.setPixelColor(5, 0,   111,   255);
      CircuitPlayground.setPixelColor(6, 0,   111,   255);
      CircuitPlayground.setPixelColor(7, 0,   111,   255);
      CircuitPlayground.setPixelColor(8, 0,   111,   255);
    }
    else if (soundValue > 140  && soundValue <= 150){
      CircuitPlayground.setPixelColor(0, 0,   111,   255);
      CircuitPlayground.setPixelColor(1, 0,   111,   255);
      CircuitPlayground.setPixelColor(2, 0,   111,   255);
      CircuitPlayground.setPixelColor(3, 0,   111,   255);
      CircuitPlayground.setPixelColor(4, 0,   111,   255);
      CircuitPlayground.setPixelColor(5, 0,   111,   255);
      CircuitPlayground.setPixelColor(6, 0,   111,   255);
      CircuitPlayground.setPixelColor(7, 0,   111,   255);
      CircuitPlayground.setPixelColor(8, 0,   111,   255);
      CircuitPlayground.setPixelColor(9, 0,   111,   255);
    }
  }


  else {//cycleCount = 0
    CircuitPlayground.clearPixels();
  }
  
  delay(100);

}
