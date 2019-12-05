#include "../../include/Maze.h"

//if maze=nullptr it means we need to create a default maze and then use the function create maze to do a random maze
//if maze!=nullptr it means the user gave us its own maze and we should set the maze to this maze.
Maze::Maze(int h, int w, char **maze) : h(h), w(w)
{
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
    int curr_h, curr_w, neighbor_h, neighbor_w;
    s.push(1, 1, ' '); //setting the stack to the first element in the maze.
    while (!s.isEmpty())
    {
        Node *temp;
        temp = s.pop();
        temp->getData(curr_h, curr_w);    //updating the curr_h and curr_w by ref
        if (hasNeighbors(curr_h, curr_w, neighbor_h, neighbor_w))
        {
            s.push(curr_h, curr_w, ' ');
            s.push(neighbor_h, neighbor_w, '$');//mark the neighbor to know that we visit there already.
        }
    }
}

bool Maze::hasNeighbors(int curr_h, int curr_w, int &neighbor_h, int &neighbor_w)
{
    srand((unsigned)time(NULL));
    int x = rand();
    if (x % 4 == 0 && curr_h - 2 > 0 && this->maze[curr_h - 2][curr_w] != '$')
    {
        neighbor_h = curr_h - 2;
        neighbor_w = curr_w;
        this->maze[curr_h - 1][curr_w] = ' '; //breaking the wall between the neighbors
        return true;
    }
    else if (x % 4 == 1 && curr_w - 2 > 0 && this->maze[curr_h][curr_w - 2] != '$')
    {
        neighbor_h = curr_h;
        neighbor_w = curr_w - 2;
        this->maze[curr_h][curr_w - 1] = ' '; //breaking the wall between the neighbors
        return true;
    }
    else if (x % 4 == 2 && curr_h + 2 < this->h - 1 && this->maze[curr_h + 2][curr_w] != '$')
    {
        neighbor_h = curr_h + 2;
        neighbor_w = curr_w;
        this->maze[curr_h + 1][curr_w] = ' '; //breaking the wall between the neighbors
        return true;
    }
    else if (x % 4 == 3 && curr_w + 2 < this->w - 1 && this->maze[curr_h][curr_w + 2] != '$')
    {
        neighbor_h = curr_h;
        neighbor_w = curr_w + 2;
        this->maze[curr_h][curr_w + 1] = ' '; //breaking the wall between the neighbors
        return true;
    }
    return false; //if non of the ifs had happened the current point in the maze has no neighbors
}

void Maze::setMaze(char **maze)
{
    this->maze = new char *[this->h];
    if (maze == nullptr) //creating a default maze and then use the function createMaze to pick a random maze
    {
        for (int i = 0; i < this->h; i++)
        {
            this->maze[i] = new char[this->w];
            if (i % 2 == 0)
            {
                for (int j = 0; j < w; j++)
                {
                    this->maze[i][j] = '*';
                }
            }
            else
            {
                for (int k = 0; k < this->w; k++)
                {
                    if (k % 2 == 0)
                    {
                        this->maze[i][k] = '*';
                    }
                    else
                    {
                        this->maze[i][k] = ' ';
                    }
                }
            }
            this->maze[i][w] = '\0';
        }
        this->maze[1][0] = this->maze[h - 2][w - 1] = ' ';
    }
    else //put the user's maze in the member maze.
    {
        for (int i = 0; i < this->h; i++)
        {
            this->maze[i] = new char[this->w];
            for (int j = 0; j < this->w; j++)
            {
                this->maze[i][j] = maze[i][j];
            }
        }
    }
}

void Maze::showMaze()
{
    for (int i = 0; i < this->h; i++)
    {
        for (int j = 0; j < this->w; j++)
        {
            cout << this->maze[i][j] << " ";
        }
        cout << endl;
    }
}

