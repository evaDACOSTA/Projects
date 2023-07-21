# moteurs

Ce code permet de faire se déplacer un robot :

On définit le sens de rotation des roues grâce au port In1, In2, In3 et In4 d'un pont en H en leur appliquant une tension de 0V ou 5V:

![image](https://github.com/L3-Option-TSI-2023/evaDACOSTA/assets/127400348/0c1c39e7-af64-45a3-9c84-d592d6185578)

Exemple :

![image](https://github.com/L3-Option-TSI-2023/evaDACOSTA/assets/127400348/faf6ff23-12c3-4ed7-8c92-674d7b064500)

- Pour avancer : les deux roues tournent dans le même sens
- Pour tourner à droite : la roue gauche avance et la roue droite recule
- Pour tourner à gauche : la roue droite avance et la roue gauche recule

# ticCodeur

Ce code utilise une interruption qui incrémente un compteur à chaque fois que le pin lié à l'interruption passe à l'état haut afin de compter le nombre de tics codeurs de chaque roue.

Il calcule ensuite la vitesse de chaque roue.
En effet, on sait que un tour de roue correspond à 990 tics codeur.

Dans une interruption de période 10 ms, on calcule la vitesse de chaque roues grâce à cette formule :

  vitesse=(tic_Codeur/990.)/periode avec la periode = 0.01 secondes.
