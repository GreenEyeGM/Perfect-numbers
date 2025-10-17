#include <iostream>
#include "perfect_numbers.h"
#include <vector>

using namespace std;

int main() {
    int choice = 0;
    bool exit = false;
    do {
        cout << "=== Меню за работа със съвършени числа ===\n";
        cout << "1. Сума от делители\n";
        cout << "2. Извеждане на делители\n";
        cout << "3. Сечение на делители на две числа\n";
        cout << "4. Обединение на прости делители на две числа\n";
        cout << "5. Проверка дали числото е съвършено\n";
        cout << "6. Всички съвършени числа в интервал\n";
        cout << "7. Първите n съвършени числа\n";
        cout << "8. Запазване на съвършени числа в интервал\n";
        cout << "9. Съвършени числа чрез Мерсенови числа\n";
        cout << "10. Формулна репрезентация на съвършени числа\n";
        cout << "11. Изход\n";
        cout << "Изберете опция (1-11): ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // Изчистване на флага за грешка
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнориране на невалидния вход
            cout << "Невалиден избор. Моля, изберете от 1 до 11." << endl;
            continue; // Продължаваме с цикъла
        }
        switch (choice) {
            case 1: {
                cout << "Избрахте опция 1 - Сума от делители\n";
                long long num;

                do {
                    cout<< "Въведи число: ";
                    cin >> num;
                } while (!Checker(num));

                cout << "Сумата от делителите на " << num << " е: " << sumOfDivisors(num) << endl;
                break;
            }
            case 2: {
                cout<< "Избрахте опция 2 - Извеждане на делители\n";
                long long num;

                do {
                    cout<< "Въведи число: ";
                    cin >> num;
                } while (!Checker(num));

                cout << "Делителите на " << num << " са: "; //<< getAllDivisors(num) << endl;

                PrinterLong(getAllDivisorsMenu(num));
                cout << "\n";

                break;
            }

            case 3: {
                cout << "Избрахте опция 3 - Сечение на делители на две числа\n";
                long long num1, num2;

                do {
                    cout << "Въведи първо число: ";
                    cin >> num1;
                    cout << "Въведи второ число: ";
                    cin >> num2;
                } while (!Checker(num1) || !Checker(num2));

                cout << "Сечението на делителите на " << num1 << " и " << num2 << " е: ";
                PrinterLong(intersectionOfDivisors(num1, num2));

                cout << "\n";
                break;
            }

            case 4: {
                cout << "Избрахте опция 4 - Обединение на прости делители на две числа\n";
                long long num1, num2;
                do {
                    cout << "Въведи първо число: ";
                    cin >> num1;
                    cout << "Въведи второ число: ";
                    cin >> num2;
                } while (!Checker(num1) || !Checker(num2));


                cout << "Обединението на делителите на " << num1 << " и " << num2 << " е: ";
                PrinterLong(unionOfDivisors(num1, num2));
                cout <<"\n";
                break;
            }
            case 5: {
                cout<< "Избрахте опция 5 - Проверка дали числото е съвършено\n";
                long long num;
                do {
                    cout<< "Въведи число: ";
                    cin >> num;
                } while (!Checker(num));

                if (isPerfect(num)) {
                    cout << "Числото " << num << " е съвършено." << endl;
                }
                else {
                    cout << "Числото " << num << " не е съвършено." << endl;
                }

                break;
            }

            case 6: {
                cout<<"Избрахте опция 6 - Всички съвършени числа в интервал\n";
                long long start, end;
                do {

                    cout << "Въведи начало на интервала: ";
                    cin >> start;
                    cout << "Въведи край на интервала: ";
                    cin >> end;
                    if (start>=end) {
                        cout<<"Интервалът е невалиден. Началото трябва да е по-голямо от края."<<endl;
                    }
                } while (!Checker(start) || !Checker(end) || start>=end);


                cout << "Съвършените числа в интервала" << start << ", " << end << " са: ";
                perfectNumbersInInterval(start, end);
                cout<<"\n";

                break;
            }

            case 7: {
                cout << "Избрахте опция 7 - Първите n съвършени числа\n";
                long long num;
                do {
                    cout<< "Въведи число: ";
                    cin >> num;
                } while (!Checker(num));

                cout<< "Първите " << num << " съвършени числа са: ";
                firstNPerfectNumbers(num);
                cout << "\n";
                break;

            }

            case 8: {
                cout <<"Избрахте опция 8 - Запазване на съвършени числа в интервал\n";
                long long start, end;
                do {
                    cout << "Въведи начало на интервала: ";
                    cin >> start;
                    cout << "Въведи край на интервала: ";
                    cin >> end;
                    if (start>=end) {
                        cout<<"Интервалът е невалиден. Началото трябва да е по-голямо от края."<<endl;
                    }
                } while (!Checker(start) || !Checker(end) || start>=end);

                cout<<"Съвършените числа в интервала " << start << ", " << end << " са: ";
                PrinterLong(perfectNumbersInIntervalVector(start, end));
                cout << "\n";
                break;
            }
            case 9: {
                cout<<"Избрахте опция 9 - Съвършени числа чрез Мерсенови числа\n";
                long long num;
                do {
                    cout<< "Въведи число: ";
                    cin >> num;
                } while (!Checker(num));
                cout << "Съвършените числа чрез Мерсенови числа до " << num << " са: ";
                PrinterLong(generatePerfectNumbersByMersenne(num));
                cout << "\n";
                break;
            }
            case 10: {
                cout<<"Избрахте опция 10- Формулна репрезентация на съвършени числа\n";
                long long num;
                do {
                    cout<< "Въведи число: ";
                    cin >> num;
                } while (!Checker(num));
                cout << "Формулната репрезентация на съвършените числа до " << num << " е: " << endl;
                vector<string> option10 = symbolicPerfectNumberForms(num);

                for (int i = 0; i < option10.size(); i++) {
                    std::cout << option10[i]<< endl;
                }

                break;
            }
            case 11: {
                cout << "Избрахте опция Изход. Потвърдете с Y или откажете с N" << endl;
                char confirm;

                    do {
                        cin >> confirm;
                        if (confirm == 'Y' || confirm == 'y') {
                            cout << "Изход от програмата." << endl;
                            exit = true; // Изход от цикъла
                        } else if (confirm == 'N' || confirm == 'n') {
                            cout << "Продължаваме с програмата." << endl;
                            continue;
                        } else {
                            cout << "Невалиден избор. Опитайте отново." << endl;
                        }
                    } while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n');
                    break;
                }

                default: {
                    cout << "Невалиден избор. Моля, изберете от 1 до 11." << endl;
                    break;
                }

            }
    } while (choice != 11 || !exit);
    return 0;
}


