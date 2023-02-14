import os
import chardet

def construct(path: str, deep: int, lst: list) -> list:
    files = os.listdir(path)
    for file in files:
        if os.path.isdir(path + '/' + file):
            lst.append(str(deep) + ',' + file + ',' + 'dir' + ',')
            print(str(deep) + ',' + file + ',' + 'dir' + ',')
            construct(path + '/' + file, deep + 1, lst)
        else:
            lst.append(str(deep) + ',' + file[:-4] + ',' + 'file' + ',' + path + '/' + file)
            print(str(deep) + ',' + file[:-4] + ',' + 'file' + ',' + path + '/' + file)
    pass
    

if __name__ == '__main__':
    print('已检测到文件：')
    print('deep,title,type,path')
    
    lst = []
    construct('./code', 1, lst)
    file = open('./config/map.csv', 'w', encoding = 'utf-8')
    
    for s in lst:
        file.write(s + '\n')
    file.close()