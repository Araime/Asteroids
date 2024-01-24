#include "../header/Math.h"

bool IsCollide(Entity* first_obj, Entity* second_obj)
{
	return (second_obj->xcor - first_obj->xcor) * (second_obj->xcor - first_obj->xcor) + //
		(second_obj->ycor - first_obj->ycor) * (second_obj->ycor - first_obj->ycor) <	 //
		(first_obj->rad + second_obj->rad) * (first_obj->rad + second_obj->rad);
};