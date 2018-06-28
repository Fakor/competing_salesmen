

class Salesman:
    def __init__(self, start_position, color, score=0):
        self.trajectory = [start_position]
        self.score = score
        self.color = color

    def last_position(self):
        return self.trajectory[-1]

    def update_status(self, x, y, score):
        self.trajectory.append([x, y, score != self.score])
        self.score = score
