#include <iostream>
#include <cstdlib>

using namespace std;

// Definicion clase Avion.
class Avion
{
private:
    int id_avion;
    string nombre;
    int estatus; //"1 = volando", "2 = aterrizando", "3 = estacionado", "4 = Asignado a un Vuelo"
    bool estado = true;

public:
    Avion();
    void setAvion(int, string, int); // Metodo para asignar un nombre y un estado a un  avion.
    void setEstatus(int); // Metodo para establecer el estatus del avion
    void setEstado(bool); // Metodo para establecer el estado del avion

    string getNombreAvion(); // Metodo para obtener el nombre del avion
    int getEstatus();        // Metodo para obtener el estatus del avion
    bool getEstado();        // Metodo para obtener el estado del avion

    void infoAvion(); ////Metodo para obtener la informacion del avion
};

Avion::Avion(){

};

//Metodo para registrar datos de un objeto avion
void Avion::setAvion(int _id_avion, string _nombre, int _estatus)
{
    id_avion = _id_avion + 1; //al id_avion recibido le aumentamos 1 para crear el nuevo avion 
    nombre = _nombre;
    estatus = _estatus;

    cout << "Avion Registrado !!" << endl;
};

void Avion::setEstatus(int _estatus)
{
    estatus = _estatus;
}

void Avion::setEstado(bool _estado)
{
    estado = _estado;
}

string Avion::getNombreAvion()
{
    return nombre;
}

void Avion::infoAvion()
{
    string estadoString, estatusString;

    //Examinamos el estatus del avion que es un numero entero y lo convertimos en una cadena de caracteres para su lectura;
    if (estatus == 1)
    {
        estatusString = "Volando";
    }
    else if (estatus == 2)
    {
        estatusString = "Aterrizando";
    }
    else if (estatus == 3)
    {
        estatusString = "Estacionado";
    }
    else if (estatus == 4)
    {
        estatusString = "Asignado a Vuelo";
    }
    else
    {
        estatusString = "No hay estado para el estado de avion ";
    }

    //Examinamos el estado del avion verdadero o falso para mostrar si esta en funcionamiento o no.
    if (estado == true)
    {
        estadoString = "En funcionamiento";
    }
    else
    {
        estadoString = "Fuera de Servicio";
    }

    //imprimimos por pantalla la informacion del avion
    cout << "\n" << id_avion << ". Nombre: " << nombre << " Estado: " << estadoString << " Estatus: " << estatusString << endl;
}

int Avion::getEstatus()
{
    return estatus;
}

bool Avion::getEstado()
{
    return estado;
}

// Definicion de la clase vuelo
class Vuelo
{
    private:
        int num_vuelo, avion, estatus; //Estatus: 1. Activo, 2. Suspendido, 3. Agotado.
        string hora_salida;
        string origen, destino;
        

    public:
        Vuelo();
        void setEstatusVuelo(int); //Metodo para modificar el estatus del vuelo

        int getIdAvion(); //Metodo para obtener el id del avion asignado al vuelo
        int getNumVuelo(); //Metodo para obtener el numero de vuelo
        int getEstatus(); //Metodo para obtener el estatus del vuelo
        string getDestion(); //Metodo para obtener el lugar de destino

        void registrarVuelo(int, string, string, string, int, int); // Metodo para registrar un vuelo
        void infoVuelo();                                           // Metodo para ver la informacion de un vuelo.
};

Vuelo::Vuelo(){

};

int Vuelo::getIdAvion() 
{
    return Vuelo::avion;
}

int Vuelo::getNumVuelo() {
    return num_vuelo;
}

int Vuelo::getEstatus() {
    return estatus;
}

string Vuelo::getDestion() {
    return destino;
}

void Vuelo::setEstatusVuelo(int _estatus)
{
    estatus = _estatus;
}

void Vuelo::registrarVuelo(int _num_vuelo, string _hora_salida, string _origen, string _destino, int _avion, int _estatus)
{
    num_vuelo = _num_vuelo;
    hora_salida = _hora_salida;
    origen = _origen;
    destino = _destino;
    avion = _avion;
    estatus = _estatus;
}

void Vuelo::infoVuelo()
{
    string stringEstatus;

    //Examinamos el estatus del vuelo que es un numero entero y lo convertimos en una cadena de caracteres para mostrar
    if (estatus == 1)
    {
        stringEstatus = "Activo";
    }
    else if (estatus == 2)
    {
        stringEstatus = "Suspendido";
    }
    else if (estatus == 3)
    {
        stringEstatus = "Agotado";
    }

    //Mostramos la informacion del vuelo por pantalla
    cout << "Num. vuelo: " << num_vuelo << " Origen: " << origen << " Destino: " << destino << " Hora Salida: " << hora_salida << " Estatus: " << stringEstatus << endl;
}

