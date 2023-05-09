#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ��������� ��� �����
struct Point {
    double x;
    double y;
};

// ��������� ��� �����
struct Ellipse {
    struct Point center;    // ����� �����
    double a;               // ������� ������ a
    double b;               // ������� ������ b
};

// ������� ��� ���������� ����� �����
double ellipse_area(struct Ellipse *e) {
    return M_PI * e->a * e->b;
}

// ������� ��� ��������� �����
struct Ellipse* create_ellipse(struct Point *center, double a, double b) {
    // �������� ������� ���������
    if (center == NULL) {
        printf("Error: invalid center point!\n");
        return NULL;
    }
    if (a <= 0 || b <= 0) {
        printf("Error: invalid semi-axes length!\n");
        return NULL;
    }
    // ��������� ������ �����
    struct Ellipse* e = (struct Ellipse*) malloc(sizeof(struct Ellipse));
    e->center = *center;
    e->a = a;
    e->b = b;
    return e;
}

// ������� ��� �������� �����
void destroy_ellipse(struct Ellipse *e) {
    free(e);
}

// ������� ��� ������ ��������� ����� �� �����
void print_ellipse(struct Ellipse *e) {
    printf("Ellipse: center=(%.2f, %.2f), a=%.2f, b=%.2f, area=%.2f\n",
           e->center.x, e->center.y, e->a, e->b, ellipse_area(e));
}

int main() {
    // ������� ������������
    struct Point center = {0, 0};
    double a = 5;
    double b = 3;
    struct Ellipse *e = create_ellipse(&center, a, b);
    if (e != NULL) {
        print_ellipse(e);
        destroy_ellipse(e);
    }
    return 0;
}
