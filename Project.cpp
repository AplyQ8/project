#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
using namespace std;
int bmp[50][50];
int bmp1[50][50];

void reader()
{
    int x;
    ifstream file1;
    ifstream file2;
    file2.open("c:\\Users\\USER\\Desktop\\test1\\v1.bmp");
    file1.open("c:\\Users\\USER\\Desktop\\test1\\v2.bmp");
    if(!file1)
    {
        cout<<"File does not opened"<<endl;
    }
    if(!file2)
    {
        cout<<"File does not opened"<<endl;
    }


    unsigned int bgr=0;

    for(int y=0;y<50;y++)
    {
        for(int x=0;x<50;x++)
        {
            file1.read((char*)&bgr,3);
            if(bgr==0xFFFFFF)
            {
                bmp[x][y]=0;
            }
            else
            {
                bmp[x][y]=1;
            }
            bgr=0;
        }
    }

    for(int y=0;y<50;y++)
    {
        for(int x=0;x<50;x++)
        {
            file2.read((char*)&bgr,3);
            if(bgr==0xFFFFFF)
            {
                bmp1[x][y]=0;
            }
            else
            {
                bmp1[x][y]=1;
            }
            bgr=0;
        }
    }
}

double cmp()
{
    double a=0, b=0;
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<50;j++)
        {
            if((bmp[i][j]==bmp1[i][j])/*&&(bmp[i][j]==1)&&(bmp1[i][j]==1)*/)
                a++;
            b++;
        }
    }
    return a*100/b;
}

int main()
{

    /*for(int i=0;i<50;i++)
    {
        for(int j=0;j<50;j++)
        {

            cout<<bmp[i][j]<<endl;

        }
    }*/

    reader();
    cout<<cmp()<<"%";
    return 0;
}
