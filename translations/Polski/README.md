# Gettime-Functions

Gettime-Functions to include, który łączy natywne funkcje SA-MP `gettime()` i `getdate()` w jedną wszechstronną funkcję o nazwie `Gettime_Function`. Ta funkcja oferuje różne formaty wyjściowe dla daty i czasu, a także obsługuje 10 różnych języków.

## Języki

- Português: [README](../../)
- Deutsch: [README](../Deutsch/README.md)
- English: [README](../English/README.md)
- Español: [README](../Espanol/README.md)
- Français: [README](../Francais/README.md)
- Italiano: [README](../Italiano/README.md)
- Русский: [README](../Русский/README.md)
- Svenska: [README](../Svenska/README.md)
- Türkçe: [README](../Turkce/README.md)

## Spis treści

- [Gettime-Functions](#gettime-functions)
  - [Języki](#języki)
  - [Spis treści](#spis-treści)
  - [Instalacja](#instalacja)
  - [Jak używać](#jak-używać)
    - [Parametry](#parametry)
    - [Podstawowe przykłady użycia](#podstawowe-przykłady-użycia)
    - [Zaawansowane przykłady](#zaawansowane-przykłady)
  - [Obsługiwane języki](#obsługiwane-języki)
  - [Dostępne typy formatów](#dostępne-typy-formatów)
  - [Funkcje specjalne](#funkcje-specjalne)
    - [Formaty daty według języka](#formaty-daty-według-języka)
    - [System pór roku](#system-pór-roku)
  - [Licencja](#licencja)
    - [Warunki:](#warunki)

## Instalacja

1. Pobierz plik [Gettime-Functions.inc](https://github.com/ocalasans/Anti-Ping/raw/refs/heads/main/src/Gettime-Functions.inc)
2. Umieść plik w folderze `pawno/include` twojego serwera
3. Dołącz plik do swojego skryptu:
```pawn
#include <Gettime-Functions>
```

> [!NOTE]
> Include automatycznie sprawdza, czy biblioteka `a_samp` jest obecna. Jeśli nie, podczas kompilacji zostanie wyświetlony błąd.

## Jak używać

Główna funkcja to `Gettime_Function(typ, język)`, która przyjmuje dwa parametry:

```pawn
Gettime_Function(GFI_type = DATE_AND_TIME, GFI_lang = LANG_POLSKI)
```

### Parametry

- `GFI_type`: Żądany format wyjściowy (opcjonalny, domyślnie: DATE_AND_TIME)
- `GFI_lang`: Żądany język (opcjonalny, domyślnie: LANG_POLSKI)

> [!TIP]
> Możesz pominąć oba parametry, aby użyć wartości domyślnych. Funkcja zwróci datę i godzinę w pełnym formacie po polsku.

### Podstawowe przykłady użycia

```pawn
main() {
    // Domyślna data i godzina
    printf("Aktualna data i godzina: %s", Gettime_Function(.GFI_lang = LANG_POLSKI));
    // Wyjście: Aktualna data i godzina: 17.01.2025 - 15:30:45

    // Tylko data
    printf("Aktualna data: %s", Gettime_Function(ONLY_THE_DATE, LANG_POLSKI));
    // Wyjście: Aktualna data: 17.01.2025

    // Tylko godzina
    printf("Aktualna godzina: %s", Gettime_Function(JUST_THE_TIME, LANG_POLSKI));
    // Wyjście: Aktualna godzina: 15:30:45

    return true;
}
```

### Zaawansowane przykłady

```pawn
public OnPlayerConnect(playerid) {
    // Przykład z dniem tygodnia i miesiącem słownie
    new welcome[128];
    format(welcome, sizeof(welcome), "Witaj! Dziś jest %s", Gettime_Function(DATE_WEEKDAY, LANG_POLSKI));
    SendClientMessage(playerid, -1, welcome); // Wyjście: Witaj! Dziś jest Piątek, 17.01.2025

    // Przykład z wieloma formatami
    new gettime_info[300];
    format(gettime_info, sizeof(gettime_info), "Informacje o czasie:\nData: %s\nGodzina: %s\nPora roku: %s",
        Gettime_Function(DATE_MONTH_TEXT, LANG_POLSKI),
        Gettime_Function(TIME_AMPM, LANG_POLSKI),
        Gettime_Function(JUST_THE_SEASON, LANG_POLSKI));
    
    ShowPlayerDialog(playerid, 1, DIALOG_STYLE_MSGBOX, "Informacje o czasie", gettime_info, "Ok", "");
    // Wyjście: Informacje o czasie:
    // Data: 17 Stycznia 2025
    // Godzina: 03:30 PM
    // Pora roku: Lato

    return true;
}
```

## Obsługiwane języki

| Stała | Język | Format daty | Separator daty |
|-----------|--------|-----------------|-------------------|
| LANG_DEUTSCH | Niemiecki | DD.MM.YYYY | . |
| LANG_ENGLISH | Angielski | MM/DD/YYYY | / |
| LANG_ESPANOL | Hiszpański | DD/MM/YYYY | / |
| LANG_FRANCAIS | Francuski | DD/MM/YYYY | / |
| LANG_ITALIANO | Włoski | DD/MM/YYYY | / |
| LANG_POLSKI | Polski | DD.MM.YYYY | . |
| LANG_PORTUGUES | Portugalski | DD/MM/YYYY | / |
| LANG_RUSSIAN | Rosyjski | DD.MM.YYYY | . |
| LANG_SVENSKA | Szwedzki | YYYY-MM-DD | - |
| LANG_TURKCE | Turecki | DD.MM.YYYY | . |

> [!NOTE]
> Każdy język ma własne tłumaczenia miesięcy, dni tygodnia i pór roku, a także specyficzne formaty daty.

## Dostępne typy formatów

| Stała | Opis | Przykład (PL) |
|-----------|-----------|-----------------|
| DATE_AND_TIME | Pełna data i godzina | 17.01.2025 - 15:30:45 |
| ONLY_THE_DATE | Tylko data | 17.01.2025 |
| JUST_THE_TIME | Tylko godzina | 15:30:45 |
| DATE_WHITOUT_SECONDS | Data i godzina bez sekund | 17.01.2025 - 15:30 |
| DATE_WHITOUT_YEAR | Data bez roku | 17.01 |
| TIME_WITHOUT_SECONDS | Godzina bez sekund | 15:30 |
| JUST_THE_YEAR | Tylko rok | 2025 |
| JUST_THE_MONTH | Tylko miesiąc | 01 |
| JUST_THE_DAY | Tylko dzień | 17 |
| JUST_THE_HOUR | Tylko godzina | 15 |
| JUST_THE_MINUTE | Tylko minuty | 30 |
| JUST_THE_SECOND | Tylko sekundy | 45 |
| DATE_TIME_FULL | Pełna data i godzina bez myślnika | 17.01.2025 15:30:45 |
| DATE_TIME_COMPACT | Data z krótkim rokiem i godzina bez sekund | 17.01.25 15:30 |
| DATE_MONTH_TEXT | Data z miesiącem słownie | 17 Stycznia 2025 |
| TIME_AMPM | Godzina w formacie AM/PM | 03:30 PM |
| DATE_WEEKDAY | Data z dniem tygodnia | Piątek, 17.01.2025 |
| DATE_TIME_SEASON | Data, godzina i pora roku | Lato - 17.01.2025 15:30 |
| JUST_THE_SEASON | Tylko pora roku | Lato |
| DATE_SEASON | Data z porą roku | 17.01.2025 - Lato |
| TIME_SEASON | Godzina z porą roku | 15:30:45 - Lato |
| MONTH_YEAR | Miesiąc i rok | Styczeń 2025 |
| DAY_MONTH | Dzień i miesiąc | 17 Stycznia |
| WEEKDAY_ONLY | Tylko dzień tygodnia | Piątek |
| WEEKDAY_TIME | Dzień tygodnia i godzina | Piątek, 15:30:45 |

## Funkcje specjalne

### Formaty daty według języka

> [!IMPORTANT]
> Include automatycznie dostosowuje format daty zgodnie ze standardem kraju:
- Format DD/MM/YYYY: Portugalski, Hiszpański, Francuski, Włoski, itd.
- Format MM/DD/YYYY: Angielski
- Format YYYY-MM-DD: Szwedzki

### System pór roku
Include posiada inteligentny system, który określa porę roku na podstawie daty:

```pawn
// Lato: 21/12 do 20/03
// Jesień: 21/03 do 20/06
// Zima: 21/06 do 22/09
// Wiosna: 23/09 do 20/12

// Przykład użycia systemu pór roku
public OnGameModeInit() {
    // Sprawdzanie aktualnej pory roku
    printf("Aktualna pora roku: %s", Gettime_Function(JUST_THE_SEASON, LANG_POLSKI));

    // Używanie w systemie pogody
    new weather;
    switch(Get_Season(GFI_months, GFI_days)) {
        case 0: weather = 10; // Lato: Słonecznie
        case 1: weather = 8;  // Jesień: Pochmurno
        case 2: weather = 12; // Zima: Burzowo
        case 3: weather = 2;  // Wiosna: Bardzo słonecznie
    }
    SetWeather(weather);
    
    return true;
}
```

> [!TIP]
> System pór roku może być używany do tworzenia sezonowych wydarzeń na serwerze, automatycznego dostosowywania pogody lub tworzenia tematycznych dekoracji opartych na aktualnej porze roku.

## Licencja

Ten Include jest chroniony Licencją Apache 2.0, która zezwala na:

- ✔️ Użytek komercyjny i prywatny
- ✔️ Modyfikację kodu źródłowego
- ✔️ Dystrybucję kodu
- ✔️ Udzielanie patentów

### Warunki:

- Zachowanie informacji o prawach autorskich
- Dokumentowanie znaczących zmian
- Dołączenie kopii licencji Apache 2.0

Więcej szczegółów o licencji: http://www.apache.org/licenses/LICENSE-2.0

**Copyright (c) Calasans - Wszelkie prawa zastrzeżone**