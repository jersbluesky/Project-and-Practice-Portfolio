"""
File: skeet.py
Original Author: Br. Burton
Designed to be completed by others

This program implements an awesome version of skeet.
"""
import arcade
import math
import random

# These are Global constants to use throughout the game
SCREEN_WIDTH = 600
SCREEN_HEIGHT = 400

RIFLE_WIDTH = 100
RIFLE_HEIGHT = 20
RIFLE_COLOR = arcade.color.BLACK

BULLET_RADIUS = 3
BULLET_COLOR = arcade.color.BLACK_OLIVE
BULLET_SPEED = 10

TARGET_RADIUS = 20
TARGET_COLOR = arcade.color.RED
TARGET_SAFE_COLOR = arcade.color.GREEN
TARGET_STRONG_COLOR = arcade.color.AMARANTH_PINK

""" Create a point to call at various moments in the program """
class Point:
    def __init__(self):
        self.x = 0.00
        self.y = 0.00
        
"""
The Velocity class is designed to create a starting point for velocity moving on both
the x and y coordinates. 
"""
class Velocity:
    def __init__(self):
        self.dx = 0.00
        self.dy = 0.00


"""Rifle is where the bullet come out, Billy."""
class Rifle:
    """
    The rifle is a rectangle that tracks the mouse.
    """
    def __init__(self):
        self.center = Point()
        self.center.x = 0
        self.center.y = 0

        self.angle = 45

    def draw(self):
        arcade.draw_rectangle_filled(self.center.x, self.center.y, RIFLE_WIDTH, RIFLE_HEIGHT, RIFLE_COLOR, 360-self.angle)

""" This is the flying object class, which can be applied to bullets, targets, witches, and beach balls. """
class FlyingObject():
    def __init__(self):
        """ Initialize the function"""
        self.center = Point() 
        self.velocity = Velocity()
        """Called in both the point and Velocity from their respective classes. 
        Generic classes are useful in saving lines of code."""
        self.alive = True
    
    def draw(self):
        """ We are passing here, because each object is drawn differently, and because
        Brother Mellor said to."""
        pass
    
    def advance(self):
        """Simple velocity, adds to the point of the object at a defined refresh-rate"""
        self.center.y += self.velocity.dy
        self.center.x += self.velocity.dx
    
    def is_off_screen(self, w, h):
        """ If the object is off-screen, it must die. AAAAAaaarrrrrgggghhhh"""
        if self.center.x > w or self.center.x < 0 or self.center.y > h or self.center.y < 0:
            return True
        else:
            return False

class Bullet(FlyingObject):
    def __init__(self):
        """ We both initialized the Class and super initialize to call on methods
        from other classes."""
        super().__init__()
        
        """We are only adding the parameters that are required for this class. We 
        don't need to add those that are in the FlyingObject class, because we 
        inherited the required methods and parameters."""
        
        self.radius = BULLET_RADIUS
        self.color = BULLET_COLOR
        self.angle = 45
        self.time = 0
        
    def draw(self):
        """Simple draw function, awesome feature in the arcade library!"""
        arcade.draw_circle_filled(self.center.x, self.center.y, self.radius, self.color)
    
    def fire(self, angle):
        """I did it this way so that the bullet would eject with the angle of the rifle."""
        self.velocity.dx = math.cos(math.radians(angle)) * BULLET_SPEED
        self.velocity.dy = math.sin(math.radians(angle)) * BULLET_SPEED
        
        self.center.y = RIFLE_WIDTH * math.sin(math.radians(angle))
        self.center.x = RIFLE_WIDTH * math.sin(math.radians(angle))
    
class Target(FlyingObject):
    """The notes on this would be similar to the bullet. Inherit what we need,
    change or add what needs to be changed or added. I'm very tired."""
    def __init__(self):
        super().__init__()
        self.center.x = 0
        self.center.y = random.uniform(SCREEN_HEIGHT / 2, SCREEN_HEIGHT)
        self.velocity.dx = random.uniform(1, 5)
        self.velocity.dy = random.uniform(-2, 5)
        self.score = 0


