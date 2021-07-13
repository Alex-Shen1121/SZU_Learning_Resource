class stack:
    def __init__(self, size) -> None:
        self.content = []
        self.size = size
        self.current = 0

    def isempty(self):
        return self.current == 0 and len(self.content) == 0

    def empty(self):
        self.current = 0
        self.content.clear()

    def setSize(self, new_size):
        if new_size < self.size:
            self.content = self.content[:new_size]
            self.current = new_size
        self.size = new_size

    def isFull(self):
        return self.current == self.size

    def push(self, ele):
        if not self.isFull():
            self.content.append(ele)
            self.current += 1
        else:
            print("非法操作")

    def pop(self):
        if not self.isempty():
            self.content.pop()
            self.current -= 1
        else:
            print("非法操作")

    def show(self):
        print(self.content)


myStack = stack(5)
# print(myStack.isempty())
# myStack.pop()
myStack.push(1)
myStack.push(2)
myStack.pop()
myStack.show()
# myStack.push(3)
# myStack.push(4)
# myStack.push(5)
# myStack.show()
# print(myStack.isFull())
# myStack.push(1)
# myStack.show()
# myStack.setSize(3)
# myStack.show()
# print("current =", myStack.current)
# print("size =", myStack.size)
# myStack.setSize(6)
# myStack.show()
# print("current =", myStack.current)
# print("size =", myStack.size)
# myStack.pop()
# myStack.pop()
# myStack.pop()
# myStack.pop()
# print(myStack.isempty())
