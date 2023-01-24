#include"strategia.hh"
#include"funkcje.hh"
#include"priority_queue.hh"
#include "proces.hh"
#include "procesor.hh"

using namespace std; 

void strategia0(prio_q *procesy, int id, int pi, int ri)
{
    //pierwszy wszedl - pierwszy wychodzi -> priorytetem będzie kolejność wejścia
    procesy->insert(id, ri, pi, id);
}

void strategia1(prio_q *procesy, int id, int pi, int ri)
{
    //pierwszenstwo ma proces o najkrotszym czasie wykonywania
    procesy->insert(id, ri, pi, ri);
}

void strategia2(prio_q *procesy, int id, int pi, int ri)
{
    //pierwszenstwo ma proces o najkrotszym czasie wykonywania
    procesy->insert(id, ri, pi, ri);
}

void strategia3(prio_q *procesy, int id, int pi, int ri)
{
    //procesy ustawiaja sie w kolejce, ten ktory dopiero skonczyl pracowac idzie na koniec kolejki
    procesy->insert(id, ri, pi, procesy->priority()+1);
}

void strategia4(prio_q *procesy, int id, int pi, int ri)
{
    //szeregowanie priorytetowe - dla tych samych priorytetow - poprzez FCFS
    procesy->insert4(id, ri, pi);
}

void strategia5(prio_q *procesy, int id, int pi, int ri)
{
    //szeregowanie priorytetowe - dla tych samych priorytetow pierwszenstwo ma proces o najkrotszym czasie wykonywania
    procesy->insert5(id, ri, pi);
}

void strategia6(prio_q *procesy, int id, int pi, int ri)
{
    //szeregowanie priorytetowe - dla tych samych priorytetow - poprzez FCFS
    procesy->insert4(id, ri, pi);
}