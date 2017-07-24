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
void Insertion_sort(int *AA, int m)
{
   int BB,j; bool just;
   for ( int i=1; i<=(m-1); i++)
   {
      BB=AA[i]; j=i-1; just = false;
      do
      {
         // ascending
         if (AA[j] > BB)
         {
            AA[j+1] = AA[j]; j--;
            if (j<0) just = true;
         }
         else just=true;
      }
      while (just==false);
      AA[j+1]= BB;
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
    Insertion_sort(iAA,nAA);
    show(iAA,nAA,'F');
    system("PAUSE");
    return EXIT_SUCCESS;
}

