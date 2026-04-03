#include <stdio.h>
#include <stdlib.h>
#include "lab8.h"
double myPow(int base, int exp){
    //if the exponent is negative we can compute the power for the positive exponent
    //then we can rewrite it as 1 over the result to get the reciprocal
    if(exp < 0){
        return 1.0 / myPow(base, -exp);
    }
    //if the exponent is 0 we can return 1 because any number to the power of 0 is 1
    if(exp == 0){
        return 1;
    }
    //if the exponent is positive, we can compute the power by multiplying the base by the base times the exponent minus 1
    //this allows us to multiply the base by itself exp times
    return base * myPow(base, exp - 1);
}
int sumSequence(int start, int end){
    //with recursion
    //two cases, if start is greater is than end, we must increment start until it is equal to end
    //if start is less than end, we must decrement start until it is equal to end
    if(start > end){
        return start + sumSequence(start - 1, end);
    } else if(start < end){
        return start + sumSequence(start + 1, end);
    } else {
        return start;//if start and end are equal, we can just return either one, since they are the same
    }
    //ultimately this function will return the sum of all integers between start and end, inclusive
}
