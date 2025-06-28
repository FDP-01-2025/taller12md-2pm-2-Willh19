#include <iostream>
#include <fstream>
using namespace std;

struct Estudiante {
    string nombre;
    string carnet;
    int edad;
};

// Función para agregar estudiante (CREATE)
void agregarEstudiante() {
    Estudiante e;
    cout << "Nombre (sin espacios): ";
    cin >> e.nombre;
    cout << "Carnet: ";
    cin >> e.carnet;
    cout << "Edad: ";
    cin >> e.edad;

    ofstream archivo("estudiantes.txt", ios::app);
    if (archivo.is_open()) {
        archivo << e.nombre << " " << e.carnet << " " << e.edad << endl;
        archivo.close();
        cout << "Estudiante agregado correctamente.\n";
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

// Función para mostrar estudiantes (READ)
void mostrarEstudiantes() {
    ifstream archivo("estudiantes.txt");
    Estudiante e;

    if (archivo.is_open()) {
        cout << "\n--- Lista de Estudiantes ---\n";
        while (archivo >> e.nombre >> e.carnet >> e.edad) {
            cout << "Nombre: " << e.nombre 
                 << ", Carnet: " << e.carnet
                 << ", Edad: " << e.edad << endl;
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

// -----------------------------
// 👇 TU TAREA: Completa esta función (UPDATE)
void modificarEstudiante() {
    std::string id;
    Estudiante e;
    ifstream archivo("estudiantes.txt");
    ofstream archivo_modificado("Archivo_modificado.txt");
    std::cout << "Pon el carnet, del estudiante que quieres modificar: \n";
    std::cin >> id;
    if (archivo.is_open() && archivo_modificado.is_open())
    {
        while (archivo >> e.nombre >> e.carnet >> e.edad) 
        {
            if (e.carnet == id) //Hasta que en archivo, se encuentre
            {
                archivo >> e.edad;
                archivo >> e.carnet;
                std::string eleccion;
                archivo >> e.nombre;
                std::cout << "El estudiante encontrado fue \n";
                std::cout << "Edad: " << e.edad<<std::endl;
                std::cout << "Nombre: " << e.nombre<<std::endl;
                std::cout << "Carnet: " << e.carnet <<std::endl; // Se enseñan las variables del estudiante
                std::cout << "Modifica al estudiante: \n";
                std::cout << "Nombre: \n";
                std::cin >> e.nombre;
                std::cout << "Carnet \n";
                std::cin >> e.carnet;
                std::cout << "Edad \n";
                std::cin >> e.edad;
                // std::cout << "Edad, Nombre o Carnet? \n";
                // std::cin >> eleccion;
                // std::ofstream archivo_modificado("estudiantes.txt");
                // if (eleccion == "Edad")
                // {
                //     std::cout << "Pon la nueva edad! \n";
                //     int nueva_edad;
                //     std::cin >> nueva_edad;
                //     e.edad = nueva_edad;
                // }
                // else if (eleccion == "Nombre")
                // {
                //     std::cout << "Pon el nuevo nombre!\n";
                //     std::cin >> e.nombre;

                // }
                // else if (eleccion == "Carnet")
                // {
                //     std::cout << "Pon el nuevo carnet! \n";
                //     std::cin >> e.carnet;
                // }
                archivo_modificado << e.nombre << " " << e.carnet << " " << e.edad << endl;

            }
            else {
                archivo_modificado <<  e.nombre << " " << e.carnet << " "<<  e.edad << endl;
            }
            
        }
        archivo.close();
        archivo_modificado.close();
        remove("estudiantes.txt");
        rename("Archivo_modificado.txt", "estudiantes.txt");

    }
    
    
    
    // Debes permitir actualizar nombre, carnet y/o edad
    // de un estudiante identificado por su carnet.
    // Puedes usar o no manejo de archivos.
    // Si lo implementas con archivos correctamente, obtendrás **2 puntos extra**.
}
// -----------------------------

// Función para eliminar estudiante (DELETE)
void eliminarEstudiante() {
    ifstream archivo("estudiantes.txt");
    ofstream temp("temp.txt");
    Estudiante e;
    string buscado;
    bool eliminado = false;

    cout << "Ingrese carnet a eliminar: ";
    cin >> buscado;

    if (archivo.is_open() && temp.is_open()) {
        while (archivo >> e.nombre >> e.carnet >> e.edad) {
            if (e.carnet == buscado) {
                eliminado = true;               // No se copia: se “borra”
            } else {
                temp << e.nombre << " " << e.carnet << " " << e.edad << endl;
            }
        }
        archivo.close();
        temp.close();
        remove("estudiantes.txt");
        rename("temp.txt", "estudiantes.txt");

        if (eliminado)
            cout << "Estudiante eliminado correctamente.\n";
        else
            cout << "Carnet no encontrado.\n";
    } else {
        cout << "Error abriendo los archivos.\n";
    }
}

// Menú principal
int main() {
    int opcion;
    do {
        cout << "\n=== CRUD de Estudiantes ===\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Mostrar todos\n";
        cout << "3. Modificar estudiante\n";
        cout << "4. Eliminar estudiante\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: agregarEstudiante(); break;
            case 2: mostrarEstudiantes(); break;
            case 3: modificarEstudiante(); break;  // 👉 Completa aquí
            case 4: eliminarEstudiante(); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n";
        }

    } while (opcion != 5);

    return 0;
}