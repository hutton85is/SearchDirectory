#include <iostream>
#include "FileCounter.h"

using namespace std;

int main()
{
    FileCounter F;
    string path = "C:/Users/JohnRussellHutton/Documents/GitHub/SearchDirectory/";
    int counter = F.countFiles(path.c_str());
    cout << "Files " << counter << endl;

    return 0;
}
