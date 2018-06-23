

class SalesmanTrajectory:
    def __init__(self, start_position):
        self.trajectory = [start_position]

    def last_position(self):
        return self.trajectory[-1]

    def new_position(self, x, y):
        self.trajectory.append([x, y])
