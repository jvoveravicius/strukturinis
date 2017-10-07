#include <cstdlib>
#include <inttypes.h>
#include <sstream>
#include <string>
#include <time.h> 
#include <iostream>
#include <fstream>
#include<cmath>

using namespace std;

/*
 Naudoti C++ bibliotekas. 
Programuoti, sudarant klase ir objektus.
Parasyti programa, kuri skaiciuotu piramides turi ir paviršiaus plota.
Vartotojas paklausiamas per dialoga ivesti pirmides krastines ilgi ir piramides aukšti. 
*/


class Pyramid
{

private:
	bool dataCheckUI(string);
	string * UI();
	double turis(double, double);
	double pavPlotas(double, double, double);
             
public:
	Pyramid();
	void results();
	
}; 
// =========================================================


Pyramid::Pyramid() // konstruktorius
{

}

// =========================================================
void Pyramid::results()
{
	
	Pyramid py;
	
	string * array = py.UI();
	
		
	if (array[0]!="*")
	{
	
		double i = atoi(array[0].c_str() ); //ilgis
		double h = atoi(array[1].c_str() ); //aukstine
	
		double sPagr = py.turis(i, h);	
		cout<<"Pavirsiaus plotas yra: "<<py.pavPlotas(sPagr, i, h)<<endl;
		

	}
	else
	{
		
		cout<<"Programa uzdaryta."<<endl;
	}


	
}
// =========================================================

string *Pyramid::UI()
{
	Pyramid py;
	
	repeat:
		
	string *array = new string[2];
	
	cout<<"Iveskite taisyklingos piramides ilgi: ";	cin>>array[0];
	bool checkSide = py.dataCheckUI(array[0]);
	
	
	cout<<"Iveskite taisyklingos piramides auksti: ";cin>>array[1];
	cout<<endl;
	
	bool checkHeight = py.dataCheckUI(array[1]);
	
	if (checkSide || checkHeight)
	{
		
		IncorrectAnsw:
		char answ;
		cout<<"Ivesti neteisingi duomenys.";
		cout<<"Ar norite pakartoti t/n? "; cin>>answ;
		
		if (answ=='t'){goto repeat;}else if(answ=='n'){array[0]="*";}
		else{cout<<"Neteisingas atsakymas, pasirinkite t[taip] arba n[ne]."<<endl; goto IncorrectAnsw;}
		
		
	}
	
	
	return array;


	
}
// =========================================================


// =========================================================s
 double Pyramid::turis(double i, double h)
{
	/*
	references:
	https://www.youtube.com/watch?v=VsOla5pas5k
	http://www.mat.lt/matematikos-formules/erdvines-figuros/taisyklingosios-piramides-turis.html
	*/
	
	Pyramid py;
	
		
	double sPagr = pow(i,2);//pagrindo plotas
	cout<<"Piramides pagrindo plotas: "<<sPagr<<"cm2"<<endl;
	double V = 0;//turis

	V  = (1.0/3) * sPagr * h;
	
	cout<<"Piramides turis: "<<V<<"cm2"<<endl;
	
	return sPagr;


	
}

// =========================================================
 double Pyramid::pavPlotas(double sPagr, double i, double h)//sPagr, i - ilgis, h - aukstine 
{
	/*
	references:
	http://www.mat.lt/matematikos-formules/erdvines-figuros.html
	
	*/
	
	//double s = sPagr + sSonas
	
	cout<<"pavPlotas()"<<endl;
	
	
	//ieskome apotema
	
	double ilgisPusiau = i / 2;
	cout<<"Ilgi daliname pusiau: "<<ilgisPusiau<<endl;
	double c = pow(ilgisPusiau,2) + pow(h,2);
	double apotema = sqrt(c);
	
	cout<<"Tmp result: "<<c<<endl;
	cout<<"Apotema: "<<apotema<<endl;
	
	
	//ieskome piramides šoninio paviršiaus plota
	double pagrindoPerimetras = i * 4;
	double sSonas = (1.0/2) * pagrindoPerimetras * apotema;
	cout<<"Soninio pavirsiaus plotas: "<<sSonas<<endl;
	//ieskome piramides šoninio paviršiaus plota
	
	double viskas = sPagr + sSonas;
	
	return viskas;
}

// =========================================================


bool Pyramid::dataCheckUI(string value)
{
	
	bool result = false;

	for (int i=0;i<value.length();i++)
	{
			
		if (isalpha(value[i]))
		{
		

			result = true;
		

		}
		else
		{
						
			if (atoi(value.c_str())<=0)
			{
			
				result = true;
			
				
			}
		}
		
	}

	
	return result;

}



// =========================================================




int main(int argc, char *argv[])
{
	
	Pyramid py;
	
	py.results();

 
    system("pause");
    return EXIT_SUCCESS;
}

