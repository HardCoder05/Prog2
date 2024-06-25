import java.util.Scanner;

class Medico{
    private int codigo;
    private String nombre;
    private String especialidad;
    private double tarifa;
    private double tiempoTotal;
    private double ingresosTotales;
    private int cantidadDeConsultas;

    //Constructores
    public Medico(){
        tiempoTotal = 0;
        ingresosTotales = 0;
        cantidadDeConsultas = 0;
    }

    public Medico(int codigo, String nombre, String especialidad, double tarifa){
        this.codigo = codigo;
        this.nombre = nombre;
        this.especialidad = especialidad;
        this.tarifa = tarifa;
        tiempoTotal = 0;
        ingresosTotales = 0;
        cantidadDeConsultas = 0;
    }

    //Metodos selectores para todos los atributos
    public int getCodigo(){
        return codigo;
    }

    public String getNombre(){
        return nombre;
    }

    public String getEspecialidad(){
        return especialidad;
    }

    public double getTarifa(){
        return tarifa;
    }

    public double getTiempoTotal(){
        return tiempoTotal;
    }

    public double getIngresosTotales(){
        return ingresosTotales;
    }

    public int getCantidadDeConsultas(){
        return cantidadDeConsultas;
    }

    //Metodos modificadores para todos los atributos
    public void setCodigo(int codigo){
        this.codigo = codigo;
    }

    public void setNombre(String nombre){
        this.nombre = nombre;
    }

    public void setEspecialidad(String especialidad){
        this.especialidad = especialidad;
    }

    public void setTarifa(double tarifa){
        this.tarifa = tarifa;
    }

    public void setTiempoTotal(double tiempoTotal){
        this.tiempoTotal = tiempoTotal;
    }

    public void setIngresosTotales(double ingresosTotales){
        this.ingresosTotales = ingresosTotales;
    }

    public void setCantidadDeConsultas(int cantidadDeConsultas){
        this.cantidadDeConsultas = cantidadDeConsultas;
    }

    public boolean leerMedico(Scanner arch) {
        codigo = arch.nextInt();
        if (codigo == 0) return false;
        nombre = arch.next();
        especialidad = arch.next();
        tarifa = arch.nextDouble();

        return true;
    }
    
    public void mostrarMedico(){
        System.out.println("Codigo: " + codigo);
        System.out.println("Nombre: " + nombre);
        System.out.println("Especialidad: " + especialidad);
        System.out.println("Tarifa: " + tarifa);
        System.out.println("Tiempo total: " + tiempoTotal);
        System.out.println("Ingresos totales: " + ingresosTotales);
        System.out.println("Cantidad de consultas: " + cantidadDeConsultas);
        System.out.println();
    }
}


