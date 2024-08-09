#include <time.h>
#include <charconv>
#include <Windows.h>

int main()
{
	//std::cout << "Hello World!\n";
	//HBITMAP bmp = reinterpret_cast<HBITMAP>(LoadImage(GetModuleHandle(nullptr), MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE));
	// DeleteObject(bmp);
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);

	system("Wednesday.mp3");
	for (;;) {
		int russian = 0;
		srand((unsigned int)time(0));
		russian = 1 + rand() % 24;

		const char* extention = ".png";
		char fname[7] = "0";
		std::to_chars(fname, fname + 2, russian);
		const char* pic4 = strcat(fname, extention);
		(const char*)pic4;

		system(pic4);
		Sleep(1000);
	}
}
