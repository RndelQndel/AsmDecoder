#!/bin/bash

# 삭제 대상 파일 리스트
files=("CMakeCache.txt" "CMakeFiles" "Makefile" "cmake_install.cmake")

# 삭제 함수 정의
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

# 현재 디렉토리부터 시작하여 순회하며 삭제
traverse() {
    local dir=$1
    delete_files "$dir"
    for d in "$dir"/*; do
        if [ -d "$d" ]; then
            traverse "$d"
        fi
    done
}

# 스크립트 시작
traverse "$(pwd)"

