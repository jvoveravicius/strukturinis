#include <cstdlib>
#include <inttypes.h>
#include <sstream>
#include <string>
#include <time.h> 
#include <iostream>
#include <fstream>
#include<cmath>
#include <set>
#include <locale>

using namespace std;

/*
2. Naudoti konteineri <set> ir C++ bibliotekas. 
   Programuoti, sudarant klase ir objektus.
   Parašyti programa, kuri iš LIETUVIŠKO teksto (ivedimas iš failo)
   išrinktu, surušiuotu pagal abecele visus žodžius ir išvestu i faila.
*/   


class Text
{

private:
    int CountWordsInFile(string);
    string Checkpunct(string);
    
   
public:
   string *ReadDataFromFile(string);
   void SortAndWriteStringData(string);
	Text();
	
}; 
// =========================================================


Text::Text()
{    
   
}
// =========================================================
string *Text::ReadDataFromFile(string FileName)
{

    int AmWords = CountWordsInFile(FileName);

    string *InitialWords = new string[AmWords];
    string word;
    
    ifstream file;
  
    file.open (FileName.c_str());
    cout<<"Reading data.."<<endl;
      
    int i = 0;
    while (file >> word)
    {
        InitialWords[i] = word;
        i++;
    }
    
    file.close();
    
    return InitialWords;
     
}
// =========================================================
int Text::CountWordsInFile(string FileName)
{
    int i = 0;
    ifstream file;
    file.open (FileName.c_str());
    string word;    

    while (file >> word)
    {
        i++;
    }
    
    return i;

}

//=============================================================

void Text::SortAndWriteStringData(string FileName)
{
    
    
    string * InitialWords = ReadDataFromFile(FileName);
    int s = CountWordsInFile(FileName);
    
    string RemakeWords[s];
        
    
    
    for (int i=0;i<s;i++)
    {
        string TempWord = "";
        string finalTempWord = "";
        int z = 0;
        
        TempWord = InitialWords[i];
   
        do
        {
            if (!ispunct(TempWord[z]))
            {
               finalTempWord = finalTempWord + TempWord[z];
            }
            z++; 
        }while(z<TempWord.length()+1);
        
        RemakeWords[i] = finalTempWord;
 
    } 
    
    
    
    set<string> setOfTxt(RemakeWords, RemakeWords + sizeof(RemakeWords) / sizeof(RemakeWords[0]));
    
    ofstream outputFile("correction.txt");
    cout<<"Writting data.."<<endl;

	for (set<string>::iterator it=setOfTxt.begin(); it!=setOfTxt.end(); ++it)
	{
        
        outputFile <<*it<<endl;
    }
    
    outputFile.close();
    
    cout<<"Output file name: "<<FileName<<endl;
    

}
// =========================================================
int main(int argc, char *argv[])
{
    
    Text t;
    t.SortAndWriteStringData("read.txt");

    system("pause");
    return EXIT_SUCCESS;    
	
}

