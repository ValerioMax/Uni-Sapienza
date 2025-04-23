class Library:

    book_list = []

    def __init__(self):
        pass

    def add_book(self, book):
        self.book_list.append(book)

    def show_books(self):
        for book in self.book_list:
            print(book)

    def find_books_by_author(self, author):
        l = []

        for book in self.book_list:
            if book.author == author:
                l.append(book)

        return l

    def find_books_by_year(self, date):
        l = []

        for book in self.book_list:
            if book.date == date:
                l.append(book)

        return l
