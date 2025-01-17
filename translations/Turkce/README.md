# Gettime-Functions

Gettime-Functions, SA-MP'nin yerel `gettime()` ve `getdate()` fonksiyonlarını daha çok yönlü tek bir fonksiyon olan `Gettime_Function` içinde birleştiren bir include'dur. Bu fonksiyon, tarih ve saat için çeşitli çıktı formatları ve 10 farklı dil desteği sunar.

## Diller

- Português: [README](../../)
- Deutsch: [README](../Deutsch/README.md)
- English: [README](../English/README.md)
- Español: [README](../Espanol/README.md)
- Français: [README](../Francais/README.md)
- Italiano: [README](../Italiano/README.md)
- Polski: [README](../Polski/README.md)
- Русский: [README](../Русский/README.md)
- Svenska: [README](../Svenska/README.md)

## İçindekiler

- [Gettime-Functions](#gettime-functions)
  - [Diller](#diller)
  - [İçindekiler](#i̇çindekiler)
  - [Kurulum](#kurulum)
  - [Nasıl Kullanılır](#nasıl-kullanılır)
    - [Parametreler](#parametreler)
    - [Temel Kullanım Örnekleri](#temel-kullanım-örnekleri)
    - [Gelişmiş Örnekler](#gelişmiş-örnekler)
  - [Desteklenen Diller](#desteklenen-diller)
  - [Kullanılabilir Format Türleri](#kullanılabilir-format-türleri)
  - [Özel Özellikler](#özel-özellikler)
    - [Dile Göre Tarih Formatları](#dile-göre-tarih-formatları)
    - [Mevsim Sistemi](#mevsim-sistemi)
  - [Lisans](#lisans)
    - [Koşullar:](#koşullar)

## Kurulum

1. [Gettime-Functions.inc](https://github.com/ocalasans/Anti-Ping/raw/refs/heads/main/src/Gettime-Functions.inc) dosyasını indirin
2. Dosyayı sunucunuzun `pawno/include` klasörüne yerleştirin
3. Scripte include dosyasını ekleyin:
```pawn
#include <Gettime-Functions>
```

> [!NOTE]
> Include otomatik olarak `a_samp` kütüphanesinin mevcut olup olmadığını kontrol eder. Mevcut değilse, derleme sırasında bir hata gösterilecektir.

## Nasıl Kullanılır

Ana fonksiyon `Gettime_Function(tip, dil)` iki parametre kabul eder:

```pawn
Gettime_Function(GFI_type = DATE_AND_TIME, GFI_lang = LANG_PORTUGUES)
```

### Parametreler

- `GFI_type`: İstenen çıktı formatı (isteğe bağlı, varsayılan: DATE_AND_TIME)
- `GFI_lang`: İstenen dil (isteğe bağlı, varsayılan: LANG_PORTUGUES)

> [!TIP]
> Varsayılan değerleri kullanmak için her iki parametreyi de atlayabilirsiniz. Fonksiyon, tam tarih ve saati Portekizce formatında döndürecektir.

### Temel Kullanım Örnekleri

```pawn
main() {
    // Varsayılan tarih ve saat
    printf("Mevcut tarih ve saat: %s", Gettime_Function(.GFI_lang = LANG_TURKCE));
    // Çıktı: Mevcut tarih ve saat: 17.01.2025 - 15:30:45

    // Sadece tarih
    printf("Mevcut tarih: %s", Gettime_Function(ONLY_THE_DATE, LANG_TURKCE));
    // Çıktı: Mevcut tarih: 17.01.2025

    // Sadece saat
    printf("Mevcut saat: %s", Gettime_Function(JUST_THE_TIME, LANG_TURKCE));
    // Çıktı: Mevcut saat: 15:30:45

    return true;
}
```

### Gelişmiş Örnekler

```pawn
public OnPlayerConnect(playerid) {
    // Haftanın günü ve ay adıyla örnek
    new welcome[128];
    format(welcome, sizeof(welcome), "Hoş geldiniz! Bugün %s", Gettime_Function(DATE_WEEKDAY, LANG_TURKCE));
    SendClientMessage(playerid, -1, welcome); // Çıktı: Hoş geldiniz! Bugün Cuma, 17.01.2025

    // Çoklu format örneği
    new gettime_info[300];
    format(gettime_info, sizeof(gettime_info), "Gettime Bilgisi:\nTarih: %s\nSaat: %s\nMevsim: %s",
        Gettime_Function(DATE_MONTH_TEXT, LANG_TURKCE),
        Gettime_Function(TIME_AMPM, LANG_TURKCE),
        Gettime_Function(JUST_THE_SEASON, LANG_TURKCE));
    
    ShowPlayerDialog(playerid, 1, DIALOG_STYLE_MSGBOX, "Gettime Bilgisi", gettime_info, "Tamam", "");
    // Çıktı: Gettime Bilgisi:
    // Tarih: 17 Ocak 2025
    // Saat: 03:30 PM
    // Mevsim: Kış

    return true;
}
```

## Desteklenen Diller

| Sabit | Dil | Tarih Formatı | Tarih Ayırıcı |
|-----------|--------|-----------------|-------------------|
| LANG_DEUTSCH | Almanca | GG.AA.YYYY | . |
| LANG_ENGLISH | İngilizce | AA/GG/YYYY | / |
| LANG_ESPANOL | İspanyolca | GG/AA/YYYY | / |
| LANG_FRANCAIS | Fransızca | GG/AA/YYYY | / |
| LANG_ITALIANO | İtalyanca | GG/AA/YYYY | / |
| LANG_POLSKI | Lehçe | GG.AA.YYYY | . |
| LANG_PORTUGUES | Portekizce | GG/AA/YYYY | / |
| LANG_RUSSIAN | Rusça | GG.AA.YYYY | . |
| LANG_SVENSKA | İsveççe | YYYY-AA-GG | - |
| LANG_TURKCE | Türkçe | GG.AA.YYYY | . |

> [!NOTE]
> Her dil, aylar, haftanın günleri ve mevsimler için kendi çevirilerine ve belirli tarih formatlarına sahiptir.

## Kullanılabilir Format Türleri

| Sabit | Açıklama | Örnek (TR) |
|-----------|-----------|-----------------|
| DATE_AND_TIME | Tam tarih ve saat | 17.01.2025 - 15:30:45 |
| ONLY_THE_DATE | Sadece tarih | 17.01.2025 |
| JUST_THE_TIME | Sadece saat | 15:30:45 |
| DATE_WHITOUT_SECONDS | Saniyesiz tarih ve saat | 17.01.2025 - 15:30 |
| DATE_WHITOUT_YEAR | Yılsız tarih | 17.01 |
| TIME_WITHOUT_SECONDS | Saniyesiz saat | 15:30 |
| JUST_THE_YEAR | Sadece yıl | 2025 |
| JUST_THE_MONTH | Sadece ay | 01 |
| JUST_THE_DAY | Sadece gün | 17 |
| JUST_THE_HOUR | Sadece saat | 15 |
| JUST_THE_MINUTE | Sadece dakika | 30 |
| JUST_THE_SECOND | Sadece saniye | 45 |
| DATE_TIME_FULL | Çizgisiz tam tarih ve saat | 17.01.2025 15:30:45 |
| DATE_TIME_COMPACT | Kısa yıl ve saniyesiz saat | 17.01.25 15:30 |
| DATE_MONTH_TEXT | Ay adıyla tarih | 17 Ocak 2025 |
| TIME_AMPM | AM/PM formatında saat | 03:30 PM |
| DATE_WEEKDAY | Haftanın günüyle tarih | Cuma, 17.01.2025 |
| DATE_TIME_SEASON | Tarih, saat ve mevsim | Kış - 17.01.2025 15:30 |
| JUST_THE_SEASON | Sadece mevsim | Kış |
| DATE_SEASON | Mevsimle tarih | 17.01.2025 - Kış |
| TIME_SEASON | Mevsimle saat | 15:30:45 - Kış |
| MONTH_YEAR | Ay ve yıl | Ocak 2025 |
| DAY_MONTH | Gün ve ay | 17 Ocak |
| WEEKDAY_ONLY | Sadece haftanın günü | Cuma |
| WEEKDAY_TIME | Haftanın günü ve saat | Cuma, 15:30:45 |

## Özel Özellikler

### Dile Göre Tarih Formatları

> [!IMPORTANT]
> Include otomatik olarak tarihi ülkenin standardına göre ayarlar:
- GG/AA/YYYY formatı: Portekizce, İspanyolca, Fransızca, İtalyanca, vb.
- AA/GG/YYYY formatı: İngilizce
- YYYY-AA-GG formatı: İsveççe

### Mevsim Sistemi
Include, tarihe göre mevsimi belirleyen akıllı bir sisteme sahiptir:

```pawn
// Yaz: 21/12 - 20/03
// Sonbahar: 21/03 - 20/06
// Kış: 21/06 - 22/09
// İlkbahar: 23/09 - 20/12

// Mevsim sistemi kullanım örneği
public OnGameModeInit() {
    // Mevcut mevsimi kontrol etme
    printf("Mevcut mevsim: %s", Gettime_Function(JUST_THE_SEASON, LANG_TURKCE));

    // Hava durumu sisteminde kullanma
    new weather;
    switch(Get_Season(GFI_months, GFI_days)) {
        case 0: weather = 10; // Yaz: Güneşli
        case 1: weather = 8;  // Sonbahar: Bulutlu
        case 2: weather = 12; // Kış: Fırtınalı
        case 3: weather = 2;  // İlkbahar: Çok güneşli
    }
    SetWeather(weather);
    
    return true;
}
```

> [!TIP]
> Mevsim sistemi, sunucunuzda mevsimsel etkinlikler oluşturmak, hava durumunu otomatik olarak özelleştirmek veya mevcut mevsime göre tematik dekorasyonlar oluşturmak için kullanılabilir.

## Lisans

Bu Include, Apache License 2.0 lisansı altında korunmaktadır ve şunlara izin verir:

- ✔️ Ticari ve özel kullanım
- ✔️ Kaynak kodunda değişiklik
- ✔️ Kod dağıtımı
- ✔️ Patent hakları

### Koşullar:

- Telif hakkı bildirimini korumak
- Önemli değişiklikleri belgelemek
- Apache License 2.0 lisansının bir kopyasını eklemek

Lisans hakkında daha fazla bilgi için: http://www.apache.org/licenses/LICENSE-2.0

**Telif Hakkı (c) Calasans - Tüm hakları saklıdır**