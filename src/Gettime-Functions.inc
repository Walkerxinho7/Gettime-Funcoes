/*
 * Gettime-Functions - include for SA-MP (San Andreas Multiplayer)
 * Copyright (c) Calasans
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#if defined _gettime_functions
    #undef _gettime_functions
#endif

#if defined _gettime_functions_included
    #endinput
#endif
#define _gettime_functions_included

#if !defined _samp_included
    #error "The `a_samp` library has not been activated. Please activate it at the beginning of your Gamemode, Ex: `#include <a_samp>`"
#endif

/*
$$$$$$$\             $$$$$$\  $$\           $$\   $$\     $$\                               
$$  __$$\           $$  __$$\ \__|          \__|  $$ |    \__|                              
$$ |  $$ | $$$$$$\  $$ /  \__|$$\ $$$$$$$\  $$\ $$$$$$\   $$\  $$$$$$\  $$$$$$$\   $$$$$$$\ 
$$ |  $$ |$$  __$$\ $$$$\     $$ |$$  __$$\ $$ |\_$$  _|  $$ |$$  __$$\ $$  __$$\ $$  _____|
$$ |  $$ |$$$$$$$$ |$$  _|    $$ |$$ |  $$ |$$ |  $$ |    $$ |$$ /  $$ |$$ |  $$ |\$$$$$$\  
$$ |  $$ |$$   ____|$$ |      $$ |$$ |  $$ |$$ |  $$ |$$\ $$ |$$ |  $$ |$$ |  $$ | \____$$\ 
$$$$$$$  |\$$$$$$$\ $$ |      $$ |$$ |  $$ |$$ |  \$$$$  |$$ |\$$$$$$  |$$ |  $$ |$$$$$$$  |
\_______/  \_______|\__|      \__|\__|  \__|\__|   \____/ \__| \______/ \__|  \__|\_______/ 
*/

#define DATE_AND_TIME 0
#define ONLY_THE_DATE 1
#define JUST_THE_TIME 2
#define DATE_WHITOUT_SECONDS 3
#define DATE_WHITOUT_YEAR 4
#define TIME_WITHOUT_SECONDS 5
#define JUST_THE_YEAR 6
#define JUST_THE_MONTH 7
#define JUST_THE_DAY 8
#define JUST_THE_HOUR 9
#define JUST_THE_MINUTE 10
#define JUST_THE_SECOND 11
#define DATE_TIME_FULL 12
#define DATE_TIME_COMPACT 13
#define DATE_MONTH_TEXT 14
#define TIME_AMPM 15
#define DATE_WEEKDAY 16
#define DATE_TIME_SEASON 17
#define JUST_THE_SEASON 18
#define DATE_SEASON 19
#define TIME_SEASON 20
#define MONTH_YEAR 21
#define DAY_MONTH 22
#define WEEKDAY_ONLY 23
#define WEEKDAY_TIME 24

#define LANG_PORTUGUES 0
#define LANG_DEUTSCH 1
#define LANG_ENGLISH 2
#define LANG_ESPANOL 3
#define LANG_FRANCAIS 4
#define LANG_ITALIANO 5
#define LANG_POLSKI 6
#define LANG_RUSSIAN 7
#define LANG_SVENSKA 8
#define LANG_TURKCE 9

/*
$$\    $$\                    $$\           $$\       $$\                     
$$ |   $$ |                   \__|          $$ |      $$ |                    
$$ |   $$ |$$$$$$\   $$$$$$\  $$\  $$$$$$\  $$$$$$$\  $$ | $$$$$$\   $$$$$$$\ 
\$$\  $$  |\____$$\ $$  __$$\ $$ | \____$$\ $$  __$$\ $$ |$$  __$$\ $$  _____|
 \$$\$$  / $$$$$$$ |$$ |  \__|$$ | $$$$$$$ |$$ |  $$ |$$ |$$$$$$$$ |\$$$$$$\  
  \$$$  / $$  __$$ |$$ |      $$ |$$  __$$ |$$ |  $$ |$$ |$$   ____| \____$$\ 
   \$  /  \$$$$$$$ |$$ |      $$ |\$$$$$$$ |$$$$$$$  |$$ |\$$$$$$$\ $$$$$$$  |
    \_/    \_______|\__|      \__| \_______|\_______/ \__| \_______|\_______/ 
*/

