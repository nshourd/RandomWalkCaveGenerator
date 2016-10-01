#include "map.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

map::map(int r, int c)
{
    rows = r;
    cols = c;
}

void map::generate(char cave[30][50])
{
    srand(time(NULL));
    int currentRow = rand() % rows, currentCol = rand() % cols, floorCount = (rows * cols) / 2, currentFloors = 0;
    cave[currentRow][currentCol] = '.';
    currentFloors++;

    while(currentFloors < floorCount)
    {
        int direction = rand() % 4; //0 is N, 1 is E, 2 is S, 3 is W
        //North
        if(direction == 0)
        {
            if(currentRow > 1)
            {
                currentRow -= 1;
                if(cave[currentRow][currentCol] == '#')
                {
                    cave[currentRow][currentCol] = '.';
                    currentFloors++;
                }
            }
        }
        //East
        else if(direction == 1)
        {
            if(currentCol < cols - 2)
            {
                currentCol += 1;
                if(cave[currentRow][currentCol] == '#')
                {
                    cave[currentRow][currentCol] = '.';
                    currentFloors++;
                }
            }
        }
        //South
        else if(direction == 2)
        {
            if(currentRow < rows - 2)
            {
                currentRow += 1;
                if(cave[currentRow][currentCol] == '#')
                {
                    cave[currentRow][currentCol] = '.';
                    currentFloors++;
                }
            }
        }
        //West
        else if(direction == 3)
        {
            if(currentCol > 1)
            {
                currentCol -= 1;
                if(cave[currentRow][currentCol] == '#')
                {
                    cave[currentRow][currentCol] = '.';
                    currentFloors++;
                }
            }
        }
    }
}

void map::display(char cave[30][50])
{
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            cout << cave[r][c];
        }
        cout << endl;
    }
}

void map::save(char cave[30][50])
{
    //creates file object
    ofstream file;
    //opens/creates the file
    file.open("map.txt");
    if(file.is_open())
    {
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                file << cave[r][c] << " ";
            }
            file << endl;
        }
    }
    else
    {
        cout << "Can't open file!" << endl;
    }

    file.close();

    cout << "Map saved to file" << endl;
}

void map::read(char cave[30][50])
{
    ifstream file;
    file.open("map.txt");
    if(file.is_open())
    {
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                file >> cave[r][c];
            }
        }
    }
    else
    {
        cout << "Can't open file!" << endl;
    }

    file.close();

    cout << "Map read!" << endl;
}
