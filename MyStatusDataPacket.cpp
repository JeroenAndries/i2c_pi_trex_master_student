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

    	setStartByte(*(data+STATUS_START));
       	setErrorFlags(*(data+STATUS_ERROR));

        d=((*(data+STATUS_BATTERY_MSB)<<8)+(*(data+STATUS_BATTERY_LSB)))/100.0;
        setBatteryVoltage(d);

        d=(*(data+STATUS_LEFT_MOTOR_CURRENT_MSB)<<8)+(*(data+STATUS_LEFT_MOTOR_CURRENT_LSB));
        setMotorCurrent(LEFT,d);
        i=(*(data+STATUS_LEFT_ENCODER_COUNT_MSB)<<8)+(*(data+STATUS_LEFT_ENCODER_COUNT_LSB));
        setEncoderCount(LEFT,i);

        d=(*(data+STATUS_RIGHT_MOTOR_CURRENT_MSB)<<8)+(*(data+STATUS_RIGHT_MOTOR_CURRENT_LSB));
        setMotorCurrent(RIGHT,d);
        i=(*(data+STATUS_RIGHT_ENCODER_COUNT_MSB)<<8)+(*(data+STATUS_RIGHT_ENCODER_COUNT_LSB));
        setEncoderCount(RIGHT,i);
               
        ameter.x=(*(data+STATUS_ACCELEROMETER_X_MSB)<<8)+(*(data+STATUS_ACCELEROMETER_X_LSB));
        ameter.y=(*(data+STATUS_ACCELEROMETER_Y_MSB)<<8)+(*(data+STATUS_ACCELEROMETER_Y_LSB));
        ameter.z=(*(data+STATUS_ACCELEROMETER_Z_MSB)<<8)+(*(data+STATUS_ACCELEROMETER_Z_LSB));
        setAcceleroMeter(ameter);

        impact.x=(*(data+STATUS_IMPACT_X_MSB)<<8)+(*(data+STATUS_IMPACT_X_LSB));
        impact.y=(*(data+STATUS_IMPACT_Y_MSB)<<8)+(*(data+STATUS_IMPACT_Y_LSB));
        impact.z=(*(data+STATUS_IMPACT_Z_MSB)<<8)+(*(data+STATUS_IMPACT_Z_LSB));
        setImpact(impact);
    }
}
