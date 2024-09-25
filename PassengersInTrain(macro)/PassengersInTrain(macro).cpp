#include <iostream>

#define CALL_WITH_COUNT(func, arr, size, totalCount) { for(int i = 0; i < size; ++i){ func(arr[i], totalCount); }}

#define CALL(func, arr, size) { for(int i = 0; i < size; ++i){ func(arr[i], i); }}

void inputPassenger(int& passengers, int index) {
        std::cout << "Input passengers for vagon " << index + 1 << ": " << std::endl;
        std::cin >> passengers;
}

void overPassVagon(int& passengers, int index) 
{
        int count = passengers - 20; 
        if (count > 0) {
            std::cout << "Vagon " << index + 1 << " filled on: " << count << " people" << std::endl;
        }
}

void emptyPassVagon(int passengers, int index)
{
    int  count = 20 - passengers; 
        if (count > 0) {
            std::cout << "Vagon " << index + 1 << " has: " << count << " free places" << std::endl;
        }
}

void totalPassVagon(int passengers, int& totalCount) {
    
    totalCount += passengers; // суммируем пассажиров
}

int main() {
    int passengers[10];
    int totalCount = 0;

    // Ввод данных о пассажирах
    CALL(inputPassenger, passengers, 10);

    // Вывод информации о пустых местах в вагонах
    CALL(emptyPassVagon, passengers, 10);

    // Вывод информации о переполненных вагонах
    CALL(overPassVagon, passengers, 10);

    // Вывод общего количества пассажиров
    CALL_WITH_COUNT(totalPassVagon, passengers, 10, totalCount);



    std::cout << "Total passengers in train: " << totalCount << std::endl;

    return 0;
}
