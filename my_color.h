void set_color(int a, int b)
{
    // "��������� �����������" - ���������� � ���������, ����� ��� ��������� ����� ��������� ����
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // a - ���� ����    b - ���� ������
    SetConsoleTextAttribute(hConsole, (WORD) ((a << 4) | b));
}
