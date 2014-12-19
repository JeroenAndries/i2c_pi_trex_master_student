#include "MyStatusDataPacket.h"


 namespace TRexLib{

    string MyStatusDataPacket::toJSON(void)
    {
        AcceleroMeter ameter;
        ameter=getAcceleroMeter();
        Impact impact;
        impact=getImpact();

        JsonClass json;
        jsonString == "{"
        +json.charValue("startbyte",getStartByte()) +","
        +json.charValue("errorflags",getErrorFlags()) +","
        +json.doubleValue("batteryvoltage",getBatteryVoltage()) +","
        +json.doubleValue("leftmotorcurrent",getMotorCurrent(LEFT)) +","
        +json.doubleValue("rightmotorcurrent",getMotorCurrent(RIGHT)) +","
        +json.intValue("leftencodercount",getEncoderCount(LEFT)) +","
        +json.intValue("rightencodercount",getEncoderCount(RIGHT)) +","
        +json.intValue("AcceleroMeter x",ameter.x) +","
        +json.intValue("AcceleroMeter y",ameter.y) +","
        +json.intValue("AcceleroMeter z",ameter.z) +","
        +json.intValue("Impact x",impact.x) +","
        +json.intValue("Impact y",impact.y) +","
        +json.intValue("Impact z",impact.z) +","
        +"}";

        return jsonString;
    }

    void MyStatusDataPacket::fromJSON(string json) 
    {

    }

    void MyStatusDataPacket::toTRex(char* buffer)
    {

    }

    void MyStatusDataPacket::fromTRex(char * data)
    {
        AcceleroMeter ameter;
        Impact impact;

    	setStartByte(*data);
       	setErrorFlags(*data+1);

		memcpy(&d, data+2, sizeof(int));
        d=d/100.00;
        setBatteryVoltage((double)d);

        memcpy(&d, data+4, sizeof(double));
        setMotorCurrent(LEFT,d);
        memcpy(&i, data+8, sizeof(int));
        setEncoderCount(LEFT,i);

        memcpy(&d, data+6, sizeof(double));
        setMotorCurrent(RIGHT,d);
        memcpy(&i, data+10, sizeof(int));
        setEncoderCount(RIGHT,i);
               
        memcpy(&ameter.x, data+12, sizeof(int));
        memcpy(&ameter.y, data+14, sizeof(int));
        memcpy(&ameter.z, data+16, sizeof(int));
        setAcceleroMeter(ameter);

        memcpy(&impact.x, data+18, sizeof(int));
        memcpy(&impact.y, data+20, sizeof(int));
        memcpy(&impact.z, data+22, sizeof(int));
        setImpact(impact);
    }
}
