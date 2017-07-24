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



struct s_FileData {
  int y[1000];
  int tw[1000];
  int Amount;
  int twAmount;
}FileData;



void writeRandValue(string FileName, int amount){

	int max = 999, min = 100, range, random; 
	srand (time(NULL));

	ofstream outputFile(FileName.c_str());
	
	range = max-min + 1;
	
	cout<<"Writting data.."<<endl;
	
	for (int i=0;i<amount;i++){
		
		random=rand()%range + min;
		outputFile <<random<<endl; 
		cout<<random<<endl;	
	}
	
	
	outputFile.close();
}



int readRandValue(string FileName, int stop){
	

	string number;
	
	FileData.Amount = stop;
	
	cout<<endl<<"Reading data..."<<endl;
	
	//atidarymas
	ifstream input(FileName.c_str());

	if(input.is_open()){
	
	    do{
	    	
	    	stop--;
	    	
	    	getline(input,number);
	        
			FileData.y[stop] = atoi(number.c_str()); 
	        cout<<FileData.y[stop]<<endl;
	    	
		}while(stop!=0);
	
	}
	
	//uzdarymas
	input.close();

	cout<<endl;
		
}


void AnalizeNewValue(){
	
	
	int tmpc=0;
	
	
	for (int i=FileData.Amount-1;i>-1;i--){
				
		
    	if ( FileData.y[i] % 2 == 0){
    	 	
    	 	
    	 	FileData.tw[tmpc] = FileData.y[i]; 
    	 	
    	 	cout<<"Twisted: "<<FileData.tw[tmpc]<<endl;
    		tmpc++;
			   		
		}
	        	
		
	}
	
	
	FileData.twAmount = tmpc;
	
	
}


void readDataToFile(string FileName, int amount){


	ofstream outputFile(FileName.c_str());
	
	cout<<endl<<"Writting data.."<<endl;
	
	
	for (int i=0;i<amount;i++){
		
		outputFile <<FileData.tw[i]<<endl; 
		
	}
	
	
	outputFile.close();
}


int main(int argc, char *argv[])
{	


	writeRandValue("test.txt",10);
	readRandValue("test.txt", 10);
	AnalizeNewValue();
	readDataToFile("test_tw.txt", FileData.twAmount);
	
	
	system("pause");
    return EXIT_SUCCESS;
}



