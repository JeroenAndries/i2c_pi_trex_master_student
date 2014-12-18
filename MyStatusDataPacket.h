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
