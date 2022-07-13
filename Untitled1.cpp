#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <iostream>

using namespace std;

CONSOLE_SCREEN_BUFFER_INFO csbuf;
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

void clear_input()
{
int a;
while ((a = getchar()) != '\n' && a != EOF);
}

int result[5] = {0, 0, 0, 0, 0};

void bull();
void bulls_and_cows();
void Victory();
void Defeat();
void account();
void game(int);
void draw_first_menu(char* [], int, int);
void draw_second_menu(char* [], int, int);
void rules();

int main(){

time_t t;
srand((unsigned) time(&t));

SetConsoleTitle("Bulls and cows");

SetConsoleTextAttribute(handle, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_BLUE);
account();
return 0;
}

void account(){

int variant = 0;
int q = 0, a = 0, indi;
char r;

string nick, sign_in, del;
string password;
int n;

string Array_nick[5];
string Array_pass[5];

char *acc[4] = {"Sign up", "Sign in", "Delete account (forever)", "Exit (Do not try Esc)"};
GetConsoleScreenBufferInfo(handle, &csbuf);

while (1){

cout << endl << endl;

system("cls");
draw_first_menu(acc, 4, q);

variant = getch();
switch (variant)
{
case 80:
{
q++;
if (q > 3)q = 0;
break;
}

case 72:
{
q--;
if (q < 0)q = 3;
break;
}

case 13:
{
switch (q)
{
case 0:{

system("cls");
bull();

if (Array_nick[0].size() == 0 | Array_nick[1].size() == 0 | Array_nick[2].size()

== 0 |

Array_nick[3].size() == 0 | Array_nick[4].size() == 0){

for (int i = 0; i < 5; i++){

if(Array_nick[i].size() == 0){
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
for (int k = 0; k < (csbuf.srWindow.Right - 20)/2; k++) cout

<< " ";

cout << "Enter your nickname"<<endl;
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";

cin >> Array_nick[i];

for (int k = 0; k < 5; k++){//проверка уникальности ников

if (i != k){

while (Array_nick[i] == Array_nick[k]){

cout << "This name is taken : ( "<<endl;
cin >> Array_nick[i];
}
}


}

for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
for (int k = 0; k < (csbuf.srWindow.Right - 40)/2; k++) cout

<< " ";
cout << "Enter your password(do not enter only @)"<<endl;
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
cin >> Array_pass[i];

if (Array_pass[i] == "@"){

cout <<"I asked you not to do this :("<<endl;

cout << "Enter your password(do not enter only @)"<<endl;

cin >> Array_pass[i];
}
a = i;

break;

}
}
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
cout << "Remember your data and do not give it to anyone:"<<endl<<endl;

cout << "Your nickname: " << Array_nick[a] << endl;
cout << "Your password: " << Array_pass[a] << endl << endl;
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
}

else{
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-"; 
cout << "Sorry, but maximum can be only 5 accounts :( "<<endl<<endl;

for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
}

system("pause");
break;
}

case 1:{

system("cls");

bull();

if (Array_nick[0].size() == 0 & Array_nick[1].size() == 0 &

Array_nick[2].size() == 0

& Array_nick[3].size() == 0 & Array_nick[4].size() == 0){
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
for (int k = 0; k < (csbuf.srWindow.Right - 25)/2; k++) cout << " ";
cout << "Please create an account!"<<endl<<endl;
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
}
else{ // тут будет весь остальной код

cout << "Please log in or sign up (Enter nick):"<<endl<<endl;

for (int i = 0; i < 5; i++){

if(Array_nick[i].size() != 0){
cout << i+1 <<") "<< Array_nick[i] << endl << endl;

}
}
cout << "nickname -> ";
cin >> sign_in;

if (sign_in == Array_nick[0] ^ sign_in == Array_nick[1] ^ sign_in ==

Array_nick[2] ^ sign_in == Array_nick[3] ^ sign_in == Array_nick[4]){

cout << "Please enter password: ";
cin >> password;
for (int i = 0; i < 5; i++){

if (sign_in == Array_nick[i]){//вхід в акаунт, чий нік співпав із введенним

while (password != Array_pass[i]){

cout << "Please try again :( (Enter @ for exit)"<<endl;

cin >> password;
if (password == "@") break;
}
if (password == Array_pass[i]){
for (int i = 0; i <=

csbuf.srWindow.Right; i++) cout<<"-";

for (int k = 0; k <

(csbuf.srWindow.Right - 47)/2; k++) cout << " ";

cout<< "Success!!!!! Press any key to continue the game"<<endl;

for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";

system("pause");
game(i);
}
}
}
}
else{
clear_input();
cout << "Please enter the nickname correctly : ( "<<endl<<endl;
}
}
system("pause");
break;
}
case 2:{

system("cls");
bull();

if (Array_nick[0].size() == 0 & Array_nick[1].size() == 0 &

Array_nick[2].size() == 0

& Array_nick[3].size() == 0 & Array_nick[4].size() == 0){

for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
for (int k = 0; k < (csbuf.srWindow.Right - 25)/2; k++) cout << " ";
cout << "Please create an account!"<<endl<<endl;
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
}
else{

for (int i = 0; i < 5; i++){

if(Array_nick[i].size() != 0){

cout << i+1 <<") "<< Array_nick[i] << endl << endl;
a = i;

}
}
cout << "Please enter a nick:"<<endl;
cin >> del;

while (!(del == Array_nick[0] ^ del == Array_nick[1] ^ del ==

Array_nick[2] ^ del == Array_nick[3] ^ del == Array_nick[4])){//если не совпало ни одного

clear_input();
cout << "Please enter correctly : ( "<<endl<<endl;
cin >> del;
}
for (int i = 0; i < 5; i++){

if (Array_nick[i] == del) indi = i;
}
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
for (int k = 0; k < (csbuf.srWindow.Right - 60)/2; k++) cout << " ";
cout << "Are you sure you want to delete this item? Yes -> 1; No -> 0" << endl;

for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
int sure;
for (int k = 0; k < (csbuf.srWindow.Right - 1)/2; k++) cout << " ";
cin >> sure;
if (sure == 1){

result[indi] = 0;
Array_nick[indi] = "";
Array_pass[indi] = "";
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
for (int k = 0; k < (csbuf.srWindow.Right - 10)/2; k++) cout

<< " ";

cout << "Well done!"<<endl;

for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
}else {

clear_input();
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
for (int k = 0; k < (csbuf.srWindow.Right - 16)/2; k++) cout

<< " ";

cout <<"Have a nice day!"<<endl;
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
}
}
system("pause");
break;
}

case 3:{

return;

break;
}

}
break;
}
case 27:
{
system("cls");
for (int k = 0; k < (csbuf.srWindow.Right)/2; k++) cout << " ";
cout << "Now I am upset(\n";
system("pause");
break;
}
}
}
}

