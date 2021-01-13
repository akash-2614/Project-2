#include<iostream>
using namespace std;
#define  n 9

int canBeFilled(int grid[n][n], int R, int C, int num)
{
	for(int i=0; i<9; ++i)
	{
		if(grid[R][i] == num)
			return 0;
	}

	for(int i=0; i<9; ++i)
	{
		if(grid[i][C] == num)
			return 0;
	}

	int startR = R - R%3;
	int	startC = C - C%3;

	for(int i=0; i<3; ++i)
	{
		for(int j=0; j<3; ++j)
		{
			if(grid[i+startR][j+startC] == num)
				return 0;
		}
	}

	return 1;
}

int solveSuduko(int grid[n][n], int R, int C)
{
	if(R == n-1 && C == n)
		return 1;

	if(C == n)
	{
		R++;
		C=0;
	}

	if(grid[R][C]>0)
		return solveSuduko(grid, R, C+1);

		for(int i=1; i<=n; ++i)
		{
			if(canBeFilled(grid, R, C, i))
			{
				grid[R][C] = i;
				if(solveSuduko(grid, R, C+1))
					return 1;
			}
			grid[R][C] = 0;
		}
		return 0;
}

int main()
{
	cout<<"      SUDUKO SOLVER      "<<endl;
	int grid[n][n];
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
		{
			cout<<"Press 1-9 for filling the cell and 0 for leaving the cell empty:\n";
				cin>>grid[i][j];
		}
	}

	int ok = solveSuduko(grid, 0, 0);
	if(ok == 1)
	{
		cout<<endl<<"      SOLVED SUDUKO      "<<endl;
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
	}
		
	else
	{
		cout<<"Grid is not completed\n";
	}

	return 0;
}