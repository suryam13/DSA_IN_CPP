#include <bits/stdc++.h>
using namespace std;
// LC
/*T.C. O(logN) for a number there are logN+1 bits in total so in worst case it is log N simply thining there are 32 bits in INT so constant time O(32)*/
bool isSet(int x, int bitPosition)
{                                         // checks whetehr the bit is set or not
    return (x & (1 << bitPosition)) != 0; // if not equal to 0 means set so return true else false;
}

void setBit(int &x, int bitPosition)
{ // to set the bit and passing &x as the change has to be permanent
    x = x | (1 << bitPosition);
}

void unsetBit(int &x, int bitPosition)
{
    x = x ^ (1 << bitPosition); // could use this or can use x = x & ~(1 << bitPosition)
}

int minimizeXor(int num1, int num2)
{

    int x = num1; // assuming it to be num1 initially because that could eb
                  // the best possible ans as the result is 0 when xored and
                  // that is minimal

    int requiredSetBit = __builtin_popcount(num2); // have to mould and make the x to this number of set bits
    int currentSetBit = __builtin_popcount(x);     // currently we have this much

    int bitPosition = 0;
    if (currentSetBit < requiredSetBit) // means we have to add more setbit and the best way
                                        // to add is to add from LSB as 2^0==1 and minimum
                                        // could be found
    {
        while (currentSetBit < requiredSetBit)
        {
            if (!isSet(x, bitPosition)) // if not set means 0 so set
            {
                setBit(x, bitPosition);
                currentSetBit++;
            }
            bitPosition++;
        }
    }

    else if (currentSetBit > requiredSetBit) // means we have to remove set bit and again
                                             // start removing from backwards as per min
                                             // logic
    {
        while (currentSetBit > requiredSetBit)
        {
            if (isSet(x, bitPosition)) // means set so ow unset
            {
                unsetBit(x, bitPosition);
                currentSetBit--;
            }
            bitPosition++;
        }
    }

    return x;
}
int main()
{

    return 0;
}