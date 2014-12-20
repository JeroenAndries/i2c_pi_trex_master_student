#include <string>
#include <cstring>
#include "StatusDataPacket.h"
#include "AcceleroMeter.h"
#include "JsonClass.h"

#ifndef MYSTATUSDATAPACKET_H
#define MYSTATUSDATAPACKET_H

using namespace std;

namespace TRexLib{

    class MyStatusDataPacket: public StatusDataPacket{ 
    /*
    MyStatusDataPacket-> inherits StatusDataPacket
	Om toegang te krijgen tot alle private members van StatusDataPacket zijn er
	setters (protected) en getters (public) in het leven geroepen.
	In principe zijn enkel de getters nodig want de 'status' wordt enkel uitgelezen.
    
    StatusDataPacket-> inherits DataPacket
    met virtuele functies toJSON, fromJSON, toTRex en fromTRex
    dus hier kunnen deze functies gebruikt worden als onafhankelijke members
    dus de functies kunnen nog eens onafhankelijk gedeclareerd worden in MyCommandDataPacket
    */
        public:
            string jsonString;
            string toJSON(void);
            void fromJSON(string json);
            void toTRex(char* buffer);
            void fromTRex(char * data); 
    };
}

#endif
