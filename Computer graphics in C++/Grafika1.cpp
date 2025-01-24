#include <windows.h>
#include <iostream>
#include <windowsx.h>
#include <locale.h>
using namespace std;

void grid(HDC hdc, int size, int numX, int numY, int startX, int startY) {
    HPEN whitePen = GetStockPen(WHITE_PEN);
    SelectPen(hdc, whitePen);

    for (int i = 0; i <= numX; ++i) {
        MoveToEx(hdc, startX + i * size, startY, NULL);
        LineTo(hdc, startX + i * size, startY + numY * size);
    }

    for (int i = 0; i <= numY; ++i) {
        MoveToEx(hdc, startX, startY + (numY - i) * size, NULL);
        LineTo(hdc, startX + numX * size, startY + (numY - i) * size);
    }
}

void square(HDC hdc, int cellX, int cellY, int size, int numY, COLORREF color, int startX, int startY) {
    HBRUSH brush = CreateSolidBrush(color);
    SelectBrush(hdc, brush);

    int x = startX + cellX * size;
    int y = startY + (numY - cellY - 1) * size;

    Rectangle(hdc, x, y, x + size, y + size);

    DeleteBrush(brush);
}

int main() {
    setlocale(LC_ALL, "Russian");
    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);

    int size, numX, numY, cellX, cellY;
    cout << "Введите размер ячейки в пикселях: ";
    cin >> size;
    cout << "Введите количество ячеек по x: ";
    cin >> numX;
    cout << "Введите количество ячеек по y: ";
    cin >> numY;
    cout << "Введите координату x для квадрата: ";
    cin >> cellX;
    cout << "Введите координату y для квадрата: ";
    cin >> cellY;

    int startX = 250;
    int startY = 250;

    grid(hdc, size, numX, numY, startX, startY);
    square(hdc, cellX, cellY, size, numY, RGB(240, 255, 240), startX, startY);

    ReleaseDC(hwnd, hdc);
    int i;
    cin >> i;

    return 0;
}
