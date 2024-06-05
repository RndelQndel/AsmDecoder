#!/bin/bash

# ���� ��� ���� ����Ʈ
files=("CMakeCache.txt" "CMakeFiles" "Makefile" "cmake_install.cmake")

# ���� �Լ� ����
delete_files() {
    local dir=$1
    for file in "${files[@]}"; do
        local target="$dir/$file"
        if [ -e "$target" ]; then
            echo "Deleting: $target"
            rm -rf "$target"
        fi
    done
}

# ���� ���丮���� �����Ͽ� ��ȸ�ϸ� ����
traverse() {
    local dir=$1
    delete_files "$dir"
    for d in "$dir"/*; do
        if [ -d "$d" ]; then
            traverse "$d"
        fi
    done
}

# ��ũ��Ʈ ����
traverse "$(pwd)"

