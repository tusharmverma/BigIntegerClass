#include "BigInt.hpp"

struct slot
{
    int value;
    slot * next;
    slot * previous;
};

BigInt::BigInt()
{
    constructPointers();
}

// Shared code among all constructors: make the pointers to the start and end of the list nullpointers and initialise the slotcounter.
void BigInt::constructPointers()
{
    numberOfSlots = 0;
    start = nullptr;
    end = nullptr;
    isPositive = true;
}

// Copyconstructor
BigInt::BigInt(const BigInt & that)
{
    constructPointers();
    copy(that);
}

// Constructor from int, reads the int into the BigInt.
BigInt::BigInt(int value)
{
    constructPointers();
    if (value < 0)
    {
        isPositive = false;
        value *= -1;
    }
    
    if (value >= valuePerSlot)
    {
        put(value / valuePerSlot);
        value %= valuePerSlot;
    }
    put(value);
}

// Constructor from a char array, reads the array into the BigInt. Assumes only digits to be present in the array.
BigInt::BigInt(const char string[])
{
    constructPointers();
    
    int lengthOfString = 0;
    while (string[lengthOfString] != '\0')
    {
        lengthOfString++;
    }
    int value = 0;
    int index = 0;
    if (string[0] == '-')
    {
        isPositive = false;
        lengthOfString--;
        index++;
    }
    while (lengthOfString)
    {
        if (!(lengthOfString % digitsPerSlot))
        {
            put(value);
            value = 0;
        }
        value = value * 10 + (string[index] - '0');
        lengthOfString--;
        index++;
    }
    put(value);
}

BigInt::~BigInt()
{
    clear();
}
