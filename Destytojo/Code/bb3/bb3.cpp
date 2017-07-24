#include <cstdlib>
#include <iostream>

using namespace std;

class SACHOPANSA
{
private:
   int   ***iKubas; 
   int iStulpeliuSkaicius;
   int   iEiluciuSkaicius;        
   int iSluoksniuSkaicius;  
public:
   SACHOPANSA();  // konstruktorius
   void input();
   void show();    
}; //end class SACHOPANSA
// ==================================
SACHOPANSA::SACHOPANSA() // konstruktorius
{
    cout << "3D masyvas\n ";
    cout << "Kiek sluoksniu ? "; cin >> iSluoksniuSkaicius;
    cout << "Kiek stulpeliu ? "; cin >> iStulpeliuSkaicius;    
    cout << "Kiek   eiluciu ? "; cin >> iEiluciuSkaicius; 
    
    // 3D alokacija
    iKubas = new int**[iSluoksniuSkaicius+1];      //  1
    
    for (int i=0; i<=iSluoksniuSkaicius; i++)      //  2
        iKubas[i] = new int*[iEiluciuSkaicius+1];  
        
    for (int i=0; i<=iSluoksniuSkaicius; i++)      //  3
    {
        for (int j=0; j<=iEiluciuSkaicius; j++)
        {
            iKubas[i][j] = new int[iStulpeliuSkaicius+1]; 
        }
    }
    
    // 3D isnulinimas
    for (int i=0; i<=iSluoksniuSkaicius; i++)      //  3
    {
        for (int j=0; j<=iEiluciuSkaicius; j++)
        {
            for (int k=0; k<=iStulpeliuSkaicius; k++)
            {
                iKubas[i][j][k] = 0; 
            }   
        }
    }        
}
// ==================================
void SACHOPANSA::input()
{
    
}
// ==================================
void SACHOPANSA::show()
{
    cout << "3D masyvo isvedimas\n";
    for (int i=1; i<=iSluoksniuSkaicius; i++)      //  3
    {
        cout << i << " sluoksnis\n";
        for (int j=1; j<=iEiluciuSkaicius; j++)
        {
            for (int k=1; k<=iStulpeliuSkaicius; k++)
            {
                cout << iKubas[i][j][k] << "  "; 
            } 
            cout << endl;  
        }
    }        
}
// ==================================  
int main(int argc, char *argv[])
{
    SACHOPANSA rosinante;
               rosinante.show();
    system("pause");
    return EXIT_SUCCESS;
}
