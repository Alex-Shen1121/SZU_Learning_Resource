import itertools
import random


class Card():
    def __init__(self, rank, suit):
        """ 扑克牌14个等级，从2，3，4，...,10, J, Q, K, A
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        扑克牌花色： S代表黑桃，H代表红桃，C代表梅花，D代表方块
        """
        assert suit in {'S', 'H', 'C', 'D'}
        assert rank in range(2, 15)

        self.rank = rank
        self.suit = suit

    suit_str = {'S': "\u2660", 'H': "\u2661", 'C': "\u2663", 'D': "\u2662"}
    rank_str = {n: str(n) for n in range(2, 11)}
    rank_str[11] = 'J'
    rank_str[12] = 'Q'
    rank_str[13] = 'K'
    rank_str[14] = 'A'

    def __str__(self):  # 输出，如'2♡'
        return f"{self.rank_str[self.rank]}{self.suit_str[self.suit]}"

    def __repr__(self):  # Card(2,'H')
        return f"Card({self.rank},'{self.suit}')"

    def __gt__(self, other):
        return self.rank > other.rank

    def __lt__(self, other):
        return self.rank < other.rank

    def __eq__(self, other):
        return self.rank == other.rank


class Hand():
    def __init__(self, cards=[]):
        self.cards = []
        self.receive_cards(cards)

    def receive_cards(self, cards):
        self.cards.extend(cards)

    def receive_card(self, card):
        self.cards.append(card)

    def shuffle(self):
        if self.cards:
            random.shuffle(self.cards)

    def give_card(self):
        if not self.cards:
            return None
        temp = self.cards[0]
        del self.cards[0]
        return temp

    def give_cards(self):
        if not self.cards:
            return None
        temp = self.cards.copy()
        self.cards.clear()
        return temp

    def __iter__(self):
        yield from self.cards

    def __repr__(self):
        return f"Hand({self.cards})"

    def __str__(self):
        return str([str(card) for card in self.cards])

    @property  # 设置属性，这样可以使用 对象.num_cards 访问，而不是 对象.num_cards()
    def num_cards(self):
        return len(self.cards)


class Deck(Hand):
    def __init__(self):
        self.cards = []
        for i in Card.rank_str:
            for j in Card.suit_str:
                self.cards.append(Card(i, j))
            # 补充代码: 52张牌
        # self.cards = [Card(2, "H"), Card(2, "S"), Card(
        #     3, "D"), Card(3, "S")]  # 仅供测试用，补充上句后可注释
        self.size = self.num_cards
        self.shuffle()


class Player(Hand):
    def __init__(self, name, cards=[]):
        self.name = name
        self.cards = cards.copy()

    def __repr__(self):
        return f"Player({repr(self.name)}, {[c for c in self]})"

    def __str__(self):
        return f"<{repr(self.name)} has {[str(c) for c in self]}>"


class Game():
    def __init__(self, players):
        self.players = players
        self.deck = Deck()

    def deal(self):
        # 补充代码：给两个玩家发牌。每个玩家轮流从牌堆Deck中取出一张牌，每人26张。
        # while self.deck.cards:
        # 	self.players[0].receive_card(self.deck.give_card())
        # 	self.players[1].receive_card(self.deck.give_card())

        # self.players[0].cards = self.deck.cards[:26]
        # self.players[1].cards = self.deck.cards[26:]
        self.players[0].cards = [Card(2, 'H'), Card(3, 'C')]
        self.players[1].cards = [Card(3, 'H'), Card(3, 'C')]

    def turn(self):
        h = Hand()
        while True:
            card1 = self.players[0].give_card()
            card2 = self.players[1].give_card()
            h.receive_cards([card1, card2])
            if card1 != card2:
                break
            if not self.players[0].cards and not self.players[1].cards:
                print(h, '=> Tie')
                return 'Tie'
            if not self.players[0].cards:
                print(h, '=>', self.players[1].name)
                return self.players[1]
            if not self.players[1].cards:
                print(h, '=>', self.players[0].name)
                return self.players[0]
        if card1 < card2:
            print(h, '=>', self.players[1].name)
            self.players[1].receive_cards(h.give_cards())
            self.players[1].shuffle()
            return self.players[1]
        else:
            print(h, '=>', self.players[0].name)
            self.players[0].receive_cards(h.give_cards())
            self.players[0].shuffle()
            return self.players[0]

    def play(self):
        self.deal()  # 发牌
        cnt = 0
        while True:
            cnt += 1
            winner = self.turn()
            if winner == 'Tie' or not self.players[0].cards or not self.players[1].cards:
                break

        print("经历了{}轮".format(cnt))
        return winner.name if winner != 'Tie' else 'No Winner'


def test_Card():
    cards = [Card(3, 'S'), Card(14, 'D'), Card(10, 'D'), Card(14, 'H')]
    # cards: [Card(3,'S'), Card(14,'D'), Card(10,'D'), Card(14,'H')]
    print("cards:", cards)
    print("max:", max(cards))  # max: A♢
    print("min:", min(cards))  # min: 3♠
    print("position of max card:", cards.index(
        max(cards)))  # position of max card: 1
    # regular sorted: ['3♠', '10♢', 'A♢', 'A♡']
    print("regular sorted:", [str(c) for c in sorted(cards)])
    # reverse sorted: ['A♢', 'A♡', '10♢', '3♠']
    print("reverse sorted:", [str(c) for c in sorted(cards, reverse=True)])


def test_Hand():
    h = Hand()
    h.receive_card(Card(2, 'S'))
    h.receive_cards([Card(13, 'H'), Card(7, 'C')])
    print("hand:", h)  # hand: ['2♠', 'K♡', '7♣']
    print("num_cards:", h.num_cards)  # num_cards: 3
    print("give card:", h.give_card())  # give card: 2♠
    # rest of cards: ['K♡', '7♣']
    print("rest of cards:", [str(c) for c in h.give_cards()])
    print("give card:", h.give_card())  # None


def test_Deck():
    d = Deck()
    print(d)  # ['3♢', '3♠', '2♠', '2♡']
    print("size of deck:", d.size)  # size of deck: 4
    print("give card:", d.give_card())  # give card: 3♢
    # rest of cards: ['3♠', '2♠', '2♡']
    print("rest of cards:", [str(c) for c in d.give_cards()])


def test_Player():
    p = Player('Pam')
    p.receive_card(Card(10, 'H'))
    print(p)  # <'Pam' has ['10♡']>


def test_Game():
    game = Game([Player("A"), Player("B")])
    winner = game.play()
    print("获胜的是", winner)


test_Game()
# test_Card()
# test_Deck()
# test_Hand()
# test_Player()


# """
# 例子1:
# at start <'A' has ['2♡', '3♢']>
# at start <'B' has ['2♠', '3♠']>
# ['2♡', '2♠'] => Tie
# ['3♢', '3♠', '2♡', '2♠'] => Tie
# No Winner

# 例子2:
# at start <'A' has ['2♡', '2♠']>
# at start <'B' has ['3♠', '3♢']>
# ['2♡', '3♠'] => B
# ['2♠', '3♠'] => B
# B wins!
