# Bloque de control de procesos

## Ejercicio 4. Consulta el tipo de fichero y contenido de los siguientes ficheros del proceso de la shell actual (/proc/$$) completa la siguiente tabla:
| Fichero | Tipo                  | Contenido/propósito                                 |
| ------- | --------------------- | --------------------------------------------------- |
| cmdline | fichero               | la shell en uso                                     |
| cwd     | hardlink a directorio | enlace al directorio de trabajo                     |
| environ | fichero               | variables de entorno                                |
| exe     | symlink               | proceso padre de la consola                         |
| fd      | directorio            | enlaces a los dispositivos en uso                   |
| limits  | fichero               | "soft" y "hard" limits para la máquina / el sistema |
| maps    | fichero               | mapa de las direcciones virtuales de memoria        |
| root    | directorio            | hardlink a /                                        |
