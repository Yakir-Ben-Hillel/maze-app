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
    s.push(1, 1); //setting the stack to the first element in the maze.
    Node *temp;
    while (!s.isEmpty())
    {
        temp = s.pop();
        temp->getData(curr_h, curr_w); //updating the curr_h and curr_w by ref
        if (hasNeighbors(curr_h, curr_w, neighbor_h, neighbor_w,*temp))
        {
            s.push(curr_h, curr_w);
            s.push(neighbor_h, neighbor_w); //mark the neighbor to know that we visit there already.
            //Staging to next block.
        }
        if (curr_h == h - 2 && curr_w == w - 2)
        {
            s.makeEmpty();//we got to the exit so we free the stack and finish the building of the maze
        }
    }
}

bool Maze::hasNeighbors(int curr_h, int curr_w, int &neighbor_h, int &neighbor_w,Node& curr)
{
    int arr[5]; //The last one is for the option that no matter what we go back a step.
    int counter = 0;

    for (int i = 0; i < 4; i++)
    {
        if (i == 0 && curr_h - 2 > 0 && !curr.getNeighborPlace(0))
        {
            arr[counter] = i;
            counter++;
        }
        else if (i == 1 && curr_w - 2 > 0 && !curr.getNeighborPlace(1))
        {
            arr[counter] = i;
            counter++;
        }
        else if (i == 2 && curr_h + 2 < this->h - 1 && !curr.getNeighborPlace(2))
        {
            arr[counter] = i;
            counter++;
        }
        else if (i == 3 && curr_w + 2 < this->w - 1 && !curr.getNeighborPlace(3))
        {
            arr[counter] = i;
            counter++;
        }
    }

    if (counter == 0)
        return false; //if non of the ifs had happened the current point in the maze has no neighbors

    int index;
    index=rand()%counter;
    int chosen = arr[index];
    switch (chosen)
    {
    case 0:
        neighbor_h = curr_h - 2;
        neighbor_w = curr_w;
        this->maze[curr_h - 1][curr_w] = ' '; //breaking the wall between the neighbors
        curr.setNeighborPlace(0);//it means that we visit this neighbor and set it to be true
        return true;
        break;
    case 1:
        neighbor_h = curr_h;
        neighbor_w = curr_w - 2;
        this->maze[curr_h][curr_w - 1] = ' '; //breaking the wall between the neighbors
        curr.setNeighborPlace(1);
        return true;
        break;
    case 2:
        neighbor_h = curr_h + 2;
        neighbor_w = curr_w;
        this->maze[curr_h + 1][curr_w] = ' '; //breaking the wall between the neighbors
        curr.setNeighborPlace(2);
        return true;
        break;
    case 3:
        neighbor_h = curr_h;
        neighbor_w = curr_w + 2;
        this->maze[curr_h][curr_w + 1] = ' '; //breaking the wall between the neighbors
       curr.setNeighborPlace(3);
        return true;
        break;

    default:
        return false; //if non of the ifs had happened the current point in the maze has no neighbors
        break;
    }
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
