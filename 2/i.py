import datetime

t = int(input())

moth = [
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
]

for i in range(t):
    year, month, day = input().split('-')

    year = int(year)
    month = moth.index(month)+1
    day = int(day)


    k = int(input())

    date = datetime.datetime(year, month, day)
    time = datetime.timedelta(k)

    date += time

    print(f"Case {i+1}: {date.year}-{moth[date.month-1]}-{date.day if date.day > 9 else '0'+str(date.day)}")