# 🐦 Flappy Bird en C++

## Descripción del Proyecto

Reimplementación del clásico y popular juego **Flappy Bird** desarrollado en el lenguaje de programación **C++**. El objetivo del proyecto es recrear la mecánica de juego esencial (gravedad, salto y colisión) para demostrar habilidades de programación de juegos y manejo de librerías gráficas.

---

## 🛠️ Tecnologías Utilizadas

* **Lenguaje:** C++ (Se recomienda usar un compilador compatible con C++11 o superior).
* **Compilación:** **Makefile** para automatizar el proceso de construcción y enlace.
* **Librería Gráfica:** (Añade aquí la librería que usaste, por ejemplo: **SFML** o **SDL**).

*Si el proyecto utiliza una librería específica para gráficos, como SFML o SDL, asegúrate de añadirla en la sección de "Librería Gráfica" para claridad.*

## ✨ Características Principales

* Implementación de la física básica del pájaro (gravedad y salto).
* Generación procedural de obstáculos (tuberías).
* Detección de colisiones.
* Sistema de puntuación.

---

## ⚙️ Instalación y Configuración

Para compilar y ejecutar este proyecto en tu entorno local, sigue los siguientes pasos.

### Prerrequisitos

Asegúrate de tener instalados:

1.  Un compilador de C++ (ej. **g++**).
2.  El gestor de compilación **Make**.
3.  Todas las librerías dependientes (e.g., SFML, SDL) y sus respectivos archivos de encabezado (`headers`).

### Pasos de Instalación

1.  **Clona el repositorio:**

    ```bash
    git clone [https://github.com/Danuzu11/flappybird03.git](https://github.com/Danuzu11/flappybird03.git)
    cd flappybird03
    ```

2.  **Compila el proyecto:**

    Utiliza el `Makefile` para compilar todo el código fuente:

    ```bash
    make
    ```

3.  **Ejecuta el juego:**

    Una vez finalizada la compilación, se generará el ejecutable.

    ```bash
    ./flappybird
    ```
    *(Asegúrate de que el nombre del ejecutable sea el correcto si lo has modificado en el `Makefile`)*

---

## 🕹️ Modo de Uso

| Acción | Entrada (Input) |
| :--- | :--- |
| **Salto** | Barra espaciadora o clic izquierdo del ratón. |
| **Objetivo** | Evitar las tuberías y conseguir la máxima puntuación. |

## 🤝 Contribuciones

Las contribuciones son bienvenidas. Si encuentras un error o tienes sugerencias de mejora (como optimización o nuevas características), por favor, abre un *issue* o envíame un *pull request*.

1.  Crea un *fork* del proyecto.
2.  Crea tu nueva rama (`git checkout -b feature/AmazingFeature`).
3.  Realiza tus cambios y haz *commit* (`git commit -m 'Add some AmazingFeature'`).
4.  Sube la rama (`git push origin feature/AmazingFeature`).
5.  Abre un *Pull Request*.

---
