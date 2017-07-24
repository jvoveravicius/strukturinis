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
void Bubble_sort(int *AA, int m)
{
    int kk, a1,a2; int k=m;
    do
    {
        kk=0;
        for (int i=0; i<k-1; i++)
        {
            // ascending
            if (AA[i] > AA[i+1])
            {
                 swap(AA[i],AA[i+1]);
                 kk=i+1;
            };
        };
    k=kk;
    show(AA,m,'T');
    }
    while (k>1);
}
// ======================================
int main(int argc, char *argv[])
{
    int iAA[]={80,89,57,53,35,
               11,42,29,88,16};
    int nAA=10;
    
    show(iAA,nAA,'I');
    Bubble_sort(iAA,nAA);
    show(iAA,nAA,'F');
    system("PAUSE");
    return EXIT_SUCCESS;
}

