#include <cstdlib>
#include <iostream>
#include <set>
using namespace std;

void show(set<int> sXX)
{
    set<int>::iterator iter;
    set<int>::iterator iter_ini;
    set<int>::iterator iter_fin;
    
    iter_ini = sXX.begin();
    iter_fin = sXX.end();
    
    for (iter  = iter_ini;
         iter != iter_fin;
         iter++)
        cout << *iter << endl;
    cout << endl;
}
// ==================================================
int main(int argc, char *argv[])
{
      // filling of set
      set<int> sAA;
               sAA.insert(19); sAA.insert(20);
               sAA.insert(10); sAA.insert(11);
      show(sAA);

      // pointers used as iterators
      int iBB[]= {17,14,15,16,13};
      set<int> sBB (iBB,iBB+4);   // iBB   atitinka &iBB[0]
      show(sBB);

      // a copy of set
      set<int> sCC (sBB);
      show(sCC);

      // a copy of set using iterators
      set<int> sDD (sBB.begin(), sBB.end());
      sDD.insert (sAA.begin(), sAA.end());
      show(sDD);

     system("PAUSE"); 
     return 0;
}
