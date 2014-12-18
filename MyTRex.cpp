#include "MyTRex.h"

 namespace TRexLib{

	MyTRex::MyTRex(I2C* i2c, int i2cAddress):TRex(i2c, i2cAddress)
	{
		
	}

	bool MyTRex::readStatus(StatusDataPacket * status)
	{
		return false;
	}

	bool MyTRex::writeCommand(CommandDataPacket * status)
	{
		return false;
	}


}
