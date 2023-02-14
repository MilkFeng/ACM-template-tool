@echo off

title ACMģ������С����

echo �������ļ�ת��Ϊutf-8
echo:
python convert_encoding.py
echo:

echo ����ļ�������Ϣ������./config/map.csv��
echo:
python generate_config.py
echo:

echo ����latex�ļ�
echo:
python generate.py
echo:

echo ����pdf�ļ�����ȷ����װ��xelatex
echo:
latexmk -xelatex -file-line-error -halt-on-error -interaction=nonstopmode -synctex=1 template.tex
echo:

echo ɾ���м��ļ�
rm template.xdv
rm template.aux
rm template.fdb_latexmk
rm template.fls
rm template.log
rm template.synctex.gz
rm template.toc
echo:


echo �������������ɵ�pdf�ļ�
start template.pdf

pause