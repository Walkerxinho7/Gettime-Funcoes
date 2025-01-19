# Gettime-Functions

Gettime-Functions è un include che racchiude le funzioni native `gettime()` e `getdate()` di SA-MP in un'unica funzione più versatile chiamata `Gettime_Function`. Questa funzione offre diversi formati di output per data e ora, oltre al supporto per 10 lingue diverse.

## Lingue

- Português: [README](../../)
- Deutsch: [README](../Deutsch/README.md)
- English: [README](../English/README.md)
- Español: [README](../Espanol/README.md)
- Français: [README](../Francais/README.md)
- Polski: [README](../Polski/README.md)
- Русский: [README](../Русский/README.md)
- Svenska: [README](../Svenska/README.md)
- Türkçe: [README](../Turkce/README.md)

## Indice

- [Gettime-Functions](#gettime-functions)
  - [Lingue](#lingue)
  - [Indice](#indice)
  - [Installazione](#installazione)
  - [Come Utilizzare](#come-utilizzare)
    - [Parametri](#parametri)
    - [Esempi di utilizzo base](#esempi-di-utilizzo-base)
    - [Esempi Avanzati](#esempi-avanzati)
  - [Lingue Supportate](#lingue-supportate)
  - [Tipi di formato disponibili](#tipi-di-formato-disponibili)
  - [Caratteristiche Speciali](#caratteristiche-speciali)
    - [Formati di data per lingua](#formati-di-data-per-lingua)
    - [Sistema delle Stagioni](#sistema-delle-stagioni)
  - [Licenza](#licenza)
    - [Condizioni:](#condizioni)

## Installazione

1. Scarica il file [Gettime-Functions.inc](https://github.com/ocalasans/Gettime-Functions/raw/refs/heads/main/src/Gettime-Functions.inc)
2. Inserisci il file nella cartella `pawno/include` del tuo server
3. Includi il file nel tuo script:
```pawn
#include <Gettime-Functions>
```

> [!NOTE]
> L'include verifica automaticamente se la libreria `a_samp` è presente. Se non lo è, verrà visualizzato un errore durante la compilazione.

## Come Utilizzare

La funzione principale è `Gettime_Function(tipo, lingua)` che accetta due parametri:

```pawn
Gettime_Function(GFI_type = DATE_AND_TIME, GFI_lang = LANG_ITALIANO)
```

### Parametri

- `GFI_type`: Il formato di output desiderato (opzionale, predefinito: DATE_AND_TIME)
- `GFI_lang`: La lingua desiderata (opzionale, predefinito: LANG_ITALIANO)

> [!TIP]
> Puoi omettere entrambi i parametri per utilizzare i valori predefiniti. La funzione restituirà la data e l'ora nel formato completo in italiano.

### Esempi di utilizzo base

```pawn
main() {
    // Data e ora predefinite
    printf("Data e ora attuale: %s", Gettime_Function(.GFI_lang = LANG_ITALIANO));
    // Output: Data e ora attuale: 17/01/2025 - 15:30:45

    // Solo la data
    printf("Data attuale: %s", Gettime_Function(ONLY_THE_DATE, LANG_ITALIANO));
    // Output: Data attuale: 17/01/2025

    // Solo l'ora
    printf("Ora attuale: %s", Gettime_Function(JUST_THE_TIME, LANG_ITALIANO));
    // Output: Ora attuale: 15:30:45

    return true;
}
```

### Esempi Avanzati

```pawn
public OnPlayerConnect(playerid) {
    // Esempio con giorno della settimana e mese per esteso
    new welcome[128];
    format(welcome, sizeof(welcome), "Benvenuto! Oggi è %s", Gettime_Function(DATE_WEEKDAY, LANG_ITALIANO));
    SendClientMessage(playerid, -1, welcome); // Output: Benvenuto! Oggi è Venerdì, 17/01/2025

    // Esempio con formati multipli
    new gettime_info[300];
    format(gettime_info, sizeof(gettime_info), "Info Temporali:\nData: %s\nOra: %s\nStagione: %s",
        Gettime_Function(DATE_MONTH_TEXT, LANG_ITALIANO),
        Gettime_Function(TIME_AMPM, LANG_ITALIANO),
        Gettime_Function(JUST_THE_SEASON, LANG_ITALIANO));
    
    ShowPlayerDialog(playerid, 1, DIALOG_STYLE_MSGBOX, "Info Temporali", gettime_info, "Ok", "");
    // Output: Info Temporali:
    // Data: 17 di Gennaio 2025
    // Ora: 03:30 PM
    // Stagione: Estate

    return true;
}
```

## Lingue Supportate

| Costante | Lingua | Formato Data | Separatore Data |
|-----------|--------|-----------------|-------------------|
| LANG_DEUTSCH | Tedesco | DD.MM.YYYY | . |
| LANG_ENGLISH | Inglese | MM/DD/YYYY | / |
| LANG_ESPANOL | Spagnolo | DD/MM/YYYY | / |
| LANG_FRANCAIS | Francese | DD/MM/YYYY | / |
| LANG_ITALIANO | Italiano | DD/MM/YYYY | / |
| LANG_POLSKI | Polacco | DD.MM.YYYY | . |
| LANG_PORTUGUES | Portoghese | DD/MM/YYYY | / |
| LANG_RUSSIAN | Russo | DD.MM.YYYY | . |
| LANG_SVENSKA | Svedese | YYYY-MM-DD | - |
| LANG_TURKCE | Turco | DD.MM.YYYY | . |

> [!NOTE]
> Ogni lingua ha le proprie traduzioni per mesi, giorni della settimana e stagioni, oltre a formati di data specifici.

## Tipi di formato disponibili

| Costante | Descrizione | Esempio (IT) |
|-----------|-----------|-----------------|
| DATE_AND_TIME | Data e ora complete | 17/01/2025 - 15:30:45 |
| ONLY_THE_DATE | Solo la data | 17/01/2025 |
| JUST_THE_TIME | Solo l'ora | 15:30:45 |
| DATE_WHITOUT_SECONDS | Data e ora senza secondi | 17/01/2025 - 15:30 |
| DATE_WHITOUT_YEAR | Data senza anno | 17/01 |
| TIME_WITHOUT_SECONDS | Ora senza secondi | 15:30 |
| JUST_THE_YEAR | Solo l'anno | 2025 |
| JUST_THE_MONTH | Solo il mese | 01 |
| JUST_THE_DAY | Solo il giorno | 17 |
| JUST_THE_HOUR | Solo l'ora | 15 |
| JUST_THE_MINUTE | Solo i minuti | 30 |
| JUST_THE_SECOND | Solo i secondi | 45 |
| DATE_TIME_FULL | Data e ora complete senza trattino | 17/01/2025 15:30:45 |
| DATE_TIME_COMPACT | Data con anno breve e ora senza secondi | 17/01/25 15:30 |
| DATE_MONTH_TEXT | Data con mese in lettere | 17 di Gennaio 2025 |
| TIME_AMPM | Ora in formato AM/PM | 03:30 PM |
| DATE_WEEKDAY | Data con giorno della settimana | Venerdì, 17/01/2025 |
| DATE_TIME_SEASON | Data, ora e stagione | Estate - 17/01/2025 15:30 |
| JUST_THE_SEASON | Solo la stagione | Estate |
| DATE_SEASON | Data con stagione | 17/01/2025 - Estate |
| TIME_SEASON | Ora con stagione | 15:30:45 - Estate |
| MONTH_YEAR | Mese e anno | Gennaio di 2025 |
| DAY_MONTH | Giorno e mese | 17 di Gennaio |
| WEEKDAY_ONLY | Solo il giorno della settimana | Venerdì |
| WEEKDAY_TIME | Giorno della settimana e ora | Venerdì, 15:30:45 |

## Caratteristiche Speciali

### Formati di data per lingua

> [!IMPORTANT]
> L'include adatta automaticamente il formato della data secondo lo standard del paese:
- Formato DD/MM/YYYY: Italiano, Portoghese, Spagnolo, Francese, ecc.
- Formato MM/DD/YYYY: Inglese
- Formato YYYY-MM-DD: Svedese

### Sistema delle Stagioni
L'include ha un sistema intelligente che determina la stagione dell'anno in base alla data:

```pawn
// Estate: 21/12 fino al 20/03
// Autunno: 21/03 fino al 20/06
// Inverno: 21/06 fino al 22/09
// Primavera: 23/09 fino al 20/12

// Esempio di utilizzo del sistema delle stagioni
public OnGameModeInit() {
    // Verifica della stagione attuale
    printf("Stagione attuale: %s", Gettime_Function(JUST_THE_SEASON, LANG_ITALIANO));

    // Utilizzo in un sistema meteorologico
    new weather;
    switch(Get_Season(GFI_months, GFI_days)) {
        case 0: weather = 10; // Estate: Soleggiato
        case 1: weather = 8;  // Autunno: Nuvoloso
        case 2: weather = 12; // Inverno: Tempestoso
        case 3: weather = 2;  // Primavera: Molto soleggiato
    }
    SetWeather(weather);
    
    return true;
}
```

> [!TIP]
> Il sistema delle stagioni può essere utilizzato per creare eventi stagionali nel tuo server, personalizzare automaticamente il meteo o creare decorazioni tematiche basate sulla stagione corrente.

## Licenza

Questo Include è protetto sotto la Licenza Apache 2.0, che permette:

- ✔️ Uso commerciale e privato
- ✔️ Modifica del codice sorgente
- ✔️ Distribuzione del codice
- ✔️ Concessione di brevetti

### Condizioni:

- Mantenere l'avviso di copyright
- Documentare le modifiche significative
- Includere una copia della licenza Apache 2.0

Per maggiori dettagli sulla licenza: http://www.apache.org/licenses/LICENSE-2.0

**Copyright (c) Calasans - Tutti i diritti riservati**