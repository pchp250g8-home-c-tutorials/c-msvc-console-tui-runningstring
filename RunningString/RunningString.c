// RunningString.c : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define PDC_DLL_BUILD
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <curses.h>

int main(int argc, char* argv[])
{
    int nStrLen;
    int nCounter = 0;
    char szLine[_MAX_PATH] = "";
    char szSpaces[80] = "";
    memset(szSpaces, 32, 80);
    memset(szLine, 0, _MAX_PATH);
    memcpy(szLine, szSpaces, 80);
    strncat(szLine, "Hello World!!! Running String!!! Press Any Key To Exit!!!", 58);
    strncat(szLine, szSpaces, 80);
    nStrLen = strlen(szLine) - 80;
    initscr();
    clear();
    curs_set(0);
    nodelay(stdscr, true);
    do
    {
        memcpy(szSpaces, szLine + nCounter, 80);
        szSpaces[79] = 0;
        mvprintw(10, 10, "%s", szSpaces);
        _sleep(140);
        nCounter++;
        if (nCounter >= nStrLen) nCounter = 0;
    }while(getch() == ERR);
    endwin();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
