
#include <iostream>
#include"funkcje.hh"
using namespace std; 

int main(int argc, char ** argv)
{
    int kwant_czasu = 1;
    int ilosc_procesorow = 1;
    if ((argc <= 4) && (argc > 1))
    {
        int strategia = atoi(argv[1]);
        if (argc == 4)
        {   

            ilosc_procesorow = atoi(argv[2]);
            kwant_czasu = atoi(argv[3]);

        }
        if (argc == 3)
        {
            ilosc_procesorow = atoi(argv[2]);
        }
        if ((ilosc_procesorow < 0)||(kwant_czasu < 0))
        {
            cout << "DRUGI I TRZECI ARGUMENT - LICZBA > 0" << endl;
            return 0;
        }
        if ((strategia >= 0) && (strategia <= 6))
        {
            wczytaj(strategia, ilosc_procesorow, kwant_czasu);
        }
        else
        {
            cout << "PIERWSZY ARGUMENT - LICZBA W ZAKRSIE [0,6]" << endl;
        }
    }
    else
    {
        cout << "NALEŻT UŻYĆ OD 1 DO 3 ARGUMENTÓW" << endl;
    }
    return 0;
}