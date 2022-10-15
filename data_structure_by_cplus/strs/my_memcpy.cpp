// memcpy2
#include <bits/stdc++.h>

using namespace std;

void* memcpy(void* dest,const void* src,size_t length)
{
	assert(dest != NULL);
	assert(src != NULL);
	void* tmp = dest;
	if ((dest <= src) || ((char*)dest >= (char*)src + length))
	{
		while (length--)
		{
			*(char*)dest = *(char*)src;
			((char*)dest)++;
			((char*)src)++;
		}
	}
	else
	{
		while (length > 0)
		{
			*((char*)dest + length - 1) = *((char*)src + length - 1);
			length--;
		}
	}
	return tmp;
}
