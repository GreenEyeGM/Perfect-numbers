//
// Created by Ivan Todorov on 9.05.25.
//
#include "perfect_numbers.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

/*
Примери на съвършени числа
6
28
496
8128
33550336
8589869056
137438691328
2305843008139952128
*/

bool isPrime(long long current_number);

//std::vector<std::string> removeDuplicates(std::string str);
std::vector<long long> getAllDivisors(long long n);
void PrinterString (std::vector<std::string> vectorToBePrinted);
void PrinterLong (std::vector<long long> vectorToBePrinted);


//Опция 1
long long sumOfDivisors(long long n) {
    if (n <= 1) return 0;

    long long sum = 1; // 1 е делител на всички числа > 1

    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;

            // if (i != n / i) {
            //     sum += n / i;
            // }

            if (i * i != n) {
                sum += n / i;
            }
        }
    }
    return sum;
}


//Опция 2

std::vector<long long> getAllDivisorsMenu(long long n) {
    std::vector<long long> divisors;

    if (n <= 1) return divisors; // Няма делители, освен себе си

    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i != n) divisors.push_back(i);
            long long pair = n / i;
            if (pair != i && pair != n) {
                divisors.push_back(pair);
            }
        }
    }

    std::sort(divisors.begin(), divisors.end()); // Подредба във възходящ ред
    return divisors;
}

// Опция 3
std::vector<long long> intersectionOfDivisors(long long a,long long b) {

    std::vector<long long> number1Divisors = getAllDivisors(a);
    std::vector<long long> number2Divisors = getAllDivisors(b);

    std::vector<long long> result;

    for (long long i = 0; i <= std::min(number1Divisors.size(),number2Divisors.size()); i++) {
        if (number1Divisors[i] == number2Divisors[i]) {
            result.push_back(number1Divisors[i]);
        }
    }

    return result;
}

// Опция 4
std::vector<long long> unionOfDivisors(long long a, long long b) {

    // Обхождаме всички делители на a и b
    std::vector<long long> number1Divisors = getAllDivisors(a);
    std::vector<long long> number2Divisors = getAllDivisors(b);

    std::vector<long long> result;

    //Проверяваме кои от тях са прости
    for (long long i = 0; i <= std::max(number1Divisors.size(),number2Divisors.size()); i++) {
        if (isPrime(number1Divisors[i])) {
            result.push_back(number1Divisors[i]);
        }
        if (isPrime(number2Divisors[i])) {
            result.push_back(number2Divisors[i]);
        }
    }

    //Сортиране
    std::sort(result.begin(), result.end());
    // Премахване на дубликати
    result.erase(std::unique(result.begin(), result.end()), result.end());

    return result;
}


// Опция 5
bool isPerfect(long long n) {
    return sumOfDivisors(n) == n;
}

// Опция 6 само принтирам без да запазвам? Не ми става ясно от условието
void perfectNumbersInInterval(long long start, long long end) {
    for (long long i = start; i <= end; i++) {
        if (isPerfect(i)) {
            std::cout << i << " ";
        }
    }
}

//Опция 7 - zakomentirai
void firstNPerfectNumbers(int n) {
    int counter = 0;
    long long num = 0;
    do {
        if (isPerfect(num)) {
            std::cout << num << " ";
            counter++;
        }
        num ++;
    } while (counter < n);
}

//Опция 8
std::vector<long long> perfectNumbersInIntervalVector(long long a, long long b) {
    std::vector<long long> numbers;
    int counter = 0;
    for (long long i = a; i <= b; i++) {
        if (isPerfect(i)) {
            numbers.push_back(i);
        }
    }
    return numbers;
}

//Опция 9
std::vector<long long> generatePerfectNumbersByMersenne(int n) {
    std::vector<long long> result;
    int found = 0;

    for (int p = 2; found < n; ++p) {
        long long mersenne = pow(2, p) - 1;
        if (isPrime(mersenne)) {
            long long perfect = pow(2, p - 1) * mersenne;
            result.push_back(perfect);
            found++;
        }
    }

    return result;
}

