void set_color(int a, int b)
{
    // "Получение дескриптора" - подсмотрел в интернете, нужно для изменения цвета отдельных слов
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // a - цвет фона    b - цвет текста
    SetConsoleTextAttribute(hConsole, (WORD) ((a << 4) | b));
}