static const GFI_MONTHS[10][12][] = {
    // Português
    {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"},
    // Deutsch
    {"Januar", "Februar", "März", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember"},
    // English
    {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"},
    // Español
    {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"},
    // Français
    {"Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"},
    // Italiano
    {"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"},
    // Polski
    {"Styczeń", "Luty", "Marzec", "Kwiecień", "Maj", "Czerwiec", "Lipiec", "Sierpień", "Wrzesień", "Październik", "Listopad", "Grudzień"},
    // Русский
    {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"},
    // Svenska
    {"Januari", "Februari", "Mars", "April", "Maj", "Juni", "Juli", "Augusti", "September", "Oktober", "November", "December"},
    // Türkçe
    {"Ocak", "Şubat", "Mart", "Nisan", "Mayıs", "Haziran", "Temmuz", "Ağustos", "Eylül", "Ekim", "Kasım", "Aralık"}
};

static const GFI_WEEKDAYS[10][7][] = {
    // Português
    {"Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sábado"},
    // Deutsch
    {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"},
    // English
    {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"},
    // Español
    {"Domingo", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado"},
    // Français
    {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"},
    // Italiano
    {"Domenica", "Lunedì", "Martedì", "Mercoledì", "Giovedì", "Venerdì", "Sabato"},
    // Polski
    {"Niedziela", "Poniedziałek", "Wtorek", "Środa", "Czwartek", "Piątek", "Sobota"},
    // Русский
    {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"},
    // Svenska
    {"Söndag", "Måndag", "Tisdag", "Onsdag", "Torsdag", "Fredag", "Lördag"},
    // Türkçe
    {"Pazar", "Pazartesi", "Salı", "Çarşamba", "Perşembe", "Cuma", "Cumartesi"}
};

static const GFI_SEASONS[10][4][] = {
    // Português
    {"Verão", "Outono", "Inverno", "Primavera"},
    // Deutsch
    {"Sommer", "Herbst", "Winter", "Frühling"},
    // English
    {"Summer", "Autumn", "Winter", "Spring"},
    // Español
    {"Verano", "Otoño", "Invierno", "Primavera"},
    // Français
    {"Été", "Automne", "Hiver", "Printemps"},
    // Italiano
    {"Estate", "Autunno", "Inverno", "Primavera"},
    // Polski
    {"Lato", "Jesień", "Zima", "Wiosna"},
    // Русский
    {"Лето", "Осень", "Зима", "Весна"},
    // Svenska
    {"Sommar", "Höst", "Vinter", "Vår"},
    // Türkçe
    {"Yaz", "Sonbahar", "Kış", "İlkbahar"}
};

static const GFI_DATE_SEPARATORS[10][] = {
    "/", // Português
    ".", // Deutsch
    "/", // English
    "/", // Español
    "/", // Français
    "/", // Italiano
    ".", // Polski
    ".", // Русский
    "-", // Svenska
    "."  // Türkçe
};

static const GFI_TIME_SEPARATORS[10][] = {
    ":",
    ":",
    ":",
    ":",
    ":",
    ":",
    ":",
    ":",
    ":",
    ":"
};

static const GFI_OF_TEXT[10][] = {
    "de",  // Português
    "von", // Deutsch
    "of",  // English
    "de",  // Español
    "de",  // Français
    "di",  // Italiano
    "",    // Polski (uses case inflection)
    "",    // Русский (uses case inflection)
    "",    // Svenska
    ""     // Türkçe
};

static const GFI_DATE_FORMATS[10] = {
    0, // Português (DD/MM/YYYY)
    0, // Deutsch (DD.MM.YYYY)
    1, // English (MM/DD/YYYY)
    0, // Español (DD/MM/YYYY)
    0, // Français (DD/MM/YYYY)
    0, // Italiano (DD/MM/YYYY)
    0, // Polski (DD.MM.YYYY)
    0, // Русский (DD.MM.YYYY)
    2, // Svenska (YYYY-MM-DD)
    0  // Türkçe (DD.MM.YYYY)
};

static GFI_string_time[256],
    GFI_hours,
    GFI_minutes,
    GFI_seconds,
    GFI_years,
    GFI_months,
    GFI_days,
    GFI_weekday;

/*
$$$$$$$$\                              $$\     $$\                               
$$  _____|                             $$ |    \__|                              
$$ |   $$\   $$\ $$$$$$$\   $$$$$$$\ $$$$$$\   $$\  $$$$$$\  $$$$$$$\   $$$$$$$\ 
$$$$$\ $$ |  $$ |$$  __$$\ $$  _____|\_$$  _|  $$ |$$  __$$\ $$  __$$\ $$  _____|
$$  __|$$ |  $$ |$$ |  $$ |$$ /        $$ |    $$ |$$ /  $$ |$$ |  $$ |\$$$$$$\  
$$ |   $$ |  $$ |$$ |  $$ |$$ |        $$ |$$\ $$ |$$ |  $$ |$$ |  $$ | \____$$\ 
$$ |   \$$$$$$  |$$ |  $$ |\$$$$$$$\   \$$$$  |$$ |\$$$$$$  |$$ |  $$ |$$$$$$$  |
\__|    \______/ \__|  \__| \_______|   \____/ \__| \______/ \__|  \__|\_______/ 
*/

stock GetWeekDay_FromDate(GFI_day, GFI_month, GFI_year) {
    new a = (14 - GFI_month) / 12;
    new y = GFI_year - a;
    new m = GFI_month + 12 * a - 2;
    new weekday = (GFI_day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
    
    return weekday;
}

stock Get_Season(GFI_month, GFI_day) {
    if ((GFI_month == 12 && GFI_day >= 21) || GFI_month <= 2 || (GFI_month == 3 && GFI_day < 21))
        return 0;
    
    if ((GFI_month == 3 && GFI_day >= 21) || GFI_month <= 5 || (GFI_month == 6 && GFI_day < 21))
        return 1;
    
    if ((GFI_month == 6 && GFI_day >= 21) || GFI_month <= 8 || (GFI_month == 9 && GFI_day < 23))
        return 2;
    
    return 3;
}

stock Gettime_Function(GFI_type = DATE_AND_TIME, GFI_lang = LANG_PORTUGUES) {
    getdate(GFI_years, GFI_months, GFI_days);
    gettime(GFI_hours, GFI_minutes, GFI_seconds);
    
    new GFI_date_sep[2];
    strcat(GFI_date_sep, GFI_DATE_SEPARATORS[GFI_lang]);
    
    new GFI_time_sep[2];
    strcat(GFI_time_sep, GFI_TIME_SEPARATORS[GFI_lang]);
    
    switch(GFI_type) {
        case DATE_AND_TIME: {
            switch(GFI_DATE_FORMATS[GFI_lang]) {
                case 0:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d%s%04d - %02d%s%02d%s%02d", GFI_days, GFI_date_sep, GFI_months, GFI_date_sep, GFI_years, GFI_hours, GFI_time_sep, GFI_minutes, GFI_time_sep, GFI_seconds);
                
                case 1:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d%s%04d - %02d%s%02d%s%02d", GFI_months, GFI_date_sep, GFI_days, GFI_date_sep, GFI_years, GFI_hours, GFI_time_sep, GFI_minutes, GFI_time_sep, GFI_seconds);

                case 2:
                    format(GFI_string_time, sizeof(GFI_string_time), "%04d%s%02d%s%02d - %02d%s%02d%s%02d", GFI_years, GFI_date_sep, GFI_months, GFI_date_sep, GFI_days, GFI_hours, GFI_time_sep, GFI_minutes, GFI_time_sep, GFI_seconds);
            }
        }
        
        case ONLY_THE_DATE: {
            switch(GFI_DATE_FORMATS[GFI_lang]) {
                case 0:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d%s%04d", GFI_days, GFI_date_sep, GFI_months, GFI_date_sep, GFI_years);
                
                case 1:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d%s%04d", GFI_months, GFI_date_sep, GFI_days, GFI_date_sep, GFI_years);
                
                case 2:
                    format(GFI_string_time, sizeof(GFI_string_time), "%04d%s%02d%s%02d", GFI_years, GFI_date_sep, GFI_months, GFI_date_sep, GFI_days);
            }
        }
        
        case JUST_THE_TIME:
            format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d%s%02d", GFI_hours, GFI_time_sep, GFI_minutes, GFI_time_sep, GFI_seconds);
        
        case DATE_WHITOUT_SECONDS: {
            switch(GFI_DATE_FORMATS[GFI_lang]) {
                case 0:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d%s%04d - %02d%s%02d", GFI_days, GFI_date_sep, GFI_months, GFI_date_sep, GFI_years, GFI_hours, GFI_time_sep, GFI_minutes);
                
                case 1:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d%s%04d - %02d%s%02d", GFI_months, GFI_date_sep, GFI_days, GFI_date_sep, GFI_years, GFI_hours, GFI_time_sep, GFI_minutes);
                
                case 2:
                    format(GFI_string_time, sizeof(GFI_string_time), "%04d%s%02d%s%02d - %02d%s%02d", GFI_years, GFI_date_sep, GFI_months, GFI_date_sep, GFI_days, GFI_hours, GFI_time_sep, GFI_minutes);
            }
        }
        
        case DATE_WHITOUT_YEAR: {
            switch(GFI_DATE_FORMATS[GFI_lang]) {
                case 0:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d", GFI_days, GFI_date_sep, GFI_months);
                
                case 1:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d", GFI_months, GFI_date_sep, GFI_days);
                
                case 2:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d", GFI_months, GFI_date_sep, GFI_days);
            }
        }
        
        case TIME_WITHOUT_SECONDS:
            format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d", GFI_hours, GFI_time_sep, GFI_minutes);
        
        case JUST_THE_YEAR:
            format(GFI_string_time, sizeof(GFI_string_time), "%04d", GFI_years);
        
        case JUST_THE_MONTH:
            format(GFI_string_time, sizeof(GFI_string_time), "%02d", GFI_months);

        case JUST_THE_DAY:
            format(GFI_string_time, sizeof(GFI_string_time), "%02d", GFI_days);

        case JUST_THE_HOUR:
            format(GFI_string_time, sizeof(GFI_string_time), "%02d", GFI_hours);

        case JUST_THE_MINUTE:
            format(GFI_string_time, sizeof(GFI_string_time), "%02d", GFI_minutes);

        case JUST_THE_SECOND:
            format(GFI_string_time, sizeof(GFI_string_time), "%02d", GFI_seconds);

        case DATE_TIME_FULL: {
            switch(GFI_DATE_FORMATS[GFI_lang]) {
                case 0:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d%s%04d %02d%s%02d%s%02d", GFI_days, GFI_date_sep, GFI_months, GFI_date_sep, GFI_years, GFI_hours, GFI_time_sep, GFI_minutes, GFI_time_sep, GFI_seconds);

                case 1:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d%s%04d %02d%s%02d%s%02d", GFI_months, GFI_date_sep, GFI_days, GFI_date_sep, GFI_years, GFI_hours, GFI_time_sep, GFI_minutes, GFI_time_sep, GFI_seconds);

                case 2:
                    format(GFI_string_time, sizeof(GFI_string_time), "%04d%s%02d%s%02d %02d%s%02d%s%02d", GFI_years, GFI_date_sep, GFI_months, GFI_date_sep, GFI_days, GFI_hours, GFI_time_sep, GFI_minutes, GFI_time_sep, GFI_seconds);
            }
        }

        case DATE_TIME_COMPACT: {
            switch(GFI_DATE_FORMATS[GFI_lang]) {
                case 0:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d%s%02d %02d%s%02d", GFI_days, GFI_date_sep, GFI_months, GFI_date_sep, GFI_years % 100, GFI_hours, GFI_time_sep, GFI_minutes);

                case 1:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d%s%02d %02d%s%02d", GFI_months, GFI_date_sep, GFI_days, GFI_date_sep, GFI_years % 100, GFI_hours, GFI_time_sep, GFI_minutes);

                case 2:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d%s%02d %02d%s%02d", GFI_years % 100, GFI_date_sep, GFI_months, GFI_date_sep, GFI_days, GFI_hours, GFI_time_sep, GFI_minutes);
            }
        }

        case DATE_MONTH_TEXT: {
            if(GFI_lang == LANG_POLSKI || GFI_lang == LANG_RUSSIAN)
                format(GFI_string_time, sizeof(GFI_string_time), "%02d %s %04d", GFI_days, GFI_MONTHS[GFI_lang][GFI_months - 1], GFI_years);
            
            else if(GFI_lang == LANG_ENGLISH)
                format(GFI_string_time, sizeof(GFI_string_time), "%s %02d %s %04d", GFI_MONTHS[GFI_lang][GFI_months - 1], GFI_days, GFI_OF_TEXT[GFI_lang], GFI_years);
            
            else if(strlen(GFI_OF_TEXT[GFI_lang]) > 0)
                format(GFI_string_time, sizeof(GFI_string_time), "%02d %s %s %s %04d", GFI_days, GFI_OF_TEXT[GFI_lang], GFI_MONTHS[GFI_lang][GFI_months - 1], GFI_OF_TEXT[GFI_lang], GFI_years);
            
            else
                format(GFI_string_time, sizeof(GFI_string_time), "%02d %s %04d", GFI_days, GFI_MONTHS[GFI_lang][GFI_months - 1], GFI_years);
        }

        case TIME_AMPM: {
            new ampm[3];
            new hour = GFI_hours;
            
            if (hour >= 12) {
                ampm = "PM";

                if (hour > 12)
                    hour -= 12;
            }
            else {
                ampm = "AM";

                if (hour == 0)
                    hour = 12;
            }
            
            format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d %s", hour, GFI_time_sep, GFI_minutes, ampm);
        }

        case DATE_WEEKDAY: {
            new weekday = GetWeekDay_FromDate(GFI_days, GFI_months, GFI_years);

            switch(GFI_DATE_FORMATS[GFI_lang]) {
                case 0:
                    format(GFI_string_time, sizeof(GFI_string_time), "%s, %02d%s%02d%s%04d", GFI_WEEKDAYS[GFI_lang][weekday], GFI_days, GFI_date_sep, GFI_months, GFI_date_sep, GFI_years);

                case 1:
                    format(GFI_string_time, sizeof(GFI_string_time), "%s, %02d%s%02d%s%04d", GFI_WEEKDAYS[GFI_lang][weekday], GFI_months, GFI_date_sep, GFI_days, GFI_date_sep, GFI_years);

                case 2:
                    format(GFI_string_time, sizeof(GFI_string_time), "%s, %04d%s%02d%s%02d", GFI_WEEKDAYS[GFI_lang][weekday], GFI_years, GFI_date_sep, GFI_months, GFI_date_sep, GFI_days);
            }
        }

        case DATE_TIME_SEASON: {
            new season = Get_Season(GFI_months, GFI_days);

            switch(GFI_DATE_FORMATS[GFI_lang]) {
                case 0:
                    format(GFI_string_time, sizeof(GFI_string_time), "%s - %02d%s%02d%s%04d %02d%s%02d", GFI_SEASONS[GFI_lang][season], GFI_days, GFI_date_sep, GFI_months, GFI_date_sep, GFI_years, GFI_hours, GFI_time_sep, GFI_minutes);

                case 1:
                    format(GFI_string_time, sizeof(GFI_string_time), "%s - %02d%s%02d%s%04d %02d%s%02d", GFI_SEASONS[GFI_lang][season], GFI_months, GFI_date_sep, GFI_days, GFI_date_sep, GFI_years, GFI_hours, GFI_time_sep, GFI_minutes);

                case 2:
                    format(GFI_string_time, sizeof(GFI_string_time), "%s - %04d%s%02d%s%02d %02d%s%02d", GFI_SEASONS[GFI_lang][season], GFI_years, GFI_date_sep, GFI_months, GFI_date_sep, GFI_days, GFI_hours, GFI_time_sep, GFI_minutes);
            }
        }

        case JUST_THE_SEASON: {
            new season = Get_Season(GFI_months, GFI_days);
            format(GFI_string_time, sizeof(GFI_string_time), "%s", GFI_SEASONS[GFI_lang][season]);
        }

        case DATE_SEASON: {
            new season = Get_Season(GFI_months, GFI_days);

            switch(GFI_DATE_FORMATS[GFI_lang]) {
                case 0:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d%s%04d - %s", GFI_days, GFI_date_sep, GFI_months, GFI_date_sep, GFI_years, GFI_SEASONS[GFI_lang][season]);

                case 1:
                    format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d%s%04d - %s", GFI_months, GFI_date_sep, GFI_days, GFI_date_sep, GFI_years, GFI_SEASONS[GFI_lang][season]);

                case 2:
                    format(GFI_string_time, sizeof(GFI_string_time), "%04d%s%02d%s%02d - %s", GFI_years, GFI_date_sep, GFI_months, GFI_date_sep, GFI_days, GFI_SEASONS[GFI_lang][season]);
            }
        }

        case TIME_SEASON: {
            new season = Get_Season(GFI_months, GFI_days);
            format(GFI_string_time, sizeof(GFI_string_time), "%02d%s%02d%s%02d - %s", GFI_hours, GFI_time_sep, GFI_minutes, GFI_time_sep, GFI_seconds, GFI_SEASONS[GFI_lang][season]);
        }
        
        case MONTH_YEAR: {
            if(strlen(GFI_OF_TEXT[GFI_lang]) > 0)
                format(GFI_string_time, sizeof(GFI_string_time), "%s %s %04d", GFI_MONTHS[GFI_lang][GFI_months - 1], GFI_OF_TEXT[GFI_lang], GFI_years);
            
            else
                format(GFI_string_time, sizeof(GFI_string_time), "%s %04d", GFI_MONTHS[GFI_lang][GFI_months - 1], GFI_years);
        }
        
        case DAY_MONTH: {
            if(strlen(GFI_OF_TEXT[GFI_lang]) > 0)
                format(GFI_string_time, sizeof(GFI_string_time), "%02d %s %s", GFI_days, GFI_OF_TEXT[GFI_lang], GFI_MONTHS[GFI_lang][GFI_months - 1]);
            
            else
                format(GFI_string_time, sizeof(GFI_string_time), "%02d %s", GFI_days, GFI_MONTHS[GFI_lang][GFI_months - 1]);
        }
        
        case WEEKDAY_ONLY: {
            new weekday = GetWeekDay_FromDate(GFI_days, GFI_months, GFI_years);
            format(GFI_string_time, sizeof(GFI_string_time), "%s", GFI_WEEKDAYS[GFI_lang][weekday]);
        }
        
        case WEEKDAY_TIME: {
            new weekday = GetWeekDay_FromDate(GFI_days, GFI_months, GFI_years);

            switch(GFI_DATE_FORMATS[GFI_lang]) {
                case 0:
                    format(GFI_string_time, sizeof(GFI_string_time), "%s, %02d%s%02d%s%02d", GFI_WEEKDAYS[GFI_lang][weekday], GFI_hours, GFI_time_sep, GFI_minutes, GFI_time_sep, GFI_seconds);

                case 1:
                    format(GFI_string_time, sizeof(GFI_string_time), "%s, %02d%s%02d%s%02d", GFI_WEEKDAYS[GFI_lang][weekday], GFI_hours, GFI_time_sep, GFI_minutes, GFI_time_sep, GFI_seconds);

                case 2:
                    format(GFI_string_time, sizeof(GFI_string_time), "%s, %02d%s%02d%s%02d", GFI_WEEKDAYS[GFI_lang][weekday], GFI_hours, GFI_time_sep, GFI_minutes, GFI_time_sep, GFI_seconds);
            }
        }
    }

    return GFI_string_time;
}

public OnGameModeInit() { 
    print(" ");
    print("__________________________________________________________________");
    print("||==============================================================||");
    print("||                                                              ||");
    print("||                      Gettime Functions                       ||");
    print("||                                                              ||");
    print("||               ,ad8888ba,             88888888888             ||");
    print("||              d8''    `'8b            88                      ||");
    print("||             d8'                      88                      ||");
    print("||             88                       88aaaaa                 ||");
    print("||             88      88888  aaaaaaaa  88=====                 ||");
    print("||             Y8,        88  ========  88                      ||");
    print("||              Y8a.    .a88            88                      ||");
    print("||               `'Y88888P'             88                      ||");
    print("||                                                              ||");
    print("||                                                              ||");
    print("||                                                              ||");
    print("|| Developer: Calasans                                          ||");
    print("|| Instagram: ocalasans                                         ||");
    print("|| Discord: ocalasans                                           ||");
    print("||                                                              ||");
    print("|| [Info]: Include version: 1.0.2                               ||");
    print("||                                                              ||");
    print("||==============================================================||");
    print("__________________________________________________________________");
    print(" ");
    
    #if defined GFI_print_gamemodeinit
        return GFI_print_gamemodeinit();
    #else
        return true;
    #endif
}

/*
 $$$$$$\  $$\       $$$$$$\  
$$  __$$\ $$ |     $$  __$$\ 
$$ /  $$ |$$ |     $$ /  \__|
$$$$$$$$ |$$ |     \$$$$$$\  
$$  __$$ |$$ |      \____$$\ 
$$ |  $$ |$$ |     $$\   $$ |
$$ |  $$ |$$$$$$$$\\$$$$$$  |
\__|  \__|\________|\______/ 
*/

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit GFI_print_gamemodeinit
#if defined GFI_print_gamemodeinit
    forward GFI_print_gamemodeinit();
#endif
