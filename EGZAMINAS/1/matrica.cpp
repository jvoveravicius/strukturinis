#include <cstdlib>
#include <inttypes.h>
#include <sstream>
#include <string>
#include <time.h> 
#include <iostream>
#include <fstream>
#include<cmath>

using namespace std;
//https://owlcation.com/stem/How-to-work-with-Multidimensional-Array-in-C-Programming`
/*
1. Naudoti C++ bibliotekas. 
   Programuoti, sudarant klase ir objektus.
   Sukurti dinamini tridimensini masyva (5*5*5 nariu,i,j,k),
   užpildyti ji skaiciais pagal funkcija: f(i,j,k)=i*100+j*10+k. 
   Atspausdinti gautaji masyva i faila. 
   Prieš programai pasibaigiant, sunaikinti ši masyva. 
*/   


class ThreeDimMatrix
{

private:
    
    int CalculationValue();

public:
	ThreeDimMatrix();
	void WriteDataToFile(string);
}; 
// =========================================================


ThreeDimMatrix::ThreeDimMatrix()
{    
}
// =========================================================
int ThreeDimMatrix::CalculationValue()
{
    int i = rand() % 10;
    int j = rand() % 10;
    int k = rand() % 10;
    
    int f = i*100+j*10+k;
    
    return f;

}

// =========================================================

void ThreeDimMatrix::WriteDataToFile(string FileName)
{
    
  int ***arr=NULL;
  arr=new int**[5];

    for(int i=0;i<5;i++)
    {
        arr[i] = new int*[5];  
    
        for(int j=0;j<5;j++)
        {
            arr[i][j]=new int[5]; 
    
            for(int k=0;k<5;k++)
            {
                arr[i][j][k]=i+j+k; 
            }
        }
    }
       
        
    srand (time(NULL));
    
    cout<<"Generating three dimensional matrix..."<<endl<<endl;
    
    ofstream outputFile(FileName.c_str());
    
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<5;j++)
        {
            
             for (int k=0;k<5;k++)
             {   
                 arr[i][j][k] = CalculationValue();
                 outputFile <<arr[i][j][k]<<" ";
                 cout<<arr[i][j][k]<<" ";
                      
             }
             
             cout<<endl;
             outputFile<<endl;

        }
        
        
        cout<<endl<<endl;
        outputFile<<endl<<endl;
        
                
    }
    
    outputFile.close();
    cout<<"Output file '"<<FileName<<".txt' was created in the same directory."<<endl;
    
    cout << endl <<"Clean up three dimensional matrix." << endl;

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            delete[] arr[i][j];   
        }
        delete[] arr[i];
    }
    delete arr;
   
            
   
}
// =========================================================
int main(int argc, char *argv[])
{
    ThreeDimMatrix mx;
         mx.WriteDataToFile("OuputFile.txt");
         
    cout<<"Program was stopped."<<endl;

	system("pause");
    return EXIT_SUCCESS;    
	
}

