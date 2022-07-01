import imp
from lib2to3.pgen2.grammar import opmap
from time import sleep
from unittest import result
from matplotlib.pyplot import title
import requests
import re
from selenium.webdriver import Chrome
from selenium.webdriver.support.select import Select

web  = Chrome()
url = r'https://www1.szu.edu.cn/board/'
web.get(url + 'infolist.asp?')

# 解析数据
obj1 = re.compile(r'<a target="_blank" class="fontcolor3" href=".*?">(?P<title>.*?)</b></a></td>', re.S)
obj2 = re.compile(r'<a target="_blank" class="fontcolor3" href="(?P<url>.*?)">', re.S)

for departmentName in ['党政办公室', '教务部', '招生办公室', '研究生院', '科学技术部']:
    web.get(url + 'infolist.asp?')
    # 定位到年份下拉列表
    year_sel = web.find_element_by_xpath('/html/body/table/tbody/tr[2]/td/table/tbody/tr[3]/td/table/tbody/tr[1]/td/table/tbody/tr/td[2]/select[1]')
    year_sel = Select(year_sel)

    # 定位到部门下拉列表
    dep_sel = web.find_element_by_xpath('/html/body/table/tbody/tr[2]/td/table/tbody/tr[3]/td/table/tbody/tr[1]/td/table/tbody/tr/td[2]/select[2]')
    dep_sel = Select(dep_sel)

    # 定位到搜索按钮
    search_ele = web.find_element_by_xpath('/html/body/table/tbody/tr[2]/td/table/tbody/tr[3]/td/table/tbody/tr[1]/td/table/tbody/tr/td[2]/input[3]')
    
    # 年份调整为2021年，并刷新列表
    year_sel.select_by_value('2021')
    dep_sel.select_by_value(departmentName)
    search_ele.click()
    sleep(1)
    
    
    # 获得新闻列表
    table = web.find_element_by_xpath('/html/body/table/tbody/tr[2]/td/table/tbody/tr[3]/td/table/tbody/tr[3]/td')
    table_html = table.get_attribute('innerHTML')
    
    # 提取url
    result = obj2.finditer(table_html)
    for index, item in enumerate(result):
        print(index, item.group('url'))
        if index == 30:
            break
        
        # 获取公文通内容
        new_url = url + item.group('url')
        web.get(new_url)
        content = web.find_element_by_xpath('/html/body/table/tbody/tr[2]/td/table/tbody/tr[3]/td/table/tbody/tr[2]/td')
        # print(content.text)
        # print(f"/data/{departmentName}{index}")
        
        # 写入文件 /data/departmentName/title.txt
        f = open(f"data/{departmentName}{index}.txt", 'a')
        f.write(content.text)
    print('--------------------------------------------')
    
    
    
    