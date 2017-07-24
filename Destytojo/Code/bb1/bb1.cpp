#include <cstdlib>
#include <iostream>

using namespace std;

class OBUOLYS
{
private:
    int   *iElena;
    int    nSkaicius;
public:  
    OBUOLYS();         // 1 konstr
    OBUOLYS(int ijk);  // 2 konstr
    void input();
    void show();  
};// end class OBUOLYS
// ====================================
OBUOLYS::OBUOLYS() // 1 konstr
{
darkarta:
    cout << "1D masyvas : kiek nariu ? ";
    cin >> nSkaicius;
    if (nSkaicius <=0)
    {
        cout << nSkaicius << " <=0 ... :(\n"; 
        goto darkarta;
    }
    iElena = new int[nSkaicius+1];
}
// ====================================
OBUOLYS::OBUOLYS(int ijk)// 2 konstr
{
    cout << "1D masyvas, fiksuotas nariu skaicius = " << ijk << endl;
    nSkaicius = ijk;
    iElena = new int[nSkaicius+1];
}
// ====================================
void OBUOLYS::input()
{
    int ia;
    cout << "1D masyvo ivedimas\n";
    for (int i=1; i<=nSkaicius; i++)
    {
        cout << i << "-narys : "; cin >> ia; 
        iElena[i] =ia;
    }
}
// ====================================
void OBUOLYS::show()
{
    cout << "1D masyvo isvedimas\n";
    for (int i=1; i<=nSkaicius; i++)
    {
        cout << i <<  " "; cout << iElena[i] << endl;
    }
    cout << "**********************************************\n";
} 
// ====================================
int main(int argc, char *argv[])
{
    OBUOLYS grenismith;
            grenismith.input();
            grenismith.show();

    OBUOLYS jonagold(12);
            jonagold.input();
            jonagold.show();
            
    system("pause");
    return EXIT_SUCCESS;
}
