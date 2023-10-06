// NxN tic-tac-toes
#include <iostream>
#include <cstdlib>
using namespace std;
char getEntryAtRC(char grid[], int dim, int r, int c);


int idxToRow(int idx, int dim);

int idxToCol(int idx, int dim);

void printTTT(char grid[], int dim);

int checkForWinner(char grid[], int dim);

bool checkForDraw(char grid[], int dim);

bool getAiChoiceAndUpdateGrid(char grid[], int dim, char player);

bool getRandChoiceAndUpdateGrid(char grid[], int dim, char player);

char getEntryAtRC(char grid[], int dim, int r, int c)
{
    return grid[dim * r + c];
}

int idxToRow(int idx, int dim)
{
    return idx / dim;
}

int idxToCol(int idx, int dim)
{
    return idx % dim;
}

void printTTT(char grid[], int dim)
{
  for(int i = 0; i < dim; i++)
  {
    for (int j = 0; j < dim; j++)
    {
      cout << " " << getEntryAtRC(grid, dim, i, j) << " "; //prints indexes 0-dim
      if (j < dim - 1)
      {
        cout << "|";
      }
    }
    if (i < dim - 1) // printing horizontal grid lines
    { cout << endl;
        for(int k = 0; k < dim; k++)
        {
            if(k < dim - 1)
            {
            cout << "----";  
            }
            else
            {
                cout << "---";
            }
        }
      cout << endl;
    }
  }
}

int checkForWinner(char grid[], int dim)
{
  int result = 0;
  int xs;
  int os;
  for(int i = 0; i < dim; i++) //row checker
  {
    xs = 0;
    os = 0;
    for(int j = 0; j < dim; j++) //counting xs and os
    {
      if(getEntryAtRC(grid, dim, i, j) == 'X')
      {
        xs++;
      }
      else if (getEntryAtRC(grid, dim, i, j) == 'O')
      {
        os++;
      }
    }
    if (xs == dim) //if whole row is filled, player wins
    {
      result = 1;
      //cout << "row";
      return result;
    }
    else if (os == dim)
    {
      result = 2;
      //cout << "row";
      return result;
    }
  }
  for(int i = 0; i < dim; i++) //column checker
  {
    xs = 0;
    os = 0;
    for(int j = 0; j < dim; j++)
    {
      if(grid[i + dim * j] == 'X')
      {
        xs++;
      }
      else if (grid[i + dim * j] == 'O')
      {
        os++;
      }
    }
    if (xs == dim)
    {
      result = 1;
      //cout << "row";
      return result;
    }
    else if (os == dim)
    {
      result = 2;
      //cout << "col";
      return result;
    }
  }
  for(int i = 0; i < dim * dim; i += (dim + 1)) //top left to bottom right diagonal checker
  {
    if (i == 0)
    {
      xs = 0;
      os = 0;
    }
    if (grid[i] == 'X') // counting xs and os
    {
      xs++;
    }
    else if (grid[i] == 'O')
    {
      os++;
    }
    if (xs == dim) //if diag is filled, player wins
    {
      result = 1;
      //cout << "diag";
      return result;
    }
    else if (os == dim)
    {
      result = 2;
      //cout << "Diag";
      return result;
    }
  }

  for(int i = dim - 1; i <= dim * (dim - 1); i += (dim - 1)) //top right to bottom left diagonal checker
  {
    if (i == dim - 1)
    {
      xs = 0;
      os = 0;
    }
    if(grid[i] == 'X')
    {
      xs++;
    }
    else if (grid[i] == 'O')
    {
      os++;
    }
    if (xs == dim)
    {
      result = 1;
      //cout << "tiag";
      return result;
    }
    else if (os == dim)
    {
      result = 2;
      //cout << "Tiag";
      return result;
    }
  }
  return result;
}

