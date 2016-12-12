#include <iostream>
#include <fstream>
#include <string>
//#include <string.h>
using namespace std;

#define MAX 60000
string ipbuffer;
char temp[16];

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

    char buffer[80];
    fin.getline(buffer, 80, '\n');
    while(!fin.eof())
    {
        int i = 0;
//        memset(temp, 0, 16);
        for(;buffer[i] != ' ';i++)
        {
            temp[i] = buffer[i];
        }
        temp[i] = '\0';
        //cout << temp << endl;

        // remove same ip
        if(ipbuffer.find(temp) == string::npos)
        {
            ipbuffer.append(temp);
            ipbuffer.append("|");
        }
        int size = ipbuffer.size();
        if(size > 1024)
        {
            fout.write(ipbuffer.c_str(), size);
            ipbuffer.resize(0, ' ');
        }
        //cout << ipbuffer <<endl;

        fin.getline(buffer, 80, '\n');
    }

    fout.write(ipbuffer.c_str(), ipbuffer.size());

    fin.close();
    fout.close();

    return 0;
}
