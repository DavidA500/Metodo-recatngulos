#include <iostream>
#include <cmath>

using namespace std;

class Funcion {
public:
    double operator()(double x) const {
        // Función: f(x) = 1/(sqrt(x)+1)
        return 1/(sqrt(x)+1);
    }
};

class MetodoRectangulos {
public:
    double calcularIntegral(const Funcion& funcion, double a, double b, int n) const {
        double h = (b - a) / n;  // Tamaño del intervalo

        double suma = 0.0;
        for (int i = 0; i < n; i++) {
            double x = a + i * h;  // Punto medio del rectángulo
            suma += funcion(x);
        }

        return suma * h;
    }
};

int main() {
    double a, b;
    int n;
    int decimales;

    cout << "Ingrese el límite inferior (a): ";
    cin >> a;
    cout << "Ingrese el límite superior (b): ";
    cin >> b;
    cout << "Ingrese el número de subintervalos (n): ";
    cin >> n;
    cout << "Ingrese la cantidad de decimales a calcular: ";
    cin >> decimales;

    cout.precision(decimales);  // Establece la precisión decimal

    Funcion funcion;
    MetodoRectangulos metodoRectangulos;

    cout << "La ecuación de la función es: f(x) = 1/(sqrt(x)+1)" << endl;

    double integral = metodoRectangulos.calcularIntegral(funcion, a, b, n);

    cout << "El valor aproximado de la integral es: " << fixed << integral << endl;

    return 0;
}
