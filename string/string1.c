#include <string.h>
#include <stdio.h>
int main ()
{
	size_t read;
	char *string;
	size_t size;
	printf("please enter a string\n");

	read = getline(&string, &size, stdin);
	if(read == -1)
	{
		puts("error");
	} 
	else{
		puts("you entered the string:");
		puts(string);
		printf("the length of string is %ld", strlen(string));
	
	}
	return 0;
}
