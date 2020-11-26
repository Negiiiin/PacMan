
// Negin Baghbanzadeh
//810196599

#include"Pacman.h"
#define R 8 // shoae pacman
#define w 6 // shoae roh
#define t 9 // tole har khone jadval
#define s 6 // tedade soton ha
#define r 5 // tedade radif ha
#define c 3 // shoae koloche ha

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int waitAndGetDirection(int waitTime, char *direction)
{
	DWORD start_time, check_time;

	start_time = GetTickCount();
	check_time = start_time + waitTime; //GetTickTime returns time in miliseconds
	char ch = 0;
	char hit = 0;

	while (check_time>GetTickCount())
	{
		if (_kbhit())
		{
			hit = 1;
			ch = _getch();
			if (ch == 0)
				ch = _getch();
			break;
		}
	}

	switch (ch)
	{
	case 'w':
		ch = 'w';
		break;
	case 'z':
		ch = 'z';
		break;
	case 'a':
		ch = 'a';
		break;
	case 's':
		ch = 's';
		break;
	default:
		break;
	}

	if (ch != *direction && (ch == 'w' || ch == 'z' || ch == 'a' || ch == 's'))
	{
		*direction = ch;
		return 1;
	}
	else
		return 0;

}


// in tabe baraye keshidane yek dayere kamel ast
void FULL_Circle(int x, int y)
{
	gotoxy(x, y);

	for (int i = -R; i < R; i += 2) /*keshidane dayereye packman*/

	{
		for (int j = -R; j < R; j++) /*keshidane dayereye packman*/
		{
			if (i*i + j*j < R*(R - 2)) /*sharte dayere shodan*/
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		gotoxy(x, y++);
	}
}

void initScreen()
{
	COORD coord;
	HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleDisplayMode(stdHandle, CONSOLE_FULLSCREEN_MODE, &coord);

}


// int tabe dar har khane jadval yek moraba ba space chap mikonad va mohtaviyate ghabli khane ra pak mikonad
void clear_cell(int x, int y)
{
	gotoxy(x, y);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			printf(" ");
		}
		printf("\n");
		gotoxy(x, y + i);
	}
}


