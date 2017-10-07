#include <cstdlib>
#include <inttypes.h>
#include <sstream>
#include <string>
#include <time.h> 
#include <iostream>
#include <fstream>

using namespace std;

//UI skirtas tam
//Ilgalaikis taupymas

//Trumpalaikiai tikslai: auto, dvi keliones per metus, baldai

class UI
{

private:
	void UIMainObjects();
	void UIMainSalary();	
             
public:
	UI();
	void UIMain();
	
}; // end class UI
// =========================================================

class DATA
{

public:
	DATA();
	void Write(string FileName, string data[], short length);
	bool Check(string FileName);
	string *Read(string FileName);

	void WriteObjectDataFormat(string FileName);
	void AnalizeObjectData(string FileName);
	
	void WriteSalaryDataFormat(string FileName);//need to write
	void AnalizeSalaryData(string FileName);//need to write
    
}; // end class DATA
// =========================================================
class CALC
{

public:
	CALC();
	void Sum(int Money, int TimeFrame);
	    
}; 
// =========================================================
// =========================================================
// =========================================================
UI::UI() // konstruktorius
{
}
// =========================================================
DATA::DATA() // konstruktorius
{
}
// =========================================================
CALC::CALC() // konstruktorius
{
}
// =========================================================
// =========================================================
// =========================================================

void CALC::Sum(int Money, int TimeFrame)
{

	
    for (int n = 1; n < TimeFrame+1; n++) {
        
        cout<<"Month: "<<n<<" Tot: "<<Money*n<<endl;
        
    }
}
	



void UI::UIMain(){
	
	DATA DataMain;
	
	char iv;

	start:
	
	cout<<"MAIN MENU: "<<endl<<endl; cout<<"Objects[o]"<<endl;cout<<"Salary[s]"<<endl; cout<<"Exit[e]"<<endl<<endl;	
	cout<<"Ivesti: "; cin>>iv;


	
	switch(iv) {
		case 'o':
			DataMain.AnalizeObjectData("Obj.txt");
			goto start;
			break;
				        
	    case 's' :
			DataMain.AnalizeSalaryData("Salary.txt");
	    	break;
	        
	    case 'e' :
			break;

	    default :
	    	goto start;
	    	
   }
	
	
	
	
}
// =========================================================
void UI::UIMainObjects(){
	
	char iv;

	start:
	cout<<endl<<endl;
	cout<<"OBJECTS MENU: "<<endl<<endl; cout<<"Add[a]"<<endl;cout<<"Remove[r]"<<endl; cout<<"Exit[e]"<<endl<<endl;	
	cout<<"Ivesti: "; cin>>iv;
	
	/*
	
	cia turi buti isvesti jau ivesti duomeny
	
	
	*/
	
	switch(iv) {
		case 'a':
			
	        goto start;
	        
	    case 'r' :

	        goto start;
	        
	    case 'e' :
	    	UIMain();
	    	break;

	    default :
	    	goto start;
	    	
   }
	
	
	
	
}
// =========================================================
void UI::UIMainSalary(){
	
	char iv;

	start:
	cout<<endl<<endl;
	cout<<"SALRY MENU: "<<endl<<endl; cout<<"Modify[m]"<<endl;cout<<"Exit[e]"<<endl<<endl;	
	cout<<"Ivesti: "; cin>>iv;
	
	/*
	
	cia turi buti isvesti jau ivesti duomeny
	
	
	*/
	
	switch(iv) {
		case 'a':
			
	        goto start;
	        
	    case 'r' :

	        goto start;
	        
	    case 'e' :
	    	UIMain();
	    	break;

	    default :
	    	goto start;
	    	
   }
	
	
	
	
}
// =========================================================
// =========================================================
// =========================================================

void DATA:: Write(string FileName, string data[], short length)
{

	ofstream outputFile(FileName.c_str());

	cout<<"Writting data.."<<endl;

    for(int i = 0; i < length; ++i)
    {
    	
        outputFile <<data[i]<<endl;
        
    }

    outputFile.close();
    
 
}

// =========================================================
bool DATA::Check(string FileName)
{
	bool returningValue = false;
	
	ifstream my_file(FileName.c_str());
	
	if (my_file)
	{
		
		returningValue = true;
		
	}

	
	return returningValue;
		
}

