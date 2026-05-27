<div align="center">

# Multiplicación de Matrices

## **👥 | Miembros**

| Nombre | Github |
|------|--------|
|Matias Felipe Jener Valdebenito Valenzuela|[@Mazulini](https://github.com/Mazulini)|
|Pablo Esteban Villagran Hermanns|[@Pvilla14](https://github.com/Pvilla14)|
|Javier Alejandro Campos Contreras|[@4lehh](https://github.com/4lehh)|



## **Tecnologías usadas**

<a href="https://skillicons.dev">
  <img src="https://skillicons.dev/icons?i=git,github,vscode&perline=5" />
</a>

## **🔐 | Lenguajes de Programación**

<a href="https://skillicons.dev">
  <img src="https://skillicons.dev/icons?i=cpp,python,bash&perline=5" />
</a>

## **📚 | Descripción**

</div>

La multiplicación de matrices es una operación fundamental en computación científica, gráficos computacionales, aprendizaje automático y muchas otras áreas.

En este problema, recibimos como entrada dos matrices de coeficientes reales:

- $A$ de dimensión $n_1 \times n_2$
- $B$ de dimensión $n_2 \times n_3$

y queremos calcular:

$$
C = A \cdot B
$$

donde $C$ tiene dimensión $n_1 \times n_3$ y sus componentes están definidas por:

$$
C_{i,j} =
\sum_{k=1}^{n_2}
A_{i,k} \cdot B_{k,j}
$$

El algoritmo clásico calcula directamente cada componente de la matriz producto y posee complejidad:

$$
\Theta(n_1 \cdot n_2 \cdot n_3)
$$

En 1969, Volker Strassen demostró que es posible realizar esta operación con una complejidad asintótica menor utilizando una estrategia de tipo *Divide & Conquer*. Este descubrimiento abrió una línea de investigación sobre algoritmos subcúbicos que continúa activa hasta la actualidad.

El objetivo de esta tarea es diseñar, implementar y evaluar experimentalmente el algoritmo de Strassen.

<div align="center">

## **🗂️ | Inicio rápido**

</div>

> [!IMPORTANT]
> Requisitos: Se recomienda usar g++ 11.4 como mínimo

```sh
# Ejecutar el código
g++ -std=c++11 uhr.cpp src/*.cpp -o uhr

./uhr <filename>.csv <runs> <lower> <upper> <step>
```

