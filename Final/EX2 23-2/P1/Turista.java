import java.util.Scanner;

class Turista extends Pasajero {
    boolean valija;
    boolean almuerzo;
    double tarifaExtra;
    
    public Turista(){
        valija = false;
        almuerzo = false;
        tarifaExtra = 0;
    }

    @Override
    public void leerPasajero(Scanner arch){
        super.leerPasajero(arch);
        String aux = arch.next();
        if(aux.compareTo("S") == 0) valija = true;
        aux = arch.next();
        if(aux.compareTo("S") == 0) almuerzo = true;
        
        if(valija){
            tarifaExtra += 85.5;
        }
        
        if(almuerzo){
            tarifaExtra += 55.9;
        }
    }

    @Override
    public void imprime(){
        super.imprime();
        System.out.println(tarifaExtra);
        System.out.println();
    }

}
