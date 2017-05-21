#include <stdio.h>

#define VIEW_NAME_MAX_LEN 64 
#define VIEW_PARAM_MAX_LEN 32

struct view_info {
    /* 在往 view_name[]字段中写数据的时候，必须先清零;大小 sizeof()
     * 用到 sizeof( ->current_view); 所以view_name 必须用数组 */
    /* 传入传出参数：传入视图名，传出切换后的视图名或视图模板名;
     * 如 ip_udp_1.1.1.1 视图名，中的 ip_udp_  */
    char view_name[VIEW_NAME_MAX_LEN];  

    /* 如 ip_udp_1.1.1.1 视图名中的 1.1.1.1;
     * 若是普通视图，该字段必须清零;memset() */
    char view_param[VIEW_PARAM_MAX_LEN];

    /* 1 表示往前进入子视图；0 表示不改变当前视图；
     * -1 表示退到上一视图，如 quit */
    /* int view_change_flag; */

    /* 1, 表示是视图模板名；0，表示不是 */
    /* int is_view_template;    */
};

int change_str(struct view_info *in_out_view_info);

int main()
{


    return 0;
}

int change_str(struct view_info *in_out_view_info)
{
    free();


}
