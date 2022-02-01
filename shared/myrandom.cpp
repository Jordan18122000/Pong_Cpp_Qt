#include "myrandom.h"
#include <QDateTime>

MyRandom::MyRandom(int seed)
{
    srand(seed);
}

int MyRandom::get(int max)
{
    return rand()%max;
}
