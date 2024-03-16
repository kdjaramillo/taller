#include <iostream>
#include <string>

using namespace std;

struct RegistroTemperatura {
    string fecha;
    float temperaturaManana;
    float temperaturaTarde;
    float temperaturaNoche;
};

const int MAX_DIAS = 10; // Máximo número de días a registrar

void agregarRegistro(RegistroTemperatura registros[], int dia) {
    cout << "Ingrese la fecha del día " << dia + 1 << " (dd/mm/yyyy): ";
    cin >> registros[dia].fecha;
    cout << "Ingrese la temperatura de la mañana: ";
    cin >> registros[dia].temperaturaManana;
    cout << "Ingrese la temperatura de la tarde: ";
    cin >> registros[dia].temperaturaTarde;
    cout << "Ingrese la temperatura de la noche: ";
    cin >> registros[dia].temperaturaNoche;
}

void mostrarRegistros(const RegistroTemperatura registros[], int numDias) {
    cout << "Registros de temperatura:" << endl;
    for (int i = 0; i < numDias; ++i) {
        cout << "Fecha: " << registros[i].fecha << ", Mañana: " << registros[i].temperaturaManana
             << ", Tarde: " << registros[i].temperaturaTarde << ", Noche: " << registros[i].temperaturaNoche << endl;
    }
}

float calcularPromedioDiario(const RegistroTemperatura& registro) {
    return (registro.temperaturaManana + registro.temperaturaTarde + registro.temperaturaNoche) / 3.0;
}

float calcularPromedioTotal(const RegistroTemperatura registros[], int numDias) {
    float sumaTotal = 0;
    for (int i = 0; i < numDias; ++i) {
        sumaTotal += registros[i].temperaturaManana + registros[i].temperaturaTarde + registros[i].temperaturaNoche;
    }
    return sumaTotal / (3 * numDias);
}

int main() {
    int n;
    cout << "Ingrese el número de días a registrar (máximo " << MAX_DIAS << "): ";
    cin >> n;
    if (n <= 0 || n > MAX_DIAS) {
        cout << "Número de días no válido." << endl;
        return 1;
    }

    RegistroTemperatura registros[MAX_DIAS];

    for (int i = 0; i < n; ++i) {
        cout << "\nRegistro del día " << (i + 1) << ":" << endl;
        agregarRegistro(registros, i);
    }

    mostrarRegistros(registros, n);

    // Calcular promedio de temperatura del día para cada registro
    cout << "\nPromedio de temperatura del día:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Fecha: " << registros[i].fecha << ", Promedio: " << calcularPromedioDiario(registros[i]) << endl;
    }

    // Calcular promedio de temperatura de todos los registros
    cout << "\nPromedio de temperatura de todos los registros: " << calcularPromedioTotal(registros, n) << endl;

    return 0;
}