// Definicion de la clase aeropuerto
class Aeropuerto
{
private:
    Avion aviones[10]; //Array para almacenar los objetos avion
    Vuelo vuelos[10]; //Array para almacenar los objetos vuelos 
    Vuelo pistas[10]; //Array para almacenar los objetos vuelos que se asignen a un pista

public:
    Aeropuerto();
    void setAvion(Avion);   // Metodo para insertar la informacion de un avion en array aviones
    void setEstatusAvion(int, int); //Metodo para modificar el estatus de un avion desde el aeropuerto
    void reportesAviones(); // Metodo para listar los aviones existentes en el aeropuerto
    int getIdAvionVuelo(int); // Metodo para obtener desde aeropuerto el id_avion asignado a un vuelo
    Avion getAvion(int); // Metodo para obtener un objeto avion dentro del array de aeropueto

    void setVuelo(Vuelo); // Metodo para insertar la informacion de un vuelo en array vuelos.
    void reporteVuelos(); // Metodo de reporte de los vuelos registrados
    void cancelarVuelo(); // Metodo para cancelar un vuelo cambiando su estado a suspendido
    Vuelo getVuelo(int); // Metodo para obtener un objeto vuelo dentro del array de aeropuerto

    int getLongitudArrayVuelos(); //Metodo para recorrer el array de vuelo y ver cuantos vuelos hay en el
    int getLongitudArrayAviones(); //Metodo para recorrer el array de aviones y ver cuantos aviones hay en el
    int getLongitudArrayPistas(); //Metodo para recorrer el array de pistas y ver cuantos vuelos hay en el

    void asignarPista(Vuelo); //Metodo para guardar en el array pista un vuelo
    void reportePistas(); // Metodo que muestra reporte de las pistas
};

Aeropuerto::Aeropuerto(){};

void Aeropuerto::setAvion(Avion _avion)
{   
    //recibimos como parametro un objeto _avion para insertarlo en el array aviones


    int cant_aviones; //variable para almacenar la cantidad de aviones registrados.

    cant_aviones = getLongitudArrayAviones(); // usamos el metodo para obtener la cantidad de aviones registrados

    cout << "Total Aviones: " << cant_aviones << endl;

    if (cant_aviones >= 1) // Comprobamos si ya tenemos aviones registrados de ser asi se inserta en su posicion del array aviones
    {
        aviones[cant_aviones] = _avion; //insertamos el objeto _avion en el array segun la cantidad de aviones registrados
        cout << "Guardado en la posicion " << cant_aviones << endl;
    }
    else
    {
        aviones[0] = _avion; // si no hay aviones registrados el primer avion se registra en la posicion 0 del array aviones
        cout << "Guardado en la posicion 0" << endl;
    }

    cout << "Impresion info avion: " << endl;
    _avion.infoAvion();
}

void Aeropuerto::setEstatusAvion(int id_avion, int _estatus) {
    //recibimos como parametros en id_avion a buscar y el estatus a modificar
    //como los aviones estan enumerados del 1 al 10, pero el array empieza en la posicion 0 le restamos 1 al id_avion obtenido para conocer la posicion del avion en el array.

    aviones[id_avion - 1].setEstatus(_estatus); //una vez obtenemos el avion del array modificamos su estatus
    cout << "Estatus del Avion " << id_avion << " modificado !!" << endl;
}

void Aeropuerto::reportesAviones()
{
    
    //hacemos uso de la funcion sizeof para obtener el tamaño total en bytes del array aviones y luego lo dividimos por el tamaño en bytes de su primera posicion para conocer el tamaño del arreglo aviones.

    int longitud_array_aviones = sizeof(aviones) / sizeof(aviones[0]);

    cout << "------------ LISTA DE AVIONES --------------" << endl;
    cout << "Cantidad: " << getLongitudArrayAviones() << endl;

    if (getLongitudArrayAviones() > 0) //comprobamos si hay aviones registrados
    {
        for (int i = 0; i < longitud_array_aviones; i++)
        {
            if (aviones[i].getNombreAvion() != "") // Si hay aviones registrados comprobamos sus nombres si es diferente de vacio "" 
            {
                aviones[i].infoAvion(); //si es diferente mostramos su informacion.
            }
            else
            {
                break; //sino rompemos el ciclo
            }
        }
    }
    else
    {
        cout << "No hay aviones registrados !!" << endl;
    }
}

