//
// Created by Ivan Todorov on 9.05.25.
//

#ifndef PERFECT_NUMBERS_H
#define PERFECT_NUMBERS_H

#include <string>
#include <vector>

// Декларация на функцията като глобална

long long sumOfDivisors(long long n); //Опция 1
std::vector<long long> getAllDivisorsMenu(long long n); //Опция 2
std::vector<long long> intersectionOfDivisors(long long a, long long b); //Опция 3
std::vector<long long> unionOfDivisors(long long a, long long b); //Опция 4
bool isPerfect(long long n); //Опция 5
void perfectNumbersInInterval(long long start, long long end); //Опция 6
void firstNPerfectNumbers(int n);//Опция 7
std::vector<long long> perfectNumbersInIntervalVector(long long a, long long b); //Опция 8
std::vector<long long> generatePerfectNumbersByMersenne(int n); //Опция 9
std::vector<std::string> symbolicPerfectNumberForms(int n); //Опция 10


//Декларация на други функции

bool Checker(long long num); //Проверка за валидност на числото
std::vector<long long> getAllDivisors(long long n); //Извеждане на делители в масив
void PrinterString (std::vector<std::string> vectorToBePrinted); //Функция за принтиране на вектор от string
void PrinterLong (std::vector<long long> vectorToBePrinted); //Функция за принтиране на вектор от long
#endif // PERFECT_NUMBERS_H

