#include <cstdlib>
#include <iostream>

using namespace std;

class KUBAS
{
private:
    int iBriaunosIlgis;
    int iTuris; 
    int iPlotas;  
    void turis();
    void pavirsiaus_plotas();    
         
public:
    KUBAS();
    void briauna();

    void show();
    void a3a2();     
}; // end class KUBAS
// =========================================================
KUBAS::KUBAS() // konstruktorius
{
    iBriaunosIlgis = 0;
    iTuris         = 0; 
    iPlotas        = 0; 
}
// =========================================================
void KUBAS::briauna()
{
    int iBr;
    
darkarta:
    cout << "Briaunos ilgis : "; cin >> iBr;
    if      (iBr >= 0) iBriaunosIlgis = iBr;
    else if (iBr <  0) 
    {
        cout << iBr << " < 0 ...  :( Turi buti teigiamas !\n";
        system("pause"); goto darkarta;
    }
}
// =========================================================
void KUBAS::turis()
{
    iTuris = iBriaunosIlgis * iBriaunosIlgis * iBriaunosIlgis;
}
// =========================================================
void KUBAS::pavirsiaus_plotas()
{
    iPlotas = 6 * iBriaunosIlgis * iBriaunosIlgis;
}
// =========================================================
void KUBAS::a3a2()
{
    turis();
    pavirsiaus_plotas();
}
// =========================================================
void KUBAS::show()
{
    cout << " KUBAS : briaunos ilgis = " << iBriaunosIlgis << endl;
    cout << "             Kubo turis = " << iTuris         << endl; 
    cout << " Kubo pavirsiaus plotas = " << iPlotas        << endl << endl;        
}
// =========================================================
int main(int argc, char *argv[])
{
    KUBAS figura;
          figura.show(); 
    
          figura.briauna();
          figura.a3a2();
          figura.show();  
                            
    system("pause");
    return EXIT_SUCCESS;
}