int Aeropuerto::getIdAvionVuelo(int _num_vuelo) 
{   
    //retornamos en id_avion registrado en el vuelo pasando como parametro el numero de vuelo.
    //como los vuelos esta enumerados del 1 al 10, pero el array empieza en 0 le restamos 1 al num_vuelo obtenido para conocer la posicion del vuelo en el array
    return vuelos[_num_vuelo - 1].getIdAvion();
}

Avion Aeropuerto::getAvion(int _id_avion)
{   
    //retonamos el objeto avion en el array aviones pasando como parametro el id_avion.
    //para conocer su posicion hacemos el mismo procedimiento de restar 1 al id_avion para obtener su posicion
    return aviones[_id_avion - 1];
}

void Aeropuerto::setVuelo(Vuelo _vuelo)
{
    int cant_vuelos = getLongitudArrayVuelos(); //obtenemos la cantidad de vuelos registrados;

    vuelos[cant_vuelos] = _vuelo; //insertamos el vuelo en el array segun la cantidad de vuelos registrados
    cout << "Guardado en la posicion " << cant_vuelos << endl;
   
    cout << "Informacion del vuelo" << endl;
    _vuelo.infoVuelo();
}

void Aeropuerto::reporteVuelos()
{
    int longitud_array_vuelos = sizeof(vuelos) / sizeof(vuelos[0]); //mismo procedimiento utilizado para conocer el tamñado del array aviones, aplicado al array vuelos;

    cout << "------------ LISTA DE VUELOS ------------" << endl;
    cout << "Cantidad: " << getLongitudArrayVuelos() << endl;

    if (getLongitudArrayVuelos() > 0) //comprobamos si hay vuelos registrados
    {
        for (int i = 0; i < longitud_array_vuelos; i++)
        {   
            if (vuelos[i].getDestion() != "") //si hay vuelos registrados recorremos el array vuelos verificando que exista un destino para cada vuelo
            {
                vuelos[i].infoVuelo(); //si hay un destino mostramos la informacion del vuelo para listarlo
            }
            else
            {
                break; //si no hay rompemos el ciclo
            }
        }
    }
    else
    {
        cout << "No hay vuelos registrados !!" << endl;
    }
}

void Aeropuerto::cancelarVuelo()
{

    cout << "-------------LISTA DE VUELOS--------------" << endl;
    cout << "Cantidad: " << getLongitudArrayVuelos() << endl;

    if (getLongitudArrayVuelos() > 0) //Comprobamos si hay vuelos registrados
    {
        int num_vuelo; //variable para almacenar el numero de vuelo a cancelar

        for (int i = 0; i < getLongitudArrayVuelos(); i++)
        {
            vuelos[i].infoVuelo(); //listamos los vuelos  insertados en el array vuelos
        }
        cout << "ingrese el numero de vuelo que desea cuyo estatus va a modificar: " << endl;
        cin >> num_vuelo;


        vuelos[num_vuelo - 1].setEstatusVuelo(2); // Buscamos la posicion del vuelo en el array restando 1 al num_vuelo y Modificamos el estatus del vuelo;
    }
    else
    {
        cout << "No hay vuelos registrados !!" << endl;
    }
}

Vuelo Aeropuerto::getVuelo(int _num_vuelo)
{   
    //recibimos como parametro el numero de vuelo y le restamos 1 para buscar su posicion en el array vuelos
    return vuelos[_num_vuelo - 1]; 
}

int Aeropuerto::getLongitudArrayVuelos()
{   
    //Como en metodo anteriores obtenemos el tamaño del array vuelos
    int longitud_array_vuelos = sizeof(vuelos) / sizeof(vuelos[0]);
    int cant_vuelos = 0;

    for (int i = 0; i < longitud_array_vuelos; i++)
    {
        //recorremos el array vuelos buscando si en alguna posicion hay algun vuelo registrado para contarlos
        if (vuelos[i].getDestion() != "") // 
        {
            cant_vuelos += 1; // Si hay se aumenta el valor del contrador en 1
        }
        else
        {
            break; //Si no hay se rompe el ciclo para obtener la cantidad contada
        }
    }
    return cant_vuelos;
}

