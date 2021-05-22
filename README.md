# quick open project
该项目就是个模板项目生成器,用于快速搭建项目.

# 使用

> qopenproject --template cpp ； 此命令选择模板.
> 
> qopenproject                ； 此命令初始化.

没有多少选项,直接"qopenproject --help"查看.
模板格式见"tests/assets/templates"目录,更多查看"pantor/inja"项目.

### qop.ini
- "templates_dir_path" 模板存放路径.
- "run_env" run命令运行环境.
- "editor" 可选, 文本编辑器路径.

# 注意事项
- linux 下 可以用'xdg-open', 将使用默认程序打开文本.

- windows msys2 似linux环境中,"start"无法正确工作.
