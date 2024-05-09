#include "../include/core.h"
#include <fstream>
#include <stdint.h>
#include <iostream>

char *readDotBinFile(char *fileName, int *fileSizeBuf)
{
    std::ifstream file;

    file.open(fileName, std::ios::in);

    file.seekg(0, std::ios::end);

    uint32_t fileSize = file.tellg();

    file.seekg(0, std::ios::beg);

    *fileSizeBuf = fileSize;

    if(!fileSize)
    {
        std::cout << "Empty File\n";
        return 0;
    }
    
    char *buffer = new char[fileSize];
    uint32_t counter = 0;

    while(file.is_open())
    {
        char nextChar = file.get();

        if(nextChar == EOF)
        {
            file.close();
            break;
        }
        
        buffer[counter] = nextChar;
        counter++;
    }

    if(counter != fileSize)
    {
        std::cout << "Did not read the entire file\n";
        return buffer;
    }

    return buffer;
}