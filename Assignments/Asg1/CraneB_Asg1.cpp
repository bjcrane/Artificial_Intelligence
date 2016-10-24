#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

bool goalTest (int *board)
{
	int total = 0;

	for (int i = 0; i < 50; i++)
	{
		total += board[i];
	}
	cout << "total : " << total << endl;

	if (board [25] == 1 && total == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool inBounds(int pegNumber)
{
	int outOfBounds[17] = {0, 1, 2, 6, 7, 8, 9, 13, 14, 36, 37, 41, 42, 43, 44, 48, 49};
	for (int i=0; i < 17; i++)
	{
		if (pegNumber == outOfBounds[i])
		{
			return false;
		}
	}
	return true;
}

int* jump(int board[], int pegNumber, int direction)
{
	// NSEW, North
	if (direction == 0 && board[pegNumber - 14] == 0 && inBounds(board[pegNumber - 14])  )
	{
		board[pegNumber] = 0;
		board[pegNumber - 14] = 1;
		board[pegNumber - 7] = 0;
		return board;
	}
	// South
	else if (direction == 1 && board[pegNumber + 14] == 0 && inBounds(board[pegNumber + 14]) )
	{
		board[pegNumber] = 0;
		board[pegNumber + 14] = 1;
		board[pegNumber + 7] = 0;
		return board;
	}	
	// East
	else if (direction == 2 && board[pegNumber + 2] == 0 && inBounds(board[pegNumber + 2]))
	{
		board[pegNumber] = 0;
		board[pegNumber + 2] = 1;
		board[pegNumber + 1] = 0;
		return board;
	}
	// West
	else if (direction == 3 && board[pegNumber - 2] == 0 && inBounds(board[pegNumber - 2])) 
	{
		board[pegNumber] = 0;
		board[pegNumber - 2] = 1;
		board[pegNumber - 1] = 0;
		return board;
	}
	else 
	{
		return board; 
	}
}

void successor(int board[], int iPrime, int jPrime, int &cost)
{
	for (int i=iPrime; i<47; i++)
	{
		for(int j=jPrime; j<3; j++)
		{	
			if(!goalTest(board))
			{	
				//increaseStepCost(cost);
				successor(jump(board, i, j), i, j);
			}
		}
	}
	//reduceStepCost(cost);
}

void increaseStepCost(int &cost)
{
	cost++;
}

void reduceStepCost(int &cost)
{
	cost--;
}

int main() {
	// int board[50] = {0, 0, 0, 1, 1, 1, 0, 0,     
 //                  	0, 0, 1, 1, 1, 0, 0,
 //                  	1, 1, 1, 1, 1, 1, 1,
 //                  	1, 1, 1, 0, 1, 1, 1,
 //                  	1, 1, 1, 1, 1, 1, 1,
 //               		0, 0, 1, 1, 1, 0, 0,
 //                  	0, 0, 1, 1, 1, 0, 0};
 
 	int board [50] = {0, 0, 0, 0, 0, 0, 0, 0,
 					  0, 0, 0, 0, 0, 0, 0,
 					  0, 0, 0, 0, 0, 0, 0,
 					  0, 0, 0, 1, 0, 0, 0, 
 					  0, 0, 0, 0, 0, 0, 0, 
 					  0, 0, 0, 0, 0, 0, 0,
 					  0, 0, 0, 0, 0, 0, 0};
	int cost = 0;

	for (int i=0; i< 50; i++)
	{
		cout << board[i];
		if (i%7 == 0 && i != 0){
			cout << endl;
		}
	}
	
	// Goal Test
	cout << "middle = " << board[25] << endl;
	
	bool test = goalTest(board);
	cout << "goal test fn = " << test << endl;
	
	//Successor Function
	// if (successor(board, 3, 0))
	// {
	// 	cout << "solution found" << endl;
	// }

	return 0;
}