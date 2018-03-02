#include "FileCounter.h"

FileCounter::FileCounter()
{
    filecounter = 0;
}

FileCounter::~FileCounter()
{
}

void FileCounter::findSubFolders(const char *directory)
{
    filecounter += countFiles(directory);

    DIR *dir = opendir(directory);

    entry = readdir(dir);

    while (entry != NULL)
    {
        if (entry->d_type == DT_DIR)
        {
            if (entry->d_name[0] != '.')
            {
                cout << "directory is : " << directory << endl;
                size_t dirlength1 = strlen(directory);
                size_t dirlength2 = strlen(entry->d_name);
                cout << "size of directory is : " << dirlength1 << endl;
                cout << "new folder found is : " << entry->d_name << endl;

                char *newdirectory = (char*) malloc(dirlength1 + dirlength2 + 2);
                cout << "size of newdirectory : " << dirlength1 + dirlength2 + 2 << endl;

                memcpy(newdirectory, directory, dirlength1);
                newdirectory[dirlength1 + dirlength2] = '/';
                newdirectory[dirlength1 + dirlength2 + 1] = '\0';

                cout << "newdirectory is : " << newdirectory << endl;
                cout << endl;
                findSubFolders(newdirectory);
            }
        }
        entry = readdir(dir);
    }

    closedir(dir);
}


int FileCounter::countFiles(const char *filepath)
{
    DIR *dir = opendir(filepath);

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

int FileCounter::CountingFiles(const char *directorypath)
{
    findSubFolders(directorypath);

    return filecounter;
}
