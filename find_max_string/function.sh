#!/bin/bash

filter_types=(mp4 avi gz zip tar)

function filter() {
    file_name=$1
    type_name=`basename ${file_name} | rev | cut -d "." -f 1 | rev`
    # basename ${file_name} 取出 file_name 的文件名
    # rev 将字符串反转
    # cut -d "." -f 1 以字符串中的 . 分割，取出第一部分
    # 最后再反转得到文件的后缀

    # ${filter_types[@]} 中的 @ 代表 filter_types 中的所有元素
    for i in ${filter_types[@]};do
        if [[ ${type_name} == ${i} ]];then
            echo "Fileters On! ${file_name}"
            return 1
        fi
    done
}

function find_max_in_file() {
    echo "Finding Max_string in file $1"
    # ! -f ${1} 判断是否是普通文件  ! 取反
    # -d ${1}  判断是否是目录
    if [[ ! -f ${1} ]];then
        echo "$1 is not a regular file"
        return 
    fi
    filter $1
    # $? 上一条命令的返回值
    if [[ $? -eq 1 ]];then
        return 
    fi
    words=`cat $1 | tr -s -c "a-zA-Z" "\n"`
    for i in ${words};do
        len_t=`echo -n ${i} | wc -c`
        if [[ ${len_t} -gt ${len_max} ]];then
            len_max=${len_t}
            max_string=${i}
            max_file=$1
        fi
    done
}


function find_max_in_dir() {
    for i in `ls -A $1`;do
        if [[ -d ${1}/${i} ]];then
            echo "${1}/${i} is a dir"
            find_max_in_dir ${1}/${i}
        else
            echo "${1}/${i} is a file"
            find_max_in_file ${1}/${i}
        fi
    done
}