void DATA::AnalizeObjectData(string FileName)
{
	rep_CancelC:
	rep_AddObject:
		
	string * array = Read("Obj.txt"); 
	
	string SeparateElement;
	string Name[1000], Money[1000], Period[1000];
	unsigned int Total[1000];
	unsigned short ArrayIt = 0;
	unsigned short WriteIt = 0;
	unsigned short toShort = atoi(array[0].c_str());
	
	CALC CalcMain;
	
	bool stop = false;//stabdome pagrindini cikla
	unsigned short z = 0;
		


	cout<<"Analizing data..."<<endl;
	for(int i=1;i<toShort;i++)
	{ 

		SeparateElement = array[i];
		


		do
		{
			
			if (SeparateElement[z]=='$')
			{
				
				ArrayIt++; // incrementiname pagrindini array iteratoriu
				stop = true;

			
			}
			else if (SeparateElement[z]=='#')
			{
				
			
				WriteIt++;
		
				

			}
			else
			{
			
	
				
				if (WriteIt==0)
				{
					Name[ArrayIt] =  Name[ArrayIt] + SeparateElement[z];

				}
				else if (WriteIt==1)
				{
					Money[ArrayIt]	= Money[ArrayIt] + SeparateElement[z];
		
				}
				else if (WriteIt==2)
				{
					Period[ArrayIt] = Period[ArrayIt] + SeparateElement[z];	
			
				}
				

			}
			
			
			z++;
			
			
		}while(stop==false);
		
		stop = false;
		WriteIt = 0;
		z = 0;
		
			
	}
	

	
	for (int i=0;i<ArrayIt;i++)
	{
		
		
		
		Total[i] = atoi(Money[i].c_str()) * atoi(Period[i].c_str());
		cout<<"NB: "<<i+1<<" OBJ: "<<Name[i]<<" MON: "<<Money[i]<<" PER: "<<Period[i]<<" TOT: "<<Total[i]<<endl;
	}
	
	cout<<endl;
	unsigned short ChooseObj;	
	
	
	//1
	cout<<"ACTIONS: "<<endl<<endl;
	cout<<"Add object[0]"<<endl; cout<<"Observe [1 to "<<ArrayIt<<"]"<<endl; cout<<"Exit[100]"<<endl<<endl;
	cout<<"Choose: "; cin>>ChooseObj;
	
	
	if (ChooseObj==0)
	{
		WriteObjectDataFormat("Obj.txt");
		goto rep_AddObject;
	}
	else if (ChooseObj==100){return;};
	
	
	//2
	cout<<endl<<endl;
	cout<<"Nb.: "<<ChooseObj<<" OBJ: "<<Name[ChooseObj-1]<<" MON: "<<Money[ChooseObj-1]<<" PER: "<<Period[ChooseObj-1]<<" TOT: "<<Total[ChooseObj-1]<<endl;
	
	cout<<endl<<endl;
	cout<<"ACTIONS: "<<endl; cout<<"Observe details[o]"<<endl; cout<<"Delete object[d]"<<endl;
	cout<<"Cancel[c]"<<endl;
	
	char Action;
	cout<<"Choose action: ";cin>>Action;
	
	if(Action=='o')
	{
		
		CalcMain.Sum(atoi(Money[ChooseObj-1].c_str()), atoi(Period[ChooseObj-1].c_str()));
		goto rep_CancelC;
		
	}
	else if (Action=='d')
	{
		
		char confirmation;
		cout<<"Are you sure you want to delete this object? y/n "; cin>>confirmation;
		
		if (confirmation=='y')
		{
			
			for (int i=ChooseObj-1;i<ArrayIt;++i)
			{
				
				Name[i] = Name[i+1];
				Money[i] = Money[i+1];
				Period[i] = Period[i+1];
				
				
			}
			
			string dataOverwriten[1000];
			
			for (int h=0;h<ArrayIt-1;h++)
			{
				
				dataOverwriten[h] = Name[h]+"#"+Money[h]+"#"+Period[h]+"$";
					
			}
			
			Write(FileName, dataOverwriten, ArrayIt-1);
			goto rep_CancelC;
			
	
		}
		else if (confirmation=='n')
		{
			goto rep_CancelC;	
		}
		
		
		
	}
	else if (Action=='c')
	{
		goto rep_CancelC;
	}


	
}


