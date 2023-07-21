## Code césar

#### Principe :

Le code césar consiste à crypter ou décrypter des messages selon une clé de codage qui décale les caractères ASCII de 33 à 126 (caractères lisibles).
Exemple :
Les caractères __abc__, cryptés avec une clé de codage qui décale les lettre de 3 positions, deviendront les caractères __def__.
De la même manière si l'on décrypte les caractères __def__ avec cette même clé, ils deviendront les caractères __abc__.

#### Objectifs :
Nous disponsons d'une carte adruino Mega, de 3 leds (rouge, verte, jaune) et d'un bouton poussoir.
Il faut réaliser un programme permettant :
- Lors du __1<sup>er</sup>__ appui : La led __JAUNE__ est allumée, la phrase écrite dans le terminal est recopiée à __l'IDENTIQUE__.
![image](https://user-images.githubusercontent.com/127400348/233962538-24d8b5de-5331-41ef-b251-22f0bfe9a84d.png)


- Lors du __2<sup>ème</sup>__ appui : La led __ROUGE__ est allumée, la phrase écrite dans le terminal est recopiée sous forme __CRYPTEE__.
![image](https://user-images.githubusercontent.com/127400348/233961284-30cc11e5-7ac6-47ff-a534-983f2fb7cfe6.png)

- Lors du __3<sup>ème</sup>__ appui : La led __VERTE__ est allumée, la phrase écrite dans le terminal est recopiée sous forme __DECRYPTEE__.
![image](https://user-images.githubusercontent.com/127400348/233961570-89a2bad2-5ddd-446f-a684-2d6fedfca816.png)




