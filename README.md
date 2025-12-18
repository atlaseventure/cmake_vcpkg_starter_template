VS Code下CMake C++开发的基本示例，包含vcpkg集成，catch2测试框架集成

# 安装vcpkg

官方教程

[vcpkg with Visual Studio Code](https://learn.microsoft.com/vcpkg/get_started/get-started-vscode)

总结下来分为这样几步

## 克隆存储库

```bash
git clone https://github.com/microsoft/vcpkg.git ~/devel/vcpkg
```


## 运行启动脚本

```bash
# 安装必要组件
sudo apt install -y pkg-config curl zip unzip tar ninja-build cmake gcc g++
cd ~/devel/vcpkg && ./bootstrap-vcpkg.sh
```

## 设置环境变量

```bash
cat >> ~/.bashrc <<'EOF'

# --- vcpkg settings ---
export VCPKG_ROOT=~/devel/vcpkg
export PATH=$PATH:$VCPKG_ROOT
# --- end vcpkg settings ---

EOF

# 没有安装zsh终端可以不执行
cat >> ~/.zshrc <<'EOF'

# --- vcpkg settings ---
export VCPKG_ROOT=~/devel/vcpkg
export PATH=$PATH:$VCPKG_ROOT
# --- end vcpkg settings ---

EOF
```

重启终端使环境变量生效

# 运行本项目

本项目`vcpkg.json`中已添加两个依赖

- fmt: 更好的字符串格式化输出工具
- catch2: C++ 的单元测试框架

修改`vcpkg.json`中的`builtin-baseline`可以更新依赖版本

`builtin-baseline`可以在[vcpkg的提交记录](https://github.com/microsoft/vcpkg/commits/master/)中查看，复制SHA值替换`builtin-baseline`字段的值

安装工作区建议的插件可以获得更好的体验

.clang-format, .clang-tidy引用自[llama.cpp](https://github.com/ggml-org/llama.cpp)项目

我在CMakePresets.json添加了变量"VCPKG_MANIFEST_INSTALL": "OFF"，这会防止cmake配置时自动安装依赖，增加配置速度，使用`vcpkg install`以手动安装依赖，如果你需要自动安装依赖，请将这个变量值设置为`ON`

编译及运行命令如下

```bash
vcpkg install
cmake --preset debug
cmake --build build/debug
ctest --test-dir build/debug
build/debug/bin/foo_example
```

