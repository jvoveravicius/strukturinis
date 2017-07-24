#include <cstdlib>
#include <iostream>

using namespace std;

class ZOLE
{
private:
    int **iMatrica;
    int iStulpeliuSkaicius;
    int   iEiluciuSkaicius;
    char cTipas;
public:
    ZOLE(char a);
    ZOLE(char a, int iStul, int iEil);   
    void input();
    void show();
    void sumuojame(ZOLE &A, ZOLE &B);
    void    kopija(ZOLE &A);       
};
// =========================================================
ZOLE::ZOLE(char a){} 
// ========================================================= 
ZOLE::ZOLE(char a, int iStul, int iEil)
{
    cout << "2D masyvas = " << a << " = stulpeliu skaicius = " << iStul << endl;
    cout << "2D masyvas = " << a << " =   eiluciu skaicius = " << iEil  << endl; 
    iStulpeliuSkaicius = iStul;
    iEiluciuSkaicius   = iEil;  
    cTipas = a; 
    
    // 2D masyvo alokacija
    iMatrica = new int*[iEiluciuSkaicius+1];
    for (int i=1; i<=iEiluciuSkaicius; i++)
        iMatrica[i] = new int[iStulpeliuSkaicius+1];
    
    // 2D masyvo isnulinimas    
    for (int i=1; i<=iEiluciuSkaicius; i++)
    {
        for (int j=1; j<=iStulpeliuSkaicius; j++)
        {
            iMatrica[i][j] = 0;
        }
    }     
}
// =========================================================     
void ZOLE::input()
{
    int ia;
    cout << cTipas << " matricos ivedimas\n";
    for (int i=1; i<=iEiluciuSkaicius; i++)
    {
        cout << i << " eilute : ";
        for (int j=1; j<=iStulpeliuSkaicius; j++)
        {
            cin >> ia; iMatrica[i][j] = ia;
        }
    }
} 
// ========================================================= 
void ZOLE::show()
{
    cout << cTipas << " matricos isvedimas\n";
    for (int i=1; i<=iEiluciuSkaicius; i++)
    {
        for (int j=1; j<=iStulpeliuSkaicius; j++)
        {
            cout << iMatrica[i][j] << "  ";
        }
        cout << endl;
    }
}
// =========================================================  
void ZOLE::kopija(ZOLE &A)
{
    cout << "Matricu kopijavimas: " 
         << cTipas << " = " << A.cTipas << "\n";
         
    for (int i=1; i<=iEiluciuSkaicius; i++)
    {
        for (int j=1; j<=iStulpeliuSkaicius; j++)
        {
            iMatrica[i][j] = A.iMatrica[i][j];
        }
    }
}
// =========================================================  
void ZOLE::sumuojame(ZOLE &A, ZOLE &B) 
{
    cout << "Matricu sumavimas: " 
         << cTipas << " = " << A.cTipas << " + " << B.cTipas << "\n";
         
    for (int i=1; i<=iEiluciuSkaicius; i++)
    {
        for (int j=1; j<=iStulpeliuSkaicius; j++)
        {
            iMatrica[i][j] = A.iMatrica[i][j] +
                             B.iMatrica[i][j];
        }
    }
}   
// =========================================================
int main(int argc, char *argv[])
{
    // stul, eil
    ZOLE ponasLinksmutis('A',4,3),  // 1 matrica , demuo
                kalvados('B',4,3),  // 2 matrica , demuo
          ponasLiudnutis('C',4,3),  // 3 matrica , suma
               rosinante('D',4,3);  // kopija
         
         ponasLinksmutis.input();
         kalvados.input();
         rosinante.kopija(kalvados);

         ponasLiudnutis.sumuojame(ponasLinksmutis,kalvados);
         
         ponasLinksmutis.show();
                kalvados.show();
          ponasLiudnutis.show();
               rosinante.show();

    system("pause");
    return EXIT_SUCCESS;
}
