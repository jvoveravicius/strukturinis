#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    queue <int> nora1; // 1st
    for (int i=0; i<=4; i++)
       nora1.push(i*10);
       
    while (!nora1.empty())
    {
        cout << nora1.front() << " ";
        nora1.pop();
    };
    cout << endl;
     
    queue <int> nora2; // 2nd
    for (int j=5; j<=9; j++)
         nora2.push(j*10);
         
    while (!nora2.empty())
    {   
         cout << nora2.back() << " ";
         nora2.pop();
    };
    cout << endl;
 
    system("PAUSE"); return 0;
}
