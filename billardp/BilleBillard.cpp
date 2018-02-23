#include "BilleBillard.h"

BilleBillard::BilleBillard()
{
	_myRandom = RandomSingleton::getRandomSingleton();
	int offset= 5;
	_centreX = _myRandom->Next(Billard::StartX + _rayon + offset, Billard::StartX + Billard::TailleX - _rayon - offset);
	_centreY = _myRandom->Next(Billard::StartY + _rayon + offset, Billard::StartY + Billard::TailleY - _rayon - offset);
	_couleur = Color::Red;
	_vitX = _myRandom->Next(-10, 10);
	_vitY = _myRandom->Next(-10, 10);
	_rect = Rectangle(Point(_centreX - _rayon, _centreY - _rayon), Size(_rayon * 2, _rayon * 2));
}

Rectangle BilleBillard::getRect()
{
	return _rect;
}

void BilleBillard::changeColor()
{
	_couleur = Color::FromArgb(_myRandom->Next(0, 255), _myRandom->Next(0, 255), _myRandom->Next(0, 255));
}

void BilleBillard::changeDirection(char c)
{
	if (c == 'X')
	{
		_vitX = _vitX*-1;
	}
	else
	{
		if (c == 'Y')
		{
			_vitY = _vitY*-1;
		}
	}
	_countCollision = 0;
}

void BilleBillard::bouge()
{
	_centreX += _vitX;
	_centreY += _vitY;
	_rect.X = _centreX - _rayon;
	_rect.Y = _centreY - _rayon;

}

void BilleBillard::rebondit()
{
	_vitX = _vitX*-1;
	_vitY = _vitY*-1;
	changeColor();
}

void BilleBillard::dessine(Graphics ^ g)
{
	Font^f = gcnew System::Drawing::Font("Arial", 16);
	g->FillEllipse(gcnew SolidBrush(_couleur), _rect);
	g->DrawString(Convert::ToString(_countCollision), f, Brushes::Black, _centreX-10, _centreY-12);
	


}

bool BilleBillard::collisionBille(BilleBillard ^ b)
{
	Console::WriteLine(_countCollision);
	if (this == b)
	{
		return false;
	}
	else
	{

		Rectangle r = b->getRect();

		int pa = 0;
		int pb = 0;
		if (_rect.X > r.X)
		{
			pa = _rect.X - r.X;
		}
		else
		{
			pa = r.X - _rect.X;
		}
		if (_rect.Y > r.Y)
		{
			pb = _rect.Y - r.Y;
		}
		else
		{
			pb = r.Y - _rect.Y;
		}
		if (sqrt(pow(pa,2)+pow(pb,2)) < 2*_rayon)
		{
			_countCollision++;
			return true;
		}
	}
	//_countCollision = 0;
	return false;
}

bool BilleBillard::doitEtreSupprimer()
{
	if (_centreX < Billard::StartX || _centreX > (Billard::StartX + Billard::TailleX))
	{
		return true;
	}

	if (_centreY < Billard::StartY || _centreY >(Billard::StartY + Billard::TailleY))
	{
		return true;
	}
	if (_countCollision > 10)
	{
		return true;
	}
	return false;
}
