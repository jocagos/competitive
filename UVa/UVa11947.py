from datetime import datetime
from datetime import timedelta
import sys

def getZod(s):
    if ( s.day >= 21 and s.month == 1 ) or ( s.day <= 19 and s.month == 2 ):
        return "aquarius"
    elif ( s.day >= 20 and s.month == 2 ) or ( s.day <= 20 and s.month == 3 ):
        return "pisces"
    elif ( s.day >= 21 and s.month == 3 ) or ( s.day <= 20 and s.month == 4 ):
        return "aries"
    elif ( s.day >= 21 and s.month == 4 ) or ( s.day <= 21 and s.month == 5 ):
        return "taurus"
    elif ( s.day >= 22 and s.month == 5 ) or ( s.day <= 21 and s.month == 6 ):
        return "gemini"
    elif ( s.day >= 22 and s.month == 6 ) or ( s.day <= 22 and s.month == 7 ):
        return "cancer"
    elif ( s.day >= 23 and s.month == 7 ) or ( s.day <= 21 and s.month == 8 ):
        return "leo"
    elif ( s.day >= 22 and s.month == 8 ) or ( s.day <= 23 and s.month == 9 ):
        return "virgo"
    elif ( s.day >= 24 and s.month == 9 ) or ( s.day <= 23 and s.month == 10 ):
        return "libra"
    elif ( s.day >= 24 and s.month == 10 ) or ( s.day <= 22 and s.month == 11 ):
        return "scorpio"
    elif ( s.day >= 23 and s.month == 11 ) or ( s.day <= 22 and s.month == 12 ):
        return "sagittarius"
    elif ( s.day >= 23 and s.month == 12 ) or ( s.day <= 20 and s.month == 1 ):
        return "capricorn"

t = int(sys.stdin.readline())
for i in range(1, t+1):
    line = sys.stdin.readline()
    d = datetime(int(line[4:]), int(line[0:2]), int(line[2:4]) )
    d = d + timedelta(days=280)
    zodiac = getZod(d)
    days = str(d.day)
    month = str(d.month)
    if len(days) == 1:
        days = "0" + days
    if len(month) == 1:
        month = "0" + month
    print(i, month + "/" + days + "/" + str(d.year), zodiac)
