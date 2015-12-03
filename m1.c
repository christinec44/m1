#include <stdio.h>
#include <math.h>
#include "timer.h"

double pi_bbp (int n);
double pi_leibniz (int n);
int adjust_rep_count (int count, double time, double tmin, double tmax);

int main (void)
{
    double pi;	//initializes pi
    double tol = 0.000001, abserr;	//declares the absolute error and minimum error
    int i, ileibniz, ibbp;	//initialize iteration variables

    i = 1;	
    do		//loop for calculating the value of pi for leibniz
    {
        pi = pi_leibniz (i);
        abserr = fabs (pi - M_PI);	//calculates the absolute error 
        printf ("%8d %20.15f %20.15f\n", i, pi, abserr);
        i *= 2;		//doubles the iterations
    }
    while (abserr > tol);	//runs loop for as long as the absolute error is greater than the minimum error
    ileibniz = i / 2;		

    printf ("ileibniz = %8d\n", ileibniz); // prints the number of iterations for leibniz

    i = 1;
    do		//loop for calculating the value of pi for bbp
    {
        pi = pi_bbp (i);
        abserr = fabs (pi - M_PI);	//calculates the absolute error
        printf ("%8d %20.15f %20.15f\n", i, pi, abserr);
        i *= 2;		//doubles the iterations
    }
    while (abserr > tol);	//runs loop for as long as the absolute error is greater than the minimum error
    ibbp = i / 2;

    printf ("ibbp = %8d\n \n \n", ibbp);	// prints the number of iterations for bbp

    double time, time1, time2; //initializes variables
    int m;
    double tmax = 2.;
    double tmin = 1.;
    int count = 1000;

    printf ("Timing the BBP Series Method:\n\n");
    printf ("   Time/Iteration          Total Time           Iterations\n");
    do		//measures the time per function of the bbp function
    {
        timer_start ();
        for (m = 0; m < count; m++)
        {
            pi_bbp (ibbp);
        }
        time = timer_stop ();

        //adjust count between tmin and tmax
        time1 = time / count;
        printf (" %10.2f usec         %10.6f sec      %10d\n", time1 * 1.e6,
            time, count);
        count = adjust_rep_count (count, time, tmin, tmax);
    }
    while ((time > tmax) || (time < tmin));

    printf ("\n\n");

    count = 1000;

    printf ("Timing the Leibniz Series Method:\n\n");
    printf ("   Time/Iteration          Total Time           Iterations\n");
    do		//measures the time per function of the leibniz function
    {
        timer_start ();

        for (m = 0; m < count; m++)
        {
            pi_leibniz (ileibniz);
        }

        time = timer_stop ();

        //adjust count between tmin and tmax

        time2 = time / count;
        printf (" %10.2f usec         %10.6f sec      %10d\n", time2 * 1.e6,
            time, count);
        count = adjust_rep_count (count, time, tmin, tmax);
    }
    while ((time > tmax) || (time < tmin));
    printf ("\n\n");

    double tt = time2 / time1; //calculates the time ratio of two algorithms

    printf ("Ratio of Algorithms: %10.2f\n\n", tt);

    return 0;
}
