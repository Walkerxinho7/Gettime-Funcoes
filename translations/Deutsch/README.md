# Gettime-Functions

Gettime-Functions ist ein Include, das die nativen SA-MP-Funktionen `gettime()` und `getdate()` in einer vielseitigeren Funktion namens `Gettime_Function` kapselt. Diese Funktion bietet verschiedene Ausgabeformate für Datum und Uhrzeit sowie Unterstützung für 10 verschiedene Sprachen.

## Sprachen

- Português: [README](../../)
- English: [README](../English/README.md)
- Español: [README](../Espanol/README.md)
- Français: [README](../Francais/README.md)
- Italiano: [README](../Italiano/README.md)
- Polski: [README](../Polski/README.md)
- Русский: [README](../Русский/README.md)
- Svenska: [README](../Svenska/README.md)
- Türkçe: [README](../Turkce/README.md)

## Inhaltsverzeichnis

- [Gettime-Functions](#gettime-functions)
  - [Sprachen](#sprachen)
  - [Inhaltsverzeichnis](#inhaltsverzeichnis)
  - [Installation](#installation)
  - [Verwendung](#verwendung)
    - [Parameter](#parameter)
    - [Grundlegende Verwendungsbeispiele](#grundlegende-verwendungsbeispiele)
    - [Fortgeschrittene Beispiele](#fortgeschrittene-beispiele)
  - [Unterstützte Sprachen](#unterstützte-sprachen)
  - [Verfügbare Formattypen](#verfügbare-formattypen)
  - [Besondere Funktionen](#besondere-funktionen)
    - [Datumsformate nach Sprache](#datumsformate-nach-sprache)
    - [Jahreszeitensystem](#jahreszeitensystem)
  - [Lizenz](#lizenz)
    - [Bedingungen:](#bedingungen)

## Installation

1. Laden Sie die Datei [Gettime-Functions.inc](https://github.com/ocalasans/Gettime-Functions/raw/refs/heads/main/src/Gettime-Functions.inc) herunter
2. Legen Sie die Datei im Ordner `pawno/include` Ihres Servers ab
3. Fügen Sie die Datei in Ihr Skript ein:
```pawn
#include <Gettime-Functions>
```

> [!NOTE]
> Das Include überprüft automatisch, ob die `a_samp`-Bibliothek vorhanden ist. Falls nicht, wird während der Kompilierung ein Fehler angezeigt.

## Verwendung

Die Hauptfunktion ist `Gettime_Function(typ, sprache)`, die zwei Parameter akzeptiert:

```pawn
Gettime_Function(GFI_type = DATE_AND_TIME, GFI_lang = LANG_DEUTSCH)
```

### Parameter

- `GFI_type`: Das gewünschte Ausgabeformat (optional, Standard: DATE_AND_TIME)
- `GFI_lang`: Die gewünschte Sprache (optional, Standard: LANG_DEUTSCH)

> [!TIP]
> Sie können beide Parameter weglassen, um die Standardwerte zu verwenden. Die Funktion gibt dann Datum und Uhrzeit im vollständigen Format auf Deutsch zurück.

### Grundlegende Verwendungsbeispiele

```pawn
main() {
    // Standard Datum und Uhrzeit
    printf("Aktuelles Datum und Uhrzeit: %s", Gettime_Function(.GFI_lang = LANG_DEUTSCH));
    // Ausgabe: Aktuelles Datum und Uhrzeit: 17.01.2025 - 15:30:45

    // Nur das Datum
    printf("Aktuelles Datum: %s", Gettime_Function(ONLY_THE_DATE, LANG_DEUTSCH));
    // Ausgabe: Aktuelles Datum: 17.01.2025

    // Nur die Uhrzeit
    printf("Aktuelle Uhrzeit: %s", Gettime_Function(JUST_THE_TIME, LANG_DEUTSCH));
    // Ausgabe: Aktuelle Uhrzeit: 15:30:45

    return true;
}
```

### Fortgeschrittene Beispiele

```pawn
public OnPlayerConnect(playerid) {
    // Beispiel mit Wochentag und ausgeschriebenem Monat
    new welcome[128];
    format(welcome, sizeof(welcome), "Willkommen! Heute ist %s", Gettime_Function(DATE_WEEKDAY, LANG_DEUTSCH));
    SendClientMessage(playerid, -1, welcome); // Ausgabe: Willkommen! Heute ist Freitag, 17.01.2025

    // Beispiel mit mehreren Formaten
    new gettime_info[300];
    format(gettime_info, sizeof(gettime_info), "Gettime Info:\nDatum: %s\nUhrzeit: %s\nJahreszeit: %s",
        Gettime_Function(DATE_MONTH_TEXT, LANG_DEUTSCH),
        Gettime_Function(TIME_AMPM, LANG_DEUTSCH),
        Gettime_Function(JUST_THE_SEASON, LANG_DEUTSCH));
    
    ShowPlayerDialog(playerid, 1, DIALOG_STYLE_MSGBOX, "Gettime Info", gettime_info, "Ok", "");
    // Ausgabe: Gettime Info:
    // Datum: 17 von Januar von 2025
    // Uhrzeit: 03:30 PM
    // Jahreszeit: Sommer

    return true;
}
```

## Unterstützte Sprachen

| Konstante | Sprache | Datumsformat | Datumstrenner |
|-----------|---------|--------------|---------------|
| LANG_DEUTSCH | Deutsch | TT.MM.JJJJ | . |
| LANG_ENGLISH | Englisch | MM/TT/JJJJ | / |
| LANG_ESPANOL | Spanisch | TT/MM/JJJJ | / |
| LANG_FRANCAIS | Französisch | TT/MM/JJJJ | / |
| LANG_ITALIANO | Italienisch | TT/MM/JJJJ | / |
| LANG_POLSKI | Polnisch | TT.MM.JJJJ | . |
| LANG_PORTUGUES | Portugiesisch | TT/MM/JJJJ | / |
| LANG_RUSSIAN | Russisch | TT.MM.JJJJ | . |
| LANG_SVENSKA | Schwedisch | JJJJ-MM-TT | - |
| LANG_TURKCE | Türkisch | TT.MM.JJJJ | . |

> [!NOTE]
> Jede Sprache verfügt über eigene Übersetzungen für Monate, Wochentage und Jahreszeiten sowie spezifische Datumsformate.

## Verfügbare Formattypen

| Konstante | Beschreibung | Beispiel (DE) |
|-----------|--------------|---------------|
| DATE_AND_TIME | Vollständiges Datum und Uhrzeit | 17.01.2025 - 15:30:45 |
| ONLY_THE_DATE | Nur das Datum | 17.01.2025 |
| JUST_THE_TIME | Nur die Uhrzeit | 15:30:45 |
| DATE_WHITOUT_SECONDS | Datum und Uhrzeit ohne Sekunden | 17.01.2025 - 15:30 |
| DATE_WHITOUT_YEAR | Datum ohne Jahr | 17.01 |
| TIME_WITHOUT_SECONDS | Uhrzeit ohne Sekunden | 15:30 |
| JUST_THE_YEAR | Nur das Jahr | 2025 |
| JUST_THE_MONTH | Nur der Monat | 01 |
| JUST_THE_DAY | Nur der Tag | 17 |
| JUST_THE_HOUR | Nur die Stunde | 15 |
| JUST_THE_MINUTE | Nur die Minuten | 30 |
| JUST_THE_SECOND | Nur die Sekunden | 45 |
| DATE_TIME_FULL | Vollständiges Datum und Uhrzeit ohne Strich | 17.01.2025 15:30:45 |
| DATE_TIME_COMPACT | Datum mit Kurz-Jahr und Uhrzeit ohne Sekunden | 17.01.25 15:30 |
| DATE_MONTH_TEXT | Datum mit ausgeschriebenem Monat | 17 von Januar von 2025 |
| TIME_AMPM | Uhrzeit im AM/PM-Format | 03:30 PM |
| DATE_WEEKDAY | Datum mit Wochentag | Freitag, 17.01.2025 |
| DATE_TIME_SEASON | Datum, Uhrzeit und Jahreszeit | Sommer - 17.01.2025 15:30 |
| JUST_THE_SEASON | Nur die Jahreszeit | Sommer |
| DATE_SEASON | Datum mit Jahreszeit | 17.01.2025 - Sommer |
| TIME_SEASON | Uhrzeit mit Jahreszeit | 15:30:45 - Sommer |
| MONTH_YEAR | Monat und Jahr | Januar von 2025 |
| DAY_MONTH | Tag und Monat | 17 von Januar |
| WEEKDAY_ONLY | Nur der Wochentag | Freitag |
| WEEKDAY_TIME | Wochentag und Uhrzeit | Freitag, 15:30:45 |

## Besondere Funktionen

### Datumsformate nach Sprache

> [!IMPORTANT]
> Das Include passt das Datumsformat automatisch an den Länderstandard an:
- Format TT/MM/JJJJ: Portugiesisch, Spanisch, Französisch, Italienisch, etc.
- Format MM/TT/JJJJ: Englisch
- Format JJJJ-MM-TT: Schwedisch

### Jahreszeitensystem
Das Include verfügt über ein intelligentes System zur Bestimmung der Jahreszeit basierend auf dem Datum:

```pawn
// Sommer: 21.12 bis 20.03
// Herbst: 21.03 bis 20.06
// Winter: 21.06 bis 22.09
// Frühling: 23.09 bis 20.12

// Beispiel für die Verwendung des Jahreszeitensystems
public OnGameModeInit() {
    // Aktuelle Jahreszeit überprüfen
    printf("Aktuelle Jahreszeit: %s", Gettime_Function(JUST_THE_SEASON, LANG_DEUTSCH));

    // Verwendung in einem Wettersystem
    new weather;
    switch(Get_Season(GFI_months, GFI_days)) {
        case 0: weather = 10; // Sommer: Sonnig
        case 1: weather = 8;  // Herbst: Bewölkt
        case 2: weather = 12; // Winter: Stürmisch
        case 3: weather = 2;  // Frühling: Extra sonnig
    }
    SetWeather(weather);
    
    return true;
}
```

> [!TIP]
> Das Jahreszeitensystem kann verwendet werden, um saisonale Events auf Ihrem Server zu erstellen, das Wetter automatisch anzupassen oder thematische Dekorationen basierend auf der aktuellen Jahreszeit zu erstellen.

## Lizenz

Dieses Include steht unter der Apache 2.0 Lizenz, die Folgendes erlaubt:

- ✔️ Kommerzielle und private Nutzung
- ✔️ Modifikation des Quellcodes
- ✔️ Verteilung des Codes
- ✔️ Patenterteilung

### Bedingungen:

- Urheberrechtshinweis beibehalten
- Wesentliche Änderungen dokumentieren
- Kopie der Apache 2.0 Lizenz beifügen

Weitere Details zur Lizenz: http://www.apache.org/licenses/LICENSE-2.0

**Copyright (c) Calasans - Alle Rechte vorbehalten**