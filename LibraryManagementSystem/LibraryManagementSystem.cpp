#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

class Book
{
public:
    // Constructor
    Book(std::string const& title, std::string const& author,
        unsigned long long ISBN, bool available);

    // Method declarations
    void checkIn();
    void checkOut();
    std::string getTitle() const;
    std::string getAuthor() const;
    unsigned long long getISBN() const;
    bool isAvailable() const;

private:
    std::string title;
    std::string author;
    unsigned long long ISBN; // International Standard Book Number.
    bool available;
};

// Parameterized constructor implementation.
Book::Book(std::string const& title, std::string const& author,
    unsigned long long ISBN, bool available)
    : title(title), author(author), ISBN(ISBN), available(available) {}

// Method implementations
void Book::checkIn() { available = true; }
void Book::checkOut() { available = false; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
unsigned long long Book::getISBN() const { return ISBN; }
bool Book::isAvailable() const { return available; }

class Library
{
public:
    // Method to get a singleton instance.
    static Library& getInstance() {
        static Library instance;
        return instance;
    }

    Library(const Library&) = delete;
    Library& operator=(const Library&) = delete;

    void addBook(const Book& book) {
        books.push_back(book);
    }

    void showBooks() const {
        std::cout << "============================================================================================\n";
        std::cout << "                                       My Library\n";
        std::cout << "============================================================================================\n";



        for (const auto& book : books) {
            std::cout << std::left;
            std::cout << std::setw(15) << "Title: " << book.getTitle() << "\n";
            std::cout << std::setw(15) << "Author: " << book.getAuthor() << "\n";
            std::cout << std::setw(15) << "ISBN: " << book.getISBN() << "\n";
            std::cout << std::setw(15) << "Available: " << (book.isAvailable() ? "Yes" : "No") << "\n";
            std::cout << "--------------------------------------------------------------------------------------------\n";
        }

        std::cout << "============================================================================================\n";

    }

    void sortBooksByTitle() {
        std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.getTitle() < b.getTitle();
        });
    }

    void sortBooksByAuthor() {
        std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.getAuthor() < b.getAuthor();
            });
    }

    void sortBooksByISBN() {
        std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.getISBN() < b.getISBN();
            });
    }

private:
    Library() = default;

    std::vector<Book> books; // List of books in the library.
};

class Member
{
public:
    Member();
private:
};

Member::Member() { }

int main() {
    // Example usage
    Library& library = Library::getInstance();
    library.addBook(Book("1984", "George Orwell", 1234567890123, true));
    library.addBook(Book("Brave New World", "Aldous Huxley", 9876543210987, false));
    library.addBook(Book("A Very Long Title That Exceeds The Set Width", "Johnathan Longname", 9780134192480, true));
    library.addBook(Book("C++ Programming Language", "Bjarne Stroustrup", 9780321992789, false));
    library.addBook(Book("Understanding Machine Learning: From Theory to Algorithms", "Shai Shalev-Shwartz and Shai Shalev-Shwartz", 9781108445570, true));
    library.addBook(Book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 9780345391803, true));
    library.addBook(Book("Harry Potter and the Philosopher's Stone", "J.K. Rowling", 9780747532699, false));
    library.addBook(Book("A Brief History of Time", "Stephen Hawking", 9780553380163, true));
    library.addBook(Book("War and Peace", "Leo Tolstoy", 9780198800545, true));
    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 9780316769488, false));
    library.addBook(Book("The Lord of the Rings: The Fellowship of the Ring", "J.R.R. Tolkien", 9780618123476, true));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 9780061120084, true));
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 9780743273565, true));
    library.addBook(Book("Moby Dick", "Herman Melville", 9781503280786, false));
    library.addBook(Book("Pride and Prejudice", "Jane Austen", 9781503290563, true));
    library.addBook(Book("The Picture of Dorian Gray", "Oscar Wilde", 9780141439570, true));
    library.addBook(Book("Catch-22", "Joseph Heller", 9781451626650, false));
    library.addBook(Book("The Brothers Karamazov", "Fyodor Dostoevsky", 9780374528379, true));
    library.addBook(Book("The Alchemist", "Paulo Coelho", 9780062315007, true));
    library.addBook(Book("A Tale of Two Cities", "Charles Dickens", 9781515111553, false));
    library.addBook(Book("The Sound and the Fury", "William Faulkner", 9780679732259, true));
    library.addBook(Book("Crime and Punishment", "Fyodor Dostoevsky", 9780486415871, true));
    library.addBook(Book("The Grapes of Wrath", "John Steinbeck", 9780143039433, false));
    library.addBook(Book("Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 9780062316097, true));
    library.addBook(Book("The Silent Patient", "Alex Michaelides", 9781250233655, true));
    library.addBook(Book("The Subtle Art of Not Giving a F*ck", "Mark Manson", 9780062457714, false));
    library.addBook(Book("Educated: A Memoir", "Tara Westover", 9780399590504, true));
    library.addBook(Book("Becoming", "Michelle Obama", 9781524763138, true));
    library.addBook(Book("Where the Crawdads Sing", "Delia Owens", 9780735219113, false));
    library.addBook(Book("The Midnight Library", "Matt Haig", 9780525559474, true));
    library.addBook(Book("Atomic Habits: An Easy & Proven Way to Build Good Habits & Break Bad Ones", "James Clear", 9780735211292, true));
    library.addBook(Book("The Vanishing Half", "Brit Bennett", 9780525536963, false));
    library.addBook(Book("The Body Keeps the Score: Brain, Mind, and Body in the Healing of Trauma", "Bessel van der Kolk", 9780670785933, true));
    library.addBook(Book("The Five Love Languages: How to Express Heartfelt Commitment to Your Mate", "Gary Chapman", 9780802412706, true));
    library.showBooks();

    // Sort by Title
    std::cout << "Library sorted by title:\n";
    library.sortBooksByTitle();
    library.showBooks();

    // Sort by author
    std::cout << "Library sorted by author:\n";
    library.sortBooksByAuthor();
    library.showBooks();

    // Sort by ISBN
    std::cout << "Library sorted by ISBN:\n";
    library.sortBooksByISBN();
    library.showBooks();

    return 0;
}
