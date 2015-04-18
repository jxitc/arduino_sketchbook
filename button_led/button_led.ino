/*
作者：极客工坊
时间：2012年5月24日
IDE版本号：1.0.1
发布地址：[url=http://www.geek-workshop.com]www.geek-workshop.com[/url]
作用:当你按下按钮后1秒钟，灯会亮，然后维持5秒钟，熄灭
*/
 
void setup ()
{
  Serial.begin(9600);
  pinMode(2,INPUT);                 //将4号数字口设置为输入状态，13号数字口设置为输出状态
  pinMode(13,OUTPUT);
}
 
void loop()
{
  int n =digitalRead(2);                   //创建一个变量n，将4号数字口的状态采集出来赋值给他。
  if (n==HIGH)                             //判断n是否为高电平，如果是执行下面的语句，不是则跳过。
  {
    Serial.println("HIGH");
    digitalWrite(13,HIGH);
  } else {
    Serial.println("LOW");
      digitalWrite(13,LOW);
  }
}

