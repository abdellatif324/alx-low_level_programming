#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * init_dog - that initialize a variable of type struct dog
 * @d: array
 * @name: name
 * @age: age
 * @owner: owner
 * Description: strict dog
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
