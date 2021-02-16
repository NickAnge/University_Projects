/* PURPOSE: MINESWEEPER */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EASY 6
#define MEDIUM 12
#define EXPERT 24

/* Global variables */
char game[24][24], displayed[24][24];
int SIZE;

/* DHLWSH SUNARTHSEWN */
void full_board(int x); /*Init method of board game and display*/
int check_win(int b);
void end_of_the_game(int y);
void play_game(int w);

int main(int argc, char *argv[])
{
	char difficulty;
	int i, j, k;
	char Answer;
	int c_selection;
	int r_selection;

	do
	{
		srand(time(NULL));
		do
		{ /* Choice of difficulty */
			printf("    1. EASY (E,e)\n");
			printf("    2. MEDIUM (M,m)\n");
			printf("    3. EXPERT (X,x)\n");
			printf("Choose difficulty level: ");
			scanf(" %c", &difficulty);

			switch (difficulty)
			{
			case 'E':
			case 'e':
			{
				SIZE = EASY;
				break;
			}
			case 'M':
			case 'm':
			{
				SIZE = MEDIUM;
				break;
			}
			case 'X':
			case 'x':
			{
				SIZE = EXPERT;
				break;
			}
			default:
			{
				printf("Invalid selection\n");
			}
			}
		} while (difficulty != 'E' && difficulty != 'e' && difficulty != 'M' && difficulty != 'm' && difficulty != 'X' && difficulty != 'x');

		printf("\t");
		for (j = 1; j <= SIZE; j++)
		{
			printf(" ");
			printf("%d", j);
			printf("\t");
		}
		printf("\n");
		printf("\n");

		for (i = 0, k = 1; i < SIZE; i++, k++)
		{
			printf("%d", k);
			printf("\t");
			for (j = 0; j < SIZE; j++)
			{
				printf(" ");
				printf("-");
				printf("\t");
			}
			printf("\n");
		}

		full_board(SIZE);

		do
		{
			do
			{
				printf("Row>");
				scanf("%d", &r_selection);
				printf("Col>");
				scanf("%d", &c_selection);

				if (r_selection < 0 || r_selection > SIZE)
				{
					printf("Invalid %d.Try again!\n", r_selection);
					continue;
				}
				else if (c_selection < 1 || c_selection > SIZE)
				{
					printf("Invalid %d.Try again!\n", c_selection);
					continue;
				}
			} while ((r_selection < 0 || r_selection > SIZE) || (c_selection < 1 || c_selection > SIZE));

			if (r_selection == 0)
			{
				printf("You selected to interrupt the current puzzle!\n");
				break;
			}
			if (game[r_selection - 1][c_selection - 1] == '*')
			{
				printf("Oops you have selected a mine\n");
				printf("\n");
				end_of_the_game(SIZE);
				printf("\n");
				printf("\n");
				break;
			}
			else if (displayed[r_selection - 1][c_selection - 1] == '0')
			{
				displayed[r_selection - 1][c_selection - 1] = '1';
				play_game(SIZE);
			}
			else if (displayed[r_selection - 1][c_selection - 1] == '1')
			{
				play_game(SIZE);
			}
		} while (check_win(SIZE) == -1);

		if (check_win(SIZE) == 1)
		{
			printf("Congratulations you have solved the puzzle!\n");
			printf("\n");
			end_of_the_game(SIZE);
			printf("\n");
			printf("\n");
		}
		do
		{
			printf("Play again? (y/n)\n");
			scanf(" %c", &Answer);
		} while ((Answer != 'y' && Answer != 'Y') && (Answer != 'n' && Answer != 'N'));

	} while (Answer == 'y' || Answer == 'Y');

	return 0;
}
void full_board(int x)
{
	int i;
	int j, k;
	int max_bombs = (20 * x * x) / 100;
	char nearby_bomb = '0';

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < x; j++)
		{
			game[i][j] = '-';
			displayed[i][j] = '0';
		}
	}
	for (i = rand() % (x + 1), j = rand() % (x + 1), k = 0; k < max_bombs; k++)
	{
		if (game[i][j] == '-')
		{
			game[i][j] = '*';
		}
		else
		{
			while (game[i][j] != '-')
			{
				i = rand() % (x + 1);
				j = rand() % (x + 1);
			}
			game[i][j] = '*';
		}
		i = rand() % (x + 1);
		j = rand() % (x + 1);
	}

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < x; j++)
		{
			if (game[i][j] == '*')
			{
				continue;
			}
			if ((i > 0 && i < x - 1) && (j > 0 && j < x - 1))
			{
				if (game[i][j + 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i + 1][j] == '*')
				{
					nearby_bomb++;
				}
				if (game[i + 1][j + 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i + 1][j - 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i][j - 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i - 1][j] == '*')
				{
					nearby_bomb++;
				}
				if (game[i - 1][j - 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i - 1][j + 1] == '*')
				{
					nearby_bomb++;
				}
				game[i][j] = nearby_bomb;
				nearby_bomb = '0';
			}
			else if (i == 0 && (j > 0 && j < x - 1))
			{
				if (game[i][j - 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i + 1][j - 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i + 1][j] == '*')
				{
					nearby_bomb++;
				}
				if (game[i + 1][j + 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i][j + 1] == '*')
				{
					nearby_bomb++;
				}
				game[i][j] = nearby_bomb;
				nearby_bomb = '0';
			}
			else if (i == x - 1 && (j > 0 && j < x - 1))
			{
				if (game[i][j - 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i][j + 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i - 1][j - 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i - 1][j] == '*')
				{
					nearby_bomb++;
				}
				if (game[i - 1][j + 1] == '*')
				{
					nearby_bomb++;
				}
				game[i][j] = nearby_bomb;
				nearby_bomb = '0';
			}
			else if ((i > 0 && i < x - 1) && j == 0)
			{
				if (game[i - 1][j] == '*')
				{
					nearby_bomb++;
				}
				if (game[i - 1][j + 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i][j + 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i + 1][j + 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i + 1][j] == '*')
				{
					nearby_bomb++;
				}
				game[i][j] = nearby_bomb;
				nearby_bomb = '0';
			}
			else if ((i > 0 && i < x - 1) && j == x - 1)
			{
				if (game[i - 1][j] == '*')
				{
					nearby_bomb++;
				}
				if (game[i - 1][j - 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i][j - 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i + 1][j - 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i + 1][j] == '*')
				{
					nearby_bomb++;
				}
				game[i][j] = nearby_bomb;
				nearby_bomb = '0';
			}
			else if (i == 0 && j == 0)
			{
				if (game[i][j + 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i + 1][j + 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i + 1][j] == '*')
				{
					nearby_bomb++;
				}
				game[i][j] = nearby_bomb;
				nearby_bomb = '0';
			}
			else if (i == x - 1 && j == 0)
			{
				if (game[i - 1][j] == '*')
				{
					nearby_bomb++;
				}
				if (game[i - 1][j + 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i][j + 1] == '*')
				{
					nearby_bomb++;
				}
				game[i][j] = nearby_bomb;
				nearby_bomb = '0';
			}
			else if (i == 0 && j == x - 1)
			{
				if (game[i][j - 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i + 1][j - 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i + 1][j] == '*')
				{
					nearby_bomb++;
				}
				game[i][j] = nearby_bomb;
				nearby_bomb = '0';
			}
			else if (i == x - 1 && j == x - 1)
			{
				if (game[i][j - 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i - 1][j - 1] == '*')
				{
					nearby_bomb++;
				}
				if (game[i - 1][j] == '*')
				{
					nearby_bomb++;
				}
				game[i][j] = nearby_bomb;
				nearby_bomb = '0';
			}
		}
	}
}

