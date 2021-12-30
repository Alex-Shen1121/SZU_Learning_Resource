from typing import final
import pandas as pd
import tqdm as tqdm

mrr1 = 0.5580901856763985
mrr2 = 0.558719436112289
mrr3 = 0.5558528967004702

if __name__ == '__main__':
    result1 = pd.read_csv(
        '../prediction_result/result_lgb_'+str(mrr1)+'.csv')
    result2 = pd.read_csv(
        '../prediction_result/result_lgb_'+str(mrr2)+'.csv')
    result3 = pd.read_csv(
        '../prediction_result/result_lgb_'+str(mrr3)+'.csv')

    print('cbt_model:')
    print(result1.head())
    print('lgb_model:')
    print(result2.head())
    print('xgb_model:')
    print(result3.head())

    final_result = pd.DataFrame().reindex_like(result2)

    for i in range(final_result.shape[0]):
        list1 = result2.loc[i][1:]
        list2 = result3.loc[i][1:]
        list3 = result1.loc[i][1:]
        mylist = set(set(list1).intersection(
            set(list2))).intersection(set(list3))
        finallist = []
        for j in list1:
            if i in mylist:
                finallist.append(j)
        for j in range(5):
            if list1[j] not in finallist:
                finallist.append(list1[j])
            if list2[j] not in finallist:
                finallist.append(list2[j])
            if list3[j] not in finallist:
                finallist.append(list3[j])
        finallist = finallist[:5]
        final_result.loc[i] = pd.array([i+200000]+finallist, dtype=str)
        # print(final_result.head())
        if i % 1000 == 0:
            print(i)
    # final_result.drop(['index'], axis=1)
    final_result.to_csv('../prediction_result/ronghe_2.csv')

    print(result2.shape, result3.shape,
          result1.shape, final_result.shape)
