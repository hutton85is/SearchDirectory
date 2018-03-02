#include "FileCounter.h"

FileCounter::FileCounter()
{
    filecounter = 0;
}

FileCounter::~FileCounter()
{
}

int FileCounter::CountingFiles(const char *directorypath)
{
    DIR *dir = opendir(directorypath);

    entry = readdir(dir);

    if (!entry)
    {
        closedir(dir);

        return -1;
    }

    closedir(dir);

    findSubFolders(directorypath);

    return filecounter;
}

void FileCounter::findSubFolders(const char *directorypath)
{
    filecounter += countFilesInFolder(directorypath);

    DIR *dir = opendir(directorypath);

    entry = readdir(dir);

    while (entry != NULL)
    {
        if (entry->d_type == DT_DIR)
        {
            if (entry->d_name[0] != '.')
            {
                findSubFolders(createNewPath(directorypath));
            }
        }
        entry = readdir(dir);
    }

    closedir(dir);
}


int FileCounter::countFilesInFolder(const char *directorypath)
{
    DIR *dir = opendir(directorypath);

    entry = readdir(dir);

    unsigned int counter = 0;

    while (entry != NULL)
    {
        if (entry->d_type == DT_REG)
        {
            counter++;
        }
        entry = readdir(dir);
    }

    closedir(dir);

    return counter;
}

char *FileCounter::createNewPath(const char *directory)
{
    size_t dirlength1 = strlen(directory);
    size_t dirlength2 = strlen(entry->d_name);

    char *newdirectory = (char*) malloc(dirlength1 + dirlength2 + 2);
    memcpy(newdirectory, directory, dirlength1);
    for (unsigned int i = 0; i < dirlength2; i++)
    {
        newdirectory[dirlength1 + i] = entry->d_name[i];
    }
    newdirectory[dirlength1 + dirlength2] = '/';
    newdirectory[dirlength1 + dirlength2 + 1] = '\0';

    return newdirectory;
}
