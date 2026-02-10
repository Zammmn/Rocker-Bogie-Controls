//PIN VARIABLES
//the motor will be controlled by the motor A pins on the motor driver

const int AIN1_FL = 50;           //control pin 1 on the motor driver for the right motor
const int AIN2_FL = 52;            //control pin 2 on the motor driver for the right motor
const int PWMA_FL = 13;            //speed control pin on the motor driver for the right motor

const int BIN1_BL = 51;           //control pin 1 on the motor driver for the right motor
const int BIN2_BL = 53;            //control pin 2 on the motor driver for the right motor
const int PWMB_BL = 12;            //speed control pin on the motor driver for the right motor

const int AIN1_ML = 44;           //control pin 1 on the motor driver for the right motor
const int AIN2_ML = 46;            //control pin 2 on the motor driver for the right motor
const int PWMA_ML = 9;            //speed control pin on the motor driver for the right motor

const int BIN1_MR = 45;           //control pin 1 on the motor driver for the right motor
const int BIN2_MR = 47;            //control pin 2 on the motor driver for the right motor
const int PWMB_MR = 8;            //speed control pin on the motor driver for the right motor

const int AIN1_BR = 38;           //control pin 1 on the motor driver for the right motor
const int AIN2_BR = 40;            //control pin 2 on the motor driver for the right motor
const int PWMA_BR = 5;            //speed control pin on the motor driver for the right motor

const int BIN1_FR = 39;           //control pin 1 on the motor driver for the right motor
const int BIN2_FR = 41;            //control pin 2 on the motor driver for the right motor
const int PWMB_FR = 4;            //speed control pin on the motor driver for the right motor


//int switchPin = 7;             //switch to turn the robot on and off

//VARIABLES
int motorSpeed = 0;       //starting speed for the motor

void setup() {
//  pinMode(switchPin, INPUT_PULLUP);   //set this as a pullup to sense whether the switch is flipped

  //set the motor control pins as outputs
pinMode(AIN1_FL, OUTPUT);
pinMode(AIN2_FL, OUTPUT);
pinMode(PWMA_FL, OUTPUT);

pinMode(AIN1_ML, OUTPUT);
pinMode(AIN2_ML, OUTPUT);
pinMode(PWMA_ML, OUTPUT);

pinMode(BIN1_BL, OUTPUT);
pinMode(BIN2_BL, OUTPUT);
pinMode(PWMB_BL, OUTPUT);

pinMode(BIN1_FR, OUTPUT);
pinMode(BIN2_FR, OUTPUT);
pinMode(PWMB_FR, OUTPUT);

pinMode(BIN1_MR, OUTPUT);
pinMode(BIN2_MR, OUTPUT);
pinMode(PWMB_MR, OUTPUT);

pinMode(AIN1_BR, OUTPUT);
pinMode(AIN2_BR, OUTPUT);
pinMode(PWMA_BR, OUTPUT);

Serial.begin(115200);
  

    

  //Serial.println("Enter motor speed (0-255)... ");    //Prompt to get input in the serial monitor.
}

void loop() {

  if (Serial.available()> 0) {//if the user has entered something in the serial monitor
  
    String command=Serial.readStringUntil('\n');
    
    if (command == "forward") 
    {
      Serial.println("Moving Forward: ");
      int  motorSpeed=120;
      Serial.print("Motor Speed: ");
      Serial.println(motorSpeed);
       
      digitalWrite(AIN1_FL, HIGH);                         //set pin 1 to high
      digitalWrite(AIN2_FL, LOW);
      analogWrite(PWMA_FL, abs(motorSpeed));
  
      digitalWrite(BIN1_FR, HIGH);                         //set pin 1 to high
      digitalWrite(BIN2_FR, LOW);
      analogWrite(PWMB_FR, abs(motorSpeed));
  
      digitalWrite(AIN1_ML, HIGH);                         //set pin 1 to high
      digitalWrite(AIN2_ML, LOW);
      analogWrite(PWMA_ML, abs(motorSpeed));
  
      digitalWrite(BIN1_MR, HIGH);                         //set pin 1 to high
      digitalWrite(BIN2_MR, LOW);
      analogWrite(PWMB_MR, abs(motorSpeed));
  
      digitalWrite(AIN1_BR, HIGH);                         //set pin 1 to high
      digitalWrite(AIN2_BR, LOW);
      analogWrite(PWMA_BR, abs(motorSpeed));
  
      digitalWrite(BIN1_BL, HIGH);                         //set pin 1 to high
      digitalWrite(BIN2_BL, LOW);
      analogWrite(PWMB_BL, abs(motorSpeed));
   }
   else if (command == "backward") {
      Serial.println("Moving Forward: ");
      int  motorSpeed=120;
      Serial.print("Motor Speed: ");
      Serial.println(motorSpeed);
       
      digitalWrite(AIN1_FL, LOW);                         //set pin 1 to high
      digitalWrite(AIN2_FL, HIGH);
      analogWrite(PWMA_FL, abs(motorSpeed));
  
      digitalWrite(BIN1_FR, LOW);                         //set pin 1 to high
      digitalWrite(BIN2_FR, HIGH);
      analogWrite(PWMB_FR, abs(motorSpeed));
  
      digitalWrite(AIN1_ML, LOW);                         //set pin 1 to high
      digitalWrite(AIN2_ML, HIGH);
      analogWrite(PWMA_ML, abs(motorSpeed));
  
      digitalWrite(BIN1_MR, LOW);                         //set pin 1 to high
      digitalWrite(BIN2_MR, HIGH);
      analogWrite(PWMB_MR, abs(motorSpeed));
  
      digitalWrite(AIN1_BR, LOW);                         //set pin 1 to high
      digitalWrite(AIN2_BR, HIGH);
      analogWrite(PWMA_BR, abs(motorSpeed));
  
      digitalWrite(BIN1_BL, LOW);                         //set pin 1 to high
      digitalWrite(BIN2_BL, HIGH);
      analogWrite(PWMB_BL, abs(motorSpeed));
   } 
   else if (command == "stop")  {
      int  motorSpeed=0;
      Serial.print("Motor Speed: ");
      Serial.println(motorSpeed);
      analogWrite(PWMA_FL, abs(motorSpeed));
      analogWrite(PWMB_FR, abs(motorSpeed));

      analogWrite(PWMA_ML, abs(motorSpeed));
      analogWrite(PWMB_MR, abs(motorSpeed));
      
      analogWrite(PWMA_BR, abs(motorSpeed));
      analogWrite(PWMB_BL, abs(motorSpeed));
    }
   }
  }
/********************************************************************************/
//  analogWrite(PWMA_FL, abs(motorSpeed));                 //now that the motor direction is set, drive it at the entered speed
//  analogWrite(PWMB_FR, abs(motorSpeed));                 //now that the motor direction is set, drive it at the entered speed
//  analogWrite(PWMA_BR, abs(motorSpeed));                 //now that the motor direction is set, drive it at the entered speed
//  analogWrite(PWMB_BL, abs(motorSpeed));                 //now that the motor direction is set, drive it at the entered speed
//}
