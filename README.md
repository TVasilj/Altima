# Altima

Instructions:
Run application on windows

If you have installed Visual Studio
Open "Altima.sln" with Visual Studio

To run application press
"Ctrl + f5"

Or 
Debug -> Start Without Debbuging

To run the application from cmd
>g++ Main.cpp Altima.cpp Relatives.cpp -o test
>test.exe

Example 1)
relatives.txt:
Adam Ivan
Marko Stjepan
Stjepan Adam
Robert Stjepan
Fran Ivan
Leopold Luka

Application output:
Ivan
     Adam
          Stjepan
               Marko
               Robert
     Fran
Luka
     Leopold
Press any key to continue . . .

Example 2)
relatives.txt:
Adam Ivan
Marko Stjepan
Stjepan Adam
Robert Stjepan
Fran Ivan
Leopold Luka
Nikola Franjo
Stjepan Fran

Application output:
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

Example 3)
relatives.txt:
Adam Ivan
Stjepan Adam
Ivan Stjepan

Aplication output:
cyclic relationships!

Debug Error will show up, abort will be called

