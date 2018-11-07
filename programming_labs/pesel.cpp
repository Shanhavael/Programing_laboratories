#include <stdio.h>
#include <stdlib.h>

short PESEL[11];
int valid = 0;

int getBirthYear() {
int year;
int month;
year = 10 * PESEL[0];
year += PESEL[1];
month = 10 * PESEL[2];
month += PESEL[3];
if (month > 80 && month < 93) {
year += 1800;
}
else if (month > 0 && month < 13) {
year += 1900;
}
else if (month > 20 && month < 33) {
year += 2000;
}
else if (month > 40 && month < 53) {
year += 2100;
}
else if (month > 60 && month < 73) {
year += 2200;
}
return year;
}

int getBirthMonth() {
int month;
month = 10 * PESEL[2];
month += PESEL[3];
if (month > 80 && month < 93) {
month -= 80;
}
else if (month > 20 && month < 33) {
month -= 20;
}
else if (month > 40 && month < 53) {
month -= 40;
}
else if (month > 60 && month < 73) {
month -= 60;
}
return month;
}

int getBirthDay() {
int day;
day = 10 * PESEL[4];
day += PESEL[5];
return day;
}

char* getSex() {
if (valid) {
if (PESEL[9] % 2 == 1) {
return "Mezczyzna";
}
else {
return "Kobieta";
}
}
else {
return "---";
}
}

int checkSum() {
int sum = 1 * PESEL[0] +
3 * PESEL[1] +
7 * PESEL[2] +
9 * PESEL[3] +
1 * PESEL[4] +
3 * PESEL[5] +
7 * PESEL[6] +
9 * PESEL[7] +
1 * PESEL[8] +
3 * PESEL[9];
sum %= 10;
sum = 10 - sum;
sum %= 10;

if (sum == PESEL[10]) {
return 1;
}
else {
return 0;
}
}

int checkMonth() {
int month = getBirthMonth();
if (month > 0 && month < 13) {
return 1;
}
else {
return 0;
}
}

int checkDay() {
int year = getBirthYear();
int month = getBirthMonth();
int day = getBirthDay();
if ((day >0 && day < 32) &&
(month == 1 || month == 3 || month == 5 ||
month == 7 || month == 8 || month == 10 ||
month == 12)) {
return 1;
}
else if ((day >0 && day < 31) &&
(month == 4 || month == 6 || month == 9 ||
month == 11)) {
return 1;
}
else if ((day >0 && day < 30 && leapYear(year)) ||
(day >0 && day < 29 && !leapYear(year))) {
return 1;
}
else {
return 0;
}
}

int leapYear(int year) {
if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
return 1;
else
return 0;
}

void PeselValidator(char *PESELNumber) {
int i;

if (strlen(PESELNumber) != 11){
valid = 0;
}
else {
for (i = 0; i < 11; i++){
PESEL[i] = PESELNumber[i] - 48;
}
if (checkSum() && checkMonth() && checkDay()) {
valid = 1;
}
else {
valid = 0;
}
}
}

void main(void)
{
char PESEL[200];

printf("Podaj numer PESEL\n");
scanf("%s", PESEL);

PeselValidator(PESEL);

if (valid == 1) {
printf("Numer PESEL jest prawidlowy\n");
printf("Rok urodzenia: %d\n", getBirthYear());
printf("Miesiac urodzenia: %d\n", getBirthMonth());
printf("Dzien urodzenia: %d\n", getBirthDay());
printf("Plec: %s\n", getSex());
}
else {
printf("Numer PESEL jest nieprawidlowy\n");
}
return;
}

