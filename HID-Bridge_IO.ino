#include <PS2X_lib.h>  //for v1.6

#define PS2_DAT        13  //14    
#define PS2_CMD        11  //15
#define PS2_SEL        10  //16
#define PS2_CLK        12  //17
#define LED            8

PS2X ps2x;

int error = 0;
byte type = 0;

void setup() {
  Serial.begin(115200);

  delay(300);
  
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);
  type = ps2x.readType(); 

  pinMode(LED,OUTPUT);
}

/*
 * DPAD,LXAXIS,LYAXIS,RAXIS,RYAXIS,L1,L2,L3,R1,R2,R3,X,S,C,T,SEL,STR
 * 0,000,000,000,000,0,0,0,0,0,0,0,0,0,0,0,0\n
 */
void loop() {
  if(error == 1){
    digitalWrite(LED,HIGH);
    delay(100);  
    digitalWrite(LED,LOW);;
    delay(100);
    return; 
  }
  ps2x.read_gamepad(false, 0);

  Serial.print(map(ps2x.Analog(PSS_LX),0,255,-32767,32767));
  Serial.print(',');
  Serial.print(map(ps2x.Analog(PSS_LY),0,255,-32767,32767));
  Serial.print(',');
  Serial.print(map(ps2x.Analog(PSS_RX),0,255,-32767,32767));
  Serial.print(',');
  Serial.print(map(ps2x.Analog(PSS_RY),0,255,-32767,32767));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_PAD_UP));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_PAD_DOWN));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_PAD_LEFT));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_PAD_RIGHT));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_L1));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_L2));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_L3));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_R1));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_R2));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_R3));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_CROSS));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_SQUARE));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_CIRCLE));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_TRIANGLE));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_SELECT));
  Serial.print(',');
  Serial.print(ps2x.Button(PSB_START));
  Serial.print(',');
  Serial.print('0');
  Serial.print('\n');
  delay(50);
}
