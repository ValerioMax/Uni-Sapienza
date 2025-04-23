from book import Book
from library import Library
from fast_library import FLibrary
import random
from time import perf_counter

NUM_BOOKS = 100000

def main():
    library1 = FLibrary()
    library2 = Library()

    for i in range(0, NUM_BOOKS):
        library1.add_book(Book(f"title{random.randint(0, NUM_BOOKS)}",
                              f"author{random.randint(0, NUM_BOOKS)}",
                              random.randint(0, NUM_BOOKS),
                              f"genre{random.randint(0, NUM_BOOKS)}"))
        
        library2.add_book(Book(f"title{random.randint(0, NUM_BOOKS)}",
                              f"author{random.randint(0, NUM_BOOKS)}",
                              random.randint(0, NUM_BOOKS),
                              f"genre{random.randint(0, NUM_BOOKS)}"))

    #library1.show_books()
    #library2.show_books()

    start_time = perf_counter()
    l = library1.find_books_by_author("author3")
    end_time = perf_counter()
    diff1 = end_time - start_time

    start_time = perf_counter()
    l = library2.find_books_by_author("author3")
    end_time = perf_counter()
    diff2 = end_time - start_time
    
    print(f"Implementation 1 took {diff1} sec.")
    print(f"Implementation 2 took {diff2} sec.")

if __name__ == "__main__":
    main()