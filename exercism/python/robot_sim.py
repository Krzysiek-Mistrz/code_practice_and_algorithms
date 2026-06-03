NORTH = 0
EAST = 1
SOUTH = 2
WEST = 3


class Robot:
    def __init__(self, direction=NORTH, x_pos=0, y_pos=0):
        self.direction = direction
        self.x_pos = x_pos
        self.y_pos = y_pos

    @property
    def coordinates(self):
        return (self.x_pos, self.y_pos)

    def move(self, instructions):
        for instruction in instructions:
            if instruction == "R":
                self.direction = (self.direction + 1) % 4
                
            elif instruction == "L":
                self.direction = (self.direction - 1) % 4
                
            elif instruction == "A":
                if self.direction == NORTH:
                    self.y_pos += 1
                elif self.direction == EAST:
                    self.x_pos += 1
                elif self.direction == SOUTH:
                    self.y_pos -= 1
                elif self.direction == WEST:
                    self.x_pos -= 1