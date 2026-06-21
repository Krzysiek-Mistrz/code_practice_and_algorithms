class Matrix:
    def __init__(self, matrix_string):
        self._rows = [
            [int(num) for num in line.split()]
            for line in matrix_string.splitlines()
        ]

    def row(self, index):
        return list(self._rows[index - 1])

    def column(self, index):
        return [row[index - 1] for row in self._rows]