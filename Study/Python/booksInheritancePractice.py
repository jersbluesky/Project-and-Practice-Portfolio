# Jer Johnson
# Week 06  - Prepare : Checkpoint A
# CS241 - Brother Meller
# 2-8-2022

"""Book class is the parent class. It applies to all other classes below."""
class Book():
    """Initialize the three attributes"""   
    def __init__(self, title, author, publication_year):
        self.title = str(title)
        self.author = str(author)
        self.publication_year = int(publication_year)
    """Get info from the user"""
    def prompt_book_info(self):
        self.title = input("Title: ")
        self.author = input("Author: ")
        self.publication_year = input("Publication Year: ")
    """Display the information"""
    def display(self):
        print (f'{self.title} ({self.publication_year}) by {self.author}')

"""This is a child class of the book class."""
class TextBook(Book):
    """This has inherited the title, author, and publication attributes.
        It adds the subject attribute."""
    def __init__(self, subject):    
        super().__init__("", "", 0)
        self.subject = str(subject)
    """The other methods are inherited. We need to add the subject prompt."""
    def prompt_subject(self):
        self.subject = input("Subject: ")
    """This displays the subject."""
    def display(self):
        print (f'{self.title} ({self.publication_year}) by {self.author}')
        print (f'Subject: {self.subject}')

"""This inherits from the parent class, Book, including its methods and attributes."""
class PictureBook(Book):
    """This won't take anything from Textbook, but takes from Book. It's a picture
    book, but it adds the illustrator attribute."""
    def __init__(self, illustrator):    
        super().__init__("", "", 0)
        self.illustrator = str(illustrator)
    """Method to prompt the illustrator."""
    def prompt_illustrator(self):
        self.illustrator = input("Illustrator: ")
    """Method to display the illustrator."""
    def display(self):
        print (f'{self.title} ({self.publication_year}) by {self.author}')
        print (f'Illustrated by {self.illustrator}')
        
def main():
    book = Book("", "", 0)
    textbook = TextBook("")
    picturebook = PictureBook("")
    book.prompt_book_info()
    print("")
    book.display()
    print("")
    textbook.prompt_book_info()
    textbook.prompt_subject()
    print("")
    textbook.display()
    print("")
    picturebook.prompt_book_info()
    picturebook.prompt_illustrator()
    print("")
    picturebook.display()


if __name__ == "__main__":
    main()