// in tabe dar har khane koloche chap mikonad (baraye zamani ke yek roh az khanee rad shode va emtiyaze an khane hanoz gerefte nashode bod)
void clear_cell_Ghost(int x, int y)
{
	gotoxy(x, y);
	for (int i = -c; i < c; i += 2)

	{
		for (int j = -c; j < c; j++)
		{
			if (i*i + j*j < c*(c - 2))
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		gotoxy(x, y++);
	}
}


// in tabe yek pacman ba zaviye dahan haye mokhtalef dar khanee ke pacman bayad chap shavad mikeshad(pacman sabet ast)
void Draw_Pacman( int x, int y, float mouth_degree , char direction)
{
	switch (direction)
	{
	case 'z':
		if (mouth_degree == 60)
		{
			mouth_degree = sqrt(3.0) / 3;
		}
		if (mouth_degree == 90)
		{
			mouth_degree = 1;
		}
		if (mouth_degree == 120)
		{
			mouth_degree = sqrt(3.0);
		}

		gotoxy(x, y);

		for (int i = -R; i < R; i += 2) /*keshidane dayereye packman*/

		{
			for (int j = -R; j < R; j++) /*keshidane dayereye packman*/
			{
				if (i*i + j*j < R*(R - 2)) /*sharte dayere shodan*/
				{
					if (-j <= mouth_degree*i && j <= mouth_degree*i) /*sharti ke on ghesmat az dahane packman ro khali kone */
					{
						printf(" ");
					}
					else
					{
						printf("#");
					}
				}
				else
				{
					printf(" ");
				}
				
			}
			gotoxy(x, y++);
		}
		break;

	case 'w':
		if (mouth_degree == 60)
		{
			mouth_degree = sqrt(3.0) / 3;
		}
		if (mouth_degree == 90)
		{
			mouth_degree = 1;
		}
		if (mouth_degree == 120)
		{
			mouth_degree = sqrt(3.0);
		}

		gotoxy(x, y);

		for (int i = -R; i < R; i += 2) /*keshidane dayereye packman*/

		{
			for (int j = -R; j < R; j++) /*keshidane dayereye packman*/
			{
				if (i*i + j*j < R*(R - 2)) /*sharte dayere shodan*/
				{
					if (-j < mouth_degree*i || j < mouth_degree*i) /*sharti ke on ghesmat az dahane packman ro khali kone */
					{
						printf("#");
					}
					else
					{
						printf(" ");
					}
				}
				else
				{
					printf(" ");
				}

			}
			gotoxy(x, y++);
		}
		break;

	case 'a':
		if (mouth_degree == 120)
		{
			mouth_degree = sqrt(3.0) / 3;
		}
		if (mouth_degree == 90)
		{
			mouth_degree = 1;
		}
		if (mouth_degree == 60)
		{
			mouth_degree = sqrt(3.0);
		}

		gotoxy(x, y);

		for (int i = -R; i < R; i += 2) /*keshidane dayereye packman*/

		{
			for (int j = -R; j < R; j++) /*keshidane dayereye packman*/
			{
				if (i*i + j*j < R*(R - 2)) /*sharte dayere shodan*/
				{
					if (j >= mouth_degree*-i || j >= mouth_degree*i) /*sharti ke on ghesmat az dahane packman ro khali kone */
					{
						printf("#");
					}
					else
					{
						printf(" ");
					}
				}
				else
				{
					printf(" ");
				}
			}
			gotoxy(x, y++);
		}
		break;

	case 's':
		/* moshakhas kadan zarib mehvar ha baraye dahane packman*/
		if (mouth_degree == 120)
		{
			mouth_degree = sqrt(3.0) / 3;
		}
		if (mouth_degree == 90)
		{
			mouth_degree = 1;
		}
		if (mouth_degree == 60)
		{
			mouth_degree  = sqrt(3.0);
		}

		gotoxy(x, y);

		for (int i = -R; i < R; i += 2) /*keshidane dayereye packman*/
		{

			for (int j = -R; j < R; j++) /*keshidane dayereye packman*/
			{
				if (i*i + j*j < R*(R - 2)) /*sharte dayere shodan*/
				{
					if (j <= mouth_degree*-i || j <= mouth_degree*i) /*sharti ke on ghesmat az dahane packman ro khali kone */
					{

						printf("#");
					}
					else
					{
						printf(" ");
					}
				}

				else
				{
					printf(" ");
				}
			}
			gotoxy(x, y++);
		}
	default:
		break;
	}
}

// in tabe yek pacman ba zaviye dahan haye mokhtalef mikeshad(pacman moteharek ast)
void drawOpeningMouthPacman(int x, int y, char *direction, int p, int q, int u, int z)
{
	/*taarife moteghayer hayi ke be an ha dar tabe niyaz darim*/
	int* a = &x;
	int* b = &y;
	int* n = &p;
	int* m = &q;
	int* e = &u;
	int* f = &z;
	int q_0, q_1, q_2, q_3, q_4, q_5, q_6;  // baraye in ke bebinim jahate harekat taghir karde ya na
	int flag[6][5];   // baraye emtiyaz dehi

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			flag[i][j] = 0;
		}
	}
	int o = 0;
	while (true)  // baraye in ke pacman hamishe ta vaghti ke bemirad harekat konad
	{
		Draw_Ghost(p, q);         // keshidane roh 1
		Draw_Ghost(u, z);         // keshidane roh 2
		
		//agar mokhtasateyeki az roh ha va pacman yeki bod game over mishavad
		if ((x == p && y == q) || (x == u && y == z))
		{
			gotoxy(140, 12);
			printf("GAME OVER");
			gotoxy(140, 14);
			break;
		}

		//keshidane zaviye haye mokhtalefe pacman
		FULL_Circle(x, y);
		q_0 = waitAndGetDirection(50, direction);
		clear_cell(x, y);

		Draw_Pacman(x, y, 60, *direction);
		q_1 = waitAndGetDirection(50, direction);
		clear_cell(x, y);

		Draw_Pacman(x, y, 90, *direction);
		q_2 = waitAndGetDirection(50, direction);
		clear_cell(x, y);

		Draw_Pacman(x, y, 120, *direction);
		q_3 = waitAndGetDirection(50, direction);
		clear_cell(x, y);

		Draw_Pacman(x, y, 90, *direction);
		q_4 = waitAndGetDirection(50, direction);
		clear_cell(x, y);

		Draw_Pacman(x, y, 60, *direction);
		q_5 = waitAndGetDirection(50, direction);
		clear_cell(x, y);

		FULL_Circle(x, y);
		q_6 = waitAndGetDirection(100, direction);

		// aghar yeki az tabe haye waitAndGetDirection vorodi jadid gerefte baodand varede in shart mishavad
		if (q_0 == 1 || q_1 == 1 || q_2 == 1 || q_3 == 1 || q_5 == 0 || q_6 == 1)
		{
			// mokhtasate i va j roh ha baraye in ke bebinim aghar emtiyaze khaneyi gerefte shode bod dar an khane baad az raftane roh az an koloche chap nashavad.
			int i_1 = (p - 2) / 19;    
			int j_1 = (q - 1) / 9;

			int i_2 = (u - 2) / 19;
			int j_2 = (z - 1) / 9;

			// mokhtasate i va j pacman baraye mohasebe emtiyaz
			int i = (x - 2) / 19;
			int j = (y - 1) / 9;

			clear_cell(x, y); // mokhtasate ghabli pacman ra pak mikonad
			int d = setNextLocation(a, b, *direction, p, q, u, z); // mokhtasate badi pacman ra peyda mikonad
			if (d == 1) // aghar ba rohe 1 barkhord kar game over shavad
			{
				gotoxy(140, 12);
				printf("GAME OVER");
				gotoxy(140, 14);
				break;
			}
			if (d == 2)  // aghar ba rohe 2 barkhord kar game over shavad
			{
				gotoxy(140, 12);
				printf("GAME OVER");
				gotoxy(140, 14);
				break;
			}
			else if (d == 0) // aghar ba hich kodam barkhord nakard
			{
				int i = (x - 2) / 19;
				int j = (y - 1) / 9;

				// kane hayi ke bayad koloche chap shavad ( on 3 va 5 ha baraye ine ke vasate khone chap beshe )
				int l = p + 5;
				int k = q + 3;
				int l_1 = u + 5;
				int k_1 = z + 3;

				// aghe emtiyaz gherefte bod faghat pak she aghe na koloche chap beshe
				if (flag[i_1][j_1] == 1)
				{
					clear_cell(p, q);
				}
				else {
					clear_cell(p, q);
					clear_cell_Ghost(l, k);
				}

				setNextLocationGhost(a, b, n, m); // mokhtasate badi rohe 1

				if (flag[i_2][j_2] == 1)
				{
					clear_cell(u, z);
				}
				else {
					clear_cell(u, z);
					clear_cell_Ghost(l_1, k_1);
				}

				setNextLocationGhost(a, b, e, f);  // mokhtasate badi rohe 2
				if (u == p && q == z) 
					
					/* aghe 2 ta roh ro ham oftadan baraye in ke ta akhar bazi ro ham nabashand va faghat yek roh namayesh dade nashavad
					mokhtasate yeki az roh ha ba tavaghoh be divar nabodan avaz mishavad.*/
				{
			if ((u == 78 && z == 1) || (u == 40 && z == 10) || (u == 59 && z == 19) || (u == 78 && z == 28) || (u == 2 && z == 19) || (u == 21 && z == 28))
					{
						if (u < 97)
							u += 19;
					}
				}
			if ((u == 78 && z == 10) || (u == 40 && z == 19) || (u == 59 && z == 28) || (u == 78 && z == 37) || (u == 2 && z == 28) || (u == 21 && z == 37))
				{
					if (z < 37)
						z += 9;
				}
			}
			if ((u == 78 && z == 1) || (u == 59 && z == 19) || (u == 40 && z == 10) || (u == 78 && z == 28) || (u == 2 && z == 19) || (u == 21 && z == 28) || (u == 97 && z == 37))
			{
				if (z > 1)
					z -= 9;
			}
			if ((u == 78 && z == 10) || (u == 40 && z == 19) || (u == 59 && z == 28) || (u == 78 && z == 37) || (u == 2 && z == 28) || (u == 10 && z == 19) || (u == 59 && z == 1) || (u == 21 && z == 10))
			{
				if (u > 2)
					u -= 19;
			}


			// mohasebe emtiyaz be tori ke pacman dar har khaneyi ke raft aghar meghdare an 0 bod, 1 shavad va be emtiyaz ("o") yek vahed ezafe shavad
			if (flag[i][j] == 0)
			{
				flag[i][j] = 1;
				o++;
			}
			gotoxy(140, 10);
			printf("YOUR SCORE IS: %d", o); // printe emtiyaz
			gotoxy(140, 11);
			gotoxy(x, y);
		}
	}
}


