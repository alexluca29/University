#include "Artwork.h"
#include <assert.h>

void testsArtwork()
{
	Artwork a{ "asd","dsa",123 };
	assert("asd" == a.getName());
	assert("dsa" == a.getType());
	assert(123 == a.getPrice());
	a.toString();
}