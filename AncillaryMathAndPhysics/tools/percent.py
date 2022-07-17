class Percent(float):
    def __str__(self):
        return '{:.2%}'.format(self)