"""Target is the proud father of three sub-targets, starting with little Standard_Target. 
   While he's not the sharpest tool in the shed (he's a circle), his tax refund value is
   a 1 point. """
class Standard_Target(Target):
    def __init__(self):
        super().__init__()
        self.radius = TARGET_RADIUS
        self.color = TARGET_COLOR

    def draw(self):
        arcade.draw_circle_filled(self.center.x, self.center.y, self.radius, self.color, 0, -1)
        
    def hit(self):
        self.score = 1
        self.alive = False
        return self.score
    
    def advance(self):
        self.center.y += self.velocity.dy
        self.center.x += self.velocity.dx
    

"""Safe target is untouchable. Drawn from arcade draw rectangle filled, if you hit him, you
lose 10 points. Guess we know whose the favorite of the Target family."""
class Safe_Target(Target):
    def __init__(self):
        super().__init__()
        self.color = TARGET_SAFE_COLOR
        self.radius = TARGET_RADIUS
    
    def draw(self):
        arcade.draw_rectangle_filled(self.center.x, self.center.y, 50.00, 50.00, self.color)
        
    def hit(self):
        self.score = -10
        self.alive = False
        return self.score
    
    def advance(self):
        self.center.y += self.velocity.dy
        self.center.x += self.velocity.dx

"""Strong target can really take a hit. He has 3 lives. If you take away the first and second, he
   loses on life and you get one point each time. If you hit him a third time, he's dead as a 
   doornail, and you get 5 whole points you sick freak."""
class Strong_Target(Target):
    def __init__(self):
        super().__init__()
        self.lives = 3
        self.velocity.dx = random.uniform(1, 3)
        self.velocity.dy = random.uniform(-2, 3)
        self.color = TARGET_STRONG_COLOR
        self.radius = TARGET_RADIUS

    
    def draw(self):
        arcade.draw_circle_outline(self.center.x, self.center.y, self.radius, self.color, 2)
        text_x = self.center.x - (self.radius / 2)
        text_y = self.center.y - (self.radius / 2)
        arcade.draw_text(repr(self.lives), text_x, text_y, self.color, font_size=20)
        
# first hit - Remove 1 life, add 1 point
# second hit - remove 1 life, add 1 point
# third hit - self.alive = False, add 5 points

    """The hit is defined below in a simple if-then statement."""
    def hit(self):
        if self.lives == 3:
            self.score = 1
            self.lives -=1
            return self.score
        elif self.lives == 2:
            self.score = 1
            self.lives -=1
            return self.score
        elif self.lives == 1:
            self.score = 5
            self.alive = False
            return self.score

    """The advance function continues to be the same basic math, adding move at a defined speed"""
    def advance(self):
        self.center.y += self.velocity.dy
        self.center.x += self.velocity.dx
        

