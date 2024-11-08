public class NewtonRaphson {

    // Declaración del método nativo
    public native double calcularRaiz(double valorInicial, int maxIteraciones, double tolerancia);

    // Cargar la biblioteca nativa
    static {
        System.loadLibrary("numerico"); // Nombre de la biblioteca C (sin extensión)
    }

    public static void main(String[] args) {
        NewtonRaphson nr = new NewtonRaphson();
        double raiz = nr.calcularRaiz(1.0, 100, 0.0001); // Valor inicial, iteraciones y tolerancia
        System.out.println("Raíz calculada: " + raiz);
    }
}

