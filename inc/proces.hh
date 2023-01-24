#ifndef PROCES
#define PROCES

struct proces
{
  proces *next;
  int prio;
  int time_left;
  int id;
  int prio_n;
};

#endif
