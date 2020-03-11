class RecentCounter:
    import queue
    def __init__(self):
        self.Q = []
        self.minIdex = 0

    def ping(self, t: int) -> int:
        if(len(self.Q)==0):
            self.Q.append(t)
            return 1
        else:
            self.Q.append(t)
            while(t - self.Q[self.minIdex] > 3000):
                self.Q.pop(0)
            return len(self.Q)
