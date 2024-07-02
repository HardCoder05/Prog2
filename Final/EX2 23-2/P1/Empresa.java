import java.util.ArrayList;
import java.util.Scanner;

class Empresa {
    private ArrayList<Omnibus> flota;

    public Empresa(){
        flota = new ArrayList<Omnibus>();
    }

    public void leerBuses(Scanner arch){
        Omnibus bus;
        while(arch.hasNext()){
            bus = new Omnibus();
            if(bus.leerBus(arch) == false) break;
            flota.add(bus);
        }
    }

    public void leerPasajeros(Scanner arch){
        String tipoPasajero;
        Pasajero pasajero;
        while(arch.hasNext()){
            tipoPasajero = arch.next();
            if(tipoPasajero.compareTo("P") == 0)
                pasajero = new PrimeraClase();
            else
                pasajero = new Turista();
            
            pasajero.leerPasajero(arch);
            
            agregarPasajero(pasajero, tipoPasajero);
        }
    }

    public void agregarPasajero(Pasajero pasajero,String tipoPasajero){
        for(Omnibus bus : flota){
            if(bus.agregar(pasajero, tipoPasajero) == true){
                break;
            }
        }
    }

    public void imprimirBuses(){
        for(Omnibus bus : flota){
            bus.imprimirBuses();
        }
    }

}
