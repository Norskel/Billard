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
	if (_rect.Width < _rect.Height)
	{
		b->changeDirection('x');
	}
	else
	{
		b->changeDirection('y');
	}
}
