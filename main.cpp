#include <iostream>
#include "FileCounter.h"

using namespace std;

int main()
{
    FileCounter F;
    string path = "/home/russell/CPPProgramss/";
    int counter = F.CountingFiles(path.c_str());
    cout << "Files " << counter << endl;

    return 0;
}
