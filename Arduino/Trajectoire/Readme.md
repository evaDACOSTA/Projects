# Trajectoire

Ce code consiste à faire suivre une trajectoire à un robot.

![image](https://github.com/L3-Option-TSI-2023/evaDACOSTA/assets/127400348/815b7bff-d30f-4ecc-865f-6a37eb0eaf18)


Il est composé de 2 parties :
- Une partie pour l'asservissement du robot
- Une partie de définition de fonctions pour la trajectoire du robot

### Asservissement 
Le robot ne parvient pas à garder une trajectoire droite (par exempe à cause des asperités du sol).
Il faut donc asservir les deux moteurs grâce à un correcteur Proportionnel-Intégrale.
Pour cela, on utilise une interruption de période 20ms.

Avant de définir l'asservissemnt, il faut mesurer la vitesse des roues.


##### 1. Vitesse des roues :

Pour mesurer la vitesse des roues, il faut compter le nombre de tics codeurs de chaque roues.
Pour cela, on utilise une interruption qui incrémente un compteur à chaque fois que le pin lié à l'interruption passe à l'état haut.

Ensuite, on sait que un tour de roue correspond à 990 tics codeur.

Dans notre interruption on peut donc calculer la vitesse de chaque roues grâce à cette formule :

  vitesse=(tic_Codeur/990.)/periode avec la periode = 0.02 secondes.


On peut aussi calculer la vitesse de déplaacement du robot grâce à la fomule :

  vit_Depl=((tic / 990.0) * Diamètre_Roue * pi) / 0.02
  

Maintenant que l'on connait les vitesses des deux roues, on peut asservir notre robot.

##### 2. Partie proportionnelle :

Il faut tout d'abord définir une consigne (une vitesse) que l'on va pouvoir varier grâce à un potentiomètre.
On récupère cette valeur grâce à :

  tension=(analogRead(3) * 5) / 1023; // On lit la valeur de la tension entre 0 et 1023 que l'on convertie en volt.
  
  consigne=tension * 255. / 5.;  // Cette ligne permet de faire correspondre la tension à une valeur comprise entre 0 et 255.
  
  consigne=consigne * 1.21 / 255; // on converie cette valeur en tour/s en utilisant le fait qu'une tension de 255 coresspond à 1.21 tour/s (valeur max).
  
  
Pour l'asservissement, il faut ensuite calculer l'erreur entre la consigne et la vitesse de chaque roue :

  erreurG=consigne-vitesseG;
  erreurD=consigne-vitesseD;
  
  
La commande des moteurs devient donc :

  commandeG=Gmax * erreurG;
  commandeD=Gmax * erreurD;
  
  
Le Gmax étant définit grâce à des essais successifs pour que la réponse converge le plus rapidement possible sans oscillations.

##### 3. Partie Intégrale :

Notre robot réagit maintenant rapidement, cependant il persiste une erreur statique (la réponse ne rejoint pas précisément la consigne).
On ajoute donc une partie intégration qui correspond à la somme des erreurs :

sommeEG += erreurG;
sommeED += erreurD;

La commande des moteurs devient donc :

  commandeG=Gmax * erreurG + tauI * sommeEG;
  commandeD=Gmax * erreurD + tauI * sommeED;
  
Le Gmax étant définit grâce à des essais successifs pour que la réponse converge le plus rapidement possible sans oscillations en atteignant la consigne.

On applique ensuite cette commande sur les moteurs :

  analogWrite(2,commandeD);
  analogWrite(7,commandeG);

### Fonctions de déplacement :

On définit le sens de rotation des roues grâce au port In1, In2, In3 et In4 d'un pont en H en leur appliquant une tension de 0V ou 5V:

![image](https://github.com/L3-Option-TSI-2023/evaDACOSTA/assets/127400348/0c1c39e7-af64-45a3-9c84-d592d6185578)

Exemple :

![image](https://github.com/L3-Option-TSI-2023/evaDACOSTA/assets/127400348/faf6ff23-12c3-4ed7-8c92-674d7b064500)

- Pour avancer : les deux roues tournent dans le même sens
- Pour tourner à droite : la roue gauche avance et la roue droite recule
- Pour tourner à gauche : la roue droite avance et la roue gauche recule

Enfin, on définit le temps pendant lequel le robot doit tourner à partir de la vitesse angulaire (2 * pi * consigne) :

void delais(float a) 

{

  temps = (a / (2 * pi * consigne)) * 1000; // 
  
  d = roundf(temps)-50;
  
  delay(d);
  
}


##### Exemple de trajectoire

https://drive.google.com/file/d/1g6Tj05B2l1Lm2iAIBRYC_W4hm9Cdz_GU/view?usp=drive_link