// in tabe jadval ra rasm mikonad
void draw_Table()
{
	int x = 0, y = 1;

	for (int i = 0; i < (2 * t*s) + s + 1; i++) /*halghe baraye chape avalin khate "-"  */
	{
		printf("-");
	}
	gotoxy(x, y);
	for (int i = 0; i < t*r ; i++)
	{
		printf("|");
		y++;
		gotoxy(x, y);
	}
	
	x = 0, y = (s - 1)*t;
	gotoxy(x, y);
	for (int i = 0; i < (2 * t*s) + s + 1; i++) /*halghe baraye chape avalin khate "-"  */
	{
		printf("-");
	}

	x = (2 * t*s) + s, y = 1;
	gotoxy(x, y);
	for (int i = 0; i < t*r-1; i++)
	{
		printf("|");
		y++;
		gotoxy(x, y);
	}

	x = (4 * 18) + 5;
	y = 1;
	gotoxy(x, y);
	for (int i = 0; i < t -1 ; i++)
	{
		printf("|");
		y++;
		gotoxy(x, y);
	}

	x = (4 * 18) + 5;
	y = 9;
	gotoxy(x, y);
	for (int i = 0; i < (2 * t) +2; i++) /*halghe baraye chape avalin khate "-"  */
	{
		printf("-");
	}

	x = (5 * 18) + 6;
	y = 10;
	gotoxy(x, y);
	for (int i = 0; i < t - 1; i++)
	{
		printf("|");
		y++;
		gotoxy(x, y);
	}

	x = (2 * 18) + 3;
	y = 10;
	gotoxy(x, y);
	for (int i = 0; i < t - 1; i++)
	{
		printf("|");
		y++;
		gotoxy(x, y);
	}

	x = (2 * 18) + 3;
	y = 18;
	gotoxy(x, y);
	for (int i = 0; i < (2 * t) + 2; i++) /*halghe baraye chape avalin khate "-"  */
	{
		printf("-");
	}

	x = (3 * 18) + 4;
	y = 27;
	gotoxy(x, y);
	for (int i = 0; i < (2 * t) + 2; i++) /*halghe baraye chape avalin khate "-"  */
	{
		printf("-");
	}

	x = (3 * 18) + 4;
	y = 19;
	gotoxy(x, y);
	for (int i = 0; i < t - 1; i++)
	{
		printf("|");
		y++;
		gotoxy(x, y);
	}

	x = (4 * 18) + 5;
	y = 28;
	gotoxy(x, y);
	for (int i = 0; i < t - 1; i++)
	{
		printf("|");
		y++;
		gotoxy(x, y);
	}

	x = (4 * 18) + 5;
	y = 36;
	gotoxy(x, y);
	for (int i = 0; i < (2 * t) + 2; i++) /*halghe baraye chape avalin khate "-"  */
	{
		printf("-");
	}

	x = (5 * 18) + 6;
	y = 37;
	gotoxy(x, y);
	for (int i = 0; i < t - 1; i++)
	{
		printf("|");
		y++;
		gotoxy(x, y);
	}

	x = 1;
	y = 27;
	gotoxy(x, y);
	for (int i = 0; i < (2 * t) + 2; i++) /*halghe baraye chape avalin khate "-"  */
	{
		printf("-");
	}

	x = (1 * 18) + 2;
	y = 28;
	gotoxy(x, y);
	for (int i = 0; i < t - 1; i++)
	{
		printf("|");
		y++;
		gotoxy(x, y);
	}

	x = (1 * 18) + 2;
	y = 36;
	gotoxy(x, y);
	for (int i = 0; i < (2 * t) + 2; i++) /*halghe baraye chape avalin khate "-"  */
	{
		printf("-");
	}

	printf("\n");
}


