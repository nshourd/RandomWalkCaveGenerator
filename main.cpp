#include <iostream>
#include "map.h"

using namespace std;

int main()
{
    char response;

    while(response != 'q')
    {
        cout << "Do you have a map you would like to load?(y/n/q): ";
        cin >> response;
        int rows = 30, cols = 50;

        map gameMap(rows, cols);

        char cave[30][50];

        if(response == 'n')
        {
            map gameMap(rows, cols);

            char cave[30][50];
            for(int r = 0; r < rows; r++)
            {
                for(int c = 0; c < cols; c++)
                {
                    cave[r][c] = '#';
                }
            }

            gameMap.generate(cave);
            gameMap.display(cave);
            gameMap.save(cave);
        }
        else if(response == 'y')
        {
            gameMap.read(cave);
            gameMap.display(cave);
        }
    }

    cout << "Thanks for using this Random Walk Cave Generator!" << endl;

    return 0;
}
