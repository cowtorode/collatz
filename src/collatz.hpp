//
// Created by cory on 3/7/24.
//

#ifndef COLLATZ_COLLATZ_HPP
#define COLLATZ_COLLATZ_HPP


class CollatzRunner
{
public:
    struct CollatzResult
    {
        unsigned long num;
        unsigned long peak;
        unsigned long steps;
    };

    static CollatzResult collatz( unsigned long num);

    static CollatzResult maxCollatz( unsigned long previous, unsigned long start, unsigned long end );
};


#endif //COLLATZ_COLLATZ_HPP
