#include <string.h>
#include "Side.h"
#include "DataPacket.h"

#ifndef TREX_COMMAND_DATA_PACKET_H
#define TREX_COMMAND_DATA_PACKET_H

namespace TRexLib{

    /*
     * Possible PWN frequencies for the motor control.
     */
    enum PWMFrequency {
        PWMF_31250HZ, PWMF_3906HZ, PWMF_977HZ, PWMF_488HZ, PWMF_244HZ, PWMF_122HZ, PWMF_31HZ
    };

    /*
     * Possible I2C frequencies.
     */
    enum ClockFrequency { CF_100KHZ, CF_400KHZ };

    class CommandDataPacket: public DataPacket{
        public:
            /* Number of bytes in the TREX byte array representation */
            const static int SIZE_TREX_DATA_PACKET = 27;

            /* Number of servos the system can control */
            const static int NUMBER_OF_SERVOS = 6;

        /* Getters are only needed internally so we set them protected */
        protected:
            unsigned char getStartByte(void);
            PWMFrequency getPwmFrequency(void);
            int getMotorSpeed(Side side);
            bool getMotorBrake(Side side);
            int getServoPosition(int location);
            unsigned char getAcceleroMeterDevibrate(void);
            unsigned char getImpactSensitivity(void);
            int getLowBatteryVoltage(void);
            unsigned char getI2CAddress(void);
            ClockFrequency getI2CClockFrequency(void);

        /* Setters need to be accessible by all */
        public:
            void setStartByte(char start);
            void setPwmFrequency(PWMFrequency freq);
            void setMotorSpeed(Side side, int speed);
            void setMotorBrake(Side side, bool on);
            void setServoPosition(int location, int position);
            void setAcceleroMeterDevibrate(unsigned char devibrate);
            void setLowBatteryVoltage(int sensitivity);
            void setI2CAddress(unsigned char address);
            void setI2CClockFrequency(ClockFrequency frequency);

        private:
            char startbyte;
            int motorspeed;
            bool motorbrake;
            int servoposition;
            unsigned char amdvibrate;
            unsigned char impactsens;
            int lowbatteryvoltage;
            unsigned char i2cadress;
    };
}

#endif