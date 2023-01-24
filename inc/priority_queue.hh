#ifndef PRIOQ
#define PRIOQ
#include "proces.hh"

using namespace std; 

//KLASA
class prio_q
{
    private:
        int e_numb = 0;
        proces *head;
        proces *tail;
    public:
        prio_q();
        ~prio_q();
        bool isEmpty();
        int max_time();
        int max_id();
        int max_prio();
        void removeMax();
        int  priority();
        void insert(int id, int time_left , int prio_n, int prio);
        int get_e_numb() {return e_numb;}
        void insert4(int id, int time_left , int prio_n);
        void insert5(int id, int time_left , int prio_n);
        void insert6(int id, int time_left , int prio_n, int prio);
};
#endif