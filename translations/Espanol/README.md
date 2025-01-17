# Gettime-Functions

Gettime-Functions es un include que encapsula las funciones nativas `gettime()` y `getdate()` de SA-MP en una única función más versátil llamada `Gettime_Function`. Esta función ofrece diversos formatos de salida para fecha y hora, además de soporte para 10 idiomas diferentes.

## Idiomas

- Português: [README](../../)
- Deutsch: [README](../Deutsch/README.md)
- English: [README](../English/README.md)
- Français: [README](../Francais/README.md)
- Italiano: [README](../Italiano/README.md)
- Polski: [README](../Polski/README.md)
- Русский: [README](../Русский/README.md)
- Svenska: [README](../Svenska/README.md)
- Türkçe: [README](../Turkce/README.md)

## Índice

- [Gettime-Functions](#gettime-functions)
  - [Idiomas](#idiomas)
  - [Índice](#índice)
  - [Instalación](#instalación)
  - [Cómo Usar](#cómo-usar)
    - [Parámetros](#parámetros)
    - [Ejemplos de uso básico](#ejemplos-de-uso-básico)
    - [Ejemplos Avanzados](#ejemplos-avanzados)
  - [Idiomas Soportados](#idiomas-soportados)
  - [Tipos de formato disponibles](#tipos-de-formato-disponibles)
  - [Características Especiales](#características-especiales)
    - [Formatos de fecha por idioma](#formatos-de-fecha-por-idioma)
    - [Sistema de Estaciones](#sistema-de-estaciones)
  - [Licencia](#licencia)
    - [Condiciones:](#condiciones)

## Instalación

1. Descarga el archivo [Gettime-Functions.inc](https://github.com/ocalasans/Anti-Ping/raw/refs/heads/main/src/Gettime-Functions.inc)
2. Coloca el archivo en la carpeta `pawno/include` de tu servidor
3. Incluye el archivo en tu script:
```pawn
#include <Gettime-Functions>
```

> [!NOTE]
> El include verifica automáticamente si la biblioteca `a_samp` está presente. Si no lo está, se mostrará un error durante la compilación.

## Cómo Usar

La función principal es `Gettime_Function(tipo, idioma)` que acepta dos parámetros:

```pawn
Gettime_Function(GFI_type = DATE_AND_TIME, GFI_lang = LANG_PORTUGUES)
```

### Parámetros

- `GFI_type`: El formato de salida deseado (opcional, por defecto: DATE_AND_TIME)
- `GFI_lang`: El idioma deseado (opcional, por defecto: LANG_PORTUGUES)

> [!TIP]
> Puedes omitir ambos parámetros para usar los valores por defecto. La función devolverá la fecha y hora en formato completo en portugués.

### Ejemplos de uso básico

```pawn
main() {
    // Fecha y hora por defecto
    printf("Fecha y hora actual: %s", Gettime_Function(.GFI_lang = LANG_ESPANOL));
    // Salida: Fecha y hora actual: 17/01/2025 - 15:30:45

    // Solo la fecha
    printf("Fecha actual: %s", Gettime_Function(ONLY_THE_DATE, LANG_ESPANOL));
    // Salida: Fecha actual: 17/01/2025

    // Solo la hora
    printf("Hora actual: %s", Gettime_Function(JUST_THE_TIME, LANG_ESPANOL));
    // Salida: Hora actual: 15:30:45

    return true;
}
```

### Ejemplos Avanzados

```pawn
public OnPlayerConnect(playerid) {
    // Ejemplo con día de la semana y mes completo
    new welcome[128];
    format(welcome, sizeof(welcome), "¡Bienvenido! Hoy es %s", Gettime_Function(DATE_WEEKDAY, LANG_ESPANOL));
    SendClientMessage(playerid, -1, welcome); // Salida: ¡Bienvenido! Hoy es Viernes, 17/01/2025

    // Ejemplo con múltiples formatos
    new gettime_info[300];
    format(gettime_info, sizeof(gettime_info), "Gettime Info:\nFecha: %s\nHora: %s\nEstación: %s",
        Gettime_Function(DATE_MONTH_TEXT, LANG_ESPANOL),
        Gettime_Function(TIME_AMPM, LANG_ESPANOL),
        Gettime_Function(JUST_THE_SEASON, LANG_ESPANOL));
    
    ShowPlayerDialog(playerid, 1, DIALOG_STYLE_MSGBOX, "Gettime Info", gettime_info, "Ok", "");
    // Salida: Gettime Info:
    // Fecha: 17 de Enero de 2025
    // Hora: 03:30 PM
    // Estación: Verano

    return true;
}
```

## Idiomas Soportados

| Constante | Idioma | Formato de Fecha | Separador de Fecha |
|-----------|--------|------------------|-------------------|
| LANG_DEUTSCH | Alemán | DD.MM.YYYY | . |
| LANG_ENGLISH | Inglés | MM/DD/YYYY | / |
| LANG_ESPANOL | Español | DD/MM/YYYY | / |
| LANG_FRANCAIS | Francés | DD/MM/YYYY | / |
| LANG_ITALIANO | Italiano | DD/MM/YYYY | / |
| LANG_POLSKI | Polaco | DD.MM.YYYY | . |
| LANG_PORTUGUES | Portugués | DD/MM/YYYY | / |
| LANG_RUSSIAN | Ruso | DD.MM.YYYY | . |
| LANG_SVENSKA | Sueco | YYYY-MM-DD | - |
| LANG_TURKCE | Turco | DD.MM.YYYY | . |

> [!NOTE]
> Cada idioma tiene sus propias traducciones para meses, días de la semana y estaciones del año, además de formatos específicos de fecha.

## Tipos de formato disponibles

| Constante | Descripción | Ejemplo (ES) |
|-----------|-------------|--------------|
| DATE_AND_TIME | Fecha y hora completas | 17/01/2025 - 15:30:45 |
| ONLY_THE_DATE | Solo la fecha | 17/01/2025 |
| JUST_THE_TIME | Solo la hora | 15:30:45 |
| DATE_WHITOUT_SECONDS | Fecha y hora sin segundos | 17/01/2025 - 15:30 |
| DATE_WHITOUT_YEAR | Fecha sin el año | 17/01 |
| TIME_WITHOUT_SECONDS | Hora sin segundos | 15:30 |
| JUST_THE_YEAR | Solo el año | 2025 |
| JUST_THE_MONTH | Solo el mes | 01 |
| JUST_THE_DAY | Solo el día | 17 |
| JUST_THE_HOUR | Solo la hora | 15 |
| JUST_THE_MINUTE | Solo los minutos | 30 |
| JUST_THE_SECOND | Solo los segundos | 45 |
| DATE_TIME_FULL | Fecha y hora completas sin guión | 17/01/2025 15:30:45 |
| DATE_TIME_COMPACT | Fecha con año corto y hora sin segundos | 17/01/25 15:30 |
| DATE_MONTH_TEXT | Fecha con mes en texto | 17 de Enero de 2025 |
| TIME_AMPM | Hora en formato AM/PM | 03:30 PM |
| DATE_WEEKDAY | Fecha con día de la semana | Viernes, 17/01/2025 |
| DATE_TIME_SEASON | Fecha, hora y estación | Verano - 17/01/2025 15:30 |
| JUST_THE_SEASON | Solo la estación del año | Verano |
| DATE_SEASON | Fecha con estación | 17/01/2025 - Verano |
| TIME_SEASON | Hora con estación | 15:30:45 - Verano |
| MONTH_YEAR | Mes y año | Enero de 2025 |
| DAY_MONTH | Día y mes | 17 de Enero |
| WEEKDAY_ONLY | Solo el día de la semana | Viernes |
| WEEKDAY_TIME | Día de la semana y hora | Viernes, 15:30:45 |

## Características Especiales

### Formatos de fecha por idioma

> [!IMPORTANT]
> El include ajusta automáticamente el formato de la fecha según el estándar del país:
- Formato DD/MM/YYYY: Español, Portugués, Francés, Italiano, etc.
- Formato MM/DD/YYYY: Inglés
- Formato YYYY-MM-DD: Sueco

### Sistema de Estaciones
El include tiene un sistema inteligente que determina la estación del año según la fecha:

```pawn
// Verano: 21/12 hasta 20/03
// Otoño: 21/03 hasta 20/06
// Invierno: 21/06 hasta 22/09
// Primavera: 23/09 hasta 20/12

// Ejemplo de uso del sistema de estaciones
public OnGameModeInit() {
    // Verificando la estación actual
    printf("Estación actual: %s", Gettime_Function(JUST_THE_SEASON, LANG_ESPANOL));

    // Usando en un sistema de clima
    new weather;
    switch(Get_Season(GFI_months, GFI_days)) {
        case 0: weather = 10; // Verano: Soleado
        case 1: weather = 8;  // Otoño: Nublado
        case 2: weather = 12; // Invierno: Tormentoso
        case 3: weather = 2;  // Primavera: Muy soleado
    }
    SetWeather(weather);
    
    return true;
}
```

> [!TIP]
> El sistema de estaciones puede usarse para crear eventos estacionales en tu servidor, personalizar el clima automáticamente o crear decoraciones temáticas basadas en la estación del año actual.

## Licencia

Este Include está protegido bajo la Licencia Apache 2.0, que permite:

- ✔️ Uso comercial y privado
- ✔️ Modificación del código fuente
- ✔️ Distribución del código
- ✔️ Concesión de patentes

### Condiciones:

- Mantener el aviso de derechos de autor
- Documentar cambios significativos
- Incluir copia de la licencia Apache 2.0

Para más detalles sobre la licencia: http://www.apache.org/licenses/LICENSE-2.0

**Copyright (c) Calasans - Todos los derechos reservados**