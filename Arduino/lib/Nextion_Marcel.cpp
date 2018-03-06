#include "Nextion_Marcel.h"
#define NexTionSerial Serial
/*#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);*/

NexTion::NexTion(int PgID, String ComID){
	this->PgID = PgID;
	this->ComID = ComID;
	NexTionSerial.begin(115200);
}
void NexTion::SendText(String Command){
	while (NexTionSerial.available())
    {
        NexTionSerial.read();
    }
    /*if(this->PgID > 0){
      String __page = String(PgID);
      for (int i = 0; i < __page.length(); i++)
      {
        mySerial.write(__page[i]);   // Push each char 1 by 1 on each loop pass  
      }
      mySerial.write(0xFF);
      mySerial.write(0xFF);
      mySerial.write(0xFF);
      delay(100);
    }*/
    write_Nextion(Command);
}
bool NexTion::write_Nextion(String Command){
	String cmd;
    cmd += this->ComID;
    cmd += ".txt=\"";
    cmd += Command;
    cmd += "\"";
    for (int i = 0; i < cmd.length(); i++)
    {
      NexTionSerial.write(cmd[i]);   // Push each char 1 by 1 on each loop pass  
    }
    NexTionSerial.write(0xFF);
    NexTionSerial.write(0xFF);
    NexTionSerial.write(0xFF);
}
void NexTion::SendNummer(uint32_t Command){
	
}
uint32_t NexTion::Button(void){
	
}