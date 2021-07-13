class SM:
    start_state = None

    def transition_fn(self, s, x):
        raise NotImplementedError

    def output_fn(self, s):
        raise NotImplementedError

    def transduce(self, input_seq):
        ans = []
        for input in input_seq:
            self.start_state = self.transition_fn(
                self.start_state, input)
            ans.append(self.output_fn(self.start_state))
        return ans


class Accumulator(SM):
    start_state = 0

    def transition_fn(self, s, x):
        return s+x

    def output_fn(self, s):
        return s


class Binary_Addition(SM):
    start_state = (0, 0)

    def transition_fn(self, s, x):
        return ((x[0]+x[1]+s[0]) // 2, (x[0]+x[1]+s[0]) % 2)

    def output_fn(self, s):
        return s[1]


class Reverser(SM):
    start_state = []
    end = False

    def transition_fn(self, s, x):
        if x == 'end':
            self.end = True
        if self.end:
            return s
        else:
            s.append(x)
            return s

    def output_fn(self, s):
        if not self.end:
            return None
        else:
            if s:
                return s.pop()
            else:
                return None


output = Accumulator().transduce([-1, 2, 3, -2, 5, 6])
print(output)

output = Binary_Addition().transduce([(1, 1), (1, 0), (0, 0)])
print(output)

output = Binary_Addition().transduce(
    [(1, 1), (1, 0), (0, 0), (1, 1), (0, 1), (1, 0)])
print(output)

output = Reverser().transduce(
    ['foo', ' ', 'bar'] + ['end'] + ['end']*3 + list(range(2)))
print(output)

output = Reverser().transduce(list('the') + ['end'] + list(range(3)))
print(output)

output = Reverser().transduce([] + ['end'] + list(range(5)))
print(output)

output = Reverser().transduce(list('nehznehS evol I') + ['end'] +
                              list(range(15)))
print(output)
