#include "Billard.h"


Billard::Billard()
{
	int largeur = 10;
	_les4Bandes.Add(gcnew BandeBillard(0, 0, Billard::TailleX, largeur, Color::Black));//--
	_les4Bandes.Add(gcnew BandeBillard(0, 0, largeur, Billard::TailleY, Color::Black));//|
	_les4Bandes.Add(gcnew BandeBillard(0, Billard::TailleY, Billard::TailleX+ largeur, largeur, Color::Black));//_
	_les4Bandes.Add(gcnew BandeBillard(Billard::TailleX, 0, largeur, Billard::TailleY+ largeur, Color::Black));//  |
	_threadBillard = gcnew Thread(gcnew ThreadStart(this, &Billard::fctThreadBillard));
	_threadBillard->Name = "ThreadBillard";
	_threadBillard->Start();

}

Billard::~Billard()
{
	_threadBillard->Abort();
}

void Billard::dessineBandes(Graphics ^ g)
{

	int largeur = 10;
	_les4Bandes[0]->reInit(Billard::StartX, Billard::StartY, Billard::TailleX, largeur);//--
	_les4Bandes[1]->reInit(Billard::StartX, Billard::StartY, largeur, Billard::TailleY);//|
	_les4Bandes[2]->reInit(Billard::StartX, Billard::StartY +Billard::TailleY, Billard::TailleX + largeur, largeur);//_
	_les4Bandes[3]->reInit(Billard::StartX+Billard::TailleX, Billard::StartY, largeur, Billard::TailleY + largeur);//  |
	for each (BandeBillard^ bandes in _les4Bandes)
	{
		bandes->dessine(g);
	}
}

void Billard::dessineBilles(Graphics ^ g)
{
	for (int i = 0; i < _lesBilles.Count; i++)
	{
		_lesBilles[i]->dessine(g);
	}
}

void Billard::ajouterBille()
{
	_lesBilles.Add(gcnew BilleBillard());
}

void Billard::setTaille(int x, int y)
{
	Billard::TailleX = x-50 - Billard::StartX;
	Billard::TailleY = y-50 - Billard::StartY;

}

void Billard::supprimeBille()
{
	_lesBilles.Clear();
}

int Billard::getNombreBille()
{
	return _lesBilles.Count;
}

void Billard::fctThreadBillard()
{
	while (true)
	{
		Thread::Sleep(10);
		for (int y = 0; y < _lesBilles.Count; y++)
		{
			if (_lesBilles[y]->doitEtreSupprimer())
			{
				_lesBilles.RemoveAt(y);
			}
			else
			{
				_lesBilles[y]->bouge();

				for (int i = 0; i < _les4Bandes.Count;i++)
				{
					_les4Bandes[i]->interagitBille(_lesBilles[y]);
				}

				for (int i = 0; i < _lesBilles.Count; i++)
				{
					if (_lesBilles[i]->collisionBille(_lesBilles[y]))
					{
						_lesBilles[y]->rebondit();
						break;
					}

				}
			}


		}
	}
}