#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char board[6][6];
int r1, x1, r2, x2, x1p, y1p, x2p, y2p;
void
drawBoard ()
{
  int t;			                                                        // Draws the board of the game a 6x6 grid
  for (t = 0; t < 6; t++)
    {
      printf (" %c | %c | %c | %c | %c | %c ", board[t][0], board[t][1],
	      board[t][2], board[t][3], board[t][4], board[t][5]);
      if (t != 5)
	printf ("\n---|---|---|---|---|---\n");
    }
  printf ("\n");
}

void
initalize_board ()
{				                                                               // initializes all values in the 2d array
  int i, j;
  for (i = 0; i < 6; i++)
    {
      for (j = 0; j < 6; j++)
	{
	  board[i][j] = ' ';
	}
    }
}

void
Randomize ()
{
  printf ("First play is randomized for each player \n ");	                      // Randomizes first position for both player 1 & 2
  srand (time (NULL));
  r1 = rand () % 6;		                                                          //srand(time(Null)) generates pseudo numbers using the internal clock of the proccessor
  x1 = rand () % 6;
  board[r1][x1] = 'O';                                                            // rand()%6 generates random numbers within range of the 2d array
  printf ("\nFirst player randomized coordinates are %d %d \n", r1 + 1,x1 + 1);
  do
    {
      r2 = rand () % 6;		                                                      // do - while to make sure player 2 doesn't get the same value from rand as player 1
      x2 = rand () % 6;
    }
  while (board[r2][x2] != ' ');
  board[r2][x2] = 'X';
  printf ("\nSecond Player randomized coordinates are %d %d \n", r2 + 1,x2 + 1);
}

void
Player1 ()
{
  printf ("(Player 1) Enter X and Y coordinates for your move : ");	                            // Gets move from player 1 and checks if place is occupied
  do
    {
      scanf ("%d%d", &x1p, &y1p);
      if (x1p < 1 || x1p > 6 || y1p < 1 || y1p > 6)	                                            // checks if input is in the correct range (1-6)
	printf
	  ("Incorrect input number must be between 1 and 6, please try again\n");
    }
  while (x1p < 1 || x1p > 6 || y1p < 1 || y1p > 6);
  x1p--;
  y1p--;
  if (board[x1p][y1p] != ' ')
    {
      printf ("Place is already occupied please pick a different spot \n");	                    // checks if input positions are not empty, if they are not empty
      Player1 ();		                                                                        // player 1 function is called again to ask for another input
    }
int i, j;
  for (i = r1 - 1, j = x1 - 1; i <= r1 + 1, j <= x1 + 1; i++, j++)
    {				                                                                            // checks if input is close to previous input
      if (x1p == i || x1p == i + 1 || x1p == i + 2 && y1p == j || y1p == j + 1 || y1p == j + 2)
	{			                                                                                // by checking in a 3x3 grid close to the previous input
	  board[x1p][y1p] = 'O';
	  r1 = x1p;
	  x1 = y1p;
	  break;
	}
      else                                                                                      // Checks if input is close to previous input
	{
	  printf ("Invalid, input must be close to previous position\n");
	  Player1 ();
	}
    }
}
void
Player2 ()
{				                                                                    // Gets move from player 2
  printf ("(Player 2) Enter X and Y coordinates for your move : ");
  do
    {
      scanf ("%d%d", &x2p, &y2p);	                                                // do - while loop to keep asking for input if it is incorrect
      if (x2p < 1 || x2p > 6 || y2p < 1 || y2p > 6)	                                // checks if input is in the desired range (1-6)
	printf
	  ("Incorrect input number must be between 1 and 6, please try again\n");
    }
  while (x2p < 1 || x2p > 6 || y2p < 1 || y2p > 6);
  x2p--;
  y2p--;
  if (board[x2p][y2p] != ' ')
    {				                                                                // checks if input positions are not empty, if they are not empty
      printf ("Place is already occupied please pick a different spot \n");	        // player function is called again to ask for another input
      Player2 ();
    }
int i, j;
  for (i = r2 - 1, j = x2 - 1; i <= r2 + 1, j <= x2 + 1; i++, j++)
    {				                                                                // Same as the code in Player1 but checks for player 2
      if (x2p == i || x2p == i + 1 || x2p == i + 2 && y2p == j || y2p == j + 1 || y2p == j + 2)
	{
	  board[x2p][y2p] = 'X';
	  r2 = x2p;
	  x2 = y2p;                                                                       // checks if input is close to previous input
	  break;
	}
      else
	{
	  printf ("Invalid, input must be close to previous position\n");
	  Player2 ();
	}
    }
}

