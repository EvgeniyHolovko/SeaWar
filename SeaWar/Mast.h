#pragma once
#include "Coordinate.h"
enum HitResponse{MISS, HIT, REPEATED, DEFEAT, DESTROYED, WRONG};

class Mast
{
public:
	Mast();

	Mast(Coordinate &coord);


	inline void setPosition(const Coordinate pos)
	{ 
		position = pos; 
	}

	inline void setPosition(const _TCHAR x, const int y)
	{
		position.setX(x);
		position.setY(y);
	}

	bool isDestroyed() const;
	void setDestroyed(const bool destroyed);

	Coordinate& getPosition();
	~Mast();

private:
	Coordinate &position;
	bool destroyed;
};

