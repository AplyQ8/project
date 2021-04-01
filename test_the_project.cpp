#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctime>
#include <string>
#include <direct.h>
#include <dirent.h>
using namespace std;
char bmp[50][50];
char bmp1[50][50];


DIR* dir;
struct dirent* ent;

void reader()
{
    int x;
    ifstream file1;
    ifstream file2;
    file1.open("c:\\Users\\HYPERPC\\Desktop\\test1\\v1.bmp");
    file2.open("c:\\Users\\HYPERPC\\Desktop\\test2\\v2.bmp");
    if (!file1)
    {
        cout << "File does not opened" << endl;
    }
    if (!file2)
    {
        cout << "File does not opened" << endl;
    }


    unsigned int bgr = 0;

 

    for (int i = 0; i < 36; i++)
    {
        file1.read((char*)&bgr, 3);
        file2.read((char*)&bgr, 3);
    }

    for (int y = 50; y > 0; y--)
    {
        for (int x = 0; x < 50; x++)
        {
            file2.read((char*)&bgr, 3);
            if (bgr == 0xFFFFFF)
            {
                bmp1[x][y] = '0';
            }
            else
            {
                bmp1[x][y] = '1';
            }
            bgr = 0;
        }
    }
    for (int y = 50; y > 0; y--)
        {
        for (int x = 0; x < 50; x++)
            {
            file1.read((char*)&bgr, 3);
            if (bgr == 0xFFFFFF)
            {
                bmp[x][y] = '0';
            }
            else
            {
                bmp[x][y] = '1';
            }
            bgr = 0;
            }
        }    
}

void write()
{
    srand(time(NULL));
    auto x = rand();
    string l = "C:\\Users\\HYPERPC\\Desktop\\test1\\" + to_string(x) + ".bmp";
    ifstream file2;
    file2.open("C:\\Users\\HYPERPC\\Desktop\\test2\\v2.bmp");
    ofstream file1;
    file1.open(l, fstream::out);
    while (!file2.eof())
    {
        char a[3];
        file2.read(a, 3);
        file1.write(a, 3);

    }
    file2.close();
    file1.close();

    _chdir("C:\\Users\\HYPERPC\\Desktop\\test2");
    system("del v2.bmp");
    
}


double cmp()
{
    double a = 0, b = 0;
    for (int i = 50; i > 0; i--)
    {
        for (int j = 0; j < 50; j++)
        {
            if (bmp[i][j] == bmp1[i][j])
                a++;
            b++;
        }
    }
    return a * 100 / b -2.64;
}

int main()
{
    reader();
    cout << cmp() << "%";
    write();

    return 0;
}

