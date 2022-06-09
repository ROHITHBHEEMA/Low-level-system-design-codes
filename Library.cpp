#include <bits/stdc++.h>
using namespace std;

enum Category {FICTION, SCI_FI, MYSTERY, FABLE, MYTHOLOGY};

class Book
{
	private:
		string name;
		string author;
		string publisher;
		int publish_year;
		double price;
		int count;
		Category category;
	
	public:
		Book(string name,string author,string publisher,int publish_year,Category category,double price,int count);
		string getName();
		string getAuthor();
};

class Library
{
	private:
		vector<Book>books;
		unordered_map<string,vector<Book>>authormap;
	public:
		Library(){};
		void addBookToLibrary(Book&);
		vector<Book> searchBookByName(string);
		vector<Book> searchBookByAuthor(string);

};

Book :: Book(string name,string author,string publisher,int publish_year,Category category,double price,int count)
{
	this->name = name;
	this->author = author;
	this->publisher = publisher;
	this->publish_year = publish_year;
	this->category = category;
	this->price = price;
	this->count = count;
}

string Book :: getName()
{
	return name;
}

string Book :: getAuthor()
{
	return author;
}

void Library :: addBookToLibrary(Book& book)
{
	books.push_back(book);
	authormap[book.getAuthor()].push_back(book);
}

vector<Book> Library :: searchBookByName(string prefix)
{
	vector<Book> bookList;
	for(Book book: books)
	{
		string name = book.getName();
		if(name.substr(0, prefix.size()) == prefix)
			bookList.push_back(book);
	}

	return bookList;
}

vector<Book> Library :: searchBookByAuthor(string authorname)
{
	auto p = authormap[authorname];
	return p;
}


int main()
{
	Book book("HP & The PS", "J K Rowling", "Bloomsbury", 1997, Category::FICTION, 200, 80);
	Book book1("HP & The COS", "J K Rowling", "Bloomsbury", 1998, Category::FICTION, 1000, 100);
	Book book2("HP & The POA", "J K Rowling", "Bloomsbury", 1999, Category::FICTION, 2000, 500);
	Book book3("HP & The HBP", "J K Rowling", "Bloomsbury", 2005, Category::FICTION, 3000, 700);
	Book book4("The Immortals of Meluha", "Amish", "Westland", 2010, Category::MYTHOLOGY, 1500, 600);
	Book book5("The Secret of the Nagas", "Amish", "Westland", 2011, Category::MYTHOLOGY, 2500, 400);
	Book book6("The Oath of the Vayuputras", "Amish", "Westland", 2013, Category::MYTHOLOGY, 3500, 200);
	Book book7("Do Androids dream of Electric Sheep", "Philip K Dick", "DoubleDay", 1968, Category::SCI_FI, 30, 20);

	Library library;
	library.addBookToLibrary(book);
	library.addBookToLibrary(book1);
	library.addBookToLibrary(book2);
	library.addBookToLibrary(book3);
	library.addBookToLibrary(book4);
	library.addBookToLibrary(book5);
	library.addBookToLibrary(book6);
	library.addBookToLibrary(book7);

	vector<Book> list =  library.searchBookByAuthor("J K Rowling");
	for(Book book: list)
		cout << book.getName()<< endl;
	cout << "**************************************************************************************\n";

	list = library.searchBookByName("The");
	for(Book book: list)
		cout << book.getName()<< endl;

}




