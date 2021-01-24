import time
from datetime import date


dat = date(2013, 5, 29)
wday = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']
print('May 29, 2013', wday[dat.weekday()])
