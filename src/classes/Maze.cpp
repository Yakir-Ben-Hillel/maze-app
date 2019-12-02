#include "../../include/Maze.h"

//if maze=nullptr it means we need to create a default maze and then use the function create maze to do a random maze
//if maze!=nullptr it means the user gave us its own maze and we should set the maze to this maze.
Maze::Maze(int h, int w, char **maze):h(h),w(w)
{
    //allocating the member maze than sent it to setMaze
    this->maze = new char *[h];
    for (int i = 0; i < h; i++)
    {
        this->maze[i] = new char[w];
    }
    setMaze(maze);
}
Maze::~Maze()
{
    for (int i = 0; i < this->h; i++)
    {
        delete[] this->maze[i];
    }
    delete[] this->maze;
}
char **Maze::getMaze() const
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

void Maze::createMaze()
{
    //in the constractor we make the full maze so,we already know that the member from the main who call this function is a full maze.
    Stack s;
    int curr_h, curr_w;
    s.push(1, 1, '*'); //setting the stack to the first element in the maze.
    while (!s.isEmpty)
    {
        Node *temp;
        temp = s.pop();
        temp->getData(curr_h, curr_w);    //updating the curr_h and curr_w by ref
        this->maze[curr_h][curr_w] = ' '; //mark the point we popped from the stack
        if (hasNeighbors(curr_h, curr_w))
        {
        }
    }
}

bool Maze::hasNeighbors(int curr_h, int curr_w)
{
}

void Maze::setMaze(char **maze)
{
    if (maze == nullptr)//creating a default maze and then use the function createMaze to pick a random maze
    {
       for(int i=0;i<this->h;i++)
       {
           if(i%2==0)
           {
               for(int j=0;j<w;j++)
               {
                   this->maze[i][j]='*';
               }
           }
           else
           {
               for(int k=0;k<this->w;k++)
               {
                   if(k%2==0)
                   {
                       this->maze[i][k]='*';
                   }
                   else
                   {
                       this->maze[i][k]=' ';
                   }
                   
               }
           }
           this->maze[i][w]='\0';
       }
       this->maze[1][0]=this->maze[h-2][w-1]=' ';
    }
    else//put the user's maze in the member maze.
    {
        for (int i = 0; i < this->h; i++)
        {
            for (int j = 0; j < this->w; j++)
            {
                this->maze[i][j] = maze[i][j];
            }
        }
    }
}

void showMaze(char **maze, int h, int w) 
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}