void DATA::AnalizeSalaryData(string FileName)
{
	
	UI UIMain;

	
	RepeatAll:

		
	string * array = Read(FileName); 
	
	string SeparateElement;
	string Salary;
	string Expense[1000], Reason[1000];
	unsigned int Total[1000];
	short ArrayIt = -1;
	unsigned short WriteIt = 0;
	unsigned short toShort = atoi(array[0].c_str());
	
	CALC CalcMain;
	
	bool stop = false;//stabdome pagrindini cikla
	unsigned short z = 0;
		


	cout<<"Analizing data..."<<endl;
	for(int i=1;i<toShort;i++)
	{ 

		SeparateElement = array[i];
		


		do
		{
			
			if (SeparateElement[z]=='$')
			{
				
				ArrayIt++; // incrementiname pagrindini array iteratoriu
				stop = true;

			
			}
			else if (SeparateElement[z]=='#')
			{
				
			
				WriteIt++;
		
				

			}
			else
			{
				
				if (ArrayIt==-1)
				{
					Salary = Salary + SeparateElement[z];
					
				}
				else
				{
					
					if (WriteIt==0)
					{
						Reason[ArrayIt] =  Reason[ArrayIt] + SeparateElement[z];
	
					}
					else if (WriteIt==1)
					{
						Expense[ArrayIt] = Expense[ArrayIt] + SeparateElement[z];
			
					}	
	
				}


			}
			
			
			z++;
			
			
		}while(stop==false);
		
		stop = false;
		WriteIt = 0;
		z = 0;

			
	}
	
	
	unsigned int SalaryToInt = atoi(Salary.c_str());
	int Result = SalaryToInt;
	
	cout<<"Salary: "<<SalaryToInt<<endl<<endl;
	

	
	for (int i=0;i<ArrayIt;i++)
	{
		
		Result = Result - atoi(Expense[i].c_str());
		cout<<""<<Expense[i]<<" Reason: "<<Reason[i]<<" Remain: "<<Result<<endl;
		
	}
	
	
	if(Result>0)
	{
		cout<<endl<<"Remained: "<<Result<<endl;
	}
	else
	{
		cout<<endl<<"WARNING!!! Remained: "<<Result<<endl<<endl;
	}
	
	
	char opt;
	
	cout<<"Would you like to change data? y/n "; cin>>opt;

	if (opt=='y')
	{
		WriteSalaryDataFormat(FileName);
		cout<<endl;
		goto RepeatAll;
			
	}
	else if (opt=='n')
	{
		
		UIMain.UIMain();
		
	}
	

}
string *DATA::Read(string FileName)
{
	string line;	
	string *array = new string[1000];
	
	
	ifstream myfile (FileName.c_str());
	
	
	bool CheckFile = Check(FileName);
	
	
	
	if (!CheckFile)
	{
		
		cout<<"File does not exists"<<endl;
		
		
	}
	else
	{
		
		if (myfile.is_open())
		{
			
			unsigned short tmpit = 0;
		
			while (getline (myfile,line) )
			{
						
				array[tmpit+1] = line;	
				//cout<<"Result: "<<array[tmpit+1]<<endl;
				tmpit++;
				
			}
			
			
			//int to string
			stringstream ss;
			ss << tmpit+1;
			string str = ss.str();
			
			array[0] = str;
			
  		}
  		
  		
  	
	}
	
	return array;

}
// =========================================================
void DATA::WriteObjectDataFormat(string FileName)
{
	

	string Final[1000];
	
	char LoopControl = 'a';
	
	string Name;
	string Money;
	string Period;
	
	unsigned short tmpIt = 0;
	
	do
	{
		
		cout<<"Name: ";cin>>Name; cout<<"Money: "; cin>>Money; cout<<"Period: "; cin>>Period;
		Final[tmpIt] = Name+"#"+Money+"#"+Period+"$";
		
		
		checAgain:
		cout<<"Would you like to add additional object? y/n "; cin>>LoopControl;
		
				
		
		
		//ar reikia ivesti papildomo simoliaus
		if (LoopControl!='y' && LoopControl!='n')
		{
			
			cout<<"Incorrect data was entered: "<<LoopControl<<endl; goto checAgain;
			
		}
		else if (LoopControl=='y')
		{
			tmpIt++;
		}
		
	}while(LoopControl!='n');
	

	
	bool CheckFile = Check(FileName);
	
	if (!CheckFile)
	{
		cout<<"Creating new file.."<<endl;
		Write("Obj.txt",Final, tmpIt+1);	
	}
	else
	{
		
		string line;
		//unsigned short tmpItW = 0;
		
		ifstream myfile (FileName.c_str());
		
		if (myfile.is_open())
		{
			while ( getline (myfile,line) )
			{
				
				tmpIt++;
				Final[tmpIt] = line;
				
			}
			
			myfile.close();
			
  		}
		
		Write(FileName, Final, tmpIt+1);
		  	
	}
	
	
}
// =========================================================
void DATA::WriteSalaryDataFormat(string FileName)
{
	string Final[1000];
	
	char LoopControl = 'a';
	
	string Salary;
	string Expense;
	string Reason;
	
	unsigned short tmpIt = 0;
	
	do
	{
		if (tmpIt==0)
		{
			cout<<"Salary: ";cin>>Salary;
			Final[tmpIt]=Salary+"$";
			tmpIt++;
			continue;	
		}
		
		
		cout<<"Expense: ";cin>>Expense; cout<<"Reason: "; cin>>Reason;
		Final[tmpIt] = Reason+"#"+Expense+"$";
				
		checAgain:
		cout<<"Would you like to add additional expense? y/n "; cin>>LoopControl;

		
		//ar reikia ivesti papildomo simoliaus
		if (LoopControl!='y' && LoopControl!='n')
		{
			
			cout<<"Incorrect data was entered: "<<LoopControl<<endl; goto checAgain;
			
		}
		else if (LoopControl=='y')
		{
			tmpIt++;
		}
		
	}while(LoopControl!='n');
	
	Write(FileName,Final, tmpIt+1);	
	
	
	
}
// =========================================================

// =========================================================
// =========================================================
// =========================================================

int main(int argc, char *argv[])
{
	
	string test[100];
	
	
	UI UIMain;
	UIMain.UIMain();


 
    system("pause");
    return EXIT_SUCCESS;
}