// in tabe mokhtasate badi roh ra moshakhas mikonad
void setNextLocationGhost(int *x, int *y, int* a, int *b)
{
	if (*x - *a < 0 && *a > 2)     // aghar pacman nesbat be roh rast tar bod, roh yek khane be samte rast miravad
	{
		// faghat dar sorati roh be rast nemiravad ke dar samte raste an divar bashad. ke dar in soart be chap miravad. 
		// ( vaghti ghoftam rohe aghe samte rastesh divar bod bere samte chap taghriban yekam bistar harekat mikard)
		if ((*a == 78 && *b == 1) || (*a == 40 && *b == 10) || (*a == 59 && *b == 19) || (*a == 78 && *b == 28) || (*a == 2 && *b == 19) || (*a == 21 && *b == 28) || (*a == 97 && *b == 10) || (*a == 97 && *b == 37))
		{
			if (*a < 97)
			{
				*a += 19;
			}
		}
		else
		{

			*a -= 19;
		}
	}
	if (*x - *a > 0 && *a < 97)     // aghar pacman nesbat be roh chap tar bod, roh yek khane be samte chap miravad
	{
		// faghat dar sorati roh be chap nemiravad ke dar samte chape an divar bashad. ke dar in soart be rast miravad.
		if ((*a == 78 && *b == 10) || (*a == 40 && *b == 19) || (*a == 59 && *b == 28) || (*a == 78 && *b == 37) || (*a == 2 && *b == 28) || (*a == 10 && *b == 19) || (*a == 59 && *b == 1) || (*a == 21 && *b == 10))
		{
			if (*a > 2)
			{
				*a -= 19;
			}
		}
		else
		{
			*a += 19;
		}
	}
	if (*y - *b < 0 && *b > 1)         // aghar pacman nesbat be roh payin bod, roh yek khane payin miravad
	{
		// faghat dar sorati roh payin nemiravad ke dar payine an divar bashad. ke dar in soart bala miravad.
		if ((*a == 78 && *b == 10) || (*a == 40 && *b == 19) || (*b == 59 && *b == 28) || (*a == 78 && *b == 37) || (*a == 2 && *b == 28) || (*a == 21 && *b == 37))
		{
			if (*b < 37)
			{
				*b += 9;
			}
		}

		else
		{
			*b -= 9;
		}
	}
	if (*y - *b > 0 && *b < 37)         // aghar pacman nesbat be roh bala tar bod, roh yek khane bala miravad
	{
		// faghat dar sorati roh bala nemiravad ke dar balaye an divar bashad. ke dar in soart payin miravad.
		if ((*a == 78 && *b == 1) || (*a == 59 && *b == 19) || (*a == 40 && *b == 10) || (*a == 78 && *b == 28) || (*a == 2 && *b == 19) || (*a == 21 && *b == 28))
		{
			if (*b > 1)
			{
				*b -= 9;
			}
		}
		else
		{
			*b += 9;
		}
	}
}


