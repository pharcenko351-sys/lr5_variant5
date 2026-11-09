#include "work.h"
#include "computations.h"
#include <chrono>
#include <format>
#include <future>
#include <iostream>
#include <syncstream>
using namespace std;

void work()
{
    auto start = chrono::steady_clock::now();

    auto chainA = async(launch::async, []
                        {
                            slow("A1");
                            quick("A2");
                        });
    auto chainC = async(launch::async, []
                        {
                            quick("C");
                            quick("F");
                        });

    quick("B1");
    slow("B2");
    chainA.get();
    quick("D");
    chainC.get();

    auto seconds = chrono::duration<double>(chrono::steady_clock::now() - start).count();
    osyncstream(cout) << format("Time: {:.2f} s", seconds) << endl;
    osyncstream(cout) << "Work is done!" << endl;
}
