from collections import deque
from pickle import FALSE

class Student:
    
    def __init__(self, name, course):
        self.name = str(name)
        self.course = str(course)
    
    def prompt(self):
        pass
    
    def display(self):
        pass
    
class HelpSystem(Student):
    
    def __init__(self):
        super().__init__(Student)
    
    def is_student_waiting(self):
        pass
    
    def add_to_waiting_list(self, Student):
        pass
    
    def help_next_student():
        pass
        
            

def main():
    option = 0
    
    while option != 3:
        print("1. Add a new student\n"
              "2. Help next student\n"
              "3. Quit\n"
        )
        option = int(input("Enter selection: "))
        if int(option) == 1:
            song.title = input("Enter the title: ")
            song.artist = input("Enter the artist: ")
            songs.append(song)
            print("")
        elif int(option) == 2:
            song.title = input("Enter the title: ")
            song.artist = input("Enter the artist: ")
            songs.appendleft(song)
            print("")
        elif int(option) == 3:
            if not songs:
                print("The playlist is currently empty.\n")
            else:
                # for i in songs:
                #     print(i)
                print("\nPlaying song:")
                song.display()
                songs.pop()
        elif int(option) == 4:
            pass
            
            
                       

        
        
        
if __name__ == "__main__":
    main()