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
void Odd_even_sort(int *AA, int m)
{
   bool bDone = false;
   while(!bDone)
   {
      bDone=true;
      for(int i=1; i<m-1; i+=2)
      {
          if(AA[i]>AA[i+1])
          {
              swap(AA[i],AA[i+1]); bDone = false;
          };
      };
      show(AA,m,'t');
      for(int j=0; j<m-1; j+=2)
      {
          if(AA[j]>AA[j+1])
          {
               swap(AA[j],AA[j+1]); bDone = false;
          };
      };
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
    Odd_even_sort(iAA,nAA);
    show(iAA,nAA,'F');
    system("PAUSE");
    return EXIT_SUCCESS;
}