// in tabe mokhtasate baadi ke pacman bayad be an ja beravd ra moshakas mikonad va agar mokhtasate kaneyi ke bayad miraft bamokhtasate 
// rohe 1 barabar bod adade 1 agar ba rohe 2 barabar bod adade 2 va agar bahich kodam barabar nabod adade 0 ra bar migardanad
int setNextLocation(int *x, int *y, char direction, int a, int b, int p, int q)
{
		switch (direction)
		{
		case 'w':
			if (*y != 1)
			{
				if ((*x == 78 && *y == 10) || (*x == 40 && *y == 19) || (*x == 59 && *y == 28) || (*x == 78 && *y == 37) || (*x == 2 && *y == 28) || (*x == 21 && *y == 37))
				{
// mokhtasate divar ha
				}
				else
				{
					*y -= 9;
					if (*y == b  && *x == a)
					{
						return 1;
					}
					if (*y == p && *x == q)
					{
						return 2;
					}
						return 0;
				}
			}
			break;
		case'z':
			if (*y != 37)
			{
					if ((*x == 78 && *y == 1) || (*x == 40 && *y == 10) || (*x == 59 && *y == 19) || (*x == 78 && *y == 28) || (*x == 2 && *y == 19) || (*x == 21 && *y == 28))
					{
						// mokhtasate divar ha
					}
					else
					{
						*y += 9;
						if (*y == b && *x == a)
						{
							return 1;
						}
						if (*y == p && *x == q)
						{
							return 2;
						}
							return 0;
					}
				}
			
			break;
		case'a':
			if (*x != 2)
			{

				if ((*x == 78 && *y == 1) || (*x == 40 && *y == 10) || (*x == 59 && *y == 19) || (*x == 78 && *y == 28) || (*x == 2 && *y == 19) || (*x == 21 && *y == 28) || (*x == 97 && *y == 10) || (*x == 97 && *y == 37))
				{
					// mokhtasate divar ha
				}
				else
				{
					*x -= 19;
					if (*y == b && *x == a)
					{
						return 1;
					}
					if (*y == p && *x == q)
					{
						return 2;
					}
					
						return 0;
				}
			}
			break;
		case's':
			if (*x != 97)
			{
				if ((*x == 78 && *y == 10) || (*x == 40 && *y == 19) || (*x == 59 && *y == 28) || (*x == 78 && *y == 37) || (*x == 2 && *y == 28) || (*x == 10 && *y == 19) || (*x == 59 && *y == 1) || (*x == 21 && *y == 10))
				{
					// mokhtasate divar ha
				}
				else
				{
					*x += 19;
					if (*y == b && *x == a)
					{
						return 1;
					}
					if (*y == p && *x == q)
					{
						return 2;
					}
					
					
						return 0;
				}
			}
			break;
		default:
			break;
		}

	}


	// in tabe dar hameye khane haye jadval koloche chap mikonad
