#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <windows.h>

// Структура для представления точки с координатами x и y
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // Определение оператора == для структуры Point
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    // Определение оператора != для структуры Point
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
};

// Структура для представления отрезка между двумя точками
struct Segment {
    Point p1, p2;
    double length;

    Segment(Point p1, Point p2) : p1(p1), p2(p2) {
        calculateLength();
    }

    // Определение оператора == для структуры Segment
    bool operator==(const Segment& other) const {
        return (p1 == other.p1 && p2 == other.p2) || (p1 == other.p2 && p2 == other.p1);
    }

    // Определение оператора != для структуры Segment
    bool operator!=(const Segment& other) const {
        return !(*this == other);
    }

private:
    // Вычисление длины отрезка по формуле расстояния между точками
    void calculateLength() {
        length = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    }
};

class Triangulation {
public:
    // Проверка пересечения двух отрезков методом векторного произведения
    static bool doSegmentsIntersect(const Segment& s1, const Segment& s2) {
        double x1 = s1.p1.x, y1 = s1.p1.y;
        double x2 = s1.p2.x, y2 = s1.p2.y;
        double x3 = s2.p1.x, y3 = s2.p1.y;
        double x4 = s2.p2.x, y4 = s2.p2.y;

        // Вычисление определителя для проверки пересечения
        double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
        if (denominator == 0) return false;

        // Вычисление параметров t и u
        double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
        double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

        return (t > 0 && t < 1 && u > 0 && u < 1);
    }

    // Создание всех возможных отрезков между точками
    static std::vector<Segment> createSegments(const std::vector<Point>& points) {
        std::vector<Segment> segments;
        for (size_t i = 0; i < points.size(); ++i) {
            for (size_t j = i + 1; j < points.size(); ++j) {
                segments.push_back(Segment(points[i], points[j]));
            }
        }
        return segments;
    }

    // Проверка условия Делоне для двух треугольников
    static bool isDelaunay(const Point& a, const Point& b, const Point& c, const Point& d) {
        return (a.x - d.x) * (b.y - d.y) - (b.x - d.x) * (a.y - d.y) > 0 &&
            (b.x - d.x) * (c.y - d.y) - (c.x - d.x) * (b.y - d.y) > 0 &&
            (c.x - d.x) * (a.y - d.y) - (a.x - d.x) * (c.y - d.y) > 0;
    }

    // Переворот ребра
    static void flipEdge(std::vector<Segment>& segments, const Segment& edge, const Point& a, const Point& b) {
        segments.push_back(Segment(a, b));
        segments.erase(std::remove(segments.begin(), segments.end(), edge), segments.end());
    }
};

// Класс для отрисовки графических примитивов
class Graphics {
public:
    // Отрисовка точки
    static void drawPoint(HDC hdc, int x, int y) {
        HPEN pen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
        HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
        SelectObject(hdc, pen);
        SelectObject(hdc, brush);
        Ellipse(hdc, x - 3, y - 3, x + 3, y + 3);
        DeleteObject(pen);
        DeleteObject(brush);
    }

    // Отрисовка линии
    static void drawLine(HDC hdc, int x1, int y1, int x2, int y2) {
        HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 255));
        SelectObject(hdc, pen);
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        DeleteObject(pen);
    }

    // Очистка экрана
    static void clearScreen(HDC hdc) {
        RECT rect;
        GetClientRect(GetConsoleWindow(), &rect);
        HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
        FillRect(hdc, &rect, blackBrush);
        DeleteObject(blackBrush);
    }
};

// Класс для обновления и отрисовки триангуляции
class TriangulationUpdater {
public:
    // Основной метод обновления отображения
    static void update(HDC hdc, const std::vector<Point>& points) {
        Graphics::clearScreen(hdc);
        drawPoints(hdc, points);
        drawTriangulation(hdc, points);
    }

private:
    // Отрисовка всех точек
    static void drawPoints(HDC hdc, const std::vector<Point>& points) {
        for (const Point& p : points) {
            Graphics::drawPoint(hdc, p.x, p.y);
        }
    }

    // Построение и отрисовка триангуляции
    static void drawTriangulation(HDC hdc, const std::vector<Point>& points) {
        auto segments = Triangulation::createSegments(points);

        // Сортировка отрезков по длине для жадного алгоритма
        std::sort(segments.begin(), segments.end(),
            [](const Segment& a, const Segment& b) {
                return a.length < b.length;
            });

        // Применение жадного алгоритма для построения триангуляции
        std::vector<Segment> acceptedSegments;
        for (const Segment& segment : segments) {
            if (canAddSegment(segment, acceptedSegments)) {
                acceptedSegments.push_back(segment);
                Graphics::drawLine(hdc, segment.p1.x, segment.p1.y,
                    segment.p2.x, segment.p2.y);
            }
        }

        // Применение условия Делоне
        applyDelaunayCondition(acceptedSegments, points);
    }

    // Проверка возможности добавления нового отрезка
    static bool canAddSegment(const Segment& segment,
        const std::vector<Segment>& acceptedSegments) {
        for (const Segment& accepted : acceptedSegments) {
            if (Triangulation::doSegmentsIntersect(segment, accepted)) {
                return false;
            }
        }
        return true;
    }

    // Применение условия Делоне
    static void applyDelaunayCondition(std::vector<Segment>& segments, const std::vector<Point>& points) {
        for (const Segment& edge : segments) {
            for (const Point& p : points) {
                if (p != edge.p1 && p != edge.p2) {
                    Point a = edge.p1;
                    Point b = edge.p2;
                    Point c = p;
                    for (const Segment& otherEdge : segments) {
                        if (otherEdge.p1 == a && otherEdge.p2 == c) {
                            Point d = otherEdge.p2;
                            if (!Triangulation::isDelaunay(a, b, c, d)) {
                                Triangulation::flipEdge(segments, edge, c, d);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
};

// Обработчик событий окна
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static std::vector<Point> points;
    static HDC hdc;

    switch (uMsg) {
        // Обработка создания окна
    case WM_CREATE: {
        hdc = GetDC(hwnd);
        Graphics::clearScreen(hdc);
        return 0;
    }

                  // Обработка клика мыши
    case WM_LBUTTONDOWN: {
        int xPos = LOWORD(lParam);
        int yPos = HIWORD(lParam);
        points.push_back(Point(xPos, yPos));
        TriangulationUpdater::update(hdc, points);
        return 0;
    }

                       // Обработка закрытия окна
    case WM_DESTROY: {
        ReleaseDC(hwnd, hdc);
        PostQuitMessage(0);
        return 0;
    }

                   // Обработка перерисовки окна
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        TriangulationUpdater::update(hdc, points);
        EndPaint(hwnd, &ps);
        return 0;
    }

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int main() {
    HINSTANCE hInstance = GetModuleHandle(NULL);

    // Регистрация класса окна
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"TriangulationWindow";
    wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
    RegisterClass(&wc);

    // Создание главного окна приложения
    HWND hwnd = CreateWindowEx(
        0,
        L"TriangulationWindow",
        L"Triangulation",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) return 0;

    ShowWindow(hwnd, SW_SHOW);

    // Главный цикл обработки сообщений
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
