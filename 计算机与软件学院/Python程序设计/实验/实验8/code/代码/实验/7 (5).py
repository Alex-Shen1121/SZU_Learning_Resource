import time as T


class Time:
    def __init__(self) -> None:
        self.__time = T.time()
        time = T.localtime(self.__time)
        self.__hour = time.tm_hour
        self.__minute = time.tm_min
        self.__second = time.tm_sec

    def getHour(self):
        return self.__hour

    def getMinute(self):
        return self.__minute

    def getSecond(self):
        return self.__second

    def setTime(self, elapseTime):
        Time = T.localtime(self.__time+int(elapseTime))
        self.__hour = Time.tm_hour
        self.__minute = Time.tm_min
        self.__second = Time.tm_sec

    def __str__(self) -> str:
        return "时间是：{:02d}：{:02d}：{:02d}".format(self.__hour, self.__minute, self.__second)


myTime = Time()
print("Hour:{:02d}".format(myTime.getHour()))
print("Minute:{:02d}".format(myTime.getMinute()))
print("Second:{:02d}".format(myTime.getSecond()))
print(myTime)
myTime.setTime(20)
print(myTime)
