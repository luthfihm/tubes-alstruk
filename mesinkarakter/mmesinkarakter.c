#include "mesinkarakter.h"
#include "stdio.h"

int main()
{
	char input;
	
	START();
	
	printf("Error: %d\n", ERROR_MESINKAR);
	while ((!ERROR_MESINKAR) && (!EOP))
	{
		printf("%c", CC);
		ADV();
	}
	
	return 0;
	

}
