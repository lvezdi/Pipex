<div align="center">
	<img src="https://img.shields.io/badge/norminette-passing-success"/>
	<img src="https://img.shields.io/badge/leaks-none-success" />
  	<img src="https://img.shields.io/badge/-100%2F100-success?logo=42&logoColor=fff" />
	<a href="https://github.com/lvezdi/Pipex/blob/main/README.md" >
   	<img src="https://img.shields.io/badge/Change_Language-English-blue" align="right"></a>
</div>

# Pipex
`Pipex` es un proyecto que recrea en C la forma en que dos comandos se conectan mediante un pipeline (`|`) en la shell.

## Procesos y Funciones

### Proceso Principal
`Pipex` permite ejecutar dos comandos en secuencia, donde la salida del primer comando se convierte en la entrada del segundo comando. Esto se logra utilizando tuberías (`pipes`), procesos hijos (`fork`), y duplicación de descriptores de archivo (`dup2`).

### Funciones Clave

- `pipe()`: crea un canal unidireccional de `comunicación entre dos procesos`, permitiendo que los datos escritos en un extremo del pipe se puedan leer desde el otro extremo. Devuelve un array de dos descriptores de archivo: el primer fd es para la lectura y el segundo fd para la escritura.
- `fork()`: crea un nuevo proceso llamado `proceso hijo`, que es una copia del proceso padre. Esta función devuelve el `PID` del hijo al proceso padre, y 0 al proceso hijo. Es fundamental para la creación de procesos en Unix.
- `dup2()`: duplica un descriptor de archivo. Hace que uno de los descriptores de archivo se refiera al mismo archivo que el otro descriptor.
- `execve()`: reemplaza el programa en el proceso actual con un nuevo programa. Toma como argumentos el nombre del archivo que contiene el programa a ejecutar, un array de argumentos y un array de variables de entorno.
- `access()`: comprueba el `permiso de acceso` a un archivo. Permite verificar si el proceso tiene permisos para `leer`, `escribir` o `ejecutar` un archivo especificado. Devuelve 0 si el acceso es permitido, y -1 si no lo es.

### Uso del PATH
Para ejecutar los comandos, pipex debe buscar los ejecutables en las rutas especificadas en la variable de entorno `PATH`. La variable `PATH` es una lista de directorios separados por donde el sistema busca los archivos ejecutables.

### Ejemplo de Uso
```bash
./pipex infile cmd1 cmd2 outfile

pipe()
 |
 |-- fork()
      |
      |-- first child // cmd1
      :     |--dup2()  // Redirige la entrada del comando cmd1 desde infile
      :     |--close end[0]  // Cierra el extremo de lectura del pipe
      :     |--execve(cmd1)  // Ejecuta cmd1
      :
      |-- second child // cmd2
            |--dup2()  // Redirige la salida del comando cmd2 hacia outfile
            |--close end[1]  // Cierra el extremo de escritura del pipe
            |--execve(cmd2)  // Ejecuta cmd2
