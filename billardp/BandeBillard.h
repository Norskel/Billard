#pragma once
#include "BilleBillard.h"
using namespace System;
using namespace System::Drawing;

ref class BilleBillard;

ref class BandeBillard
{
private:
	Rectangle _rect;
	Color _couleur;
public:
	BandeBillard(int x,int y,int width,int height,Color c);
	void dessine(Graphics^ g);
	void interagitBille(BilleBillard^ b);
	void reInit(int x, int y, int width, int height);
};

