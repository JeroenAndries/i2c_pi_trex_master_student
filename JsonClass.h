#include <string>
#include <sstream>

#ifndef Json_Class_H
#define Json_Class_H

using namespace std;

namespace TRexLib{

class JsonClass{	
public:
	/*Voor elke soort waarde een andere functie om 
	naar JSON-members om te zetten.*/
	string intValue(string key, int value );

	string charValue(string key, char value );

	string doubleValue(string key, double value );

	/*Wordt in dit geval nog niet gebruikt aangezien er nog geen
	commando's naar byte-sequenties worden omgezet.*/
	void fromJSON();
};

}

#endif