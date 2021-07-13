from datetime import datetime


def calculate_age():
    birth_date = datetime(2000, 11, 21)
    cur_date = datetime.now()
    delta = (cur_date-birth_date).days
    return(delta, (int)(delta/30), (int)(delta/365))


res = calculate_age()
print("day={},month={},year={}".format(res[0], res[1], res[2]))
