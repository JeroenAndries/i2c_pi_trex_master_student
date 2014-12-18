#include <string>
#include <sstream>

#ifndef Json_Class_H
#define Json_Class_H

using namespace std;

namespace TRexLib{

class JsonClass{
public:
	string intValue(string key, int value );

	string charValue(string key, char value );

	string doubleValue(string key, double value );

	void fromJSON();

	ostringstream convert;
};

}

#endif