#include "FileCounter.h"

FileCounter::FileCounter()
{
    filecounter = 0;
}

FileCounter::~FileCounter()
{
}


int FileCounter::countFiles(const char *filepath)
{

    DIR *dir = opendir(filepath);

    entry = readdir(dir);

    while (entry != NULL)
    {
        if (entry->d_type == DT_REG)
        {
            filecounter++;
            cout << entry->d_name << endl;
        }
        entry = readdir(dir);
    }

    closedir(dir);

    return filecounter;
}