char
checkDraw ()
{
  int i, j;
  for (i = 0; i < 6; i++)
    {				                                                     // Condition to check if game ended in a draw
      for (j = 0; j < 6; j++)
	if (board[i][j] == ' ')
	  break;		                                                     // Loops on all elements in the 2d array, to check if there are any empty spaces
    }				                                                     // if there is any empty spaces it breaks out of the loop, if there are no empty spaces
  if (i * j == 36)
    {				                                                     // it multiplies value of i with the value of j (i*j) = (6*6) which means all spaces are occupied
      return 'D';		                                                 // and returns 'D'
    }
  return ' ';
}

char
checkWin ()
{				                                                                                 //Function to check if there's a winner
  int i;
  for (i = 0; i < 6; i++)
    {				                                                                            // Horizontal Check
      if (board[i][0] == board[i][1] && board[i][0] == board[i][2]
	  && board[i][0] == board[i][3] && board[i][0] == board[i][4]
	  && board[i][0] == board[i][5])
	return board[i][0];
    }
  for (i = 0; i < 6; i++)
    {				                                                                            //Vertical Check
      if (board[0][i] == board[1][i] && board[0][i] == board[2][i]
	  && board[0][i] == board[3][i] && board[0][i] == board[4][i]
	  && board[0][i] == board[5][i])
	return board[0][i];
    }
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]	//positive diagonal check
      && board[3][3] == board[4][4] && board[4][4] == board[5][5])
    return board[0][0];

  if (board[0][5] == board[1][4] && board[1][4] == board[2][3] && board[2][3] == board[3][2]	//negative diagonal check
      && board[3][2] == board[4][1] && board[4][1] == board[5][0])
    return board[0][5];
  return ' ';
}

int
main ()
{
  char done, start;
  system ("COLOR F");		                                                        // changes the color of the text to bright white
  printf
    ("\t--------------------Welcome to Connect 6, Press (Y) to start or (N) to quit--------------------\n");
  printf ("Press ENTER key to continue...");
  getchar ();			                                                            // getchar(); ignores \n input or enter
  scanf ("%c", &start);
  system ("cls");		                                                            // clears the output screen
  if (start == 'n' || start == 'N')
    {
      printf ("Maybe next time, goodbye!\n");
      return 0;
    }
  else if (start == 'y' || start == 'Y')
    {				                                                                // goes into do - while if input is y or Y
      do
	{
	  printf ("Player 1 is O & Player 2 is X \n\n");
	  done = ' ';
	  initalize_board ();
	  Randomize ();
	  do
	    {
	      drawBoard ();
	      Player1 ();
	      done = checkWin ();
	      if (done != ' ')
		break;
	      done = checkDraw ();
	      drawBoard ();
	      Player2 ();
	      done = checkWin ();
	      if (done != ' ')
		break;
	      done = checkDraw ();
	    }
	  while (done == ' ');
	  drawBoard ();
	  if (done == 'O')
	    {			                                                                        // gets character return from functions and checks if done
	      printf ("\t\t\t\tPlayer 1 Won! Good Game!\n");	                                // is equal to 'O' or 'X'
	    }
	  else if (done == 'X')
	    printf ("\t\t\tPlayer 2 Won! Good Game!\n");
	  else
	    printf ("\n\t\t\t\t\tGood Game!! It ended in a draw\n");
	  system ("PAUSE");	                                                                    // pauses the system/program and waits until users presses any key
	  system ("cls");
	  printf ("Do you want to play another game? press Y or N\n");	                        // prompt to ask user if he wants to play another game
	  getchar ();
	  scanf ("%c", &start);	                                                                // if input is equal to 'n' or 'N' the programs exits
	  if (start == 'n' || start == 'N')
	    {
	      printf ("Thank you for playing Connect 6!!\n");	                                // if input is y or Y the program restarts and a new game starts
	      return 0;
	    }
	}
      while (start == 'Y' || start == 'y');
    }
  return 0;
}