void game(int n){

int variant = 0;
int q = 0;
int a, b, c, d;

char* var[6] = {"Your number", "Computer's number", "Rating", "Rules for game", "Owner", "Exit (Do not try Esc)"};
GetConsoleScreenBufferInfo(handle, &csbuf);

while (1)
{
cout << endl << endl;

system("cls");
draw_second_menu(var, 6, q);

variant = getch();

switch (variant)
{
case 80:
{
q++;
if (q > 5)q = 0;
break;
}

case 72:
{
q--;
if (q < 0)q = 5;
break;
}

case 13:
{
switch (q)
{
case 0:{
system("cls");
bulls_and_cows();
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";

cout << "Enter your number please (4 digits):" << endl;

cout << "Please do not try to enter non-integer values "<<endl;
cin >> a;
while (1 > a ^ a > 9){
clear_input();
cin >> a;
}

cin >> b;
while (0 > b ^ b > 9 ^ b==a){
// clear_input();
cin >> b;
}

cin >> c;
while (0 > c ^ c > 9 ^ c==b ^ c==a){
// clear_input();
cin >> c;
}

cin >> d;
while (0 > d ^ d > 9 ^ d==a ^ d==b ^ d==c){

// clear_input();

cin >> d;
}
int A[4] = {a, b, c, d};
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
for (int i = 0; i < 4; i++){

cout << A[i];

for (int j = 0; j < (csbuf.srWindow.Right)/4; j++) cout << " ";

}

for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
for (int k = 0; k < (csbuf.srWindow.Right - 23)/2; k++) cout << " ";
cout << "Press any key to play :)" <<endl;
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";

system("pause");
int e, f, g, h;
int bo = 0;

for (int k = 0; k < 200; k++){

e = 1 + rand()%9;

do
f = rand()%10;
while (f == e);

do
g = rand()%10;
while (g == e ^ g == f);

do
h = rand()%10;
while (h == e ^ h == f ^ h == g);

int B[4] = {e, f, g, h};

cout << "|"<< B[0] << "|";
for (int j = 0; j < (csbuf.srWindow.Right)/4; j++) cout << " ";

cout << "|"<< B[1] << "|";
for (int j = 0; j < (csbuf.srWindow.Right)/4; j++) cout << " ";

cout << "|"<< B[2] << "|";
for (int j = 0; j < (csbuf.srWindow.Right)/4; j++) cout << " ";

cout << "|"<< B[3] << "|";
for (int j = 0; j < (csbuf.srWindow.Right)/4; j++) cout << " ";

if (a==B[0] & b==B[1] & c==B[2]){
bo++;
}
}

if (bo == 0){

cout <<endl<<endl;
Victory();
result[n]++;
bo = 0;
system("pause");
}

else{
cout <<endl;
Defeat();
result[n]--;
bo = 0;
if (result[n] < 0) result[n] = 0;
system("pause");
}
break;
}

case 1:{

system ("cls");
bulls_and_cows();
a = 1 + rand()%9;

do
b = rand()%10;
while (b == a);

do
c = rand()%10;
while (c == a ^ c == b);

do
d = rand()%10;
while (d == a ^ d == b ^ d == c);
// cout<<a<<b<<c<<d;
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
// for (int k = 0; k < (csbuf.srWindow.Right)/8; k++) cout << " ";

for (int j = 0; j < 4; j++){
cout << "*";
for (int i = 0; i < (csbuf.srWindow.Right)/4; i++) cout << " ";
}
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
// for (int k = 0; k < (csbuf.srWindow.Right)/2.5; k++) cout << " ";
// cout << "please enter 4 digits:"<<endl<<endl;
int flg = 10;
int j, k, l, m;
int truemesto[4];
int sovpadenie = 0;

while (flg > 0){
sovpadenie = 0;
for (int k = 0; k < (csbuf.srWindow.Right - 26)/2; k++) cout << " ";
cout << "The number of attempts -> " << flg<<endl;

cout <<endl<< "Please, enter the first digit:"<<endl;
cin >> j;
while (1 > j ^ j > 9){

cout << "Please, enter correct digit ->"<<endl;
cin >> j;
}
if(j==a ^ j==b ^ j==c ^ j==d) sovpadenie++;
if(j==a) truemesto[0] = j;

for (int k = 0; k < (csbuf.srWindow.Right)/8; k++) cout << " ";
printf("\nPlease, enter the second digit:\n");
cin >> k;
while (0 > k ^ k > 9 ^ k==j){
printf("Please, enter correct digit -> ");
cin >> k;
}

if(k==a ^ k==b ^ k==c ^ k==d) sovpadenie++;


if(k==b) truemesto[1] = k;

for (int k = 0; k < (csbuf.srWindow.Right)/8; k++) cout << " ";
printf("\nPlease, enter the third digit:\n");
cin >> l;
while (0 > l ^ l > 9 ^ l==j ^ l==k){
printf("Please, enter norm digit -> ");
cin >> l;
}

if(l==a ^ l==b ^ l==c ^ l==d) sovpadenie++;
if(l==c) truemesto[2] = l;
for (int k = 0; k < (csbuf.srWindow.Right)/8; k++) cout << " ";
printf("\nPlease, enter the fourth digit:\n");
cin >> m;
while (0 > m ^ m > 9 ^ m==j ^ m==k ^ m==l){
printf("Please, enter correct digit -> ");
cin >> m;
}

if(m==a ^ m==b ^ m==c ^ m==d) sovpadenie++;
if(m==d) truemesto[3] = m; cout<<endl<<endl;

for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
// for (int k = 0; k < (csbuf.srWindow.Right)/8; k++) cout <<

" ";

// cout << truemesto[j];
if (a==truemesto[0]) cout << a; else cout<< "*"; for (int i =

0; i < (csbuf.srWindow.Right)/4; i++) cout << " ";

if (b==truemesto[1]) cout << b; else cout<< "*"; for (int i

= 0; i < (csbuf.srWindow.Right)/4; i++) cout << " ";

if (c==truemesto[2]) cout << c; else cout<< "*"; for (int i =

0; i < (csbuf.srWindow.Right)/4; i++) cout << " ";

if (d==truemesto[3]) cout << d; else cout<< "*"; for (int i

= 0; i < (csbuf.srWindow.Right)/4; i++) cout << " ";

for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
for (int k = 0; k < (csbuf.srWindow.Right - 9)/2; k++) cout

<< " ";

cout <<endl<<"Cows -> "<< sovpadenie<<endl<<endl;

if (a==truemesto[0] & b==truemesto[1] & c==truemesto[2] &

d==truemesto[3]){

Victory();
result[n]++;
break;
}else flg--;
}
if (flg == 0){

Defeat();
result[n]--;
if (result[n] < 0) result[n] = 0;
}
system("pause");
break;
}

case 2:{
system("cls");
for (int k = 0; k < (csbuf.srWindow.Top)/20; k++) cout << " ";
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
for (int k = 0; k < (csbuf.srWindow.Right - 11)/2; k++) cout << " ";
cout << "Your rating: ";
cout << result[n] << endl;
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
system("pause");

break;
}

case 3:
{
system("cls");
rules();
system("pause");
system("cls");
break;
}

case 4:

{
system("cls");
for (int k = 0; k < (csbuf.srWindow.Top)/20; k++) cout << " ";
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
for (int k = 0; k < (csbuf.srWindow.Right - 25)/2; k++) cout << " ";
cout << "Created by: Artem Titikov"<<endl;
for (int k = 0; k < (csbuf.srWindow.Right - 21)/2; k++) cout << " ";
cout << "Telegram: @temyartemy"<<endl;
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
system("pause");
system("cls");
break;
}
case 5:
{
return;
break;
}
}
break;
}
case 27:
{
system("cls");
cout << "Now I am upset(\n";
system("pause");
break;
}
}
}
}

