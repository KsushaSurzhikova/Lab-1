#include <iostream>
#include <ctime> // в ней функция time
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "\t\tСлед матрицы\n";

    srand(time(NULL)); // Инициализируем генератор случайных чисел.
    int X = 0;
    int n = 0;
    cout << "Введите количество стобцов и строк: ";
    cin >> n; // Считываем с клавиатуры n

    clock_t start = clock();
    for (int k = 0; k < 100; k++) {
        int** a = new int* [n]; // Создаем массив указателей
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i] = new int[n];
            }
        }
    // А дальше работа как с обычным массивом.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = rand() % 100; // Каждый элемент случайному числу от 0 до 100
                cout << a[i][j] << " "; // Вывести элементы на консольку
                if (a[i] == a[j])
                {
                    X += a[i][j];
                }
            }
            cout << endl; // Двумерный массив. Строка кончилась, переводим строку и на консоли
        }
        cout << "След матрицы: " << X << endl;

        // Удаление массива
        for (int i = 0; i < n; i++)
        {
            delete[]a[i]; // Удаляем каждый элемент
        }
        delete[] a; // А потом массив
    }

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Прошло времени: %f секунд\n", seconds);

    return 0;
}