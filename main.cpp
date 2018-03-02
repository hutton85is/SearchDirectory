#include <iostream>
#include "FileCounter.h"

using namespace std;

int main()
{
    FileCounter F;
    string path = "C:/Users/JohnRussellHutton/Documents/GitHub/SearchDirectory/";
    int counter = F.CountingFiles(path.c_str());
    cout << "Files " << counter << endl;

    return 0;
}
