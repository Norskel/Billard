#pragma once
#include "BilleBillard.h"
#include "BandeBillard.h"

using namespace System;
using namespace System::Threading;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class Billard
{

private:
	List<BandeBillard^>_les4Bandes;
	//Thread _threadBillard;
	//void fctThreadBillard();
public:
	Billard();
	void dessineBandes(Graphics^ g);
	void dessineBilles(Graphics^ g);
	void ajouterBille();
	

};

