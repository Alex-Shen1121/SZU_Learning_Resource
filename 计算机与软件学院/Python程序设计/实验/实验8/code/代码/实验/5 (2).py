list1 = ['apple', 'orange', 'pear']
print([i[0].upper() for i in list1])

list2 = ['apple', 'orange', 'pear']
print([i for i in list2 if i.count('p') > 0])

list3 = ["TA_parth",  "student_poohbear",
         "TA_michael",  "TA_guido",  "student_htiek"]
print([i[3:] for i in list3 if i.startswith('TA_')])

list4 = ['apple', 'orange', 'pear']
print([{i, len(i)} for i in list4])

list5 = ['apple', 'orange', 'pear']
print({i: len(i) for i in list5})
