from urllib.request import urlopen
from bs4 import BeautifulSoup

html = urlopen('http://www.pythonscraping.com/pages/page1.html')
bs = BeautifulSoup(html.read(), 'html.parser')

print(bs.body)
print('*' * 100)
print(bs.body.parent)
print('*' * 100)
for child in bs.body.children:
    print('child.name:', end='')
    print(child.name)
    print('child.string:', end='')
    print(child.string)
    print('*' * 100)
