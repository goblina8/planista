#ifndef PROCESOR
#define PROCESOR

class procesor
{
    private:
        int id = -1;
        bool is_working = 0; 
        int time_left = 0;
        int proces_id = -1;
        int proces_prio = -1;
        int kwant= 0;
    public:
        procesor(){};
        procesor(int _id) {id = _id;};
        void one_tic();
        void start_working(int proces_id, int time, int prio);
        void stop_working();
        int what_time(); //zwraca ile czasu zostalo
        int what_kwant(); //zwraca ile czasu zostalo
        int what_prio(); //jaki priotytet ma proces
        int what_proces(); //zwraca jaki proces obenie na nim pracuje, -1 gdy żaden
        int what_id(); //zwraca swoj numer id
        bool is_it_working(); //zwraca 1 gdy obecnie pracuje na nim proces i 0 gdy nie pracuje żaden
};

#endif
