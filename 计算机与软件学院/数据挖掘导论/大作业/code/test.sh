time=$(date "+%Y-%m-%d-%H:%M:%S")
# 处理数据
python 1_data.py --mode valid --logfile "${time}.log"
# itemcf 召回
python 2_recall_itemcf.py --mode valid --logfile "${time}.log"
# binetwork 召回
python 3_recall_binetwork.py --mode valid --logfile "${time}.log"
# w2v 召回
python 4_recall_w2v.py --mode valid --logfile "${time}.log"
# 召回合并
python 5_recall.py --mode valid --logfile "${time}.log"
# 排序特征
python 6_rank_feature.py --mode valid --logfile "${time}.log"
# lgb 模型训练
python 7_rank_lgb.py --mode valid --logfile "${time}.log"