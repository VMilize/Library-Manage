#include <stdio.h>

typedef struct booklist {
	int id;
	char name[10];
}bkl;

static int number = 0;

int main_1()
{
	printf("%d", number);
	
	number++;
	printf("\n%d", number);
}

