#ifndef FILECOUNTER_H
#define FILECOUNTER_H

#include <tchar.h>
#include <stdio.h>
#include <string>
#include <dirent.h>
#include <Windows.h>

/*ONLY USE THIS WHEN DOING 'COUT'  */
#include <iostream>
using namespace std;
/****************************/

class FileCounter
{
    public:
        FileCounter();
        ~FileCounter();
        int countFiles(const char *filepath);

    private:
        unsigned int filecounter;
        struct dirent *entry;
};

#endif // FILECOUNTER_H
