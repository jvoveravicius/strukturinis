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
Programuoti, sudarant klase ir objektus.
Parasyti programa, kuri skaiciuotu piramides turi ir paviršiaus plota.
Vartotojas paklausiamas per dialoga ivesti pirmides krastines ilgi ir piramides aukšti. 
*/


/*
kadangi salygoje nenurodytos piramides detales, darau prielaida, jog tai yra taisyklinga keturkampe piramide. 
taipogi programoje prasau ivesti piramides pagrindo krastines ilgi.
*/


class Pyramid
{

private:
	
	bool dataCheckUI(string);//metodas skirtas nustatyti ar ivesti duomenys teisingi
	string * UI(); //ui vartotojui
	double turis(double, double); //apskaiciuoja turi, grazina pagrindo plota tam, kad po to skaiciuoti pavirsiaus plota
	double pavPlotas(double, double, double);//apskaiciuoja ir grazina pavirsiaus plota
             
public:
	Pyramid(); // konstruktorius
	void results(); //rezultatai
		
}; 
// =========================================================


Pyramid::Pyramid()
{
    
    string * array = UI();//patikrina ivesties duomenu validuma
	
		
	if (array[0]!="*") //jeigu UI funkcija, grazina char '*', tada vartotojo ivesti duomenys yra neteisingi
	{
	
		double i = atoi(array[0].c_str() ); //grazina patikrinta ilgi
		double h = atoi(array[1].c_str() ); //grazina patikrinta aukstine
	
		double sPagr = turis(i, h);
		cout<<"Piramides pavirsiaus plotas yra: "<<pavPlotas(sPagr, i, h)<<" cm2"<<endl;
		

	}
	else
	{
		
		cout<<"Programa uzdaryta."<<endl;
	}

    
}
// =========================================================

string *Pyramid::UI()
{

	repeat:
		
		
	string *array = new string[2];

	
	cout<<"Iveskite taisyklingos keturkampes piramides pagrindo krastines ilgi centimetrais: ";	cin>>array[0];
	bool checkSide = dataCheckUI(array[0]);
	
	cout<<"Iveskite taisyklingos keturkampes piramides aukstine centimetrais: ";cin>>array[1];
	cout<<endl;
	
	bool checkHeight = dataCheckUI(array[1]);
	
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
 double Pyramid::turis(double i, double h)//i - ilgis, h aukstine
{
	/*
	formule turiui nustatyti:
	http://www.mat.lt/matematikos-formules/erdvines-figuros/taisyklingosios-piramides-turis.html
	*/
		
	double sPagr = pow(i,2);//apskaiciuoju pirmides pagrindo plota
	cout<<"Piramides pagrindo plotas: "<<sPagr<<" cm2"<<endl;
	double V = (1.0/3) * sPagr * h; // apskaiciuoju piramides turi
	cout<<"Piramides turis: "<<V<<" cm2"<<endl;
	
	return sPagr;//grazinu pagrindo plota tam, kad kitame metode apskaiciuoti piramides pavirsiaus plota
	
}

// =========================================================
 double Pyramid::pavPlotas(double sPagr, double i, double h)//sPagr, i - ilgis, h - aukstine 
{
	//sustojau cia!!!
	
	double ip = i / 2; //piramides pagrindo ilgi dalinu pusiau
	/*
	pritaikau pitagoro teorema, nustatyti apotema.
	*/	
	double c = pow(ip,2) + pow(h,2);
	double apotema = sqrt(c);
	cout<<"Piramides apotema: "<<apotema<<" cm"<<endl;
	
	/*
	formule sonininiam piramides pavirsio plotui nustatyti:
	http://www.mat.lt/matematikos-formules/erdvines-figuros/taisyklingosios-piramides-soninio-pavirsiaus-plotas.html
	*/
	
	double pagrindoPerimetras = i * 4;//gaunu pagrindo perimetra
	double sSonas = (1.0/2) * pagrindoPerimetras * apotema;//formule
	cout<<"Piramides soninio pavirsiaus plotas: "<<sSonas<<" cm2"<<endl;
	//ieskome piramides šoninio paviršiaus plot	
	
	double all = sPagr + sSonas; // sudedame pagrinda ir sonanini plota, gauname viso pavirsiaus plota 
	return all;
}

// =========================================================


bool Pyramid::dataCheckUI(string value)
{
	
	//metoodas grazina false, jeigu ivedamos raides, arba skaicius kuris x<=0, nes priesingu atveju butu nelogiska
	
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
	
	system("pause");
    return EXIT_SUCCESS;    
	
}

