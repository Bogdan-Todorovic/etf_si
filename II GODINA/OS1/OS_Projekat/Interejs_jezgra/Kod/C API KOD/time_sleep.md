#Kod 
 0x31

#Potpis 
```c
typedef unsigned long time_t;

int time_sleep (time_t);
```

#Objasnjenje 
Uspavljuje pozivajuću nit na zadati period u internim jedinicama vremena (periodama tajmera). U slučaju uspeha vraća 0, a u slučaju neuspeha vraća negativnu vrednost (kôd greške).