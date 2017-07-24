#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    vector <int> vGina;
    vector <int>::iterator iter;
    vector <int>::iterator iter_sta;
    vector <int>::iterator iter_end;



    
    cout << vGina.size() << " " << vGina.capacity() << endl;
    
    cout << "Konteinerio uzpildymas reiksmemis \n";
    for (int i=0; i<=10; i++)
    {
        vGina.push_back(i*10);
        cout << i << " " << vGina.size() << " " << vGina.capacity() << endl;
    };
    iter_sta = vGina.begin();
    iter_end = vGina.end();
    vGina.insert(iter_sta+1,101);
    vGina.insert(iter_sta+5,505);
    
    cout << "Konteinerio turinio isvedimas: 1 budas \n";
    int iSize = vGina.size();
    for (int i=0; i<iSize; i++)
    {
        cout << i << " " << vGina[i] << endl;
    };
    
    cout << "Konteinerio turinio isvedimas: 2 budas \n";
    iter_sta = vGina.begin();
    iter_end = vGina.end();
    for (   iter  = iter_sta; 
            iter  < iter_end; 
          ++iter)
    {
        cout << *iter << endl;
    };
    

    
    system("pause");
    return EXIT_SUCCESS;
}
