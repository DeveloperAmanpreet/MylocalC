#include <vektor.h>

int init_vecktor(vektor& v, int size)
{
	v.elements = new int[size];
	if ( v.elements== nullptr)
	{
		return -1;//unable to create vektor
	}
	v.size = size;
	return 0;//successfull creation
}