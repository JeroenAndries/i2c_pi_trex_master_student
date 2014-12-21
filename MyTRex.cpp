#include "MyTRex.h"

 namespace TRexLib{

	MyTRex::MyTRex(I2C* i2c, int i2cAddress):TRex(i2c, i2cAddress)
	{
		
	}

	bool MyTRex::readStatus(StatusDataPacket * status)
	{
		/*
		De opdracht was tot nu toe enkel de status uitlezen vanuit
		de main. Dit kan enkel gebeuren als deze functie true als
		teruggeefwaarde geeft. 
		*/
		return true;
	}

	bool MyTRex::writeCommand(CommandDataPacket * status)
	{
		return false;
	}


}
