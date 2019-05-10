from urllib.request import urlopen
from bs4 import BeautifulSoup

html = urlopen('http://www.pythonscraping.com/pages/page1.html')
# html = urlopen('http://www.naver.com')
bs = BeautifulSoup(html.read(), 'html.parser')

# print('*' * 100)
# print(bs.html)
# print('*' * 100)
# print(bs.h1)
# print('*' * 100)
# print(bs.body)

print(bs.html.select('h1'))