#include <iostream>
#include <vector>
using namespace std;

class Item {
private:
    int id;
    string title;
    bool available;

public:
    Item(int i, string t) {
        id = i;
        title = t;
        available = true;
    }

    virtual ~Item() {}

    int getId() { return id; }
    string getTitle() { return title; }
    bool isAvailable() { return available; }
    void setAvailable(bool a) { available = a; }

    virtual void display() = 0;
};

class Book : public Item {
public:
    Book(int i, string t) : Item(i, t) {}

    void display() override {
        cout << "Book: " << getTitle()
             << " ID: " << getId() << endl;
    }
};

class Magazine : public Item {
public:
    Magazine(int i, string t) : Item(i, t) {}

    void display() override {
        cout << "Magazine: " << getTitle()
             << " ID: " << getId() << endl;
    }
};

class Library {
private:
    vector<Item*> items;

public:
    ~Library() {
        for (Item* x : items)
            delete x;
    }

    void add(Item* x) {
        items.push_back(x);
    }

    void show() {
        for (Item* x : items)
            x->display();
    }

    // Function Overloading
    Item* search(int id) {
        for (Item* x : items)
            if (x->getId() == id)
                return x;
        return nullptr;
    }

    Item* search(string title) {
        for (Item* x : items)
            if (x->getTitle() == title)
                return x;
        return nullptr;
    }

    void borrow(int id) {
        Item* x = search(id);

        if (x && x->isAvailable()) {
            x->setAvailable(false);
            cout << "Borrowed successfully\n";
        }
        else
            cout << "Not available\n";
    }

    void giveBack(int id) {
        Item* x = search(id);

        if (x && !x->isAvailable()) {
            x->setAvailable(true);
            cout << "Returned successfully\n";
        }
        else
            cout << "Not found or not borrowed\n";
    }
};

int main() {
    Library lib;
    int choice, id;
    string title;

    do {
        cout << "\n1. Add Book";
        cout << "\n2. Add Magazine";
        cout << "\n3. Show Items";
        cout << "\n4. Search";
        cout << "\n5. Borrow";
        cout << "\n6. Return";
        cout << "\n0. Exit";
        cout << "\nChoose: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ID and Title: ";
            cin >> id >> title;
            lib.add(new Book(id, title));
            break;

        case 2:
            cout << "Enter ID and Title: ";
            cin >> id >> title;
            lib.add(new Magazine(id, title));
            break;

        case 3:
            lib.show();
            break;

        case 4:
            cout << "Enter ID: ";
            cin >> id;

            if (Item* x = lib.search(id))
                x->display();
            else
                cout << "Not found\n";
            break;

        case 5:
            cout << "Enter ID: ";
            cin >> id;
            lib.borrow(id);
            break;

        case 6:
            cout << "Enter ID: ";
            cin >> id;
            lib.giveBack(id);
            break;
        }

    } while (choice != 0);

    return 0;
}