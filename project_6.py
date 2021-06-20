import bs4
import requests
import csv

headers ={
    'User-Agent': 'Not_Crawling X'
}

response = requests.get('https://kin.naver.com/',headers=headers).text
soup = bs4.BeautifulSoup(response, 'html.parser')
ranks = soup.select('#rankingChart > ul > li')

ranking = lambda rank: int(rank.select_one('span.no').text)
content = lambda rank: rank.select_one('a.ranking_title').text

with open('kin_rank.csv','w') as ff:
    writer = csv.writer(ff)
    for rank in sorted(ranks, key=ranking):
       realrank = ranking(rank)
       contents = content(rank)
       writer.writerow([f'{realrank}위', contents])