	#include "JsonClass.h"

	namespace TRexLib{
		
		string JsonClass::intValue(string key, int value )
		{
			/*voorlopige private stream-member om intwaarde naar string om te zetten*/
			ostringstream convert;
			convert << value;
			return "\""+key+"\"" + "\""+convert.str()+"\"";
		}

		string JsonClass::charValue(string key, char value )
		{
			return "\""+key+"\"" + "\""+value+"\"";
		}

		string JsonClass::doubleValue(string key, double value )
		{
			/*voorlopige private stream-member om doublewaarde naar string om te zetten*/
			ostringstream convert;
			convert << value;
			return "\""+key+"\"" + "\""+convert.str()+"\"";
		}
	}