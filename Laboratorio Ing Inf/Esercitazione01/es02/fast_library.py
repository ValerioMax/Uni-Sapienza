from typing import Dict, List
from book import Book

class FLibrary:

    book_list: List[Book] = []
    author_to_book: Dict[str, List[Book]] = {}
    date_to_book: Dict[int, List[Book]] = {}

    def __init__(self):
        pass

    def add_book(self, book):
        self.book_list.append(book)

        if book.author not in self.author_to_book:
            self.author_to_book[book.author] = []
        self.author_to_book[book.author].append(book)

        if book.date not in self.date_to_book:
            self.date_to_book[book.date] = []
        self.date_to_book[book.date].append(book)

    def show_books(self):
        for book in self.book_list:
            print(book)

    def find_books_by_author(self, author):
        l = self.author_to_book.get(author)
        if l == None:
            return []
        return l

    def find_books_by_year(self, date):
        l = self.date_to_book.get(date)
        if l == None:
            return []
        return l
