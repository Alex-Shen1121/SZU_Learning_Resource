class China:
    def __init__(self, given, family):
        self.given = given
        self.family = family
    def __str__(self):
        return self.given + ' ' + self.family + '\n' + self.get_description()
    def get_description(self):
        return 'From China'
    def execute(self):
        print(self.family)


class Guangdong(China):
    def __init__(self):
        China.__init__(self, 'Ming', 'Li')


class England(China):
    def __init__(self):
        China.__init__(self, 'David', 'Beckham')
    def get_description(self):
        return 'From England'


def test_person(person):
    print(person)


ming = Guangdong()
ming.execute()
test_person(ming)
test_person(England())
