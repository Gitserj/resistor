// Программа помогает узнать номинал резистора по цветовой маркировке

#include <stdio.h>
#include <windows.h>
#include <math.h>       // Для функции pow() - возведение числа X в степень Y
#include "my_color.h"   // Для работы set_color() - смена цвета фона и символа

// Функция считает значимую часть номинала резистора и умножает на множитель
// Возвращает число типа long long unsigned
long long unsigned get_nominal(unsigned a, unsigned b, unsigned c, unsigned d)
{
    long long unsigned result = 0;

    d = pow(10,d);
    result = ( a * 100 + b * 10 + c ) * d;

    return result;
}

// Функция интерпретирует ввод для вычисления погрешности
// Возвращает число типа double с значением погрешности %
double get_limit(int e)
{
    if(e == -2) return 10;
    if(e == -1) return 5;
    if(e == 0)  return 0;
    if(e == 1)  return 1;
    if(e == 2)  return 2;
    if(e == 3)  return 0;
    if(e == 4)  return 0;
    if(e == 5)  return 0.5;
    if(e == 6)  return 0.25;
    if(e == 7)  return 0.1;
    if(e == 8)  return 0.05;
    if(e == 9)  return 0;
}

int main(void)
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // обьявление и инициализация переменных
    unsigned a, b, c , d, r;        // переменные для хранения номиналов, перменная r для хранения кол-ва полосок.
    a = b = c = d = r = 0;
    int e = 0;                      // переменная для записи 5(4) числа - погрешность, может принимать отрицательное значение

    // Начало вывода псевдографики (картинка - резистор)
    printf("  ┌────┐           ┌────┐  \n");
    printf("  │    └───────────┘│   │  \n");
    printf("┌─┤     1  2  3  4  5   ├─┐\n");
    printf("  │    ┌┬──┬──┬──┬─┐│   │  \n");
    printf("  └────┘│  │  │  │ └┬───┘  \n");
    printf("        │  │  │  │  └ 5 цифра - величина допуска\n");
    printf("        │  │  │  └─── 4 цифра - множитель величины\n");
    printf("        │  │  └────── 3 цифра - единицы Ом\n");
    printf("        │  └───────── 2 цифра - десятки Ом\n");
    printf("        └──────────── 1 цифра - сотни   Ом\n\n");
    // Конец вывода псевдографики

    // Начало вывода таблицы с подсказкой
                      printf("Цвет         Число       Множитель        Допуск  \n");
    set_color(7, 0);  printf("Серебряный   -2          0,01             ±10%%   \n");
    set_color(14, 0); printf("Золотой      -1          0,1              ±5%%    \n");
    set_color(0, 15); printf("Чёрный       0           1                -       \n");
    set_color(6, 0);  printf("Коричневый   1           10               ±1%%    \n");
    set_color(4, 15); printf("Красный      2           100              ±2%%    \n");
    set_color(12,15); printf("Оранжевый    3           1000             -       \n");
    set_color(14,0);  printf("Жёлтый       4           10000            -       \n");
    set_color(2, 15); printf("Зелёный      5           100000           ±0,5%%  \n");
    set_color(9, 15); printf("Голубой      6           1000000          ±0,25%% \n");
    set_color(5, 15); printf("Фиолетовый   7           10000000         ±0,1%%  \n");
    set_color(8, 15); printf("Серый        8           100000000        ±0,05%% \n");
    set_color(15, 0); printf("Белый        9           1000000000       -       \n\n");
    set_color(0, 15); // возврат цвета консоли
    // Конец таблицы с подсказкой

    // Приглашение на ввод
    printf("Сколько полосок на вашем резисторе?\nОтвет: ");
    scanf(" %u", &r);
    fflush(stdin);
    if(r > 5 || r < 4)
        printf("\nОшибка! Программа только для резисторов с 4 и 5 полосками.\n");
    else
    {
        printf("\nВведите %u цифр через пробел в соответствии с таблицей,\nчтобы узнать номинал и погрешность вашего резистора:\n",r);
        if(r == 4)
        {
            scanf(" %u %u %u %i", &b, &c , &d, &e);
            fflush(stdin);

            printf("\nНоминал резистора %d Ом\n", get_nominal(0, b, c, d));
            printf("Возможная погрешность ±%.2f%%", get_limit(e));
        }
        else
        {
            scanf(" %u %u %u %u %i", &a, &b, &c , &d, &e);
            fflush(stdin);

            printf("\nНоминал резистора %d Ом\n", get_nominal(a, b, c, d));
            printf("Возможная погрешность ±%.2f%%", get_limit(e));
        }
    }

    // конец программы
    printf("\n\n");
    system("pause>null");
    return 0;
}
