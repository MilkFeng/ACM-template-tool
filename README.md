## 结构

- `./config`：一些参数
  - `./config/head.txt`、`./config/tail.txt`：latex正文前后的模板
  - `./config/map.csv`：文件信息，从左到右含义为：深度（deep）、标题（title）、类型（type，包含dir和file）、路径（path）
- `./code`：所有的代码，因为latex的限制，最多只能出现三级文件夹
- `./convert_encoding.py`：将`./code`中的所有文件转换成`UTF-8`编码，其他编码可能使latex生成乱码
- `./generate_config.py`：检测`./code`中的文件，将信息储存在`./config/map.csv`中
- `./generate.py`：生成tex文件
- `./start.cmd`：脚本文件，一键生成