# Gettime-Functions

Gettime-Functions är ett tillägg som kapslar in SA-MPs inbyggda funktioner `gettime()` och `getdate()` i en enda mer mångsidig funktion kallad `Gettime_Function`. Denna funktion erbjuder olika utdataformat för datum och tid, samt stöd för 10 olika språk.

## Språk

- Português: [README](../../)
- Deutsch: [README](../Deutsch/README.md)
- English: [README](../English/README.md)
- Español: [README](../Espanol/README.md)
- Français: [README](../Francais/README.md)
- Italiano: [README](../Italiano/README.md)
- Polski: [README](../Polski/README.md)
- Русский: [README](../Русский/README.md)
- Türkçe: [README](../Turkce/README.md)

## Innehållsförteckning

- [Gettime-Functions](#gettime-functions)
  - [Språk](#språk)
  - [Innehållsförteckning](#innehållsförteckning)
  - [Installation](#installation)
  - [Användning](#användning)
    - [Parametrar](#parametrar)
    - [Grundläggande exempel](#grundläggande-exempel)
    - [Avancerade exempel](#avancerade-exempel)
  - [Språkstöd](#språkstöd)
  - [Tillgängliga formattyper](#tillgängliga-formattyper)
  - [Specialfunktioner](#specialfunktioner)
    - [Datumformat per språk](#datumformat-per-språk)
    - [Årstidssystem](#årstidssystem)
  - [Licens](#licens)
    - [Villkor:](#villkor)

## Installation

1. Ladda ner filen [Gettime-Functions.inc](https://github.com/ocalasans/Anti-Ping/raw/refs/heads/main/src/Gettime-Functions.inc)
2. Placera filen i din servers `pawno/include` mapp
3. Inkludera filen i ditt skript:
```pawn
#include <Gettime-Functions>
```

> [!NOTE]
> Tillägget kontrollerar automatiskt om `a_samp` biblioteket finns. Om det saknas visas ett felmeddelande under kompileringen.

## Användning

Huvudfunktionen är `Gettime_Function(typ, språk)` som tar två parametrar:

```pawn
Gettime_Function(GFI_type = DATE_AND_TIME, GFI_lang = LANG_SVENSKA)
```

### Parametrar

- `GFI_type`: Önskat utdataformat (valfritt, standard: DATE_AND_TIME)
- `GFI_lang`: Önskat språk (valfritt, standard: LANG_SVENSKA)

> [!TIP]
> Du kan utelämna båda parametrarna för att använda standardvärdena. Funktionen returnerar då datum och tid i fullständigt format på svenska.

### Grundläggande exempel

```pawn
main() {
    // Standard datum och tid
    printf("Aktuellt datum och tid: %s", Gettime_Function(.GFI_lang = LANG_SVENSKA));
    // Utdata: Aktuellt datum och tid: 2025-01-17 - 15:30:45

    // Endast datum
    printf("Aktuellt datum: %s", Gettime_Function(ONLY_THE_DATE, LANG_SVENSKA));
    // Utdata: Aktuellt datum: 2025-01-17

    // Endast tid
    printf("Aktuell tid: %s", Gettime_Function(JUST_THE_TIME, LANG_SVENSKA));
    // Utdata: Aktuell tid: 15:30:45

    return true;
}
```

### Avancerade exempel

```pawn
public OnPlayerConnect(playerid) {
    // Exempel med veckodag och månadsnamn
    new welcome[128];
    format(welcome, sizeof(welcome), "Välkommen! Idag är det %s", Gettime_Function(DATE_WEEKDAY, LANG_SVENSKA));
    SendClientMessage(playerid, -1, welcome); // Utdata: Välkommen! Idag är det Fredag, 2025-01-17

    // Exempel med flera format
    new gettime_info[300];
    format(gettime_info, sizeof(gettime_info), "Gettime Info:\nDatum: %s\nTid: %s\nÅrstid: %s",
        Gettime_Function(DATE_MONTH_TEXT, LANG_SVENSKA),
        Gettime_Function(TIME_AMPM, LANG_SVENSKA),
        Gettime_Function(JUST_THE_SEASON, LANG_SVENSKA));
    
    ShowPlayerDialog(playerid, 1, DIALOG_STYLE_MSGBOX, "Gettime Info", gettime_info, "Ok", "");
    // Utdata: Gettime Info:
    // Datum: 17 Januari 2025
    // Tid: 03:30 PM
    // Årstid: Sommar

    return true;
}
```

## Språkstöd

| Konstant | Språk | Datumformat | Datumseparator |
|-----------|--------|-----------------|-------------------|
| LANG_DEUTSCH | Tyska | DD.MM.YYYY | . |
| LANG_ENGLISH | Engelska | MM/DD/YYYY | / |
| LANG_ESPANOL | Spanska | DD/MM/YYYY | / |
| LANG_FRANCAIS | Franska | DD/MM/YYYY | / |
| LANG_ITALIANO | Italienska | DD/MM/YYYY | / |
| LANG_POLSKI | Polska | DD.MM.YYYY | . |
| LANG_PORTUGUES | Portugisiska | DD/MM/YYYY | / |
| LANG_RUSSIAN | Ryska | DD.MM.YYYY | . |
| LANG_SVENSKA | Svenska | YYYY-MM-DD | - |
| LANG_TURKCE | Turkiska | DD.MM.YYYY | . |

> [!NOTE]
> Varje språk har sina egna översättningar för månader, veckodagar och årstider, samt specifika datumformat.

## Tillgängliga formattyper

| Konstant | Beskrivning | Exempel (Svenska) |
|-----------|-----------|-----------------|
| DATE_AND_TIME | Fullständigt datum och tid | 2025-01-17 - 15:30:45 |
| ONLY_THE_DATE | Endast datum | 2025-01-17 |
| JUST_THE_TIME | Endast tid | 15:30:45 |
| DATE_WHITOUT_SECONDS | Datum och tid utan sekunder | 2025-01-17 - 15:30 |
| DATE_WHITOUT_YEAR | Datum utan år | 01-17 |
| TIME_WITHOUT_SECONDS | Tid utan sekunder | 15:30 |
| JUST_THE_YEAR | Endast år | 2025 |
| JUST_THE_MONTH | Endast månad | 01 |
| JUST_THE_DAY | Endast dag | 17 |
| JUST_THE_HOUR | Endast timme | 15 |
| JUST_THE_MINUTE | Endast minuter | 30 |
| JUST_THE_SECOND | Endast sekunder | 45 |
| DATE_TIME_FULL | Fullständigt datum och tid utan streck | 2025-01-17 15:30:45 |
| DATE_TIME_COMPACT | Datum med kort år och tid utan sekunder | 25-01-17 15:30 |
| DATE_MONTH_TEXT | Datum med månadsnamn | 17 Januari 2025 |
| TIME_AMPM | Tid i AM/PM-format | 03:30 PM |
| DATE_WEEKDAY | Datum med veckodag | Fredag, 2025-01-17 |
| DATE_TIME_SEASON | Datum, tid och årstid | Sommar - 2025-01-17 15:30 |
| JUST_THE_SEASON | Endast årstid | Sommar |
| DATE_SEASON | Datum med årstid | 2025-01-17 - Sommar |
| TIME_SEASON | Tid med årstid | 15:30:45 - Sommar |
| MONTH_YEAR | Månad och år | Januari 2025 |
| DAY_MONTH | Dag och månad | 17 Januari |
| WEEKDAY_ONLY | Endast veckodag | Fredag |
| WEEKDAY_TIME | Veckodag och tid | Fredag, 15:30:45 |

## Specialfunktioner

### Datumformat per språk

> [!IMPORTANT]
> Tillägget justerar automatiskt datumformatet enligt landets standard:
- Format DD/MM/YYYY: Portugisiska, Spanska, Franska, Italienska, etc.
- Format MM/DD/YYYY: Engelska
- Format YYYY-MM-DD: Svenska

### Årstidssystem
Tillägget har ett intelligent system som bestämmer årstiden baserat på datumet:

```pawn
// Sommar: 21/12 till 20/03
// Höst: 21/03 till 20/06
// Vinter: 21/06 till 22/09
// Vår: 23/09 till 20/12

// Exempel på användning av årstidssystemet
public OnGameModeInit() {
    // Kontrollera aktuell årstid
    printf("Aktuell årstid: %s", Gettime_Function(JUST_THE_SEASON, LANG_SVENSKA));

    // Användning i ett vädersystem
    new weather;
    switch(Get_Season(GFI_months, GFI_days)) {
        case 0: weather = 10; // Sommar: Soligt
        case 1: weather = 8;  // Höst: Molnigt
        case 2: weather = 12; // Vinter: Stormigt
        case 3: weather = 2;  // Vår: Extra soligt
    }
    SetWeather(weather);
    
    return true;
}
```

> [!TIP]
> Årstidssystemet kan användas för att skapa säsongsbaserade händelser på din server, automatiskt anpassa vädret eller skapa tematiska dekorationer baserade på aktuell årstid.

## Licens

Detta tillägg är skyddat under Apache License 2.0, som tillåter:

- ✔️ Kommersiell och privat användning
- ✔️ Modifiering av källkoden
- ✔️ Distribution av koden
- ✔️ Patentbeviljning

### Villkor:

- Behåll upphovsrättsmeddelandet
- Dokumentera betydande ändringar
- Inkludera en kopia av Apache 2.0-licensen

För mer information om licensen: http://www.apache.org/licenses/LICENSE-2.0

**Copyright (c) Calasans - Alla rättigheter förbehållna**