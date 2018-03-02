/**
    This program returns a count for all files in a given path and its subfolders.
    Program returns 0, if there are no files
    Program returns -1, if the file path requested does not exist

    It's constraints are that it does not count folders that have a name starting with
    the character dot('.')
**/

#ifndef FILECOUNTER_H
#define FILECOUNTER_H

#include <dirent.h>
#include <Windows.h>

class FileCounter
{
    public:

        FileCounter();

        ~FileCounter();

        int CountingFiles(const char *directorypath);

    private:

        unsigned int filecounter;

        struct dirent *entry;

        int countFilesInFolder(const char *directorypath);

        void findSubFolders(const char *directorypath);

        char *createNewPath(const char *directorypath);
};

#endif // FILECOUNTER_H
