#include <iostream>
#include <windows.h>
#include <windowsx.h>
#include <vector>
#include <locale.h>

#define X_OFFSET 500
#define Y_OFFSET 40

void setLocale() {
    setlocale(LC_ALL, "Russian");
}

void createGrid(HDC hdc, int& cols, int& rows, int& cell_side_len) {
    std::cout << "Введите размер сетки(cols rows): ";
    std::cin >> cols >> rows;
    cell_side_len *= 100 / (float)rows;

    for (int i = 0; i <= cols; ++i) {
        MoveToEx(hdc, X_OFFSET + i * cell_side_len, Y_OFFSET, NULL);
        LineTo(hdc, X_OFFSET + i * cell_side_len, Y_OFFSET + rows * cell_side_len);
    }

    for (int i = 0; i <= rows; ++i) {
        MoveToEx(hdc, X_OFFSET, Y_OFFSET + i * cell_side_len, NULL);
        LineTo(hdc, X_OFFSET + cols * cell_side_len, Y_OFFSET + i * cell_side_len);
    }
}

void fillCell(HDC hdc, int cols, int rows, int cell_side_len, int x, int y, char object) {
    if (x < 1 || x > cols || y < 1 || y > rows) return;
    int xPos = X_OFFSET + (x - 1) * cell_side_len;
    int yPos = Y_OFFSET + (rows - y) * cell_side_len;
    if (object == 'r') {
        Rectangle(hdc, xPos, yPos, xPos + cell_side_len, yPos + cell_side_len);
    }
    else if (object == 'c') {
        Ellipse(hdc, xPos, yPos, xPos + cell_side_len, yPos + cell_side_len);
    }
}

COLORREF getCellColor(HDC hdc, int rows, int cell_side_len, int x, int y) {
    return GetPixel(hdc, X_OFFSET + (x - 1) * cell_side_len + 1, Y_OFFSET + (rows - y) * cell_side_len + 1);
}

void drawLine(HDC hdc, int cols, int rows, int cell_side_len, int x1, int y1, int x2, int y2) {
    int xSign = x1 > x2 ? -1 : 1;
    int ySign = y1 > y2 ? -1 : 1;
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int err = dx - dy;
    int x = x1, y = y1;

    while (true) {
        fillCell(hdc, cols, rows, cell_side_len, x, y, 'r');
        if (x == x2 && y == y2) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x += xSign;
        }
        if (e2 < dx) {
            err += dx;
            y += ySign;
        }
    }
}

void drawTriangle(HDC hdc, int cols, int rows, int cell_side_len) {
    int P1[2], P2[2], P3[2];
    std::cout << "Введите 3 точки (x1, y1, x2, y2, x3, y3): ";
    std::cin >> P1[0] >> P1[1] >> P2[0] >> P2[1] >> P3[0] >> P3[1];

    drawLine(hdc, cols, rows, cell_side_len, P1[0], P1[1], P2[0], P2[1]);
    drawLine(hdc, cols, rows, cell_side_len, P3[0], P3[1], P2[0], P2[1]);
    drawLine(hdc, cols, rows, cell_side_len, P1[0], P1[1], P3[0], P3[1]);
}

void circ_8(HDC hdc, int cols, int rows, int cell_side_len, int ix0, int iy0, int x, int y, int col) {
    fillCell(hdc, cols, rows, cell_side_len, ix0 + x, iy0 + y, col);
    fillCell(hdc, cols, rows, cell_side_len, ix0 + x, iy0 - y, col);
    fillCell(hdc, cols, rows, cell_side_len, ix0 - x, iy0 + y, col);
    fillCell(hdc, cols, rows, cell_side_len, ix0 - x, iy0 - y, col);
    fillCell(hdc, cols, rows, cell_side_len, ix0 + y, iy0 + x, col);
    fillCell(hdc, cols, rows, cell_side_len, ix0 + y, iy0 - x, col);
    fillCell(hdc, cols, rows, cell_side_len, ix0 - y, iy0 + x, col);
    fillCell(hdc, cols, rows, cell_side_len, ix0 - y, iy0 - x, col);
}

void drawCircle(HDC hdc, int cols, int rows, int cell_side_len) {
    int ix0, iy0, ir;
    std::cout << "Введите центр окружности и радиус(x, y, r): ";
    std::cin >> ix0 >> iy0 >> ir;

    int x = 0, y = ir, d = 3 - (ir << 1);
    while (x < y) {
        circ_8(hdc, cols, rows, cell_side_len, ix0, iy0, x, y, 'r');
        if (d < 0) {
            d += (x << 2) + 6;
        }
        else {
            d += ((x - y) << 2) + 10;
            --y;
        }
        ++x;
    }
    if (x == y) {
        circ_8(hdc, cols, rows, cell_side_len, ix0, iy0, x, y, 'r');
    }
}

void fillFigure(HDC hdc, int cols, int rows, int cell_side_len, int x, int y, COLORREF color) {
    LOGBRUSH logBrush;
    GetObject((HBRUSH)::GetStockObject(DC_BRUSH), sizeof(LOGBRUSH), &logBrush);
    if (logBrush.lbColor == color) return;

    std::vector<std::pair<int, int>> stack;
    stack.push_back({ x, y });

    while (!stack.empty()) {
        std::pair<int, int> point = stack.back();
        stack.pop_back();
        int cx = point.first;
        int cy = point.second;

        if (getCellColor(hdc, rows, cell_side_len, cx, cy) != color) continue;

        fillCell(hdc, cols, rows, cell_side_len, cx, cy, 'r');

        if (cy > 1 && getCellColor(hdc, rows, cell_side_len, cx, cy - 1) == color) {
            stack.push_back({ cx, cy - 1 });
        }
        if (cy < rows && getCellColor(hdc, rows, cell_side_len, cx, cy + 1) == color) {
            stack.push_back({ cx, cy + 1 });
        }
        if (cx > 1 && getCellColor(hdc, rows, cell_side_len, cx - 1, cy) == color) {
            stack.push_back({ cx - 1, cy });
        }
        if (cx < cols && getCellColor(hdc, rows, cell_side_len, cx + 1, cy) == color) {
            stack.push_back({ cx + 1, cy });
        }
    }
}

int main() {
    setLocale();

    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);

    HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    HBRUSH brush = (HBRUSH)::GetStockObject(DC_BRUSH);
    SelectObject(hdc, pen);
    SelectObject(hdc, brush);

    int cols, rows, cell_side_len = 4;

    createGrid(hdc, cols, rows, cell_side_len);

    for (int i, x, y, r, g, b;;) {
        std::cout << "1. Выбрать цвет \n2. Нарисовать круг \n3. Нарисовать треугольник \n4. Закрасить фигуру\n";
        std::cin >> i;
        switch (i) {
        case 1: {
            std::cout << "Введите значение от 0 до 255 (r g b): ";
            std::cin >> r >> g >> b;
            SetDCBrushColor(hdc, RGB(r, g, b));
            break;
        }
        case 2: {
            drawCircle(hdc, cols, rows, cell_side_len);
            break;
        }
        case 3: {
            drawTriangle(hdc, cols, rows, cell_side_len);
            break;
        }
        case 4: {
            std::cout << "Введите начальную точку для заливки(x y): ";
            std::cin >> x >> y;
            fillFigure(hdc, cols, rows, cell_side_len, x, y, getCellColor(hdc, rows, cell_side_len, x, y));
            break;
        }
        default:
            goto end;
        }
    }
end:

    DeleteObject(pen);
    DeleteObject(brush);
    ReleaseDC(hwnd, hdc);

    int i;
    std::cin >> i;
}
