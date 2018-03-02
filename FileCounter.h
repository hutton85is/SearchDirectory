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

        /*
            A public caller function that makes a call to search and count files in a specific path
            Variable directorypath is the path to the folder which files are counted in
            return count of all files in variable directorypath and all its subfolders
         */
        int CountingFiles(const char *directorypath);

    private:

        /* counter for all files in a file path */
        unsigned int filecounter;

        /* structure variable entry contains all the information of folder and file */
        struct dirent *entry;

        /*
            Count all files in a single folder
            variable directorypath is the path to the folder which files are counted in
            return a count of all files in the folder from variable directorypath
         */
        void countFilesInFolder(const char *directorypath);

        /* find subfolders to search for files in */
        void findSubFolders(const char *directorypath);

        /*
            Create a new path from the folder path variable directorypath, appending the new folder found from the private pointer variable entry
            return new path to search for files and folders
        */
        char *createNewPath(const char *directorypath);
};

#endif // FILECOUNTER_H
