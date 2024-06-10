# Resumen de Ejercicios

## Ejercicio 1

### Objetivo:

Instalar Qt, lo que incluye herramientas de compilación C++, la biblioteca Qt y Qt Creator.

### Descripción:

Configurar el entorno de desarrollo instalando Qt y Qt Creator para comenzar a trabajar con aplicaciones Qt.

### Consigna:

* Instalar Qt. Lo cual incluye las herramientas de compilación C++, la biblioteca Qt y Qt Creator.
* Crear un primer programa que muestre por la consola de QtCreator 10 números aleatorios en el intervalo [ 2, 20 ]
* Cada vez que se ejecute el programa, los números deberán ser aleatorios y distintos en cada ejecución.

## Ejercicio 2

### Objetivo:

Familiarizarse con librerías, archivos DLL y la variable de entorno PATH.

### Descripción:

Crear un programa en C++ que utilice una librería externa (archivo DLL) y hacer uso de la variable de entorno PATH para ubicarla.

### Consigna:

Objetivo: Familiarización con librerías, archivos DLL y variable de entorno PATH. Tener presente la distinción entre biblioteca, librería y library.

Descripción: Crear un programa simple en C++ que utilice una librería externa (en forma de archivo DLL o similar en otros sistemas operativos) y que haga uso de la variable de entorno PATH para ubicar dicha librería.

Pasos a seguir:

1. Crear una librería en C++ y compilarla como un archivo DLL 8o similar en otros sistemas operativos). Programar en la librería una función que imprima un mensaje simple, como "Hola, desde la biblioteca".
2. Crear un programa principal en C++ que utilice esta librería. Hacer referencia (o linkear) a la librería de manera dinámica.
3. Incluir la ruta al archivo DLL en la variable de entorno PATH.
4. En el programa principal, cargar la librería, invocar a la función y mostrar el mensaje.

## Ejercicio 3

### Objetivo:

Practicar el uso de namespaces en C++.

### Descripción:

Definir un namespace propio y crear una función que devuelva el número de versión junto con la fecha de la última actualización de una biblioteca.

### Consigna:

* Elija un nombre para su propio espacio de nombres para todo lo que se haga en este asignatura
* Luego de elegido el nombre para su namespace, defina una función dentro de ese namespace para devolver el número de versión junto con la fecha de la última actualización de la biblioteca

```
QString getVersion();  // Devuelve un texto como "v0.0.1 - 20240318"
```

## Ejercicio 4

### Objetivo:

Practicar el uso de contenedores en C++, específicamente std::vector.

### Descripción:

Crear un std::vector para contener números enteros y calcular la moda de los valores.

### Consigna:

* Crear un std::vector para contener int
* Cargar 30 valores pseudo aleatorios entre 1 y 15
* Publicar la moda

## Ejercicio 5

### Objetivo:

Seguir practicando el uso de contenedores en C++, esta vez con std::vector de objetos de la clase std::string.

### Descripción:

Crear un std::vector para contener expresiones idiomáticas y ordenarlas alfabéticamente.

### Consigna:

* Crear un std::vector para contener objetos de la clase std::string
* Cargar 5 expresiones idiomáticas, como por ejemplo: pan comido
* Publicar por consola ordenado alfabéticamente

## Ejercicio 6

### Objetivo:

Practicar la creación de clases y objetos en C++.

### Descripción:

Crear una nueva clase en un proyecto qmake vacío, implementar constructores, métodos y atributos, y crear objetos de esta clase en la función main.

### Consigna:

* En un Empty qmake Project
* Crear una nueva clase (que no sea Persona, ni Cliente, ni Poste). Invente una clase.
* Agregar uno o más constructores, agregar sus métodos y sus atributos
* Crear algunos objetos de esta clase en la función main

## Ejercicio 7

### Objetivo:

Practicar el uso de contenedores y clases en C++.

### Descripción:

Utilizar la clase creada en el ejercicio anterior para crear objetos y almacenarlos en un std::vector. Explorar estrategias para ordenar los objetos de menor a mayor.

### Consigna:

* Empty qmake Project
* Utilizar la clase creada en el ejercicio anterior para crear objetos y almacenarlos en un `std::vector`
* ¿Se pueden ordenar? Qué estrategia utilizaría para ordenarlos de menor a mayor

## Ejercicio 8

### Objetivo:

Practicar la creación de funciones genéricas en C++.

### Descripción:

Crear una función genérica que imprima por consola una descripción de cualquier objeto. Probar esta función con objetos de diferentes clases en la función main.

### Consigna:

