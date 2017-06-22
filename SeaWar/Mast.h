#pragma once
#include "Coordinate.h"
class Mast
{
public:
	Mast();
	void setPosition(Coordinate pos)
	{ 
		position_ = pos; 
	}
	void setPosition(_TCHAR x, int y)
	{
		position_.setX(x);
		position_.setY(y);
	}
	Coordinate& getPosition();
	~Mast();

private:
	Coordinate	&position_;
	bool		isDestroyed_;
};

