# Gettime-Functions

O Gettime-Functions é um include que encapsula as funções nativas `gettime()` e `getdate()` do SA-MP em uma única função mais versátil chamada `Gettime_Function`. Esta função oferece diversos formatos de saída para data e hora, além de suporte para 10 idiomas diferentes.

## Idiomas

- Deutsch: [README](translations/Deutsch/README.md)
- English: [README](translations/English/README.md)
- Español: [README](translations/Espanol/README.md)
- Français: [README](translations/Francais/README.md)
- Italiano: [README](translations/Italiano/README.md)
- Polski: [README](translations/Polski/README.md)
- Русский: [README](translations/Русский/README.md)
- Svenska: [README](translations/Svenska/README.md)
- Türkçe: [README](translations/Turkce/README.md)

## Índice

- [Gettime-Functions](#gettime-functions)
  - [Idiomas](#idiomas)
  - [Índice](#índice)
  - [Instalação](#instalação)
  - [Como Usar](#como-usar)
    - [Parâmetros](#parâmetros)
    - [Exemplos de uso básico](#exemplos-de-uso-básico)
    - [Exemplos Avançados](#exemplos-avançados)
  - [Idiomas Suportados](#idiomas-suportados)
  - [Tipos de formato disponíveis](#tipos-de-formato-disponíveis)
  - [Características Especiais](#características-especiais)
    - [Formatos de data por idioma](#formatos-de-data-por-idioma)
    - [Sistema de Estações](#sistema-de-estações)
  - [Licença](#licença)
    - [Condições:](#condições)

## Instalação

1. Baixe o arquivo `Gettime-Functions.inc`
2. Coloque o arquivo na pasta `pawno/include` do seu servidor
3. Inclua o arquivo no seu script:
```pawn
#include <Gettime-Functions>
```

> [!NOTE]
> O include automaticamente verifica se a biblioteca `a_samp` está presente. Caso não esteja, um erro será exibido durante a compilação.

## Como Usar

A função principal é `Gettime_Function(tipo, idioma)` que aceita dois parâmetros:

```pawn
Gettime_Function(GFI_type = DATE_AND_TIME, GFI_lang = LANG_PORTUGUES)
```

### Parâmetros

- `GFI_type`: O formato de saída desejado (opcional, padrão: DATE_AND_TIME)
- `GFI_lang`: O idioma desejado (opcional, padrão: LANG_PORTUGUES)

> [!TIP]
> Você pode omitir ambos os parâmetros para usar os valores padrão. A função retornará a data e hora no formato completo em português.

### Exemplos de uso básico

```pawn
main() {
    // Data e hora padrão
    printf("Data e hora atual: %s", Gettime_Function());
    // Saída: Data e hora atual: 17/01/2025 - 15:30:45

    // Apenas a data
    printf("Data atual: %s", Gettime_Function(ONLY_THE_DATE));
    // Saída: Data atual: 17/01/2025

    // Apenas a hora
    printf("Hora atual: %s", Gettime_Function(JUST_THE_TIME));
    // Saída: Hora atual: 15:30:45

    return true;
}
```

### Exemplos Avançados

```pawn
public OnPlayerConnect(playerid) {
    // Exemplo com dia da semana e mês por extenso
    new welcome[128];
    format(welcome, sizeof(welcome), "Bem-vindo! Hoje é %s", Gettime_Function(DATE_WEEKDAY));
    SendClientMessage(playerid, -1, welcome); // Saída: Bem-vindo! Hoje é Sexta-feira, 17/01/2025

    // Exemplo com múltiplos formatos
    new gettime_info[300];
    format(gettime_info, sizeof(gettime_info), "Gettime Info:\nData: %s\nHora: %s\nEstação: %s",
        Gettime_Function(DATE_MONTH_TEXT),
        Gettime_Function(TIME_AMPM),
        Gettime_Function(JUST_THE_SEASON));
    
    ShowPlayerDialog(playerid, 1, DIALOG_STYLE_MSGBOX, "Gettime Info", gettime_info, "Ok", "");
    // Saída: Gettime Info:
    // Data: 17 de Janeiro de 2025
    // Hora: 03:30 PM
    // Estação: Verão

    return true;
}
```

## Idiomas Suportados

| Constante | Idioma | Formato de Data | Separador de Data |
|-----------|--------|-----------------|-------------------|
| LANG_DEUTSCH | Alemão | DD.MM.YYYY | . |
| LANG_ENGLISH | Inglês | MM/DD/YYYY | / |
| LANG_ESPANOL | Espanhol | DD/MM/YYYY | / |
| LANG_FRANCAIS | Francês | DD/MM/YYYY | / |
| LANG_ITALIANO | Italiano | DD/MM/YYYY | / |
| LANG_POLSKI | Polonês | DD.MM.YYYY | . |
| LANG_PORTUGUES | Português | DD/MM/YYYY | / |
| LANG_RUSSIAN | Russo | DD.MM.YYYY | . |
| LANG_SVENSKA | Sueco | YYYY-MM-DD | - |
| LANG_TURKCE | Turco | DD.MM.YYYY | . |

> [!NOTE]
> Cada idioma possui suas próprias traduções para meses, dias da semana e estações do ano, além de formatos específicos de data.

## Tipos de formato disponíveis

| Constante | Descrição | Exemplo (PT-BR) |
|-----------|-----------|-----------------|
| DATE_AND_TIME | Data e hora completas | 17/01/2025 - 15:30:45 |
| ONLY_THE_DATE | Apenas a data | 17/01/2025 |
| JUST_THE_TIME | Apenas a hora | 15:30:45 |
| DATE_WHITOUT_SECONDS | Data e hora sem segundos | 17/01/2025 - 15:30 |
| DATE_WHITOUT_YEAR | Data sem o ano | 17/01 |
| TIME_WITHOUT_SECONDS | Hora sem segundos | 15:30 |
| JUST_THE_YEAR | Apenas o ano | 2025 |
| JUST_THE_MONTH | Apenas o mês | 01 |
| JUST_THE_DAY | Apenas o dia | 17 |
| JUST_THE_HOUR | Apenas a hora | 15 |
| JUST_THE_MINUTE | Apenas os minutos | 30 |
| JUST_THE_SECOND | Apenas os segundos | 45 |
| DATE_TIME_FULL | Data e hora completas sem traço | 17/01/2025 15:30:45 |
| DATE_TIME_COMPACT | Data com ano curto e hora sem segundos | 17/01/25 15:30 |
| DATE_MONTH_TEXT | Data com mês por extenso | 17 de Janeiro de 2025 |
| TIME_AMPM | Hora no formato AM/PM | 03:30 PM |
| DATE_WEEKDAY | Data com dia da semana | Sexta-feira, 17/01/2025 |
| DATE_TIME_SEASON | Data, hora e estação | Verão - 17/01/2025 15:30 |
| JUST_THE_SEASON | Apenas a estação do ano | Verão |
| DATE_SEASON | Data com estação | 17/01/2025 - Verão |
| TIME_SEASON | Hora com estação | 15:30:45 - Verão |
| MONTH_YEAR | Mês e ano | Janeiro de 2025 |
| DAY_MONTH | Dia e mês | 17 de Janeiro |
| WEEKDAY_ONLY | Apenas o dia da semana | Sexta-feira |
| WEEKDAY_TIME | Dia da semana e hora | Sexta-feira, 15:30:45 |

## Características Especiais

### Formatos de data por idioma

> [!IMPORTANT]
> O include automaticamente ajusta o formato da data de acordo com o padrão do país:
- Formato DD/MM/YYYY: Português, Espanhol, Francês, Italiano, etc.
- Formato MM/DD/YYYY: Inglês
- Formato YYYY-MM-DD: Sueco

### Sistema de Estações
O include possui um sistema inteligente que determina a estação do ano com base na data:

```pawn
// Verão: 21/12 até 20/03
// Outono: 21/03 até 20/06
// Inverno: 21/06 até 22/09
// Primavera: 23/09 até 20/12

// Exemplo de uso do sistema de estações
public OnGameModeInit() {
    // Verificando a estação atual
    printf("Estação atual: %s", Gettime_Function(JUST_THE_SEASON));

    // Usando em um sistema de clima
    new weather;
    switch(Get_Season(GFI_months, GFI_days)) {
        case 0: weather = 10; // Verão: Ensolarado
        case 1: weather = 8;  // Outono: Nublado
        case 2: weather = 12; // Inverno: Tempestuoso
        case 3: weather = 2;  // Primavera: Extrasol
    }
    SetWeather(weather);
    
    return true;
}
```

> [!TIP]
> O sistema de estações pode ser usado para criar eventos sazonais em seu servidor, personalizar o clima automaticamente ou criar decorações temáticas baseadas na estação do ano atual.

## Licença

Este Include está protegido sob a Licença Apache 2.0, que permite:

- ✔️ Uso comercial e privado
- ✔️ Modificação do código fonte
- ✔️ Distribuição do código
- ✔️ Concessão de patentes

### Condições:

- Manter o aviso de direitos autorais
- Documentar alterações significativas
- Incluir cópia da licença Apache 2.0

Para mais detalhes sobre a licença: http://www.apache.org/licenses/LICENSE-2.0

**Copyright (c) Calasans - Todos os direitos reservados**
