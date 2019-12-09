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
bool ifValidMaze(char **maze_to_check, int h, int w)
{
    int sizeOfLine = strlen(maze_to_check[0]);
    SetMazeSpace(&maze_to_check, h, w);
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
            if (sizeOfLine != strlen(maze_to_check[i]))
                return false;
            //this loop checks if the top and the bottom walls are exist.
            for (int j = 0; j < w; j++)
            {
                if (maze_to_check[0][j] != '*')
                    return false;
                if (maze_to_check[h - 1][j] != '*')
                    return false;
                if (maze_to_check[i][j] != ' ' && maze_to_check[i][j] != '*')
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
    char **temp = new char *[h];
    for (int i = 0; i < h; i++)
    {
        temp[i] = new char[w + 1];
        cin.getline(temp[i], w + 1, '\n');
        if (i < h - 1)
            getchar(); //flush the '\n' from the buffer
    }
    if (ifValidMaze(temp, h, w) == true) //checks if the user's maze is valid. //TODO
    {
        Maze maze(h, w, temp);
        M_free(temp, h);
        cout << "your maze: " << endl;
        maze.showMaze(); //show why a friend function does not work
        cout << "Final solution: " << endl;
        maze.solveMaze();
        maze.showMaze();
    }
    else
    {
        cout << "invalid input" << endl;
        exit(1);
    }
}

void SetMazeSpace(char ***temp, int h, int w)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if ((*temp)[i][j] != ' ' && (*temp)[i][j] != '*')
                (*temp)[i][j] = ' ';
        }
    }
}