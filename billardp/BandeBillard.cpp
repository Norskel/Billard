#include "BandeBillard.h"


BandeBillard::BandeBillard(int x, int y, int width, int height, Color c)
{
	_rect = Rectangle(x, y, width, height);
	_couleur = c;
}

void BandeBillard::dessine(Graphics ^ g)
{
	g->FillRectangle(gcnew SolidBrush(_couleur), _rect);
}

void BandeBillard::interagitBille(BilleBillard ^ b)
{
	
	if (_rect.Width < _rect.Height)// |
	{
		if (_rect.IntersectsWith(b->getRect()))
		{
			b->changeDirection('X');
		}

	}
	else // _
	{
		if (_rect.IntersectsWith(b->getRect()))
		{
			b->changeDirection('Y');
		}
	}
}

void BandeBillard::reInit(int x, int y, int width, int height)
{
	_rect = Rectangle(x, y, width, height);
}
