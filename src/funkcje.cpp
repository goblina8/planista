#include "funkcje.hh"
#include "proces.hh"
#include "procesor.hh"
#include "strategia.hh"
#include "priority_queue.hh"
#include "proces.hh"

void dodaj_proces(prio_q* procesy,int strategia, int id, int pi, int ri)
{
    switch(strategia)
    {
        case 0:
        {
            strategia0(procesy, id, pi, ri);
            break;
        }
        case 1:
        {
            strategia1(procesy, id, pi, ri);
            break;
        }
        case 2:
        {
            strategia2(procesy, id, pi, ri);
            break;
        }
        case 3:
        {
            strategia3(procesy, id, pi, ri);
            break;
        }
        case 4:
        {
            strategia4(procesy, id, pi, ri);
            break;
        }
        case 5:
        {
            strategia5(procesy, id, pi, ri);
            break;
        }
        case 6:
        {
            strategia6(procesy, id, pi, ri);
            break;
        }
    }
}

void wczytaj(int strategia, int ilosc_procesorow, int kwant_czasu)
{
    int obecnie;
    prio_q procesy; //tworzy kolejke procesow
    procesor tab[ilosc_procesorow];
    for (int i = 0; i < ilosc_procesorow; i++) //tworzy odpowiednia liczbe procesorow
    {
        procesor p(i);
        tab[i] = p;
    }
    char linia[100];
    int obecny_czas = -1;
    int k = 0;
    fgets(linia,100,stdin);
    while(linia[0] != '\n') //dopoki nie ostatni wiersz pliku
    {
        int id;
        int pi;
        int ri;
        int x = 0;
        char czas[3];
        czas[0] = linia[0];
        if (linia[1] != ' ')
        {
            czas[1] = linia[1];
            x++;
            if (linia[2] != ' ')
            {
                x++;
                czas[2] = linia[2];
            }
        }  
        obecny_czas = atoi(czas); //pierwszy element linii to obecny czas
        for (int k = 1+x; k<400; k++)
        {
            if(linia[k] == '\n' || linia[k] == '\0')
            {   
                k = 400;
            }
            else if((linia[1] == ' ') && (linia[3] == ' ') && (linia[5] == ' '))
            {
                k++;
                if (linia[k] == '-')
                {
                    k++;
                    id = int(linia[k] - 48) * (-1);
                }
                else
                {
                    id = int(linia[k] - 48);
                }

                if (linia[k+2] == '-')
                {
                    k++;
                    pi = int(linia[k+2] - 48) * (-1);
                }
                else
                {
                    pi = int(linia[k+2] - 48);
                }

                if (linia[k+4] == '-')
                {
                    k++;
                    ri = int(linia[k+4] - 48) * (-1);
                }
                else
                {
                    ri = int(linia[k+4] - 48);
                }
                k = k+4;
                dodaj_proces(&procesy, strategia, id, pi, ri); //wstawia element do kolejki w zaleznosci od wybranej strategii
            }
        }
        obecnie = planuj(&procesy, tab, ilosc_procesorow, kwant_czasu, obecny_czas, strategia);
        cout << endl;
        fgets(linia,100,stdin);
    }
    int koniec = 1;
    while(koniec)
    {
        obecnie++;
        planuj(&procesy, tab, ilosc_procesorow, kwant_czasu, obecnie, strategia);
        if(procesy.get_e_numb() == 0)
        {
            int ilosc = 0;
            for (int i = 0; i < ilosc_procesorow; i++)
            {
                if(!(tab[i].is_it_working()))
                {
                    ilosc++;
                }
            }
            if(ilosc == ilosc_procesorow)
            {
                koniec = 0;
            }
        }
    }
}