bool checkForDraw(char grid[], int dim)
{
  bool draw = 0;
  int xrowCounter = 0;
  int orowCounter = 0;
  bool rows = 1;
  int xcolCounter = 0;
  int ocolCounter = 0;
  bool cols = 1;
  int xdiagCounter = 0;
  int odiagCounter = 0;
  bool diag = 1;
  int xtiagCounter = 0;
  int otiagCounter = 0;
  bool tiag = 1;
  for(int i = 0; i < dim; i++) //row checker
  {
    xrowCounter = 0;
    orowCounter = 0;
    for (int j = 0; j < dim; j++)
    {
      if(getEntryAtRC(grid, dim, i, j) == 'X') //counting xs and os
      {
        xrowCounter++;
      }
      if(getEntryAtRC(grid, dim, i, j) == 'O')
      {
        orowCounter++;
      }
    }
    if (xrowCounter < 1 || orowCounter < 1) //if it's proven it's NOT a draw, returns 0 early
      {
        rows = 0;
        break;
      }
  }
  for(int i = 0; i < dim; i++) //col checker
  {
    xcolCounter = 0;
    ocolCounter = 0;
    for (int j = 0; j < dim; j++)
    {
      if(grid[dim * j + i] == 'X')
      {
        xcolCounter++;
      }
      if(grid[dim * j + i] == 'O')
      {
        ocolCounter++;
      }
    }
    if (xcolCounter < 1 || ocolCounter < 1)
      {
        cols = 0;
        break;
      }
  }
  for(int i = dim - 1; i <= dim * (dim - 1); i += (dim - 1)) //tiag checker
  {
    if (grid[i] == 'X')
    {
      xtiagCounter++;
    }
    if (grid[i] == 'O')
    {
      otiagCounter++;
    }
  }
  if (xtiagCounter < 1 || otiagCounter < 1)
    {
      tiag = 0;
    }
  for(int i = 0; i < dim * dim; i += (dim + 1)) //diag checker
  {
    if (grid[i] == 'X')
    {
      xdiagCounter++;
    }
    if (grid[i] == 'O')
    {
      odiagCounter++;
    }
  }
  if (xdiagCounter < 1 || odiagCounter < 1)
    {
      diag = 0;
    }
  //cout << "rows: " << rows << endl << "cols: " << cols << endl << "diag: " << diag << endl << "tiag: " << tiag << endl;
  if (!rows || !cols || !diag || !tiag)
  {
    return draw;
  }
  else
  {
    draw = 1;
    return draw;
  }
}

bool getAiChoiceAndUpdateGrid(char grid[], int dim, char player)
{
  int xs;
  int os;
  for(int i = 0; i < dim; i++) //row updater
  {
    xs = 0;
    os = 0;
    for(int j = 0; j < dim; j++)
    {
      if(getEntryAtRC(grid, dim, i, j) == 'X')
      {
        xs++;
      }
      else if (getEntryAtRC(grid, dim, i, j) == 'O')
      {
        os++;
      }
    }
    if (xs == dim - 1) //if there's one space left in the row, AI will complete OR block depending on what player
    {
      for(int j = dim * i; j < dim * (i + 1); j++)
      {
        if (grid[j] == '?')
        {
          if(player == 'O')
          {
             grid[j] = 'O';
             return 1;
          }
          else if (player == 'X')
          {
            grid[j] = 'X';
            return 1;
          }
        }
      }
    }
    else if (os == dim - 1)
    {
      for(int j = dim * i; j < dim * (i + 1); j++)
      {
        if (grid[j] == '?')
        {
          if(player == 'O')
          {
            grid[j] = 'O';
            return 1;
          }
          else if (player == 'X')
          {
            grid[j] = 'X';
            return 1;
          }
        }
      }
    }
  }
  for(int i = 0; i < dim; i++) //column updater
  {
    xs = 0;
    os = 0;
    for(int j = 0; j < dim; j++)
    {
      if(grid[dim * j + i] == 'X')
      {
        xs++;
      }
      else if (grid[dim * j + i] == 'O')
      {
        os++;
      }
    }
    if (xs == dim - 1)
    {
      for(int j = i; j <= dim * (dim - 1) + i; j += dim)
      {
        if (grid[j] == '?')
        {
          if(player == 'O')
          {
             grid[j] = 'O';
             return 1;
          }
          else if (player == 'X')
          {
            grid[j] = 'X';
            return 1;
          }
        }
      }
    }
    else if (os == dim - 1)
    {
      for(int j = i; j <= dim * (dim - 1) + i; j += dim)
      {
        if (grid[j] == '?')
        {
          if(player == 'O')
          {
            grid[j] = 'O';
            return 1;
          }
          else if (player == 'X')
          {
            grid[j] = 'X';
            return 1;
          }
        }
      }
    }
  }
  for(int i = 0; i <= dim * dim - 1; i += (dim + 1)) //diag updater
  {
    xs = 0;
    os = 0;
    if (grid[i] == 'X')
    {
        xs++;
    }
    else if (grid[i] == 'O')
    {
        os++;
    }
    if (xs == dim - 1)
    {
      for(int i = 0; i <= dim * dim - 1; i += (dim + 1))
      {
        if (grid[i] == '?')
        {
          if (player == 'O')
          {
            grid[i] = 'O';
            return 1;
          }
          else if (player == 'X')
          {
            grid[i] = 'X';
            return 1;
          }
        }
      }
    }
    else if (os == dim - 1)
    {
      for(int i = 0; i <= dim * dim - 1; i += (dim + 1))
      {
        if (grid[i] == '?')
        {
          if (player == 'O')
          {
            grid[i] = 'O';
            return 1;
          }
          else if (player == 'X')
          {
            grid[i] = 'X';
            return 1;
          }
        }
      }
    }
  }
  for(int i = dim - 1; i <= dim * (dim - 1); i += (dim - 1)) //tiag updater
  {
   if (grid[i] == 'X')
   {
       xs++;
   }
   else if (grid[i] == 'O')
   {
       os++;
   }
    if (xs == dim - 1)
    {
      for(int i = dim - 1; i <= dim * (dim - 1); i += (dim - 1))
      {
        if (grid[i] == '?')
        {
          if (player == 'O')
          {
            grid[i] = 'O';
            return 1;
          }
          else if (player == 'X')
          {
            grid[i] = 'X';
            return 1;
          }
        }
      }
    }
    else if (os == dim - 1)
    {
      for(int i = dim - 1; i <= dim * (dim - 1); i += (dim - 1))
      {
        if (grid[i] == '?')
        {
          if (player == 'O')
          {
            grid[i] = 'O';
            return 1;
          }
          else if (player == 'X')
          {
            grid[i] = 'X';
            return 1;
          }
        }
      }
    }
  }
  //last case, AI chooses the first possible index with '?'
  for(int i = 0; i < dim * dim; i++)
  {
      if (grid[i] == '?')
      {
          if (player == 'X')
          {
              grid[i] = 'X';
              return 1;
          }
          else if (player == 'O')
          {
              grid[i] = 'O';
              return 1;
          }
      }
  }
}


