#include "Maze.h"

Maze::Maze(int h = max_h, int w = max_w)
{
    this->maze = new char *[h];
    for (int x = 0; x < w; x++)
    {
        this->maze[x] = new char[w];
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            this->maze[h][w] = '*';
        }
    }
    this->maze[1][0] = ' ';
    this->maze[h - 2][w - 1] = ' ';
}
Maze::~Maze()
{
    for (int i = 0; i < this->h; i++)
    {
        delete[] this->maze[i];
    }
    delete[] this->maze;
}
const char **Maze::getMaze() const
{
    return this->maze;
}

int Maze::gethight() const
{
    return this->h;
}
int Maze::getwidth() const
{
    return this->w;
}