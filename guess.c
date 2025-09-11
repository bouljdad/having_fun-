#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int	main(void)
{
	printf("######/ GUESS NUMBER GAME \\######\n");
	srand(time(NULL));
	int random_number = rand() % 100 + 1;
	int usr_gs;
	int i = 0;
	do
	{
		printf("\nGuess the number between 1 and 100(u have %d chanse left) : ", 10 - i);
		scanf("%d", &usr_gs);
		if (usr_gs > random_number)
			printf("\nthe number u give is biger !");
		else if (usr_gs < random_number)
			printf("\nthe number u give is smaller !");
		else 
		{
			printf("\nWell done u guessd the number in %dth try.", i);
			return 0;
		}
		i++;
	}while (i < 10 && usr_gs != random_number);
	printf("\nEmmm Are u stupid! u lose the game !");
	return 0;
}
