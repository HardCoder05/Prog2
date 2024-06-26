import java.util.ArrayList;
import java.util.Scanner;

class Buses{
    private String codigo;
    private String conductor;
    private ArrayList<String> ruta;
    private int cantPri;
    private int cantTur;

    public Buses(){
        ruta = new ArrayList<String>();
        cantPri = 0;
        cantTur = 0;
    }

    public Buses(String codigo, String conductor, ArrayList<String> ruta, int cantPri, int cantTur){
        this.codigo = codigo;
        this.conductor = conductor;
        this.ruta = ruta;
        this.cantPri = cantPri;
        this.cantTur = cantTur;
    }

    public boolean leerBus(Scanner arch){
        codigo = arch.next();
        if(codigo.compareTo("FIN") == 0) return false;
        conductor = arch.next();
        while(!arch.hasNextInt()){
            String ciudad = arch.next();
            ruta.add(ciudad);
        }
        cantPri = arch.nextInt();
        cantTur = arch.nextInt();

        return true;
    }

    public void mostrarBus(Integer i){
        System.out.println(i+1 + ") Bus: " + codigo);
        //System.out.printf("%d) Bus: %s\n", i, codigo);
        System.out.println("Conductor: " + conductor);
        
        System.out.println("Ruta: ");
        for(String ciudad : ruta){
            System.out.println(ciudad);
        }
        
        System.out.println("Cantidad de pasajeros prioritarios: " + cantPri);
        System.out.println("Cantidad de pasajeros turistas: " + cantTur);
        System.out.println();
    }
}