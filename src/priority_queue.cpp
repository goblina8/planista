#include "priority_queue.hh"
#include <iostream>

using namespace std;

//FUNKCJE KLASY PRIO_Q
prio_q::prio_q()
{
    head = NULL;

}

prio_q::~prio_q()
{
    while(head)
    {
        removeMax();
    }
}

bool prio_q::isEmpty()
{
    //cout << "czy pusta:" << !head << endl;
    return !head;
}

int prio_q::max_time()
{
    if(head)
    {
        return head->time_left;
    }
    else
    {
        return -1;
    }
}

int prio_q::max_id()
{
    if(head)
    {
        return head->id;
    }
    else
    {
        return -1;
    }
}

int prio_q::max_prio()
{
    if(head)
    {
        return head->prio_n;
    }
    else
    {
        return -1;
    }
}

void prio_q::removeMax()
{
    /*
    if(head)
    {
        //cout << "Zakonczony proces nr " << head->id;
    }
    else
    {
        throw "EmptyQueueException";
    }
    */

    if(head)
    {
        proces* p = head;
        head = head->next;
        if (!head)
        {
            tail = NULL;
        }
        delete p;
        e_numb--;  
    }
    else
    {
        cout << "nie da sie usunac" << endl;
    }
}

void prio_q::insert(int id, int time_left, int prio_n, int prio)
{
    e_numb++;
    proces *p, *r;
    p = new proces;
    p->next = NULL;
    p->prio = prio;
    p->id = id;
    p->time_left = time_left;
    p->prio_n = prio_n;

    if (!head)
    {
        head = p;
        tail = p;
    }
    else if (head->prio > prio)
    {
        p->next = head;
        head = p;
    }
    else
    {
        r = head;
        while ((r->next) && (r->next->prio <= prio))
            {
                r = r->next;
            }
        p->next = r->next;
        r->next = p;
        if(!p->next)
        {
            tail = p;
        }
    }
}

int  prio_q::priority()
{
    if(!head)
    {
        return -1;
    }
    else
    { 
        return head->prio;
    }
}

void prio_q::insert4(int id, int time_left, int prio_n)
{
    e_numb++;
    proces *p, *r;
    p = new proces;
    p->next = NULL;
    p->id = id;
    p->time_left = time_left;
    p->prio_n = prio_n;
    if (!head)
    {
        head = p;
        tail = p;
    }
    else if (head->prio_n > prio_n)
    {
        p->next = head;
        head = p;
    }
    else
    {
        r = head;
        while ((r->next) && (r->next->prio_n < prio_n))
        {
            r = r->next;
        }
        while ((r->next) && (r->next->prio_n == prio_n))
        {
           r = r->next; 
        }
        if ((r->next) && (r->next->prio_n == prio_n))
        {
            while ((r->next) && (r->next->id <= id))
            {
                r = r->next;
            }
        }
        p->next = r->next;
        r->next = p;
        if(!p->next)
        {
            tail = p;
        }
    }
}

void prio_q::insert5(int id, int time_left, int prio_n)
{
    e_numb++;
    proces *p, *r;
    p = new proces;
    p->next = NULL;
    p->id = id;
    p->time_left = time_left;
    p->prio_n = prio_n;
    if (!head)
    {
        head = p;
        tail = p;
    }
    else if (head->prio_n > prio_n)
    {
        p->next = head;
        head = p;
    }
    else
    {
        r = head;
        while ((r->next) && (r->next->prio_n < prio_n))
        {
            r = r->next;
        }
        while ((r->next) && (r->next->prio_n == prio_n))
        {
           r = r->next; 
        }
        if ((r->next) && (r->next->prio_n == prio_n))
        {
            while ((r->next) && (r->next->time_left <= time_left))
            {
                r = r->next;
            }
        }
        p->next = r->next;
        r->next = p;
        if(!p->next)
        {
            tail = p;
        }
    }
}