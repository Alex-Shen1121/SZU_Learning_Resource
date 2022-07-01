# _*_ coding:utf-8 _*_
from numpy import *
from functools import reduce
import re
import random
import operator


# 准备数据：从文本中构建词向量
def loadDataSet():
    postingList = [['my', 'dog', 'has', 'flea', 'problems', 'help', 'please'],
                   ['maybe', 'not', 'take', 'him', 'to', 'dog', 'park', 'stupid'],
                   ['my', 'dalmation', 'is', 'so', 'cute', 'r', 'love', 'him'],
                   ['stop', 'posting', 'stupid', 'worthless', 'garbage'],
                   ['mr', 'licks', 'ate', 'my', 'steak',
                       'how', 'to', 'stop', 'him'],
                   ['quit', 'buying', 'worthless', 'dog', 'food', 'stupid']]
    classVec = [0, 1, 0, 1, 0, 1]  # 由人工标注的文本类别，1代表侮辱性文字，0代表正常言论
    return postingList, classVec

# 构建一个包含所有文档词汇且不重复的词汇表
def createVocabList(dataSet):
    vocabSet = set([])  # 创建一个空集
    for document in dataSet:
        vocabSet = vocabSet | set(document)  # 创建两个集合的并集
    return list(vocabSet)


def setOfWords2Vec(vocabList, inputSet):
    returnVec = [0]*len(vocabList)
    for word in inputSet:
        if word in vocabList:
            returnVec[vocabList.index(word)] += 1  # 改为增加词向量中的对应值
        else:
            print("the word: %s is not in my Vocabulary!" % word)
    return returnVec


# trainMatrix已转换为向量的文档矩阵，trainCategory每篇文档类别标签所构成的向量
def trainNB(trainMatrix, trainCategory):
    numTrainDocs = len(trainMatrix)  # 文档数量
    numWords = len(trainMatrix[0])  # 第一篇文档的长度，也就是词汇表的长度
    pAbusive = sum(trainCategory)/float(numTrainDocs)  # 侮辱文档占总文档比例
    # 初始化概率
    p0Num = zeros(numWords)  # 初始化概率
    p1Num = zeros(numWords)
    p0Denom = 0
    p1Denom = 0
    for i in range(numTrainDocs):
        if trainCategory[i] == 1:  # 如果是侮辱性文档
            p1Num += trainMatrix[i]  # 文档对应的词语数量全部加1，向量相加
            p1Denom += sum(trainMatrix[i])  # 侮辱性文档词语的总数量
        else:
            p0Num += trainMatrix[i]  # 正常文档对应的词语数量向量
            p0Denom += sum(trainMatrix[i])  # 正常文档词语的总数量
    # 对p1Num的每个元素做除法，即侮辱性文档中出现每个词语的概率
    p1Vect = p1Num/p1Denom
    # 对p0Num的每个元素做除法，即正常文档中出现每个词语的概率
    p0Vect = p0Num/p0Denom
    return p0Vect, p1Vect, pAbusive


# 朴素贝叶斯分类函数
# vec2Classify待分类文档向量
# trainMatrix训练文档矩阵
# trainCategory训练文档类别向量
def classifyNB(vec2Classify, trainMatrix, trainCategory):
    p0Vect, p1Vect, pAb = trainNB(trainMatrix, trainCategory)
    # 计算待分类文档词条对应的条件概率P(w0|Ci)P(w1|Ci)P(w2|Ci)...P(wn|Ci)
    p1VectClassify = vec2Classify*p1Vect  # 元素相乘
    p0VectClassify = vec2Classify*p0Vect
    # 去掉列表中的0元素
    p1Cond = []
    p0Cond = []
    for i in range(len(p1VectClassify)):
        if p1VectClassify[i] == 0:
            continue
        else:
            p1Cond.append(p1VectClassify[i])
    for i in range(len(p0VectClassify)):
        if p0VectClassify[i] == 0:
            continue
        else:
            p0Cond.append(p0VectClassify[i])
    # 计算各概率向量的乘积
    if len(p0Cond):  # 若p0Cond不为空，即p0VectClassify不全为0
        pC0 = reduce(operator.mul, p0Cond, 1)  # 计算概率向量内元素乘积，得到P(w|C0)
    else:
        pC0 = 0
    if len(p1Cond):
        pC1 = reduce(operator.mul, p1Cond, 1)
    else:
        pC1 = 0
    p1 = pC1*pAb
    p0 = pC0*(1.0-pAb)
    if p1 > p0:
        return 1
    else:
        return 0


def testingNB():
    # 加载数据
    listOposts, listClasses = loadDataSet()
    # 构建词表
    myVocabList = createVocabList(listOposts)
    # 构建文档矩阵
    trainMat = []
    for postinDoc in listOposts:
        trainMat.append(setOfWords2Vec(myVocabList, postinDoc))
    # 测试用例
    testEntry1 = ['love', 'my', 'dalmation']
    testEntry2 = ['stupid', 'garbage']
    thisDoc1 = array(setOfWords2Vec(myVocabList, testEntry1))
    thisDoc2 = array(setOfWords2Vec(myVocabList, testEntry2))
    print(classifyNB(thisDoc1, trainMat, listClasses))
    print(classifyNB(thisDoc2, trainMat, listClasses))


if __name__ == '__main__':
    testingNB()
