# Gettime-Functions

Gettime-Functions is an include that encapsulates SA-MP's native `gettime()` and `getdate()` functions into a more versatile single function called `Gettime_Function`. This function offers various output formats for date and time, plus support for 10 different languages.

## Languages

- Português: [README](../../)
- Deutsch: [README](../Deutsch/README.md)
- Español: [README](../Espanol/README.md)
- Français: [README](../Francais/README.md)
- Italiano: [README](../Italiano/README.md)
- Polski: [README](../Polski/README.md)
- Русский: [README](../Русский/README.md)
- Svenska: [README](../Svenska/README.md)
- Türkçe: [README](../Turkce/README.md)

## Table of Contents

- [Gettime-Functions](#gettime-functions)
  - [Languages](#languages)
  - [Table of Contents](#table-of-contents)
  - [Installation](#installation)
  - [How to Use](#how-to-use)
    - [Parameters](#parameters)
    - [Basic Usage Examples](#basic-usage-examples)
    - [Advanced Examples](#advanced-examples)
  - [Supported Languages](#supported-languages)
  - [Available Format Types](#available-format-types)
  - [Special Features](#special-features)
    - [Date Formats by Language](#date-formats-by-language)
    - [Seasons System](#seasons-system)
  - [License](#license)
    - [Conditions:](#conditions)

## Installation

1. Download the [Gettime-Functions.inc](https://github.com/ocalasans/Anti-Ping/raw/refs/heads/main/src/Gettime-Functions.inc) file
2. Place the file in your server's `pawno/include` folder
3. Include the file in your script:
```pawn
#include <Gettime-Functions>
```

> [!NOTE]
> The include automatically checks if the `a_samp` library is present. If it's not, an error will be displayed during compilation.

## How to Use

The main function is `Gettime_Function(type, language)` which accepts two parameters:

```pawn
Gettime_Function(GFI_type = DATE_AND_TIME, GFI_lang = LANG_ENGLISH)
```

### Parameters

- `GFI_type`: The desired output format (optional, default: DATE_AND_TIME)
- `GFI_lang`: The desired language (optional, default: LANG_ENGLISH)

> [!TIP]
> You can omit both parameters to use the default values. The function will return the date and time in the complete format in English.

### Basic Usage Examples

```pawn
main() {
    // Default date and time
    printf("Current date and time: %s", Gettime_Function(.GFI_lang = LANG_ENGLISH));
    // Output: Current date and time: 01/17/2025 - 15:30:45

    // Only the date
    printf("Current date: %s", Gettime_Function(ONLY_THE_DATE, LANG_ENGLISH));
    // Output: Current date: 01/17/2025

    // Only the time
    printf("Current time: %s", Gettime_Function(JUST_THE_TIME, LANG_ENGLISH));
    // Output: Current time: 15:30:45

    return true;
}
```

### Advanced Examples

```pawn
public OnPlayerConnect(playerid) {
    // Example with weekday and month in text form
    new welcome[128];
    format(welcome, sizeof(welcome), "Welcome! Today is %s", Gettime_Function(DATE_WEEKDAY, LANG_ENGLISH));
    SendClientMessage(playerid, -1, welcome); // Output: Welcome! Today is Friday, 01/17/2025

    // Example with multiple formats
    new gettime_info[300];
    format(gettime_info, sizeof(gettime_info), "Gettime Info:\nDate: %s\nTime: %s\nSeason: %s",
        Gettime_Function(DATE_MONTH_TEXT, LANG_ENGLISH),
        Gettime_Function(TIME_AMPM, LANG_ENGLISH),
        Gettime_Function(JUST_THE_SEASON, LANG_ENGLISH));
    
    ShowPlayerDialog(playerid, 1, DIALOG_STYLE_MSGBOX, "Gettime Info", gettime_info, "Ok", "");
    // Output: Gettime Info:
    // Date: January 17 of 2025
    // Time: 03:30 PM
    // Season: Summer

    return true;
}
```

## Supported Languages

| Constant | Language | Date Format | Date Separator |
|----------|----------|-------------|----------------|
| LANG_DEUTSCH | German | DD.MM.YYYY | . |
| LANG_ENGLISH | English | MM/DD/YYYY | / |
| LANG_ESPANOL | Spanish | DD/MM/YYYY | / |
| LANG_FRANCAIS | French | DD/MM/YYYY | / |
| LANG_ITALIANO | Italian | DD/MM/YYYY | / |
| LANG_POLSKI | Polish | DD.MM.YYYY | . |
| LANG_PORTUGUES | Portuguese | DD/MM/YYYY | / |
| LANG_RUSSIAN | Russian | DD.MM.YYYY | . |
| LANG_SVENSKA | Swedish | YYYY-MM-DD | - |
| LANG_TURKCE | Turkish | DD.MM.YYYY | . |

> [!NOTE]
> Each language has its own .. for months, weekdays, and seasons, as well as specific date formats.

## Available Format Types

| Constant | Description | Example (EN) |
|----------|-------------|--------------|
| DATE_AND_TIME | Complete date and time | 01/17/2025 - 15:30:45 |
| ONLY_THE_DATE | Only the date | 01/17/2025 |
| JUST_THE_TIME | Only the time | 15:30:45 |
| DATE_WHITOUT_SECONDS | Date and time without seconds | 01/17/2025 - 15:30 |
| DATE_WHITOUT_YEAR | Date without year | 01/17 |
| TIME_WITHOUT_SECONDS | Time without seconds | 15:30 |
| JUST_THE_YEAR | Only the year | 2025 |
| JUST_THE_MONTH | Only the month | 01 |
| JUST_THE_DAY | Only the day | 17 |
| JUST_THE_HOUR | Only the hour | 15 |
| JUST_THE_MINUTE | Only the minutes | 30 |
| JUST_THE_SECOND | Only the seconds | 45 |
| DATE_TIME_FULL | Complete date and time without dash | 01/17/2025 15:30:45 |
| DATE_TIME_COMPACT | Date with short year and time without seconds | 01/17/25 15:30 |
| DATE_MONTH_TEXT | Date with month in text form | January 17 of 2025 |
| TIME_AMPM | Time in AM/PM format | 03:30 PM |
| DATE_WEEKDAY | Date with weekday | Friday, 01/17/2025 |
| DATE_TIME_SEASON | Date, time and season | Summer - 01/17/2025 15:30 |
| JUST_THE_SEASON | Only the season | Summer |
| DATE_SEASON | Date with season | 01/17/2025 - Summer |
| TIME_SEASON | Time with season | 15:30:45 - Summer |
| MONTH_YEAR | Month and year | January of 2025 |
| DAY_MONTH | Day and month | 17 of January |
| WEEKDAY_ONLY | Only the weekday | Friday |
| WEEKDAY_TIME | Weekday and time | Friday, 15:30:45 |

## Special Features

### Date Formats by Language

> [!IMPORTANT]
> The include automatically adjusts the date format according to the country's standard:
- DD/MM/YYYY format: Portuguese, Spanish, French, Italian, etc.
- MM/DD/YYYY format: English
- YYYY-MM-DD format: Swedish

### Seasons System
The include has an intelligent system that determines the season based on the date:

```pawn
// Summer: 12/21 to 03/20
// Autumn: 03/21 to 06/20
// Winter: 06/21 to 09/22
// Spring: 09/23 to 12/20

// Example of using the seasons system
public OnGameModeInit() {
    // Checking current season
    printf("Current season: %s", Gettime_Function(JUST_THE_SEASON, LANG_ENGLISH));

    // Using in a weather system
    new weather;
    switch(Get_Season(GFI_months, GFI_days)) {
        case 0: weather = 10; // Summer: Sunny
        case 1: weather = 8;  // Autumn: Cloudy
        case 2: weather = 12; // Winter: Stormy
        case 3: weather = 2;  // Spring: Extra Sunny
    }
    SetWeather(weather);
    
    return true;
}
```

> [!TIP]
> The seasons system can be used to create seasonal events in your server, automatically customize weather, or create themed decorations based on the current season.

## License

This Include is protected under the Apache License 2.0, which allows:

- ✔️ Commercial and private use
- ✔️ Source code modification
- ✔️ Code distribution
- ✔️ Patent grant

### Conditions:

- Maintain copyright notice
- Document significant changes
- Include Apache License 2.0 copy

For more details about the license: http://www.apache.org/licenses/LICENSE-2.0

**Copyright (c) Calasans - All rights reserved**