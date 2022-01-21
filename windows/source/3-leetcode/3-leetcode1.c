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
    // 题目
    printi("leetcode 1 两数之和\n");
    printi("给定一个整数数组 nums和一个整数目标值 target,\n");
    printi("请你在该数组中找出 和为目标值 target的那两个整数，并返回它们的数组下标\n");
    printi("你可以假设每种输入只会对应一个答案。\n");
    printi("但是，数组中同一个元素在答案里不能重复出现。\n");

    //1 暴力枚举
    printi("#############################\n");
    printi("solution 1 暴力枚举\n");
    printi("枚举数组中的每一个数 x，寻找数组中是否存在 target - x\n");
    printi("当我们使用遍历整个数组的方式寻找 target - x 时，\n");
    printi("需要注意到每一个位于 x 之前的元素都已经和 x 匹配过，因此不需要再进行匹配。\n");
    printi("而每一个元素不能被使用两次，所以我们只需要在 x 后面的元素中寻找 target - x。\n");
    printi("复杂度分析\n");
    printi("时间复杂度:O(N^2)\n");
    printi("其中 NN 是数组中的元素数量。最坏情况下数组中任意两个数都要被匹配一次。\n");
    printi("空间复杂度:O(1)\n");

    //2 哈希表
    printi("方法二 哈希\n");
    printi("思路及算法\n");
    printi("注意到方法一的时间复杂度较高的原因是寻找 target - x 的时间复杂度过高。\n");
    printi("因此，我们需要一种更优秀的方法，能够快速寻找数组中是否存在目标元素。\\n");
    printi("如果存在，我们需要找出它的索引。\n");
    printi("使用哈希表，可以将寻找 target - x 的时间复杂度降低到从 O(N)O(N) 降低到 O(1)O(1)。\n");
    printi("这样我们创建一个哈希表，对于每一个 x，我们首先查询哈希表中是否存在 target - x，\n");
    printi("然后将 x 插入到哈希表中，即可保证不会让 x 和自己匹配\n");
    printi("复杂度分析\n");
    printi("时间复杂度 O(N)O(N)\n");
    printi("其中 NN 是数组中的元素数量。对于每一个元素 x，我们可以 O(1)O(1) 地寻找 target - x。\n");
    printi("空间复杂度 O(N)O(N)\n");
    printi("其中 NN 是数组中的元素数量。主要为哈希表的开销。\n");
}

//solution 2 ##########################################################################################
/** 
 * @brief 1 define hash struct
 * @file 3-1-leetcode.c
 * @name 
 * @param int key
 * @param int key
 * @param UT_hash_handle hh //hash handle ,don't need assign a value
 * @note 类似于双向链表的操作，可以通过结构体成员hh的hh.prev和hh.next获取当前节点的上一个节点或者下一个节点。
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
    printi("###################solution 1 暴力枚举\n");
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