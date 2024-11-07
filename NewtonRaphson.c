#include <stdio.h>
#include <math.h>
#include <jni.h>
#include "NewtonRaphson.h"

// Función para calcular f(x) = x^2 - 2
double f(double x) {
    return x*x - 2;
}

// Derivada de f(x) = 2x
double f_prime(double x) {
    return 2*x;
}

// Método de Newton-Raphson
JNIEXPORT jdouble JNICALL Java_NewtonRaphson_calcularRaiz
  (JNIEnv *env, jobject obj, jdouble valorInicial, jint maxIteraciones, jdouble tolerancia) {
    
    double x0 = valorInicial;
    double x1;
    int iter = 0;

    // Iteración del método de Newton-Raphson
    while (iter < maxIteraciones) {
        // Calculamos f(x0) y f'(x0)
        double fx0 = f(x0);
        double fx0_prime = f_prime(x0);
        
        // Actualizamos el valor de x usando la fórmula de Newton-Raphson
        x1 = x0 - fx0 / fx0_prime;
        
        // Verificamos si la diferencia es menor que la tolerancia
        if (fabs(x1 - x0) < tolerancia) {
            break;
        }

        x0 = x1;
        iter++;
    }

    // Devolver la raíz encontrada
    return x1;
}

