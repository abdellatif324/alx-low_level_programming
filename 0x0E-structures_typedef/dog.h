#ifndef DOG_H
#define DOG_H

#include <stdio.h>
/**
 * struct dog -strucrtures
 * @name: name
 * @age: age
 * @owner: owner
 *
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};
/**
 * dog_t - typedef for struct dog
 */
void iinit_dog(struct dog *d, char *name, float age, char *owner);
#endif
