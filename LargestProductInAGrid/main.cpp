//
//  main.cpp
//  LargestProductInAGrid
//
//  Created by Michael Wienands on 9/26/17.
//  Copyright © 2017 Michael Wienands. All rights reserved.
//
//  https://github.com/mwienands/LargestProductInAGrid.git


#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    // always a 20x20 matrix
    const unsigned int Size = 20;
    unsigned int grid[Size][Size];
    
    // read from console
    for (unsigned int y = 0; y < Size; y++)
        for (unsigned int x = 0; x < Size; x++)
            std::cin >> grid[x][y];
    
    unsigned int best = 0;
    // walk through all cells of the matrix
    for (unsigned int y = 0; y < Size; y++)
        for (unsigned int x = 0; x < Size; x++)
        {
            // three more horizontal cells (right)
            if (x + 3 < Size)
            {
                unsigned int current = grid[x][y] * grid[x+1][y] * grid[x+2][y] * grid[x+3][y];
                if (best < current)
                    best = current;
            }
            // three more vertical cells available (down)
            if (y + 3 < Size)
            {
                unsigned int current = grid[x][y] * grid[x][y+1] * grid[x][y+2] * grid[x][y+3];
                if (best < current)
                    best = current;
            }
            // three more diagonal cells (right-down)
            if (x + 3 < Size && y + 3 < Size)
            {
                unsigned int current = grid[x][y] * grid[x+1][y+1] * grid[x+2][y+2] * grid[x+3][y+3];
                if (best < current)
                    best = current;
            }
            // three more diagonal cells (left-down)
            if (x + 3 < Size && y >= 3)
            {
                unsigned int current = grid[x][y] * grid[x+1][y-1] * grid[x+2][y-2] * grid[x+3][y-3];
                if (best < current)
                    best = current;
            }
        }
    
    std::cout << best << std::endl;
    return 0;
}



