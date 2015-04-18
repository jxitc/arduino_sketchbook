/*
* 发射红外线讯号
*     注意! 红外线发射器(IR LED)必须接到 pin 3, 不能接其它脚位
*/
#include <IRremote.h>                  // 引用 IRRemote 函式库
                            
const int buttonPin = 4;                 // 按键(pushbutton)接在 pin 4
int buttonState = 0;                     // 按键状态
int RECV_PIN = 11;

IRsend irsend;                          // 定义 IRsend D物件来发射红外线讯号


             
void setup()
{
  Serial.begin(9600);

}
                            
void loop()
{
  Serial.println("Sending signal...");
  irsend.sendNEC(0x32A6A857, 32);   // 记得换成你遥控器的红外线编码
  delay(500);
  irsend.sendNEC(0x32A638C7, 32);
  delay(500);
}
