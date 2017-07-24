#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char *argv[])
{
    stack <int> malka;
    malka.push(500);
    cout << malka.size() << " " << malka.top() << endl;
    malka.push(501);
    cout << malka.size() << " " << malka.top() << endl;
    malka.push(510);
    cout << malka.size() << " " << malka.top() << endl;
    malka.push(520);
    cout << malka.size() << " " << malka.top() << endl;  
    malka.pop();
    cout << malka.size() << " " << malka.top() << endl;           
    system("pause");
    return EXIT_SUCCESS;
}
