#include "../include/Maze.h"
constexpr int x=23;
constexpr int y=23;
int main() 
{
	Maze maze(y,x);
	char** temp=maze.getMaze();
    for(int i=0;i<y;i++)
	{
		for(int j=0;j<x;j++)
		{
			cout<<temp[i][j]<<"  ";
		}
		cout<<endl;
	}
	system("pause");
}