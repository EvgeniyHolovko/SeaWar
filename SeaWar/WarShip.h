#pragma once
#include "Rectangle.h"
#include <list>
#include "Mast.h"
using namespace std;

class WarShip
{
public:
	WarShip();
	virtual Rectangle& getRect() = 0;
	virtual Rectangle& getAroundRect() = 0;
	virtual ~WarShip();


};

