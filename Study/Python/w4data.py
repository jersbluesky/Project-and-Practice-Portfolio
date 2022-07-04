from collections import deque
from pickle import FALSE

class Song:
    
    def __init__(self):
        self.title = ""
        self.artist = ""
    
    def display(self):
        print(f'{self.title} by {self.artist}')
        
        
def main():
    option = 0
    song = Song()
    songs = deque()
    
    while option != 4:
        print("1. Add a new song to the end of the playlist\n"
              "2. Insert a new song to the beginning of the playlist\n"
              "3. Play the next song\n"
              "4. Quit\n"
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