class Game(arcade.Window):
    """
    This class handles all the game callbacks and interaction
    It assumes the following classes exist:
        Rifle
        Target (and it's sub-classes)
        Point
        Velocity
        Bullet

    This class will then call the appropriate functions of
    each of the above classes.

    You are welcome to modify anything in this class, but mostly
    you shouldn't have to. There are a few sections that you
    must add code to.
    """

    def __init__(self, width, height):
        """
        Sets up the initial conditions of the game
        :param width: Screen width
        :param height: Screen height
        """
        super().__init__(width, height)

        self.rifle = Rifle()
        self.target = Target()
        self.score = 0

        self.bullets = []
        """Yup, totally added this. Go me."""
        self.targets = []


        arcade.set_background_color(arcade.color.WHITE)

    def on_draw(self):
        """
        Called automatically by the arcade framework.
        Handles the responsibility of drawing all elements.
        """

        # clear the screen to begin drawing
        arcade.start_render()

        # draw each object
        self.rifle.draw()

        for bullet in self.bullets:
            bullet.draw()

        for target in self.targets: 
            target.draw()


        self.draw_score()

    def draw_score(self):
        """
        Puts the current score on the screen
        """
        score_text = "Score: {}".format(self.score)
        start_x = 10
        start_y = SCREEN_HEIGHT - 20
        arcade.draw_text(score_text, start_x=start_x, start_y=start_y, font_size=12, color=arcade.color.NAVY_BLUE)

    def update(self, delta_time):
        """
        Update each object in the game.
        :param delta_time: tells us how much time has actually elapsed
        """
        self.check_collisions()
        self.check_off_screen()

        # decide if we should start a target
        if random.randint(1, 50) == 1:
            self.create_target()

        """The advance method needs to be called in order for the bullets
        and targets to move. The following accomplishes that with for-loops."""
        for bullet in self.bullets:
            bullet.advance()
            
        for target in self.targets:
            target.advance()
            
    
    """This method determines which target will be created by using a random number
    generator along with an if/elif statement"""
    def create_target(self):
                
        random_number = random.randint(1, 3)
        
        if random_number == 1:
            tar = Standard_Target()
        elif random_number == 2:
            tar = Strong_Target()
        elif random_number == 3:
            tar = Safe_Target()         
        
        
        
        """
        Creates a new target of a random type and adds it to the list.
        """
        self.targets.append(tar)

    def check_collisions(self):
        """
        Checks to see if bullets have hit targets.
        Updates scores and removes dead items.
        :return:
        """

        # NOTE: This assumes you named your targets list "targets"

        for bullet in self.bullets:
            for target in self.targets:

                # Make sure they are both alive before checking for a collision
                if bullet.alive and target.alive:
                    too_close = bullet.radius + target.radius

                    if (abs(bullet.center.x - target.center.x) < too_close and
                                abs(bullet.center.y - target.center.y) < too_close):
                        # its a hit!
                        bullet.alive = False
                        self.score += target.hit()

                        # We will wait to remove the dead objects until after we
                        # finish going through the list

        # Now, check for anything that is dead, and remove it
        self.cleanup_zombies()

    def cleanup_zombies(self):
        """
        Removes any dead bullets or targets from the list.
        :return:
        """
        for bullet in self.bullets:
            if not bullet.alive:
                self.bullets.remove(bullet)

        for target in self.targets:
            if not target.alive:
                self.targets.remove(target)

    def check_off_screen(self):
        """
        Checks to see if bullets or targets have left the screen
        and if so, removes them from their lists.
        :return:
        """
        for bullet in self.bullets:
            if bullet.is_off_screen(SCREEN_WIDTH, SCREEN_HEIGHT):
                self.bullets.remove(bullet)

        for target in self.targets:
            if target.is_off_screen(SCREEN_WIDTH, SCREEN_HEIGHT):
                self.targets.remove(target)

    def on_mouse_motion(self, x: float, y: float, dx: float, dy: float):
        # set the rifle angle in degrees
        self.rifle.angle = self._get_angle_degrees(x, y)

    def on_mouse_press(self, x: float, y: float, button: int, modifiers: int):
        # Fire!
        angle = self._get_angle_degrees(x, y)

        bullet = Bullet()
        bullet.fire(angle)

        self.bullets.append(bullet)

    def _get_angle_degrees(self, x, y):
        """
        Gets the value of an angle (in degrees) defined
        by the provided x and y.

        Note: This could be a static method, but we haven't
        discussed them yet...
        """
        # get the angle in radians
        angle_radians = math.atan2(y, x)

        # convert to degrees
        angle_degrees = math.degrees(angle_radians)

        return angle_degrees

# Creates the game and starts it going
window = Game(SCREEN_WIDTH, SCREEN_HEIGHT)
arcade.run()