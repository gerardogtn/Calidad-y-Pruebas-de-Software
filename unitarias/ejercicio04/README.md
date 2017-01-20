# Clase del 20 de enero.

Temas:
* Typed Test
* Typed Test with special Constructor
* Value Parametrized Test.

## Typed Test.

Si se tiene una jerarquia asi:

```
+--------------------+
|        Base        |
+--------------------+
| int doSomething()  |
+--------------------+
    ^            ^
    |            |
+--------+  +--------+
| Child1 |  | Child2 |
+--------+  +--------+
```

De tal manera que Child1 y Child2 tienen distintas implementaciones de
``doSomething()`` pero regresan el mismo resultado. Por ejemplo Base puede
ser una clase de ordenamiento, Child1 InsertionSort y Child2 MergeSort.
Se pueden generar test genericos que corran los mismos tests sobre los objetos
de una jerarquia.

### Pasos
1. Crear tu clase que herede de testing::Test, i.e. ADerivedBase.
2. ADerivedBase debe ser una plantilla, donde el parametro de la plantilla es
la clase concreta que deriva de ``Base``
3. Definir los typos en un typedef con testing::Types, i.e. ``typedef Types<Child1, Child2> MyTypes``
4. Definir un TYPED_TEST_CASE con el nombre de la clase, ADerivedBase, y el
nombre de los tipos MyTypes, i.e. `` TYPED_TEST_CASE(ADerivedBase, MyTypes)``
5. En lugar de usar el macro ``TEST_F()``, utilizar ``TYPED_TEST()``.
