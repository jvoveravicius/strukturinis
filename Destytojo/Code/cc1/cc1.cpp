#include <cstdlib>
#include <iostream>
#include <list>
using namespace std;

int main(int argc, char *argv[])
{
    list <int> sarasas;
    list <int>::iterator iter;
    list <int>::iterator iter_ini;
    list <int>::iterator iter_fin;
    
               sarasas.push_back(1);
               sarasas.push_back(2);
               sarasas.push_front(3);
               sarasas.push_front(4); 
               
    iter_ini = sarasas.begin();
    iter_fin = sarasas.end();
  
    cout << "1-asis ************\n";  
    for (iter  = iter_ini; 
         iter != iter_fin; 
         iter++)
       cout << *iter << endl;
    cout << endl;  
    
               sarasas.push_front(5);
               sarasas.push_front(6);

    iter_ini = sarasas.begin();
    iter_fin = sarasas.end();
               
    cout << "2-asis ************\n";  
    for (iter  = iter_ini; 
         iter != iter_fin; 
         iter++)
       cout << *iter << endl;
    cout << endl;                           

    sarasas.reverse();
    iter_ini = sarasas.begin();
    iter_fin = sarasas.end();
               
    cout << "3-asis ************\n";  
    for (iter  = iter_ini; 
         iter != iter_fin; 
         iter++)
       cout << *iter << endl;
    cout << endl;       

    sarasas.sort();
    iter_ini = sarasas.begin();
    iter_fin = sarasas.end();
               
    cout << "4-asis ************\n";  
    for (iter  = iter_ini; 
         iter != iter_fin; 
         iter++)
       cout << *iter << endl;
    cout << endl;       
                                                           
    system("pause");
    return EXIT_SUCCESS;
}
