import calendar
from datetime import date


class MeetupDayException(ValueError):
    """Exception raised when the Meetup weekday and count do not result in a valid date."""
    
    def __init__(self, message):
        self.message = message
        super().__init__(self.message)


def meetup(year, month, week, day_of_week):
    # Słownik do mapowania angielskich nazw dni tygodnia na numery Pythona (Monday=0, Sunday=6)
    
    days_mapping = {
        "Monday": 0, "Tuesday": 1, "Wednesday": 2, 
        "Thursday": 3, "Friday": 4, "Saturday": 5, "Sunday": 6
    }
    
    target_day_of_week = days_mapping[day_of_week]
    matching_days = []
    
    for week_list in calendar.monthcalendar(year, month):
        day = week_list[target_day_of_week]
        if day != 0:
            matching_days.append(day)
    
    try:
        if week == "first":
            chosen_day = matching_days[0]
        elif week == "second":
            chosen_day = matching_days[1]
        elif week == "third":
            chosen_day = matching_days[2]
        elif week == "fourth":
            chosen_day = matching_days[3]
        elif week == "fifth":
            if len(matching_days) < 5:
                raise MeetupDayException("That day does not exist.")
            chosen_day = matching_days[4]
        elif week == "last":
            chosen_day = matching_days[-1]
        elif week == "teenth":
            chosen_day = None
            
            for d in matching_days:
                if 13 <= d <= 19:
                    chosen_day = d
                    break
        else:
            raise MeetupDayException("That day does not exist.")
        
        return date(year, month, chosen_day)
        
    except IndexError:
        raise MeetupDayException("That day does not exist.")