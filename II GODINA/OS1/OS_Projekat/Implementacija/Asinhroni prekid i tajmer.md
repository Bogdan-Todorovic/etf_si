Asinhorne promene konteksta dolaze iz dva izvora:
- Konzola
- Tajmer

## Tajmer
Na prekid tajmera treba:
- Azurirati preostalo vreme izvrsavanja tekucoj niti umanjenjem za jednu periodu tajmera
- Ukoliko je vreme isteklo, uraditi promenu konteksta i tekuce niti. 
- Svakoj novoj niti dodeliti vremenski odsecak za izvrsavanje. Vrednost vremena preostalog najlakse je cuvati u statickoj promenljivoj.
- Azurirati evidenciju uspavanih niti i po potrebi probuditi odgovarajuce niti