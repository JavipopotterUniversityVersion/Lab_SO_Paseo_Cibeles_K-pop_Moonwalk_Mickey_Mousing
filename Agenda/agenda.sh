#!/bin/bash

select opt in "listar" "buscar" "borrar" "añadir" "salir"
do
    case $opt in

        "listar")
            ls -l
            # Crearía una función "Desformatear" y pasaría todas las líneas por ella
            ;;

        "buscar")
            # grep
            date
            ;;

        "borrar")
            # grep "nombre" borrarla
            echo "Exiting..."
            break
            ;;

        "añadir")
            # Crear funcion formatear y escribir una linea nueva
            echo "Exiting..."
            break
            ;;

        "salir")
            return
            ;;

        *)
            echo "Error en opción"
            ;;
    esac
done
