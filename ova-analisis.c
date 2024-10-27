#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void ing_Datos(float ecuacion[], int iter);
void calcDeriv(float ecuacion[], float primDeriv[], int grado, int grado1);
int iteraciones(float ecuacion[], float primDeriv[], int grado, int grado1);
float errorEstimado(float errorAntes, float errorActual);

int main(int argc, char const *argv[]){
    int grado = 0;
    int grado1 = 0;
    int val = 0;
    do{
        printf("\t\t\t\t----------------NEWTON-RAPHSON MEJORADO----------------\n\n");
        printf("\t\tEste programa nos ayudar%c a encontrar una buena aproximaci%cn a la raiz de la funci%cn.",160, 162, 162);
        printf("\n\t\tEl programa puede resolver funciones de grado n.\n");
        printf("\n\t\tReglas:");
        printf("\n\t\tPara llevar a cabo la ejecuci%cn del programa, se debe tener en cuenta lo siguiente:", 162);
        printf("\n\t\t\t1.-Los terminos de la funci%cn pueden llegar a ser n%cmeros racionales, ", 162,163);
        printf("\n\t\t\t   lo cual indica que no abarca los n%cmeros reales.", 163);
        printf("\n\t\t\t2.-Tener cuidado de no teclear alguna letra.\n\n\n");
        while(1){
            printf("\tIngrese el grado mayor del polinomio: ");
            fflush(stdin);
            int aux1 = scanf("%d", &grado);
            if(aux1 != 0 && grado > 0)
                break;
            printf("\t\tIngrese un n%cmero.\n", 163);
        }
    
        float ecuacion[grado];
        ing_Datos(ecuacion, grado);
    
        grado1 = grado - 1;
        float derivada[grado1];
        
        calcDeriv(ecuacion, derivada, grado, grado1);
        val = iteraciones(ecuacion, derivada, grado, grado1);    
    }while(val == 1);
    printf("\n\n\n\n\t\t\t\t----------------%cGRACIAS%c----------------\n\n", 173,33);
    return 0;
}

void ing_Datos(float ecuacion[], int iter){
    float coe;
    int i;
    for(i = iter; i >= 0; i--){
        if(i == 0){  
            while(1){
                printf("\tIngrese el t%crmino independiente: ", 130);
                fflush(stdin);
                float aux1 = scanf("%f", &coe);
                if(aux1 != 0){
                    ecuacion[i] = coe;
                    break;
                } else
                    printf("\t\tIngrese un n%cmero.\n", 163);
            }
        } else{
            while(1){
                printf("\tIngrese el coeficiente de la variable x^%d:  ", i);
                fflush(stdin);
                float aux1 = scanf("%f", &coe);
                if(aux1 != 0){
                    ecuacion[i] = coe;
                    break; 
                } else
                    printf("\t\tIngrese un n%cmero.\n", 163);
            }
        }
    }
}

void calcDeriv(float ecuacion[], float primDeriv[], int grado, int grado1){
    int i = 0;
    for(i = grado1; i >= 0; i--){
        primDeriv[i] = ecuacion[i + 1] * (i + 1);   
    }
}

int iteraciones(float ecuacion[], float primDeriv[], int grado, int grado1){
    int i;
    float sigX = 0;
    float xInicial = 0;
    float erDeseado = 0;
    while(1){
        printf("\n\tIngrese la X inicial: ");
        fflush(stdin);
        float aux1 = scanf("%f", &xInicial);
        if(aux1 != 0)
            break;
        printf("\t\tIngrese un n%cmero.\n", 163);
    }
    
    while(1){
        printf("\tIngrese el error estimado: ");
        fflush(stdin);
        float aux1 = scanf("%f", &erDeseado);
        if(aux1 != 0)
            break;
        printf("\t\tIngrese un n%cmero.\n", 163);
    }
    printf("\n\n\tf(x) = ");
    for(i = grado; i >= 0; i--){
        if(i >= 1)
            printf("%4.2fx^%d + ", ecuacion[i], i );
        else
            printf("%4.2f\n", ecuacion[i]);
    }
    printf("\tf%c(x) = ", 39);
    for(i = grado - 1; i >= 0; i--){
        if(i >= 1)
            printf("%4.2fx^%d + ", primDeriv[i], i );
        else
            printf("%4.2f\n", primDeriv[i]);
    }
    
    int itera = 0;
    printf("\tITERACIONES\t\t\t\tXi\t\t\t\t\t\tEa\n");
    printf("\t%d\t\t\t\t\t%4.6f\t\t\t\t\t-----\n", itera, xInicial);
    float errCalcul = 0;
    do{
        float valor = 0;
        float valor1 = 0;
        
        itera++;

        for(i = grado; i >= 0; i--){
            valor = valor + ecuacion[i] * pow(xInicial, i);
        }

        for(i = grado1; i >= 0; i--){
            valor1 = valor1 + primDeriv[i]*pow(xInicial, i);
        }
        if(valor1 == 0){
            printf("Se est%c realizando una divisi%cn entre cero. ", 160, 162);
            break;
        }

        sigX = xInicial - (valor / valor1);
        
        errCalcul = errorEstimado(xInicial, sigX);
        printf("\t%d\t\t\t\t\t%4.6f\t\t\t\t\t%4.2f%c\n", itera, sigX, errCalcul, 37);
        
        xInicial = sigX;
        sigX = 0;
    }while(errCalcul > erDeseado);
    system("pause");
    int val = 0;
    while(1){
        printf("\n\t\t%cDesea ingresar otra ecuaci%cn%c\n", 168, 162, 63);
        printf("\t\t\tDigite 1 para S%c.\n\t\t\tDigite 2 para No.\n\t\t\t-- ", 161);
        fflush(stdin);
        int aux1 = scanf("%d", &val);
        if(aux1 != 0 && aux1 == 1 || aux1 == 2) 
            break;
        printf("\t\t\t\tIngrese un n%cmero correcto.\n", 163);
    }
    system("cls");
    return val;
}

float errorEstimado(float errorAntes, float errorActual){
    float aux1 = (errorActual - errorAntes)/errorActual;
    if(aux1 < 0)
        aux1 = aux1 * -1;
    float aux = aux1 *100;
    return aux;
}