// Complete...Do not alter
bool getRandChoiceAndUpdateGrid(char grid[], int dim, char player)
{
    int start = rand()%(dim*dim);
    // look for an open location to play based on random starting location.
    // If that location is occupied, move on sequentially until wrapping and
    // trying all locations
    for(int i=0; i < dim*dim; i++) {
        int loc = (start + i) % (dim*dim);
        if(grid[ loc ] == '?') {
            grid[ loc ] = player;
            return false;
        }
    }
    // No viable location
    return true;
}

int main()
{
    // This array holds the actual board/grid of X and Os. It is sized
    // for the biggest possible case (11x11), but you should only
    // use dim^2 entries (i.e. if dim=3, only use 9 entries: 0 to 8)
    char tttdata[121];

    // dim stands for dimension and is the side length of the
    // tic-tac-toe board i.e. dim x dim (3x3 or 5x5).
    int dim;
    int seed;
    // Get the dimension from the user
    cin >> dim >> seed;
    srand(seed);

    int dim_sq = dim*dim;

    for(int i=0; i < dim_sq; i++) {
        tttdata[i] = '?';
    }

    // Print one of these messages when the game is over
    // and before you quit
    const char xwins_msg[] = "X player wins!";
    const char owins_msg[] = "O player wins!";
    const char draw_msg[] =  "Draw...game over!";

    bool done = false;
    char player = 'X';
    int input = 0;
    // Show the initial starting board
    printTTT(tttdata, dim);

    while(!done) {

        // Add your code here for getting input
        cout << endl << "Player " << player << " enter your square choice [0-" << dim * dim - 1 << "], -1 (AI), or -2 (Random): " << endl;
          cin >> input; 
          if (input < -2 || input >= dim_sq)
          {
            done = 1;
          }
        while (tttdata[input] == 'X' || tttdata[input] == 'O')
        {
          cout << endl << "Player " << player << " enter your square choice [0-" << dim * dim - 1 << "], -1 (AI), or -2 (Random): " << endl;
          cin >> input; 
          if (input < -2 || input >= dim_sq)
          {
            done = 1;
          }
        }
        if(input != -1 && input != -2) //manual input from player
        {
          tttdata[input] = player;
        }
        else if (input == -1) //AI move
        {
          getAiChoiceAndUpdateGrid(tttdata, dim, player);
        }
        else if (input == -2) //random move
        {
          getRandChoiceAndUpdateGrid(tttdata, dim, player);
        }
        printTTT(tttdata, dim);
        if (checkForWinner(tttdata, dim) == 1) //X wins
        {
          cout << endl << xwins_msg << endl;
          done = 1;
        }
        else if (checkForWinner(tttdata, dim) == 2) //O wins
        {
          cout << endl << owins_msg << endl;
          done = 1;
        }
        else if (checkForWinner(tttdata, dim) == 0)
        {
          if (checkForDraw(tttdata, dim) == 1) //check for draw
          {
            cout << endl << draw_msg << endl;
            done = 1;
          }
          else
          {
            if (player == 'X') //switch turn from X to O and vice versa
            {
              player = 'O';
            }
            else
            {
              player = 'X';
            }
          }
        }
    } // end while
    return 0;
}