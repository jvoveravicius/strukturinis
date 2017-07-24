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
void Quick_sort(int *AA, int iLower,int iHigher)
{
   int i = iLower,
   j = iHigher;
   int index =(int)((iLower+iHigher)/2);
   int XXX = AA[index];
   // partition
   do
   {
      while (AA[i]<XXX) i++;
      while (AA[j]>XXX) j--;
      if (i<=j)
      {
          swap(AA[i],AA[j]);
          i++; j--;
      };
      show(AA,iHigher,'T');
    }
    while (i<=j);
    // recursion
    if ( iLower < j       ) Quick_sort(AA, iLower, j      );
    if ( i      < iHigher ) Quick_sort(AA, i,      iHigher);
}
// ======================================
int main(int argc, char *argv[])
{
    int iAA[]={80,89,57,53,35,
               11,42,29,88,16};
    int nAA=10;
    
    show(iAA,nAA,'I');
    Quick_sort(iAA,0,nAA-1);
    show(iAA,nAA,'F');
    system("PAUSE");
    return EXIT_SUCCESS;
}

