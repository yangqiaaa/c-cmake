
# 1. ANSI escape code
escape sequence code ȫ�ƽ��� escape sequence code���� Escape ������Ļ�����룬<br>
��ʵ����һЩ������ַ�������Щ�ַ����뵽printf��ӡ�������У�<br>
��������ʵ�����ն��������Ը�����ɫ�����ֱ���ɫ��ʾ���ݣ������Ը������Ӵ֡���˸.<br>

# 2. �������ʽ
�ַ�        |��ʾ  | ����
:-:|:-:|:-:
�����ַ�    | \033  | ֪ͨ�ն��л���escapeģʽ
��ʼ�ַ�    | [��      | CSI���ݵĿ�ʼ
CSI�����ַ� | �����±���|�����±���
CSI�����ַ� | m | CSI���ݵĽ���

## 2.1 ������ɫ��

�ֱ�����ɫ��Χ:40----49        
����|��ɫ 
:-:|:-:
40|��                        
41|���                       
42|��                          
43|��ɫ                        
44|��ɫ                        
45|��ɫ                     
46|����               
47|��ɫ                 

## 2.2 ����ɫ��
����ɫ:30-----------39

��ʾ����|����
:-:|:-:
30|��
31|��
32|��
33|��
34|��ɫ
35|��ɫ
36|����
37|��ɫ

## 2.3
���      |  ����
:-:|:-:
\33[0m   |  �ر��������� 
\33[1m   |  ���ø����� 
\33[4m   | �»��� 
\33[5m   |  ��˸ 
\33[7m   | ���� 
\33[8m   | ���� 
\33[30m  | -- \33[37m ����ǰ��ɫ 
\33[40m  | -- \33[47m ���ñ���ɫ 
\33[nA   | �������n�� 
\33[nB   | �������n�� 
\33[nC   | �������n�� 
\33[nD   | �������n�� 
\33[y;xH | ���ù��λ�� 
\33[2J   | ���� 
\33[K    | ����ӹ�굽��β������ 
\33[s    | ������λ�� 
\33[u    | �ָ����λ�� 
\33[?25l | ���ع�� 
\33[?25h | ��ʾ���

# 3. ʾ��
```
printf("\033[32;?25hmHelloWorld\r\n");
printf("\033[32;5mHelloWorld\033[0m\r\n");
```