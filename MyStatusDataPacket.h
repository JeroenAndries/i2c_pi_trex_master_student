#include <string>

#ifndef TREX_DATA_PACKET_H
#define TREX_DATA_PACKET_H

    enum StatusDataPacketFields {
        STATUS_START = 0,
        STATUS_ERROR = 1,
        STATUS_BATTERY_MSB = 2,
        STATUS_BATTERY_LSB = 3,
        STATUS_LEFT_MOTOR_CURRENT_MSB = 4,
        STATUS_LEFT_MOTOR_CURRENT_LSB = 5,
        STATUS_LEFT_ENCODER_COUNT_MSB = 6,
        STATUS_LEFT_ENCODER_COUNT_LSB = 7,
        STATUS_RIGHT_MOTOR_CURRENT_MSB = 8,
        STATUS_RIGHT_MOTOR_CURRENT_LSB = 9,
        STATUS_RIGHT_ENCODER_COUNT_MSB = 10,
        STATUS_RIGHT_ENCODER_COUNT_LSB = 11,
        STATUS_ACCELEROMETER_X_MSB = 12,
        STATUS_ACCELEROMETER_X_LSB = 13,
        STATUS_ACCELEROMETER_Y_MSB = 14,
        STATUS_ACCELEROMETER_Y_LSB = 15,
        STATUS_ACCELEROMETER_Z_MSB = 16,
        STATUS_ACCELEROMETER_Z_LSB = 17,
        STATUS_IMPACT_X_MSB = 18,
        STATUS_IMPACT_X_LSB = 19,
        STATUS_IMPACT_Y_MSB = 20,
        STATUS_IMPACT_Y_LSB = 21,
        STATUS_IMPACT_Z_MSB = 22,
        STATUS_IMPACT_Z_LSB = 23
    };

namespace TRexLib{

    class MyStatusDataPacket : public StatusDataPacket{
        public:
        	/*
        	 * Convert the internal values to a JSON string
        	 *
        	 * @return json string
        	 */
            virtual std::string toJSON(void);

            /*
             * Parse the json representation of the DataPacket
             * and set the internal values accordingly.
			 *
			 * @json json string representation
             */
            virtual void fromJSON(std::string json);

        	/*
        	 * Convert the internal values to a char buffer representation ready 
        	 * for writing to the TRex controller using I2C.
        	 *
        	 * @buffer buffer to which the values should be written (should be big enough for all values to fit)
        	 */
            virtual void toTRex(char * buffer);

            /*
             * Parse the TRex representation of the DataPacket
             * and set the internal values accordingly.
			 *
        	 * @buffer char buffer which contains the values that should be parsed
             */
            virtual void fromTRex(char * data);
    };
}

#endif
