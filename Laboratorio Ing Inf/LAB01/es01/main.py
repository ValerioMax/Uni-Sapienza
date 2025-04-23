from book import Book
from library import Library

def main():
    # create some book
    book1 = Book("1984","George Orwell", 1949, "Distopia")
    book2 = Book("Il nome della rosa","Umberto Eco", 1980, "Storico")
    book3 = Book("Orgoglio e pregiudizio","Jane Austen", 1813, "Romanzo")

    # create a library
    library = Library()

    # add those books in the library
    library.add_book(book1)
    library.add_book(book2)
    library.add_book(book3)

    # show the books in the library
    library.show_books()

    # search by author
    print("\nLibri di George Orwell:")
    for book in library.find_books_by_author("George Orwell"):
        print(book)

    # search by year
    print("\nLibri del 1980:")
    for book in library.find_books_by_year(1980):
        print(book)

if __name__ == "__main__":
    main()