void Print_Cookie()
{
	int x = 6;
	int a = 4;
	int y = a;
	
	gotoxy(x, y);
	for (int i; a != 49; a += 9)
	{
		for (int x = 6; x != 120; x += 19)
		{
			int y = a;
			for (int i = -c; i < c; i += 2)

			{
				for (int j = -c; j < c; j++)
				{
					if (i*i + j*j < c*(c - 2))
					{
						printf("*");
					}
					else
					{
						printf(" ");
					}
				}
				gotoxy(x, y++);
			}
		}
	}
	/*for (int i = -c; i < c; i += 2)

	{
		for (int j = -c; j < c; j++)
		{
			if (i*i + j*j < c*(c - 2))
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		gotoxy(x, y++);
	}

	int a = 4;
	gotoxy(x += 20, a);

	for (int i = -c; i < c; i += 2)

	{
		for (int j = -c; j < c; j++)
		{
			if (i*i + j*j < c*(c - 2))
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		gotoxy(x, a++);
	}*/
} 

// in tabe dar mokhtasate khaneyi ke be an dade shode roh rasm mikonad
void Draw_Ghost(int x, int y)
{
	gotoxy(x, y);

	for (int i = -R; i < R; i += 2) /*keshidane dayereye packman*/

	{
		for (int j = -w; j < w; j++) /*keshidane dayereye packman*/
		{
			if (i*i + j*j < w*(w - 2)) /*sharte dayere shodan*/
			{
				printf("^");
			}
			else
			{
				printf(" ");
			}
		}
		gotoxy(x, y++);
	}
}