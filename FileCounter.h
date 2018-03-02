#ifndef FILECOUNTER_H
#define FILECOUNTER_H

#include <tchar.h>
#include <stdio.h>
#include <string>
#include <dirent.h>
#include <Windows.h>
#include <stdlib.h>

/*ONLY USE THIS WHEN DOING 'COUT'  */
#include <iostream>
using namespace std;
/****************************/

class FileCounter
{
    public:

        FileCounter();

        ~FileCounter();

        int CountingFiles(const char *directorypath);

    private:

        unsigned int filecounter;

        struct dirent *entry;

        int countFiles(const char *filepath);

        void findSubFolders(const char *directory);
};

#endif // FILECOUNTER_H
