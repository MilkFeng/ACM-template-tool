@echo off

title ACM模板整合小工具

echo 将所有文件转换为utf-8
echo:
python convert_encoding.py
echo:

echo 检测文件并将信息储存在./config/map.csv中
echo:
python generate_config.py
echo:

echo 生成latex文件
echo:
python generate.py
echo:

echo 生成pdf文件，请确保安装了xelatex
echo:
latexmk -xelatex -file-line-error -halt-on-error -interaction=nonstopmode -synctex=1 template.tex
echo:

echo 删除中间文件
rm template.xdv
rm template.aux
rm template.fdb_latexmk
rm template.fls
rm template.log
rm template.synctex.gz
rm template.toc
echo:


echo 结束，将打开生成的pdf文件
start template.pdf

pause