void rules(){

for (int k = 0; k < (csbuf.srWindow.Top)/20; k++) cout << " ";
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
FILE* fp;
if ((fp = fopen("rules.txt", "r")) == NULL){

cout <<"Please install my game correctly and try again!";
return;
}
int no_problem_to_find_the_file;

while ((no_problem_to_find_the_file = fgetc(fp)) != EOF){
printf("%c", no_problem_to_find_the_file);
}
cout <<endl<<endl;

fclose(fp);
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
return;
}

void bull(){

FILE* fp;
if ((fp = fopen("bull.txt", "r")) == NULL){
cout <<"Please install my game correctly and try again!";
return;
}
int no_problem_to_find_the_file;
while ((no_problem_to_find_the_file = fgetc(fp)) != EOF){

printf("%c", no_problem_to_find_the_file);
}
cout <<endl<<endl;

fclose(fp);

return;
}

void bulls_and_cows(){

FILE* fp;
if ((fp = fopen("bulls_and_cows.txt", "r")) == NULL){

cout <<"Please install my game correctly and try again!";
return;
}
int no_problem_to_find_the_file;

while ((no_problem_to_find_the_file = fgetc(fp)) != EOF){

printf("%c", no_problem_to_find_the_file);
}
cout <<endl<<endl;

fclose(fp);

return;
}

