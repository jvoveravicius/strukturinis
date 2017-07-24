#include <cstdlib>
#include <iostream>
#include <utility>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    pair <string, string> knyga1;
                          knyga1.first  = "Petras_Cvirka";
                          knyga1.second = "Frank_Kruk";
    pair <string, string> knyga2("Lazdynu_Peleda", "Rastai");
    pair <string, string> knyga3;
                          knyga3 = make_pair ("Zemaite","Rastai"); 
    
    cout << knyga1.first << "  " << knyga1.second << endl;  
    cout << knyga2.first << "  " << knyga2.second << endl; 
    cout << knyga3.first << "  " << knyga3.second << endl;                                              
    system("pause");   
    return EXIT_SUCCESS;
}               
