#include "procesor.hh"
#include "proces.hh"

void procesor:: one_tic()
{
    this->time_left--;
    this->kwant++;
}

void procesor:: start_working(int id, int time, int prio)
{
    this->proces_id = id;
    this->proces_prio = prio;
    this->time_left = time;
    this->is_working = 1;
    this->kwant = 0;
}
void procesor:: stop_working()
{
    this->proces_id = -1;
    this->is_working = 0;
}

int procesor:: what_time()
{
    return this->time_left;
}

int procesor:: what_proces()
{
    return this->proces_id;
}

int procesor:: what_id()
{
    return this->proces_id;
}

int procesor:: what_prio()
{
    return this->proces_prio;
}

int procesor:: what_kwant()
{
    return this->kwant;
}

bool procesor:: is_it_working()
{
    return this->is_working;
}