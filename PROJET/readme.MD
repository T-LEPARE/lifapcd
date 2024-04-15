Sprites : 
https://comp3interactive.itch.io/invaders-from-outerspace-full-project-asset-pack

Commande valgrind (ignore les erreurs inhérentes à SDL) : 
 valgrind --suppressions=./sdl_suppressions.supp ./bin/StarblitzGame

 UML : 
 http://www.plantuml.com/plantuml/uml/

 Tests : sudo apt install libgtest-dev


 StarBlitz

StarBlitz est un jeu inspiré de Space Invaders, où vous contrôlez un vaisseau spatial pour éliminer des envahisseurs extraterrestres.
Organisation des dossiers

    data/ : Contient les ressources graphiques et sonores du jeu.
    src/ : Contient le code source de l'application.
    doc/ : contient l'UML et la documentation doxygen du jeu.

Compilation et exécution
Compilation avec makefile et CMakeLists.txt

Pour compiler le jeu, assurez-vous d'avoir installé les bibliothèques SDL2, SDL2_image, SDL2_ttf et SDL2_mixer ainsi que gtest pour les tests unitaires.


Contrôles :

    Utilisez les flèches directionnelles pour vous déplacer.
    Appuyez sur la barre d'espace pour tirer.
    Changez d'arme avec la touche 'd'.

But du jeu :

Votre mission est de détruire tous les envahisseurs extraterrestres. Évitez les tirs ennemis et collectez des points en éliminant les vaisseaux ennemis. Survivez à un maximum de manches pour atteindre le plus haut score !

Liste des fonctionnalités du programme :

    Contrôle du vaisseau spatial.
    Tirs de projectiles.
    Gestion des envahisseurs extraterrestres.
    Système de score.
    Effets sonores et musique de fond.



Amusez-vous bien ! 🚀👾✨