#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        cout << "Usage: " << argv[0] << " inputfile outputfile\n";
        return 1;
    }

    ifstream fin;
    ofstream fout;
    fin.open(argv[1]);
    fout.open(argv[2]);

    if(!fin.is_open())
    {
         cerr << "open inputfile failed" << endl;
         return 1;
    }

    if(!fout.is_open())
    {
         cerr << "open outputfile failed" << endl;
         return 1;
    }

    char buffer[18] = "\0";
    int len;
    //static char bigbuffer[1024];
    fin.getline(buffer, 18, '\n');
    while(!fin.eof())
    {
        len = strlen(buffer);
        buffer[len++] = '|';
        buffer[len] = '\0';
        fout.write(buffer, len);
        fin.getline(buffer, 18, '\n');
    }

    fin.close();
    fout.close();

    return 0;
}
