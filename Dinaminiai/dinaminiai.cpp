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

	int *d = new int; //kompiuterio atmintyje isskiriama vieta sveikojo tipo dinaminiam kitnamajam *d ir sio kintamjo adresas priskiriamas rodykles tipo kintamajam d
	//ir sio kintamojo adresas priskiriamas rodykles tipo kintamajam d
	
	
	
	cout << sizeof(d) << "\n"; //<<pointerio dydis
	
	/*
	
	arba:
	
	int *d; <<isskiriama vieta
	d = new int; <<sio kintamojo adresas priskiriamas rodykles tipo kintamajam d;
	
	
	*/
	*d = 125;
	
	cout<<d<<endl; //ekrane parodomas rodykles d laikomas adresas
	cout<<*d<<endl; //ekrane parodomas dinaminio kintamojo d reiksme 

	
	delete[] d;
	
	system("pause");
    return EXIT_SUCCESS;
}



