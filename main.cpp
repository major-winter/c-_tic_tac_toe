#include <iostream>

using namespace std;

char board[3][3]{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
void player1st_move();
void player2nd_move();
void check_win();
int check_row();
int check_col();
int check_diagonal();
void draw_board();
void start()
{
  player1st_move();
  player2nd_move();
  check_win();
}

int main()
{
  start();
  draw_board();
  return 0;
}

void player1st_move()
{
  int x{0};
  int y{0};
  cout << "1st Player enters your move: ";
  cin >> x >> y;
  cout << endl;
  if (board[x - 1][y - 1] == 'O')
  {
    cout << "1st Player: ";
    cin >> x >> y;
    cout << endl;
  }
  board[x - 1][y - 1] = 'X';
  draw_board();
}

void player2nd_move()
{
  int x{0};
  int y{0};
  cout << "2nd Player enters your move: ";
  cin >> x >> y;
  cout << endl;
  if (board[x - 1][y - 1] == 'X')
  {
    cout << "2nd Player enters your move: ";
    cin >> x >> y;
    cout << endl;
  }
  else if (board[x - 1][y - 1] != 'X')
  {
    board[x - 1][y - 1] = 'O';
  }
  draw_board();
}

void check_win()
{
  int result{check_row()};
  if (result == 1)
  {
    cout << "Player 1 has won" << endl;
  }
  else if (result == 2)
  {
    cout << "Player 2 has won" << endl;
  }
  else
  {
    int result_diagonal{check_diagonal()};
    if (result_diagonal == 1)
    {
      cout << "Player 1 has won" << endl;
    }
    else if (result_diagonal == 2)
    {
      cout << "Player 2 has won" << endl;
    }
    else
    {
      int result_col{check_col()};
      if (result_col == 1)
      {
        cout << "Player 1 has won" << endl;
      }
      else if (result_col == 2)
      {
        cout << "Player 2 has won" << endl;
      }
      else
      {
        start();
      }
    }
  }
}

int check_row()
{
  if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
  {
    if (board[0][0] == 'X')
    {
      return 1;
    }
    else if (board[0][0] == 'O')
    {
      return 2;
    }
  }
  else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
  {
    if (board[1][0] == 'X')
    {
      return 1;
    }
    else if (board[1][0] == 'O')
    {
      return 2;
    }
  }
  else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
  {
    if (board[2][0] == 'X')
    {
      return 1;
    }
    else if (board[2][0] == 'O')
    {
      return 2;
    }
  }
  return 3;
}

int check_diagonal()
{
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
  {
    if (board[0][0] == 'X')
    {
      return 1;
    }
    else if (board[0][0] == 'O')
    {
      return 2;
    }
  }
  else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
  {
    if (board[0][2] == 'X')
    {
      return 1;
    }
    else if (board[0][2] == 'O')
    {
      return 2;
    }
  }
  return 3;
}

int check_col()
{
  if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
  {
    if (board[0][0] == 'X')
    {
      return 1;
    }
    else if (board[0][0] == 'O')
    {
      return 2;
    }
  }
  else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
  {
    if (board[0][1] == 'X')
    {
      return 1;
    }
    else if (board[0][1] == 'O')
    {
      return 2;
    }
  }
  else if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
  {
    if (board[0][2] == 'X')
    {
      return 1;
    }
    else if (board[0][2] == 'O')
    {
      return 2;
    }
  }
  return 3;
}

void draw_board()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << board[i][j] << "|";
    }
    cout << endl;
  }
}