int planuj(prio_q *procesy, procesor *tab, int ilosc_procesorow, int kwant_czasu, int obecny_czas, int strategia)
{
    int time;
    int id;
    int prio;
    for(int i = 0; i < ilosc_procesorow; i++)
    {
        if(tab[i].what_time() == 0)
        {
            tab[i].stop_working();
        }
        if (tab[i].is_it_working() == 1)
        {
            tab[i].one_tic();
            if(tab[i].what_time() == 0)
            {
                tab[i].stop_working();
                for (int g = i+1; g < ilosc_procesorow-i; g++)
                {
                    if((tab[g].is_it_working())&&(tab[g].what_time() != 1))
                    {
                        tab[i].start_working(tab[g].what_proces(), tab[g].what_time(), tab[g].what_prio());
                        tab[i].one_tic();
                        tab[g].stop_working(); 
                        g = ilosc_procesorow;
                    }
                }
                if(tab[i].is_it_working() == 0)
                {
                    if(procesy->get_e_numb() > 0)
                    {
                        time = procesy->max_time();
                        id = procesy->max_id();
                        prio = procesy->max_prio();
                        procesy->removeMax();
                        tab[i].start_working(id, time, prio);

                    }
                }
                
            }
        }
        else
        {
            if(procesy->get_e_numb() > 0)
            {
                time = procesy->max_time();
                id = procesy->max_id();
                prio = procesy->max_prio();
                procesy->removeMax();
                tab[i].start_working(id, time, prio);
            }
        }
        if ((strategia == 2)||(strategia == 3)||(strategia == 4)||(strategia == 5))
        {
            if ((tab[i].what_kwant()%kwant_czasu == 0)&&(tab[i].what_kwant() != 0))
            {
                wywlaszczanie(procesy, tab, ilosc_procesorow, kwant_czasu, strategia, i);
            }
        }
    }
    starter(ilosc_procesorow, tab);
    cout << obecny_czas << " ";
    for (int i = 0; i < ilosc_procesorow; i++)
    {
        cout << tab[i].what_proces() << "  ";
    }
    cout << endl;
    return obecny_czas;
}

void wywlaszczanie(prio_q *procesy, procesor* tab, int ilosc_procesorow, int kwant_czasu, int strategia, int g)
{
    switch(strategia)
    {
        case 2:
        {
            for (int i = 0; i < ilosc_procesorow; i++)
            {
                if(((tab[i].what_time() > procesy->max_time()+1))&&(procesy->get_e_numb() > 0))
                {
                    int time = procesy->max_time();
                    int id = procesy->max_id();
                    int prio = procesy->max_prio();
                    procesy->removeMax();
                    dodaj_proces(procesy, strategia, tab[i].what_proces(), tab[i].what_prio(), tab[i].what_time());
                    tab[i].start_working(id, time, prio);
                }
            }
            break;
        }
        case 3:
        {
            if(procesy->get_e_numb() > 0)
            {
                int time = procesy->max_time();
                int id = procesy->max_id();
                int prio = procesy->max_prio();
                procesy->removeMax();
                dodaj_proces(procesy, strategia, tab[g].what_proces(), tab[g].what_prio(), tab[g].what_time());
                tab[g].start_working(id, time, prio);
            }
            break;
        }
        case 4:
        {
            if(((tab[g].what_prio() > procesy->max_prio()))&&(procesy->get_e_numb() > 0))
            {
                int time = procesy->max_time();
                int id = procesy->max_id();
                int prio = procesy->max_prio();
                procesy->removeMax();
                dodaj_proces(procesy, strategia, tab[g].what_proces(), tab[g].what_prio(), tab[g].what_time());
                tab[g].start_working(id, time, prio);
            }
            break;
        }
        case 5:
        {
            if(((tab[g].what_prio() > procesy->max_prio()))&&(procesy->get_e_numb() > 0))
            {
                int time = procesy->max_time();
                int id = procesy->max_id();
                int prio = procesy->max_prio();
                procesy->removeMax();
                dodaj_proces(procesy, strategia, tab[g].what_proces(), tab[g].what_prio(), tab[g].what_time());
                tab[g].start_working(id, time, prio);

            }
            break;
        }
    }

}

void starter(int ilosc_procesorow, procesor *tab)
{
    cout << endl << "t" << " ";
    for (int j = 1; j < ilosc_procesorow+1; j++)
    {
        cout << "p" << j << " ";
        if (!(tab[j].is_it_working()))
        {
            cout << " ";
        } 
    }
    cout << endl;
}