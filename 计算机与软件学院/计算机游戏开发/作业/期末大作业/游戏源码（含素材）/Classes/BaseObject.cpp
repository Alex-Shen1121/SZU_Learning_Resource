#include "BaseObject.h"

bool BaseObject::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	return true;
}
