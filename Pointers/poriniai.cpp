#include <cstdlib>
#include <inttypes.h>
#include <sstream>
#include <string>
#include <time.h> 
#include <iostream>
#include <fstream>


using namespace std;



int main(int argc, char *argv[])
{	

	int *x = NULL;

	int z = 15;
	
	x = &z;
	
	cout<<"Pointerio adresas        "<<x<<endl;
	cout<<"Kintamasis Z              "<<z<<endl;
	cout<<"Priskirto pointerio x reiksme      "<<*x<<endl;
	cout<<"Z kintamojo adresas         "<<&z<<endl;
	
	cout<<endl<<endl<<endl;
	
	system("pause");
    return EXIT_SUCCESS;
}



