#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str = NULL;
	char *str2 = "I have an underlying issue here.";

	str = calloc(BUFFER_SIZE, sizeof(char));

	str = strchr(str2, 'y');
	printf("%c\n", *str);
	return (0);
}