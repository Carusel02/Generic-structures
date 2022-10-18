# TEMA1 IOCLA

## Metoda rezolvare tema:
Ideea principala consta in alocarea dinamica a unei structuri,
citirea unor date si adaugarea acestora in structura data_element.
Fiind dat un vector *arr, toata memoria (nu adresele) de la acea 
structura data_element trebuiesc copiate in vectorul *arr prin
intermediul functiei memcpy si cu ajutorul unor functii. Toata
implementarea are la baza o "joaca" cu dimensiunea unei citiri,
respectiv cu bytes alocati la o citire.

## Observatii:
- Am stocat tot continutul head ului cu `memcpy`. Acesta contine
8 bytes, 1 bytes pentru char type si urmatorii 3 tot pentru el
(padding) si 4 bytes pentru len.
- De asemenea, am folosit cast urile necesare pentru a putea citi
si scrie date in vectorul generic.

## Functii:
* 1. `main` : pe langa lucrurile principale declarate in main, am
folosit un while (cu scop de loop infinit) pana cand citim de la
tastatura comanda exit. Cu strcmp vedem ce comanda trebuie sa executam,
apoi in functie de cerinta intram intr un if personalizat.
* 2. `write_data` : dupa ce am alocat dinamic o structura in main, am
transmis o ca parametru pentru a putea face citirea si stocarea datelor
in structura respectiva, dupa cele 3 tipuri de inserare a datelor de
citire prezentate in cerinta. De mentionat este faptul ca trebuie 
transmis si vectorul **arr deoarece am apelat inautrul acestei functii
add_last (la final am fost atent sa dau free la tot ce a fost alocat)
(a trebuit sa folosesc memcpy pentru a stoca datele in pointerul generic
void)
* 3. `add_last` : cu functia add_last am copiat folosit memcpy din structura
data_element recent completata in vectorul *arr. A trebuit sa salvez
valoarea initiala a adresei pointerului pentru a nu o pierde. Am copiat
head ul dupa am sarit cu 8 bytes dupa am copiat tot campul void data cu
dimensiunea extrasa din head. ( dupa am marit dimensiunea vectorului arr)
(la inceput vectorul *arr trebuie alocat dinamic de fiecare data fix cu
dimensiunea care trebuie adaugata )
* 4. `write_element` : asemanatoare cu write_data, am folosit o pentru a putea
citi si insera un element la un index. Are acelasi principiu ca si write_data,
doar ca apeleaza alta functie. ( add_at )
* 5. `add_at` : ideea la aceasta functie este ca intai sa realocam vectorul
nostru pentru a i putea face spatiu noului element,apoi sa parcurgem vectorul 
pana la index. Dupa copiem bytes de la adresa indexului + dimensiunea
elementului inserat de la adresa indexului cu memcpy, apoi copiem de la 
adresa indexului pana la adresa indexului + dimensiunea elementului elementul.
dupa facem adresa vectorului *arr cea initiala pentru a printa iar daca dorim
vectorul *arr
* 6. `delete_at` : parcurgem vectorul pana la index, de data asta copiem bytes de la
adresa *arr + dimensiune element sters la adresa *arr si apoi realocam vectorul 
cu len - dimensiunea elementului
* 7. `find` : functia find are ca principiu parcurgerea vectorului pana la index. Ca
sa facem asta, intr un while citim lungimea unui element mutandu ne cu 4 bytes (dupa
tipul char ( 1 byte ) + 3 bytes padding ) si dupa * arr va fi incrementat cu 8 (size ul
unui head) + lungimea elementului iar apoi un contor creste. Facem tot asa pana cand
contorul va fi egal cu indexul. Apoi afisam elementul
* 8. `print` : acelasi mod de lucru ca find doar ca parcurgem pana ajungem la lungimea len.
( tot vectorul ). Pentru a citi datele, aflam intai ce tip este si dupa ne mutam cu x nr
de bytes in functie de felul in care se situeaza ( exemplu daca bancnotele sunt de tip int8_t
inseamna ca au 1 byte. prima parte din *arr este headul ( in primii 4 bytes este tipul si in urmatorii
este len ul , sarim cu 8 bytes ajungem la data unde se afla primul sir, sarim cu lungimea lui si
ajungem la prima bancnota , sarim cu un byte ajungem la 2 a, sarim cu alt byte ajungem la ultimul sir)
De mentionat e la citire si scriere ca trebuie obligatoriu sa facem cast pentru a ne putea da seama
exact ce fel (tip) de date citim. ( de asemenea mai am prin cod expresia (char *)arr + x , asta inseamna
ca ma mut cu x bytes implicit pentru ca *arr este acum de tip pointer char si, conform aritmeticii pointerilor,
acestia sar cu lungimea lor, daca aveam (int *)arr + x saream cu 4 * x deoarece pointerul int sare cu 4
bytes).
* 9. `exit` : cand citim exit iesim, facand o variabila care ne ajuta sa trecem la urmatoarea iteratie in while
sa nu mai respecte conditia din while ( e pe post de flag )

