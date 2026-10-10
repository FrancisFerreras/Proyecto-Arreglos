#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    const int TAM = 5;
    float calificaciones[TAM] = {85, 67, 92, 74, 58};
    int opcion;


    do {
        cout << "\n=== SISTEMA DE CALIFICACIONES ===\n";
        cout << "1. Mostrar calificaciones\n";
        cout << "2. Consultar calificacion por indice\n";
        cout << "3. Mostrar estadisticas\n";
        cout << "4. Modificar calificacion\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;


        if (opcion == 1) {
            cout << "\nCalificaciones actuales:\n";
            for (int i = 0; i < TAM; i++) {
                cout << "Indice " << i << ": "
                     << calificaciones[i] << '\n';
            }
        } else if (opcion == 2) {
            int indice;
            cout << "Ingrese un indice entre 0 y " << TAM - 1 << ": ";
            cin >> indice;


            if (indice >= 0 && indice < TAM) {
                cout << "Calificacion en el indice " << indice
                     << ": " << calificaciones[indice] << '\n';
            } else {
                cout << "Error: indice fuera de rango.\n";
            }
        } else if (opcion == 3) {
            float suma = 0;
            float mayor = calificaciones[0];
            float menor = calificaciones[0];
            int aprobados = 0, reprobados = 0;


            for (int i = 0; i < TAM; i++) {
                suma += calificaciones[i];


                if (calificaciones[i] > mayor)
                    mayor = calificaciones[i];
                if (calificaciones[i] < menor)
                    menor = calificaciones[i];


                if (calificaciones[i] >= 70)
                    aprobados++;
                else
                    reprobados++;
            }


            cout << fixed << setprecision(2);
            cout << "Promedio: " << suma / TAM << '\n';
            cout << "Calificacion mas alta: " << mayor << '\n';
            cout << "Calificacion mas baja: " << menor << '\n';
            cout << "Aprobados: " << aprobados << '\n';
            cout << "Reprobados: " << reprobados << '\n';
        } else if (opcion == 4) {
            int indice;
            float nuevaNota;
            cout << "Indice que desea modificar (0-" << TAM - 1 << "): ";
            cin >> indice;


            if (indice >= 0 && indice < TAM) {
                cout << "Ingrese la nueva calificacion (0-100): ";
                cin >> nuevaNota;


                if (nuevaNota >= 0 && nuevaNota <= 100) {
                    calificaciones[indice] = nuevaNota;
                    cout << "Calificacion actualizada correctamente.\n";
                    cout << "Nuevo vector: ";
                    for (int i = 0; i < TAM; i++)
                        cout << calificaciones[i] << " ";
                    cout << '\n';
                } else {
                    cout << "Error: la nota debe estar entre 0 y 100.\n";
                }
            } else {
                cout << "Error: indice fuera de rango.\n";
            }
        } else if (opcion != 0) {
            cout << "Opcion no valida.\n";
        }
    } while (opcion != 0);


    cout << "Programa finalizado.\n";
    return 0;
}



