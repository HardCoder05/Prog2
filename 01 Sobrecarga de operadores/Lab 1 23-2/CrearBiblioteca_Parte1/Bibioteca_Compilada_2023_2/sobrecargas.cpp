
#include "sobrecargas.h"
using namespace std;

bool operator >>(ifstream &arch,struct Cliente &c){
    arch>>c.dni;
    if(arch.eof()) return false;
    arch.get(); // sacamos la coma
    arch.getline(c.nombre, 50, ',');
    arch>>c.telefono; 
    c.cantidadProductosEntrgados = 0;
    c.montoTotal = 0;
    return true;
}

bool operator >>(ifstream &arch,struct Producto &p){
    arch.getline(p.codigo, 10, ',');
    if(arch.eof()) return false;
    arch.getline(p.descripcion, 60, ',');
    arch>>p.precio;
    arch.get();
    arch>>p.stock;
    p.cantidadClientesServidos = 0;
    p.cantidadClientesNoServidos = 0;
    for(int i=0 ; i<20 ; i++) p.clientesNoServidos[i] = 0;
    for(int i=0 ; i<20 ; i++) p.clientesServidos[i] = 0;
    arch.get();
    return true;
}

bool operator >>(ifstream &arch,struct Pedido &p){
    arch.getline(p.CodigoProducto, 10, ',');
    if(arch.eof()) return false;
    arch>>p.dniCliente;
    arch.get();
    p.precioProducto = 0;
    return true;
}

void operator +=(struct Cliente *cliente,const struct Pedido &pedido) {
    for (int i = 0 ; cliente[i].dni != 0 ; i++) {
      if (cliente[i].dni == pedido.dniCliente) {
        strcpy(cliente[i].productosEntregados[cliente[i].
            cantidadProductosEntrgados].codigo, pedido.CodigoProducto);
        cliente[i].productosEntregados[cliente[i].cantidadProductosEntrgados].
            precio = pedido.precioProducto;
        cliente[i].cantidadProductosEntrgados++;
        cliente[i].montoTotal += pedido.precioProducto;
        break;
      }
    }
}

bool operator +=(struct Producto *producto,struct Pedido &pedido) {
    for (int i = 0 ; strcmp(producto[i].codigo, "XXXXXXX") != 0 ; i++) {
        if(strcmp(producto[i].codigo, pedido.CodigoProducto) == 0){
            if(producto[i].stock > 0){
                producto[i].clientesServidos[producto[i].cantidadClientesServidos] = 
                    pedido.dniCliente;
                producto[i].cantidadClientesServidos++;
                if(producto[i].stock - 1 >= 0) producto[i].stock--;
                pedido.precioProducto = producto[i].precio;
                return true;
            }else{
                producto[i].clientesNoServidos[producto[i].cantidadClientesNoServidos] 
                    = pedido.dniCliente;
                producto[i].cantidadClientesNoServidos++;
                producto[i].stock = 0;
                pedido.precioProducto = producto[i].precio;
                return false;
            }
        }
    }
}

void operator <<(ostream &out, const struct Cliente c){
    out.precision(2);
    out<<fixed;
    out<<c.dni<<"  "<<c.nombre;
    for(int i=0 ; i< 50 - strlen(c.nombre) ; i++) out<<" ";
    out<<setw(12)<<c.telefono<<setw(9)<<c.montoTotal;
    if(c.cantidadProductosEntrgados > 0){
        out<<endl<<"Productos entregados: ";
        for(int i=0 ; i<c.cantidadProductosEntrgados ; i++){
            out<<c.productosEntregados[i].codigo<<setw(8);
        }
        out<<endl;
    }else{
        out<<setw(32)<<"NO SE LE ENTREGARON PRODUCTOS"<<endl;
    }
}

void operator <<(ostream &out, const struct Producto p){
    out.precision(2);
    out<<fixed;
    out<<p.codigo<<" "<<p.descripcion;
    for(int i=0 ; i< 55 - strlen(p.descripcion) ; i++) out<<" ";
    out<<setw(9)<<p.precio<<setw(5)<<p.stock;
    if(p.cantidadClientesNoServidos >= 0 and p.cantidadClientesServidos > 0){
        out<<endl<<"Clientes atendidos: ";
        for(int i=0 ; i<p.cantidadClientesServidos ; i++){
            out<<setw(10)<<p.clientesServidos[i]<<setw(5);
        }
        out<<endl;
        if(p.cantidadClientesNoServidos == 0){
            out<<"NO HAY CLIENTES SIN ATENDER"<<endl;
        }else{
            out<<"Clientes no atendidos: ";
            for(int i=0 ; i<p.cantidadClientesNoServidos ; i++){
                out<<setw(12)<<p.clientesNoServidos[i]<<setw(5);
            }
            out<<endl;
        }
    }else{
        out<<setw(28)<<"NO SE ATENDIERON PEDIDOS"<<endl;
    }
}
