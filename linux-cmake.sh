#!/bin/bash

# echo -e "\e[1;36m \e[0m"
# \e[1;36 ����ɫ����Ϊ��ɫ \e[0����ɫ�����ûء�
# ����֪��shell���ն˴�ӡ��echo printfһ�㳣�õľ���echo����
# ע��������ɫ ����=0��
#��ɫ=30��
#��ɫ=31��
#��ɫ=32��
# ***=33��
#��ɫ=34�� ���=35�� ��ɫ=36�� ��ɫ=37.
# ������ɫ ����=0����ɫ=40����ɫ=41����ɫ=42��
# ***=43����ɫ=44�� ���=45�� ��ɫ=46�� ��ɫ=47.
# Ҫ��ӡ��ɫ�ı����������������
# echo -e "\e[1;36m \e[0m"
# ���ƴ����������:

echo "if you don't know how to use:'./1.sh help'"
##cmake && make ������ѡ���������shell����
case $* in
"cmake make")
    # mkdir ./build
    if [ ! -d "./linux-build/" ]
    then 
        echo -e "\e[1;32m mkdir ./linux-build \e[0m"
        mkdir ./linux-build
    fi

    # mkdir ./bin
    if [ ! -d "./linux/bin" ]
    then 
        echo -e "\e[1;32m mkdir ./linux/bin \e[0m"
        mkdir ./linux/bin
    fi

    #mkdir ./bin/ortp
    #if [ ! -d "./bin/ortp" ]
    #then 
    #    echo "mkdir ortp"
    #    echo -e "\e[1;32m mkdir ./bin/ortp \e[0m"
    #    mkdir ../bin/ortp
    #fi

    # cd ./build/ [and] rm ./* -r [and] cmake .. && make
    echo -e "\e[1;32m cd ./linux-build \e[0m"
    cd ./linux-build || exit
    echo -e "\e[1;31m rm ./* -r \e[0m"
    rm -r ./*
    echo -e "\e[1;32m cmake .. && make \e[0m"
    cmake .. && make
    echo -e "\e[1;32m exit build \e[0m"
    cd .. || exit 
    echo -e "\e[1;36m finished \e[0m"
    ;;
"cmake")

    if [ ! -d "./linux-build/" ]
    then 
        echo "mkdir linux-build"
        mkdir ./linux-build
    fi
    
    if [ ! -d "./linux/bin" ]
    then 
        echo "mkdir bin"
        mkdir ./linux/bin
    fi

    cd ./linux-build || exit
    cmake ..
    ;;
"cmake clean")

    if [ ! -d "./build/" ]
    then 
        echo "no dir build, exit"
        exit
    fi
    cd ./linux-build || exit
    echo "cd linux-build & rm ./* -r"
    rm ./* -r
    ;;
"make")

    if [ ! -d "./linux-build/" ]
    then 
        echo "no dir linux-build, exit"
        exit
    fi

    cd ./linux-build || exit

    if [[ -f "./makefile" ]] || [[ -f "./Makefile" ]] || [[ -f "./GUNMakefile" ]] 
    then 
        make
    else 
        echo "no makefile, exit,please './1.sh cmake'"
        exit
    fi
    ;;
"make clean")

    if [ ! -d "./build/" ]
    then 
        echo "no dir build, exit"
        exit
    fi

    cd ./linux-build || exit

    if [[ -f "./makefile" ]] || [[ -f "./Makefile" ]] || [[ -f "./GUNMakefile" ]] 
    then 
        make clean
    else 
        echo "no makefile, exit,please './1.sh cmake'"
        exit
    fi
    ;;
"help")
    echo "usage"
    echo "cmake make: './1.sh cmake make'"
    echo "cmake: './1.sh cmake'"
    echo "cmake clean: './1.sh cmake clean'"
    echo "make: './1.sh make'"
    echo "make clean: './1.sh make clean'"
    ;;
"run")
    ./linux/bin/main
    ;;   
esac

#ortp�����ĸ���ִ���ļ