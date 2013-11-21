#include "mystring.h"
#include "mesinbaris.h"

int main()
{
	STARTBARIS();
	
	while ((!EOD()) && (!ERROR_MESINBARIS))
	{
		ADVBARIS();
		if(!EOD())
		{
			printf("%s\n", BARIS);
		}
	}
	
	if (ERROR_MESINBARIS)
	{
		printf("ERROR: %d\n", ERROR_MESINBARIS);
	}
	
	return 0;
}
