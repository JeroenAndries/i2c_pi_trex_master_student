#include <string.h>
#include "Side.h"
#include "CommandDataPacket.h"

namespace TRexLib{

    unsigned char CommandDataPacket::getStartByte(void){
        return this->startbyte;
    }

    void CommandDataPacket::setStartByte(char start){
        this->startbyte = start;
    }

    PWMFrequency CommandDataPacket::getPwmFrequency(void){
        PWMFrequency PWM;
        return PWM;
    }

    void CommandDataPacket::setPwmFrequency(PWMFrequency freq){
        PWMFrequency PWM;
        PWM = freq;
    }

    int CommandDataPacket::getMotorSpeed(Side side){
        return 0;
    }

    void CommandDataPacket::setMotorSpeed(Side side, int speed){

    }

    bool CommandDataPacket::getMotorBrake(Side side){
        return true;
    }

    void CommandDataPacket::setMotorBrake(Side side, bool on){

    }

    int CommandDataPacket::getServoPosition(int location){
        return 0;
    }

    void CommandDataPacket::setServoPosition(int location, int position){

    }

    unsigned char CommandDataPacket::getAcceleroMeterDevibrate(void){
        unsigned char amd;
        return amd;
    }

    void CommandDataPacket::setAcceleroMeterDevibrate(unsigned char devibrate){

    }

    unsigned char CommandDataPacket::getImpactSensitivity(void){
        unsigned char iS;
        return iS;
    }

    int CommandDataPacket::getLowBatteryVoltage(void){
        return 0;
    }

    void CommandDataPacket::setLowBatteryVoltage(int sensitivity){

    }

    unsigned char CommandDataPacket::getI2CAddress(void){
        unsigned char adress;
        return adress;
    }

    void CommandDataPacket::setI2CAddress(unsigned char address){

    }

    ClockFrequency CommandDataPacket::getI2CClockFrequency(void){
        ClockFrequency clkf;
        return clkf;
    }

    void CommandDataPacket::setI2CClockFrequency(ClockFrequency frequency){

    }   
    
}