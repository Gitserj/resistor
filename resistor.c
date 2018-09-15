// ��������� �������� ������ ������� ��������� �� �������� ����������

#include <stdio.h>
#include <windows.h>
#include <math.h>       // ��� ������� pow() - ���������� ����� X � ������� Y
#include "my_color.h"   // ��� ������ set_color() - ����� ����� ���� � �������

// ������� ������� �������� ����� �������� ��������� � �������� �� ���������
// ���������� ����� ���� int
int get_nominal(int a, int b, int c, int d)
{
    int result = 0;

    d = pow(10,d);
    result = ( a * 100 + b * 10 + c ) * d;

    return result;
}

// ������� �������������� ���� ��� ���������� �����������
// ���������� ����� ���� double � ��������� ����������� %
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
{   // ���������� � ������������� ����������
    int a, b, c , d, e;        // ���������� ��� �������� ���������
    a = b = c = d = e = 0;
    unsigned r = 0;            // ���������� ��� �������� ���-�� ������� ���������

    // ������ ������ ������������� (�������� - ��������)
    printf("  %c%c%c%c%c%c           %c%c%c%c%c%c\n", 218,196,196,196,196,191,218,196,196,196,196,191);
    printf("  %c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c\n", 179,192,196,196,196,196,196,196,196,196,196,196,196,217,179,179);
    printf("%c%c%c     1  2  3  4  5   %�%�%�\n", 218,196,180, 195,196,191);
    printf("  %c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c\n", 179,218,194,196,196,194,196,196,194,196,196,194,196,191,179,179);
    printf("  %c%c%c%c%c%c%c  %c  %c  %c %c%c%c%c%c%c\n", 192,196,196,196,196,217, 179,179,179,179, 192,194,196,196,196,217);
    printf("        %c  %c  %c  %c  %c",179,179,179,179, 192);
    printf(" 5 tsifra - velichina dopuska\n");
    printf("        %c  %c  %c  %c%c%c%c",179,179,179,192, 196,196,196,196);
    printf(" 4 tsifra - mnozhitel' velichiny\n");
    printf("        %c  %c  %c%c%c%c%c%c%c",179,179,192, 196,196,196,196,196,196);
    printf(" 3 tsifra - edinitsy Om\n");
    printf("        %c  %c%c%c%c%c%c%c%c%c%c",179,192, 196,196,196,196,196,196,196,196,196);
    printf(" 2 tsifra - desyatki Om\n");
    printf("        %c%c%c%c%c%c%c%c%c%c%c%c%c",192, 196,196,196,196,196,196,196,196,196,196,196);
    printf(" 1 tsifra - sotni    Om\n\n");
    // ����� ������ �������������

    // ������ ������ ������� � ����������
                      printf("Cvet         CHislo      Mnozhitel'       Dopusk   \n");
    set_color(7, 0);  printf("Serebryanyj  -2          0,01             %�10%%   \n", 241);
    set_color(14, 0); printf("Zolotoj      -1          0,1              %�5%%    \n", 241);
    set_color(0, 15); printf("CHernyj      0           1                -        \n");
    set_color(6, 0);  printf("Korichnevyj  1           10               %�1%%    \n", 241);
    set_color(4, 15); printf("Krasnyj      2           100              %�2%%    \n", 241);
    set_color(12,15); printf("Oranzhevyj   3           1000             -       \n");
    set_color(14,0);  printf("ZHeltyj      4           10000            -       \n");
    set_color(2, 15); printf("Zelenyj      5           100000           %�0,5%%  \n", 241);
    set_color(9, 15); printf("Goluboj      6           1000000          %�0,25%% \n", 241);
    set_color(5, 15); printf("Fioletovyj   7           10000000         %�0,1%%  \n", 241);
    set_color(8, 15); printf("Seryj        8           100000000        %�0,05%% \n", 241);
    set_color(15, 0); printf("Belyj        9           1000000000       -       \n\n");
    set_color(0, 15); // ������� ����� �������
    // ����� ������� � ����������

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // ����������� �� ����
    printf("������� ������� �� ����� ���������?\n�����: ");
    scanf(" %u", &r);
    fflush(stdin);
    if(r > 5 || r < 4)
        printf("\n������! ��������� ������ ��� ���������� � 4 � 5 ���������.\n");
    else
    {
        printf("\n������� %u ���� ����� ������ � ������������ � ��������,\n����� ������ ������� � ����������� ������ ���������:\n",r);
        if(r == 4)
        {
            scanf(" %i %i %i %i", &b, &c , &d, &e);
            fflush(stdin);

            printf("\n������� ��������� %d ��\n", get_nominal(0, b, c, d));
            printf("��������� ����������� %c %.2f%%",177, get_limit(e));
        }
        else
        {
            scanf(" %i %i %i %i %i", &a, &b, &c , &d, &e);
            fflush(stdin);

            printf("\n������� ��������� %d ��\n", get_nominal(a, b, c, d));
            printf("��������� ����������� %c %.2f%%",177, get_limit(e));
        }
    }

    // ����� ���������
    printf("\n\n");
    system("pause>null");
    return 0;
}
