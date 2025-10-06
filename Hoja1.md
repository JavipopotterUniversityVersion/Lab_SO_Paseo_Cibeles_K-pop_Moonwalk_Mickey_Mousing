# La línea de comandos - 1. Arrancar un terminal y comprobar el prompt de la shell. Cada usuario tiene un prompt distinto configurable. Para cambiar de usuario podemos usar el programa su. Ejecutar sudo -i  y comprobar si cambia el prompt, regresar al usuario inicial con la orden exit. El comando exit termina la ejecución de la shell y devuelve opcionalmente un código de retorno.
    - *!!:* Esto significa 'ultimo comando ejecutado'
    - *su <usuario> :* Switch user

# Las páginas del manual

- 3. Para buscar páginas de manual sobre un tema en particular se puede usar la opción -k, o las órdenes whatis o apropos. Buscar las órdenes relacionadas con la “hora” (time). Nota: Este comando accede a una base de datos sencilla para cada página de manual. La base de datos se gestiona con el comando mandb.

# Comandos y secuencias

- 3. La shell dispone de una serie de meta-caracteres que permiten controlar su comportamiento. En especial: || && ; ( ) | &, sirven para generar secuencias o listas de comandos. Estudiar el funcionamiento de las siguientes secuencias:

    - *&&:* "After", Ejecuta el segundo comando si el primero es exitoso
    - *||* "Or", Ejecuta el segundo comando si el primero **no** es exitoso
    - *;* Ejecuta el segundo comando después del primero. Es equivalente a un salto de línea en un .sh
    - *|* "Pipe", Usa el output de salida estandar como input del siguiente comando
    - *>* "Write", Usa el output de salida estandar y lo cambia por el contenido del siguiente archivo
    - *>>* "Append", Usa el output de salida estandar y lo añade al contenido del siguiente archivo
    - *()* Ejecuta el comando en una sub-shell
    - *&* Ejecuta el comando anterior en un sub-proceso independiente de la shell

# Variables de entorno

- 2. El valor de las variables se puede acceder con el prefijo $. Consultar el valor, y determinar el significado de: USER, UID, HOME, PWD, SHELL, $, PPID, ?,  PATH. Ejemplo:
    - *$?* El valor de salida del último proceso que se ha ejecutado
    - *$PPID* La id del proceso que se está ejecutando en este momento
    - *$PATH* Los ficheros en los que busca la shell las instrucciones que existen
    - *$PS1* El formato de la prompt de la shell

- 7. La orden which determina qué comando se ejecutará cuando se usa en la línea de comandos. Sintaxis: which <comando> 

# Manejo de cadenas

- 7. El comando tr sirve para cambiar caracteres (translate) o eliminarlos. Poner todas las palabras del fichero texto1 en una línea sustituyendo el carácter fin de línea por un tabulador.

# Redirecciones

- 3. Se pueden duplicar los descriptores con >& y >>&, en la forma: comando > salida 2>&1. Redirigir la salida estándar y de error del comando ls anterior al fichero salida.txt. Comprobar que el comportamiento es distinto a comando 2>&1 > salida (las “duplicaciones” se hacen secuencialmente)

>[!Warning] Mirar las redirecciones de error en las transparencias