// Опция 10
std::vector<std::string> symbolicPerfectNumberForms(int n) {
    std::vector<std::string> result;
    int found = 0;

    for (int p = 2; found < n; ++p) {
        long long mersenne = pow(2, p) - 1;
        if (isPrime(mersenne)) {
            std::string formula = "2^(" + std::to_string(p - 1) + ").(2^" + std::to_string(p) + "-1)";
            result.push_back(formula);
            found++;
        }
    }

    return result;
}

// Метод за проверка на валидността на числото
bool Checker (long long num) {
    if (num <0 || num > 2305843008139952128 ) {
        std::cout << "Числото трябва да е по-голямо или равно на 0 и по-малко или равно на 2 305 843 008 139 952 128.\n";
        return false;
    }
    return true;
}

//Функция за проверка дали числото е просто
bool isPrime(long long n) {
    if (n <= 1) return false;

    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

//Функция за проверка на Съвършенно число - внедрено
// bool isPerfectNumber(long long n) {
//     if (n <= 1) return false;
//
//     long long sum = 0;
//     for (long long i = 1; i <= n / 2; ++i) {
//         if (n % i == 0) {
//             sum += i;
//         }
//     }
//     return sum == n;
// }

//Взимане на всички делители
std::vector<long long> getAllDivisors(long long n) {
    std::vector<long long> divisors;

    if (n <= 1) return divisors; // Няма делители, освен себе си

    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i != n) divisors.push_back(i);
            long long pair = n / i;
            if (pair != i && pair != n) {
                divisors.push_back(pair);
            }
        }
    }

    std::sort(divisors.begin(), divisors.end()); // Подредба във възходящ ред
    return divisors;
}

//Функция за принтиране на вектор от string
void PrinterString (std::vector<std::string> vectorToBePrinted) {
    for (int i = 0; i < vectorToBePrinted.size(); i++) {
        std::cout << vectorToBePrinted[i];
        if (i+1==vectorToBePrinted.size()) {
            break;
        }
        std::cout << ", ";
    }
}

//Функция за принтиране на вектор от long
void PrinterLong (std::vector<long long> vectorToBePrinted) {
    for (int i = 0; i < vectorToBePrinted.size(); i++) {
        std::cout << vectorToBePrinted[i];
        if (i+1==vectorToBePrinted.size()) {
            break;
        }
        std::cout << ", ";
    }
}

//Функция за проверка на дубликати - не го използвам никъде
// std::vector<long long> removeDuplicates(std::vector<long long> inputVector) {
//     std::vector<long long> correctVector;
//
//     for (int i = 0; i < inputVector.size(); i++) {
//         if (inputVector[i] != inputVector[inputVector.size()-1-i]) {}
//     }
//
//     return correctVector;
// }


//Закоментирани функции за въпрос
//Опция 2 със запазване
// std::string getAllDivisors (long long n) {
//     long long sum = 0;
//     std::string divisors = "";
//     for (long long i = 1; i <= n / 2; ++i) {
//         if (n % i == 0) {
//             divisors += std::to_string(i) + " ";
//         }
//     }
//     return divisors;
// }
// Опция 6- грешна, защото запазвам???
// std::vector<long long> perfectNumbersInInterval(long long start, long long end) {
//     std::vector<long long> perfectNumbers;
//     for (long long i = start; i <= end; i++) {
//         if (isPerfect(i)) {
//             perfectNumbers.push_back(i);
//         }
//     }
//     return  perfectNumbers;
// }

//Опция 7
// std::vector<long long> firstNPerfectNumbers(int n) {
// std::vector<long long> numbers;
// int counter = 1;
// do {
// if (isPerfect(counter)) {
// numbers.push_back(counter);
// }
// counter++;
// } while (numbers.size() < n);
//
//
// return numbers;
// }
//

