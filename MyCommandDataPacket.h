#include <string>
#include <cstring>
#include "CommandDataPacket.h"
#include "AcceleroMeter.h"
#include "JsonClass.h"

#ifndef MYCOMMANDDATAPACKET_H
#define MYCOMMANDDATAPACKET_H

using namespace std;

namespace TRexLib{

    class MyCommandDataPacket: public CommandDataPacket{
            double d;
            int i; 
        public:
            string jsonString;
            string toJSON(void);
            void fromJSON(string json);
            void toTRex(char* buffer);
            void fromTRex(char * data);      
    };
}

#endif