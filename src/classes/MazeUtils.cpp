#include "../../include/Maze.h"
void M_free(char **arr, int h)
{
    for (int i = 0; i < h; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
//we already checked if the h and w are valid,now we are checking if the maze has all the walls and all the chars are ' ' or '*'
bool Maze::isMazeValid()
{
    int sizeOfLine = strlen(this->maze[0]);
    if (h % 2 == 0 || w % 2 == 0) //the maze height or width must be odd
        return false;
    else if (this->maze[1][0] != ' ' || this->maze[h - 2][w - 1] != ' ') //the maze must have both entrance and exit
        return false;
    else //the maze must have a path from the enter to the exit from the entrance
    {
        //this loop check if all the walls are in the maze
        for (int i = 0; i < this->h; i++)
        {
            //the next two ifs check if the left and right walls are exist.
            if (this->maze[i][0] != '*' && i != 1)
                return false;
            if (this->maze[i][this->w - 1] != '*' && i != this->h - 2)
                return false;
            if (sizeOfLine != strlen(this->maze[i]))
                return false;
            //this loop checks if the top and the bottom walls are exist.
            for (int j = 0; j < w; j++)
            {
                if (this->maze[0][j] != '*')
                    return false;
                if (this->maze[h - 1][j] != '*')
                    return false;
                if (this->maze[i][j] != ' ' && this->maze[i][j] != '*')
                    return false;
            }
        }
        return true; //if all the checks didn't give false the maze is valid.
    }
}
void startMaze()
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
        cout << "insert the hight and the width of the maze:(in this format hight(max:25) then width(max:79))" << endl;
        cout << "For Example: 3 5 (3 for height then space then 5 for width)" << endl;
        cin >> h >> w;
        getchar();
        if ((h > 25 || w > 79) || (h < 0 || w < 0))
            cout << "invalid values please try again" << endl;
        if (h % 2 == 0 || w % 2 == 0)
            cout << "invalid values please try again" << endl;
    } while ((h > 25 || w > 79) || (h < 0 || w < 0) || (h % 2 == 0 || w % 2 == 0));
    if (x == 1) //making a random maze
    {
        randomMaze(h, w);
    }
    else //if (x == 2)insert the user's maze
    {
        userMaze(h, w);
    }
}
void randomMaze(int h, int w)
{
    Maze maze(h, w); //creating the starting maze in the constractor
    cout << "Maze Skeleton:" << endl;
    maze.showMaze();
    maze.createMaze();
    cout << "Built Maze" << endl;
    maze.changeDollars();
    maze.showMaze();
    cout << "Finished Solution" << endl;
    maze.solveMaze();
    maze.showMaze();
}
void userMaze(int h, int w)
{
    cout << "insert your maze: " << endl;
    // cin.ignore();
    char **temp = new char *[h];
    char str[80];
    cin.getline(str, 80);
    temp[0] = new char[w + 1];
    strcpy(temp[0], str);
    for (int i = 1; i < h; i++)
    {
        cin.getline(str, 80);
        temp[i] = new char[w + 1];
        strcpy(temp[i], str);
    }
    Maze maze(h, w, temp);
    M_free(temp, h);
    cout << "The maze you built" << endl;
    maze.showMaze();

    if (maze.isMazeValid() && maze.solveMaze())
    { //Checks if the given input is valid in the maze structure, and if the maze as a solution.
        cout << "your maze: " << endl;
        cout << "Final solution: " << endl;
        maze.showMaze();
    }
    else
    {
        cout << "invalid input" << endl;
        exit(1);
    }
}
