#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//display shortest path
void printPath(int q, int r, int* P[])
{
	if (P[q][r] != 0)
	{
		printPath(q,P[q][r]-1,P);
		cout << "V" << P[q][r]<<" -> ";
		printPath(P[q][r]-1,r, P);
	}

}

//get matrix D, P
void floy2(int n,  int *W[], int *D[], int *P[])
{

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			P[i][j] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			D[i][j] = W[i][j];
		}
	}

	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if (D[i][k] + D[k][j] < D[i][j])
				{
					P[i][j] = k+1;
					D[i][j] = D[i][k] + D[k][j];
				}
}



int main()
{
	int matrixDimension = 0;//size of the two dimential array
	string temp;
	string fileName = "p4data.txt";// file that stores weight graph data

	ifstream file;
	
	file.open(fileName);

	if (file.is_open())// get the dimension of the mtrix by counting the number of lines
	{
		while (getline(file, temp))
		{
			matrixDimension++;
		}
	}
	else
		cout << "Unable to open file." << endl;
	file.close();


	// Array that stores the weitghs of the vertexes
	int **W = new int *[matrixDimension];
	for (int i = 0; i < matrixDimension; ++i)
	{
		W[i] = new int[matrixDimension];
	}

	//array that stores weight of the shortest path
	int **D = new int *[matrixDimension];
	for (int i = 0; i < matrixDimension; ++i)
	{
		D[i] = new int[matrixDimension];
	}

	//array that stores the highest vertex in the shortest path
	int **P = new int *[matrixDimension];
	for (int i = 0; i < matrixDimension; ++i)
	{
		P[i] = new int[matrixDimension];
	}

	file.open(fileName, 0);

	//read in weight data to matrix W
	if (file.is_open())
	{
		for (int i = 0; i < matrixDimension; i++)
		{
			for (int j = 0; j < matrixDimension; j++)
			{
				file >> temp;
				W[i][j] = stoi(temp);
			}
		}

	}
	else
		cout << "Unable to open file." << endl;


	// call function floy2 to get matrix D,P
	floy2(matrixDimension, W, D, P);

	//display matrix D
	cout << "D: " << endl;
	for (int i = 0; i < matrixDimension; i++)
	{
		for (int j = 0; j < matrixDimension; j++)
		{
			cout << D[i][j] << " ";
		}
		cout << endl;
	}cout << endl;

	//display matrix P
	cout << "P: " << endl;
	for (int i = 0; i < matrixDimension; i++)
	{
		for (int j = 0; j < matrixDimension; j++)
		{
			cout << P[i][j] << " ";
		}
		cout << endl;
	}cout << endl;


	int userInputVertex1, userInputVertex2;//store unser input vertexes for getting the shotest path
	char userContinueChoice = 'y';// store user input for continue with next path

	while (userContinueChoice == 'y')
	{
		cout << "Enter a source vertex and destination vertex: ";
		cin >> userInputVertex1 >> userInputVertex2;
		cout << "V" << userInputVertex1 << " -> ";
		printPath(userInputVertex1-1, userInputVertex2-1,P);
		cout << "V" << userInputVertex2 << endl;;
		cout << "More path ?";
		cin >> userContinueChoice;

	}



	char c;
	cin >> c;
	return 0;
}