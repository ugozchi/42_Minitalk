![Minitalk logo](.media/minitalk_logo.png)

![Grade badge](https://img.shields.io/badge/125_%2F_100-004d40?label=final%20grade&labelColor=151515&logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIGhlaWdodD0iMjRweCIgdmlld0JveD0iMCAwIDI0IDI0IiB3aWR0aD0iMjRweCIgZmlsbD0iI0ZGRkZGRiI+PHBhdGggZD0iTTAgMGgyNHYyNEgweiIgZmlsbD0ibm9uZSIvPjxwYXRoIGQ9Ik0xMiAxNy4yN0wxOC4xOCAyMWwtMS42NC03LjAzTDIyIDkuMjRsLTcuMTktLjYxTDEyIDIgOS4xOSA4LjYzIDIgOS4yNGw1LjQ2IDQuNzNMNS44MiAyMXoiLz48L3N2Zz4=) ![Language Badge](https://img.shields.io/badge/C-fe428e?logo=C&label=language&labelColor=151515) ![Norminette Badge](https://img.shields.io/badge/passing-brightgreen?logo=42&label=norminette&labelColor=151515)

# Minitalk

Ce projet consiste à créer un programme client/serveur simple. Les deux programmes ne peuvent communiquer que via les signaux POSIX `SIGUSR1` et `SIGUSR2`.
Le client encode chaque bit du message et utilise `SIGUSR1` pour envoyer des 0 au serveur et `SIGUSR2` pour envoyer des 1. Le serveur accumule les bits reçus et stocke chaque octet reçu dans un tampon temporaire.
Une fois qu'un terminateur nul `\0` a été reçu par le serveur, il imprime le message et renvoie `SIGUSR2` au client pour fermer la communication. Les caractères Unicode sont pris en charge par le client et le serveur.
Vous pouvez trouver le sujet [ici](en.subject.pdf).

