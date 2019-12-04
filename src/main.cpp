#include "../include/Maze.h"

void Mfree(char** arr,int h);

int main()
{
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
		cout << "insert the hight and the width of the maze:(in this format hight(max:25) then width(max:80))"<<endl;
		cin >> h >> w;
		cin.ignore(256, '\n');
		if ((h > 25 || w > 80) || (h < 0 || w < 0))
			cout << "invalid values please try again" << endl;
	} while ((h > 25 || w > 80) || (h < 0 || w < 0));
	if (x == 1) //making a random maze
	{
		Maze maze(h, w);//creating the starting maze in the constractor
		maze.createMaze(); //TODO
		showMaze(maze.getMaze(), h, w);
	}
	else //if (x == 2)insert the user's maze
	{
		cout<<"insert your maze: "<<endl;
		char **temp = new char *[h];
		for (int i = 0; i < h; i++)
		{
			temp[i] = new char[w];
			cin.getline(temp[i], w);
		}
		if (ifValidMaze(temp, h, w)==true)//checks if the user's maze is valid. //TODO
		{
			Maze maze(h, w, temp);
			Mfree(temp,h);
			showMaze(maze.getMaze(), h, w);//show why a friend function does not work
		}
		else
		{
			cout << "invalid input" << endl;
			exit(1);
		}
	}
	system("pause");
}

void Mfree(char** arr,int h)
{
  for(int i=0;i<h;i++)
  {
	  delete[] arr[h];
  }
  delete[] arr;
}