int Aeropuerto::getLongitudArrayAviones()
{
    //Como en metodo anteriores obtenemos el tamaño del array aviones
    int longitud_array_aviones = sizeof(aviones) / sizeof(aviones[0]);
    int cant_aviones = 0;

    //recorremos el array aviones buscando si en alguna posicion hay algun avion registrado para contarlos
    for (int i = 0; i < longitud_array_aviones; i++)
    {

        if (aviones[i].getNombreAvion() != "")
        {
            cant_aviones += 1; // Si hay se aumenta el valor del contrador en 1
        }
        else
        {
            break; //Si no hay se rompe el ciclo para obtener la cantidad contada
        }
    }
    return cant_aviones;
}

int Aeropuerto::getLongitudArrayPistas()
{
    //Como en metodo anteriores obtenemos el tamaño del array vuelos
    
    int longitud_array_pistas = sizeof(pistas) / sizeof(pistas[0]);
    int cant_pistas = 0;

    //recorremos el array aviones buscando si en alguna posicion hay algun avion registrado para contarlos
    for(int i = 0; i < longitud_array_pistas; i++){

        if(pistas[i].getDestion() != ""){
            cant_pistas += 1; // Si hay se aumenta el valor del contrador en 1
        }

        //En este caso no rompemos el ciclo porque las pistas seran asignadas en una posicion aleatoria del array pistas
    }

    return cant_pistas;
}

void Aeropuerto::asignarPista(Vuelo _vuelo) 
{
    int rand_pista = rand() % 10; //hacemos uso de la funcion rand() de la librerira cstdlib al colocar % 10 nos devolvera un valor entre 0 y 9, 10 numero en total para las 10 pistas.


    if(pistas[rand_pista].getDestion() == "") //Si la posicion en el array pista que coincide con el numero random esta vacia se asigna el vuelo a esta pista.
    {
        pistas[rand_pista] = _vuelo;
        cout << "Vuelo asignado a la pista: " << (rand_pista + 1) << endl;
    }else
    {   
        //Si la posicion en el array pista que coincide con el numero random no esta vacia se vuelve a realizar el proceso generando otro numero random.
        rand_pista = rand() % 10;

        if(pistas[rand_pista].getDestion() == "")//Si la posicion en el array pista que coincide con el numero random esta vacia se asigna el vuelo a esta pista.
        {
            pistas[rand_pista] = _vuelo;
            cout << "Vuelo asignado a la pista: " << (rand_pista + 1) << endl;
        }else
        {
            //Si la posicion en el array pista que coincide con el numero random por segunda vez no esta vacia se vuelve a realizar el proceso generando otro numero random.
            rand_pista = rand() % 10;

            if(pistas[rand_pista].getDestion() == "")//Si la posicion en el array pista que coincide con el numero random esta vacia se asigna el vuelo a esta pista.
            {
                pistas[rand_pista] = _vuelo;
                cout << "Vuelo asignado a la pista: " << (rand_pista + 1) << endl;
            }else
            {
                //Si la posicion en el array pista que coincide con el numero random no esta vacia en el tercer intento se asigna el vuelo a esta pista, eliminado el vuelo anterior de la pista.

                cout << "Error al generar aleatorio para pista, coincidencia 3 veces" << endl;
                cout << "Se sobrescribira al vuelo anterior en esta pista.";
                pistas[rand_pista] = _vuelo;
            }
        }
    }

    cout << "Pista asignada !!" << endl;
    
}

void Aeropuerto::reportePistas()
{   
    //Como en metodo anteriores obtenemos el tamaño del array pistas
    int longitud_array_pistas = sizeof(pistas) / sizeof(pistas[0]);

    for (int i = 0; i < longitud_array_pistas; i++){

        //recorremos el arreglo de pistas para listar si estan vacia o ocupadas
        if(pistas[i].getDestion() != "") //Preguntamos si en la posicion i del array pista hay un vuelo con destino
        {
            cout << "Pista " << (i + 1) << " en uso." << endl; // Si la pista esta en uso se muestra la informacion del vuelo que se encuentra en ella.

            //hacemos uso de la funcion getVuelo() para buscar el vuelo pasando como parametro el valor obtenido de la funcion getNumVuelo() del array pista. Y del vuelo obtenido con la funcion getVuelo().infoVuelo() llamamos a su metodo infoVuelo() para que nos muestre la infomacion del vuelo por pantalla.

            getVuelo(pistas[i].getNumVuelo()).infoVuelo();
        }else
        {
            cout << "Pista " << (i + 1) << " desocupada." << endl; //Si la pista no tiene un vuelo con destino se refleja que esta desocupada
        }
    }
}

