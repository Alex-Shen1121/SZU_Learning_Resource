import string


def encrypt_caesar(plaintext):
    before = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    after = 'DEFGHIJKLMNOPQRSTUVWXYZABC'
    table = ''.maketrans(before, after)
    return plaintext.translate(table)


def decrypt_caesar(ciphertext):
    after = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    before = 'DEFGHIJKLMNOPQRSTUVWXYZABC'
    table = ''.maketrans(before, after)
    return ciphertext.translate(table)


word1 = str(input("请输入加密单词："))
print(encrypt_caesar(word1))
word1 = str(input("请输入解密单词："))
print(decrypt_caesar(word1))
