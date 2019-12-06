#include "../include/Maze.h"

void M_free(char **arr, int h);
bool ifValidMaze(char **maze_to_check, int h, int w);
void changeDollars(int h, int w, char **maze);

int main()
{
	srand((unsigned)time(NULL));
	//the building main for the part of creating maze
	//TODO:: making the solution of the maze by queue and build it's main parts
	int x;
	do
	{
		cout << "Welcome to MAZE" << endl;
		cout << "would you like to pick a random maze or enter your own?" << endl;
		cout << "press 1 for random" << endl;
		cout << "press 2 for your maze" << endl;
		cin >> x;
		if (x > 2 || x < 1)
			cout << "invalid input please try again." << endl;
	} while (x > 2 || x < 1);
	int h, w;
	do
	{
		cout << "insert the hight and the width of the maze:(in this format hight(max:25) then width(max:80))" << endl;
		cin >> h >> w;
		cin.ignore(256, '\n');
		if ((h > 25 || w > 80) || (h < 0 || w < 0))
			cout << "invalid values please try again" << endl;
		if (h % 2 == 0 || w % 2 == 0)
			cout << "invalid values please try again" << endl;
	} while ((h > 25 || w > 80) || (h < 0 || w < 0) || (h % 2 == 0 || w % 2 == 0));
	if (x == 1) //making a random maze
	{
		Maze maze(h, w); //creating the starting maze in the constractor
		maze.showMaze();

		maze.createMaze();
		cout << "Finished Maze" << endl;
		changeDollars(h, w, maze.getMaze());
		maze.showMaze();
	}
	else //if (x == 2)insert the user's maze
	{
		cout << "insert your maze: " << endl;
		char **temp = new char *[h];
		for (int i = 0; i < h; i++)
		{
			temp[i] = new char[w];
			cin.getline(temp[i], w);
		}
		if (ifValidMaze(temp, h, w) == true) //checks if the user's maze is valid. //TODO
		{
			Maze maze(h, w, temp);
			M_free(temp, h);
			maze.showMaze(); //show why a friend function does not work
		}
		else
		{
			cout << "invalid input" << endl;
			exit(1);
		}
	}
	system("pause");
}

void M_free(char **arr, int h)
{
	for (int i = 0; i < h; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

bool ifValidMaze(char **maze_to_check, int h, int w)
{
	if (h % 2 == 0 || w % 2 == 0) //the maze height or width must be odd
		return false;
	else if (maze_to_check[1][0] != ' ' || maze_to_check[h - 2][w - 1] != ' ') //the maze must have both entrance and exit
		return false;
	else //the maze must have a path from the enter to the exit from the entrance
	{
		//this loop check if all the walls are in the maze
		for (int i = 0; i < h; i++)
		{
			//the next two ifs check if the left and right walls are exist.
			if (maze_to_check[i][0] != '*' && i != 1)
				return false;
			if (maze_to_check[i][w - 1] != '*' && i != h - 2)
				return false;
			//this loop checks if the top and the bottom walls are exist.
			for (int j = 0; j < w; j++)
			{
				if (maze_to_check[0][j] != '*')
					return false;
				if (maze_to_check[h - 1][j] != '*')
					return false;
			}
		}
		return true; //if all the checks didn't give false the maze is valid.
	}
}
void changeDollars(int h, int w, char **maze)
{
	for (int i = 1; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (maze[i][j] == '$')
				maze[i][j] = ' ';
		}
	}
}