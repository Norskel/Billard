#pragma once
#include "BilleBillard.h"
using namespace System;
using namespace System::Drawing;


ref class BilleBillard
{
private:
	int _centreX;
	int _centreY;
	int _rayon;
	int _vitX;
	int _vitY;
	Rectangle _rect;
	Color _couleur;

public:
	BilleBillard();
	Rectangle getRect();
	void changeColor();
	void changeDirection(char c);
	void bouge();
	void rebondit();
	void dessine(Graphics^ g);
	//collisionBille(BilleBillard^ b);
};