* En un Empty qmake Project
* Crear una función genérica que imprima por consola una descripción de cualquier objeto.
* El mensaje puede ser algo así: "Persona con nombre Lucrecia", "Poste con altura de 8 metros y 15 cm de diámetro".
* Probar esta función en main utilizando dos objetos de la clase Persona y dos objetos de la clase Poste.
* Incluir todo el código fuente en el archivo main.cpp.
* Pedirle al chat el código, interpretarlo y hacerlo funcionar.

## Ejercicio 9

### Objetivo:

Explorar el uso de plantillas y el método de ordenamiento por inserción en C++.

### Descripción:

Crear una función genérica que imprima por consola los valores ordenados de un array utilizando el método de ordenamiento por inserción. Probar la función con arrays de enteros y flotantes, ordenándolos de mayor a menor y viceversa.

### Consigna:

* En un Empty qmake Project
* Crear una función genérica que imprima por consola sus valores ordenados
* Es decir, se le pasa un array con sus valores en cualquier orden, y la función genérica los imprime ordenados
* Que el prototipo sea: `template < class T > void imprimir( T * v, int cantidad, bool mayor_a_menor );`
* Utilizar el método de ordenamiento por inserción
* Probar esta función en main utilizando dos arrays (int y float) y ordenar de mayor a menor y el otro al revés.

## Ejercicio 10

### Objetivo:

Practicar la creación de clases y objetos en C++ utilizando Qt.

### Descripción:

Crear una clase Jugador con atributos y métodos, instanciar objetos de esta clase en la función main y publicar los datos de cada jugador por consola.

### Consigna:

* En un Empty qmake Project
* Crear una clase Jugador con atributos `int velocidad`, `int fuerza` y `std::string nombre`
* Usar constructor inicializando de la manera recomendada la velocidad en 0, fuerza en 0 y nombre "sin nombre"
* Crear los métodos setter y getter para setear y obtener los valores de los atributos
* Incluir el destructor
* En la función main crear un `std::vector< Jugador >` e insertar 10 jugadores distintos
* Por último, publicar los datos de cada uno de los jugadores con `std::cout`

## Ejercicio 11

### Objetivo:

Crear objetos de diferentes clases de widgets en un proyecto Qt.

### Descripción:

Crear objetos de las clases QLabel, QWidget, QPushButton y QLineEdit en un proyecto Qt vacío y mostrarlos independientemente.

### Consigna:

* En un Empty qmake Project
* En la función main crear un objeto de la clase QLabel, uno de QWidget, uno de QPushButton y uno de QLineEdit
* Invocar al método show() de cada uno de estos 4 objetos
* Notar que cada objeto se muestra independiente

## Ejercicio 12

### Objetivo:

Crear una aplicación Qt que muestre una imagen en una ventana.

### Descripción:

Crear un QLabel y cargar una imagen desde un archivo JPG en la ventana principal de la aplicación. Mostrar la ventana maximizada y cerrarla después de 3 segundos.

### Consigna:

* En un Empty qmake Project
* En la función main crear un objeto de la clase QLabel y pegarle en el mismo objeto QLabel una imagen de alta resolución.
* Que la imagen se obtenga desde un archivo JPG del disco duro
* Mostrar el QLabel de forma maximizada y que la imagen no se deforme.
* Al cabo de 3 segundos, el QLabel y la aplicación se deberá cerrar

### Objetivo:

Modificar la interfaz gráfica en respuesta a eventos en Qt.

### Descripción:

Actualizar el título de la ventana cuando se modifique el valor de un QSlider.

## Ejercicio 14

### Objetivo:

Integrar una base de datos MongoDB con una API web utilizando FastAPI.

### Descripción:

Registrar usuarios en una base de datos MongoDB y proporcionar un endpoint con FastAPI para validar usuarios.

### Consigna:

* Diseñar un login con QGridLayout.
* Usar asteriscos para la clave.
* Detectar enter para simular la pulsación del botón.
* Definir la clase Formulario que será un QWidget
* Formulario tendrá QLabels y QLineEdits para Legajo, Nombre y Apellido, y un QPushButton
* Si la clave ingresada es admin:1111, se cierra Login y se muestra Formulario
* Si se ingresa otra clave se borrará el texto del QLineEdit de la clave.

## Ejercicio 15

### Objetivo:

Crear una aplicación Qt que permita al usuario interactuar con una base de datos.

### Descripción:

Crear un formulario de registro de usuarios en Qt que valide y registre usuarios en una base de datos SQLite.

### Consigna:

