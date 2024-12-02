#include "../src/Stopwatch.h"
#include <iostream>
#include <iomanip>

int test_Stopwatch() {

    Stopwatch stopwatch;



    stopwatch.start();

    // do something
    std::cout << "outer loop --> 10,000\t inner loop --> 1,000\n";
    int num = 0;
    for(unsigned i = 0 ; i < 10000; i++) 
        for (unsigned j = 0; j < 1000; j++)
            if(i % 2)
                num++;

    stopwatch.stop();

    std::cout << "duration: " << stopwatch.getMilliseconds() << "ms\n\n";
    std::cout << "duration: " << stopwatch.getMicroseconds() << "microseconds\n\n";;

    stopwatch.start();

    // do something
    std::cout << "outer loop --> 10,000\t inner loop --> 10,000\n";
    num = 0;
    for(unsigned i = 0 ; i < 10000; i++) 
        for (unsigned j = 0; j < 10000; j++)
            if(i % 2)
                num++;

    stopwatch.stop();

    std::cout << "duration: " << stopwatch.getMilliseconds() << "ms\n\n";
    std::cout << "duration: " << stopwatch.getMicroseconds() << "microseconds\n\n";
    // do something
    num = 0;
    std::cout << "outer loop --> 100,000\t inner loop --> 10,000\n";
    for(unsigned i = 0 ; i < 100000; i++) 
        for (unsigned j = 0; j < 10000; j++)
            if(i % 2)
                num++;

    stopwatch.stop();

    std::cout << "duration: " << stopwatch.getMilliseconds() << "ms\n\n";
    std::cout << "duration: " << stopwatch.getMicroseconds() << "microseconds\n\n";

    return 0;
}