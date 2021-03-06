#include "pch.h"
#include <iostream>

constexpr int N = 6;

using namespace std;

void PrintTab(int tab[N][N]) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << tab[i][j];
		}
		cout << endl;
	}
}

bool SafeSpot(int tab[N][N], int col, int row) {

	int i, j;

	for (i = 0; i < col; i++)
	{
		if (tab[row][i])
		{
			return false;
		}
	}

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (tab[i][j])
		{
			return false;
		}
	}

	for (i = row, j = col; i < N && j >= 0; i++, j--) {
		if (tab[i][j]) {
			return false;
		}
	}

	return true;

}

bool SolveNQueen(int tab[N][N], int col) {

	if (col>=N)
	{
		return true;
	}

	for (int i = 0; i < N; i++)
	{
		if (SafeSpot(tab, col, i)) {
			tab[i][col] = 1;

			if (SolveNQueen(tab, col + 1))
			{
				return true;
			}

			tab[i][col] = 0;
		}
	}

	return false;

}


int main()
{

	int tab[N][N] = { {0,0,0,0,0,0},
					  {0,0,0,0,0,0},
					  {0,0,0,0,0,0},
					  {0,0,0,0,0,0},
					  {0,0,0,0,0,0},
					  {0,0,0,0,0,0} };

	PrintTab(tab);

	if (SolveNQueen(tab, 0) == false)
	{
		cout << "No Solutions !" << endl;
		return 0;
	}

	PrintTab(tab);
	return 1;

}
