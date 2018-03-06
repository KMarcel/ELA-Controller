#include <Nextion_Marcel.h>
NexTion t0 = NexTion(0, "t0");
NexTion t1 = NexTion(0, "t1");
NexTion t4 = NexTion(0, "t4");
NexTion t8 = NexTion(0, "t8");
NexTion t9 = NexTion(0, "t9");
NexTion t10 = NexTion(0, "t10");
byte h = 15,mi = 26,d = 6,m = 3,y = 18;
String Alarme[10];
long prev;


String Clock(byte Stunde,byte Minute)
{
  String __Clock__ = String(Stunde);
  __Clock__ += ":";
  __Clock__ += String(Minute);
  __Clock__ += " Uhr";
  return __Clock__;
}
String Datum(byte Tag, byte Monat, byte Jahr)
{
  String __Datum__ = String(Tag);
  __Datum__ += ".";
  __Datum__ += String(Monat);
  __Datum__ += ".20";
  __Datum__ += String(Jahr);
  return __Datum__;
}
void setup() {
  Alarme[0] = "8:40 Uhr Kaffee";
  Alarme[1] = "9:00 Uhr FP";
  Alarme[2] = "9:15 Uhr FPE";
  Alarme[3] = "11:35 Uhr Kaffee";
  Alarme[4] = "11:55 Uhr MP";
  prev = millis();
}

void loop() {
  if(millis() - prev > 60000){
    mi++;
    if(mi == 60)
    {
      h++;
      mi = 0;
    }
  }
  t0.SendText(Clock(h,mi));
  delay(30);
  t1.SendText(Datum(d,m,y));
  delay(30);
  t4.SendText(Alarme[0]);
  delay(30);
  t8.SendText(Alarme[1]);
  delay(30);
  t9.SendText(Alarme[2]);
  delay(30);
  t10.SendText(Alarme[3]);
  delay(30);
}
