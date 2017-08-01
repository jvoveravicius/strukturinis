#include <cstdlib>
#include <inttypes.h>
#include <sstream>
#include <string>
#include <time.h> 
#include <iostream>
#include <fstream>


using namespace std;


/*
Ne objetiniu budu:

Tekstiniame faile irasyta 10 trizenkliu skaiciu - po viena skaiciu kiekvienoje eiluteje. 
Parasykite funkcijas, kurios a) perskaitytu skaiciu, b) isnalaizuotu, kurie lyginiai, c) perrasytu i nauja faila tik tai tuos, kurie lyginiai

*/



void writeRandValue(string FileName, int amount){
	
	
	int *max  = new int;
	int *min = new int;
	int *range = new int; 
	int *random = new int;
	
	
	*max = 999;
	*min = 100;
 
	srand (time(NULL));

	ofstream outputFile(FileName.c_str());
	
	*range = *max-*min + 1;
	
	
	cout<<"Writting data.."<<endl;
	
	
	for (int i=0;i<amount;i++){
		
		*random=rand()%*range + *min;
		outputFile <<*random<<endl; 
		cout<<*random<<endl;	
	}
	
	outputFile.close();
	
	delete[] max, min, range, random;
}



short *readRandValue(string FileName, int stop){
	
	cout<<"Reading data... "<<endl;
	
	short *output = new short;
	short* array=new short[stop];
	
	
	 ifstream myReadFile;
	 
	 myReadFile.open(FileName.c_str());
	 
	 short is = 0;
	 
	 
	 if (myReadFile.is_open()) {
	 	
		 	
		 while (!myReadFile.eof()) {
		 	
		    myReadFile >> array[is];
		    
		    
		    if (is==stop){
		    	break;
			}
		    
		    cout<<array[is]<<endl;
			is++;
	
			
		}
	
	
	}
	
	cout<<endl<<endl;
	
	delete[] output;
	
	 return array;

}

short* AnalizeNewValue(int stop){


	short* AllInitialValues = readRandValue("test.txt", stop);
	short* array = new short[stop];
	
	
	cout<<"Analization result: "<<endl;
	
	short tmpIt = 1;
	
	for (int i = 0; i<stop;i++){
		
		
		if (AllInitialValues[i] % 2 == 0){
	 		
		   	array[tmpIt] = AllInitialValues[i];
		   	cout<<array[tmpIt]<<endl;	
			tmpIt++;
		}
			
		
	}
	
	
	array[0] = tmpIt;
	
	return array;


	
}



int main(int argc, char *argv[])
{	

	short *amount = new short;
	*amount = 10;
	
	writeRandValue("test.txt",*amount);
	
	short * array = AnalizeNewValue(*amount); 
	
	//-----------Irasymas---------
	ofstream outputFile("test1.txt");

	cout<<"Now writting correct data to file..."<<endl;
	
	outputFile<<"Results are: "<<endl;
	
	for (int i=1;i<array[0];i++){
		
		outputFile<<array[i]<<endl;
		
	}
	
	outputFile.close();
	//-----------Irasymas---------
	
	system("pause");
    return EXIT_SUCCESS;
}



