import java.util.Scanner;

class Paciente {
    //atributos dni, nombre, distrito, tiempoTotal, gastosTotales, cantidadDeConsultas
    private int dni;
    private String nombre;
    private String distrito;
    private double tiempoTotal;
    private double gastosTotales;
    private int cantidadDeConsultas;

    //Constructores
    public Paciente(){
        tiempoTotal = 0;
        gastosTotales = 0;
        cantidadDeConsultas = 0;
    }

    public Paciente(int dni, String nombre, String distrito){
        this.dni = dni;
        this.nombre = nombre;
        this.distrito = distrito;
        tiempoTotal = 0;
        gastosTotales = 0;
        cantidadDeConsultas = 0;
    }

    //Metodos selectores para todos los atributos
    public int getDni(){
        return dni;
    }

    public String getNombre(){
        return nombre;
    }

    public String getDistrito(){
        return distrito;
    }

    public double getTiempoTotal(){
        return tiempoTotal;
    }

    public double getGastosTotales(){
        return gastosTotales;
    }

    public int getCantidadDeConsultas(){
        return cantidadDeConsultas;
    }

    //Metodos modificadores para todos los atributos
    public void setDni(int dni){
        this.dni = dni;
    }

    public void setNombre(String nombre){
        this.nombre = nombre;
    }

    public void setDistrito(String distrito){
        this.distrito = distrito;
    }

    public void setTiempoTotal(double tiempoTotal){
        this.tiempoTotal = tiempoTotal;
    }

    public void setGastosTotales(double gastosTotales){
        this.gastosTotales = gastosTotales;
    }

    public void setCantidadDeConsultas(int cantidadDeConsultas){
        this.cantidadDeConsultas = cantidadDeConsultas;
    }

    public boolean leerPaciente(Scanner arch) {
        dni = arch.nextInt();
        if (dni == 0) return false;
        nombre = arch.next();
        distrito = arch.next();

        return true;
    }

    public void mostrarPaciente(){
        System.out.println("DNI: " + dni);
        System.out.println("Nombre: " + nombre);
        System.out.println("Distrito: " + distrito);
        System.out.println("Tiempo total: " + tiempoTotal);
        System.out.println("Gastos totales: " + gastosTotales);
        System.out.println("Cantidad de consultas: " + cantidadDeConsultas);
        System.out.println();
    }
}

