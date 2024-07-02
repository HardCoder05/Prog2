import java.util.Scanner;

abstract class Pasajero {
    int dni;
    String nombre;
    String destino;

    public Pasajero(){
        
    }
    
    public void leerPasajero(Scanner arch){
        dni = arch.nextInt();
        nombre = arch.next();
        destino = arch.next();
    }

    public String getDestino(){
        return destino;
    }

    public void imprime(){
        System.out.println(dni + " " + nombre + " " + destino);
    }


}
