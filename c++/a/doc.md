# C++ -> .so file 

bron: 
````https://www.youtube.com/watch?v=fvvWr1jaLyw````

 1. Maak een c++ bestand
Voorbeeld **main.cpp**: 
````c
#include <pybind11/pybind11.h>  
  
float add(float arg1, float arg2){  
    return arg1 + arg2;  
}  
  
PYBIND11_MODULE(example, m){  
    m.def("add", &add, "Beschrijving")  
}
````
 2. Open ubuntu
 3. voer het volgende uit: 
````
sudo apt-get -y install python3-pip
sudo apt-get install python3-dev
pip3 install pybind11
````

 4. Ga binnen ubuntu naar de map waar je **main.cpp** staat
 5. Voer dit commando uit:
 ````
 c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) example.cpp -o example$(python3-config --extension-suffix)
 ````
 6. Er is binnen deze folder nu een .so file gegenereerd bijvoorbeeld: example.so
 7. Het is nu mogelijk om deze te importeren in python door:
 ````import example````
 8. Vervolgens is de functie aan te roepen door:
````python
example.add(3,5) #results in 8
````
