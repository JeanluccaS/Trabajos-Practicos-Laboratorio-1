ypedef struct{
   int id;
   char nombre[51];
   char apellido[51];
   float salario;
   int sector;
   int estaVacio;// 0 para esta vacio, 1 para no esta vacio

}eEmpleado;

void inicializarEmpleados(eEmpleado[],int cantidad,int estado);
void hardcodearEmpleados(eEmpleado[],int cantidad);
int listarEmpleados(eEmpleado[],int cantidad);
void mostrarEmpleado(eEmpleado);
int dameIndiceLibre(eEmpleado[],int cantidad);
int cargarEmpleados (eEmpleado listaDe[],int cantidad);
void pedirString (char mensaje[],char contenido[],char mensajeDeError[]);
int pedirEntero (char mensaje[]);
int buscarEmpleado(eEmpleado[],int cantidad);
int borrarEmpleado(eEmpleado[],int cantidad);
eEmpleado cargarEmpleado (void);
int modificarEmpleado(eEmpleado[],int cantidad);