![imagenes/ejercicio_captcha.jpg](https://github.com/cosimani/Curso-POO-2024/raw/main/imagenes/ejercicio_captcha.jpg)

## Ejercicio 16

### Objetivo:

Explorar la manipulación de archivos y la descarga de recursos web en Qt.

### Descripción:

Desarrollar una aplicación Qt que descargue recursos (imágenes, CSS, JavaScript) de un sitio web y los guarde en archivos locales.

### Consigna:

* Registrar en MongoDB algunos usuarios (nombre, apellido, usuario, clave)
* Tener disponible un endpoint con FastAPI para validar usuarios.

## Ejercicio 17

### Objetivo:

Desarrollar una aplicación Qt que implemente un proceso de autenticación y una interfaz gráfica atractiva.

### Descripción:

Crear un sistema de login con una imagen de fondo descargada de internet. Al autenticar al usuario, abrir una ventana en pantalla completa con otra imagen descargada de internet.

### Consigna:

* Diseñar un login que cargue como fondo, una imagen descargada de internet
* Cuando un usuario sea válido, que se abra en full screen otra ventana (definida en la clase Ventana) y que tenga otra imagen descargada de internet en su interior, abarcando toda la ventana.
* Esta ventana no deberá abrirse hasta tanto se haya descargado la imagen.
* La imagen no se debe deformar al visualizarse.

## Ejercicio 18

### Objetivo:

Crear una aplicación Qt que permita cargar y mostrar contenido HTML desde una URL.

### Descripción:

Crear una interfaz de usuario con un QLineEdit para ingresar una URL y un QTextEdit para mostrar el contenido HTML de la página. Implementar la funcionalidad para cargar y mostrar el HTML al presionar Enter en el QLineEdit.

### Consigna:

* Utilizar un proyecto con un login cualquiera que valide admin:1234
* Cuando el usuario es válido, abrir una nueva ventana que tenga un QTextEdit que permita mostrar código HTML.
* Esta ventana deberá tener un QLineEdit que permita ingresar una URL
* Cuando se pulse Enter, se deberá buscar el html de la URL escrita y se deberá publicar en el QTextEdit.

## Ejercicio 19

### Objetivo:

Crear una clase QWidget en Qt que permita dibujar a mano alzada con el mouse.

### Descripción:

Desarrollar una clase llamada Pintura que herede de QWidget y permita dibujar con el mouse. La clase deberá proporcionar funcionalidades como ajuste del tamaño del trazo, cambio de color del pincel y borrado de contenido dibujado.

### Consigna:

* Crear una clase Pintura que herede de QWidget y que permita dibujar a mano alzada con el mouse.
* Con el scroll permitirá ampliar y disminuir el tamaño del trazo del pincel.
* Con las teclas R, G y B se cambia el color del pincel.
* Con Escape se borra todo lo que esté dibujado.

## Ejercicio 20

### Objetivo:

Crear un proyecto Qt Widget con múltiples clases que interactúen entre sí.

### Descripción:

Desarrollar un proyecto con una clase Ventana que contenga varios objetos de la clase Boton. La clase Boton deberá heredar de QWidget y permitir personalizar su apariencia y color.

### Consigna:

* Crear un proyecto Qt Widget Application con un QWidget que sea la clase Ventana
* Crear una clase Boton que hereda de QWidget
* Redefinir paintEvent en Boton y usar fillRect para dibujarlo de algún color
* Definir el siguiente método en Boton:

```c
Boton * boton = new Boton;
boton->colorear( Boton::Azul );

// Este método recibe como parámetro una enumeración que puede ser:
// Boton::Azul  Boton::Verde  Boton::Magenta
```

* Usar QtDesigner para Ventana y Boton. Es decir, Designer Form Class
* Definir la enumeración en Boton
* Abrir el designer de Ventana y agregar 5 botones (objetos de la clase Boton). Promocionarlos
* Que esta Ventana con botones quede lo más parecido a la siguiente imagen:

  ![imagenes/botones.png](https://github.com/cosimani/Curso-POO-2024/raw/main/imagenes/botones.png)
* Usar para Ventana grid layout, usar espaciadores y usar todos los recursos posibles del QtDesigner
* Dibujar un fondo agradable con paintEvent y drawImage
* Que Boton tenga la señal signal_clic()

## Ejercicio 21

### Objetivo:

Practicar la integración de bases de datos SQLite con interfaces gráficas Qt.

### Descripción:

Crear un sistema de login que valide a los usuarios contra una base de datos SQLite. Al autenticar al usuario, mostrar una ventana con un botón para volver al login.

### Consigna:

* Definir dos QWidgets (una clase Login y una clase Ventana).
* El Login validará al usuario contra una base SQLite
* La Ventana sólo mostrará un QPushButton para "Volver" al login.
* Crear solamente un objeto de Ventana y uno solo de Login.
* Si sucede un problema en la compilación, analizar los motivos (respetar el enunciado).
* Solucionar ese problema y ver la alternativa de hacerlo con Manager.

## Ejercicio 22

### Objetivo:

Practicar el uso de herencia, polimorfismo y contenedores en C++.

### Descripción:

Crear una jerarquía de clases de instrumentos musicales con herencia, polimorfismo y métodos virtuales. Utilizar un std::vector para almacenar objetos de las clases e imprimir información sobre cada instrumento.

### Consigna:

* Crear una clase base llamada Instrumento y las clases derivadas Guitarra, Bateria y Teclado.
* La clase base tiene una función virtual pura llamada `sonar()`.
* Defina una función virtual `verlo()` que publique la marca del instrumento. Por defecto todos los instrumentos son de la marca Yamaha.
* Utilice en la función `main()` un `std::vector` para almacenar punteros a objetos del tipo Instrumento. Instancie 5 objetos y agréguelos al `std::vector`.
* Publique la marca de cada instrumento recorriendo el vector.
* En las clases derivadas agregue los datos miembro "`int cuerdas`", "`int teclas`" e "`int tambores`" según corresponda. Por defecto, guitarra con 6 cuerdas, teclado con 61 teclas y batería con 5 tambores.
* Haga que la clase `Teclado` tenga herencia múltiple, heredando además de una nueva clase `Electrico`. Todos los equipos del tipo "`Electrico`" tienen por defecto un voltaje de 220 volts. Esta clase deberá tener un destructor que al destruirse publique la leyenda "Desenchufado".
* Al llamar a la función `sonar()`, se deberá publicar "Guitarra suena...", "Teclado suena..." o "Batería suena..." según corresponda.
* Incluya los métodos `get` y `set` que crea convenientes.

## Ejercicio 23

### Objetivo:

Explorar el uso de características avanzadas de C++ en un proyecto previamente desarrollado.

### Descripción:

Reutilizar un proyecto anterior e implementar herencia múltiple, funciones inline y amigas según sea necesario para mejorar la estructura y funcionalidad del código.

### Consigna:

* Reutilizar el código fuente de cualquier otro ejericio y utilizar herencia múltiple, inline y friend.
* Implementar herencia múltiple, inline y friend cuando sea beneficioso hacerlo.

## Ejercicio 24

### Objetivo:

Desarrollar una aplicación Qt que analice y descargue recursos de páginas web.

### Descripción:

Crear un analizador de HTML que extraiga todas las URLs de una página web y descargue los recursos (imágenes, CSS, JavaScript) a archivos locales. Implementar una GUI que permita al usuario ingresar una URL y elegir la ubicación de descarga de los archivos.

### Consigna:

* Crear un **parser** que pueda analizar cualquier html en busca de todas las URLs que encuentre
* Crear una GUI que permita al usuario ingresar un sitio web en un QLineEdit
* Que descargue en archivos todos los recursos de dicho sitio web
* Es decir, que busque en el html las imágenes, los css, los javascript y los descargue en archivos
* Que le permita al usuario indicar en qué directorio descargar los archivos
* También agregar un botón que upermita elegir un archivo de imagen del disco con `QFileDialog` y que la dibuje en pantalla con paintEvent.

## Ejercicio 25

### Objetivo:

Crear una aplicación Qt que integre un sistema de login con una base de datos SQLite y una interfaz de usuario personalizada.

### Descripción:

Desarrollar un sistema de login que valide a los usuarios contra una base de datos SQLite y muestre una ventana con información sobre los usuarios registrados. La ventana deberá permitir editar los datos de los usuarios como en una hoja de cálculo.

### Consigna:

* Construir un nuevo proyecto que tenga un Login independiente, es decir, que no dependa de otra clase GUI.
* El Login tenga un QLabel que funciona como botón que sea para registrar un nuevo usuario.
* Cuando se presiona el QLabel que funciona como botón, se abrirá una ventana para dar de alta un usuario.
* Usar SQLite con AdminDB como singleton.
* Cuando un usuario válido ingresa correctamente se mostrará otra ventana que visualizará todos los usuarios cargados en la base.
* Para la visualización de los usuarios se puede usar QTreeWidget. Agregar la funcionalidad para que en esta misma ventana se puedan editar los campos como si fuera una planilla tipo excel.
* Seguir las recomendaciones que se comentaron durante el dictado de clases para construir las clases.
