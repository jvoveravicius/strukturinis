#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

void swap(int &B, int &C)
{
    int D; D=B; B=C; C=D;
}
// =============================
void show(int *AA, int k, char a)
{
    ofstream fout1("rez.txt",ios::out | ios::binary);
    cout << a << " ";
    fout1 << a << " ";
    for (int i=0; i<k; i++)
    {
        cout << " " << AA[i];
        fout1 << " " << AA[i];
    };
    cout << endl;
    fout1 << endl;
    fout1.close();
}
// ===================================
void Selection_sort(int *AA, int m)
{
   int BB,CC; int mm=m;
   BB=AA[mm];
   for (int i=(mm-1); i>=0; i--)
   {
       if (AA[i]>BB) BB=AA[i];
       while (( mm > 0 )&&(AA[mm] == BB)) mm--;
   };
   while (mm>0)
   {
       CC=BB; BB=AA[mm];
       for (int j=(mm-1); j>=0; j--)
       {
           if (AA[j] == CC)
           {
               swap(AA[j], AA[mm]);
               mm--;
           }
           else
           {
               if (AA[j]>BB) BB=AA[j];
           };
       };
       while (( mm > 0)&&(AA[mm] == BB)) mm--;
       show(AA,m,'T');
    };
}
// ======================================
int main(int argc, char *argv[])
{
    int iAA[]={80,89,57,53,35,
               11,42,29,88,16};
    int nAA=10;
    
    show(iAA,nAA,'I');
    Selection_sort(iAA,nAA);
    show(iAA,nAA,'F');
    system("PAUSE");
    return EXIT_SUCCESS;
}

