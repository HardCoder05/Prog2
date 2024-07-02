import java.util.ArrayList;
import java.util.Scanner;

class PrimeraClase extends Pasajero {
    private ArrayList<String> articulosSolicitados;

    public PrimeraClase(){
        articulosSolicitados = new ArrayList<String>();
    }

    @Override
    public void leerPasajero(Scanner arch){
        super.leerPasajero(arch);
        int cantidadArticulos = arch.nextInt();
        for(int i = 0; i < cantidadArticulos; i++){
            String articulo = arch.next();
            articulosSolicitados.add(articulo);
        }
    }

    @Override
    public void imprime(){
        super.imprime();
        for(String articulo : articulosSolicitados){
            System.out.print(articulo + " ");
        }
        System.out.println(); 
        System.out.println(); 
    }


}
