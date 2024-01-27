// Tarea1_A01794025.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.//

//Incluír las librerías necesarias
#include <iostream>
#include <omp.h>

//Eliminar los 'std::' de todos los comandos c
using namespace std;

//Definir las constantes del programa
#define N 1000 // Cambia el tamaño de los arreglos, son 1000 según lo sugerido.
#define chunk 500 // Corresponde al número de partes en que se distribuirá la carga de trabajo.
#define mostrar 15 // Describe los valores del arreglo que se mostrarán.

//Función para imprimir valor de los arreglos
void printArreglo(float* d);

int main()
{    
    //Título
    cout << " --- Sumado de Arreglos en Paralelo (Comcurrencia) --- \n\n";
    
    //Variables
    float a[N], b[N], c[N];// Nombre de los arreglos
    int i; //El iterador de los arreglos
    int pedazos = chunk; // Puntua la división de carga

    // Inclusión de los valores en los arreglos a y b
    for (i = 0; i < N; i++)
    {
        //Modificar el cálculo para tener distintos valores
        a[i] = (i + 25) * 13;
        b[i] = (i + 8) * 45;
    }

    //Definir la instrucción 'for' para que se realice en paralelo
    #pragma omp parallel for \
    shared(a,b,c, pedazos) private(i) \
    schedule(static, pedazos)

    //Construir un ciclo para sumar los valores de a + b y son guardados en c
    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    //Imprimimos los resultados
    cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a:\n" << endl;
    printArreglo(a);
    cout <<"\n\n" << endl;
    cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b:\n" << endl;
    printArreglo(b);
    cout << "\n\n" << endl;
    cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c:\n" << endl;
    printArreglo(c);
    cout << "\n\n" << endl;
}

//Declarar la función vacía para imprimir los valores del arreglo

void printArreglo(float* d)
{
    //La variable 'mostrar' controla el número de valores a mostrar

    for (int x = 0; x < mostrar; x++)
    {
        cout << "|" << d[x] << "|\t";
    }
    cout << endl;
}