#include<iostream>
#include<vector>
using namespace std;

int solution_count = 0;//notice solution_count is unbounded, purpose: we can call solution_count on 2 different functions

void queen_print(vector<vector<int>> board, int n)
//function to print out the board
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";//taking the vector 'board' content out
        }
        cout << '\n';
    }
    cout << "-----------------\n";
}

bool queen_check(vector<vector<int>> board, int row, int col, int n)
//set of loops to implement the queen function (checks run along the y-axis)
{
    //vertical check
    for (int j = 0; j < col; j++)
    {
        if (board[row][j])
        {
            return false;
        }
    }
    //vertical-left diagonal check
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    //vertical-right diagonal check
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    //if the given position passed all the checks,
    return true;
}

bool queen_solve(vector<vector<int>> board, int col, int n)
//this function will place the queens while applying backtracking algorithm
{
    bool result = true;
    if (col == n)
    {
        queen_print(board, n);//prints the solution board every time the tracer reaches the end
        solution_count++;
        return result;
    }
    for (int i = 0; i < n; i++)//iterator for placing the queens
    {
        if (queen_check(board, i, col, n))//backtracker
        {
            board[i][col] = 1;
            result = queen_solve(board, col+1, n) || result;
            board[i][col] = 0;
        }  
    }
    return result;
}

int main()
{
    cout << "nqueen --- the N-Queen Problem Solver\nVersion 1.0 //Copyright 2023 - Enrico William Rusliem - 2254164//\n\n";
    cout << "[nqueen] Enter the chessboard size (Input must be an int > 1) : ";
    int n;
    cin >> n;
    while (true)
    //filtering user input, preventing errors caused by invalid input
    //note: all doubles input will be rounded down
    {
        if (n == 12345)
            cout << "Do not put that as your account password!";
        else if (n > 1)
            break;
        else
            cout << "[nqueen] Invalid input, please enter an integer > 1\n";
        return 0;
    }
    cout << '\n';
    vector<vector<int>> chessboard(n, vector<int>(n, 0)); //formulating the nxn chessboard
    if (queen_solve(chessboard, 0, n)) //print out the iteration summary
        cout << "\n[nqueen] Board size: " << n << "x" << n << " ; solution count: " << solution_count << '\n';
	return 0;
}