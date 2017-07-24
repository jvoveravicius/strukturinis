#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    map <int, string>:: iterator iter1;
    map <string, int>:: iterator iter2; 
          
    map <int,string> sarasas1;
                     sarasas1 [7401] = "Mike Q.";
                     sarasas1 [7220] = "Charlie B.";
                     sarasas1 [7228] = "David R.";
                     sarasas1 [7224] = "Harry D.";
                     sarasas1 [7400] = "John S.";
    
    map <string, int> sarasas2;
                      sarasas2 ["Hank Q."   ] = 6250;
                      sarasas2 ["Charlie G."] = 6290;
                      sarasas2 ["Kent Z."   ] = 6271;
                      sarasas2 ["Harry D."  ] = 6222;
                      sarasas2 ["Dave Q."   ] = 6211;
    
    pair <string, int> kazkas;
                       kazkas = make_pair ("Zemaite",1850); 
    sarasas2.insert(kazkas);
                      
    // Assignment: insert() and STL pair
    sarasas2.insert (std::pair<string,int>("Stephen F.",6003));
    
    // Assignment: insert() and "value_type()"
    sarasas2.insert(map<string,int>::value_type("Michael I.",6009));

    // Assignment: insert() and "make_pair()"
    sarasas2.insert(std::make_pair("Larry N.",6005));                  
   
   for ( iter1 = sarasas1.begin(); iter1 != sarasas1.end(); ++iter1)
   {
          cout << (*iter1).first << " ==> "
               << (*iter1).second << endl;
   };
   cout << endl;
   
      for ( iter2 = sarasas2.begin(); iter2 != sarasas2.end(); ++iter2)
   {
          cout << (*iter2).first << " ==> "
               << (*iter2).second << endl;
   };
   cout << endl;
    
    system("pause");
    return EXIT_SUCCESS;
}
