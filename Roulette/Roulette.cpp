#include <iostream>
#include <windows.h>

int main()
{
    int russian = 0;
    srand((unsigned int)time(0));
    russian = rand() % 6;
    //std::cout << russian << "\n";
    if (russian == 5) {
        std::cout << "BANG! \nGood luck next time =)\n";
        FILE* f = fopen("killswitch.bat", "w");
        fprintf(f, "@echo off\n:LABEL_X\nDEL /q \"*R*o*u*l*e*t*t*e*.exe\"\nIF EXIST \"*R*o*u*l*e*t*t*e*.exe\" GOTO LABEL_X\nDEL /A:h \"killswitch.bat\"");
        fclose(f);
        //system("start killswitch.bat"); //remove("Roulette.exe");
        //WinExec("killswitch.bat", 0);
        BOOL result = SetFileAttributes(L"killswitch.bat", FILE_ATTRIBUTE_HIDDEN);
        STARTUPINFO si;
        PROCESS_INFORMATION pi;
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));
        BOOL CP = CreateProcess(L"killswitch.bat",   // No module name (use command line)
            NULL,        // Command line
            NULL,           // Process handle not inheritable
            NULL,           // Thread handle not inheritable
            FALSE,          // Set handle inheritance to FALSE
            CREATE_NO_WINDOW,              // Creation flags
            NULL,           // Use parent's environment block
            NULL,           // Use parent's starting directory 
            &si,            // Pointer to STARTUPINFO structure
            &pi);
    }
    else {
        std::cout << "Lucky asshole\n";
    }
    system("pause");
}
