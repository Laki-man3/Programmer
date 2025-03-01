#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <utility>

// Структуры для хранения данных
struct Vec3 {
    float x, y, z;

    bool operator==(const Vec3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};

struct Edge {
    int v1, v2;

    Edge(int a, int b) {
        // Нормализуем ребро, чтобы меньший индекс всегда был первым
        if (a < b) {
            v1 = a;
            v2 = b;
        }
        else {
            v1 = b;
            v2 = a;
        }
    }

    bool operator<(const Edge& other) const {
        if (v1 != other.v1)
            return v1 < other.v1;
        return v2 < other.v2;
    }
};

struct Face {
    std::vector<int> vertexIndices;
};

// Класс для работы с OBJ-файлами
class ObjModel {
private:
    std::vector<Vec3> vertices;
    std::vector<Face> faces;
    std::set<Edge> edges;
    Vec3 center;
    float scale;
    Vec3 position;
    float faceColor[3];
    float edgeColor[3];
    float edgeWidth;

public:
    ObjModel() : scale(1.0f), position({ 0.0f, 0.0f, 0.0f }), edgeWidth(2.0f) {
        // Цвет граней по умолчанию - светло-серый
        faceColor[0] = 0.8f;
        faceColor[1] = 0.8f;
        faceColor[2] = 0.8f;

        // Цвет рёбер по умолчанию - чёрный
        edgeColor[0] = 0.0f;
        edgeColor[1] = 0.0f;
        edgeColor[2] = 0.0f;
    }
    float getEdgeWidth() const {
        return edgeWidth;
    }
    bool loadFromFile(const std::string& filename) {
        vertices.clear();
        faces.clear();
        edges.clear();

        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Не удалось открыть файл: " << filename << std::endl;
            return false;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string prefix;
            iss >> prefix;

            if (prefix == "v") {
                // Чтение вершины
                Vec3 vertex;
                iss >> vertex.x >> vertex.y >> vertex.z;
                vertices.push_back(vertex);
            }
            else if (prefix == "f") {
                // Чтение грани
                Face face;
                std::string vertexStr;
                while (iss >> vertexStr) {
                    // OBJ индексы начинаются с 1, поэтому вычитаем 1
                    int vertexIndex = std::stoi(vertexStr.substr(0, vertexStr.find('/'))) - 1;
                    face.vertexIndices.push_back(vertexIndex);
                }

                // Добавляем грань
                faces.push_back(face);

                // Извлекаем рёбра из грани
                for (size_t i = 0; i < face.vertexIndices.size(); i++) {
                    int v1 = face.vertexIndices[i];
                    int v2 = face.vertexIndices[(i + 1) % face.vertexIndices.size()];
                    edges.insert(Edge(v1, v2));
                }
            }
        }

        calculateCenter();
        return true;
    }

    void calculateCenter() {
        if (vertices.empty()) return;

        center = { 0.0f, 0.0f, 0.0f };
        for (const auto& v : vertices) {
            center.x += v.x;
            center.y += v.y;
            center.z += v.z;
        }
        center.x /= vertices.size();
        center.y /= vertices.size();
        center.z /= vertices.size();
    }

    void render() const {
        glPushMatrix();

        // Применение трансформаций
        glTranslatef(position.x, position.y, position.z);
        glTranslatef(center.x, center.y, center.z);
        glScalef(scale, scale, scale);
        glTranslatef(-center.x, -center.y, -center.z);

        // Отрисовка граней
        glColor3f(faceColor[0], faceColor[1], faceColor[2]);
        for (const auto& face : faces) {
            if (face.vertexIndices.size() == 3) {
                // Треугольник
                glBegin(GL_TRIANGLES);
                for (int idx : face.vertexIndices) {
                    const Vec3& v = vertices[idx];
                    glVertex3f(v.x, v.y, v.z);
                }
                glEnd();
            }
            else if (face.vertexIndices.size() == 4) {
                // Четырехугольник
                glBegin(GL_QUADS);
                for (int idx : face.vertexIndices) {
                    const Vec3& v = vertices[idx];
                    glVertex3f(v.x, v.y, v.z);
                }
                glEnd();
            }
            else {
                // Многоугольник
                glBegin(GL_POLYGON);
                for (int idx : face.vertexIndices) {
                    const Vec3& v = vertices[idx];
                    glVertex3f(v.x, v.y, v.z);
                }
                glEnd();
            }
        }

        // Отрисовка рёбер
        glColor3f(edgeColor[0], edgeColor[1], edgeColor[2]);
        glLineWidth(edgeWidth);

        glBegin(GL_LINES);
        for (const auto& edge : edges) {
            const Vec3& v1 = vertices[edge.v1];
            const Vec3& v2 = vertices[edge.v2];

            glVertex3f(v1.x, v1.y, v1.z);
            glVertex3f(v2.x, v2.y, v2.z);
        }
        glEnd();

        glPopMatrix();
    }

    void rotate(float angle, float x, float y, float z) {
        glMatrixMode(GL_MODELVIEW);
        glRotatef(angle, x, y, z);
    }

    void translate(float x, float y, float z) {
        position.x += x;
        position.y += y;
        position.z += z;
    }

    void scaleModel(float factor) {
        scale *= factor;
    }

