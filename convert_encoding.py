import os
import chardet

def construct(path: str) -> list:
    files = os.listdir(path)
    
    for file in files:
        if os.path.isdir(path + '/' + file):
            construct(path + '/' + file)
        else:
            res = chardet.detect(open(path + '/' + file, 'rb').read())
            print(path + '/' + file + ' 转换完成')
            if res['encoding'] != 'utf-8':
                con = open(path + '/' + file, 'r', encoding = res['encoding']).read()
                open(path + '/' + file, 'w', encoding = 'utf-8').write(con)
    pass

if __name__ == '__main__':
    construct('./code')