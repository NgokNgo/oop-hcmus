// THE LIBARY APP 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BorrowerRecord;

class Book{
private:
  string catalogueNumber;
  string author;
  string title;
  BorrowerRecord* borrower;
public:
  Book(string catalogueNumber, string author, string title)
  {
    this->catalogueNumber = catalogueNumber;
    this->author = author;
    this->title = title;
  }

//get/set
  void setNumber(string catalogueNumber){this->catalogueNumber = catalogueNumber;}
  string getNumber(){ return this->catalogueNumber;}
  void setAuthor(string author){this->author = author;}
  string getAuthor(){return this->author;}
  void setTitle(string title){this->title = title;}
  string getTitle(){return this->title;}
  void setBorrower(BorrowerRecord *borrowerName){this->borrower = borrowerName;}
  BorrowerRecord* getBorrower(){return this->borrower;}

//behavior
  void attachBorrower(BorrowerRecord* borrower); 
  void detachBorrower(); 
  void display(){
    cout << "Number: " << getNumber() << endl;
    cout << "Author: " << getAuthor() << endl;
    cout << "Title: " << getTitle() << endl;
  }
};

class BorrowerRecord{
private:
  string name;
  vector<Book*> borrowedBooks;
public:
  BorrowerRecord(string name){
    this->name = name;
  }
  void setName(string name){this->name = name;}
  string getName(){return this->name;}

  void attachBook(Book *aBook){
    this->borrowedBooks.push_back(aBook);
  }
  void detachBook(Book *aBook){
    for(int i = 0; i < borrowedBooks.size(); i++){
      if(borrowedBooks[i] == aBook){
        borrowedBooks.erase(borrowedBooks.begin() + i);
        break;
      }
    }
  }
};

void Book::attachBorrower(BorrowerRecord* borrower){
  borrower->attachBook(this);
  this->borrower = borrower;
}

void Book::detachBorrower(){
  this->borrower->detachBook(this);
  this->borrower = nullptr;
}

class Library{
private:
  string name;
  vector<Book*> stock;
  vector<BorrowerRecord*> borrowers;
public:
  Library(string s){
    this->name = s;
  }
  ~Library(){
    for (auto borrower : borrowers){
      delete borrower;
    }
    //cout << "before clear the borrowers: size = " << this->borrowers.size() << endl;
    this->borrowers.clear();
    //cout << "after clear the borrowers: size = " << this->borrowers.size() << endl;
  }
  void setName(string name){this->name = name;}
  string getName(){ return this->name; }
  
//behavior
  void registerOneBorrower(string borrowerName){
    this->borrowers.push_back(new BorrowerRecord(borrowerName));
  }
  void addOneBook(Book *abook){
    abook->setBorrower(nullptr);
    this->stock.push_back(abook);
  }
  void displayBooksAvailableForLoan(){
    for (auto book : stock){
      if(book->getBorrower() == nullptr)
        book->display();
    }
  }
  void displayBooksOnLoan(){
    for (auto book : stock){
      if(book->getBorrower() != nullptr)
      book->display();
    }
  }
  void lendOneBook(string catalogueNumber, string borrowerName){
    Book* book = nullptr;
    BorrowerRecord* borrower = nullptr;
    for(auto b : borrowers){
      if(b->getName() == borrowerName){
        borrower = b;
        break;
      }
    }
    if(borrower == nullptr){
      cout << "Can not find the borrower\n";
      return;
    }
    for(auto b : stock){
      if(b->getNumber() == catalogueNumber){
        book = b;
        break;
      }
    }
    if(book == nullptr){
      cout << "Can not find the book\n";
      return;
    }
    book->attachBorrower(borrower);
    cout << "Lend successfull! \n";
  }
  void returnOneBook(string catalogueNumber){
    for(auto book : stock){
      if(book->getNumber() == catalogueNumber){
        book->detachBorrower();
        cout << "Book returned! \n";
      }
    }
  }
};



int main()
{
  // Book* new_book = new Book("Book", "ABC", "12");
  // delete(new_book);
  Book book("001", "C", "McGrawHill");
  Book book2("002", "Java", "McGrawHill");
  Library lib("HCMUS");
  lib.addOneBook(&book);
  lib.addOneBook(&book2);
  lib.registerOneBorrower("Huy");
  lib.lendOneBook("001","Huy");
  // lib.displayBooksAvailableForLoan();
  lib.lendOneBook("002","Huy");
  lib.returnOneBook("002");
  return 0;
}