    void setFaceColor(float r, float g, float b) {
        faceColor[0] = r;
        faceColor[1] = g;
        faceColor[2] = b;
    }

    void setEdgeColor(float r, float g, float b) {
        edgeColor[0] = r;
        edgeColor[1] = g;
        edgeColor[2] = b;
    }

    void setEdgeWidth(float width) {
        edgeWidth = width;
    }
};

// Глобальные переменные
ObjModel currentModel;
int selectedShape = 0;
float rotationAngleX = 0.0f;
float rotationAngleY = 0.0f;
std::vector<std::string> shapeFiles = {
    "tetrahedron.obj",
    "cube.obj",
    "octahedron.obj",
    "dodecahedron.obj",
    "icosahedron.obj"
};

bool wireframeMode = false;

// Функции обратного вызова GLUT
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Установка камеры
    gluLookAt(0.0, 0.0, 5.0,  // позиция камеры
        0.0, 0.0, 0.0,  // точка, на которую смотрит камера
        0.0, 1.0, 0.0); // вектор "вверх"

    // Вращение сцены
    glRotatef(rotationAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotationAngleY, 0.0f, 1.0f, 0.0f);

    // Установка режима отображения
    if (wireframeMode) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    // Отрисовка модели
    currentModel.render();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

static int colorIndex = 0;
static int edgeColorIndex = 0;

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Выбор фигуры
    case '1': case '2': case '3': case '4': case '5':
        selectedShape = key - '1';
        currentModel.loadFromFile(shapeFiles[selectedShape]);
        break;

        // Вращение
    case 'q': rotationAngleX += 5.0f; break;
    case 'w': rotationAngleX -= 5.0f; break;
    case 'e': rotationAngleY += 5.0f; break;
    case 'r': rotationAngleY -= 5.0f; break;

        // Перемещение
    case 'a': currentModel.translate(-0.1f, 0.0f, 0.0f); break;
    case 'd': currentModel.translate(0.1f, 0.0f, 0.0f); break;
    case 's': currentModel.translate(0.0f, -0.1f, 0.0f); break;
    case 'f': currentModel.translate(0.0f, 0.1f, 0.0f); break;
    case 'z': currentModel.translate(0.0f, 0.0f, -0.1f); break;
    case 'x': currentModel.translate(0.0f, 0.0f, 0.1f); break;

        // Масштабирование
    case '+': currentModel.scaleModel(1.1f); break;
    case '-': currentModel.scaleModel(0.9f); break;

        // Переключение режима отображения
    case 'm': wireframeMode = !wireframeMode; break;

        // Изменение цвета граней
    case 'c':
        // Циклическое изменение цвета граней (без static)
        colorIndex = (colorIndex + 1) % 6;
        switch (colorIndex) {
        case 0: currentModel.setFaceColor(0.8f, 0.8f, 0.8f); break; // Серый
        case 1: currentModel.setFaceColor(0.8f, 0.4f, 0.4f); break; // Красный
        case 2: currentModel.setFaceColor(0.4f, 0.8f, 0.4f); break; // Зеленый
        case 3: currentModel.setFaceColor(0.4f, 0.4f, 0.8f); break; // Синий
        case 4: currentModel.setFaceColor(0.8f, 0.8f, 0.4f); break; // Желтый
        case 5: currentModel.setFaceColor(0.8f, 0.4f, 0.8f); break; // Фиолетовый
        }
        break;

        // Изменение цвета рёбер
    case 'v':
        // Циклическое изменение цвета рёбер (без static)
        edgeColorIndex = (edgeColorIndex + 1) % 4;
        switch (edgeColorIndex) {
        case 0: currentModel.setEdgeColor(0.0f, 0.0f, 0.0f); break; // Черный
        case 1: currentModel.setEdgeColor(1.0f, 0.0f, 0.0f); break; // Красный
        case 2: currentModel.setEdgeColor(0.0f, 0.0f, 1.0f); break; // Синий
        case 3: currentModel.setEdgeColor(0.0f, 1.0f, 0.0f); break; // Зеленый
        }
        break;
        // Изменение толщины рёбер
    case '[': {
        float currentWidth = currentModel.getEdgeWidth(); // Нужно добавить метод для получения текущей ширины
        currentModel.setEdgeWidth(std::max(1.0f, currentWidth - 0.5f));
        break;
    }
    case ']': {
        float currentWidth = currentModel.getEdgeWidth(); // Нужно добавить метод для получения текущей ширины
        currentModel.setEdgeWidth(std::min(5.0f, currentWidth + 0.5f));
        break;
    }
        // Выход
    case 27: // Escape
        exit(0);
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    // Инициализация GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D .obj viewer");

    // Настройка OpenGL
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    // Загрузка первой модели по умолчанию
    currentModel.loadFromFile(shapeFiles[selectedShape]);

    // Устанавливаем цвета по умолчанию
    currentModel.setFaceColor(0.8f, 0.8f, 0.8f); // Светло-серый для граней
    currentModel.setEdgeColor(0.0f, 0.0f, 0.0f); // Черный для рёбер
    currentModel.setEdgeWidth(2.0f); // Толщина рёбер

    // Регистрация обработчиков событий
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    // Запуск главного цикла
    glutMainLoop();

    return 0;
}