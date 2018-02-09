#include "RandomSingleton.h"

RandomSingleton::RandomSingleton(int seed):Random(seed){}

RandomSingleton ^ RandomSingleton::getRandomSingleton()
{
	if (_hRandomSingleton == nullptr)
	{ 
		_hRandomSingleton = gcnew RandomSingleton(24535);
	}
	return _hRandomSingleton;
}
