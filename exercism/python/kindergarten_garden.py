class Garden:
    PLANT_MAP = {
        'G': 'Grass',
        'C': 'Clover',
        'R': 'Radishes',
        'V': 'Violets'
    }

    DEFAULT_STUDENTS = [
        "Alice", "Bob", "Charlie", "David", "Eve", "Fred",
        "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"
    ]

    def __init__(self, diagram, students=None):
        self._rows = diagram.split('\n')
        
        if students is None:
            self._students = sorted(self.DEFAULT_STUDENTS)
        else:
            self._students = sorted(students)

    def plants(self, student):
        idx = self._students.index(student)
        start_pos = idx * 2
        
        row1_plants = self._rows[0][start_pos : start_pos + 2]
        row2_plants = self._rows[1][start_pos : start_pos + 2]
        
        student_letters = row1_plants + row2_plants
        
        return [self.PLANT_MAP[letter] for letter in student_letters]