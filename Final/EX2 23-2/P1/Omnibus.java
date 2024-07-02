import java.util.ArrayList;
import java.util.Scanner;

class Omnibus{
    private String placa;
    private String chofer;
    private ArrayList<String> ruta;
    private int asientosPC;
    private int asientosCT;
    private ArrayList<Pasajero> pasajeros;

    public Omnibus(){
        ruta = new ArrayList<String>();
        pasajeros = new ArrayList<Pasajero>();
    }

    public int getAsientosPC(){
        return asientosPC;
    }

    public int getAsientosCT(){
        return asientosCT;
    }

    public void setAsientosPC(int asientosPC){
        this.asientosPC = asientosPC;
    }

    public void setAsientosCT(int asientosCT){
        this.asientosCT = asientosCT;
    }

    public boolean leerBus(Scanner arch){
        placa = arch.next();
        if(placa.compareTo("FIN") == 0) return false;
        chofer = arch.next();
        while(!arch.hasNextInt()){
            String ciudad = arch.next();
            ruta.add(ciudad);
            //ruta.add(arch.next());
        }
        asientosPC = arch.nextInt();
        asientosCT = arch.nextInt();
        return true;
    }

    public boolean agregar(Pasajero pasajero,String tipoPasajero){
        for(String ciudad : ruta){
            if(ciudad.compareTo(pasajero.getDestino()) == 0){
                if(tipoPasajero.compareTo("P") == 0){
                    if(asientosPC > 0){
                        pasajeros.add(pasajero);
                        asientosPC--;
                        return true;
                    }
                }else if(tipoPasajero.compareTo("T") == 0){
                    if(asientosCT > 0){
                        pasajeros.add(pasajero);
                        asientosCT--;
                        return true;
                    }
                }
            }
        }

        return false;
    }

    public void imprimirBuses(){
        System.out.println("Placa: " + placa);
        System.out.println("Chofer: " + chofer);
        System.out.println("Ruta: ");
        for(String ciudad : ruta){
            System.out.println(ciudad);
        }
        System.out.println("Asientos PC: " + asientosPC);
        System.out.println("Asientos CT: " + asientosCT);
        System.out.println("Pasajeros: ");
        for(Pasajero pasajero : pasajeros){
            pasajero.imprime();
        }
        System.out.println();
    }


}