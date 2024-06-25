import java.util.ArrayList;
import java.util.Scanner;

class ClinicaLP1 {
    private ArrayList<Medico> medicos;
    private ArrayList<Paciente> pacientes;

    //Constructor
    public ClinicaLP1(){
        medicos = new ArrayList<Medico>();
        pacientes = new ArrayList<Paciente>();
    }

    public void leerDatos() {
        Scanner arch = new Scanner(System.in);

        leerMedicos(arch);
        leerPacientes(arch);
        leerConsultas(arch);
    }

    private void leerMedicos(Scanner arch) {
        while (arch.hasNext()) {
            Medico medico = new Medico();
            if (medico.leerMedico(arch) == false) break;
            medicos.add(medico);
        }
    }

    private void leerPacientes(Scanner arch) {
        while (arch.hasNext()) {
            Paciente paciente = new Paciente();
            if (paciente.leerPaciente(arch) == false) break;
            pacientes.add(paciente);
        }
    }

    private void leerConsultas(Scanner arch) {
        while (arch.hasNext()) {
            int dni = arch.nextInt();
            int codigo = arch.nextInt();
            int hIni = arch.nextInt();
            int minIni = arch.nextInt();
            int segIni = arch.nextInt();
            int hFin = arch.nextInt();
            int minFin = arch.nextInt();
            int segFin = arch.nextInt();

            int tiempo = (hFin - hIni) * 3600 + (minFin - minIni) * 60 + (segFin - segIni);

            // Buscar medico
            Medico medico = buscarMedico(codigo);

            // Buscar paciente
            Paciente paciente = buscarPaciente(dni);

            // Agregar consulta
            if (medico != null && paciente != null) {
                agregarConsulta(medico, paciente, tiempo);
            }
        }
    }

    private Medico buscarMedico(int codigo) {
        for (Medico medico : medicos) {
            if (medico.getCodigo() == codigo) {
                return medico;
            }
        }
        return null;
    }

    private Paciente buscarPaciente(int dni) {
        for (Paciente paciente : pacientes) {
            if (paciente.getDni() == dni) {
                return paciente;
            }
        }
        return null;
    }

    private void agregarConsulta(Medico medico, Paciente paciente, int tiempo) {
        medico.setTiempoTotal(medico.getTiempoTotal() + tiempo);
        medico.setIngresosTotales(medico.getIngresosTotales() + (tiempo / 3600.0) * medico.getTarifa());
        medico.setCantidadDeConsultas(medico.getCantidadDeConsultas() + 1);

        paciente.setTiempoTotal(paciente.getTiempoTotal() + tiempo);
        paciente.setGastosTotales(paciente.getGastosTotales() + (tiempo / 3600.0) * medico.getTarifa());
        paciente.setCantidadDeConsultas(paciente.getCantidadDeConsultas() + 1);
    }

    public void mostrarDatos(){
        System.out.println("MEDICOS: ");
        for(Medico medico : medicos){
            medico.mostrarMedico();
        }

        System.out.println("PACIENTES: ");
        for(Paciente paciente : pacientes){
            paciente.mostrarPaciente();
        }
    }
}

