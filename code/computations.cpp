#include "computations.h"
#include <chrono>
#include <iostream>
#include <syncstream>
#include <thread>
using namespace std;

void slow(const string &name)
{
    this_thread::sleep_for(7s);
    osyncstream(cout) << name << endl;
}

void quick(const string &name)
{
    this_thread::sleep_for(1s);
    osyncstream(cout) << name << endl;
}
