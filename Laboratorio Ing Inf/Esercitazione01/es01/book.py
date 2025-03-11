class Book:
    def __init__(self, title, author, date, genre):
        self.title = title
        self.author = author
        self.date = date
        self.genre = genre
    
    def __str__(self):
        return self.title + ", " + self.author + ", " + str(self.date) + ", " + self.genre
