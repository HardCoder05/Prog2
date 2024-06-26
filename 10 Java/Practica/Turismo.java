import java.util.ArrayList;
import java.util.Scanner;

class Turismo {
    private ArrayList<Buses> buses;

    public Turismo(){
        buses = new ArrayList<Buses>();
    }

    public void leerBuses(){
        Scanner arch = new Scanner(System.in);
        Buses bus;
        while(arch.hasNext()){
            bus = new Buses();
            if(bus.leerBus(arch) == false) break;
            buses.add(bus);
        }
    }

    public void mostrarBuses(){
        Integer i = 0;
        for(Buses bus : buses){
            bus.mostrarBus(i++);
        }
    }
}
