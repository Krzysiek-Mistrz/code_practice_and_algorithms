// Instructions
// Your task is to create a program that implements the Sieve of Eratosthenes algorithm to find all prime numbers less than or equal to a given number.
// A prime number is a number larger than 1 that is only divisible by 1 and itself. For example, 2, 3, 5, 7, 11, and 13 are prime numbers. By contrast, 6 is not a prime number as it not only divisible by 1 and itself, but also by 2 and 3.
// To use the Sieve of Eratosthenes, first, write out all the numbers from 2 up to and including your given number. Then, follow these steps:
// Find the next unmarked number (skipping over marked numbers). This is a prime number.
// Mark all the multiples of that prime number as not prime.
// Repeat the steps until you've gone through every number. At the end, all the unmarked numbers are prime.
// Note
// The Sieve of Eratosthenes marks off multiples of each prime using addition (repeatedly adding the prime) or multiplication (directly computing its multiples), rather than checking each number for divisibility.
// The tests don't check that you've implemented the algorithm, only that you've come up with the correct primes.

#pragma once

#include <vector>


namespace sieve {

std::vector<int> primes(int limit);

}  // namespace sieve
