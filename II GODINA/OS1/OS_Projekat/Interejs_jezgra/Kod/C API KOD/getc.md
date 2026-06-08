#Kod 
0x41

#Potpis 
```c
const int EOF = -1;
char getc ();
```

#Objasnjenje 
Učitava jedan znak iz bafera znakova učitanih sa konzole. U slučaju da je bafer prazan, suspenduje pozivajuću nit dok se znak ne pojavi. Vraća učitani znak u slučaju uspeha, a konstantu EOF u slučaju greške.