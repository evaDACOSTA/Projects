# Les microcontrôleurs
### Qu'est-ce qu'un microcontrôleur ?

Le microcontrôleur est un dérivé du microprocesseur. Il est composé d'une **unité centrale de traitement** et de commande (équivalente au microprocesseur), de **mémoires** et de ports **d'entrées/sorties**.
En plus de cette configuration minimale, les microcontrôleurs sont dotés d'un ou plusieurs **systèmes de comptage** (TIMER). Quelques uns sont dotés d'un **convertisseur analogique/numérique** (CAN) intégré. Ces atouts supplémentaires permettent de nombreuses applications telles que :

- acquisition et traitement de données analogiques (CAN)
- comptage d'événements (TIMER)
- mesure de fréquence ou de période (TIMER)
- génération d'impulsions (TIMER) 

Dans un seul circuit on va trouver :
- Une Horloge (oscillateur) 
- Un processeur (Unité centrale) 
- De la mémoire vive (RAM)
- De la mémoire morte (PROM, EPROM, EEPROM) 
- Des interfaces qui vont dépendre du type de microcontrôleurs choisi (Compteurs/Timer, Convertisseurs Analogiques/numériques)

![image](https://user-images.githubusercontent.com/127400348/227773436-797b5098-633b-4341-a90c-0de0943c10a3.png)

### Types de microcontôleurs :

Les microcôntroleurs diffèrent de part leurs :
- Largeur de bus de données (8 / 16 / 32 / 64 bits)
- Mémoire embarquée (toujours) ou externe (dans certain cas)
- Jeu d'instructions (CISC / RISC)
- Architecture (Von Neuman / Harvard)

### Différences entre CISC et RISC :
#### 1. Définition de RISC :

Le terme RISC signifie « Reduced Instruction Set Computer », il est basé sur des instructions simples et rapide.
RISC définit un ensemble d’instructions réduit : chaque instruction doit faire des petits tâches. 

Les jeux d’instructions sont simples et modestes, ce qui aide à comprendre des commandes plus complexes. 
Chaque instruction possède à peu près la même longueur et sont regroupés pour effectuer des tâches complexes en une seule opération. 
La plupart des commandes sont exécutées en un cycle d'horloge.

Il nécessite moins de transistors, ce qui les rend moins chères à concevoir et à produire. Quelques autres caractéristiques de RISC incluent:
  - Moins de demande de décodage
  - Jeu d'instructions uniformes
  - Adresses simples
  - Peu de types de données dans le matériel

![image](https://user-images.githubusercontent.com/127400348/227775515-d4d0864e-9e6d-416c-84ce-2103cdc9afae.png)



#### 2. Définition de CISC :

Le terme CISC signifie « Complex Instruction Set Computer », il est basé sur des instructions uniques, capables d’exécuter des opérations en plusieurs étapes.

Les ordinateurs du CISC ont de petits programmes. Il comporte un grand nombre d’instructions composées, ce qui prend beaucoup de temps. Un seul jeu
d’instructions est couvert en plusieurs étapes : chaque jeu d’instructions contient plus de 300 instructions distinctes.
La plupart des instructions sont complétées en deux à dix cycles machine. Dans CISC, le traitement en continu des instructions n’est pas facile à mettre en œuvre.

Il effectue des opérations de bas niveau telles qu'une opération arithmétique ou un chargement à partir de la mémoire et de la mémoire.

Le CISC facilite la création de nœuds d'adressage volumineux et de davantage de types de données dans le matériel de la machine. 


![image](https://user-images.githubusercontent.com/127400348/227775532-52c4d34b-ebfb-4b23-8d2f-2c66a770e9e5.png)



#### 3. Conclusion sur les différences entre CISC et RISC :

![image](https://user-images.githubusercontent.com/127400348/227777286-f204e5f4-c5b1-4f0e-9f69-0a413b76f092.png)

### Différences entre architecture Von Neuman et Harvard :
#### 1. Architecture Von Neumann :

L’architecture de von Neumann est un modèle structurel d’ordinateur dans lequel une unité de stockage (mémoire) unique sert à conserver à la fois les instructions et les données demandées ou produites par le calcul : un bus de données unique véhicule les instructions et les données ce qui rend la communication très lente.
Il véhicule donc tour à tour les codes des instructions et les données qui leur sont associées.

![image](https://user-images.githubusercontent.com/127400348/227778181-153ba08c-b68d-4235-b257-a170b36e1078.png)

#### 2. Architecture Harvard :
L’architecture HARVARD est basée sur deux bus de données. Un bus est utilisé pour les données et un autre pour les instructions.

![image](https://user-images.githubusercontent.com/127400348/227778299-a8423d5e-1868-4fe0-ba8a-47ed0f7d497d.png)

Il est composé de 2 blocs mémoire distincts et 2 bus différents : 1 bus 8 bits pour communiquer avec la RAM, 1 bus 14 bits pour communiquer avec la ROM, qui contient le programme. Cela permet donc de séparer les mémoires programme et données et une meilleure utilisation du CPU grâce au chargement du programme et des données en parallèle.

![image](https://user-images.githubusercontent.com/127400348/227778329-71361d90-ad06-4549-84c0-338d27a52fb1.png)


#### 3. Conclusion sur les différences entre architecture Von Neumann et Harvard :

![image](https://user-images.githubusercontent.com/127400348/227778874-deb390e9-55a6-4268-9b7b-1f8ac1fc96e9.png)



