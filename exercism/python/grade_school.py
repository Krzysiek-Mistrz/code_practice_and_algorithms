class School:
    def __init__(self):
        self.db = {}
        self.add_history = []

    def add_student(self, name, grade):
        for students in self.db.values():
            if name in students:
                self.add_history.append(False)
                return "Incorrect"
        
        if grade not in self.db:
            self.db[grade] = []
            
        self.db[grade].append(name)
        self.add_history.append(True)

    def roster(self):
        full_roster = []
        
        for g in sorted(self.db.keys()):
            full_roster.extend(sorted(self.db[g]))
        
        return full_roster

    def grade(self, grade_number):
        if grade_number not in self.db:
            return []
        
        return sorted(self.db[grade_number])

    def added(self):
        return self.add_history