// StaticMemberFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
// All references from ALEX (2023) LEARN C++ 15.7 Static member functions, Question #1

#include <chrono>
#include <random>
#include <iostream>

class Random
{
public:
    //Generate a random int between [min, max] (inclusive)
    static int get(int min, int max)
    {
        return distribution(mt, std::uniform_int_distribution<int>::param_type{ min,max });
    }

private:
    static std::mt19937& getMT()
    {
        static std::random_device rd{};
        //create seed_seq with high-res clock and 7 random numbers from std::random_device
        static std::mt19937 mt{ std::mt19937(rd()) };
        return mt;
    }
    

    //generates a seeded std::mt19937 and copies it into our global object
    static std::uniform_int_distribution <int> distribution; 
    static std::mt19937* mt;
};

std::uniform_int_distribution<int> Random::distribution{}; 
std::mt19937* Random::mt = &Random::getMT();

int main()
{
    //print a bunch of random numbers 
    for (int count =0; count < 10; ++count)
    {
        std::cout << Random::get(1, 6) << '\t';
    }

    std::cout << '\n'; 
    return 0; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
