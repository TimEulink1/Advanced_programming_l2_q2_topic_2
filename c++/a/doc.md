# C++ -> .so file 

bron: 
````https://www.youtube.com/watch?v=fvvWr1jaLyw````

 1. Maak een c++ bestand
Voorbeeld **main.cpp**: 
````c
#include <pybind11/pybind11.h>
#include <string>
namespace py = pybind11;

int add(int a, int b) {
    return a + b;
}

struct Pet{
    Pet(const std::string &name) : name(name){}
    void setName(const std::string &name_){
        name = name_;
    }
    const std::string &getName()  const { return name; }

    std::string name;
};

PYBIND11_MODULE(example, m) {
    m.doc () = "Example plugin";
    m.def("add", &add, "A function which adds two intergers");

    py::class_<Pet>(m, "Pet")
            .def(py::init<const std::string  &>())
            .def("setName", &Pet::setName)
            .def("getName", &Pet::getName)
            .def_readwrite("name", &Pet::name);
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
