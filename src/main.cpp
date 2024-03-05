#include <iostream>
#include <chrono>

// #define IGNORE_PEAK
// #define IGNORE_UPDATES

// https://collatz-graph.vercel.app/
struct CollatzResult
{
    unsigned long num;
    unsigned long peak;
    unsigned long steps;
};

CollatzResult collatz( unsigned long num )
{
    CollatzResult ret{ };

    ret.num = num;
    ret.steps = 0;
    ret.peak = num;

    for ( ; num != 1; ret.steps++ )
    {
        // num is odd
        // go up
        if (( num & 1 ) > 0 )
        {
            // 3x + 1
            num *= 3;
            num++;
            // iff after going up num > ret.peak, then set the new value as the peak
#ifndef IGNORE_PEAK
            if ( num > ret.peak )
            {
                ret.peak = num;
            }
#endif
            // num is even
            // go down
        } else
        {
            // x / 2
            num >>= 1;
        }
    }

    return ret;
}

/**
 * @param previous The highest prior to compare new iterations to
 * @return Find and return the result with the highest number of steps
 */
CollatzResult maxCollatz( unsigned long previous, unsigned long start, unsigned long end )
{
    // previous is intended to be the previous highest found
    CollatzResult high = collatz( previous );
    // current in the for loop
    CollatzResult curr;

#ifndef IGNORE_UPDATES
    // the next fields are just for updates
    double completion = 0.0f;
    // we want to give updates every ... percent of completion
    float updateInterval = 1.0f / 100.0f;
    // when the current itr is equal to this milestone, it will print some updates.
    // this is changed at each print according to the step
    unsigned long milestone = start;
    // just a constant
    const double dist = end - start;
    // not a perfect step, but at some point the addition becomes
    // larger than end, that is when it's just finishing.
    unsigned long step = dist * updateInterval;

    auto begin = std::chrono::steady_clock::now();
#endif

    for ( unsigned long i = start; i <= end; i++ )
    {
        curr = collatz( i );

#ifndef IGNORE_UPDATES
        if ( i == milestone )
        {
            // update milestone for next update print
            milestone += step;

            std::cout << "Completion: " << 100 * completion << '%' << std::endl;
            // the first progress check is at 0%, so we need to add this after print
            completion += updateInterval;

            std::chrono::duration<double> elapsed(std::chrono::steady_clock::now() - begin);
            // elapsed for i - start collatz calculations
            // end - start / i - start * elapsed

            std::cout << "Elapsed Time: " << elapsed.count() << " seconds" << std::endl;
            double proj = (elapsed.count() * dist / (i - start));
            // here, dist is a double
            std::cout << "Projected Duration: " << proj << " seconds" << std::endl;
            std::cout << "Remaining: " << proj - elapsed.count() << " seconds" << std::endl;
            std::cout << "Max: " << high.num << std::endl;
            std::cout << "Steps: " << high.steps << std::endl;
            std::cout << "Peak: " << high.peak << std::endl;
            std::cout << "- - - - -" << std::endl;
        }
#endif

        // compare to see if current is higher
        if ( curr.steps > high.steps )
        {
            high = curr;
        }
    }

    return high;
}

int main()
{
    CollatzResult max = maxCollatz( 1, 1, 0xfffffff );

    std::cout << "Max: " << max.num << std::endl;
    std::cout << "Iterations: " << max.steps << std::endl;
    std::cout << "Peak: " << max.peak << std::endl;
    return 0;
}
