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
        PWMFrequency PWM = PWMF_122HZ;
        return PWM;
    }
}