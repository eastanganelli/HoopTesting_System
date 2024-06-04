# Documentación Puerto Serial
<!-- TOC start (generated with https://github.com/derlin/bitdowntoc) -->

- [Documentación Puerto Serial](#documentación-puerto-serial)
  - [Mensaje Seriales](#mensaje-seriales)
    - [Salida](#salida)
      - [Inicio de Prueba](#inicio-de-prueba)
      - [Fin de Prueba](#fin-de-prueba)
    - [Entrada](#entrada)
      - [Datos instatáneos de la estación](#datos-instatáneos-de-la-estación)
      - [Actividad](#actividad)

<!-- TOC end -->
<!-- TOC --><a name="mensaje-seriales"></a>
## Mensaje Seriales
<!-- TOC --><a name="salida"></a>
### Salida
<!-- TOC --><a name="inicio-de-prueba"></a>
#### Inicio de Prueba
```txt
   'Estado'|'Nro Estación'|'Presión Target'|'Temperatura Target'\n
   start|1|23|34\n
```
Mensaje es enviado al darle iniciar en el programa posterior a la configuración de la prueba.
<!-- TOC --><a name="fin-de-prueba"></a>
#### Fin de Prueba
```txt
   'Estado'| 'Nro Estación'\n
   stop|3\n
```
Mensaje que se envía de forma automática o manual para dar por termina la prueba.<br>
- Automático: el programa envía mensaje de alto prueba cuando alcanza el tiempo de duración de la prueba.
- Manual: mensaje de alto prueba dada por el operador
<!-- TOC --><a name="entrada"></a>
### Entrada
<!-- TOC --><a name="datos-instatáneos-de-la-estación"></a>
#### Datos instatáneos de la estación
```txt
   'Nro Estación'|'Presión Instantánea'|'Temperatura Instantánea'\n
   2|34.12|45.10\n
```
Datos recibidos por el equipo cada 'X' tiempo.
<!-- TOC --><a name="actividad"></a>
#### Actividad
```txt
   'Dummy De Actividad'\n
   1\n
```
Mensaje verifica que el equipo se encuentra activo, dando asi el testigo en el software de que la communicación esta activa.