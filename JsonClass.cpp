	#include "JsonClass.h"

	namespace TRexLib{
		
		string JsonClass::intValue(string key, int value )
		{
			convert << value;
			return "\""+key+"\"" + "\""+convert.str()+"\"";
		}

		string JsonClass::charValue(string key, char value )
		{
			return "\""+key+"\"" + "\""+value+"\"";
		}

		string JsonClass::doubleValue(string key, double value )
		{
			convert << value;
			return "\""+key+"\"" + "\""+convert.str()+"\"";
		}
	}