def validCredit(cardNum):
    cardNum = str(cardNum)

    if cardNum[:2] == '34' or cardNum[:2] == '37' and len(cardNum) == 15:
        cardType = 'American Express'
    elif cardNum[:2] == '51' or cardNum[:2] == '52' or cardNum[:2] == '53' or cardNum[:2] == '54' or cardNum[:2] == '55' and len(cardNum) == 16:
        cardType = 'MasterCard'
    elif cardNum[0] == '4' and len(cardNum) == 16 or len(cardNum) == 13:
        cardType = 'Visa'
    else:
        print('InValid')
        return

    sum1 = 0
    for num in cardNum[-2::-2]:
        sum1 += sum([int(i) for i in str(int(num)*2)])
    sum2 = sum([int(i) for i in cardNum[-1::-2]])
    sum3 = sum1+sum2
    print('Valid, ' + cardType if sum3 % 10 == 0 else 'InValid')


validCredit(4003600000000014)
validCredit(6177292929)
validCredit(378282246310005)
validCredit(371449635398431)
validCredit(5555555555554444)
validCredit(4111111111111111)
validCredit(4012888888881881)
validCredit(4222222222222)
validCredit(4222222222229)
