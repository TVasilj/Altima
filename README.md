# Altima

Instructions:
Run application on windows

If you have installed Visual Studio
Open "Altima.sln" with Visual Studio

To run application press
"Ctrl + f5"
Or 
Debug -> Start Without Debbuging

To run the application from cmd:
```sh
> g++ Main.cpp Altima.cpp Relatives.cpp -o test
> test.exe
```
# Example 1)
relatives.txt:
```sh
Adam Ivan
Marko Stjepan
Stjepan Adam
Robert Stjepan
Fran Ivan
Leopold Luka
```

Application output:
```sh
Ivan
    Adam
          Stjepan
               Marko
               Robert
     Fran
Luka
     Leopold
Press any key to continue . . .
```

# Example 2)
relatives.txt:
```sh
Adam Ivan
Marko Stjepan
Stjepan Adam
Robert Stjepan
Fran Ivan
Leopold Luka
Nikola Franjo
Stjepan Fran
```

Application output:
```sh
Franjo
     Nikola
Ivan
     Adam
          Stjepan
               Marko
               Robert
     Fran
          Stjepan
               Marko
               Robert
Luka
     Leopold
Press any key to continue . . .
```

# Example 3)
relatives.txt:
```sh
Adam Ivan
Stjepan Adam
Ivan Stjepan
```

Aplication output:
```sh
cyclic relationships!

'Debug Error will show up, abort will be called'
```

# Unit Test
For Unit Test you need to set up Visual Studio by following instructions on the link
https://www.youtube.com/watch?v=uxyfXU63Qpw

# Run Unit Test
Test -> Run -> All Tests