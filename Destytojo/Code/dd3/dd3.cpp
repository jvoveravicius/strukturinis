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
void Shell_sort(int *AA, int m)
{
   int i,h,j,BB;
   for (h=1; h<=m/9; h=3*h+1);
   for (; h>0; h/=3)
   {
      for (i=h;i<m;i++)
      {
         BB=AA[i];
         for (j=i-h; j>=0; j-=h)
         {
            if (BB < AA[j])  AA[j+h] = AA[j];
            else break;
         };
         AA[j+h]=BB;
         show(AA,m,'T');
      };
   };
}
// ======================================
int main(int argc, char *argv[])
{
    int iAA[]={80,89,57,53,35,
               11,42,29,88,16};
    int nAA=10;
    
    show(iAA,nAA,'I');
    Shell_sort(iAA,nAA);
    show(iAA,nAA,'F');
    system("PAUSE");
    return EXIT_SUCCESS;
}

