#include <cstdlib>
#include <iostream>

using namespace std;

class LAIKAS
{
private:
    int iVal;
    int iMin;
    int iSek;
public:
    LAIKAS();       // 1-asis kontruktorius
    LAIKAS(int i);  // 2-asis kontruktorius    
    void show();    // metodas
    void input_1(); // metodas  
    void input_2(int iV, int iM, int iS); // metodas   
}; // end class LAIKAS
// ================================================
LAIKAS::LAIKAS()     // kontruktorius
{
    iVal = 10;
    iMin = 11;
    iSek =  0;
} 
// ================================================
LAIKAS::LAIKAS(int i)     // kontruktorius
{
    iVal = i;
    iMin = i;
    iSek = i;
} 
// ================================================
void LAIKAS::input_1()  // metodas  
{
    cout << "Kiek valandu ? "; cin >> iVal;
    cout << "Kiek minuciu ? "; cin >> iMin; 
    iSek = 0;   
} 
// ================================================
void LAIKAS::input_2(int iV, int iM, int iS)  // metodas  
{
    iVal = iV;
    iMin = iM;
    iSek = iS;
}  
// ================================================
void LAIKAS::show() 
{
   cout << iVal << " : " << iMin << " : " << iSek << endl << endl;
}
// ================================================
int main(int argc, char *argv[])
{
    LAIKAS mano_skubantis_laikas;
    
           mano_skubantis_laikas.show();    system("pause");
 
           mano_skubantis_laikas.input_1();  
           mano_skubantis_laikas.show();    system("pause"); 
           
           mano_skubantis_laikas.input_2(16,20,22);  
           mano_skubantis_laikas.show();    system("pause"); 
           
    LAIKAS mano_atpalaiduojantis_laikas(3); 
           mano_atpalaiduojantis_laikas.show();    system("pause");            
     
    return EXIT_SUCCESS;
}
