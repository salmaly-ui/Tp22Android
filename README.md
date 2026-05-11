# JNIBridgeDemo - Application Native C++/JNI

## Description
Application Android démontrant la communication entre Java et C++ via JNI (Java Native Interface) avec le template Native C++.

## Fonctionnalités
| Fonction | Description | Exemple |
|----------|-------------|---------|
| getWelcomeMessage | Retourne un message depuis le code natif | "Welcome to JNI Bridge!" |
| calculateProduct | Calcule le produit de deux entiers | 7 x 8 = 56 |
| transformText | Inverse la casse et renverse la chaîne | "JNI Demo" → "omeD INj" |
| sumIntegerArray | Calcule la somme d'un tableau d'entiers | [2,4,6,8,10] = 30 |


## Demo   

https://github.com/user-attachments/assets/ad25c7f7-dc75-4c85-b1c7-fc0867fd4571


## Installation

### Prérequis
- Android Studio (dernière version)
- SDK Android API 24+
- NDK installé
- CMake installé

### Étapes
1. Ouvrir Android Studio
2. File → New → Project → Native C++
3. Configurer :
   - Name: JNIBridgeDemo
   - Package: com.example.jnibridge
   - Language: Java
   - Minimum SDK: API 24
4. Cliquer sur Finish

