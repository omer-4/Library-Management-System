# Library Management System &#40;C\+\+&#41;

## Project idea

A small console\-based library system\. It allows the user to:

- Add a book\.
- Add a magazine\.
- Display all items\.
- Search for an item by its ID or title\.
- Borrow an available item\.
- Return a borrowed item\.

## OOP concepts used in this exact code

- **Classes and Objects:** `Item`, `Book`, `Magazine`, and `Library` are classes\. `lib` is an object of `Library`\.
- **Encapsulation:** `id`, `title`, and `available` are private data members in `Item`\. Public getter/setter functions provide controlled access\.
- **Constructor:** `Item(int i, string t)` initializes the ID, title, and availability\. The constructors of `Book` and `Magazine` call the base constructor\.
- **Destructor:** `virtual ~Item()` is the base\-class destructor\. `~Library()` deletes the dynamically allocated items when the library object is destroyed\.
- **Inheritance:** `Book` and `Magazine` publicly inherit from `Item`\.
- **Polymorphism:** `display()` is a pure virtual function in `Item` and is overridden in `Book` and `Magazine`\. `show()` calls it through `Item*` pointers\.
- **Function Overloading:** `search(int id)` searches by ID, while `search(string title)` searches by title\.
- **Access Modifiers:** `private` and `public` are used in the classes\.

## Important note about input

The short version reads the title with `cin >> title`, so enter a one\-word title without spaces, for example `CPlusPlus`\.

## Compile and run

Requires a C\+\+14 &#40;or newer&#41; compiler\.

Using g\+\+ on Linux/macOS:

```bash
g++ -std=c++14 Library_Management_System_Short.cpp -o library
./library
```

On Windows:

```bash
g++ -std=c++14 Library_Management_System_Short.cpp -o library.exe
library.exe
```

## Menu

1. Add Book
2. Add Magazine
3. Show Items
4. Search by ID
5. Borrow
6. Return
7. Exit

## Limitation

This educational version stores items in memory only\. The data is lost when the program closes\. File or database storage can be added later\.
