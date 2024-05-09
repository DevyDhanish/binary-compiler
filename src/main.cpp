#include "../include/core.h"
#include <iostream>

int main()
{
    
    int fileSize = 0;
    char *contents = readDotBinFile((char *)&"test.bin", &fileSize);

    int counter = 0;
    while(counter != 103)
    {
        std::cout << contents[counter];
        counter++;
    }

    return 0;
}