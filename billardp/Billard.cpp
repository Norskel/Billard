#include "Billard.h"



//Thread Billard::fctThreadBillard()
//{
//	return Thread();
//}
//
Billard::Billard()
{

}

void Billard::dessineBandes(Graphics ^ g)
{
	for each (BandeBillard^ bandes in _les4Bandes)
	{
		bandes->dessine(g);
	}
}

void Billard::dessineBilles(Graphics ^ g)
{
	throw gcnew System::NotImplementedException();
}

void Billard::ajouterBille()
{
	throw gcnew System::NotImplementedException();
}
