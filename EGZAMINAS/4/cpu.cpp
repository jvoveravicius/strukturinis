#include <stdio.h>     
#include <time.h>       
#include <math.h> 
#include <cstdlib>
#include <inttypes.h>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include<cmath>   
#include <windows.h>



using namespace std;

/*
4. Naudoti windows.h, time  ir C++ bibliotekas. 
   Programuoti, sudarant klase ir objektus.
   I grafini ekrana išvesti procesoriaus laika skaitmeniniu formatu realiuoju laiku.

*/



class CPU
{

private:
    double getTime();
            
public:
	CPU();
		
}; 
// =========================================================

CPU::CPU()
{
    
	double d0 = getTime();
		
	do
	{
		
		
		double timeInMilliseconds = 1000* (getTime() - d0);	
		
		int seconds = (int) (timeInMilliseconds / 1000) % 60 ;
		int minutes = (int) (timeInMilliseconds / (1000*60)) % 60 ;
		int hours = (int) (timeInMilliseconds / (1000*60*60)) % 24 ;
	
		
		cout<<"Time: "<<hours<<":"<<minutes<<":"<<seconds<<endl;
		
	}while(true);
    
}

// =========================================================



double CPU::getTime() {
  LARGE_INTEGER freq, val;
  QueryPerformanceFrequency(&freq);
  QueryPerformanceCounter(&val);
  return (double)val.QuadPart / (double)freq.QuadPart;
}







int main(int argc, char *argv[])
{
    
    CPU run;
    system("pause");
    return EXIT_SUCCESS;
}