string preguntar()
{   
    //Funcion que le preguntara al usuario si desea finalizar el programa.
    string repetir;

    cout << "Desea ingresar otra opcion del menu ?? s / n" << endl;
    cin >> repetir;

    return repetir;
}

int main()
{

    char terminar = 'n';
    int opcMenuP, opcMenuAe, opcMenuV, opcMenuA; // Variables para el manejo de opciones de los menus
   
    Aeropuerto aero = Aeropuerto(); //Generamos nuestro objeto aeropuerto que manejara todo en el bucle principal

    do
    {

        cout << "---------MENU PRINCIPAL---------" << endl;
        cout << "1. Aeropuerto" << endl;
        cout << "2. Vuelos" << endl;
        cout << "3. Aviones" << endl;
        cin >> opcMenuP;

        switch (opcMenuP)
        {
            case 1:
            {
                cout << "------------ MENU AEROPUERTO -------------" << endl;
                cout << "1. Comprar Boleto" << endl;
                cout << "2. Reporte de Pistas" << endl;

                cin >> opcMenuAe;

                switch (opcMenuAe)
                {
                    case 1:
                    {

                        if (aero.getLongitudArrayVuelos() >= 1) //Consultamos si hay vuelos
                        {
                            int boleto, id_avion;
                            Avion av;
                            Vuelo vu;

                            aero.reporteVuelos(); //hacemos uso del metodo reporteVuelos() para listar todos los vuelos registrados en aeropuerto
                            cout << "(El estado del vuelo debe ser activo, si no debera volver a solicitar el boleto)" << endl;
                            cout << "Para cual vuelo desea comprar un boleto ??: ";
                            cin >> boleto;


                            cout << "Uste ha solicitado un boleto para el vuelo: " << endl;
                            vu = aero.getVuelo(boleto); //obtenemos el vuelo solicitado y lo almacenamos en vu

                            if(vu.getEstatus() == 1) //Verificamos que el estatus del vuelo sea 1 que es Activo
                            {
                                //Si esta el vuelo activo 
                                //mostramos su informacion y modificamos su estatus a 3 que seria agotado
                                vu.infoVuelo();
                                vu.setEstatusVuelo(3);

                                id_avion = aero.getIdAvionVuelo(boleto); //obtenemos el id_avion del vuelo solicitado para asi buscar la informacion del avion
                                cout << "En el avion: " << endl;
                                av = aero.getAvion(id_avion); //obtenemos el avion
                                av.infoAvion(); //mostramos su informacion

                                aero.asignarPista(vu); //asignamos el vuelo a un pista
                            }else{
                                cout << "El vuelo seleccionado no esta disponible !!" << endl;
                            }
                            
                        }
                        else
                        {
                            cout << "No hay vuelos registrados en este momento, registre alguno." << endl;
                        }

                                            }
                    break;

                    case 2:
                    {
                        aero.reportePistas(); //metodo para mostrar un reporte de las pistas
                        
                    }
                    break;

                    default:
                    {
                        cout << "La opcion ingresada no esta en el menu, ingrese una opcion del menu" << endl;
                        
                    }
                    break;
                }
            }
            break;

            case 2:
            {
                cout << "------------ MENU VUELOS -------------" << endl;
                cout << "1. Registrar Vuelo" << endl;
                cout << "2. Reportes de Vuelos" << endl;
                cout << "3. Cancelar Vuelo" << endl;
                cin >> opcMenuV;

                switch (opcMenuV)
                {
                    case 1:
                    {   
                        if(aero.getLongitudArrayAviones() > 0) //Verificamos si hay aviones registrados
                        {
                            int num_vuelo, estatus, avion;
                            string hora_salida, origen, destino;
                            Avion av;

                            cout << "Ingrese hora de salida: " << endl;
                            cin >> hora_salida;
                            cout << "Ingrese lugar de origen: " << endl;
                            cin.ignore();
                            getline(cin, origen);
                            cout << "Ingrese lugar de destino: " << endl;
                            getline(cin, destino);

                            cout << "Estatus del Vuelo: " << endl;
                            cout << "1. Activo" << endl;
                            cout << "2. Suspendido" << endl;
                            cout << "3. Agotado" << endl;
                            cin >> estatus;

                            aero.reportesAviones(); //listamos los aviones disponibles para asignarlo al vuelo que estamos creando
                            cout << "(Solo asigne aviones cuyo estatus sea: Estacionado. Si no lo hace debera crear nuevamente el vuelo)" << endl;
                            cout << "Asignar un Avion : ";
                            cin >> avion;

                            num_vuelo = aero.getLongitudArrayVuelos() + 1; //con el metodo getLongitudArrayVuelos() obtenemos la cantidad de vuelos registrado y le sumamos 1 para el nuevo vuelo. Ej: si el metodo devuelve 2 para este nuevo vuelo en num_vuelo seria 3

                            cout << "Vuelo Registrado !!" << endl;
                            Vuelo v = Vuelo();
                            av = aero.getAvion(avion); // obtenemos la informacion del avion solicitado

                            if (av.getEstatus() == 3) //Verificamos que su estatus sera 3 (Estacionado) para asignarlo a este vuelo
                            {
                                v.registrarVuelo(num_vuelo, hora_salida, origen, destino, avion, estatus); //registramos los datos del vuelo 
                                aero.setVuelo(v); //almacenamos el vuelo en el aeropuerto

                                aero.setEstatusAvion(avion, 4); //modificamos el estatus del avion a 4 (Asignado a Vuelo)
                                cout << "Asignado al Avion: ";
                                aero.getAvion(avion).infoAvion(); //MOstramos la informacion del avion registrado en aeropuerto
                                
                            }
                            else
                            {
                                cout << "El avion seleccionado no esta ESTACIONADO" << endl;
                            }
                        }else{
                            cout << "No hay aviones registrados !! registre alguno para realizar un vuelo." << endl;
                        }
                       
                    }
                    break;

                    case 2:
                    {
                        aero.reporteVuelos(); //Metodo para mostrar reporte de los vuelos
                       
                    }
                    break;

                    case 3:
                    {
                        aero.cancelarVuelo(); //Metodo para cancelar un vuelo
                       
                    }
                    break;

                    default:
                    {
                        cout << "La opcion ingresada no esta en el menu, ingrese una opcion del menu" << endl;
                        
                    }
                    break;
                }
            }
            break;

            case 3:
            {
                cout << "------------ MENU AVIONES -------------" << endl;
                cout << "1. Registrar Avion." << endl;
                cout << "2. Reporte Aviones." << endl;
                cout << "3. Modificar estatus avion." << endl;
                cin >> opcMenuA;

                switch (opcMenuA)
                {

                    case 1:
                    {
                        string nombreAvion;
                        int id_avion, estadoAvion;

                        cout << "Ingrese el nombre del avion: ";
                        cin.ignore();              // Usamos ignore() para borrar el enter del buffer y que no salte la linea de solicitud del nombre.
                        getline(cin, nombreAvion); // utilizamos la funcion getline() por si el usuario ingresa un nombre con un espacio en blanco se tome completo.

                        cout << "Ingrese el estado del avion: " << endl;
                        cout << "1. Volando" << endl;
                        cout << "2. Aterrizando" << endl;
                        cout << "3. Estacionado" << endl;
                        cin >> estadoAvion;

                        Avion av = Avion();
                        id_avion = aero.getLongitudArrayAviones();  //usamos el metodo getLongitudArrayAviones() para conocer el numero de aviones registrados y lo almacenamos como id_avion.
                        av.setAvion(id_avion, nombreAvion, estadoAvion); //registramos el avion
                        aero.setAvion(av);//y lo almacenamos en el aeropuerto

                        
                    }
                    break;

                    case 2:
                    {
                        aero.reportesAviones(); //Metodo que muesta un reporte de los aviones registrados.
                        
                    }
                    break;

                    case 3:{

                        int avion, estatus;

                        aero.reportesAviones(); //listamos los aviones registrados
                        cout << "Cual avion desea modificar el estatus ??: "; //consultamos el avion que se desea modificar estatus
                        cin >> avion;
                        cout << "Seleccione el nuevo estatus: " << endl;
                        cout << "1. Volando" << endl;
                        cout << "2. Aterrizando" << endl;
                        cout << "3. Estacionado" << endl;
                        cin >> estatus;

                        aero.setEstatusAvion(avion, estatus); //modificamos el estatus del avion
                        
                    }
                    break;

                    default:
                    {
                        cout << "La opcion ingresada no esta en el menu, ingrese una opcion del menu.";
                    
                    }
                    break;
                    }
                }
                break;

            default:
            {
                cout << "La opcion ingresada no esta en el menu, ingrese una opcion del menu" << endl;
                preguntar();
            }
            break;
        }
        
    } while (terminar != 's' && terminar != 'S'); //si la repuesta a preguntar() es diferente de 's' o 'S' se romper el bucle do while

    return 0;
}