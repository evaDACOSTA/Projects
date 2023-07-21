# Les mémoires

## Introduction

- Permet le stockage d'informations (=données) qui possèdent toutes une adresse

##### Structure générale :

C'est une matrice de points mémoire (1 point = 1 info binaire) qui comporte :
- une décodeur de ligne
- une décodeur de colonne
- un circuit de lecture (Read/Write)

##### Capacité d'une mémoire :

C = m x 2<sup>n</sup>
(avec 2<sup>n</sup> : nombre de cases mémoires et m : nombre de bits)

## Les mémoires vives

Ce sont des mémoires qui perdent leur contenu sans alimentation (registres, mémoires caches, mémoires centrales). 

Il en existe deux types :

#### 1. Les SRAM
##### Structure :

- 2 inverseurs (stockage)
- 2 transistors (Read/Write)

##### Propriétés :
- Pas de rafraichissement
- Vitesse élevée (qq ns)
- Moins dense que DRAM
- Capacité faible (qq Mo)
- Consommation proportionnelle à la fréquence
- Prix élevé (5 000€ / Gbit)

#### 2. Les DRAM
##### Structure :
- 1 transistor
- 1 condensateur (Stockage)

##### Propriétés :
- Raffraichissement nécessire
- Vitesse faible (plusieurs dizaine de ns)
- Plus dense que SRAM
- Capacité élevéé (plusieurs Go)
- Elevée à cause du rafraichissemnt
- Prix faible (50€ / Gbit)

## Les mémoires mortes

Ce sont des mémoires qui gardent leur contenu avec ou sans alimentation. Il en existe quartre types :

#### 1. Les ROM
Mémoire écrite à la fabrication que l'on ne peut pas effacer (programmées par le fabricant).

#### 2. Les PROM
Mémoire dans laquelle on écrit une seule fois et que l'on ne peut pas effacer (point mémire = fusible).

#### 3. Les EPROM
Mémoire dans laquelle on peut écrire et que l'on peut effacer après passage sous UV.

##### Structure :
Basée sur un transistor MOS à grille flottante.

#### 3. Les EEPROM
Mémoire dans laquelle on peut écrire et que l'on peut effacer électriquement.

##### Structure :
Basée sur un transistor MOS à grille flottante.




