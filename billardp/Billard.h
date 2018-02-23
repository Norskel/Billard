#pragma once
#include "BilleBillard.h"
#include "BandeBillard.h"

using namespace System;
using namespace System::Threading;
using namespace System::Drawing;
using namespace System::Collections::Generic;
ref class BandeBillard;
ref class BilleBillard;

ref class Billard
{

private:
	List<BandeBillard^>_les4Bandes;
	List<BilleBillard^>_lesBilles;

	Thread^ _threadBillard;
	void fctThreadBillard();
public:
	Billard();
	~Billard();

	void dessineBandes(Graphics^ g);
	void dessineBilles(Graphics^ g);
	void ajouterBille();
	void setTaille(int x, int y);
	void supprimeBille();

	int getNombreBille();

	static int TailleY = 300;
	static int TailleX = 520;
	static int StartX = 100;
	static int StartY = 0;
	

};

