import re


def readability(passage):
    word_num = len(passage.split())
    sentence_num = len(re.split('[.?!]', passage))-1

    alpha_num = 0
    for i in range(len(passage)):
        if passage[i].isalpha():
            alpha_num += 1

    L = alpha_num/word_num*100
    S = sentence_num/word_num*100
    return round(0.0588*L-0.296*S-15.8)


sentence_list = ["One fish. Two fish. Red fish. Blue fish.",
                 "Would you like them here or there? I would not like them here or there. I would not like them anywhere.",
                 "Congratulations! Today is your day. You're off to Great Places! You're off and away!",
                 "Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.",
                 "In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.",
                 "When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.",
                 "There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy.",
                 "It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.",
                 "A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains."]

for sentence in sentence_list:
    index = readability(sentence)
    if index < 1:
        print('Before Grade 1')
    elif index >= 16:
        print('Grade 16+')
    else:
        print('Grade', index)
