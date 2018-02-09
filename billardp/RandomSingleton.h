#pragma once
using namespace System;

ref class RandomSingleton : public Random
{
private:
	static RandomSingleton^ _hRandomSingleton = nullptr;
	RandomSingleton(int seed);
public:
	static RandomSingleton^ getRandomSingleton();
};

