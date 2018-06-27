

class Salesman:
    def __init__(self, start_position, score=0):
        self.trajectory = [start_position]
        self.score = score

    def last_position(self):
        return self.trajectory[-1]

    def new_position(self, x, y):
        self.trajectory.append([x, y])