void Victory(){
FILE* fp;
if ((fp = fopen("Victory.txt", "r")) == NULL){

cout <<"Please install my game correctly and try again!";
return;
}
int no_problem_to_find_the_file;

while ((no_problem_to_find_the_file = fgetc(fp)) != EOF){
printf("%c", no_problem_to_find_the_file);
}
cout <<endl<<endl;

fclose(fp);

return;
}

void Defeat(){

FILE* fp;
if ((fp = fopen("Defeat.txt", "r")) == NULL){

cout <<"Please install my game correctly and try again!";
return;
}
int no_problem_to_find_the_file;

while ((no_problem_to_find_the_file = fgetc(fp)) != EOF){

printf("%c", no_problem_to_find_the_file);
}
cout <<endl<<endl;

fclose(fp);

return;
}

void draw_first_menu(char* points[], int size, int vudileno){

bull();
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
int a[size];

for (int i = 0; i < size; i++){

a[i] = (csbuf.srWindow.Right - strlen(points[i]))/2;
}
for (int i = 0; i < size; i++){

for (int j = 0; j < a[i]; j++) cout << " ";

if (i == vudileno){

SetConsoleTextAttribute(handle, BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_RED
| FOREGROUND_GREEN);

cout << points[i] << endl << endl;
SetConsoleTextAttribute(handle, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN |
FOREGROUND_BLUE);
}
else
cout << points[i] << endl << endl;
}
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
}

void draw_second_menu(char* points[], int size, int vudileno){

bulls_and_cows();
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
int a[size];

for (int i = 0; i < size; i++){

a[i] = (csbuf.srWindow.Right) / 8;
}
for (int i = 0; i < size; i++){

for (int j = 0; j < a[i]; j++) cout << " ";

if (i == vudileno){

SetConsoleTextAttribute(handle, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE |
FOREGROUND_RED | FOREGROUND_GREEN);
cout << points[i] << endl << endl;
SetConsoleTextAttribute(handle, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN |
FOREGROUND_BLUE);
}
else
cout << points[i] << endl << endl;
}
for (int i = 0; i <= csbuf.srWindow.Right; i++) cout<<"-";
}
