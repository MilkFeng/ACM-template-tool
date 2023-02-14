import os

def construct(lst: list[str]) -> str:
    res = ''
    
    for s in lst[1:]:
        
        set = s.split(',')
        
        deep = int(set[0])
        title = set[1]
        type = set[2]
        file = set[3]
        
        if type == 'file':
            if deep == 1:
                res = res + '    \section{' + title + '}\n'
            elif deep == 2:
                res = res + '        \subsection{' + title + '}\n'
            elif deep == 3:
                res = res + '            \subsubsection{' + title + '}\n'
            res = res + '    ' * (deep + 1) + '\lstinputlisting[language=C++]{' + file[:-1] + '}\n'
        else:
            if deep == 1:
                res = res + '    \\newpage\n'
                res = res + '    \section{' + title + '}\n'
            elif deep == 2:
                res = res + '        \subsection{' + title + '}\n'
            elif deep == 3:
                res = res + '            \subsubsection{' + title + '}\n'
            
        print(s[:-1] + ' 载入完成')
    return res

if __name__ == '__main__':
    fout = open('./template.tex', 'w', encoding = "utf-8")

    head = open('./config/head.txt', encoding = "utf-8").read()
    tail = open('./config/tail.txt', encoding = "utf-8").read()
    lst = open('./config/map.csv', encoding = 'utf-8').readlines()
    content = construct(lst)
    
    fout.write(head)
    fout.write(content)
    fout.write(tail)
    
    fout.close()