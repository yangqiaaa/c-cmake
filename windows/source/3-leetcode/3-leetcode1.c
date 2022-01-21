/*********************************************************************************
  *Copyright(C),1996-2021, Company
  *FileName:  3-leetcode1.c
  *Author:  wyp
  *Version:  V1.0
  *Date:  2022-01-21 14:43:06
  *Description:


  *History:
     1.Date:
       Author:
       Modification:
     2.
**********************************************************************************/


/***************************************Includes***********************************/
//#include"xxx.h"
//#include"xxx.h"
#include "3-1-leetcode.h"
#include "1-1-print.h"
#include "1-6-num.h"

//lib
#include "uthash.h"

#include <stdlib.h>

/***************************************Macros***********************************/
//#define


/***************************************Variables***********************************/



/***************************************Functions***********************************/


static void leetcode_1_show(void)
{
    // ��Ŀ
    printi("leetcode 1 ����֮��\n");
    printi("����һ���������� nums��һ������Ŀ��ֵ target,\n");
    printi("�����ڸ��������ҳ� ��ΪĿ��ֵ target�����������������������ǵ������±�\n");
    printi("����Լ���ÿ������ֻ���Ӧһ���𰸡�\n");
    printi("���ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�\n");

    //1 ����ö��
    printi("#############################\n");
    printi("solution 1 ����ö��\n");
    printi("ö�������е�ÿһ���� x��Ѱ���������Ƿ���� target - x\n");
    printi("������ʹ�ñ�����������ķ�ʽѰ�� target - x ʱ��\n");
    printi("��Ҫע�⵽ÿһ��λ�� x ֮ǰ��Ԫ�ض��Ѿ��� x ƥ�������˲���Ҫ�ٽ���ƥ�䡣\n");
    printi("��ÿһ��Ԫ�ز��ܱ�ʹ�����Σ���������ֻ��Ҫ�� x �����Ԫ����Ѱ�� target - x��\n");
    printi("���Ӷȷ���\n");
    printi("ʱ�临�Ӷ�:O(N^2)\n");
    printi("���� NN �������е�Ԫ��������������������������������Ҫ��ƥ��һ�Ρ�\n");
    printi("�ռ临�Ӷ�:O(1)\n");

    //2 ��ϣ��
    printi("������ ��ϣ\n");
    printi("˼·���㷨\n");
    printi("ע�⵽����һ��ʱ�临�ӶȽϸߵ�ԭ����Ѱ�� target - x ��ʱ�临�Ӷȹ��ߡ�\n");
    printi("��ˣ�������Ҫһ�ָ�����ķ������ܹ�����Ѱ���������Ƿ����Ŀ��Ԫ�ء�\\n");
    printi("������ڣ�������Ҫ�ҳ�����������\n");
    printi("ʹ�ù�ϣ�����Խ�Ѱ�� target - x ��ʱ�临�ӶȽ��͵��� O(N)O(N) ���͵� O(1)O(1)��\n");
    printi("�������Ǵ���һ����ϣ������ÿһ�� x���������Ȳ�ѯ��ϣ�����Ƿ���� target - x��\n");
    printi("Ȼ�� x ���뵽��ϣ���У����ɱ�֤������ x ���Լ�ƥ��\n");
    printi("���Ӷȷ���\n");
    printi("ʱ�临�Ӷ� O(N)O(N)\n");
    printi("���� NN �������е�Ԫ������������ÿһ��Ԫ�� x�����ǿ��� O(1)O(1) ��Ѱ�� target - x��\n");
    printi("�ռ临�Ӷ� O(N)O(N)\n");
    printi("���� NN �������е�Ԫ����������ҪΪ��ϣ��Ŀ�����\n");
}

//solution 2 ##########################################################################################
/** 
 * @brief 1 define hash struct
 * @file 3-1-leetcode.c
 * @name 
 * @param int key
 * @param int key
 * @param UT_hash_handle hh //hash handle ,don't need assign a value
 * @note ������˫������Ĳ���������ͨ���ṹ���Աhh��hh.prev��hh.next��ȡ��ǰ�ڵ����һ���ڵ������һ���ڵ㡣
 * @date 2022-01-14 10:00:09
 * @version V1.0.0
*/
struct hash_table_1_t
{
    int key; //key 
    int value; //value
    //makes this structure hashable
    UT_hash_handle hh;
};

//2 init hash struct
struct hash_table_1_t* hash_table_1 = NULL;

/** 
 * @brief find hash by key
 * @file 3-1-leetcode.c
 * @name 
 * @param[in] int key
 * @return void
 * @note 
 * @date 2021-12-16 14:53:14
 * @version V1.0.0
*/
static struct hash_table_1_t* find(int ikey) 
{
    struct hash_table_1_t* tmp;
    HASH_FIND_INT(hash_table_1, &ikey, tmp);
    return tmp;
}

/** 
 * @brief add
 * @file 3-1-leetcode.c
 * @name 
 * @param[in] int key
 * @param[in] int value
 * @return void
 * @note 
 * @date 2022-01-14 10:06:47
 * @version V1.0.0
*/
static void insert(int ikey, int ival) 
{
    struct hash_table_1_t* it = find(ikey);
    if (it == NULL)//find
    {
        struct hash_table_1_t* tmp = malloc(sizeof(struct hash_table_1_t));
        tmp->key = ikey, tmp->value = ival;
        HASH_ADD_INT(hash_table_1, key, tmp);
    }
    else//no find
    {
        it->value = ival;
    }
}

//extern int* leetcode_1_hash_twosum(int* nums, int numsSize, int target, int* returnSize)
/** 
 * @brief 
 * @file 3-1-leetcode.c
 * @name 
 * @param[in] void
 * @return void
 * @note 
 * @date 2022-01-14 11:47:37
 * @version V1.0.0
*/
extern int* leetcode_1_hash_twosum(int* nums, int numsSize, int target)  
{
    hash_table_1 = NULL;
    leetcode_1_show();
    printi("num len %d\n",numsSize);
    for (int i = 0; i < numsSize; i++) 
    {
        struct hash_table_1_t* it = find(target - nums[i]);
        if (it != NULL) //find target
        {
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = it->value, ret[1] = i;
            //*returnSize = 2;
            printi("ret[0]:%d\n ret[1]:%d\n",ret[0],ret[1]);
            return ret;
        }
        insert(nums[i], i);
    }
    //*returnSize = 0;
    return NULL;
}

//solution 1   ##########################################################################
/** 
 * @brief 
 * @file 1-leetcode.c
 * @name 
 * @param[in] int* num //array num
 * @return void
 * @note 
 * @date 2021-12-13 10:01:20
 * @version V1.0.0
*/
extern int* leetcode_1_sum_of_two_number(int* num, int len, int target)
{
    int i = 0;
    int j = 0;
    leetcode_1_show();
    int* ret = calloc(2, sizeof(int));
    leetcode_1_show();
    num_judge_element_unique(num);
    printi("###################solution 1 ����ö��\n");
    printi("len:%d\n", len);

    for ( i = 0; i < len; i++ )
    {
        for (j = i + 1; j < len; j++)
        {
            if ( num[i] + num[j] == target )
            {
                ret[0] = i;
                ret[1] = j;
                printi("i:%d\nj%d\n", ret[0], ret[1] );
                return ret;
            }
        }
    }

    return NULL;

}

//solution end ##########################################################################


/* [] END OF FILE */