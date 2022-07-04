# Jer Johnson
# 03 Prove: Assignment
# CS241 - Brother Meller
# 1-24-2022

# First, we need to create the class
class Robot():
    
    # Here, we set the initial state of the object with its variables, including
    # prompting it to consider the variables to be applied to itself with the 'self'
    # parameter.
    def __init__(self, xCoordinate, yCoordinate, fuelLevel):
        self.xCoordinate = xCoordinate
        self.yCoordinate = yCoordinate
        self.fuelLevel = fuelLevel
        
    # Below, we define functions within the object as prompted by the instructions
    # of the assignment. We use simple logical statements to decrease the fuel levels,
    # increase or decrease the x or y coordinates, display messages, or deny the user
    # from being able to do those things if the fuel level has reached zero. 
    def moveRight(self):
        if(self.fuelLevel <= 4):
            print("Insufficient fuel to perform action")
        else:
            self.xCoordinate += 1
            self.fuelLevel -= 5
        return
            
    def moveUp(self):
        if(self.fuelLevel <= 4):
            print("Insufficient fuel to perform action")
        else:
            self.yCoordinate -= 1
            self.fuelLevel -= 5
        return
            
    def moveLeft(self):
        if(self.fuelLevel <= 4):
            print("Insufficient fuel to perform action")
        else:
            self.xCoordinate -= 1
            self.fuelLevel -= 5
        return
            
    def moveDown(self):
        if(self.fuelLevel <= 4):
            print("Insufficient fuel to perform action")
        else:
            self.yCoordinate += 1
            self.fuelLevel -= 5
        return
            
    def fireLasers(self):
        if(self.fuelLevel <= 14):
            print("Insufficient fuel to perform action")
        else:
            print("Pew! Pew!")
            self.fuelLevel -=15              
        return
            
    def showStatus(self):
        print(f'({self.xCoordinate}, {self.yCoordinate}) - Fuel: {self.fuelLevel}')
        return

# The class and object is created with its functions, but it has been called yet. 
# This is done in the main section. Robot Jetsam is created by calling the class,
# and his variables are set as prescribed. Each function is called within a logical
# if/then statement, allowing the user to enter quit to end the program or otherwise
# manipulate the variables per the limitations of the functions.       
def main():
    robotJetsam = Robot(10,10,100)
    command = " "
    while (command != "quit"):
        command = input("Enter command: ")  
        if (command == "right"):
            robotJetsam.moveRight()
        elif (command == "up"):
            robotJetsam.moveUp()
        elif (command == "left"):
            robotJetsam.moveLeft()
        elif (command == "down"):
            robotJetsam.moveDown()
        elif (command == "fire"):
            robotJetsam.fireLasers()
        elif (command == "status"):
            robotJetsam.showStatus()
        elif (command == "quit"):
            print("Goodbye.")
        
if __name__ == "__main__":
    main()    