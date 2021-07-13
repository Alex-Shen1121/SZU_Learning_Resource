from datetime import datetime
from dateutil.relativedelta import relativedelta


def calculate_age():
    birth_date = datetime(2000, 11, 21)
    now_date = datetime.now()
    delta = now_date-birth_date
    print(delta.days)

calculate_age()
