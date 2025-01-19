# Gettime-Functions

Gettime-Functions est un include qui encapsule les fonctions natives `gettime()` et `getdate()` de SA-MP dans une seule fonction plus polyvalente appelée `Gettime_Function`. Cette fonction offre plusieurs formats de sortie pour la date et l'heure, ainsi que la prise en charge de 10 langues différentes.

## Langues

- Português: [README](../../)
- Deutsch: [README](../Deutsch/README.md)
- English: [README](../English/README.md)
- Español: [README](../Espanol/README.md)
- Italiano: [README](../Italiano/README.md)
- Polski: [README](../Polski/README.md)
- Русский: [README](../Русский/README.md)
- Svenska: [README](../Svenska/README.md)
- Türkçe: [README](../Turkce/README.md)

## Table des matières

- [Gettime-Functions](#gettime-functions)
  - [Langues](#langues)
  - [Table des matières](#table-des-matières)
  - [Installation](#installation)
  - [Comment utiliser](#comment-utiliser)
    - [Paramètres](#paramètres)
    - [Exemples d'utilisation basique](#exemples-dutilisation-basique)
    - [Exemples avancés](#exemples-avancés)
  - [Langues supportées](#langues-supportées)
  - [Types de formats disponibles](#types-de-formats-disponibles)
  - [Caractéristiques spéciales](#caractéristiques-spéciales)
    - [Formats de date par langue](#formats-de-date-par-langue)
    - [Système de saisons](#système-de-saisons)
  - [Licence](#licence)
    - [Conditions](#conditions)

## Installation

1. Téléchargez le fichier [Gettime-Functions.inc](https://github.com/ocalasans/Gettime-Functions/releases/download/v1.0.2/Gettime-Functions.inc)
2. Placez le fichier dans le dossier `pawno/include` de votre serveur
3. Incluez le fichier dans votre script :
```pawn
#include <Gettime-Functions>
```

> [!NOTE]
> L'include vérifie automatiquement si la bibliothèque `a_samp` est présente. Si elle ne l'est pas, une erreur s'affichera lors de la compilation.

## Comment utiliser

La fonction principale est `Gettime_Function(type, langue)` qui accepte deux paramètres :

```pawn
Gettime_Function(GFI_type = DATE_AND_TIME, GFI_lang = LANG_FRANCAIS)
```

### Paramètres

- `GFI_type` : Le format de sortie souhaité (optionnel, par défaut : DATE_AND_TIME)
- `GFI_lang` : La langue souhaitée (optionnel, par défaut : LANG_FRANCAIS)

> [!TIP]
> Vous pouvez omettre les deux paramètres pour utiliser les valeurs par défaut. La fonction retournera la date et l'heure au format complet en français.

### Exemples d'utilisation basique

```pawn
main() {
    // Date et heure par défaut
    printf("Date et heure actuelles : %s", Gettime_Function(.GFI_lang = LANG_FRANCAIS));
    // Sortie : Date et heure actuelles : 17/01/2025 - 15:30:45

    // Uniquement la date
    printf("Date actuelle : %s", Gettime_Function(ONLY_THE_DATE, LANG_FRANCAIS));
    // Sortie : Date actuelle : 17/01/2025

    // Uniquement l'heure
    printf("Heure actuelle : %s", Gettime_Function(JUST_THE_TIME, LANG_FRANCAIS));
    // Sortie : Heure actuelle : 15:30:45

    return true;
}
```

### Exemples avancés

```pawn
public OnPlayerConnect(playerid) {
    // Exemple avec jour de la semaine et mois en toutes lettres
    new welcome[128];
    format(welcome, sizeof(welcome), "Bienvenue ! Aujourd'hui nous sommes %s", Gettime_Function(DATE_WEEKDAY, LANG_FRANCAIS));
    SendClientMessage(playerid, -1, welcome); // Sortie : Bienvenue ! Aujourd'hui nous sommes Vendredi, 17/01/2025

    // Exemple avec plusieurs formats
    new gettime_info[300];
    format(gettime_info, sizeof(gettime_info), "Info Gettime :\nDate : %s\nHeure : %s\nSaison : %s",
        Gettime_Function(DATE_MONTH_TEXT, LANG_FRANCAIS),
        Gettime_Function(TIME_AMPM, LANG_FRANCAIS),
        Gettime_Function(JUST_THE_SEASON, LANG_FRANCAIS));
    
    ShowPlayerDialog(playerid, 1, DIALOG_STYLE_MSGBOX, "Info Gettime", gettime_info, "Ok", "");
    // Sortie : Info Gettime :
    // Date : 17 de Janvier de 2025
    // Heure : 03:30 PM
    // Saison : Été

    return true;
}
```

## Langues supportées

| Constante | Langue | Format de date | Séparateur de date |
|-----------|--------|----------------|-------------------|
| LANG_DEUTSCH | Allemand | JJ.MM.AAAA | . |
| LANG_ENGLISH | Anglais | MM/JJ/AAAA | / |
| LANG_ESPANOL | Espagnol | JJ/MM/AAAA | / |
| LANG_FRANCAIS | Français | JJ/MM/AAAA | / |
| LANG_ITALIANO | Italien | JJ/MM/AAAA | / |
| LANG_POLSKI | Polonais | JJ.MM.AAAA | . |
| LANG_PORTUGUES | Portugais | JJ/MM/AAAA | / |
| LANG_RUSSIAN | Russe | JJ.MM.AAAA | . |
| LANG_SVENSKA | Suédois | AAAA-MM-JJ | - |
| LANG_TURKCE | Turc | JJ.MM.AAAA | . |

> [!NOTE]
> Chaque langue possède ses propres traductions pour les mois, les jours de la semaine et les saisons, ainsi que des formats de date spécifiques.

## Types de formats disponibles

| Constante | Description | Exemple (FR) |
|-----------|-------------|--------------|
| DATE_AND_TIME | Date et heure complètes | 17/01/2025 - 15:30:45 |
| ONLY_THE_DATE | Uniquement la date | 17/01/2025 |
| JUST_THE_TIME | Uniquement l'heure | 15:30:45 |
| DATE_WHITOUT_SECONDS | Date et heure sans secondes | 17/01/2025 - 15:30 |
| DATE_WHITOUT_YEAR | Date sans l'année | 17/01 |
| TIME_WITHOUT_SECONDS | Heure sans secondes | 15:30 |
| JUST_THE_YEAR | Uniquement l'année | 2025 |
| JUST_THE_MONTH | Uniquement le mois | 01 |
| JUST_THE_DAY | Uniquement le jour | 17 |
| JUST_THE_HOUR | Uniquement l'heure | 15 |
| JUST_THE_MINUTE | Uniquement les minutes | 30 |
| JUST_THE_SECOND | Uniquement les secondes | 45 |
| DATE_TIME_FULL | Date et heure complètes sans tiret | 17/01/2025 15:30:45 |
| DATE_TIME_COMPACT | Date avec année courte et heure sans secondes | 17/01/25 15:30 |
| DATE_MONTH_TEXT | Date avec mois en toutes lettres | 17 de Janvier de 2025 |
| TIME_AMPM | Heure au format AM/PM | 03:30 PM |
| DATE_WEEKDAY | Date avec jour de la semaine | Vendredi, 17/01/2025 |
| DATE_TIME_SEASON | Date, heure et saison | Été - 17/01/2025 15:30 |
| JUST_THE_SEASON | Uniquement la saison | Été |
| DATE_SEASON | Date avec saison | 17/01/2025 - Été |
| TIME_SEASON | Heure avec saison | 15:30:45 - Été |
| MONTH_YEAR | Mois et année | Janvier de 2025 |
| DAY_MONTH | Jour et mois | 17 de Janvier |
| WEEKDAY_ONLY | Uniquement le jour de la semaine | Vendredi |
| WEEKDAY_TIME | Jour de la semaine et heure | Vendredi, 15:30:45 |

## Caractéristiques spéciales

### Formats de date par langue

> [!IMPORTANT]
> L'include ajuste automatiquement le format de la date selon le standard du pays :
- Format JJ/MM/AAAA : Français, Portugais, Espagnol, Italien, etc.
- Format MM/JJ/AAAA : Anglais
- Format AAAA-MM-JJ : Suédois

### Système de saisons
L'include possède un système intelligent qui détermine la saison en fonction de la date :

```pawn
// Été : 21/12 au 20/03
// Automne : 21/03 au 20/06
// Hiver : 21/06 au 22/09
// Printemps : 23/09 au 20/12

// Exemple d'utilisation du système de saisons
public OnGameModeInit() {
    // Vérification de la saison actuelle
    printf("Saison actuelle : %s", Gettime_Function(JUST_THE_SEASON, LANG_FRANCAIS));

    // Utilisation dans un système météo
    new weather;
    switch(Get_Season(GFI_months, GFI_days)) {
        case 0: weather = 10; // Été : Ensoleillé
        case 1: weather = 8;  // Automne : Nuageux
        case 2: weather = 12; // Hiver : Orageux
        case 3: weather = 2;  // Printemps : Très ensoleillé
    }
    SetWeather(weather);
    
    return true;
}
```

> [!TIP]
> Le système de saisons peut être utilisé pour créer des événements saisonniers sur votre serveur, personnaliser automatiquement la météo ou créer des décorations thématiques basées sur la saison actuelle.

## Licence

Cet Include est protégé sous la Licence Apache 2.0, qui permet :

- ✔️ Utilisation commerciale et privée
- ✔️ Modification du code source
- ✔️ Distribution du code
- ✔️ Concession de brevets

### Conditions

- Conserver la notice de droits d'auteur
- Documenter les modifications significatives
- Inclure une copie de la licence Apache 2.0

Pour plus de détails sur la licence : http://www.apache.org/licenses/LICENSE-2.0

**Copyright (c) Calasans - Tous droits réservés**