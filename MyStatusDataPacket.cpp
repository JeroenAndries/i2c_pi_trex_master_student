#include "MyStatusDataPacket.h"


 namespace TRexLib{

    /*functie die de JSON-string genereerd*/
    string MyStatusDataPacket::toJSON(void)
    {   /*
        Voorlopige datamembers om toegang te krijgen tot de members
        van de structs AcceleroMeter en Impact -> (x,y,z)
        */
        AcceleroMeter ameter;
        ameter=getAcceleroMeter();
        Impact impact;
        impact=getImpact();
        
        /*Instantiatie van de JsonClass*/
        JsonClass json;
        /*return string waarin alle json-members worden opgeslagen*/
        string jsonString;
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

        /*returnwaarde naar main, om zo naar de website verstuurd te worden*/
        return jsonString;
    }

    void MyStatusDataPacket::fromJSON(string json) 
    {

    }

    void MyStatusDataPacket::toTRex(char* buffer)
    {

    }

    /*functie die data(byte-sequentie) van de TRex krijgt*/
    void MyStatusDataPacket::fromTRex(char * data)
    {
        /*
        Voorlopige datamembers om toegang te krijgen tot:
        -double en int waarden bestaande uit beiden twee bytes
        -de members van de structs AcceleroMeter en Impact -> (x,y,z)
        */
        double d;
        int i;
        AcceleroMeter ameter;
        Impact impact;
        
        /*Startbyte en errorflags elk bestaande uit één byte*/
    	setStartByte(*(data+STATUS_START));
       	setErrorFlags(*(data+STATUS_ERROR));

        /*
        Alle andere double en int waarden bestaand uit twee bytes
        Om de correcte plaats van de MSB en LSB te garanderen wordt eerst de MSB gekopieerd
        en acht bit verschoven, waarna de LSB terug gekopieerd wordt.
        Dit om te voorkomen dat een andere processor met een andere indiannes anders zou reageren 
        op een memcpy... (Big-Indian->MSB op de eerste plaats / Little-Indian->LSB op de eerste plaats)
        */
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