int check_win(int b)
{
	int i, j;
	int max_bombs = (20 * b * b) / 100;
	int nub_bombs;

	nub_bombs = 0;
	for (i = 0; i < b; i++)
	{
		for (j = 0; j < b; j++)
		{
			if (displayed[i][j] == '0')
			{
				nub_bombs++;
			}
			else
			{
				continue;
			}
		}
	}

	if (nub_bombs == max_bombs)
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}
void end_of_the_game(int y)
{
	int i, j;
	int k;

	printf("\t");

	for (j = 1; j <= y; j++)
	{
		printf(" ");
		printf("%d", j);
		printf("\t");
	}
	printf("\n");
	printf("\n");

	for (i = 0, k = 1; i < y; i++, k++)
	{
		printf("%d", k);
		printf("\t");
		for (j = 0; j < y; j++)
		{
			printf(" %c", game[i][j]);
			printf("\t");
		}
		printf("\n");
	}
}
void play_game(int w)
{
	int i, j, k;

	printf("\t");
	for (j = 1; j <= w; j++)
	{
		printf(" ");
		printf("%d", j);
		printf("\t");
	}
	printf("\n");
	printf("\n");

	for (i = 0, k = 1; i < w; i++, k++)
	{
		printf("%d", k);
		printf("\t");
		for (j = 0; j < w; j++)
		{
			if (displayed[i][j] == '0')
			{
				printf(" ");
				printf("-");
				printf("\t");
			}
			else
			{
				printf(" %c", game[i][j]);
				printf("\t");
			}
		}
		printf("\n");
	}
}
