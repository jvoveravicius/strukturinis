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
// =============================
void Merge(int *AA, int part1, int nnn)
{
   // Storage requirements
   int *TT;
   TT = new int[part1+1];
   int j = 0;
   // Reduction in data transfer
   while(j < part1)
   {
      TT[j] = AA[j]; j++;
   };
   // Infinity will be Sentinel
   TT[j] = 1000000000;
   int k=0; int i=0;
   while(j < nnn)
   {
      if (TT[i] <= AA[j]) {AA[k] = TT[i]; i++;}
      else                {AA[k] = AA[j]; j++;};
      k++;
   };
   while(i < part1)
   {
      AA[k] = TT[i]; i++; k++;
   };
   show(AA,nnn,'T');
}
// ==========================================
void Merge_sort(int *AA, int m)
{
   int iPart,iLast; int *iP;
   if(m>1)
   {
      iPart = (int)((float)m/(float)2.0);
      Merge_sort( AA, iPart);
      iP=&AA[iPart];
      iLast = m; iLast -=iPart;
      Merge_sort( iP, iLast);
      Merge ( AA, iPart, m);
   }
}
// ======================================
int main(int argc, char *argv[])
{
    int iAA[]={80,89,57,53,35,
               11,42,29,88,16};
    int nAA=10;
    
    show(iAA,nAA,'I');
    Merge_sort(iAA,nAA);
    show(iAA,nAA,'F');
    system("PAUSE");
    return EXIT_SUCCESS;
}

