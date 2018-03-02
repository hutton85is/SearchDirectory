#include <iostream>
#include "FileCounter.h"

using namespace std;

int main()
{
    FileCounter F;
    string path = "C:/Users/russell.TENGI/Documents/HTML/";
    int counter = F.CountingFiles(path.c_str());
    cout << "Files " << counter << endl;

    return 0;
}
