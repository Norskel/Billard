#pragma once
#include <math.h>
#include "BilleBillard.h"
#include "RandomSingleton.h"
#include "Billard.h"
using namespace System;
using namespace System::Drawing;


ref class BilleBillard
{
private:
	int _centreX;
	int _centreY;
	int _rayon = 20;
	int _vitX;
	int _vitY;
	int _countCollision = 0;
	Rectangle _rect;
	Color _couleur;
	RandomSingleton^ _myRandom;

public:
	BilleBillard();
	Rectangle getRect();
	void changeColor();
	void changeDirection(char c);
	void bouge();
	void rebondit();
	void dessine(Graphics^ g);
	bool collisionBille(BilleBillard^ b);
	bool doitEtreSupprimer();
};

