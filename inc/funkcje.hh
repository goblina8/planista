#ifndef FUNKCJE
#define FUNKCJE

#include "proces.hh"
#include "procesor.hh"
#include "strategia.hh"
#include "priority_queue.hh"
#include "proces.hh"
#include <iostream>

void wczytaj(int strategia, int ilosc_procesorow, int kwant_czasu);
void dodaj_proces(prio_q* procesy, procesor *tab, int strategia, int kwant_czasu, int id, int pi, int ri);
int planuj(prio_q *procesy, procesor *tab, int ilosc_procesorow, int kwant_czasu, int obecny_czas, int strategia);
void wywlaszczanie(prio_q *procesy, procesor* tab, int ilosc_procesorow, int kwant_czasu, int strategia, int i);
void starter(int ilosc_procesorow, procesor* tab);

#endif
