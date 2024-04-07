
#include "Sobrecarga.h"
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
        cliente[++i].dni = 0;
      }
    }
}

bool operator +=(struct Producto *producto,struct Pedido &pedido) {
    for (int i = 0 ; strcmp(producto[i].codigo, "XXXXXXX") != 0 ; i++) {
        if(strcmp(producto[i].codigo, pedido.CodigoProducto) == 0){
            if(producto[i].stock > 0){
                producto[i].clientesServidos[i] = pedido.dniCliente;
                if(producto[i].stock - 1 >= 0) producto[i].stock--;
                pedido.precioProducto = producto[i].precio;
                strcpy(producto[++i].codigo, "XXXXXXX");
                return true;
            }else{
                producto[i].clientesNoServidos[i] = pedido.dniCliente;
                producto[i].stock = 0;
                pedido.precioProducto = producto[i].precio;
                strcpy(producto[++i].codigo, "XXXXXXX");
                return false;
            }
        }
    }
}

void operator <<(ostream &out, const struct Cliente c){
    out.precision(2);
    out<<fixed;
    out<<c.dni<<" "<<c.nombre;
    for(int i=0 ; i< 60 - strlen(c.nombre) ; i++) out<<" ";
    out<<setw(10)<<c.telefono<<setw(8)<<c.montoTotal;
    if(c.cantidadProductosEntrgados > 0){
        out<<"Productos entregados: ";
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
    for(int i=0 ; i< 60 - strlen(p.descripcion) ; i++) cout<<" ";
    out<<setw(8)<<p.precio<<setw(8)<<p.stock;
    if(p.cantidadClientesNoServidos >= 0 and p.cantidadClientesServidos > 0){
        out<<"Clientes atendidos: ";
        for(int i=0 ; i<p.cantidadClientesServidos ; i++){
            out<<p.clientesServidos[i]<<setw(8);
        }
        out<<endl;
        if(p.cantidadClientesNoServidos == 0){
            out<<"NO HAY CLIENTES SIN ATENDER";
        }else{
            out<<"Clientes no atendidos: ";
            for(int i=0 ; i<p.cantidadClientesNoServidos ; i++){
                out<<p.clientesNoServidos[i]<<setw(8);
            }
            out<<endl;
        }
    }else{
        out<<setw(28)<<"NO SE ATENDIERON PEDIDOS"<<endl;
    }
}

