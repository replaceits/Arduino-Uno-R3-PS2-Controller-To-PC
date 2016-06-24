#include "HID-Project.h"

#define INPUT_SIZE 80

void setup() {
  Serial1.begin(115200);
  Gamepad.begin();
}

/*
 * DU,DD,DL,DR,LXAXIS,LYAXIS,RAXIS,RYAXIS,L1,L2,L3,R1,R2,R3,X,S,C,T,SEL,STR
 * 0,000,000,000,000,0,0,0,0,0,0,0,0,0,0,0,0\n
 */

void loop() {
  if(Serial1.available() > 0){
    char input[INPUT_SIZE];
    byte size = Serial1.readBytesUntil('\n', input, INPUT_SIZE);
    char* command = strtok(input, ",\n");
    unsigned short int count = 0;
    while (command != NULL)
    {
      switch(count){
        case 0:
          Gamepad.xAxis(atoi(command));
          break;
        case 1:
          Gamepad.yAxis(atoi(command));
          break;
        case 2:
          Gamepad.rxAxis(atoi(command));
          break;
        case 3:
          Gamepad.ryAxis(atoi(command));
          break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
          if(atoi(command) == 1){
            Gamepad.press(count);
          } else {
            Gamepad.release(count);
          }
        default:
          break;
      }
      command = strtok(NULL, ",\n");
      count++;
    }
    Gamepad.write();
  }
}
