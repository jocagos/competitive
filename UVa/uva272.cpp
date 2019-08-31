#include <stdio.h>

int main()
{
	int c;
	bool b = true;
	while((c = getchar()) != EOF)
	{
		if(c == '\"' and b){
			printf("``");
			b = !b;
		}
		else if(c == '\"' and !b){
			printf("''");
			b = !b;
		}
		else
			putchar(c);
	}
	return 0;
}
