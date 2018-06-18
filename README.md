# Memory+
Memory+ es una aplicación que actúa como un launcher de videojuegos orientados a mejorar la memoria y las capacidades mentales. Inicialmente cuenta con dos videojuegos del tipo "juego de memoria":

- Memoria convencional: El jugador debe ir seleccionando pares de tarjetas sin verlas. Cuando encuentra todas las parejas del juego, gana.
- Memoria relacional: El jugador debe seleccionar dos o más cartas que en un principio son diferentes, pero guardan relación entre sí. Si el usuario logra seleccionar todas las cartas que están relacionadas, gana, pero si solo quedan cartas que no están relacionadas, pierde.

La aplicación fue programada en C++, utilizando la biblioteca DeSiGNAR (https://github.com/R3mmurd/DeSiGNAR) Qt 5.2.1.

# Plataformas
- Linux: Probado en Ubuntu 14.04.5 LTS (Trusty).

# Instrucciones de compilación

## Requisitos previos
- Descargar e instalar la versión de DeSiGNAR que se provee con la aplicación (DeSiGNAR.tar). Las instrucciones para su instalación se encuentran en su repositorio oficial https://github.com/R3mmurd/DeSiGNAR
- Instalar Qt 5.2.1 o una versión más actual (si la hay).
- Instalar la versión más actual del compilador gcc (se recomienda clang++-3.9).
- Descargar la carpeta "memory", la cual contiene el proyecto.
- Abrir el archivo memory+.pro (ubicado dentro de la carpeta "memory") y modificar la línea 18:
  - Debe reemplazar el path con la ubicación del directorio DeSiGNAR.

## Compilación desde la consola de comandos

- cd /ruta/al/directorio/memory
- qmake -makefile
- qmake
- make

## Compilación desde Qt Creator

- Abra el archivo memory+.pro desde Qt Creator.
- En la parte inferior izquierda seleccione el tipo de compilación en "Release".
- Presione la combinación de teclas Ctrl+R para compilar y correr la aplicación, o Ctrl+B solo para compilar.

Si los pasos fueron ejecutados correctamente, no debería haber problemas de compilación y debería tener a la vista dentro del directorio "memory" el archivo ejecutable de la aplicación.

## Autores
- Angel España
- Patricia Daboin
