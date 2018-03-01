#include <Windows.h>
#include <iostream>

#include <tchar.h>
#include <stdio.h>
#include <string>
#include <dirent.h>

using namespace std;
/*
int countFiles(const char *path)
{
    WIN32_FIND_DATA file;
    HANDLE search_handle = FindFirstFile(path, &file);
    unsigned int counter = 0;
    if (search_handle)
    {
        do
        {
            counter++;
            wcout << file.cFileName << endl;
        }while(FindNextFile(search_handle,&file));
        FindClose(search_handle);
    }
    return counter;
}
*/

int countFiles2(const char *PATH)
{

    DIR *dir = opendir(PATH);

    struct dirent *entry = readdir(dir);

    unsigned int filecounter = 0;

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

int main()
{
    string path = "c:/Users/russell.TENGI/Desktop/SearchDirectory/";
    int counter = countFiles2(path.c_str());
    cout << "Files " << counter << endl;

    return 0;
}
