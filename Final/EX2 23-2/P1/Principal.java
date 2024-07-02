import java.util.Scanner;

class Principal {
    public static void main(String[] args) {
        Empresa empresa = new Empresa();
        Scanner sc = new Scanner(System.in);

        empresa.leerBuses(sc);
        empresa.leerPasajeros(sc);
        empresa.imprimirBuses();

    }
}
