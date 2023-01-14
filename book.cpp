#include "headinclude.h"

class book {
private:
    char *author, *title, *publisher;
    float *price;
    int *stock;

public:
    book() {
        author = new char[20];
        title = new char[20];
        publisher = new char[20];
        price = new float;
        stock = new int;
    }

    void feeddata();
    void editdata();
    void showdata();
    int search(char[], char[]);
    void buybook();
    
};


void book::feeddata() {
    cin.ignore();

    cout << "Enter Author Name: ";
    cin.getline(author, 20);
    cout << " Enter Title Name: ";
    cin.getline(title, 20);
    cout << "Enter Publisher Name: ";
    cin.getline(publisher, 20);
    cout << "Enter Price: ";
    cin >> *price;
    cout << "Enter Storck Position: ";
    cin >> *stock;

}

void book::editdata() {
    cout << "Enter Author Name: ";
    cin.getline(author, 20);
    cout << " Enter Title Name: ";
    cin.getline(title, 20);
    cout << "Enter Publisher Name: ";
    cin.getline(publisher, 20);
    cout << "Enter Price: ";
    cin >> *price;
    cout << "Enter Storck Position: ";
    cin >> *stock;

}

void book::showdata() {
    cout << "\nAuthor Name: " << author;
    cout << "\nTitle Name: " << title;
    cout << "\nPublisher Name: " << publisher;
    cout << "\nPrice: " << *price;
    cout << "\nStock Position: " << stock;  
}

int book::search(char byTitle[20], char byAuthor[20]) {
    if (strcmp(byTitle, title) == 0 && strcmp(byAuthor, author) == 0)
        return 1;
    else 
         return 0;

}

void book::buybook() {
    int count;
    cout << "/nEnter Number of Books to Buy: ";
    cin >> count;
    if (count <= *stock) {
        *stock = *stock - count;
        cout << "Books Bought Sucessfully";
        cout << "Aount: $ " << (*price) * count;
    } else {
        cout << "Required copies not in stock!";
    }
}


int main() {
    book *Book[20];
    int i = 0, r, t, choice;
    char bytitle[20], byauthor[20];
    while (1) {
        cout << "\n\n\t\n\tMENU" << "\n1. Entry of New Book"
        << "\n2. Buy Book" << "\n3. Search for Book" << "\n4. Edit Details of Book"
        << "\n5. Exit"
        << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch(choice) {
            case 1: Book[i] = new book;
                    Book[i]->feeddata();
                    i++;
                    break;
            case 2: cin.ignore();
                    cout << "Enter Title of Book: ";
                    cin.getline(bytitle, 20);
                    cout << "Enter Author of Book: ";
                    cin.getline(byauthor, 20);
                    for (t = 0; t < i; t++) {
                        if (Book[t]->search(bytitle,byauthor))
                            Book[t]->buybook();
                            break;
                    }
                    if (t == i)
                        cout << "Sorry! This Book is Not in Stock.";
                    break;
            case 3: cin.ignore();
                    cout << "Enter Title of Book: ";
                    cin.getline(bytitle, 20);
                    cout << "Enter Author of Book: ";
                    cin.getline(byauthor, 20);
                    for (t = 0; t < i; t++) {
                        if (Book[t]->search(bytitle,byauthor)) {
                            cout << "\nBook Found Successfully!";
                            Book[t]->showdata();
                            break;
                        }
                    }
                    if (t == i)
                        cout << "Sorry! This Book is Not in Stock.";
                    break; 
            case 4:cin.ignore();
                    cout << "Enter Title of Book: ";
                    cin.getline(bytitle, 20);
                    cout << "Enter Author of Book: ";
                    cin.getline(byauthor, 20);
                    for (t = 0; t < i; t++) {
                        if (Book[t]->search(bytitle,byauthor)){
                            cout << "\nBook Found Successfully!";
                            Book[t]->editdata();
                            break;
                        }
                            
                    }
                    if (t == i)
                        cout << "Sorry! This Book is Not in Stock.";
                    break;
            case 5: exit(0);
            default: cout << "\nInvalid Choice Entered";
        }
    }
}


