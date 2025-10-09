#!/bin/bash

desformatear() {
  LINE=$1

  NAME=`echo $LINE | cut -d ":" -f 1`
  TLF=`echo $LINE | cut -d ":" -f 2` 
  EMAIL=`echo $LINE | cut -d ":" -f 3`

  echo "Nombre: " $NAME
  echo "Teléfono: " $TLF
  echo "Correo: " $EMAIL
  echo
}

printFormatFIle() {
  FILE=$1

  while read L; do
    desformatear $L
  done < "$FILE"
}


select opt in "listar" "buscar" "borrar" "añadir" "salir"
do
    case $opt in

        "listar")
          printFormatFIle ./databse.txt
          ;;

        "buscar")
            echo
            echo "Buscar: "
            INPUT=""
            read $INPUT

            cat ./databse.txt | grep "$INPUT" > ./aux.txt
            printFormatFIle ./aux.txt
            ;;

        "borrar")
            echo "Borrar: "
            read PATTERN
            sed -i "/${PATTERN}/d" ./databse.txt
            ;;

        "añadir")
            echo "Nombre: "
            read NAME

            echo "Telefono: "
            read TLF

            echo "Mail: "
            read ML

            echo "${NAME}:${TLF}:${ML}" >> ./databse.txt
            ;;

          "salir")
            break
            ;;

        *)
            echo "Error en opción"
            ;;
    esac
done
