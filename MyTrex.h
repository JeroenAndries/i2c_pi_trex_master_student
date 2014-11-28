#include "I2C.h"
#include "Serial.h"
#include "StatusDataPacket.h"
#include "CommandDataPacket.h"

#ifndef TREX_H
#define TREX_H

namespace TRexLib{

      class MyTRex : public TRex{
        public:
            TRex(I2C* i2c, int i2cAddress);

            /*
             * Read the status of the TRex controller.
             *
             * @status pointer to the StatusDataPacket that contains the values read from the controller.
             *
             * @return true if the read action was successful
             */
            virtual bool readStatus(StatusDataPacket * status);

            /*
             * Write command to the TRex controller.
             *
             * @command pointer to the CommandDataPacket that contains the values that should be send to the controller.
             *
             * @return true if the write action was successful
             */
            virtual bool writeCommand(CommandDataPacket * command); 

        protected:
            /* The bus on which the slave is connected. */
            I2C* i2c;

            /* Slave address */
            int i2cAddress;
    };
}

#endif
